#ifndef CUM_C_BLAS_LEVEL3_H
#define CUM_C_BLAS_LEVEL3_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BLAS level 3 (single precision, row-major). Flags are characters:
 * transpose 'N'/'T', `side` 'L'/'R', triangle `uplo` 'U'/'L', diagonal `diag` 'U'/'N'.
 * See cum/event.h for the `event` convention. */

/* C := alpha * op(A) * op(B) + beta * C; C is m x n, op(A) is m x k, op(B) is k x n */
CUM_C_API cum_status_t cum_gemm(char transpose_a, char transpose_b, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc, cum_event_t** event);
CUM_C_API cum_status_t cum_symm(char side, char uplo, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc, cum_event_t** event);
CUM_C_API cum_status_t cum_trmm(char side, char uplo, char transpose_a, char diag, cumeric_t* c, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cum_event_t** event);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_BLAS_LEVEL3_H */
