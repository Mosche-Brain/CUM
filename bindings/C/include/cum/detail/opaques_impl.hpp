#ifndef CUM_C_OPAQUES_IMPL_HPP
#define CUM_C_OPAQUES_IMPL_HPP

#include <string>

#include "cum/Tensor.hpp"
#include "cum/Matrix.hpp"
#include "cum/Core.hpp"
#include "cum/neural_primitives.hpp"

struct cum_tensor_t
{
    cum::Tensor tensor;
};

struct cum_matrix_t
{
    cum::Matrix matrix;
};

struct cum_event_t
{
    mutable cum::__event__ event;
};

/* The C vector is backed by a rank-1 tensor (cum::Vector has no safe copy semantics). */
struct cum_vector_t
{
    cum::Tensor tensor;
};

struct cum_memory_desc_t
{
    cum::neural_primitives::MemoryDescriptor desc;
};

struct cum_memory_t
{
    cum::neural_primitives::Memory memory;
};

struct cum_primitive_desc_t
{
    cum::neural_primitives::PrimitiveDescriptor desc;
    mutable std::string cached_impl_info;
};

struct cum_primitive_t
{
    cum::neural_primitives::Primitive primitive;
};

#endif /* CUM_C_OPAQUES_IMPL_HPP */
