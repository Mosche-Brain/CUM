/**
 * @file LinearAlgebra.hpp
 * @brief High-level linear algebra (LARA) routines for vectors and matrices.
 * @details Provides vector and matrix arithmetic, products, scaling, reductions, and norms
 *          operating on @ref cumeric_t buffers.
 */

#pragma once

#include "cum/Core.hpp"

namespace cum::lara /* LATK */
{
    /**
     * @brief Computes elementwise vector addition: @p r = @p v + @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Second input vector buffer.
     * @param N Number of elements.
     */
    void add(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Computes in-place elementwise vector addition: @p v += @p u.
     * @param v Vector buffer modified in place.
     * @param u Vector buffer to add.
     * @param N Number of elements.
     */
    void addInPlace(cumeric_t* v, const cumeric_t* u, std::size_t N);
    
    /**
     * @brief Adds scalar @p a to each element of vector @p v: @p r = @p v + @p a.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param a Scalar value to add.
     * @param N Number of elements.
     */
    void add(cumeric_t* r, const cumeric_t* v, const cumeric_t& a, std::size_t N);

    /**
     * @brief Adds scalar @p a to each element of vector @p v in-place: @p v += @p a.
     * @param v Vector buffer modified in place.
     * @param a Scalar value to add.
     * @param N Number of elements.
     */
    void addInPlace(cumeric_t* v, const cumeric_t& a, std::size_t N);

    /**
     * @brief Computes the sum of all elements in vector @p v.
     * @param r Output scalar result.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void sum(cumeric_t& r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Computes the sum of absolute values (L1 norm) of vector @p v.
     * @param r Output scalar result.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void asum(cumeric_t& r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Computes elementwise (Hadamard) product: @p r = @p v * @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Second input vector buffer.
     * @param N Number of elements.
     */
    void cwiseProduct(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Computes elementwise product in-place: @p v *= @p u.
     * @param v Vector buffer modified in place.
     * @param u Input vector buffer multiplier.
     * @param N Number of elements.
     */
    void cwiseProductInPlace(cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Multiplies vector elements by scalar: @p r = @p v * @p a.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param a Scalar multiplier.
     * @param n Number of elements.
     */
    void scale(cumeric_t* r, const cumeric_t* v, const cumeric_t& a, const std::size_t n);

    /**
     * @brief Multiplies vector elements by scalar in-place: @p v *= @p a.
     * @param v Vector buffer modified in place.
     * @param a Scalar multiplier.
     * @param n Number of elements.
     */
    void scaleInPlace(cumeric_t* v, const cumeric_t& a, const std::size_t n);

    /**
     * @brief Computes elementwise subtraction: @p r = @p v - @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Second input vector buffer.
     * @param N Number of elements.
     */
    void sub(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Computes elementwise subtraction in-place: @p v -= @p u.
     * @param v Vector buffer modified in place.
     * @param u Input vector buffer to subtract.
     * @param N Number of elements.
     */
    void subInPlace(cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Computes elementwise division: @p r = @p v / @p u.
     * @param r Output vector buffer.
     * @param v Numerator vector buffer.
     * @param u Denominator vector buffer.
     * @param N Number of elements.
     */
    void div(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Computes elementwise division in-place: @p v /= @p u.
     * @param v Vector buffer modified in place.
     * @param u Denominator vector buffer.
     * @param N Number of elements.
     */
    void divInPlace(cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Finds the index of the maximum element in vector @p v.
     * @param r Output scalar storing the index.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void argmax(cumeric_t* r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Finds the index of the minimum element in vector @p v.
     * @param r Output scalar storing the index.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void argmin(cumeric_t* r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Computes matrix addition: @p C = @p A + @p B.
     * @param C Output matrix buffer.
     * @param A First input matrix.
     * @param B Second input matrix.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matAdd(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, std::size_t rows, std::size_t cols);

    /**
     * @brief Computes matrix addition in-place: @p A += @p B.
     * @param A Matrix buffer modified in place.
     * @param B Matrix to add.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matAddInPlace(cumeric_t* A, const cumeric_t* B, std::size_t rows, std::size_t cols);

    /**
     * @brief Adds a row vector to every row of matrix @p matrix in-place.
     * @param matrix Matrix buffer modified in place.
     * @param row_vector Row vector of length @p cols.
     * @param rows Row count.
     * @param cols Column count.
     */
    void addRowVectorInPlace(cumeric_t* matrix, const cumeric_t* row_vector, std::size_t rows, std::size_t cols);

    /**
     * @brief Computes matrix subtraction: @p C = @p A - @p B.
     * @param C Output matrix buffer.
     * @param A First input matrix.
     * @param B Matrix to subtract.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matSub(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, std::size_t rows, std::size_t cols);

    /**
     * @brief Computes matrix subtraction in-place: @p A -= @p B.
     * @param A Matrix buffer modified in place.
     * @param B Matrix to subtract.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matSubInPlace(cumeric_t* A, const cumeric_t* B, std::size_t rows, std::size_t cols);

    /**
     * @brief Computes general matrix multiplication (GEMM): @p C = @p A * @p B.
     * @param C Output matrix buffer of size @p m x @p n.
     * @param A Left input matrix of size @p m x @p k.
     * @param B Right input matrix of size @p k x @p n.
     * @param m Number of rows of A and C.
     * @param n Number of columns of B and C.
     * @param k Number of columns of A and rows of B.
     */
    void matMul(cumeric_t* C, const cumeric_t* A, const cumeric_t* B, std::size_t m, std::size_t n, std::size_t k);

    /**
     * @brief In-place matrix multiplication: @p A = @p A * @p B.
     * @param A Matrix buffer modified in place.
     * @param B Right input matrix.
     * @param m Rows of A.
     * @param n Columns of B.
     * @param k Columns of A.
     */
    void matMulInPlace(cumeric_t* A, const cumeric_t* B, std::size_t m, std::size_t n, std::size_t k);

    /**
     * @brief Computes matrix-vector multiplication (GEMV): @p r = @p A * @p v.
     * @param r Output vector of length @p rows.
     * @param A Input matrix of size @p rows x @p cols.
     * @param v Input vector of length @p cols.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matVecMul(cumeric_t* r, const cumeric_t* A, const cumeric_t* v, std::size_t rows, std::size_t cols);

    /**
     * @brief Scales all elements of matrix: @p mat = @p old * @p a.
     * @param mat Output matrix buffer.
     * @param old Input matrix buffer.
     * @param a Scalar multiplier.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matScale(cumeric_t* mat, const cumeric_t* old, const cumeric_t& a, const std::size_t& rows, const std::size_t& cols);

    /**
     * @brief Scales all elements of matrix in-place: @p mat *= @p a.
     * @param mat Matrix buffer modified in place.
     * @param a Scalar multiplier.
     * @param rows Row count.
     * @param cols Column count.
     */
    void matScaleInPlace(cumeric_t* mat, const cumeric_t& a, const std::size_t& rows, const std::size_t& cols);

    /**
     * @brief Computes matrix transpose: @p A = @p B^T.
     * @param A Output matrix buffer of size @p cols x @p rows.
     * @param B Input matrix buffer of size @p rows x @p cols.
     * @param rows Number of rows in B.
     * @param cols Number of columns in B.
     */
    void transpose(cumeric_t* A, const cumeric_t* B, std::size_t rows, std::size_t cols);

    /**
     * @brief Transposes square matrix in-place.
     * @param mat Matrix buffer modified in place.
     * @param rows Row count.
     * @param cols Column count.
     */
    void transposeInPlace(cumeric_t* mat, std::size_t rows, std::size_t cols);

    /**
     * @brief Applies row-wise custom operation across rows in-place.
     * @param mat Matrix buffer modified in place.
     * @param arr Row-length array operand.
     * @param rows Row count.
     * @param cols Column count.
     * @param op Function pointer performing row-level computation.
     */
    void rowwiseOpInPlace(cumeric_t* mat, const cumeric_t* arr, std::size_t rows, std::size_t cols, void (*op)(cumeric_t* row, const cumeric_t* v, const std::size_t cols));

    /**
     * @brief Applies column-wise custom operation across columns in-place.
     * @param mat Matrix buffer modified in place.
     * @param arr Column-length array operand.
     * @param rows Row count.
     * @param cols Column count.
     * @param op Function pointer performing column-level computation.
     */
    void colwiseOpInPlace(cumeric_t* mat, const cumeric_t* arr, std::size_t rows, std::size_t cols, void (*op)(cumeric_t* col, const cumeric_t* v, const std::size_t rows));

    /**
     * @brief Computes row-wise sums into vector @p r.
     * @param r Output vector of length @p rows.
     * @param mat Input matrix of size @p rows x @p cols.
     * @param rows Row count.
     * @param cols Column count.
     */
    void rowwiseSum(cumeric_t* r, const cumeric_t* mat, std::size_t rows, std::size_t cols);

    /**
     * @brief Computes column-wise sums into vector @p r.
     * @param r Output vector of length @p cols.
     * @param mat Input matrix of size @p rows x @p cols.
     * @param rows Row count.
     * @param cols Column count.
     */
    void colwiseSum(cumeric_t* r, const cumeric_t* mat, std::size_t rows, std::size_t cols);

    /**
     * @brief Applies buffer transformation function out-of-place.
     * @param mat Output buffer.
     * @param old Input buffer.
     * @param func Transformation function pointer.
     */
    void transform(cumeric_t* mat, const cumeric_t* old, void (*func)(cumeric_t* data, const std::size_t size));

    /**
     * @brief Applies buffer transformation function in-place.
     * @param mat Buffer modified in place.
     * @param func Transformation function pointer.
     */
    void transformInPlace(cumeric_t* mat, void (*func)(cumeric_t* data, const std::size_t size));

    /**
     * @brief Applies scalar function to all elements out-of-place.
     * @param mat Output buffer.
     * @param old Input buffer.
     * @param func Scalar transformation function pointer.
     * @param N Number of elements.
     */
    void transform(cumeric_t* mat, const cumeric_t* old, cumeric_t (*func)(cumeric_t x), std::size_t N);

    /**
     * @brief Applies scalar function to all elements in-place.
     * @param mat Buffer modified in place.
     * @param func Scalar transformation function pointer.
     * @param N Number of elements.
     */
    void transformInPlace(cumeric_t* mat, cumeric_t (*func)(cumeric_t x), std::size_t N);

    /**
     * @brief Computes Euclidean L2 norm of vector: @p r = ||@p v||_2.
     * @param r Output scalar norm.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void norm(cumeric_t& r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Computes Euclidean L2 norm in-place.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void normInplace(cumeric_t* v, std::size_t N);

    /**
     * @brief Computes squared Euclidean L2 norm: @p r = ||@p v||_2^2.
     * @param r Output scalar squared norm.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void squaredNorm(cumeric_t& r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Normalizes vector to unit L2 norm out-of-place: @p r = @p v / ||@p v||_2.
     * @param r Output normalized vector.
     * @param v Input vector buffer.
     * @param N Number of elements.
     */
    void normalize(cumeric_t* r, const cumeric_t* v, std::size_t N);

    /**
     * @brief Normalizes vector to unit L2 norm in-place: @p v /= ||@p v||_2.
     * @param v Vector buffer normalized in place.
     * @param N Number of elements.
     */
    void normalizeInPlace(cumeric_t* v, std::size_t N);
} // namespace cum::lara
