#ifndef CUM_C_BLAS_LEVEL1_H
#define CUM_C_BLAS_LEVEL1_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BLAS level 1 (single precision, strided). See cum/event.h for the `event` convention.
 * `result` pointers must refer to device-accessible memory (see cum/memory.h) and, for
 * asynchronous calls, stay valid until the event completes. */

/* y := alpha * x + y */
CUM_C_API cum_status_t cum_axpy(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t* y, dim_t incy, cum_event_t** event);
/* y := alpha * x + beta * y */
CUM_C_API cum_status_t cum_axpby(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy, cum_event_t** event);

CUM_C_API cum_status_t cum_dot(dim_t n, const cumeric_t* x, dim_t incx, const cumeric_t* y, dim_t incy, cumeric_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_asum(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_nrm2(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_iamax(dim_t n, const cumeric_t* x, dim_t incx, dim_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_iamin(dim_t n, const cumeric_t* x, dim_t incx, dim_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_amax(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_amin(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result, cum_event_t** event);
CUM_C_API cum_status_t cum_scal(dim_t n, cumeric_t alpha, cumeric_t* x, dim_t incx, cum_event_t** event);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_BLAS_LEVEL1_H */
