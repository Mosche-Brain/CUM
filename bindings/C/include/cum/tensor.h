#ifndef CUM_C_TENSOR_H
#define CUM_C_TENSOR_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Construction / destruction. `dst` arguments of binary operations must be existing tensors,
 * their previous content is replaced by the result. */
CUM_C_API cum_status_t cum_tensor_create(
    cum_tensor_t** tensor,
    cum_shape_t shape,
    cum_datatype_t datatype,
    cum_layout_t layout
);
CUM_C_API cum_status_t cum_tensor_create_zeros(cum_tensor_t** tensor, cum_shape_t shape);
CUM_C_API cum_status_t cum_tensor_create_ones(cum_tensor_t** tensor, cum_shape_t shape);
CUM_C_API cum_status_t cum_tensor_create_random(cum_tensor_t** tensor, cum_shape_t shape, cumeric_t min, cumeric_t max);
/* Creates an FP32 tensor and copies `shape` elements worth of `data` (row-major) into it. */
CUM_C_API cum_status_t cum_tensor_create_from_data(cum_tensor_t** tensor, cum_shape_t shape, const cumeric_t* data);
CUM_C_API cum_status_t cum_tensor_destroy(cum_tensor_t* tensor);
/* Deep copy of `src` into the existing tensor `dst`. */
CUM_C_API cum_status_t cum_tensor_copy(cum_tensor_t* dst, const cum_tensor_t* src);
/* Deep copy of `src` into a newly created tensor. */
CUM_C_API cum_status_t cum_tensor_clone(cum_tensor_t** dst, const cum_tensor_t* src);

/* Properties. `size` is in bytes, `length` is the number of elements. When `dims` is NULL
 * only `rank` is written. */
CUM_C_API cum_status_t cum_tensor_shape(
    const cum_tensor_t* tensor,
    dim_t* dims,
    size_t capacity,
    size_t* rank
);
CUM_C_API cum_status_t cum_tensor_size(const cum_tensor_t* tensor, dim_t* size);
CUM_C_API cum_status_t cum_tensor_length(const cum_tensor_t* tensor, dim_t* length);
CUM_C_API cum_status_t cum_tensor_datatype(const cum_tensor_t* tensor, cum_datatype_t* datatype);
CUM_C_API cum_status_t cum_tensor_layout(const cum_tensor_t* tensor, cum_layout_t* layout);
CUM_C_API cum_status_t cum_tensor_data(const cum_tensor_t* tensor, const void** data);
CUM_C_API cum_status_t cum_tensor_mutable_data(cum_tensor_t* tensor, void** data);

/* Shape manipulation. */
CUM_C_API cum_status_t cum_tensor_reshape(cum_tensor_t* dst, const cum_tensor_t* src, cum_shape_t shape);
CUM_C_API cum_status_t cum_tensor_transpose(cum_tensor_t* dst, const cum_tensor_t* src);

CUM_C_API cum_status_t cum_tensor_fill(cum_tensor_t* tensor, cumeric_t scalar);

/* Element-wise arithmetic. */
CUM_C_API cum_status_t cum_tensor_add(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_sub(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_mul(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_div(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs);
/* Matrix multiplication (batched over leading dimensions). */
CUM_C_API cum_status_t cum_tensor_mmul(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs);

CUM_C_API cum_status_t cum_tensor_add_in_place(cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_sub_in_place(cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_mul_in_place(cum_tensor_t* lhs, const cum_tensor_t* rhs);
CUM_C_API cum_status_t cum_tensor_div_in_place(cum_tensor_t* lhs, const cum_tensor_t* rhs);

/* Tensor-scalar arithmetic. */
CUM_C_API cum_status_t cum_tensor_add_scalar(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t scalar);
CUM_C_API cum_status_t cum_tensor_sub_scalar(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t scalar);
CUM_C_API cum_status_t cum_tensor_mul_scalar(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t scalar);
CUM_C_API cum_status_t cum_tensor_div_scalar(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t scalar);
CUM_C_API cum_status_t cum_tensor_scale(cum_tensor_t* tensor, cumeric_t scalar);

/* Unary functions. */
CUM_C_API cum_status_t cum_tensor_sqrt(cum_tensor_t* dst, const cum_tensor_t* src);
CUM_C_API cum_status_t cum_tensor_square(cum_tensor_t* dst, const cum_tensor_t* src);
CUM_C_API cum_status_t cum_tensor_abs(cum_tensor_t* dst, const cum_tensor_t* src);
CUM_C_API cum_status_t cum_tensor_log(cum_tensor_t* dst, const cum_tensor_t* src);
CUM_C_API cum_status_t cum_tensor_clamp(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t min, cumeric_t max);

/* Reductions. */
CUM_C_API cum_status_t cum_tensor_sum(const cum_tensor_t* tensor, cumeric_t* result);
CUM_C_API cum_status_t cum_tensor_mean(const cum_tensor_t* tensor, cumeric_t* result);
CUM_C_API cum_status_t cum_tensor_norm(const cum_tensor_t* tensor, cumeric_t* result);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_TENSOR_H */
