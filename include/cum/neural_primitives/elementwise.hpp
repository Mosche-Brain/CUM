/**
 * @file elementwise.hpp
 * @brief Forward elementwise neural activation primitives.
 * @author jaro
 * @details Implements forward propagation primitives (ReLU, Sigmoid, Tanh, GELU, ELU, Leaky ReLU, Sqrt, Square, Exp, Log, Abs, Clamp)
 *          across raw backend handles, RAII @ref Memory / @ref Descriptor objects, and high-level @ref Tensor instances.
 */

#pragma once

#include "cum/neural_primitives/opaque_types.hpp"
#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/MemoryDescriptor.hpp"
#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

#include "cum/functions/function_id.hpp"

#include "cum/Core.hpp"

namespace cum { class Tensor; }

namespace cum::neural_primitives
{
    /* Raw handle overloads */

    /**
     * @brief Executes generic elementwise primitive on raw backend handles out-of-place.
     */
    __event__ eltwise(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc, functions::function_id algorithm, prop_kind prop_kind);

    /**
     * @brief Executes generic elementwise primitive on raw backend handle in-place.
     */
    __event__ eltwise(handles::__memory__& memory, const handles::__desc__& desc, functions::function_id algorithm, prop_kind prop_kind);

    __event__ relu(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc);
    __event__ relu(handles::__memory__& src, const handles::__desc__& desc);

    __event__ sigmoid(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc);
    __event__ sigmoid(handles::__memory__& src, const handles::__desc__& desc);

    __event__ tanh(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc);
    __event__ tanh(handles::__memory__& src, const handles::__desc__& desc);

    __event__ gelu(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc);
    __event__ gelu(handles::__memory__& src, const handles::__desc__& desc);

    __event__ elu(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc);
    __event__ elu(handles::__memory__& src, const handles::__desc__& desc);

    __event__ leaky_relu(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& r_desc, const handles::__desc__& a_desc, cumeric_t alpha);
    __event__ leaky_relu(handles::__memory__& src, const handles::__desc__& desc, cumeric_t alpha);

    __event__ sqrt(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc);
    __event__ sqrt(handles::__memory__& src, const handles::__desc__& desc);

    __event__ square(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc);
    __event__ square(handles::__memory__& src, const handles::__desc__& desc);

    __event__ exp(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc);
    __event__ exp(handles::__memory__& src, const handles::__desc__& desc);

    __event__ log(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc);
    __event__ log(handles::__memory__& src, const handles::__desc__& desc);

    __event__ abs(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc);
    __event__ abs(handles::__memory__& src, const handles::__desc__& desc);

    __event__ clamp(handles::__memory__& dst, const handles::__memory__& src, const handles::__desc__& dst_desc, const handles::__desc__& src_desc, cumeric_t min, cumeric_t max);
    __event__ clamp(handles::__memory__& src, const handles::__desc__& desc, cumeric_t min, cumeric_t max);

    /* RAII wrapper overloads */

    __event__ eltwise(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc, functions::function_id algorithm, prop_kind prop_kind);

    __event__ relu(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc);
    __event__ relu(Memory& src, const MemoryDescriptor& desc);

    __event__ sigmoid(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc);
    __event__ sigmoid(Memory& src, const MemoryDescriptor& desc);

    __event__ tanh(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc);
    __event__ tanh(Memory& src, const MemoryDescriptor& desc);

    __event__ gelu(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc);
    __event__ gelu(Memory& src, const MemoryDescriptor& desc);

    __event__ elu(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc);
    __event__ elu(Memory& src, const MemoryDescriptor& desc);

    __event__ leaky_relu(Memory& dst, const Memory& src, const MemoryDescriptor& r_desc, const MemoryDescriptor& a_desc, cumeric_t alpha);
    __event__ leaky_relu(Memory& src, const MemoryDescriptor& desc, cumeric_t alpha);

    __event__ sqrt(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc);
    __event__ sqrt(Memory& src, const MemoryDescriptor& desc);

    __event__ square(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc);
    __event__ square(Memory& src, const MemoryDescriptor& desc);

    __event__ exp(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc);
    __event__ exp(Memory& src, const MemoryDescriptor& desc);

    __event__ log(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc);
    __event__ log(Memory& src, const MemoryDescriptor& desc);

    __event__ abs(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc);
    __event__ abs(Memory& src, const MemoryDescriptor& desc);

    __event__ clamp(Memory& dst, const Memory& src, const MemoryDescriptor& dst_desc, const MemoryDescriptor& src_desc, cumeric_t min, cumeric_t max);
    __event__ clamp(Memory& src, const MemoryDescriptor& desc, cumeric_t min, cumeric_t max);

    /* Tensor overloads */

    __event__ eltwise(Tensor& dst, const Tensor& src, functions::function_id algorithm, prop_kind prop_kind);
    __event__ eltwise(Tensor& tensor, functions::function_id algorithm, prop_kind prop_kind);

    __event__ relu(Tensor& dst, const Tensor& src);
    __event__ sigmoid(Tensor& dst, const Tensor& src);

    __event__ tanh(Tensor& dst, const Tensor& src);
    __event__ tanh(Tensor& src);

    __event__ gelu(Tensor& dst, const Tensor& src);
    __event__ gelu(Tensor& src);

    __event__ elu(Tensor& dst, const Tensor& src);
    __event__ elu(Tensor& src);

    __event__ leaky_relu(Tensor& dst, const Tensor& src, cumeric_t alpha);
    __event__ leaky_relu(Tensor& src, cumeric_t alpha);

    __event__ sqrt(Tensor& dst, const Tensor& src);
    __event__ sqrt(Tensor& src);

    __event__ square(Tensor& dst, const Tensor& src);
    __event__ square(Tensor& src);

    __event__ exp(Tensor& dst, const Tensor& src);
    __event__ exp(Tensor& src);

    __event__ log(Tensor& dst, const Tensor& src);
    __event__ log(Tensor& src);

    __event__ abs(Tensor& dst, const Tensor& src);
    __event__ abs(Tensor& src);

    __event__ clamp(Tensor& dst, const Tensor& src, cumeric_t min, cumeric_t max);
    __event__ clamp(Tensor& src, cumeric_t min, cumeric_t max);
} // namespace cum::neural_primitives
