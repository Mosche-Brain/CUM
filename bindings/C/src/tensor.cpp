#include <cstring>

#include "cum/cum.h"
#include "cum/Tensor.hpp"
#include "cum/detail/opaques_impl.hpp"
#include "cum/detail/error.hpp"
#include "cum/detail/convert.hpp"

using cum_c::guard;
using cum_c::invalid_argument;

namespace
{
    constexpr const char* null_tensor = "null tensor argument";

    cum_status_t emplace(cum_tensor_t** out, cum::Tensor&& tensor)
    {
        *out = new cum_tensor_t { std::move(tensor) };
        return CUM_STATUS_SUCCESS;
    }
}

extern "C"
{
    cum_status_t cum_tensor_create(
        cum_tensor_t** tensor,
        cum_shape_t shape,
        cum_datatype_t datatype,
        cum_layout_t layout
    )
    {
        if(tensor == nullptr)
            return invalid_argument("null output pointer");
        return guard([&] {
            emplace(tensor, cum::Tensor(
                cum_c::to_shape(shape), cum_c::to_datatype(datatype), cum_c::to_layout(layout)));
        });
    }

    cum_status_t cum_tensor_create_zeros(cum_tensor_t** tensor, cum_shape_t shape)
    {
        if(tensor == nullptr)
            return invalid_argument("null output pointer");
        return guard([&] { emplace(tensor, cum::Tensor::Zeros(cum_c::to_shape(shape))); });
    }

    cum_status_t cum_tensor_create_ones(cum_tensor_t** tensor, cum_shape_t shape)
    {
        if(tensor == nullptr)
            return invalid_argument("null output pointer");
        return guard([&] { emplace(tensor, cum::Tensor::Ones(cum_c::to_shape(shape))); });
    }

    cum_status_t cum_tensor_create_random(cum_tensor_t** tensor, cum_shape_t shape, cumeric_t min, cumeric_t max)
    {
        if(tensor == nullptr)
            return invalid_argument("null output pointer");
        return guard([&] { emplace(tensor, cum::Tensor::Random(cum_c::to_shape(shape), min, max)); });
    }

    cum_status_t cum_tensor_create_from_data(cum_tensor_t** tensor, cum_shape_t shape, const cumeric_t* data)
    {
        if(tensor == nullptr || data == nullptr)
            return invalid_argument("null output pointer or data");
        return guard([&] {
            cum::Tensor created(cum_c::to_shape(shape), cum::datatype::FP32, cum::layout::ANY);
            std::memcpy(created.data(), data, static_cast<size_t>(created.size()));
            emplace(tensor, std::move(created));
        });
    }

    cum_status_t cum_tensor_create_from_desc(cum_tensor_t** tensor, const cum_memory_desc_t* desc)
    {
        if(tensor == nullptr || desc == nullptr)
            return invalid_argument("null output pointer or memory descriptor");
        return guard([&] {
            if(!desc->desc.valid() || desc->desc.size() <= 0)
                throw std::invalid_argument("memory descriptor must have a concrete non-empty layout");
            cum::neural_primitives::MemoryDescriptor md_copy(desc->desc);
            emplace(tensor, cum::Tensor(md_copy));
        });
    }

    cum_status_t cum_tensor_destroy(cum_tensor_t* tensor)
    {
        delete tensor;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_tensor_copy(cum_tensor_t* dst, const cum_tensor_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { dst->tensor = src->tensor; });
    }

    cum_status_t cum_tensor_clone(cum_tensor_t** dst, const cum_tensor_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { emplace(dst, src->tensor.clone()); });
    }

    cum_status_t cum_tensor_memory_desc(const cum_tensor_t* tensor, cum_memory_desc_t** desc)
    {
        if(tensor == nullptr || desc == nullptr)
            return invalid_argument("null tensor or output descriptor pointer");
        return guard([&] {
            const auto& md_ptr = tensor->tensor.descriptor();
            if(!md_ptr)
                throw std::invalid_argument("tensor has no memory descriptor");
            *desc = new cum_memory_desc_t { *md_ptr };
        });
    }

    cum_status_t cum_tensor_memory(const cum_tensor_t* tensor, cum_memory_t** memory)
    {
        if(tensor == nullptr || memory == nullptr)
            return invalid_argument("null tensor or output memory pointer");
        return guard([&] {
            const auto& mem_ptr = tensor->tensor.memory();
            if(!mem_ptr)
                throw std::invalid_argument("tensor has no memory handle");
            *memory = new cum_memory_t { *mem_ptr };
        });
    }

    cum_status_t cum_tensor_shape(
        const cum_tensor_t* tensor,
        dim_t* dims,
        size_t capacity,
        size_t* rank
    )
    {
        if(tensor == nullptr || rank == nullptr)
            return invalid_argument("invalid tensor or rank");
        return guard([&] {
            const cum::Shape shape = tensor->tensor.shape();
            *rank = shape.size();
            if(dims == nullptr)
                return;
            if(capacity < shape.size())
                throw std::invalid_argument("shape buffer is too small");
            for(size_t index = 0; index < shape.size(); ++index)
                dims[index] = shape[index];
        });
    }

    cum_status_t cum_tensor_size(const cum_tensor_t* tensor, dim_t* size)
    {
        if(tensor == nullptr || size == nullptr)
            return invalid_argument();
        return guard([&] { *size = tensor->tensor.size(); });
    }

    cum_status_t cum_tensor_length(const cum_tensor_t* tensor, dim_t* length)
    {
        if(tensor == nullptr || length == nullptr)
            return invalid_argument();
        return guard([&] { *length = tensor->tensor.lenght(); });
    }

    cum_status_t cum_tensor_datatype(const cum_tensor_t* tensor, cum_datatype_t* datatype)
    {
        if(tensor == nullptr || datatype == nullptr)
            return invalid_argument();
        return guard([&] { *datatype = cum_c::from_datatype(tensor->tensor.type()); });
    }

    cum_status_t cum_tensor_layout(const cum_tensor_t* tensor, cum_layout_t* layout)
    {
        if(tensor == nullptr || layout == nullptr)
            return invalid_argument();
        return guard([&] { *layout = cum_c::from_layout(tensor->tensor.format()); });
    }

    cum_status_t cum_tensor_data(const cum_tensor_t* tensor, const void** data)
    {
        if(tensor == nullptr || data == nullptr)
            return invalid_argument();
        return guard([&] { *data = tensor->tensor.data(); });
    }

    cum_status_t cum_tensor_mutable_data(cum_tensor_t* tensor, void** data)
    {
        if(tensor == nullptr || data == nullptr)
            return invalid_argument();
        return guard([&] { *data = tensor->tensor.data(); });
    }

    cum_status_t cum_tensor_reshape(cum_tensor_t* dst, const cum_tensor_t* src, cum_shape_t shape)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] {
            const cum::Shape new_shape = cum_c::to_shape(shape);
            dim_t total = 1;
            for(dim_t d : new_shape)
                total *= d;
            if(total != src->tensor.lenght())
                throw std::invalid_argument("reshape element count mismatch");
            cum::Tensor reshaped(new_shape, src->tensor.type(), cum::layout::ANY);
            std::memcpy(reshaped.data(), src->tensor.data(), static_cast<size_t>(src->tensor.size()));
            dst->tensor = std::move(reshaped);
        });
    }

    cum_status_t cum_tensor_transpose(cum_tensor_t* dst, const cum_tensor_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { dst->tensor = src->tensor.transpose(); });
    }

    cum_status_t cum_tensor_fill(cum_tensor_t* tensor, cumeric_t scalar)
    {
        if(tensor == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { tensor->tensor.fill(scalar); });
    }

    #define CUM_TENSOR_BINARY(name, expression) \
    cum_status_t name(cum_tensor_t* dst, const cum_tensor_t* lhs, const cum_tensor_t* rhs) \
    { \
        if(dst == nullptr || lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_tensor); \
        return guard([&] { dst->tensor = (expression); }); \
    }

    CUM_TENSOR_BINARY(cum_tensor_add, lhs->tensor + rhs->tensor)
    CUM_TENSOR_BINARY(cum_tensor_sub, lhs->tensor - rhs->tensor)
    CUM_TENSOR_BINARY(cum_tensor_mul, lhs->tensor.multiply(rhs->tensor))
    CUM_TENSOR_BINARY(cum_tensor_div, lhs->tensor / rhs->tensor)
    CUM_TENSOR_BINARY(cum_tensor_mmul, lhs->tensor.matmul(rhs->tensor))

    #undef CUM_TENSOR_BINARY

    #define CUM_TENSOR_IN_PLACE(name, op) \
    cum_status_t name(cum_tensor_t* lhs, const cum_tensor_t* rhs) \
    { \
        if(lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_tensor); \
        return guard([&] { lhs->tensor op rhs->tensor; }); \
    }

    CUM_TENSOR_IN_PLACE(cum_tensor_add_in_place, +=)
    CUM_TENSOR_IN_PLACE(cum_tensor_sub_in_place, -=)
    CUM_TENSOR_IN_PLACE(cum_tensor_mul_in_place, *=)
    CUM_TENSOR_IN_PLACE(cum_tensor_div_in_place, /=)

    #undef CUM_TENSOR_IN_PLACE

    #define CUM_TENSOR_SCALAR(name, expression) \
    cum_status_t name(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t scalar) \
    { \
        if(dst == nullptr || src == nullptr) \
            return invalid_argument(null_tensor); \
        return guard([&] { dst->tensor = (expression); }); \
    }

    CUM_TENSOR_SCALAR(cum_tensor_add_scalar, src->tensor + scalar)
    CUM_TENSOR_SCALAR(cum_tensor_sub_scalar, src->tensor - scalar)
    CUM_TENSOR_SCALAR(cum_tensor_mul_scalar, src->tensor * scalar)
    CUM_TENSOR_SCALAR(cum_tensor_div_scalar, src->tensor / scalar)

    #undef CUM_TENSOR_SCALAR

    cum_status_t cum_tensor_scale(cum_tensor_t* tensor, cumeric_t scalar)
    {
        if(tensor == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { tensor->tensor = tensor->tensor * scalar; });
    }

    #define CUM_TENSOR_UNARY(name, method) \
    cum_status_t name(cum_tensor_t* dst, const cum_tensor_t* src) \
    { \
        if(dst == nullptr || src == nullptr) \
            return invalid_argument(null_tensor); \
        return guard([&] { dst->tensor = src->tensor.method(); }); \
    }

    CUM_TENSOR_UNARY(cum_tensor_sqrt, sqrt)
    CUM_TENSOR_UNARY(cum_tensor_square, square)
    CUM_TENSOR_UNARY(cum_tensor_abs, abs)
    CUM_TENSOR_UNARY(cum_tensor_log, log)

    #undef CUM_TENSOR_UNARY

    cum_status_t cum_tensor_clamp(cum_tensor_t* dst, const cum_tensor_t* src, cumeric_t min, cumeric_t max)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_tensor);
        return guard([&] { dst->tensor = src->tensor.clamp(min, max); });
    }

    #define CUM_TENSOR_REDUCTION(name, method) \
    cum_status_t name(const cum_tensor_t* tensor, cumeric_t* result) \
    { \
        if(tensor == nullptr || result == nullptr) \
            return invalid_argument(); \
        return guard([&] { *result = tensor->tensor.method(); }); \
    }

    CUM_TENSOR_REDUCTION(cum_tensor_sum, sum)
    CUM_TENSOR_REDUCTION(cum_tensor_mean, mean)
    CUM_TENSOR_REDUCTION(cum_tensor_norm, norm)

    #undef CUM_TENSOR_REDUCTION
}
