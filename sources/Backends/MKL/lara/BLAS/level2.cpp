//
// Created by jaro on 8/2/26.
//

#include <oneapi/mkl/blas.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

#include "cum/lara/BLAS/level2.hpp"
#include "cum/lara/BLAS/types.hpp"

namespace cum::blas
{
    __event__ gemv(const datatype dtype, const char transa, const dim_t m, const dim_t n, const void* alpha, const void* A, const dim_t lda, const void* x, const dim_t incx, const void* beta, void* y, const dim_t incy)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto trans = internal::to_mkl_transpose(transa);
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            const SyclT beta_val = *static_cast<const SyclT*>(beta);
            auto* A_ptr = static_cast<const SyclT*>(A);
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* y_ptr = static_cast<SyclT*>(y);

            if constexpr (requires { oneapi::mkl::blas::row_major::gemv(q, trans, m, n, alpha_val, A_ptr, lda, x_ptr, incx, beta_val, y_ptr, incy); })
            {
                return oneapi::mkl::blas::row_major::gemv(q, trans, m, n, alpha_val, A_ptr, lda, x_ptr, incx, beta_val, y_ptr, incy);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const auto beta_c = static_cast<ComputeT>(beta_val);
                const bool is_trans = (trans != oneapi::mkl::transpose::nontrans);
                const dim_t out_len = is_trans ? n : m;
                const dim_t in_len = is_trans ? m : n;

                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(out_len)), [=](sycl::id<1> idx) {
                    const auto i = static_cast<dim_t>(idx[0]);
                    ComputeT acc = ComputeT(0);
                    for (dim_t j = 0; j < in_len; ++j)
                    {
                        const dim_t a_idx = is_trans ? (j * lda + i) : (i * lda + j);
                        const dim_t x_idx = internal::blas_vec_index(j, in_len, incx);
                        acc += static_cast<ComputeT>(A_ptr[a_idx]) * static_cast<ComputeT>(x_ptr[x_idx]);
                    }
                    const dim_t y_idx = internal::blas_vec_index(i, out_len, incy);
                    const ComputeT term_y = (beta_c == ComputeT(0)) ? ComputeT(0) : beta_c * static_cast<ComputeT>(y_ptr[y_idx]);
                    y_ptr[y_idx] = static_cast<SyclT>(alpha_c * acc + term_y);
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ gemv(const datatype dtype, const char transa, const dim_t m, const dim_t n, const cumeric_t alpha, const void* A, const dim_t lda, const void* x, const dim_t incx, const cumeric_t beta, void* y, const dim_t incy)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        const auto b_buf = internal::to_scalar_buffer(dtype, beta);
        return gemv(dtype, transa, m, n, a_buf.ptr(), A, lda, x, incx, b_buf.ptr(), y, incy);
    }

    __event__ gemv(const char transa, const dim_t m, const dim_t n, const cumeric_t alpha, const cumeric_t* A, const dim_t lda, const cumeric_t* x, const dim_t incx, const cumeric_t beta, cumeric_t* y, const dim_t incy)
    {
        return gemv(default_type, transa, m, n, &alpha, A, lda, x, incx, &beta, y, incy);
    }

    __event__ symv(const datatype dtype, const char vertical, const dim_t n, const void* alpha, const void* A, const dim_t lda, const void* x, const dim_t incx, const void* beta, void* y, const dim_t incy)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto uplo = internal::to_mkl_uplo(vertical);
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            const SyclT beta_val = *static_cast<const SyclT*>(beta);
            auto* A_ptr = static_cast<const SyclT*>(A);
            auto* x_ptr = static_cast<const SyclT*>(x);
            auto* y_ptr = static_cast<SyclT*>(y);

            if constexpr (requires { oneapi::mkl::blas::row_major::symv(q, uplo, n, alpha_val, A_ptr, lda, x_ptr, incx, beta_val, y_ptr, incy); })
            {
                return oneapi::mkl::blas::row_major::symv(q, uplo, n, alpha_val, A_ptr, lda, x_ptr, incx, beta_val, y_ptr, incy);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const auto beta_c = static_cast<ComputeT>(beta_val);
                const bool is_upper = (uplo == oneapi::mkl::uplo::upper);

                return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(n)), [=](sycl::id<1> idx) {
                    const auto i = static_cast<dim_t>(idx[0]);
                    ComputeT acc = ComputeT(0);
                    for (dim_t j = 0; j < n; ++j)
                    {
                        const dim_t r = is_upper ? (i < j ? i : j) : (i > j ? i : j);
                        const dim_t c = is_upper ? (i < j ? j : i) : (i > j ? j : i);
                        const dim_t x_idx = internal::blas_vec_index(j, n, incx);
                        acc += static_cast<ComputeT>(A_ptr[r * lda + c]) * static_cast<ComputeT>(x_ptr[x_idx]);
                    }
                    const dim_t y_idx = internal::blas_vec_index(i, n, incy);
                    const ComputeT term_y = (beta_c == ComputeT(0)) ? ComputeT(0) : beta_c * static_cast<ComputeT>(y_ptr[y_idx]);
                    y_ptr[y_idx] = static_cast<SyclT>(alpha_c * acc + term_y);
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ symv(const datatype dtype, const char vertical, const dim_t n, const cumeric_t alpha, const void* A, const dim_t lda, const void* x, const dim_t incx, const cumeric_t beta, void* y, const dim_t incy)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        const auto b_buf = internal::to_scalar_buffer(dtype, beta);
        return symv(dtype, vertical, n, a_buf.ptr(), A, lda, x, incx, b_buf.ptr(), y, incy);
    }

    __event__ symv(const char vertical, const dim_t n, const cumeric_t alpha, const cumeric_t* A, const dim_t lda, const cumeric_t* x, const dim_t incx, const cumeric_t beta, cumeric_t* y, const dim_t incy)
    {
        return symv(default_type, vertical, n, &alpha, A, lda, x, incx, &beta, y, incy);
    }

    __event__ trmv(const datatype dtype, const char vertical, const char transa, const char diag, const dim_t n, const void* A, const dim_t lda, void* x, const dim_t incx)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto uplo = internal::to_mkl_uplo(vertical);
            const auto trans = internal::to_mkl_transpose(transa);
            const auto unit_diag = internal::to_mkl_diag(diag);
            auto* A_ptr = static_cast<const SyclT*>(A);
            auto* x_ptr = static_cast<SyclT*>(x);

            if constexpr (requires { oneapi::mkl::blas::row_major::trmv(q, uplo, trans, unit_diag, n, A_ptr, lda, x_ptr, incx); })
            {
                return oneapi::mkl::blas::row_major::trmv(q, uplo, trans, unit_diag, n, A_ptr, lda, x_ptr, incx);
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const bool is_upper = (uplo == oneapi::mkl::uplo::upper);
                const bool is_trans = (trans != oneapi::mkl::transpose::nontrans);
                const bool is_unit = (unit_diag == oneapi::mkl::diag::unit);
                const bool eff_upper = (is_upper != is_trans);

                return q.single_task([=]() {
                    if (eff_upper)
                    {
                        for (dim_t i = 0; i < n; ++i)
                        {
                            const dim_t ix = internal::blas_vec_index(i, n, incx);
                            ComputeT acc = (is_unit ? ComputeT(1) : static_cast<ComputeT>(A_ptr[i * lda + i])) * static_cast<ComputeT>(x_ptr[ix]);
                            for (dim_t j = i + 1; j < n; ++j)
                            {
                                const dim_t a_idx = is_trans ? (j * lda + i) : (i * lda + j);
                                const dim_t jx = internal::blas_vec_index(j, n, incx);
                                acc += static_cast<ComputeT>(A_ptr[a_idx]) * static_cast<ComputeT>(x_ptr[jx]);
                            }
                            x_ptr[ix] = static_cast<SyclT>(acc);
                        }
                    }
                    else
                    {
                        for (dim_t i = n - 1; i >= 0; --i)
                        {
                            const dim_t ix = internal::blas_vec_index(i, n, incx);
                            ComputeT acc = (is_unit ? ComputeT(1) : static_cast<ComputeT>(A_ptr[i * lda + i])) * static_cast<ComputeT>(x_ptr[ix]);
                            for (dim_t j = 0; j < i; ++j)
                            {
                                const dim_t a_idx = is_trans ? (j * lda + i) : (i * lda + j);
                                const dim_t jx = internal::blas_vec_index(j, n, incx);
                                acc += static_cast<ComputeT>(A_ptr[a_idx]) * static_cast<ComputeT>(x_ptr[jx]);
                            }
                            x_ptr[ix] = static_cast<SyclT>(acc);
                        }
                    }
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ trmv(const char vertical, const char transa, const char diag, const dim_t n, const cumeric_t* A, const dim_t lda, cumeric_t* x, const dim_t incx)
    {
        return trmv(default_type, vertical, transa, diag, n, A, lda, x, incx);
    }
}
