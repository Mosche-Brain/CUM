#ifndef CUM_C_CONVERT_HPP
#define CUM_C_CONVERT_HPP

#include <stdexcept>

#include "cum/Core.hpp"
#include "cum/datatypes.hpp"
#include "cum/layout.hpp"
#include "cum/core.h"

namespace cum_c
{
    /* Enum values of the C and C++ APIs are kept identical (see static_asserts in cum.cpp). */
    inline cum::datatype to_datatype(cum_datatype_t datatype)
    {
        return static_cast<cum::datatype>(datatype);
    }

    inline cum_datatype_t from_datatype(cum::datatype datatype)
    {
        return static_cast<cum_datatype_t>(datatype);
    }

    inline cum::layout to_layout(cum_layout_t layout)
    {
        return static_cast<cum::layout>(layout);
    }

    inline cum_layout_t from_layout(cum::layout layout)
    {
        return static_cast<cum_layout_t>(layout);
    }

    inline bool valid_shape(const cum_shape_t& shape)
    {
        return shape.rank != 0 && shape.dims != nullptr;
    }

    inline cum::Shape to_shape(const cum_shape_t& shape)
    {
        if(!valid_shape(shape))
            throw std::invalid_argument("invalid shape");
        for(size_t index = 0; index < shape.rank; ++index)
            if(shape.dims[index] <= 0)
                throw std::invalid_argument("shape dimensions must be positive");
        return cum::Shape(shape.dims, shape.dims + shape.rank);
    }
}

#endif /* CUM_C_CONVERT_HPP */
