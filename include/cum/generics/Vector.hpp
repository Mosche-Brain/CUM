/*
 * @author: jaro
 * @name:   vector
 * @file:   modules/cum/include/cum/generics/vector.hpp
 * @date:   17 October 2026 09:06:28
 */

#pragma once

#include <type_traits>

#include "cum/Core.hpp"
#include "cum/memory.hpp"

namespace cum
{
    constexpr dim_t Dynamic = -1;

    template<typename T, dim_t length_=Dynamic>
    class Vector
    {
    public:
        Vector();
        Vector(dim_t len);
        Vector(const Vector& other);
        Vector(Vector&& other) noexcept;
        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other) noexcept;

        ~Vector();

        static Vector random(T min = static_cast<T>(-1), T max = static_cast<T>(1));
        static Vector random(dim_t len, T min, T max);

        static Vector zeros();
        static Vector zeros(dim_t len);

        static Vector ones();
        static Vector ones(dim_t len);

        T& operator[](const dim_t index) { return this->data_[index]; }
        const T operator[](const dim_t index) const { return this->data_[index]; }

        dim_t length() const { return this->len_; }
        dim_t size() const { return this->len_; }
        T* data() { return this->data_; }
        const T* data() const { return this->data_; }

        template <typename U, dim_t L>
        friend Vector<U, L> operator + (const Vector<U, L>& v, const Vector<U, L>& u);
        template <typename U, dim_t L>
        friend Vector<U, L> operator - (const Vector<U, L>& v, const Vector<U, L>& u);
        template <typename U, dim_t L>
        friend Vector<U, L> operator * (const Vector<U, L>& v, const Vector<U, L>& u);
        template <typename U, dim_t L>
        friend Vector<U, L> operator * (const Vector<U, L>& v, std::type_identity_t<U> scalar);
        template <typename U, dim_t L>
        friend Vector<U, L> operator / (const Vector<U, L>& v, const Vector<U, L>& u);
        template <typename U, dim_t L>
        friend Vector<U, L> operator / (const Vector<U, L>& v, std::type_identity_t<U> scalar);

        Vector& operator += (const Vector& other);
        Vector& operator -= (const Vector& other);
        Vector& operator *= (const Vector& other);
        Vector& operator *= (T scalar);
        Vector& operator /= (const Vector& other);
        Vector& operator /= (T scalar);

        Vector cross(const Vector& other) const;

        T dot(const Vector& other) const;
        T sum() const;
        T norm() const;

        Vector normalize() const;

    private:
        dim_t len_ = length_;
        T* data_ = nullptr;
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