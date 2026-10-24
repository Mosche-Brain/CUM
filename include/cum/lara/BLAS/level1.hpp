/**
 * @file level1.hpp
 * @brief BLAS Level 1 vector-vector and vector-scalar operations.
 * @author jaro
 * @details Implements axpy, dot products, scaling (scal), norms (nrm2), and min/max reductions (iamax, iamin).
 */

#ifndef YANN_LEVEL1_HPP
#define YANN_LEVEL1_HPP

#include "cum/Core.hpp"

namespace cum::blas
{
    /* Vector-scalar ops */

    /**
     * @brief Computes vector-scalar multiply and accumulate: @p y = @p alpha * @p x + @p y.
     * @param n Number of elements.
     * @param alpha Scalar multiplier.
     * @param x Input vector buffer.
     * @param incx Stride between elements of x.
     * @param y Output/accumulator vector buffer.
     * @param incy Stride between elements of y.
     * @return Asynchronous execution event.
     */
    __event__ axpy(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t* y, dim_t incy);
    __event__ axpy(datatype dtype, dim_t n, cumeric_t alpha, const void* x, dim_t incx, void* y, dim_t incy);
    __event__ axpy(datatype dtype, dim_t n, const void* alpha, const void* x, dim_t incx, void* y, dim_t incy);

    /**
     * @brief Computes scaled vector addition: @p y = @p alpha * @p x + @p beta * @p y.
     * @param n Number of elements.
     * @param alpha Scalar multiplier for x.
     * @param x Input vector buffer.
     * @param incx Stride between elements of x.
     * @param beta Scalar multiplier for y.
     * @param y Output/accumulator vector buffer.
     * @param incy Stride between elements of y.
     * @return Asynchronous execution event.
     */
    __event__ axpy(dim_t n, cumeric_t alpha, const cumeric_t* x, dim_t incx, cumeric_t beta, cumeric_t* y, dim_t incy);
    __event__ axpy(datatype dtype, dim_t n, cumeric_t alpha, const void* x, dim_t incx, cumeric_t beta, void* y, dim_t incy);
    __event__ axpy(datatype dtype, dim_t n, const void* alpha, const void* x, dim_t incx, const void* beta, void* y, dim_t incy);

    /* Vector-vector ops */

    /**
     * @brief Computes dot product of two vectors: @p result = @p x^T * @p y.
     * @param n Number of elements.
     * @param x First vector buffer.
     * @param incx Stride of x.
     * @param y Second vector buffer.
     * @param incy Stride of y.
     * @param result Pointer to output scalar result.
     * @return Asynchronous execution event.
     */
    __event__ dot(dim_t n, const cumeric_t* x, dim_t incx, const cumeric_t* y, dim_t incy, cumeric_t* result);
    __event__ dot(datatype dtype, dim_t n, const void* x, dim_t incx, const void* y, dim_t incy, void* result);

    /* Vector to scalar reductions */

    /**
     * @brief Computes sum of magnitudes (L1 norm): @p result = sum(|x_i|).
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output scalar result.
     * @return Asynchronous execution event.
     */
    __event__ asum(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result);
    __event__ asum(datatype dtype, dim_t n, const void* x, dim_t incx, void* result);

    /**
     * @brief Computes Euclidean L2 norm: @p result = ||x||_2.
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output scalar result.
     * @return Asynchronous execution event.
     */
    __event__ nrm2(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result);
    __event__ nrm2(datatype dtype, dim_t n, const void* x, dim_t incx, void* result);

    /**
     * @brief Finds the index of the first element having the maximum absolute value.
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output index.
     * @return Asynchronous execution event.
     */
    __event__ iamax(dim_t n, const cumeric_t* x, dim_t incx, dim_t* result);
    __event__ iamax(datatype dtype, dim_t n, const void* x, dim_t incx, dim_t* result);

    /**
     * @brief Finds the index of the first element having the minimum absolute value.
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output index.
     * @return Asynchronous execution event.
     */
    __event__ iamin(dim_t n, const cumeric_t* x, dim_t incx, dim_t* result);
    __event__ iamin(datatype dtype, dim_t n, const void* x, dim_t incx, dim_t* result);

    /**
     * @brief Computes maximum absolute value in vector.
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output scalar result.
     * @return Asynchronous execution event.
     */
    __event__ amax(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result);
    __event__ amax(datatype dtype, dim_t n, const void* x, dim_t incx, void* result);

    /**
     * @brief Computes minimum absolute value in vector.
     * @param n Number of elements.
     * @param x Vector buffer.
     * @param incx Stride of x.
     * @param result Pointer to output scalar result.
     * @return Asynchronous execution event.
     */
    __event__ amin(dim_t n, const cumeric_t* x, dim_t incx, cumeric_t* result);
    __event__ amin(datatype dtype, dim_t n, const void* x, dim_t incx, void* result);

    /**
     * @brief Scales a vector by a scalar: @p x = @p alpha * @p x.
     * @param n Number of elements.
     * @param alpha Scalar multiplier.
     * @param x Vector buffer scaled in place.
     * @param incx Stride of x.
     * @return Asynchronous execution event.
     */
    __event__ scal(dim_t n, cumeric_t alpha, cumeric_t* x, dim_t incx);
    __event__ scal(datatype dtype, dim_t n, cumeric_t alpha, void* x, dim_t incx);
    __event__ scal(datatype dtype, dim_t n, const void* alpha, void* x, dim_t incx);
} // namespace cum::blas

#endif //YANN_LEVEL1_HPP
