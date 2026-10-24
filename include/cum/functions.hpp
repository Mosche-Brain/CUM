/**
 * @file functions.hpp
 * @brief Master include header and functor definitions for neural activation and mathematical functions.
 * @details Aggregates trigonometric, hyperbolic, exponential, cyclometric, linear units, and logistic modules.
 */

#pragma once

#include "functions/trigonometric.hpp"
#include "functions/cyclometric.hpp"
#include "functions/hyperbolic.hpp"
#include "functions/exponential.hpp"
#include "functions/logistic.hpp"
#include "functions/linear_units.hpp"
#include "functions/various.hpp"

#include "functions/function_id.hpp"

namespace cum::functions
{
    /**
     * @struct Linear
     * @brief Linear / identity activation function functor: f(x) = x.
     */
    struct Linear
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @struct GELU
     * @brief Gaussian Error Linear Unit activation functor: f(x) = x * P(X <= x).
     */
    struct GELU
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @struct ReLU
     * @brief Rectified Linear Unit activation functor: f(x) = max(0, x).
     */
    struct ReLU
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @struct leaky_ReLU
     * @brief Leaky Rectified Linear Unit activation functor: f(x) = x if x >= 0 else alpha * x.
     */
    struct leaky_ReLU
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @struct Tanh
     * @brief Hyperbolic tangent activation functor: f(x) = tanh(x).
     */
    struct Tanh
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @struct Sigmoid
     * @brief Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)).
     */
    struct Sigmoid
    {
        cumeric_t operator()(cumeric_t x) const;
    };

    /**
     * @brief Resolves an activation function struct by string name (e.g. "relu", "sigmoid", "tanh").
     * @param activation Pointer to output @ref activation_t struct.
     * @param name C-string containing function name.
     */
    void get_function_by_name(activation_t* activation, const char* name);

    /**
     * @brief Transforms vector in-place using an activation function definition.
     * @param v Buffer to transform in-place.
     * @param func Activation function struct.
     * @param N Number of elements.
     */
    void transformInPlace(cumeric_t* v, activation_t& func, std::size_t N);

    // compute gradient of activation function for backpropagation
    // void activationDerivative(cumeric_t* r, const cumeric_t* v, activation_t& func, std::size_t N);
    // void activationDerivativeInPlace(cumeric_t* v, activation_t& func, std::size_t N);
} // namespace cum::functions
