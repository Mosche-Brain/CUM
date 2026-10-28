#ifndef CUM_C_OPAQUES_IMPL_HPP
#define CUM_C_OPAQUES_IMPL_HPP

#include "cum/Tensor.hpp"
#include "cum/Matrix.hpp"
#include "cum/Core.hpp"

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
    cum::__event__ event;
};

/* The C vector is backed by a rank-1 tensor (cum::Vector has no safe copy semantics). */
struct cum_vector_t
{
    cum::Tensor tensor;
};

#endif /* CUM_C_OPAQUES_IMPL_HPP */
