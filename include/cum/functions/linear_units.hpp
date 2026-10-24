/**
 * @file linear_units.hpp
 * @brief Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity).
 * @author jaro
 * @details Provides both scalar operations and asynchronous parallel GPU/device vector kernels.
 */

#pragma once

#include "cum/Core.hpp"

/**
 * @def leaky_relu_alpha
 * @brief Default negative slope coefficient for Leaky ReLU.
 */
#define leaky_relu_alpha (cum::cumeric_t)0.01

namespace cum::functions::linear_units
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    /**
     * @brief Evaluates scalar identity: f(x) = x.
     * @param x Input scalar.
     * @return Output scalar.
     */
    cumeric_t identity(cumeric_t x);

    /**
     * @brief Evaluates scalar ReLU: f(x) = max(0, x).
     * @param x Input scalar.
     * @return Output scalar.
     */
    cumeric_t relu(cumeric_t x);

    /**
     * @brief Evaluates scalar Leaky ReLU: f(x) = x if x >= 0 else alpha * x.
     * @param x Input scalar.
     * @return Output scalar.
     */
    cumeric_t leaky_relu(cumeric_t x);

    /**
     * @brief Evaluates scalar Gaussian Error Linear Unit (GELU).
     * @param x Input scalar.
     * @return Output scalar.
     */
    cumeric_t gelu(cumeric_t x);

    /**
     * @brief Evaluates scalar Exponential Linear Unit (ELU).
     * @param x Input scalar.
     * @return Output scalar.
     */
    cumeric_t elu(cumeric_t x);

    /* Parallel versions */

    /**
     * @brief Vector identity out-of-place: @p r = @p v.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ identity(cumeric_t* r, const cumeric_t* v, dim_t N);

    /**
     * @brief Vector identity in-place.
     * @param v Vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ identity_in_place(cumeric_t* v, dim_t N);

    __event__ identity(datatype dtype, void* r, const void* v, dim_t N);
    __event__ identity(datatype dtype, void* v, dim_t N);
    __event__ identity_in_place(datatype dtype, void* v, dim_t N);

    /**
     * @brief Vector ReLU out-of-place: @p r = max(0, @p v).
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ relu(cumeric_t* r, const cumeric_t* v, dim_t N);

    /**
     * @brief Vector ReLU in-place: @p v = max(0, @p v).
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ relu_in_place(cumeric_t* v, dim_t N);

    __event__ relu(datatype dtype, void* r, const void* v, dim_t N);
    __event__ relu(datatype dtype, void* v, dim_t N);
    __event__ relu_in_place(datatype dtype, void* v, dim_t N);

    /**
     * @brief Vector Leaky ReLU out-of-place.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ leaky_relu(cumeric_t* r, const cumeric_t* v, dim_t N);

    /**
     * @brief Vector Leaky ReLU in-place.
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ leaky_relu_in_place(cumeric_t* v, dim_t N);

    __event__ leaky_relu(datatype dtype, void* r, const void* v, dim_t N);
    __event__ leaky_relu(datatype dtype, void* v, dim_t N);
    __event__ leaky_relu_in_place(datatype dtype, void* v, dim_t N);

    /**
     * @brief Vector GELU out-of-place.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ gelu(cumeric_t* r, const cumeric_t* v, dim_t N);

    /**
     * @brief Vector GELU in-place.
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ gelu_in_place(cumeric_t* v, dim_t N);

    __event__ gelu(datatype dtype, void* r, const void* v, dim_t N);
    __event__ gelu(datatype dtype, void* v, dim_t N);
    __event__ gelu_in_place(datatype dtype, void* v, dim_t N);

    /**
     * @brief Vector ELU out-of-place.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ elu(cumeric_t* r, const cumeric_t* v, dim_t N);

    /**
     * @brief Vector ELU in-place.
     * @param v Vector buffer modified in place.
     * @param N Element count.
     * @return Asynchronous execution event.
     */
    __event__ elu_in_place(cumeric_t* v, dim_t N);

    __event__ elu(datatype dtype, void* r, const void* v, dim_t N);
    __event__ elu(datatype dtype, void* v, dim_t N);
    __event__ elu_in_place(datatype dtype, void* v, dim_t N);

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t identity_deriv(cumeric_t x);
    cumeric_t relu_deriv(cumeric_t x);
    cumeric_t leaky_relu_deriv(cumeric_t x);
    cumeric_t gelu_deriv(cumeric_t x);
    cumeric_t elu_deriv(cumeric_t x);

    /* Parallel versions */

    __event__ identity_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ identity_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ identity_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ identity_deriv(datatype dtype, void* v, dim_t N);
    __event__ identity_deriv_in_place(datatype dtype, void* v, dim_t N);

    __event__ relu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ relu_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ relu_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ relu_deriv(datatype dtype, void* v, dim_t N);
    __event__ relu_deriv_in_place(datatype dtype, void* v, dim_t N);

    __event__ leaky_relu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ leaky_relu_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ leaky_relu_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ leaky_relu_deriv(datatype dtype, void* v, dim_t N);
    __event__ leaky_relu_deriv_in_place(datatype dtype, void* v, dim_t N);

    __event__ gelu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ gelu_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ gelu_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ gelu_deriv(datatype dtype, void* v, dim_t N);
    __event__ gelu_deriv_in_place(datatype dtype, void* v, dim_t N);

    __event__ elu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N);
    __event__ elu_deriv_in_place(cumeric_t* v, dim_t N);
    __event__ elu_deriv(datatype dtype, void* r, const void* v, dim_t N);
    __event__ elu_deriv(datatype dtype, void* v, dim_t N);
    __event__ elu_deriv_in_place(datatype dtype, void* v, dim_t N);
} // namespace cum::functions::linear_units
