#ifndef CUM_C_MEMORY_H
#define CUM_C_MEMORY_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Raw BLAS functions require device-accessible (unified shared) memory. Use these helpers,
 * or the data pointers of tensors, matrices and vectors, to obtain such buffers. */

/* Allocates `count` cumeric_t elements. */
CUM_C_API cum_status_t cum_memory_allocate(dim_t count, cumeric_t** data);
CUM_C_API cum_status_t cum_memory_free(void* data);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_MEMORY_H */
