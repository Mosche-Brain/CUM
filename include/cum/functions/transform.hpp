/**
 * @file transform.hpp
 * @brief Unified elementwise transformation and derivative dispatch routines.
 * @author jaro
 * @details Dispatches forward and derivative evaluations across arrays based on @ref function_id or @ref activation_t.
 */

#pragma once

#include "cum/Core.hpp"
#include "cum/functions/function_id.hpp"

namespace cum::functions
{
    /**
     * @brief Transforms vector @p v by applying activation @p activation into @p r.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @param activation Activation function identifier.
     */
    void transform(cumeric_t* r, const cumeric_t* v, std::size_t N, function_id activation);

    /**
     * @brief Transforms vector @p v by applying activation struct @p activation into @p r.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @param activation Activation struct reference.
     */
    void transform(cumeric_t* r, const cumeric_t* v, std::size_t N, const activation_t& activation);

    /**
     * @brief Generic datatype vector transformation using activation identifier.
     * @param dtype Runtime datatype tag.
     * @param r Output memory buffer.
     * @param v Input memory buffer.
     * @param N Element count.
     * @param activation Activation function identifier.
     */
    void transform(datatype dtype, void* r, const void* v, std::size_t N, function_id activation);

    /**
     * @brief Generic datatype vector transformation using activation struct.
     * @param dtype Runtime datatype tag.
     * @param r Output memory buffer.
     * @param v Input memory buffer.
     * @param N Element count.
     * @param activation Activation struct reference.
     */
    void transform(datatype dtype, void* r, const void* v, std::size_t N, const activation_t& activation);

    /**
     * @brief Evaluates activation derivative on vector @p v into @p r.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @param activation Activation function identifier.
     */
    void transform_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N, function_id activation);

    /**
     * @brief Evaluates activation derivative on vector @p v into @p r using activation struct.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param N Element count.
     * @param activation Activation struct reference.
     */
    void transform_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N, const activation_t& activation);

    /**
     * @brief Generic datatype vector derivative evaluation.
     * @param dtype Runtime datatype tag.
     * @param r Output memory buffer.
     * @param v Input memory buffer.
     * @param N Element count.
     * @param activation Activation function identifier.
     */
    void transform_deriv(datatype dtype, void* r, const void* v, std::size_t N, function_id activation);

    /**
     * @brief Generic datatype vector derivative evaluation using activation struct.
     * @param dtype Runtime datatype tag.
     * @param r Output memory buffer.
     * @param v Input memory buffer.
     * @param N Element count.
     * @param activation Activation struct reference.
     */
    void transform_deriv(datatype dtype, void* r, const void* v, std::size_t N, const activation_t& activation);

} // namespace cum::functions
