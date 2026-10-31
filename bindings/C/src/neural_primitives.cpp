#include <span>
#include <stdexcept>
#include <string>
#include <vector>

#include "cum/cum.h"
#include "cum/neural_primitives.hpp"
#include "cum/detail/convert.hpp"
#include "cum/detail/error.hpp"
#include "cum/detail/opaques_impl.hpp"
#include "cum/detail/submit.hpp"

namespace np = cum::neural_primitives;

using cum_c::guard;
using cum_c::invalid_argument;
using cum_c::submit;

/* Verify 1-to-1 correspondence between C and C++ neural-primitive enumerations. */
static_assert(static_cast<int>(np::Purpose::forward) == CUM_PURPOSE_FORWARD, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::forward_training) == CUM_PURPOSE_FORWARD_TRAINING, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::forward_inference) == CUM_PURPOSE_FORWARD_INFERENCE, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::backward) == CUM_PURPOSE_BACKWARD, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::backward_data) == CUM_PURPOSE_BACKWARD_DATA, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::backward_weights) == CUM_PURPOSE_BACKWARD_WEIGHTS, "cum_purpose_t mismatch");
static_assert(static_cast<int>(np::Purpose::backward_bias) == CUM_PURPOSE_BACKWARD_BIAS, "cum_purpose_t mismatch");

static_assert(static_cast<int>(np::Algo::undef) == CUM_ALGO_UNDEF, "cum_algo_t::undef mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_relu) == CUM_ALGO_ELTWISE_RELU, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_tanh) == CUM_ALGO_ELTWISE_TANH, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_elu) == CUM_ALGO_ELTWISE_ELU, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_square) == CUM_ALGO_ELTWISE_SQUARE, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_abs) == CUM_ALGO_ELTWISE_ABS, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_sqrt) == CUM_ALGO_ELTWISE_SQRT, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_linear) == CUM_ALGO_ELTWISE_LINEAR, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_soft_relu) == CUM_ALGO_ELTWISE_SOFT_RELU, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_logistic) == CUM_ALGO_ELTWISE_LOGISTIC, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_exp) == CUM_ALGO_ELTWISE_EXP, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_gelu_tanh) == CUM_ALGO_ELTWISE_GELU_TANH, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_gelu_erf) == CUM_ALGO_ELTWISE_GELU_ERF, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_swish) == CUM_ALGO_ELTWISE_SWISH, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_mish) == CUM_ALGO_ELTWISE_MISH, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_log) == CUM_ALGO_ELTWISE_LOG, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_clip) == CUM_ALGO_ELTWISE_CLIP, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_clip_v2) == CUM_ALGO_ELTWISE_CLIP_V2, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_pow) == CUM_ALGO_ELTWISE_POW, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_round) == CUM_ALGO_ELTWISE_ROUND, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_hardswish) == CUM_ALGO_ELTWISE_HARDSWISH, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_hardsigmoid) == CUM_ALGO_ELTWISE_HARDSIGMOID, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_relu_use_dst_for_bwd) == CUM_ALGO_ELTWISE_RELU_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_tanh_use_dst_for_bwd) == CUM_ALGO_ELTWISE_TANH_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_elu_use_dst_for_bwd) == CUM_ALGO_ELTWISE_ELU_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_sqrt_use_dst_for_bwd) == CUM_ALGO_ELTWISE_SQRT_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_logistic_use_dst_for_bwd) == CUM_ALGO_ELTWISE_LOGISTIC_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_exp_use_dst_for_bwd) == CUM_ALGO_ELTWISE_EXP_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_clip_v2_use_dst_for_bwd) == CUM_ALGO_ELTWISE_CLIP_V2_USE_DST_FOR_BWD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_add) == CUM_ALGO_BINARY_ADD, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_sub) == CUM_ALGO_BINARY_SUB, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_mul) == CUM_ALGO_BINARY_MUL, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_div) == CUM_ALGO_BINARY_DIV, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_max) == CUM_ALGO_BINARY_MAX, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_min) == CUM_ALGO_BINARY_MIN, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_eq) == CUM_ALGO_BINARY_EQ, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_ne) == CUM_ALGO_BINARY_NE, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_gt) == CUM_ALGO_BINARY_GT, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_ge) == CUM_ALGO_BINARY_GE, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_lt) == CUM_ALGO_BINARY_LT, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::binary_le) == CUM_ALGO_BINARY_LE, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::softmax_accurate) == CUM_ALGO_SOFTMAX_ACCURATE, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::softmax_log) == CUM_ALGO_SOFTMAX_LOG, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_max) == CUM_ALGO_REDUCTION_MAX, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_min) == CUM_ALGO_REDUCTION_MIN, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_sum) == CUM_ALGO_REDUCTION_SUM, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_mul) == CUM_ALGO_REDUCTION_MUL, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_mean) == CUM_ALGO_REDUCTION_MEAN, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_norm_lp_max) == CUM_ALGO_REDUCTION_NORM_LP_MAX, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_norm_lp_sum) == CUM_ALGO_REDUCTION_NORM_LP_SUM, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_norm_lp_power_p_max) == CUM_ALGO_REDUCTION_NORM_LP_POWER_P_MAX, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::reduction_norm_lp_power_p_sum) == CUM_ALGO_REDUCTION_NORM_LP_POWER_P_SUM, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_leaky_relu) == CUM_ALGO_ELTWISE_LEAKY_RELU, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_sigmoid) == CUM_ALGO_ELTWISE_SIGMOID, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_gelu) == CUM_ALGO_ELTWISE_GELU, "cum_algo_t mismatch");
static_assert(static_cast<int>(np::Algo::eltwise_clamp) == CUM_ALGO_ELTWISE_CLAMP, "cum_algo_t mismatch");

static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::undef) == CUM_PRIMITIVE_UNDEF, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::binary) == CUM_PRIMITIVE_BINARY, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::elementwise) == CUM_PRIMITIVE_ELEMENTWISE, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::matmul) == CUM_PRIMITIVE_MATMUL, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::softmax) == CUM_PRIMITIVE_SOFTMAX, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::reduction) == CUM_PRIMITIVE_REDUCTION, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::reorder) == CUM_PRIMITIVE_REORDER, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::sum) == CUM_PRIMITIVE_SUM, "cum_primitive_kind_t mismatch");
static_assert(static_cast<int>(np::PrimitiveDescriptor::Kind::concat) == CUM_PRIMITIVE_CONCAT, "cum_primitive_kind_t mismatch");

static_assert(static_cast<int>(np::Primitive::Argument::undef) == CUM_ARG_UNDEF, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::src) == CUM_ARG_SRC, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::src0) == CUM_ARG_SRC_0, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::src1) == CUM_ARG_SRC_1, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::src2) == CUM_ARG_SRC_2, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::src3) == CUM_ARG_SRC_3, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::dst) == CUM_ARG_DST, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::dst0) == CUM_ARG_DST_0, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::weights) == CUM_ARG_WEIGHTS, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::bias) == CUM_ARG_BIAS, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::workspace) == CUM_ARG_WORKSPACE, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::scratchpad) == CUM_ARG_SCRATCHPAD, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_src) == CUM_ARG_DIFF_SRC, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_src0) == CUM_ARG_DIFF_SRC_0, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_src1) == CUM_ARG_DIFF_SRC_1, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_dst) == CUM_ARG_DIFF_DST, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_weights) == CUM_ARG_DIFF_WEIGHTS, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::diff_bias) == CUM_ARG_DIFF_BIAS, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::Argument::multiple_src) == CUM_ARG_MULTIPLE_SRC, "cum_primitive_arg_t mismatch");
static_assert(static_cast<int>(np::Primitive::multiple_src_arg(3)) == static_cast<int>(CUM_ARG_MULTIPLE_SRC_AT(3)), "CUM_ARG_MULTIPLE_SRC_AT mismatch");

namespace
{
    cum::Shape to_strides(const cum_shape_t& strides)
    {
        if(strides.rank == 0 || strides.dims == nullptr)
            throw std::invalid_argument("invalid strides");
        for(size_t i = 0; i < strides.rank; ++i)
            if(strides.dims[i] < 0)
                throw std::invalid_argument("strides must be non-negative");
        return cum::Shape(strides.dims, strides.dims + strides.rank);
    }

    void copy_dims_out(const cum::Shape& dims, dim_t* out, size_t capacity, size_t* rank)
    {
        *rank = dims.size();
        if(out == nullptr)
            return;
        if(capacity < dims.size())
            throw std::invalid_argument("output dimension buffer is too small");
        for(size_t i = 0; i < dims.size(); ++i)
            out[i] = dims[i];
    }

    cum::__events__ collect_deps(const cum_event_t* const* deps, size_t num_deps)
    {
        cum::__events__ out;
        if(num_deps == 0)
            return out;
        if(deps == nullptr)
            throw std::invalid_argument("null deps array with non-zero num_deps");
        out.reserve(num_deps);
        for(size_t i = 0; i < num_deps; ++i)
        {
            if(deps[i] == nullptr)
                throw std::invalid_argument("null event handle in deps array");
            out.push_back(std::ref(deps[i]->event));
        }
        return out;
    }

    std::vector<np::MemoryDescriptor> collect_descs(
        const cum_memory_desc_t* const* srcs,
        size_t num_srcs
    )
    {
        if(num_srcs == 0 || srcs == nullptr)
            throw std::invalid_argument("srcs must be non-empty");
        std::vector<np::MemoryDescriptor> out;
        out.reserve(num_srcs);
        for(size_t i = 0; i < num_srcs; ++i)
        {
            if(srcs[i] == nullptr)
                throw std::invalid_argument("null memory descriptor in srcs");
            out.push_back(srcs[i]->desc);
        }
        return out;
    }

    void emplace_desc(cum_memory_desc_t** out, np::MemoryDescriptor&& md)
    {
        *out = new cum_memory_desc_t { std::move(md) };
    }

    void emplace_pd(cum_primitive_desc_t** out, np::PrimitiveDescriptor&& pd)
    {
        *out = new cum_primitive_desc_t { std::move(pd), {} };
    }
}

extern "C"
{
    /* ----------------------------------------------------------------------
     * MemoryDescriptor
     * ---------------------------------------------------------------------- */

    cum_status_t cum_memory_desc_create(
        cum_memory_desc_t** desc,
        cum_shape_t shape,
        cum_datatype_t datatype,
        cum_layout_t layout
    )
    {
        if(desc == nullptr)
            return invalid_argument("null output descriptor pointer");
        return guard([&] {
            emplace_desc(desc, np::MemoryDescriptor(
                cum_c::to_shape(shape),
                cum_c::to_datatype(datatype),
                cum_c::to_layout(layout)
            ));
        });
    }

    cum_status_t cum_memory_desc_create_strided(
        cum_memory_desc_t** desc,
        cum_shape_t shape,
        cum_datatype_t datatype,
        cum_shape_t strides
    )
    {
        if(desc == nullptr)
            return invalid_argument("null output descriptor pointer");
        return guard([&] {
            emplace_desc(desc, np::MemoryDescriptor(
                cum_c::to_shape(shape),
                cum_c::to_datatype(datatype),
                to_strides(strides)
            ));
        });
    }

    cum_status_t cum_memory_desc_create_any(
        cum_memory_desc_t** desc,
        cum_shape_t shape,
        cum_datatype_t datatype
    )
    {
        if(desc == nullptr)
            return invalid_argument("null output descriptor pointer");
        return guard([&] {
            emplace_desc(desc, np::MemoryDescriptor::Any(
                cum_c::to_shape(shape),
                cum_c::to_datatype(datatype)
            ));
        });
    }

    cum_status_t cum_memory_desc_clone(
        cum_memory_desc_t** dst,
        const cum_memory_desc_t* src
    )
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument("null descriptor pointer");
        return guard([&] {
            emplace_desc(dst, np::MemoryDescriptor(src->desc));
        });
    }

    cum_status_t cum_memory_desc_destroy(cum_memory_desc_t* desc)
    {
        delete desc;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_memory_desc_valid(const cum_memory_desc_t* desc, bool* is_valid)
    {
        if(desc == nullptr || is_valid == nullptr)
            return invalid_argument("null descriptor or output pointer");
        return guard([&] { *is_valid = desc->desc.valid(); });
    }

    cum_status_t cum_memory_desc_equal(
        const cum_memory_desc_t* lhs,
        const cum_memory_desc_t* rhs,
        bool* is_equal
    )
    {
        if(lhs == nullptr || rhs == nullptr || is_equal == nullptr)
            return invalid_argument("null descriptor or output pointer");
        return guard([&] { *is_equal = (lhs->desc == rhs->desc); });
    }

    cum_status_t cum_memory_desc_size(const cum_memory_desc_t* desc, dim_t* size)
    {
        if(desc == nullptr || size == nullptr)
            return invalid_argument("null descriptor or output pointer");
        return guard([&] { *size = desc->desc.size(); });
    }

    cum_status_t cum_memory_desc_ndims(const cum_memory_desc_t* desc, dim_t* ndims)
    {
        if(desc == nullptr || ndims == nullptr)
            return invalid_argument("null descriptor or output pointer");
        return guard([&] { *ndims = desc->desc.ndims(); });
    }

    cum_status_t cum_memory_desc_shape(
        const cum_memory_desc_t* desc,
        dim_t* dims,
        size_t capacity,
        size_t* rank
    )
    {
        if(desc == nullptr || rank == nullptr)
            return invalid_argument("null descriptor or rank pointer");
        return guard([&] { copy_dims_out(desc->desc.shape(), dims, capacity, rank); });
    }

    cum_status_t cum_memory_desc_strides(
        const cum_memory_desc_t* desc,
        dim_t* strides,
        size_t capacity,
        size_t* rank
    )
    {
        if(desc == nullptr || rank == nullptr)
            return invalid_argument("null descriptor or rank pointer");
        return guard([&] { copy_dims_out(desc->desc.strides(), strides, capacity, rank); });
    }

    cum_status_t cum_memory_desc_datatype(const cum_memory_desc_t* desc, cum_datatype_t* datatype)
    {
        if(desc == nullptr || datatype == nullptr)
            return invalid_argument("null descriptor or datatype pointer");
        return guard([&] { *datatype = cum_c::from_datatype(desc->desc.type()); });
    }

    cum_status_t cum_memory_desc_layout(const cum_memory_desc_t* desc, cum_layout_t* layout)
    {
        if(desc == nullptr || layout == nullptr)
            return invalid_argument("null descriptor or layout pointer");
        return guard([&] { *layout = cum_c::from_layout(desc->desc.format()); });
    }

    cum_status_t cum_memory_desc_reshape(
        cum_memory_desc_t** dst,
        const cum_memory_desc_t* src,
        cum_shape_t shape
    )
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument("null descriptor pointer");
        return guard([&] {
            emplace_desc(dst, src->desc.reshape(cum_c::to_shape(shape)));
        });
    }

    /* ----------------------------------------------------------------------
     * Memory
     * ---------------------------------------------------------------------- */

    cum_status_t cum_memory_create(cum_memory_t** memory, const cum_memory_desc_t* desc)
    {
        if(memory == nullptr || desc == nullptr)
            return invalid_argument("null memory output pointer or descriptor");
        return guard([&] {
            *memory = new cum_memory_t { np::Memory(desc->desc) };
        });
    }

    cum_status_t cum_memory_create_from_ptr(
        cum_memory_t** memory,
        const cum_memory_desc_t* desc,
        void* data
    )
    {
        if(memory == nullptr || desc == nullptr)
            return invalid_argument("null memory output pointer or descriptor");
        return guard([&] {
            *memory = new cum_memory_t { np::Memory(desc->desc, data) };
        });
    }

    cum_status_t cum_memory_create_view(
        cum_memory_t** memory,
        const cum_memory_desc_t* view_desc,
        const cum_memory_t* source
    )
    {
        if(memory == nullptr || view_desc == nullptr || source == nullptr)
            return invalid_argument("null memory output pointer, view descriptor, or source");
        return guard([&] {
            *memory = new cum_memory_t { np::Memory(view_desc->desc, source->memory) };
        });
    }

    cum_status_t cum_memory_destroy(cum_memory_t* memory)
    {
        delete memory;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_memory_valid(const cum_memory_t* memory, bool* is_valid)
    {
        if(memory == nullptr || is_valid == nullptr)
            return invalid_argument("null memory or output pointer");
        return guard([&] { *is_valid = memory->memory.valid(); });
    }

    cum_status_t cum_memory_desc(const cum_memory_t* memory, cum_memory_desc_t** desc)
    {
        if(memory == nullptr || desc == nullptr)
            return invalid_argument("null memory or output descriptor pointer");
        return guard([&] { emplace_desc(desc, memory->memory.descriptor()); });
    }

    cum_status_t cum_memory_data(const cum_memory_t* memory, const void** data)
    {
        if(memory == nullptr || data == nullptr)
            return invalid_argument("null memory or output data pointer");
        return guard([&] { *data = memory->memory.data(); });
    }

    cum_status_t cum_memory_mutable_data(cum_memory_t* memory, void** data)
    {
        if(memory == nullptr || data == nullptr)
            return invalid_argument("null memory or output data pointer");
        return guard([&] { *data = memory->memory.data(); });
    }

    cum_status_t cum_memory_set_data(cum_memory_t* memory, void* data)
    {
        if(memory == nullptr)
            return invalid_argument("null memory pointer");
        return guard([&] { memory->memory.set_data(data); });
    }

    /* ----------------------------------------------------------------------
     * PrimitiveDescriptor
     * ---------------------------------------------------------------------- */

    cum_status_t cum_primitive_desc_create_binary(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src0,
        const cum_memory_desc_t* src1
    )
    {
        if(pd == nullptr || dst == nullptr || src0 == nullptr || src1 == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor::Binary(
                static_cast<np::Algo>(algo), dst->desc, src0->desc, src1->desc));
        });
    }

    cum_status_t cum_primitive_desc_create_eltwise_forward(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src,
        float alpha,
        float beta,
        cum_purpose_t purpose
    )
    {
        if(pd == nullptr || dst == nullptr || src == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor::ElementwiseForward(
                static_cast<np::Algo>(algo),
                dst->desc,
                src->desc,
                alpha,
                beta,
                static_cast<np::Purpose>(purpose)
            ));
        });
    }

    cum_status_t cum_primitive_desc_create_eltwise_backward(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* diff_src,
        const cum_memory_desc_t* diff_dst,
        const cum_memory_desc_t* data,
        const cum_primitive_desc_t* hint_fwd_pd,
        float alpha,
        float beta
    )
    {
        if(pd == nullptr || diff_src == nullptr || diff_dst == nullptr || data == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            if(hint_fwd_pd != nullptr)
            {
                emplace_pd(pd, np::PrimitiveDescriptor::ElementwiseBackward(
                    static_cast<np::Algo>(algo),
                    diff_src->desc,
                    diff_dst->desc,
                    data->desc,
                    hint_fwd_pd->desc,
                    alpha,
                    beta
                ));
            }
            else
            {
                emplace_pd(pd, np::PrimitiveDescriptor::ElementwiseBackward(
                    static_cast<np::Algo>(algo),
                    diff_src->desc,
                    diff_dst->desc,
                    data->desc,
                    alpha,
                    beta
                ));
            }
        });
    }

    cum_status_t cum_primitive_desc_create_matmul(
        cum_primitive_desc_t** pd,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src,
        const cum_memory_desc_t* weights,
        const cum_memory_desc_t* bias
    )
    {
        if(pd == nullptr || dst == nullptr || src == nullptr || weights == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            if(bias != nullptr)
                emplace_pd(pd, np::PrimitiveDescriptor::Matmul(dst->desc, src->desc, weights->desc, bias->desc));
            else
                emplace_pd(pd, np::PrimitiveDescriptor::Matmul(dst->desc, src->desc, weights->desc));
        });
    }

    cum_status_t cum_primitive_desc_create_softmax_forward(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src,
        int axis,
        cum_purpose_t purpose
    )
    {
        if(pd == nullptr || dst == nullptr || src == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor::SoftmaxForward(
                static_cast<np::Algo>(algo),
                dst->desc,
                src->desc,
                axis,
                static_cast<np::Purpose>(purpose)
            ));
        });
    }

    cum_status_t cum_primitive_desc_create_softmax_backward(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* diff_src,
        const cum_memory_desc_t* diff_dst,
        const cum_memory_desc_t* dst,
        int axis,
        const cum_primitive_desc_t* hint_fwd_pd
    )
    {
        if(pd == nullptr || diff_src == nullptr || diff_dst == nullptr || dst == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            if(hint_fwd_pd != nullptr)
            {
                emplace_pd(pd, np::PrimitiveDescriptor::SoftmaxBackward(
                    static_cast<np::Algo>(algo),
                    diff_src->desc,
                    diff_dst->desc,
                    dst->desc,
                    axis,
                    hint_fwd_pd->desc
                ));
            }
            else
            {
                emplace_pd(pd, np::PrimitiveDescriptor::SoftmaxBackward(
                    static_cast<np::Algo>(algo),
                    diff_src->desc,
                    diff_dst->desc,
                    dst->desc,
                    axis
                ));
            }
        });
    }

    cum_status_t cum_primitive_desc_create_reduction(
        cum_primitive_desc_t** pd,
        cum_algo_t algo,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src,
        float p,
        float eps
    )
    {
        if(pd == nullptr || dst == nullptr || src == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor::Reduction(
                static_cast<np::Algo>(algo),
                dst->desc,
                src->desc,
                p,
                eps
            ));
        });
    }

    cum_status_t cum_primitive_desc_create_reorder(
        cum_primitive_desc_t** pd,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* src
    )
    {
        if(pd == nullptr || dst == nullptr || src == nullptr)
            return invalid_argument("null primitive descriptor or memory descriptor");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor::Reorder(dst->desc, src->desc));
        });
    }

    cum_status_t cum_primitive_desc_create_sum(
        cum_primitive_desc_t** pd,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* const* srcs,
        size_t num_srcs,
        const float* scales
    )
    {
        if(pd == nullptr || dst == nullptr)
            return invalid_argument("null primitive descriptor or dst descriptor");
        return guard([&] {
            auto src_vec = collect_descs(srcs, num_srcs);
            std::span<const float> scale_span =
                (scales != nullptr) ? std::span<const float>(scales, num_srcs) : std::span<const float>();
            emplace_pd(pd, np::PrimitiveDescriptor::Sum(dst->desc, src_vec, scale_span));
        });
    }

    cum_status_t cum_primitive_desc_create_concat(
        cum_primitive_desc_t** pd,
        const cum_memory_desc_t* dst,
        const cum_memory_desc_t* const* srcs,
        size_t num_srcs,
        int axis
    )
    {
        if(pd == nullptr)
            return invalid_argument("null output primitive descriptor");
        return guard([&] {
            auto src_vec = collect_descs(srcs, num_srcs);
            if(dst != nullptr)
                emplace_pd(pd, np::PrimitiveDescriptor::Concat(dst->desc, src_vec, axis));
            else
                emplace_pd(pd, np::PrimitiveDescriptor::Concat(src_vec, axis));
        });
    }

    cum_status_t cum_primitive_desc_clone(
        cum_primitive_desc_t** dst,
        const cum_primitive_desc_t* src
    )
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument("null primitive descriptor pointer");
        return guard([&] {
            emplace_pd(dst, np::PrimitiveDescriptor(src->desc));
        });
    }

    cum_status_t cum_primitive_desc_destroy(cum_primitive_desc_t* pd)
    {
        delete pd;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_primitive_desc_valid(const cum_primitive_desc_t* pd, bool* is_valid)
    {
        if(pd == nullptr || is_valid == nullptr)
            return invalid_argument("null primitive descriptor or output pointer");
        return guard([&] { *is_valid = pd->desc.valid(); });
    }

    cum_status_t cum_primitive_desc_kind(const cum_primitive_desc_t* pd, cum_primitive_kind_t* kind)
    {
        if(pd == nullptr || kind == nullptr)
            return invalid_argument("null primitive descriptor or output pointer");
        return guard([&] { *kind = static_cast<cum_primitive_kind_t>(pd->desc.kind()); });
    }

    cum_status_t cum_primitive_desc_purpose(const cum_primitive_desc_t* pd, cum_purpose_t* purpose)
    {
        if(pd == nullptr || purpose == nullptr)
            return invalid_argument("null primitive descriptor or output pointer");
        return guard([&] { *purpose = static_cast<cum_purpose_t>(pd->desc.purpose()); });
    }

    cum_status_t cum_primitive_desc_algo(const cum_primitive_desc_t* pd, cum_algo_t* algo)
    {
        if(pd == nullptr || algo == nullptr)
            return invalid_argument("null primitive descriptor or output pointer");
        return guard([&] { *algo = static_cast<cum_algo_t>(pd->desc.algorithm()); });
    }

    cum_status_t cum_primitive_desc_impl_info(const cum_primitive_desc_t* pd, const char** info)
    {
        if(pd == nullptr || info == nullptr)
            return invalid_argument("null primitive descriptor or output pointer");
        return guard([&] {
            pd->cached_impl_info = std::string(pd->desc.impl_info());
            *info = pd->cached_impl_info.c_str();
        });
    }

    #define CUM_PD_INDEXED_DESC_QUERY(fn_name, method_name) \
    cum_status_t fn_name(const cum_primitive_desc_t* pd, int index, cum_memory_desc_t** desc) \
    { \
        if(pd == nullptr || desc == nullptr) \
            return invalid_argument("null primitive descriptor or output descriptor"); \
        return guard([&] { emplace_desc(desc, pd->desc.method_name(index)); }); \
    }

    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_src_desc, src_desc)
    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_dst_desc, dst_desc)
    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_weights_desc, weights_desc)
    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_diff_src_desc, diff_src_desc)
    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_diff_dst_desc, diff_dst_desc)
    CUM_PD_INDEXED_DESC_QUERY(cum_primitive_desc_diff_weights_desc, diff_weights_desc)

    #undef CUM_PD_INDEXED_DESC_QUERY

    #define CUM_PD_SINGLE_DESC_QUERY(fn_name, method_name) \
    cum_status_t fn_name(const cum_primitive_desc_t* pd, cum_memory_desc_t** desc) \
    { \
        if(pd == nullptr || desc == nullptr) \
            return invalid_argument("null primitive descriptor or output descriptor"); \
        return guard([&] { emplace_desc(desc, pd->desc.method_name()); }); \
    }

    CUM_PD_SINGLE_DESC_QUERY(cum_primitive_desc_bias_desc, bias_desc)
    CUM_PD_SINGLE_DESC_QUERY(cum_primitive_desc_workspace_desc, workspace_desc)
    CUM_PD_SINGLE_DESC_QUERY(cum_primitive_desc_scratchpad_desc, scratchpad_desc)

    #undef CUM_PD_SINGLE_DESC_QUERY

    /* ----------------------------------------------------------------------
     * Primitive
     * ---------------------------------------------------------------------- */

    cum_status_t cum_primitive_create(cum_primitive_t** prim, const cum_primitive_desc_t* pd)
    {
        if(prim == nullptr || pd == nullptr)
            return invalid_argument("null primitive output pointer or descriptor");
        return guard([&] {
            *prim = new cum_primitive_t { np::Primitive(pd->desc) };
        });
    }

    cum_status_t cum_primitive_clone(cum_primitive_t** dst, const cum_primitive_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument("null primitive pointer");
        return guard([&] {
            *dst = new cum_primitive_t { np::Primitive(src->primitive) };
        });
    }

    cum_status_t cum_primitive_destroy(cum_primitive_t* prim)
    {
        delete prim;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_primitive_valid(const cum_primitive_t* prim, bool* is_valid)
    {
        if(prim == nullptr || is_valid == nullptr)
            return invalid_argument("null primitive or output pointer");
        return guard([&] { *is_valid = prim->primitive.valid(); });
    }

    cum_status_t cum_primitive_kind(const cum_primitive_t* prim, cum_primitive_kind_t* kind)
    {
        if(prim == nullptr || kind == nullptr)
            return invalid_argument("null primitive or output pointer");
        return guard([&] { *kind = static_cast<cum_primitive_kind_t>(prim->primitive.kind()); });
    }

    cum_status_t cum_primitive_get_desc(const cum_primitive_t* prim, cum_primitive_desc_t** pd)
    {
        if(prim == nullptr || pd == nullptr)
            return invalid_argument("null primitive or output descriptor pointer");
        return guard([&] {
            emplace_pd(pd, np::PrimitiveDescriptor(prim->primitive.descriptor()));
        });
    }

    cum_status_t cum_primitive_execute(
        const cum_primitive_t* prim,
        const cum_memory_arg_t* args,
        size_t num_args,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || (num_args > 0 && args == nullptr))
            return invalid_argument("null primitive or argument bindings");
        return submit(event, [&] {
            std::vector<np::Primitive::ArgBinding> bindings;
            bindings.reserve(num_args);
            for(size_t i = 0; i < num_args; ++i)
            {
                if(args[i].memory == nullptr)
                    throw std::invalid_argument("null memory handle in cum_memory_arg_t");
                bindings.emplace_back(
                    static_cast<np::Primitive::Argument>(args[i].arg),
                    args[i].memory->memory
                );
            }
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(bindings, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_tensors(
        const cum_primitive_t* prim,
        const cum_tensor_arg_t* args,
        size_t num_args,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || (num_args > 0 && args == nullptr))
            return invalid_argument("null primitive or tensor argument bindings");
        return submit(event, [&] {
            std::vector<np::Primitive::ArgBinding> bindings;
            bindings.reserve(num_args);
            for(size_t i = 0; i < num_args; ++i)
            {
                if(args[i].tensor == nullptr)
                    throw std::invalid_argument("null tensor handle in cum_tensor_arg_t");
                bindings.emplace_back(
                    static_cast<np::Primitive::Argument>(args[i].arg),
                    args[i].tensor->tensor
                );
            }
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(bindings, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_unary(
        const cum_primitive_t* prim,
        cum_tensor_t* dst,
        const cum_tensor_t* src0,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr)
            return invalid_argument("null primitive or tensor operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(dst->tensor, src0->tensor, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_binary(
        const cum_primitive_t* prim,
        cum_tensor_t* dst,
        const cum_tensor_t* src0,
        const cum_tensor_t* src1,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr || src1 == nullptr)
            return invalid_argument("null primitive or tensor operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(dst->tensor, src0->tensor, src1->tensor, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_ternary(
        const cum_primitive_t* prim,
        cum_tensor_t* dst,
        const cum_tensor_t* src0,
        const cum_tensor_t* src1,
        const cum_tensor_t* src2,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr || src1 == nullptr || src2 == nullptr)
            return invalid_argument("null primitive or tensor operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(
                dst->tensor, src0->tensor, src1->tensor, src2->tensor, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_memory_unary(
        const cum_primitive_t* prim,
        cum_memory_t* dst,
        const cum_memory_t* src0,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr)
            return invalid_argument("null primitive or memory operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(dst->memory, src0->memory, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_memory_binary(
        const cum_primitive_t* prim,
        cum_memory_t* dst,
        const cum_memory_t* src0,
        const cum_memory_t* src1,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr || src1 == nullptr)
            return invalid_argument("null primitive or memory operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(dst->memory, src0->memory, src1->memory, cpp_deps);
        });
    }

    cum_status_t cum_primitive_execute_memory_ternary(
        const cum_primitive_t* prim,
        cum_memory_t* dst,
        const cum_memory_t* src0,
        const cum_memory_t* src1,
        const cum_memory_t* src2,
        const cum_event_t* const* deps,
        size_t num_deps,
        cum_event_t** event
    )
    {
        if(prim == nullptr || dst == nullptr || src0 == nullptr || src1 == nullptr || src2 == nullptr)
            return invalid_argument("null primitive or memory operand");
        return submit(event, [&] {
            auto cpp_deps = collect_deps(deps, num_deps);
            return prim->primitive.execute(
                dst->memory, src0->memory, src1->memory, src2->memory, cpp_deps);
        });
    }
}
