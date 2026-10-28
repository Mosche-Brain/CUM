#ifndef CUM_C_BLAS_LEVEL2_H
#define CUM_C_BLAS_LEVEL2_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BLAS level 2 (single precision, row-major). Flags are characters:
 * transpose 'N'/'T', triangle `uplo` 'U'/'L', diagonal `diag` 'U' (unit) / 'N'.
 * See cum/event.h for the `event` convention. */

/* y := alpha * op(A) * x + beta * y, A is m x n */
CUM_C_API cum_status_t cum_gemv(char transa, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event);
/* y := alpha * A * x + beta * y, A is symmetric n x n */
CUM_C_API cum_status_t cum_symv(char uplo, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event);
/* x := op(A) * x, A is triangular n x n */
CUM_C_API cum_status_t cum_trmv(char uplo, char transa, char diag, dim_t n, const cumeric_t* a, dim_t lda, cumeric_t* x, dim_t incx, cum_event_t** event);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_BLAS_LEVEL2_H */
