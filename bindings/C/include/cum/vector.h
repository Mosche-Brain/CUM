#ifndef CUM_C_VECTOR_H
#define CUM_C_VECTOR_H

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cum_vector_t cum_vector_t;

cum_status_t cum_vector_create(cum_vector_t** vector, dim_t length);
cum_status_t cum_vector_create_filled(cum_vector_t** vector, dim_t length, cumeric_t value);
cum_status_t cum_vector_create_from_data(cum_vector_t** vector, dim_t length, const cumeric_t* data);
cum_status_t cum_vector_destroy(cum_vector_t* vector);
cum_status_t cum_vector_clone(cum_vector_t** dst, const cum_vector_t* src);

cum_status_t cum_vector_length(const cum_vector_t* vector, dim_t* length);
cum_status_t cum_vector_data(const cum_vector_t* vector, const cumeric_t** data);
cum_status_t cum_vector_mutable_data(cum_vector_t* vector, cumeric_t** data);
cum_status_t cum_vector_fill(cum_vector_t* vector, cumeric_t value);

cum_status_t cum_vector_add(cum_vector_t* dst, const cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_sub(cum_vector_t* dst, const cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_mul(cum_vector_t* dst, const cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_div(cum_vector_t* dst, const cum_vector_t* lhs, const cum_vector_t* rhs);

cum_status_t cum_vector_add_in_place(cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_sub_in_place(cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_mul_in_place(cum_vector_t* lhs, const cum_vector_t* rhs);
cum_status_t cum_vector_div_in_place(cum_vector_t* lhs, const cum_vector_t* rhs);

cum_status_t cum_vector_scale(cum_vector_t* vector, cumeric_t scalar);
cum_status_t cum_vector_dot(const cum_vector_t* lhs, const cum_vector_t* rhs, cumeric_t* result);
cum_status_t cum_vector_sum(const cum_vector_t* vector, cumeric_t* result);
cum_status_t cum_vector_norm(const cum_vector_t* vector, cumeric_t* result);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_VECTOR_H */
