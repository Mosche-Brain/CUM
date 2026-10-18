//
// Created by jaro on 8/2/26.
//

#include <oneapi/mkl/blas.hpp>

#include <cstdint>
#include <type_traits>

#include "cum/lara/BLAS/level1.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

namespace cum::blas
{
    namespace
    {
        template <typename T>
        constexpr T abs_val(T v) noexcept
        {
            if constexpr (std::is_unsigned_v<T>)
            {
                return v;
            }
            else
            {
                return v < T(0) ? -v : v;
            }
        }
    }

    __event__ axpy(const datatype dtype, const dim_t n, const void* alpha, const void* x, const dim_t incx, void* y, const dim_t incy)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* y_ptr = static_cast<SyclT*>(y);

            if constexpr (requires { oneapi::mkl::blas::row_major::axpy(q, n, alpha_val, x_ptr, incx, y_ptr, incy); })
            {
                return oneapi::mkl::blas::row_major::axpy(q, n, alpha_val, x_ptr, incx, y_ptr, incy);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> idx) {
                    const auto i = static_cast<dim_t>(idx[0]);
                    const auto ix = internal::blas_vec_index(i, n, incx);
                    const auto iy = internal::blas_vec_index(i, n, incy);
                    y_ptr[iy] = static_cast<SyclT>(alpha_c * static_cast<ComputeT>(x_ptr[ix]) + static_cast<ComputeT>(y_ptr[iy]));
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ axpy(const datatype dtype, const dim_t n, const cumeric_t alpha, const void* x, const dim_t incx, void* y, const dim_t incy)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        return axpy(dtype, n, a_buf.ptr(), x, incx, y, incy);
    }

    __event__ axpy(const dim_t n, const cumeric_t alpha, const cumeric_t* x, const dim_t incx, cumeric_t* y, const dim_t incy)
    {
        return axpy(default_type, n, &alpha, x, incx, y, incy);
    }

    __event__ axpy(const datatype dtype, const dim_t n, const void* alpha, const void* x, const dim_t incx, const void* beta, void* y, const dim_t incy)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            const SyclT beta_val = *static_cast<const SyclT*>(beta);
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* y_ptr = static_cast<SyclT*>(y);

            if constexpr (requires { oneapi::mkl::blas::row_major::axpby(q, n, alpha_val, x_ptr, incx, beta_val, y_ptr, incy); })
            {
                return oneapi::mkl::blas::row_major::axpby(q, n, alpha_val, x_ptr, incx, beta_val, y_ptr, incy);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const auto beta_c = static_cast<ComputeT>(beta_val);
                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> idx) {
                    const auto i = static_cast<dim_t>(idx[0]);
                    const auto ix = internal::blas_vec_index(i, n, incx);
                    const auto iy = internal::blas_vec_index(i, n, incy);
                    const ComputeT term_x = alpha_c * static_cast<ComputeT>(x_ptr[ix]);
                    const ComputeT term_y = (beta_c == ComputeT(0)) ? ComputeT(0) : beta_c * static_cast<ComputeT>(y_ptr[iy]);
                    y_ptr[iy] = static_cast<SyclT>(term_x + term_y);
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ axpy(const datatype dtype, const dim_t n, const cumeric_t alpha, const void* x, const dim_t incx, const cumeric_t beta, void* y, const dim_t incy)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        const auto b_buf = internal::to_scalar_buffer(dtype, beta);
        return axpy(dtype, n, a_buf.ptr(), x, incx, b_buf.ptr(), y, incy);
    }

    __event__ axpy(const dim_t n, const cumeric_t alpha, const cumeric_t* x, const dim_t incx, const cumeric_t beta, cumeric_t* y, const dim_t incy)
    {
        return axpy(default_type, n, &alpha, x, incx, &beta, y, incy);
    }

    __event__ dot(const datatype dtype, const dim_t n, const void* x, const dim_t incx, const void* y, const dim_t incy, void* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* y_ptr = static_cast<const SyclT*>(y);
            auto* res_ptr = static_cast<SyclT*>(result);

            if constexpr (requires { oneapi::mkl::blas::row_major::dot(q, n, x_ptr, incx, y_ptr, incy, res_ptr); })
            {
                return oneapi::mkl::blas::row_major::dot(q, n, x_ptr, incx, y_ptr, incy, res_ptr);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                return q.single_task([=]() {
                    ComputeT acc = ComputeT(0);
                    for (dim_t i = 0; i < n; ++i)
                    {
                        const auto ix = internal::blas_vec_index(i, n, incx);
                        const auto iy = internal::blas_vec_index(i, n, incy);
                        acc += static_cast<ComputeT>(x_ptr[ix]) * static_cast<ComputeT>(y_ptr[iy]);
                    }
                    res_ptr[0] = static_cast<SyclT>(acc);
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ dot(const dim_t n, const cumeric_t* x, const dim_t incx, const cumeric_t* y, const dim_t incy, cumeric_t* result)
    {
        return dot(default_type, n, x, incx, y, incy, result);
    }

    __event__ asum(const datatype dtype, const dim_t n, const void* x, const dim_t incx, void* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* res_ptr = static_cast<SyclT*>(result);

            if constexpr (requires { oneapi::mkl::blas::row_major::asum(q, n, x_ptr, incx, res_ptr); })
            {
                return oneapi::mkl::blas::row_major::asum(q, n, x_ptr, incx, res_ptr);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                return q.single_task([=]() {
                    ComputeT acc = ComputeT(0);
                    for (dim_t i = 0; i < n; ++i)
                    {
                        const auto ix = internal::blas_vec_index(i, n, incx);
                        acc += abs_val(static_cast<ComputeT>(x_ptr[ix]));
                    }
                    res_ptr[0] = static_cast<SyclT>(acc);
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ asum(const dim_t n, const cumeric_t* x, const dim_t incx, cumeric_t* result)
    {
        return asum(default_type, n, x, incx, result);
    }

    __event__ nrm2(const datatype dtype, const dim_t n, const void* x, const dim_t incx, void* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* res_ptr = static_cast<SyclT*>(result);

            if constexpr (requires { oneapi::mkl::blas::row_major::nrm2(q, n, x_ptr, incx, res_ptr); })
            {
                return oneapi::mkl::blas::row_major::nrm2(q, n, x_ptr, incx, res_ptr);
            }
            else
            {
                using MathT = internal::math_compute_t<SyclT>;
                return q.single_task([=]() {
                    MathT acc = MathT(0);
                    for (dim_t i = 0; i < n; ++i)
                    {
                        const auto ix = internal::blas_vec_index(i, n, incx);
                        const auto v = static_cast<MathT>(x_ptr[ix]);
                        acc += v * v;
                    }
                    res_ptr[0] = static_cast<SyclT>(sycl::sqrt(acc));
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ nrm2(const dim_t n, const cumeric_t* x, const dim_t incx, cumeric_t* result)
    {
        return nrm2(default_type, n, x, incx, result);
    }

    __event__ iamax(const datatype dtype, const dim_t n, const void* x, const dim_t incx, dim_t* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);

            if constexpr (requires { oneapi::mkl::blas::row_major::iamax(q, n, x_ptr, incx, result); })
            {
                return oneapi::mkl::blas::row_major::iamax(q, n, x_ptr, incx, result);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                return q.single_task([=]() {
                    if (n <= 0)
                    {
                        result[0] = 0;
                        return;
                    }
                    dim_t best_idx = 0;
                    ComputeT best_val = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(0, n, incx)]));
                    for (dim_t i = 1; i < n; ++i)
                    {
                        const ComputeT cur = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(i, n, incx)]));
                        if (cur > best_val)
                        {
                            best_val = cur;
                            best_idx = i;
                        }
                    }
                    result[0] = best_idx;
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ iamax(const dim_t n, const cumeric_t* x, const dim_t incx, dim_t* result)
    {
        return iamax(default_type, n, x, incx, result);
    }

    __event__ iamin(const datatype dtype, const dim_t n, const void* x, const dim_t incx, dim_t* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);

            if constexpr (requires { oneapi::mkl::blas::row_major::iamin(q, n, x_ptr, incx, result); })
            {
                return oneapi::mkl::blas::row_major::iamin(q, n, x_ptr, incx, result);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                return q.single_task([=]() {
                    if (n <= 0)
                    {
                        result[0] = 0;
                        return;
                    }
                    dim_t best_idx = 0;
                    ComputeT best_val = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(0, n, incx)]));
                    for (dim_t i = 1; i < n; ++i)
                    {
                        const ComputeT cur = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(i, n, incx)]));
                        if (cur < best_val)
                        {
                            best_val = cur;
                            best_idx = i;
                        }
                    }
                    result[0] = best_idx;
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ iamin(const dim_t n, const cumeric_t* x, const dim_t incx, dim_t* result)
    {
        return iamin(default_type, n, x, incx, result);
    }

    __event__ amax(const datatype dtype, const dim_t n, const void* x, const dim_t incx, void* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* res_ptr = static_cast<SyclT*>(result);
            using ComputeT = internal::blas_compute_t<SyclT>;

            return q.single_task([=]() {
                if (n <= 0)
                {
                    res_ptr[0] = static_cast<SyclT>(ComputeT(0));
                    return;
                }
                dim_t best_idx = 0;
                ComputeT best_val = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(0, n, incx)]));
                for (dim_t i = 1; i < n; ++i)
                {
                    const ComputeT cur = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(i, n, incx)]));
                    if (cur > best_val)
                    {
                        best_val = cur;
                        best_idx = i;
                    }
                }
                res_ptr[0] = x_ptr[internal::blas_vec_index(best_idx, n, incx)];
            });
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ amax(const dim_t n, const cumeric_t* x, const dim_t incx, cumeric_t* result)
    {
        return amax(default_type, n, x, incx, result);
    }

    __event__ amin(const datatype dtype, const dim_t n, const void* x, const dim_t incx, void* result)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* res_ptr = static_cast<SyclT*>(result);
            using ComputeT = internal::blas_compute_t<SyclT>;

            return q.single_task([=]() {
                if (n <= 0)
                {
                    res_ptr[0] = static_cast<SyclT>(ComputeT(0));
                    return;
                }
                dim_t best_idx = 0;
                ComputeT best_val = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(0, n, incx)]));
                for (dim_t i = 1; i < n; ++i)
                {
                    const ComputeT cur = abs_val(static_cast<ComputeT>(x_ptr[internal::blas_vec_index(i, n, incx)]));
                    if (cur < best_val)
                    {
                        best_val = cur;
                        best_idx = i;
                    }
                }
                res_ptr[0] = x_ptr[internal::blas_vec_index(best_idx, n, incx)];
            });
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ amin(const dim_t n, const cumeric_t* x, const dim_t incx, cumeric_t* result)
    {
        return amin(default_type, n, x, incx, result);
    }

    __event__ scal(const datatype dtype, const dim_t n, const void* alpha, void* x, const dim_t incx)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            auto* x_ptr = static_cast<SyclT*>(x);

            if constexpr (requires { oneapi::mkl::blas::row_major::scal(q, n, alpha_val, x_ptr, incx); })
            {
                return oneapi::mkl::blas::row_major::scal(q, n, alpha_val, x_ptr, incx);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> idx) {
                    const auto i = static_cast<dim_t>(idx[0]);
                    const auto ix = internal::blas_vec_index(i, n, incx);
                    x_ptr[ix] = static_cast<SyclT>(alpha_c * static_cast<ComputeT>(x_ptr[ix]));
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ scal(const datatype dtype, const dim_t n, const cumeric_t alpha, void* x, const dim_t incx)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        return scal(dtype, n, a_buf.ptr(), x, incx);
    }

    __event__ scal(const dim_t n, const cumeric_t alpha, cumeric_t* x, const dim_t incx)
    {
        return scal(default_type, n, &alpha, x, incx);
    }
}
