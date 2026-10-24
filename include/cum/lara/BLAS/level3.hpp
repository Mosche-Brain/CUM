/**
 * @file level3.hpp
 * @brief BLAS Level 3 matrix-matrix operations.
 * @author jaro
 * @details Implements general matrix multiplication (gemm), symmetric matrix multiplication (symm),
 *          and triangular matrix multiplication (trmm).
 */

#ifndef YANN_LEVEL3_HPP
#define YANN_LEVEL3_HPP

#include "cum/Core.hpp"
#include "cum/lara/BLAS/types.hpp"

namespace cum::blas
{
    /**
     * @brief General matrix-matrix multiplication (GEMM): @p c = @p alpha * op(a) * op(b) + @p beta * @p c.
     * @param transpose_a Transpose flag for matrix A ('N' or 'T').
     * @param transpose_b Transpose flag for matrix B ('N' or 'T').
     * @param m Rows of op(A) and C.
     * @param n Columns of op(B) and C.
     * @param k Columns of op(A) and rows of op(B).
     * @param alpha Scalar multiplier for A*B.
     * @param a Left matrix buffer.
     * @param lda Leading dimension of A.
     * @param b Right matrix buffer.
     * @param ldb Leading dimension of B.
     * @param beta Scalar multiplier for C.
     * @param c Output matrix buffer.
     * @param ldc Leading dimension of C.
     * @return Asynchronous execution event.
     */
    __event__ gemm(char transpose_a, char transpose_b, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc);
    __event__ gemm(datatype dtype, char transpose_a, char transpose_b, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const void* a, dim_t lda, const void* b, dim_t ldb, cumeric_t beta, void* c, dim_t ldc);
    __event__ gemm(datatype dtype, char transpose_a, char transpose_b, dim_t m, dim_t n, dim_t k, const void* alpha, const void* a, dim_t lda, const void* b, dim_t ldb, const void* beta, void* c, dim_t ldc);

    /**
     * @brief Symmetric matrix-matrix multiplication (SYMM): @p c = @p alpha * @p a * @p b + @p beta * @p c.
     * @param horizontal Side multiplier position ('L' or 'R').
     * @param vertical Triangle specification ('U' or 'L').
     * @param m Rows of C.
     * @param n Columns of C.
     * @param k Inner dimension.
     * @param alpha Scalar multiplier.
     * @param a Symmetric matrix buffer.
     * @param lda Leading dimension of A.
     * @param b General matrix buffer.
     * @param ldb Leading dimension of B.
     * @param beta Scalar multiplier for C.
     * @param c Output matrix buffer.
     * @param ldc Leading dimension of C.
     * @return Asynchronous execution event.
     */
    __event__ symm(char horizontal, char vertical, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb, cumeric_t beta, cumeric_t* c, dim_t ldc);
    __event__ symm(datatype dtype, char horizontal, char vertical, dim_t m, dim_t n, dim_t k, cumeric_t alpha, const void* a, dim_t lda, const void* b, dim_t ldb, cumeric_t beta, void* c, dim_t ldc);
    __event__ symm(datatype dtype, char horizontal, char vertical, dim_t m, dim_t n, dim_t k, const void* alpha, const void* a, dim_t lda, const void* b, dim_t ldb, const void* beta, void* c, dim_t ldc);

    /**
     * @brief Triangular matrix-matrix multiplication (TRMM): @p b = @p alpha * op(a) * @p b.
     * @param horizontal Side specification ('L' or 'R').
     * @param vertical Triangle specification ('U' or 'L').
     * @param transpose_a Transpose flag for A ('N' or 'T').
     * @param diagonal Diagonal unit flag ('U' or 'N').
     * @param c Matrix buffer.
     * @param m Rows of C.
     * @param n Columns of C.
     * @param alpha Scalar multiplier.
     * @param a Triangular matrix buffer.
     * @param lda Leading dimension of A.
     * @param b Right matrix buffer.
     * @param ldb Leading dimension of B.
     * @return Asynchronous execution event.
     */
    __event__ trmm(char horizontal, char vertical, char transpose_a, char diagonal, cumeric_t* c, dim_t m, dim_t n, cumeric_t alpha, const cumeric_t* a, dim_t lda, const cumeric_t* b, dim_t ldb);
    __event__ trmm(datatype dtype, char horizontal, char vertical, char transpose_a, char diagonal, void* c, dim_t m, dim_t n, cumeric_t alpha, const void* a, dim_t lda, const void* b, dim_t ldb);
    __event__ trmm(datatype dtype, char horizontal, char vertical, char transpose_a, char diagonal, void* c, dim_t m, dim_t n, const void* alpha, const void* a, dim_t lda, const void* b, dim_t ldb);
} // namespace cum::blas

#endif //YANN_LEVEL3_HPP
