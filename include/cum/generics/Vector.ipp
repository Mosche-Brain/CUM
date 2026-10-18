/*
 * @author: jaro
 * @name:   Vector
 * @file:   modules/cum/include/cum/generics/Vector.cpp
 * @date:   17 October 2026 09:38:23
 */

#pragma once

#include <stdexcept>
#include <type_traits>
#include <utility>

#include "cum/lara/vecops.hpp"
#include "cum/lara/BLAS/level1.hpp"
#include "cum/functions/various.hpp"
#include "cum/random.hpp"
#include "cum/generics/Vector.hpp"

namespace cum
{
    namespace detail
    {
        template <typename T, dim_t length_>
        Vector<T, length_> make_vector_like(dim_t len)
        {
            if constexpr (length_ == Dynamic)
            {
                return Vector<T, length_>(len);
            }
            else
            {
                (void)len;
                return Vector<T, length_>();
            }
        }
    }

    template <typename T, dim_t length_>
    Vector<T, length_>::Vector()
        : len_(length_ == Dynamic ? 0 : length_),
          data_(len_ > 0 ? memory::allocate<T>(len_) : nullptr)
    {
    }

    template <typename T, dim_t length_>
    Vector<T, length_>::Vector(dim_t len)
    {
        if (length_ != Dynamic)
            throw std::runtime_error("Called dynamic length contructor on fixed lenght vector");

        this->len_ = len;
        this->data_ = (len > 0) ? memory::allocate<T>(len) : nullptr;
    }

    template <typename T, dim_t length_>
    Vector<T, length_>::Vector(const Vector& other)
        : len_(other.len_),
          data_(other.len_ > 0 ? memory::allocate<T>(other.len_) : nullptr)
    {
        if (this->data_ && other.data_)
        {
            memory::memcopy(this->data_, other.data_, this->len_ * static_cast<dim_t>(sizeof(T))).wait();
        }
    }

    template <typename T, dim_t length_>
    Vector<T, length_>::Vector(Vector&& other) noexcept
        : len_(other.len_),
          data_(std::exchange(other.data_, nullptr))
    {
        if constexpr (length_ == Dynamic)
        {
            other.len_ = 0;
        }
    }

    template <typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator=(const Vector& other)
    {
        if (this != &other)
        {
            if (this->len_ != other.len_)
            {
                if (this->data_)
                {
                    memory::free(this->data_);
                }
                this->len_ = other.len_;
                this->data_ = (this->len_ > 0) ? memory::allocate<T>(this->len_) : nullptr;
            }
            if (this->data_ && other.data_)
            {
                memory::memcopy(this->data_, other.data_, this->len_ * static_cast<dim_t>(sizeof(T))).wait();
            }
        }
        return *this;
    }

    template <typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator=(Vector&& other) noexcept
    {
        if (this != &other)
        {
            if (this->data_)
            {
                memory::free(this->data_);
            }
            this->len_ = other.len_;
            this->data_ = std::exchange(other.data_, nullptr);
            if constexpr (length_ == Dynamic)
            {
                other.len_ = 0;
            }
        }
        return *this;
    }

    template <typename T, dim_t length_>
    Vector<T, length_>::~Vector()
    {
        if (this->data_)
        {
            memory::free(this->data_);
        }
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::random(T min, T max)
    {
        if (length_ == Dynamic)
            throw std::runtime_error("Cannot call static random(min, max) without length on dynamic vector");

        Vector<T, length_> result;
        random::uniform(type_tag<T>(), result.data_, static_cast<std::size_t>(result.len_), &min, &max);
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::random(dim_t len, T min, T max)
    {
        Vector<T, length_> result(len);
        random::uniform(type_tag<T>(), result.data_, static_cast<std::size_t>(result.len_), &min, &max);
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::zeros()
    {
        if (length_ == Dynamic)
            throw std::runtime_error("Cannot call static zeros() without length on dynamic vector");

        Vector<T, length_> result;
        functions::various::fill(type_tag<T>(), result.data_, 0._c, static_cast<std::size_t>(result.len_));
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::zeros(dim_t len)
    {
        Vector<T, length_> result(len);
        functions::various::fill(type_tag<T>(), result.data_, 0._c, static_cast<std::size_t>(result.len_));
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::ones()
    {
        if (length_ == Dynamic)
            throw std::runtime_error("Cannot call static ones() without length on dynamic vector");

        Vector<T, length_> result;
        functions::various::fill(type_tag<T>(), result.data_, 1._c, static_cast<std::size_t>(result.len_));
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::ones(dim_t len)
    {
        Vector<T, length_> result(len);
        functions::various::fill(type_tag<T>(), result.data_, 1._c, static_cast<std::size_t>(result.len_));
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator + (const Vector<T, length_>& lhs, const Vector<T, length_>& rhs)
    {
        auto result = detail::make_vector_like<T, length_>(lhs.len_);
        lara::vadd(type_tag<T>(), result.data_, lhs.data_, rhs.data_, lhs.len_).wait();
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator - (const Vector<T, length_>& lhs, const Vector<T, length_>& rhs)
    {
        auto result = detail::make_vector_like<T, length_>(lhs.len_);
        lara::vsub(type_tag<T>(), result.data_, lhs.data_, rhs.data_, lhs.len_).wait();
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator * (const Vector<T, length_>& lhs, const Vector<T, length_>& rhs)
    {
        auto result = detail::make_vector_like<T, length_>(lhs.len_);
        lara::vmul(type_tag<T>(), result.data_, lhs.data_, rhs.data_, lhs.len_).wait();
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator / (const Vector<T, length_>& lhs, const Vector<T, length_>& rhs)
    {
        auto result = detail::make_vector_like<T, length_>(lhs.len_);
        lara::vdiv(type_tag<T>(), result.data_, lhs.data_, rhs.data_, lhs.len_).wait();
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator * (const Vector<T, length_>& lhs, const std::type_identity_t<T> scalar)
    {
        Vector<T, length_> result(lhs);
        result *= scalar;
        return result;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> operator / (const Vector<T, length_>& lhs, const std::type_identity_t<T> scalar)
    {
        Vector<T, length_> result(lhs);
        result /= scalar;
        return result;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator += (const Vector<T, length_>& other)
    {
        lara::vadd(type_tag<T>(), this->data_, this->data_, other.data_, this->len_).wait();
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator -= (const Vector<T, length_>& other)
    {
        lara::vsub(type_tag<T>(), this->data_, this->data_, other.data_, this->len_).wait();
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator *= (const Vector<T, length_>& other)
    {
        lara::vmul(type_tag<T>(), this->data_, this->data_, other.data_, this->len_).wait();
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator /= (const Vector<T, length_>& other)
    {
        lara::vdiv(type_tag<T>(), this->data_, this->data_, other.data_, this->len_).wait();
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator *= (const T scalar)
    {
        blas::scal(type_tag<T>(), this->len_, &scalar, this->data_, 1).wait();
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_>& Vector<T, length_>::operator /= (const T scalar)
    {
        if constexpr (std::is_integral_v<T>)
        {
            for (dim_t i = 0; i < this->len_; ++i)
            {
                this->data_[i] = static_cast<T>(this->data_[i] / scalar);
            }
        }
        else
        {
            const T inv = static_cast<T>(static_cast<T>(1) / scalar);
            blas::scal(type_tag<T>(), this->len_, &inv, this->data_, 1).wait();
        }
        return *this;
    }

    template<typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::cross(const Vector& other) const
    {
        if (this->len_ != 3 || other.len_ != 3)
            throw std::runtime_error("Cross product is only defined for 3D vectors");

        auto result = detail::make_vector_like<T, length_>(3);
        result.data_[0] = static_cast<T>(this->data_[1] * other.data_[2] - this->data_[2] * other.data_[1]);
        result.data_[1] = static_cast<T>(this->data_[2] * other.data_[0] - this->data_[0] * other.data_[2]);
        result.data_[2] = static_cast<T>(this->data_[0] * other.data_[1] - this->data_[1] * other.data_[0]);
        return result;
    }

    template<typename T, dim_t length_>
    T Vector<T, length_>::norm() const
    {
        T* result = memory::allocate<T>(1);
        blas::nrm2(type_tag<T>(), this->len_, this->data_, 1, result).wait();
        const T val = *result;
        memory::free(result);
        return val;
    }

    template <typename T, dim_t length_>
    T Vector<T, length_>::dot(const Vector& other) const
    {
        T* result = memory::allocate<T>(1);
        blas::dot(type_tag<T>(), this->len_, this->data_, 1, other.data_, 1, result).wait();
        const T val = *result;
        memory::free(result);
        return val;
    }

    template <typename T, dim_t length_>
    T Vector<T, length_>::sum() const
    {
        T acc = static_cast<T>(0);
        for (dim_t i = 0; i < this->len_; ++i)
        {
            acc = static_cast<T>(acc + this->data_[i]);
        }
        return acc;
    }

    template <typename T, dim_t length_>
    Vector<T, length_> Vector<T, length_>::normalize() const
    {
        return (*this) / this->norm();
    }
}
