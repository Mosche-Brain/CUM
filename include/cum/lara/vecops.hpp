/**
 * @file vecops.hpp
 * @brief High-level asynchronous vector arithmetic operations (vadd, vsub, vmul, vdiv, batched operations).
 * @author jaro
 */

#ifndef YANN_VECOPS_HPP
#define YANN_VECOPS_HPP

#include "cum/Core.hpp"
#include "BLAS/level1.hpp"

namespace cum::lara
{
    /**
     * @brief Asynchronous elementwise vector addition: @p r = @p v + @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Second input vector buffer.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vadd(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vadd(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous in-place vector addition: @p v += @p u.
     * @param v Vector buffer modified in place.
     * @param u Vector buffer to add.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vadd(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vadd(datatype dtype, void* v, const void* u, dim_t n);

    /**
     * @brief Batched vector addition out-of-place across @p batch_size vectors.
     * @param r Output batch buffer.
     * @param v First input batch buffer.
     * @param u Second input batch buffer.
     * @param n Vector length.
     * @param batch_size Number of vectors in batch.
     * @return Asynchronous execution event.
     */
    __event__ vadd_batch(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* r, const void* v, const void* u, dim_t n, dim_t batch_size);

    /**
     * @brief Batched vector addition in-place across @p batch_size vectors.
     * @param v Batch buffer modified in place.
     * @param u Batch buffer to add.
     * @param n Vector length.
     * @param batch_size Number of vectors in batch.
     * @return Asynchronous execution event.
     */
    __event__ vadd_batch(cumeric_t* v, const cumeric_t* u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* v, const void* u, dim_t n, dim_t batch_size);

    /**
     * @brief Strided batched vector addition out-of-place.
     * @param r Output batch buffer.
     * @param stride_r Stride between batch vectors in r.
     * @param v First input batch buffer.
     * @param stride_v Stride between batch vectors in v.
     * @param u Second input batch buffer.
     * @param stride_u Stride between batch vectors in u.
     * @param n Vector length.
     * @param batch_size Number of vectors in batch.
     * @return Asynchronous execution event.
     */
    __event__ vadd_batch(cumeric_t* r, dim_t stride_r, const cumeric_t* v, dim_t stride_v, const cumeric_t* u, dim_t stride_u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* r, dim_t stride_r, const void* v, dim_t stride_v, const void* u, dim_t stride_u, dim_t n, dim_t batch_size);

    __event__ vadd_batch(cumeric_t* v, dim_t stride_v, const cumeric_t* u, dim_t stride_u, dim_t n, dim_t batch_size);
    __event__ vadd_batch(datatype dtype, void* v, dim_t stride_v, const void* u, dim_t stride_u, dim_t n, dim_t batch_size);

    /**
     * @brief Asynchronous elementwise vector subtraction: @p r = @p v - @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Vector buffer to subtract.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vsub(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vsub(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous in-place vector subtraction: @p v -= @p u.
     * @param v Vector buffer modified in place.
     * @param u Vector buffer to subtract.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vsub(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vsub(datatype dtype, void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous elementwise vector multiplication: @p r = @p v * @p u.
     * @param r Output vector buffer.
     * @param v First input vector buffer.
     * @param u Second input vector buffer.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vmul(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vmul(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous in-place vector multiplication: @p v *= @p u.
     * @param v Vector buffer modified in place.
     * @param u Vector multiplier buffer.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vmul(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vmul(datatype dtype, void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous elementwise vector division: @p r = @p v / @p u.
     * @param r Output vector buffer.
     * @param v Numerator vector buffer.
     * @param u Denominator vector buffer.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vdiv(cumeric_t* r, const cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vdiv(datatype dtype, void* r, const void* v, const void* u, dim_t n);

    /**
     * @brief Asynchronous in-place vector division: @p v /= @p u.
     * @param v Vector buffer modified in place.
     * @param u Denominator vector buffer.
     * @param n Number of elements.
     * @return Asynchronous execution event.
     */
    __event__ vdiv(cumeric_t* v, const cumeric_t* u, dim_t n);
    __event__ vdiv(datatype dtype, void* v, const void* u, dim_t n);
} // namespace cum::lara

#endif //YANN_VECOPS_HPP
