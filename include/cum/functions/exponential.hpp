/**
 * @file exponential.hpp
 * @brief Exponential and logarithmic functions and their derivatives.
 * @author jaro
 * @details Implements exp (base e, 2, 10) and log (natural, base 2, base 10) for scalar values
 *          and parallel asynchronous GPU/device vectors.
 */

#pragma once

#include "cum/Core.hpp"
#include <cstddef>

namespace cum::functions::exponential
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    /**
     * @brief Evaluates natural exponential: e^x.
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t exp(cumeric_t x);

    /**
     * @brief Evaluates base-2 exponential: 2^x.
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t exp2(cumeric_t x);

    /**
     * @brief Evaluates base-10 exponential: 10^x.
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t exp10(cumeric_t x);

    /**
     * @brief Evaluates natural logarithm: ln(x).
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t log(cumeric_t x);

    /**
     * @brief Evaluates base-2 logarithm: log2(x).
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t log2(cumeric_t x);

    /**
     * @brief Evaluates base-10 logarithm: log10(x).
     * @param x Input scalar.
     * @return Result scalar.
     */
    cumeric_t log10(cumeric_t x);

    /* Parallel versions */

    __event__ exp(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp_in_place(cumeric_t* v, std::size_t N);
    __event__ exp(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp(datatype dtype, void* v, std::size_t N);
    __event__ exp_in_place(datatype dtype, void* v, std::size_t N);

    __event__ exp2(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp2_in_place(cumeric_t* v, std::size_t N);
    __event__ exp2(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp2(datatype dtype, void* v, std::size_t N);
    __event__ exp2_in_place(datatype dtype, void* v, std::size_t N);

    __event__ exp10(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp10_in_place(cumeric_t* v, std::size_t N);
    __event__ exp10(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp10(datatype dtype, void* v, std::size_t N);
    __event__ exp10_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log_in_place(cumeric_t* v, std::size_t N);
    __event__ log(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log(datatype dtype, void* v, std::size_t N);
    __event__ log_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log2(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log2_in_place(cumeric_t* v, std::size_t N);
    __event__ log2(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log2(datatype dtype, void* v, std::size_t N);
    __event__ log2_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log10(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log10_in_place(cumeric_t* v, std::size_t N);
    __event__ log10(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log10(datatype dtype, void* v, std::size_t N);
    __event__ log10_in_place(datatype dtype, void* v, std::size_t N);

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t exp_deriv(cumeric_t x);
    cumeric_t exp_deriv_from_result(cumeric_t x);

    cumeric_t exp2_deriv(cumeric_t x);
    cumeric_t exp2_deriv_from_result(cumeric_t x);

    cumeric_t exp10_deriv(cumeric_t x);
    cumeric_t exp10_deriv_from_result(cumeric_t x);

    cumeric_t log_deriv(cumeric_t x);
    cumeric_t log2_deriv(cumeric_t x);
    cumeric_t log10_deriv(cumeric_t x);

    /* Parallel versions */

    __event__ exp_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ exp_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp_deriv(datatype dtype, void* v, std::size_t N);
    __event__ exp_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ exp2_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp2_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ exp2_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp2_deriv(datatype dtype, void* v, std::size_t N);
    __event__ exp2_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ exp10_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ exp10_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ exp10_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ exp10_deriv(datatype dtype, void* v, std::size_t N);
    __event__ exp10_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ log_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log_deriv(datatype dtype, void* v, std::size_t N);
    __event__ log_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log2_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log2_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ log2_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log2_deriv(datatype dtype, void* v, std::size_t N);
    __event__ log2_deriv_in_place(datatype dtype, void* v, std::size_t N);

    __event__ log10_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N);
    __event__ log10_deriv_in_place(cumeric_t* v, std::size_t N);
    __event__ log10_deriv(datatype dtype, void* r, const void* v, std::size_t N);
    __event__ log10_deriv(datatype dtype, void* v, std::size_t N);
    __event__ log10_deriv_in_place(datatype dtype, void* v, std::size_t N);

} // namespace cum::functions::exponential
