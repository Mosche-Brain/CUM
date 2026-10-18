//
// Created by jaro on 8/2/26.
//

#ifndef YANN_LEVEL2_HPP
#define YANN_LEVEL2_HPP

#include "cum/Core.hpp"

namespace cum::blas
{
    __event__ gemv(char transa, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* A, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy);
    __event__ gemv(datatype dtype, char transa, dim_t m, dim_t n, cumeric_t alpha, const void* A, dim_t lda, const void* x, dim_t incx, cumeric_t beta, void* y, dim_t incy);
    __event__ gemv(datatype dtype, char transa, dim_t m, dim_t n, const void* alpha, const void* A, dim_t lda, const void* x, dim_t incx, const void* beta, void* y, dim_t incy);

    __event__ symv(char vertical, dim_t n, cumeric_t alpha, const cumeric_t* A, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy);
    __event__ symv(datatype dtype, char vertical, dim_t n, cumeric_t alpha, const void* A, dim_t lda, const void* x, dim_t incx, cumeric_t beta, void* y, dim_t incy);
    __event__ symv(datatype dtype, char vertical, dim_t n, const void* alpha, const void* A, dim_t lda, const void* x, dim_t incx, const void* beta, void* y, dim_t incy);

    __event__ trmv(char vertical, char transa, char diag, dim_t n, const cumeric_t* A, dim_t lda, cumeric_t* x, dim_t incx);
    __event__ trmv(datatype dtype, char vertical, char transa, char diag, dim_t n, const void* A, dim_t lda, void* x, dim_t incx);
}

#endif //YANN_LEVEL2_HPP
