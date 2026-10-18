//
// Created by jaro on 8/30/26.
//

#ifndef YANN_VECOPS_HPP
#define YANN_VECOPS_HPP

#include "cum/Core.hpp"

#include "BLAS/level1.hpp"

namespace cum::lara
{
    __event__ vadd(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vadd(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    __event__ vadd(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vadd(datatype dtype, void* v, const void* u, dim_t n);

    __event__ vadd_batch(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* r, const void* v, const void* u, dim_t n, dim_t batch_size);

    __event__ vadd_batch(cumeric_t* v, const cumeric_t* u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* v, const void* u, dim_t n, dim_t batch_size);

    __event__ vadd_batch(cumeric_t* r, dim_t stride_r, const cumeric_t* v, dim_t stride_v, const cumeric_t* u, dim_t stride_u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* r, dim_t stride_r, const void* v, dim_t stride_v, const void* u, dim_t stride_u, dim_t n, dim_t batch_size);

    __event__ vadd_batch(cumeric_t* v, dim_t stride_v, const cumeric_t* u, dim_t stride_u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* v, dim_t stride_v, const void* u, dim_t stride_u, dim_t n, dim_t batch_size);

    __event__ vsub(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vsub(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    __event__ vsub(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vsub(datatype dtype, void* v, const void* u, dim_t n);

    __event__ vmul(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vmul(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    __event__ vmul(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vmul(datatype dtype, void* v, const void* u, dim_t n);

    __event__ vdiv(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vdiv(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    __event__ vdiv(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vdiv(datatype dtype, void* v, const void* u, dim_t n);
}


#endif //YANN_VECOPS_HPP
