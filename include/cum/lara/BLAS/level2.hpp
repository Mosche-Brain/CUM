/**
 * @file level2.hpp
 * @brief BLAS Level 2 matrix-vector operations.
 * @author jaro
 * @details Implements general matrix-vector product (gemv), symmetric matrix-vector product (symv),
 *          and triangular matrix-vector product (trmv).
 */

#ifndef YANN_LEVEL2_HPP
#define YANN_LEVEL2_HPP

#include "cum/Core.hpp"

namespace cum::blas
{
    /**
     * @brief Computes general matrix-vector product (GEMV): @p y = @p alpha * op(A) * @p x + @p beta * @p y.
     * @param transa Matrix transposition flag ('N' or 'T').
     * @param m Number of rows of matrix A.
     * @param n Number of columns of matrix A.
     * @param alpha Scalar multiplier for op(A)*x.
     * @param A Matrix buffer of leading dimension @p lda.
     * @param lda Leading dimension of matrix A.
     * @param x Input vector buffer.
     * @param incx Stride of vector x.
     * @param beta Scalar multiplier for vector y.
     * @param y Output/accumulator vector buffer.
     * @param incy Stride of vector y.
     * @return Asynchronous execution event.
     */
    __event__ gemv(char transa, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* A, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy);
    __event__ gemv(datatype dtype, char transa, dim_t m, dim_t n, cumeric_t alpha, const void* A, dim_t lda, const void* x, dim_t incx, cumeric_t beta, void* y, dim_t incy);
    __event__ gemv(datatype dtype, char transa, dim_t m, dim_t n, const void* alpha, const void* A, dim_t lda, const void* x, dim_t incx, const void* beta, void* y, dim_t incy);

    /**
     * @brief Computes symmetric matrix-vector product (SYMV): @p y = @p alpha * @p A * @p x + @p beta * @p y.
     * @param vertical Triangle specification ('U' or 'L').
     * @param n Order of matrix A.
     * @param alpha Scalar multiplier.
     * @param A Symmetric matrix buffer.
     * @param lda Leading dimension of A.
     * @param x Input vector buffer.
     * @param incx Stride of vector x.
     * @param beta Scalar multiplier for y.
     * @param y Output/accumulator vector buffer.
     * @param incy Stride of vector y.
     * @return Asynchronous execution event.
     */
    __event__ symv(char vertical, dim_t n, cumeric_t alpha, const cumeric_t* A, dim_t lda, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy);
    __event__ symv(datatype dtype, char vertical, dim_t n, cumeric_t alpha, const void* A, dim_t lda, const void* x, dim_t incx, cumeric_t beta, void* y, dim_t incy);
    __event__ symv(datatype dtype, char vertical, dim_t n, const void* alpha, const void* A, dim_t lda, const void* x, dim_t incx, const void* beta, void* y, dim_t incy);

    /**
     * @brief Computes triangular matrix-vector product (TRMV): @p x = op(A) * @p x.
     * @param vertical Triangle specification ('U' or 'L').
     * @param transa Transpose flag ('N' or 'T').
     * @param diag Unit diagonal flag ('U' or 'N').
     * @param n Order of matrix A.
     * @param A Triangular matrix buffer.
     * @param lda Leading dimension of A.
     * @param x Vector buffer modified in place.
     * @param incx Stride of vector x.
     * @return Asynchronous execution event.
     */
    __event__ trmv(char vertical, char transa, char diag, dim_t n, const cumeric_t* A, dim_t lda, cumeric_t* x, dim_t incx);
    __event__ trmv(datatype dtype, char vertical, char transa, char diag, dim_t n, const void* A, dim_t lda, void* x, dim_t incx);
} // namespace cum::blas

#endif //YANN_LEVEL2_HPP
