/**
 * @file reductions.hpp
 * @brief Softmax forward and backward reduction primitives for neural tensors.
 * @author jaro
 * @details Implements axis-specific softmax activation and derivative operations across raw handles,
 *          @ref Memory objects, and @ref Tensor instances.
 */

#pragma once

#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/Descriptor.hpp"
#include "cum/neural_primitives/opaque_types.hpp"
#include "cum/Core.hpp"

namespace cum { class Tensor; }

namespace cum::neural_primitives
{
    /* Raw handles overloads */

    /**
     * @brief Computes softmax on raw memory handles along specified axis out-of-place.
     */
    __event__ softmax(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc, dim_t axis = -1);

    /**
     * @brief Computes softmax on raw memory handle along specified axis in-place.
     */
    __event__ softmax(handles::__memory__& memory, const handles::__desc__& desc, dim_t axis = -1);

    __event__ softmax_diff(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc, dim_t axis = -1);
    __event__ softmax_diff(handles::__memory__& memory, const handles::__desc__& desc, dim_t axis = -1);

    /* RAII wrappers overloads */

    __event__ softmax(Memory& dst, const Memory& src, const Descriptor& r_desc, const Descriptor& a_desc, dim_t axis = -1);
    __event__ softmax(Memory& src, const Descriptor& desc, dim_t axis = -1);

    __event__ softmax_diff(Memory& dst, const Memory& src, const Descriptor& r_desc, const Descriptor& a_desc, dim_t axis = -1);
    __event__ softmax_diff(Memory& memory, const Descriptor& desc, dim_t axis = -1);

    /* Tensor overloads */

    /**
     * @brief Computes softmax on Tensor along specified axis out-of-place.
     * @param dst Output destination Tensor.
     * @param src Input source Tensor.
     * @param axis Target dimension axis (-1 for last axis).
     * @return Asynchronous execution event.
     */
    __event__ softmax(Tensor& dst, const Tensor& src, dim_t axis = -1);

    /**
     * @brief Computes softmax on Tensor along specified axis in-place.
     * @param tensor Tensor modified in place.
     * @param axis Target dimension axis (-1 for last axis).
     * @return Asynchronous execution event.
     */
    __event__ softmax(Tensor& tensor, dim_t axis = -1);

    __event__ softmax_diff(Tensor& dst, const Tensor& src, dim_t axis = -1);
    __event__ softmax_diff(Tensor& tensor, dim_t axis = -1);

} // namespace cum::neural_primitives
