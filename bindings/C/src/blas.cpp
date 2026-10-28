#include "cum/cum.h"
#include "cum/lara/BLAS.hpp"
#include "cum/detail/submit.hpp"

using cum_c::submit;

extern "C"
{
    /* Level 1 */

    cum_status_t cum_axpy(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t* y, dim_t incy, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::axpy(n, alpha, x, incx, y, incy); });
    }

    cum_status_t cum_axpby(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::axpy(n, alpha, x, incx, beta, y, incy); });
    }

    cum_status_t cum_dot(dim_t n, const cumeric_t* x, dim_t incx, const cumeric_t* y, dim_t incy, cumeric_t* result, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::dot(n, x, incx, y, incy, result); });
    }

    #define CUM_BLAS_REDUCTION(name, result_type) \
    cum_status_t cum_##name(dim_t n, const cumeric_t* x, dim_t incx, result_type* result, cum_event_t** event) \
    { \
        return submit(event, [&] { return cum::blas::name(n, x, incx, result); }); \
    }

    CUM_BLAS_REDUCTION(asum, cumeric_t)
    CUM_BLAS_REDUCTION(nrm2, cumeric_t)
    CUM_BLAS_REDUCTION(iamax, dim_t)
    CUM_BLAS_REDUCTION(iamin, dim_t)
    CUM_BLAS_REDUCTION(amax, cumeric_t)
    CUM_BLAS_REDUCTION(amin, cumeric_t)

    #undef CUM_BLAS_REDUCTION

    cum_status_t cum_scal(dim_t n, cumeric_t alpha, cumeric_t* x, dim_t incx, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::scal(n, alpha, x, incx); });
    }

    /* Level 2 */

    cum_status_t cum_gemv(char transa, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::gemv(transa, m, n, alpha, a, lda, x, incx, beta, y, incy); });
    }

    cum_status_t cum_symv(char uplo, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::symv(uplo, n, alpha, a, lda, x, incx, beta, y, incy); });
    }

    cum_status_t cum_trmv(char uplo, char transa, char diag, dim_t n, const cumeric_t* a, dim_t lda, cumeric_t* x, dim_t incx, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::trmv(uplo, transa, diag, n, a, lda, x, incx); });
    }

    /* Level 3 */

    cum_status_t cum_gemm(char transpose_a, char transpose_b, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::gemm(transpose_a, transpose_b, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc); });
    }

    cum_status_t cum_symm(char side, char uplo, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::symm(side, uplo, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc); });
    }

    cum_status_t cum_trmm(char side, char uplo, char transpose_a, char diag, cumeric_t* c, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cum_event_t** event)
    {
        return submit(event, [&] { return cum::blas::trmm(side, uplo, transpose_a, diag, c, m, n, alpha, a, lda, b, ldb); });
    }
}
