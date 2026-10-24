/**
 * @file matops.hpp
 * @brief High-level asynchronous matrix multiplication and transpose operations.
 * @author jaro
 * @details Provides dependency-tracked asynchronous matrix multiplication (mmul) and transpose (mtrans).
 */

#pragma once

#include "cum/Core.hpp"
#include "BLAS/level3.hpp"

namespace cum::lara
{
    /**
     * @brief Asynchronous matrix multiplication: @p C = @p A * @p B.
     * @param C Output matrix buffer (m x n).
     * @param A Left input matrix buffer (m x k).
     * @param B Right input matrix buffer (k x n).
     * @param m Rows of A and C.
     * @param n Columns of B and C.
     * @param k Inner dimension.
     * @param depencies Event dependencies to wait on before executing.
     * @return Asynchronous execution event.
     */
    __event__ mmul(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});

    /**
     * @brief In-place matrix multiplication: @p A = @p A * @p B.
     * @param A Matrix buffer modified in place.
     * @param B Right input matrix buffer.
     * @param m Rows of A.
     * @param n Columns of B.
     * @param k Inner dimension.
     * @return Asynchronous execution event.
     */
    __event__ mmul(cumeric_t* A, const cumeric_t* B, dim_t m, dim_t n, dim_t k);

    __event__ mmul(datatype dtype, void* C, const void* A, const void* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});
    __event__ mmul(datatype dtype, void* A, const void* B, dim_t m, dim_t n, dim_t k, __events__ depencies={});

    /**
     * @brief Asynchronous matrix transpose: @p At = @p A^T.
     * @param At Output transposed buffer (n x m).
     * @param A Input matrix buffer (m x n).
     * @param m Rows of input matrix A.
     * @param n Columns of input matrix A.
     * @param depencies Event dependencies.
     * @return Asynchronous execution event.
     */
    __event__ mtrans(cumeric_t* At, const cumeric_t* A, dim_t m, dim_t n, __events__ depencies={});

    /**
     * @brief Asynchronous in-place matrix transpose for square matrices.
     * @param A Matrix buffer modified in place.
     * @param m Rows of matrix A.
     * @param n Columns of matrix A.
     * @param depencies Event dependencies.
     * @return Asynchronous execution event.
     */
    __event__ mtrans(cumeric_t* A, dim_t m, dim_t n, __events__ depencies={});

    __event__ mtrans(datatype dtype, void* At, const void* A, dim_t m, dim_t n, __events__ depencies={});
    __event__ mtrans(datatype dtype, void* A, dim_t m, dim_t n, __events__ depencies={});
} // namespace cum::lara
