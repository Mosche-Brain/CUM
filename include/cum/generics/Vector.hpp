/*
 * @author: jaro
 * @name:   vector
 * @file:   modules/cum/include/cum/generics/vector.hpp
 * @date:   17 October 2026 09:06:28
 */

#pragma once

#include "cum/Core.hpp"
#include "cum/memory.hpp"

namespace cum
{
    constexpr dim_t Dynamic = -1;

    template<typename T, dim_t length=Dynamic>
    class Vector
    {
    public:
        Vector();
        Vector(dim_t len);

        ~Vector();

        T& operator[](const dim_t index) { return this->data_[index]; }
        const T operator[](const dim_t index) const { return this->data_[index]; }

        friend Vector operator + (const Vector& v, const Vector& u);
        friend Vector operator - (const Vector& v, const Vector& u);
        friend Vector operator * (const Vector& v, const Vector& u);
        friend Vector operator / (const Vector& v, const Vector& u);

        Vector& operator += (const Vector& other);
        Vector& operator -= (const Vector& other);
        Vector& operator *= (const Vector& other);
        Vector& operator /= (const Vector& other);

        Vector dot(const Vector& other);
        Vector cross(const Vector& other);

        Vector normalize();

    private:
        T* data_;
    };

    using ivec2 = Vector<int, 2>;
    using ivec3 = Vector<int, 3>;
    using ivec4 = Vector<int, 4>;

    using fvec2 = Vector<float32, 2>;
    using fvec3 = Vector<float32, 3>;
    using fvec4 = Vector<float32, 4>;

    using dvec2 = Vector<float64, 2>;
    using dvec3 = Vector<float64, 3>;
    using dvec4 = Vector<float64, 4>;

    using hvec2 = Vector<float16, 2>;
    using hvec3 = Vector<float16, 3>;
    using hvec4 = Vector<float16, 4>;
} // cum

#include "Vector.ipp"