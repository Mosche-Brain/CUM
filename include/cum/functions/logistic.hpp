/**
 * @file logistic.hpp
 * @brief Logistic functions including Sigmoid and Softmax activations and their derivatives.
 * @author jaro
 * @details Implements scalar and asynchronous parallel GPU/device vector operations,
 *          including standard derivatives and fast derivatives from precomputed activation results.
 */

#pragma once

#include "cum/Core.hpp"

namespace cum::functions::logistic
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    /**
     * @brief Evaluates scalar logistic sigmoid: f(x) = 1 / (1 + exp(-x)).
     * @param x Input scalar.
     * @return Result scalar in range (0, 1).
     */
    cumeric_t sigmoid(cumeric_t x);

    /* Parallel versions */

    /**
     * @brief Computes vector sigmoid out-of-place: @p r = 1 / (1 + exp(-@p v)).
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ sigmoid(cumeric_t* r, const cumeric_t* v, const std::size_t N);

    /**
     * @brief Computes vector sigmoid in-place.
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ sigmoid_in_place(cumeric_t* v, const std::size_t N);

    __event__ sigmoid(datatype dtype, void* r, const void* v, const std::size_t N);
    __event__ sigmoid(datatype dtype, void* v, const std::size_t N);
    __event__ sigmoid_in_place(datatype dtype, void* v, const std::size_t N);

    /**
     * @brief Computes vector softmax normalization out-of-place: @p r_i = exp(@p v_i) / sum(exp(@p v)).
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ softmax(cumeric_t* r, const cumeric_t* v, const dim_t N);

    /**
     * @brief Computes vector softmax normalization in-place.
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ softmax_in_place(cumeric_t* v, const dim_t N);

    __event__ softmax(datatype dtype, void* r, const void* v, const dim_t N);
    __event__ softmax(datatype dtype, void* v, const dim_t N);
    __event__ softmax_in_place(datatype dtype, void* v, const dim_t N);

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    /**
     * @brief Evaluates sigmoid derivative from input @p x: f'(x) = sigmoid(x) * (1 - sigmoid(x)).
     * @param x Original input scalar before sigmoid.
     * @return Derivative scalar.
     */
    cumeric_t sigmoid_deriv(cumeric_t x);

    /**
     * @brief Evaluates sigmoid derivative directly from activated value @p y = sigmoid(x): f'(x) = y * (1 - y).
     * @param x Activated value (y).
     * @return Derivative scalar.
     */
    cumeric_t sigmoid_deriv_from_result(cumeric_t x);

    /* Parallel versions */

    __event__ sigmoid_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ sigmoid_deriv_in_place(cumeric_t* v, const std::size_t N);
    __event__ sigmoid_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ sigmoid_deriv(datatype dtype, void* v, const std::size_t N);
    __event__ sigmoid_deriv_in_place(datatype dtype, void* v, const std::size_t N);

    __event__ sigmoid_deriv_from_result(cumeric_t* r, const cumeric_t* v, const std::size_t N);
    __event__ sigmoid_deriv_from_result_in_place(cumeric_t* v, std::size_t N);
    __event__ sigmoid_deriv_from_result(datatype dtype, void* r, const void* v, const std::size_t N);
    __event__ sigmoid_deriv_from_result(datatype dtype, void* v, std::size_t N);
    __event__ sigmoid_deriv_from_result_in_place(datatype dtype, void* v, std::size_t N);

    __event__ softmax_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ softmax_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ softmax_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ softmax_deriv(datatype dtype, void* v, dim_t N);
    __event__ softmax_deriv_in_place(datatype dtype, void* v, dim_t N);

    __event__ softmax_deriv_from_result(cumeric_t* r, const cumeric_t* v, const std::size_t N);
    __event__ softmax_deriv_from_result_in_place(cumeric_t* v, const std::size_t N);
    __event__ softmax_deriv_from_result(datatype dtype, void* r, const void* v, const std::size_t N);
    __event__ softmax_deriv_from_result(datatype dtype, void* v, const std::size_t N);
    __event__ softmax_deriv_from_result_in_place(datatype dtype, void* v, const std::size_t N);

} // namespace cum::functions::logistic
