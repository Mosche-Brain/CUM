//
// Created by jaro on 8/2/26.
//

#include <oneapi/mkl/blas.hpp>

#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/lara/BLAS/level3.hpp"

namespace cum::blas
{
    __event__ gemm(const datatype dtype, const char transpose_a, const char transpose_b, const dim_t m, const dim_t n, const dim_t k, const void* alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb, const void* beta, void* c, const dim_t ldc)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto transa = internal::to_mkl_transpose(transpose_a);
            const auto transb = internal::to_mkl_transpose(transpose_b);
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            const SyclT beta_val = *static_cast<const SyclT*>(beta);
            auto* a_ptr = static_cast<const SyclT*>(a);
            auto* b_ptr = static_cast<const SyclT*>(b);
            auto* c_ptr = static_cast<SyclT*>(c);

            if constexpr (requires {
                oneapi::mkl::blas::row_major::gemm(
                    q, transa, transb, m, n, k, alpha_val, a_ptr, lda, b_ptr, ldb, beta_val, c_ptr, ldc,
                    oneapi::mkl::blas::compute_mode::standard, {});
            })
            {
                return oneapi::mkl::blas::row_major::gemm(
                    q, transa, transb, m, n, k, alpha_val, a_ptr, lda, b_ptr, ldb, beta_val, c_ptr, ldc,
                    oneapi::mkl::blas::compute_mode::standard, {});
            }
            else if constexpr (requires {
                oneapi::mkl::blas::row_major::gemm(
                    q, transa, transb, m, n, k, static_cast<float>(alpha_val), a_ptr, lda, b_ptr, ldb,
                    static_cast<float>(beta_val), c_ptr, ldc, oneapi::mkl::blas::compute_mode::standard, {});
            })
            {
                return oneapi::mkl::blas::row_major::gemm(
                    q, transa, transb, m, n, k, static_cast<float>(alpha_val), a_ptr, lda, b_ptr, ldb,
                    static_cast<float>(beta_val), c_ptr, ldc, oneapi::mkl::blas::compute_mode::standard, {});
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const auto beta_c = static_cast<ComputeT>(beta_val);
                const bool is_transa = (transa != oneapi::mkl::transpose::nontrans);
                const bool is_transb = (transb != oneapi::mkl::transpose::nontrans);

                return q.parallel_for(
                    sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
                    [=](sycl::id<2> idx) {
                        const auto row = static_cast<dim_t>(idx[0]);
                        const auto col = static_cast<dim_t>(idx[1]);
                        ComputeT acc = ComputeT(0);
                        for (dim_t p = 0; p < k; ++p)
                        {
                            const dim_t a_idx = is_transa ? (p * lda + row) : (row * lda + p);
                            const dim_t b_idx = is_transb ? (col * ldb + p) : (p * ldb + col);
                            acc += static_cast<ComputeT>(a_ptr[a_idx]) * static_cast<ComputeT>(b_ptr[b_idx]);
                        }
                        const dim_t c_idx = row * ldc + col;
                        const ComputeT term_c = (beta_c == ComputeT(0)) ? ComputeT(0) : beta_c * static_cast<ComputeT>(c_ptr[c_idx]);
                        c_ptr[c_idx] = static_cast<SyclT>(alpha_c * acc + term_c);
                    });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ gemm(const datatype dtype, const char transpose_a, const char transpose_b, const dim_t m, const dim_t n, const dim_t k, const cumeric_t alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb, const cumeric_t beta, void* c, const dim_t ldc)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        const auto b_buf = internal::to_scalar_buffer(dtype, beta);
        return gemm(dtype, transpose_a, transpose_b, m, n, k, a_buf.ptr(), a, lda, b, ldb, b_buf.ptr(), c, ldc);
    }

    __event__ gemm(const char transpose_a, const char transpose_b, const dim_t m, const dim_t n, const dim_t k, const cumeric_t alpha, const cumeric_t* a, const dim_t lda, const cumeric_t* b, const dim_t ldb, const cumeric_t beta, cumeric_t* c, const dim_t ldc)
    {
        return gemm(default_type, transpose_a, transpose_b, m, n, k, &alpha, a, lda, b, ldb, &beta, c, ldc);
    }

    __event__ symm(const datatype dtype, const char horizontal, const char vertical, const dim_t m, const dim_t n, const dim_t k, const void* alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb, const void* beta, void* c, const dim_t ldc)
    {
        (void)k;
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto side = internal::to_mkl_side(horizontal);
            const auto uplo = internal::to_mkl_uplo(vertical);
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            const SyclT beta_val = *static_cast<const SyclT*>(beta);
            auto* a_ptr = static_cast<const SyclT*>(a);
            auto* b_ptr = static_cast<const SyclT*>(b);
            auto* c_ptr = static_cast<SyclT*>(c);

            if constexpr (requires {
                oneapi::mkl::blas::row_major::symm(
                    q, side, uplo, m, n, alpha_val, a_ptr, lda, b_ptr, ldb, beta_val, c_ptr, ldc,
                    oneapi::mkl::blas::compute_mode::standard, {});
            })
            {
                return oneapi::mkl::blas::row_major::symm(
                    q, side, uplo, m, n, alpha_val, a_ptr, lda, b_ptr, ldb, beta_val, c_ptr, ldc,
                    oneapi::mkl::blas::compute_mode::standard, {});
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const auto beta_c = static_cast<ComputeT>(beta_val);
                const bool is_left = (side == oneapi::mkl::side::left);
                const bool is_upper = (uplo == oneapi::mkl::uplo::upper);
                const dim_t inner = is_left ? m : n;

                return q.parallel_for(
                    sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
                    [=](sycl::id<2> idx) {
                        const auto row = static_cast<dim_t>(idx[0]);
                        const auto col = static_cast<dim_t>(idx[1]);
                        ComputeT acc = ComputeT(0);
                        for (dim_t p = 0; p < inner; ++p)
                        {
                            const dim_t i_a = is_left ? row : p;
                            const dim_t j_a = is_left ? p : col;
                            const dim_t r_a = is_upper ? (i_a < j_a ? i_a : j_a) : (i_a > j_a ? i_a : j_a);
                            const dim_t c_a = is_upper ? (i_a < j_a ? j_a : i_a) : (i_a > j_a ? j_a : i_a);
                            const dim_t b_idx = is_left ? (p * ldb + col) : (row * ldb + p);
                            acc += static_cast<ComputeT>(a_ptr[r_a * lda + c_a]) * static_cast<ComputeT>(b_ptr[b_idx]);
                        }
                        const dim_t c_idx = row * ldc + col;
                        const ComputeT term_c = (beta_c == ComputeT(0)) ? ComputeT(0) : beta_c * static_cast<ComputeT>(c_ptr[c_idx]);
                        c_ptr[c_idx] = static_cast<SyclT>(alpha_c * acc + term_c);
                    });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ symm(const datatype dtype, const char horizontal, const char vertical, const dim_t m, const dim_t n, const dim_t k, const cumeric_t alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb, const cumeric_t beta, void* c, const dim_t ldc)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        const auto b_buf = internal::to_scalar_buffer(dtype, beta);
        return symm(dtype, horizontal, vertical, m, n, k, a_buf.ptr(), a, lda, b, ldb, b_buf.ptr(), c, ldc);
    }

    __event__ symm(const char horizontal, const char vertical, const dim_t m, const dim_t n, const dim_t k, const cumeric_t alpha, const cumeric_t* a, const dim_t lda, const cumeric_t* b, const dim_t ldb, const cumeric_t beta, cumeric_t* c, const dim_t ldc)
    {
        return symm(default_type, horizontal, vertical, m, n, k, &alpha, a, lda, b, ldb, &beta, c, ldc);
    }

    __event__ trmm(const datatype dtype, const char horizontal, const char vertical, const char transpose_a, const char diagonal, void* c, const dim_t m, const dim_t n, const void* alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb)
    {
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            const auto side = internal::to_mkl_side(horizontal);
            const auto uplo = internal::to_mkl_uplo(vertical);
            const auto transa = internal::to_mkl_transpose(transpose_a);
            const auto unit_diag = internal::to_mkl_diag(diagonal);
            const SyclT alpha_val = *static_cast<const SyclT*>(alpha);
            auto* a_ptr = static_cast<const SyclT*>(a);
            auto* b_ptr = static_cast<const SyclT*>(b);
            auto* c_ptr = static_cast<SyclT*>(c);

            if constexpr (requires {
                oneapi::mkl::blas::row_major::trmm(
                    q, side, uplo, transa, unit_diag, m, n, alpha_val, a_ptr, lda, b_ptr, ldb, SyclT(0), c_ptr, ldb,
                    oneapi::mkl::blas::compute_mode::standard, {});
            })
            {
                if (c_ptr == b_ptr)
                {
                    return oneapi::mkl::blas::row_major::trmm(
                        q, side, uplo, transa, unit_diag, m, n, alpha_val, a_ptr, lda, c_ptr, ldb,
                        oneapi::mkl::blas::compute_mode::standard, {});
                }
                return oneapi::mkl::blas::row_major::trmm(
                    q, side, uplo, transa, unit_diag, m, n, alpha_val, a_ptr, lda, b_ptr, ldb, SyclT(0), c_ptr, ldb,
                    oneapi::mkl::blas::compute_mode::standard, {});
            }
            else
            {
                using ComputeT = internal::blas_compute_t<SyclT>;
                const auto alpha_c = static_cast<ComputeT>(alpha_val);
                const bool is_left = (side == oneapi::mkl::side::left);
                const bool is_upper = (uplo == oneapi::mkl::uplo::upper);
                const bool is_trans = (transa != oneapi::mkl::transpose::nontrans);
                const bool is_unit = (unit_diag == oneapi::mkl::diag::unit);
                const bool eff_upper = (is_upper != is_trans);

                auto eval_elem = [=](dim_t row, dim_t col) -> SyclT {
                    ComputeT acc = ComputeT(0);
                    if (is_left)
                    {
                        const dim_t p_start = eff_upper ? row : 0;
                        const dim_t p_end = eff_upper ? m : (row + 1);
                        for (dim_t p = p_start; p < p_end; ++p)
                        {
                            const ComputeT a_val = (p == row && is_unit)
                                ? ComputeT(1)
                                : static_cast<ComputeT>(a_ptr[is_trans ? (p * lda + row) : (row * lda + p)]);
                            acc += a_val * static_cast<ComputeT>(b_ptr[p * ldb + col]);
                        }
                    }
                    else
                    {
                        const dim_t p_start = eff_upper ? 0 : col;
                        const dim_t p_end = eff_upper ? (col + 1) : n;
                        for (dim_t p = p_start; p < p_end; ++p)
                        {
                            const ComputeT a_val = (p == col && is_unit)
                                ? ComputeT(1)
                                : static_cast<ComputeT>(a_ptr[is_trans ? (col * lda + p) : (p * lda + col)]);
                            acc += static_cast<ComputeT>(b_ptr[row * ldb + p]) * a_val;
                        }
                    }
                    return static_cast<SyclT>(alpha_c * acc);
                };

                if (c_ptr != b_ptr)
                {
                    return q.parallel_for(
                        sycl::range<2>(static_cast<std::size_t>(m), static_cast<std::size_t>(n)),
                        [=](sycl::id<2> idx) {
                            const auto row = static_cast<dim_t>(idx[0]);
                            const auto col = static_cast<dim_t>(idx[1]);
                            c_ptr[row * ldb + col] = eval_elem(row, col);
                        });
                }

                return q.single_task([=]() {
                    if (is_left)
                    {
                        if (eff_upper)
                        {
                            for (dim_t row = 0; row < m; ++row)
                                for (dim_t col = 0; col < n; ++col)
                                    c_ptr[row * ldb + col] = eval_elem(row, col);
                        }
                        else
                        {
                            for (dim_t row = m - 1; row >= 0; --row)
                                for (dim_t col = 0; col < n; ++col)
                                    c_ptr[row * ldb + col] = eval_elem(row, col);
                        }
                    }
                    else
                    {
                        if (eff_upper)
                        {
                            for (dim_t row = 0; row < m; ++row)
                                for (dim_t col = n - 1; col >= 0; --col)
                                    c_ptr[row * ldb + col] = eval_elem(row, col);
                        }
                        else
                        {
                            for (dim_t row = 0; row < m; ++row)
                                for (dim_t col = 0; col < n; ++col)
                                    c_ptr[row * ldb + col] = eval_elem(row, col);
                        }
                    }
                });
            }
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ trmm(const datatype dtype, const char horizontal, const char vertical, const char transpose_a, const char diagonal, void* c, const dim_t m, const dim_t n, const cumeric_t alpha, const void* a, const dim_t lda, const void* b, const dim_t ldb)
    {
        const auto a_buf = internal::to_scalar_buffer(dtype, alpha);
        return trmm(dtype, horizontal, vertical, transpose_a, diagonal, c, m, n, a_buf.ptr(), a, lda, b, ldb);
    }

    __event__ trmm(const char horizontal, const char vertical, const char transpose_a, const char diagonal, cumeric_t* c, const dim_t m, const dim_t n, const cumeric_t alpha, const cumeric_t* a, const dim_t lda, const cumeric_t* b, const dim_t ldb)
    {
        return trmm(default_type, horizontal, vertical, transpose_a, diagonal, c, m, n, &alpha, a, lda, b, ldb);
    }
}
