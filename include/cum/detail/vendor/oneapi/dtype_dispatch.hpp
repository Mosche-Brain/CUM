/*
 * @author: jaro
 * @name:   dtype_dispatch
 * @file:   include/cum/detail/vendor/oneapi/dtype_dispatch.hpp
 * @date:   17 October 2026 12:34:53
 */

#pragma once

#include "cum/Core.hpp"

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"

#include <sycl/sycl.hpp>
#include <oneapi/mkl/bfloat16.hpp>
#include <oneapi/mkl/types.hpp>

namespace cum::internal
{
    template <typename T>
    struct sycl_type_map { using type = T; };

    // Mapowanie std::float16_t (lub cum::float16) -> sycl::half
    template <>
    struct sycl_type_map<float16> { using type = sycl::half; };

    // Jeśli używasz też std::bfloat16_t -> typ bfloat16 z oneMKL / SYCL:
    template <>
    struct sycl_type_map<bfloat16> { using type = oneapi::mkl::bfloat16; };

    template <typename T>
    using sycl_type_t = typename sycl_type_map<T>::type;

    template <typename F>
    decltype(auto) dispatch_sycl_datatype(datatype dt, F&& f)
    {
        return dispatch_datatype(dt, [&]<typename T>() -> decltype(auto)
            requires requires { std::forward<F>(f).template operator()<internal::sycl_type_t<T>>(); }
        {
            // Przekazuje do właściwej lambdy już zmapowany typ (np. sycl::half zamiast float16_t)
            return std::forward<F>(f).template operator()<internal::sycl_type_t<T>>();
        });
    }


    template <typename SyclT>
    using math_compute_t = std::conditional_t<std::is_same_v<SyclT, double>, double, float>;

    template <typename SyclT>
    using blas_compute_t = std::conditional_t<
        std::is_integral_v<SyclT>,
        SyclT,
        std::conditional_t<std::is_same_v<SyclT, double>, double, float>>;

    template <typename MklCall, typename FallbackOp>
    __event__ dispatch_vm_binary(
        datatype dtype, void* r, const void* v, const void* u, const dim_t n,
        MklCall&& mkl_call, FallbackOp&& fallback_op)
    {
        sycl::event event = dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* r_ptr = static_cast<SyclT*>(r);
            auto* v_ptr = static_cast<const SyclT*>(v);
            auto* u_ptr = static_cast<const SyclT*>(u);

            // Sprawdzamy, czy funkcja MKL kompiluje się dla SyclT
            if constexpr (requires { mkl_call(q, n, v_ptr, u_ptr, r_ptr); }) {
                return mkl_call(q, n, v_ptr, u_ptr, r_ptr);
            }
            // Fallback na kernel SYCL
            else if constexpr (requires(SyclT a, SyclT b) { r_ptr[0] = fallback_op(a, b); }) {
                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> i) {
                    r_ptr[i] = fallback_op(v_ptr[i], u_ptr[i]);
                });
            }
            else {
                using ComputeT = blas_compute_t<SyclT>;
                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> i) {
                    r_ptr[i] = static_cast<SyclT>(fallback_op(static_cast<ComputeT>(v_ptr[i]), static_cast<ComputeT>(u_ptr[i])));
                });
            }
        });

        return detail::event_handler::create(std::move(event));
    }

    template <typename MklCall, typename FallbackOp>
    __event__ dispatch_vm_binary_batch(
        datatype dtype,
        void* r, const dim_t stride_r,
        const void* v, const dim_t stride_v,
        const void* u, const dim_t stride_u,
        const dim_t n, const dim_t batch_size,
        MklCall&& mkl_call, FallbackOp&& fallback_op)
    {
        if (stride_r == n && stride_v == n && stride_u == n)
        {
            return dispatch_vm_binary(
                dtype, r, v, u, n * batch_size,
                std::forward<MklCall>(mkl_call),
                std::forward<FallbackOp>(fallback_op));
        }

        sycl::event event = dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* r_ptr = static_cast<SyclT*>(r);
            auto* v_ptr = static_cast<const SyclT*>(v);
            auto* u_ptr = static_cast<const SyclT*>(u);
            const auto range = sycl::range<2>(static_cast<std::size_t>(batch_size), static_cast<std::size_t>(n));

            if constexpr (requires(SyclT a, SyclT b) { r_ptr[0] = fallback_op(a, b); })
            {
                return q.parallel_for(range, [=](sycl::id<2> idx) {
                    const auto b = static_cast<dim_t>(idx[0]);
                    const auto i = static_cast<dim_t>(idx[1]);
                    r_ptr[b * stride_r + i] = fallback_op(v_ptr[b * stride_v + i], u_ptr[b * stride_u + i]);
                });
            }
            else
            {
                using ComputeT = blas_compute_t<SyclT>;
                return q.parallel_for(range, [=](sycl::id<2> idx) {
                    const auto b = static_cast<dim_t>(idx[0]);
                    const auto i = static_cast<dim_t>(idx[1]);
                    r_ptr[b * stride_r + i] = static_cast<SyclT>(
                        fallback_op(static_cast<ComputeT>(v_ptr[b * stride_v + i]),
                                    static_cast<ComputeT>(u_ptr[b * stride_u + i])));
                });
            }
        });

        return detail::event_handler::create(std::move(event));
    }

    constexpr dim_t blas_vec_index(dim_t i, dim_t n, dim_t inc) noexcept
    {
        return inc >= 0 ? i * inc : (i - (n - 1)) * inc;
    }

    struct scalar_buffer
    {
        alignas(16) std::byte data[16]{};
        const void* ptr() const noexcept { return data; }
    };

    inline scalar_buffer to_scalar_buffer(datatype dt, cumeric_t val)
    {
        scalar_buffer buf;
        dispatch_sycl_datatype(dt, [&]<typename SyclT>() {
            using ComputeT = blas_compute_t<SyclT>;
            *reinterpret_cast<SyclT*>(buf.data) = static_cast<SyclT>(static_cast<ComputeT>(val));
        });
        return buf;
    }

    constexpr oneapi::mkl::transpose to_mkl_transpose(char c) noexcept
    {
        switch (c)
        {
            case 'T':
            case 't':
            case static_cast<char>(oneapi::mkl::transpose::trans):
                return oneapi::mkl::transpose::trans;
            case 'C':
            case 'c':
            case static_cast<char>(oneapi::mkl::transpose::conjtrans):
                return oneapi::mkl::transpose::conjtrans;
            default:
                return oneapi::mkl::transpose::nontrans;
        }
    }

    constexpr oneapi::mkl::uplo to_mkl_uplo(char c) noexcept
    {
        switch (c)
        {
            case 'L':
            case 'l':
            case static_cast<char>(oneapi::mkl::uplo::lower):
                return oneapi::mkl::uplo::lower;
            default:
                return oneapi::mkl::uplo::upper;
        }
    }

    constexpr oneapi::mkl::diag to_mkl_diag(char c) noexcept
    {
        switch (c)
        {
            case 'U':
            case 'u':
            case static_cast<char>(oneapi::mkl::diag::unit):
                return oneapi::mkl::diag::unit;
            default:
                return oneapi::mkl::diag::nonunit;
        }
    }

    constexpr oneapi::mkl::side to_mkl_side(char c) noexcept
    {
        switch (c)
        {
            case 'R':
            case 'r':
            case static_cast<char>(oneapi::mkl::side::right):
                return oneapi::mkl::side::right;
            default:
                return oneapi::mkl::side::left;
        }
    }

    template <typename MklCall, typename FallbackOp>
    __event__ dispatch_vm_unary(
        datatype dtype, void* r, const void* v, const std::size_t n,
        MklCall&& mkl_call, FallbackOp&& fallback_op)
    {
        sycl::event event = dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* r_ptr = static_cast<SyclT*>(r);
            auto* v_ptr = static_cast<const SyclT*>(v);
            const auto dim_n = static_cast<dim_t>(n);

            if constexpr (requires { mkl_call(q, dim_n, v_ptr, r_ptr); }) {
                return mkl_call(q, dim_n, v_ptr, r_ptr);
            }
            else {
                using ComputeT = math_compute_t<SyclT>;
                return q.parallel_for(sycl::range<1>(n), [=](sycl::id<1> i) {
                    r_ptr[i] = static_cast<SyclT>(fallback_op(static_cast<ComputeT>(v_ptr[i])));
                });
            }
        });

        return detail::event_handler::create(std::move(event));
    }

    template <typename Op>
    __event__ dispatch_unary_math(
        datatype dtype, void* r, const void* v, const std::size_t n,
        Op&& op)
    {
        sycl::event event = dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* r_ptr = static_cast<SyclT*>(r);
            auto* v_ptr = static_cast<const SyclT*>(v);
            using ComputeT = math_compute_t<SyclT>;

            return q.parallel_for(sycl::range<1>(n), [=](sycl::id<1> i) {
                r_ptr[i] = static_cast<SyclT>(op(static_cast<ComputeT>(v_ptr[i])));
            });
        });

        return detail::event_handler::create(std::move(event));
    }

} // namespace internal

