#ifndef CUM_C_MATRIX_H
#define CUM_C_MATRIX_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cum_matrix_t cum_matrix_t;

/* `dst` arguments of binary operations must be existing matrices, their previous content
 * is replaced by the result. Matrices are stored row-major. */
cum_status_t cum_matrix_create(cum_matrix_t** matrix, dim_t rows, dim_t cols);
cum_status_t cum_matrix_create_filled(cum_matrix_t** matrix, dim_t rows, dim_t cols, cumeric_t value);
cum_status_t cum_matrix_create_zeros(cum_matrix_t** matrix, dim_t rows, dim_t cols);
cum_status_t cum_matrix_create_ones(cum_matrix_t** matrix, dim_t rows, dim_t cols);
cum_status_t cum_matrix_create_random(cum_matrix_t** matrix, dim_t rows, dim_t cols, cumeric_t min, cumeric_t max);
/* Copies rows * cols elements from `data`. */
cum_status_t cum_matrix_create_from_data(cum_matrix_t** matrix, dim_t rows, dim_t cols, const cumeric_t* data);
cum_status_t cum_matrix_destroy(cum_matrix_t* matrix);
/* Deep copy of `src` into the existing matrix `dst`. */
cum_status_t cum_matrix_copy(cum_matrix_t* dst, const cum_matrix_t* src);
/* Deep copy of `src` into a newly created matrix. */
cum_status_t cum_matrix_clone(cum_matrix_t** dst, const cum_matrix_t* src);

cum_status_t cum_matrix_rows(const cum_matrix_t* matrix, dim_t* rows);
cum_status_t cum_matrix_cols(const cum_matrix_t* matrix, dim_t* cols);
cum_status_t cum_matrix_size(const cum_matrix_t* matrix, dim_t* size);
cum_status_t cum_matrix_data(const cum_matrix_t* matrix, const cumeric_t** data);
cum_status_t cum_matrix_mutable_data(cum_matrix_t* matrix, cumeric_t** data);
cum_status_t cum_matrix_fill(cum_matrix_t* matrix, cumeric_t value);
cum_status_t cum_matrix_get(const cum_matrix_t* matrix, dim_t row, dim_t col, cumeric_t* value);
cum_status_t cum_matrix_set(cum_matrix_t* matrix, dim_t row, dim_t col, cumeric_t value);

cum_status_t cum_matrix_transpose(cum_matrix_t* dst, const cum_matrix_t* src);
cum_status_t cum_matrix_reshape(cum_matrix_t* dst, const cum_matrix_t* src, dim_t rows, dim_t cols);

cum_status_t cum_matrix_add(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_sub(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs);
/* Matrix product. */
cum_status_t cum_matrix_mul(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_eltwise_mul(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_div(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs);

cum_status_t cum_matrix_add_in_place(cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_sub_in_place(cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_mul_in_place(cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_eltwise_mul_in_place(cum_matrix_t* lhs, const cum_matrix_t* rhs);
cum_status_t cum_matrix_div_in_place(cum_matrix_t* lhs, const cum_matrix_t* rhs);

cum_status_t cum_matrix_add_scalar(cum_matrix_t* dst, const cum_matrix_t* src, cumeric_t scalar);
cum_status_t cum_matrix_mul_scalar(cum_matrix_t* dst, const cum_matrix_t* src, cumeric_t scalar);
cum_status_t cum_matrix_div_scalar(cum_matrix_t* dst, const cum_matrix_t* src, cumeric_t scalar);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_MATRIX_H */
