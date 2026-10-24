/**
 * @file function_id.hpp
 * @brief Function identifier enumeration and activation callback signatures.
 * @author jaro
 */

#pragma once

#include <cstdint>
#include "cum/datatypes.hpp"

namespace cum::functions
{
    /**
     * @enum function_id
     * @brief Numerical identifier for activation and mathematical elementwise operations.
     */
    enum class function_id : std::uint8_t
    {
        undefined = 0, ///< Unspecified / undefined function.
        linear,        ///< Identity / linear: f(x) = x.
        relu,          ///< Rectified Linear Unit: f(x) = max(0, x).
        leaky_relu,    ///< Leaky ReLU with slope alpha: f(x) = x (x>=0) or alpha*x (x<0).
        gelu,          ///< Gaussian Error Linear Unit.
        elu,           ///< Exponential Linear Unit.
        sqrt,          ///< Square root function: f(x) = sqrt(x).
        exp,           ///< Natural exponential: f(x) = e^x.
        exp2,          ///< Base-2 exponential: f(x) = 2^x.
        exp10,         ///< Base-10 exponential: f(x) = 10^x.
        log,           ///< Natural logarithm: f(x) = ln(x).
        log2,          ///< Base-2 logarithm: f(x) = log2(x).
        log10,         ///< Base-10 logarithm: f(x) = log10(x).
        sin,           ///< Sine function.
        cos,           ///< Cosine function.
        tan,           ///< Tangent function.
        sinh,          ///< Hyperbolic sine.
        cosh,          ///< Hyperbolic cosine.
        tanh,          ///< Hyperbolic tangent.
        asin,          ///< Inverse sine (arcsine).
        acos,          ///< Inverse cosine (arccosine).
        atan,          ///< Inverse tangent (arctangent).
        sigmoid        ///< Logistic sigmoid: f(x) = 1 / (1 + e^-x).
    };

    /**
     * @brief Scalar unary mathematical function pointer type.
     */
    typedef cumeric_t (*function_t)(cumeric_t);

    /**
     * @struct activation_t
     * @brief Bundles activation function identifier, forward function, and derivative pointers.
     */
    typedef struct
    {
        function_id name;       ///< Identifier of the activation function.
        function_t function;    ///< Forward evaluation function pointer.
        function_t derivative;  ///< Derivative evaluation function pointer.
    } activation_t;
} // namespace cum::functions
