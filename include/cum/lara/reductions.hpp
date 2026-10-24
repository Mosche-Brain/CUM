/**
 * @file reductions.hpp
 * @brief Asynchronous parallel reductions for matrices and vectors.
 * @author jaro
 * @details Implements row-wise/column-wise matrix reductions to vectors, and vector reductions to scalars
 *          (sum, asum, mean, amean).
 */

#ifndef YANN_REDUCTIONS_HPP
#define YANN_REDUCTIONS_HPP

#include "cum/Core.hpp"

namespace cum::lara
{
    /* Matrix ---> Vector Reductions */

    /**
     * @brief Computes row-wise sums of matrix @p mat into vector @p r.
     * @param r Output vector buffer of length @p m.
     * @param mat Input matrix buffer of dimensions @p m x @p n.
     * @param m Row count.
     * @param n Column count.
     * @return Asynchronous execution event.
     */
    __event__ rwise_sum(cumeric_t* r, cumeric_t* mat, dim_t m, dim_t n);

    /**
     * @brief Computes column-wise sums of matrix @p mat into vector @p r.
     * @param r Output vector buffer of length @p n.
     * @param mat Input matrix buffer of dimensions @p m x @p n.
     * @param m Row count.
     * @param n Column count.
     * @return Asynchronous execution event.
     */
    __event__ cwise_sum(cumeric_t* r, cumeric_t* mat, dim_t m, dim_t n);

    /* Vector ---> Scalar Reductions */

    /**
     * @brief Computes sum of all elements in vector @p v.
     * @param r Output scalar result pointer.
     * @param v Input vector buffer.
     * @param n Vector length.
     * @return Asynchronous execution event.
     */
    __event__ sum(cumeric_t* r, const cumeric_t* v, dim_t n);

    /**
     * @brief Computes sum of absolute values (L1 norm) of vector @p v.
     * @param r Output scalar result pointer.
     * @param v Input vector buffer.
     * @param n Vector length.
     * @return Asynchronous execution event.
     */
    __event__ asum(cumeric_t* r, const cumeric_t* v, dim_t n);

    /**
     * @brief Computes arithmetic mean of elements in vector @p v.
     * @param r Output scalar result pointer.
     * @param v Input vector buffer.
     * @param n Vector length.
     * @return Asynchronous execution event.
     */
    __event__ mean(cumeric_t* r, const cumeric_t* v, dim_t n);

    /**
     * @brief Computes mean of absolute values of elements in vector @p v.
     * @param r Output scalar result pointer.
     * @param v Input vector buffer.
     * @param n Vector length.
     * @return Asynchronous execution event.
     */
    __event__ amean(cumeric_t* r, const cumeric_t* v, dim_t n);
} // namespace cum::lara

#endif //YANN_REDUCTIONS_HPP
