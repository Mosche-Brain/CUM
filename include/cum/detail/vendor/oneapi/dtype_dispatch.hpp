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
                std::unreachable();
            }
        });

        return detail::event_handler::create(std::move(event));
    }

    template <typename SyclT>
    using math_compute_t = std::conditional_t<std::is_same_v<SyclT, double>, double, float>;

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

