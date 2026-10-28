#include <cstring>

#include "cum/cum.h"
#include "cum/Tensor.hpp"
#include "cum/detail/opaques_impl.hpp"
#include "cum/detail/error.hpp"

using cum_c::guard;
using cum_c::invalid_argument;

namespace
{
    constexpr const char* null_vector = "null vector argument";

    cum::Tensor make_tensor(dim_t length)
    {
        if(length <= 0)
            throw std::invalid_argument("vector length must be positive");
        return cum::Tensor(cum::Shape{length}, cum::datatype::FP32, cum::layout::A);
    }

    cum_status_t emplace(cum_vector_t** out, cum::Tensor&& tensor)
    {
        *out = new cum_vector_t { std::move(tensor) };
        return CUM_STATUS_SUCCESS;
    }

    void require_same_length(const cum_vector_t* lhs, const cum_vector_t* rhs)
    {
        if(lhs->tensor.lenght() != rhs->tensor.lenght())
            throw std::invalid_argument("vector length mismatch");
    }
}

extern "C"
{
    cum_status_t cum_vector_create(cum_vector_t** vector, dim_t length)
    {
        return cum_vector_create_filled(vector, length, 0.0f);
    }

    cum_status_t cum_vector_create_filled(cum_vector_t** vector, dim_t length, cumeric_t value)
    {
        if(vector == nullptr)
            return invalid_argument("null output pointer");
        return guard([&] {
            cum::Tensor tensor = make_tensor(length);
            tensor.fill(value);
            emplace(vector, std::move(tensor));
        });
    }

    cum_status_t cum_vector_create_from_data(cum_vector_t** vector, dim_t length, const cumeric_t* data)
    {
        if(vector == nullptr || data == nullptr)
            return invalid_argument("null output pointer or data");
        return guard([&] {
            cum::Tensor tensor = make_tensor(length);
            std::memcpy(tensor.data(), data, static_cast<size_t>(length) * sizeof(cumeric_t));
            emplace(vector, std::move(tensor));
        });
    }

    cum_status_t cum_vector_destroy(cum_vector_t* vector)
    {
        delete vector;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_vector_clone(cum_vector_t** dst, const cum_vector_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_vector);
        return guard([&] { emplace(dst, src->tensor.clone()); });
    }

    cum_status_t cum_vector_length(const cum_vector_t* vector, dim_t* length)
    {
        if(vector == nullptr || length == nullptr)
            return invalid_argument();
        return guard([&] { *length = vector->tensor.lenght(); });
    }

    cum_status_t cum_vector_data(const cum_vector_t* vector, const cumeric_t** data)
    {
        if(vector == nullptr || data == nullptr)
            return invalid_argument();
        return guard([&] { *data = static_cast<const cumeric_t*>(vector->tensor.data()); });
    }

    cum_status_t cum_vector_mutable_data(cum_vector_t* vector, cumeric_t** data)
    {
        if(vector == nullptr || data == nullptr)
            return invalid_argument();
        return guard([&] { *data = static_cast<cumeric_t*>(vector->tensor.data()); });
    }

    cum_status_t cum_vector_fill(cum_vector_t* vector, cumeric_t value)
    {
        if(vector == nullptr)
            return invalid_argument(null_vector);
        return guard([&] { vector->tensor.fill(value); });
    }

    #define CUM_VECTOR_BINARY(name, expression) \
    cum_status_t name(cum_vector_t* dst, const cum_vector_t* lhs, const cum_vector_t* rhs) \
    { \
        if(dst == nullptr || lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_vector); \
        return guard([&] { require_same_length(lhs, rhs); dst->tensor = (expression); }); \
    }

    CUM_VECTOR_BINARY(cum_vector_add, lhs->tensor + rhs->tensor)
    CUM_VECTOR_BINARY(cum_vector_sub, lhs->tensor - rhs->tensor)
    CUM_VECTOR_BINARY(cum_vector_mul, lhs->tensor.multiply(rhs->tensor))
    CUM_VECTOR_BINARY(cum_vector_div, lhs->tensor / rhs->tensor)

    #undef CUM_VECTOR_BINARY

    #define CUM_VECTOR_IN_PLACE(name, op) \
    cum_status_t name(cum_vector_t* lhs, const cum_vector_t* rhs) \
    { \
        if(lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_vector); \
        return guard([&] { require_same_length(lhs, rhs); lhs->tensor op rhs->tensor; }); \
    }

    CUM_VECTOR_IN_PLACE(cum_vector_add_in_place, +=)
    CUM_VECTOR_IN_PLACE(cum_vector_sub_in_place, -=)
    CUM_VECTOR_IN_PLACE(cum_vector_mul_in_place, *=)
    CUM_VECTOR_IN_PLACE(cum_vector_div_in_place, /=)

    #undef CUM_VECTOR_IN_PLACE

    cum_status_t cum_vector_scale(cum_vector_t* vector, cumeric_t scalar)
    {
        if(vector == nullptr)
            return invalid_argument(null_vector);
        return guard([&] { vector->tensor = vector->tensor * scalar; });
    }

    cum_status_t cum_vector_dot(const cum_vector_t* lhs, const cum_vector_t* rhs, cumeric_t* result)
    {
        if(lhs == nullptr || rhs == nullptr || result == nullptr)
            return invalid_argument();
        return guard([&] {
            require_same_length(lhs, rhs);
            *result = lhs->tensor.multiply(rhs->tensor).sum();
        });
    }

    cum_status_t cum_vector_sum(const cum_vector_t* vector, cumeric_t* result)
    {
        if(vector == nullptr || result == nullptr)
            return invalid_argument();
        return guard([&] { *result = vector->tensor.sum(); });
    }

    cum_status_t cum_vector_norm(const cum_vector_t* vector, cumeric_t* result)
    {
        if(vector == nullptr || result == nullptr)
            return invalid_argument();
        return guard([&] { *result = vector->tensor.norm(); });
    }
}
