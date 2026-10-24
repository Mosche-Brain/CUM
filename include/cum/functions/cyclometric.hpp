/**
 * @file cyclometric.hpp
 * @brief Inverse trigonometric (cyclometric) functions (asin, acos, atan) and their derivatives.
 * @author jaro
 * @details Implements scalar evaluations and asynchronous parallel GPU/device vector operations.
 */

#pragma once

#include "cum/Core.hpp"
#include <cstddef>

namespace cum::functions::cyclometric
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    /**
     * @brief Evaluates scalar inverse sine: asin(x).
     * @param x Input scalar in range [-1, 1].
     * @return Result scalar in radians.
     */
    cumeric_t asin(cumeric_t x);

    /**
     * @brief Evaluates scalar inverse cosine: acos(x).
     * @param x Input scalar in range [-1, 1].
     * @return Result scalar in radians.
     */
    cumeric_t acos(cumeric_t x);

    /**
     * @brief Evaluates scalar inverse tangent: atan(x).
     * @param x Input scalar.
     * @return Result scalar in radians.
     */
    cumeric_t atan(cumeric_t x);

    /* Parallel versions */

    __event__ asin(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ asin_in_place(cumeric_t* v, std::size_t N);
    __event__ asin(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ asin(datatype dtype, void* v, std::size_t N);
    __event__ asin_in_place(datatype dtype, void* v, std::size_t N);

    __event__ acos(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ acos_in_place(cumeric_t* v, std::size_t N);
    __event__ acos(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ acos(datatype dtype, void* v, std::size_t N);
    __event__ acos_in_place(datatype dtype, void* v, std::size_t N);

    __event__ atan(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ atan_in_place(cumeric_t* v, std::size_t N);
    __event__ atan(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ atan(datatype dtype, void* v, std::size_t N);
    __event__ atan_in_place(datatype dtype, void* v, std::size_t N);

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t asin_deriv(cumeric_t x);
    cumeric_t acos_deriv(cumeric_t x);
    cumeric_t atan_deriv(cumeric_t x);

    /* Parallel versions */

    __event__ asin_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ asin_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ asin_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ asin_deriv(datatype dtype, void* v, std::size_t N);
    __event__ asin_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ acos_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ acos_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ acos_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ acos_deriv(datatype dtype, void* v, std::size_t N);
    __event__ acos_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ atan_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ atan_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ atan_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ atan_deriv(datatype dtype, void* v, std::size_t N);
    __event__ atan_deriv_in_place(datatype dtype, void* v, std::size_t N);

} // namespace cum::functions::cyclometric
