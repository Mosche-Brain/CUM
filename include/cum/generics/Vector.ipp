/*
 * @author: jaro
 * @name:   Vector
 * @file:   modules/cum/include/cum/generics/Vector.cpp
 * @date:   17 October 2026 09:38:23
 */

#pragma once

#include "cum/generics/Vector.hpp"

namespace cum
{
    template <typename T, dim_t length>
    Vector<T, length>::Vector()
    {
        this->data_ = static_cast<T*>(memory::allocate<T>(length));
    }

    template <typename T, dim_t length>
    Vector<T, length>::Vector(dim_t len)
    {
        if (length != Dynamic)
            throw std::runtime_error("Called dynamic length contructor on fixed lenght vector");

        this->data_ = static_cast<T*>(memory::allocate<T>(len));
    }

    template <typename T, dim_t length>
    Vector<T, length>::~Vector()
    {
        memory::free(this->data_);
    }

    template <typename T, dim_t length>
    Vector<T, length> operator + (const Vector<T, length>& lhs, const Vector<T, length>& rhs)
    {
        Vector<T, length> result(length);
        // LinearAlgebra::cwiseSum(result.data_, lhs.data_, rhs.data_, length);
        return result;
    }

    template <typename T, dim_t length>
    Vector<T, length> operator - (const Vector<T, length>& lhs, const Vector<T, length>& rhs)
    {
        Vector<T, length> result(length);

        return result;
    }

    template <typename T, dim_t length>
    Vector<T, length> operator * (const Vector<T, length>& lhs, const Vector<T, length>& rhs)
    {
        Vector<T, length> result(length);
        // LinearAlgebra::cwiseSum(result.data_, lhs.data_, rhs.data_, length);
        return result;
    }

    template <typename T, dim_t length>
    Vector<T, length> operator / (const Vector<T, length>& lhs, const Vector<T, length>& rhs)
    {
        Vector<T, length> result(length);

        return result;
    }

}