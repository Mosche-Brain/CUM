/**
 * @file Vector.hpp
 * @brief Templated generic vector class supporting both fixed compile-time and dynamic dimensions.
 * @author jaro
 * @details Provides generic vector arithmetic, dot/cross products, normalization, and predefined aliases
 *          (ivec2-4, fvec2-4, dvec2-4, hvec2-4).
 */

#pragma once

#include <type_traits>

#include "cum/Core.hpp"
#include "cum/memory.hpp"

namespace cum
{
    /**
     * @brief Sentinel constant indicating dynamic (runtime) dimension sizing.
     */
    constexpr dim_t Dynamic = -1;

    /**
     * @class Vector
     * @brief Templated generic 1D dense vector.
     * @tparam T Element type.
     * @tparam length_ Dimension length (default is Dynamic for runtime sizing).
     */
    template<typename T, dim_t length_=Dynamic>
    class Vector
    {
    public:
        /**
         * @brief Default constructor.
         */
        Vector();

        /**
         * @brief Constructs dynamic vector of specified length.
         * @param len Length of the vector.
         */
        Vector(dim_t len);

        /**
         * @brief Copy constructor.
         * @param other Vector to copy from.
         */
        Vector(const Vector& other);

        /**
         * @brief Move constructor.
         * @param other Vector to move from.
         */
        Vector(Vector&& other) noexcept;

        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other) noexcept;

        ~Vector();

        /**
         * @brief Creates random vector with fixed compile-time length.
         * @param min Minimum random bound.
         * @param max Maximum random bound.
         * @return Random Vector.
         */
        static Vector random(T min = static_cast<T>(-1), T max = static_cast<T>(1));

        /**
         * @brief Creates random dynamic vector of specified length.
         * @param len Vector length.
         * @param min Minimum random bound.
         * @param max Maximum random bound.
         * @return Random Vector.
         */
        static Vector random(dim_t len, T min, T max);

        /**
         * @brief Creates zero-filled vector with fixed compile-time length.
         * @return Zero-filled Vector.
         */
        static Vector zeros();

        /**
         * @brief Creates zero-filled dynamic vector of specified length.
         * @param len Vector length.
         * @return Zero-filled Vector.
         */
        static Vector zeros(dim_t len);

        /**
         * @brief Creates ones-filled vector with fixed compile-time length.
         * @return Ones-filled Vector.
         */
        static Vector ones();

        /**
         * @brief Creates ones-filled dynamic vector of specified length.
         * @param len Vector length.
         * @return Ones-filled Vector.
         */
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

        /**
         * @brief Computes 3D vector cross product.
         * @param other Right-hand side vector.
         * @return Cross product Vector.
         */
        Vector cross(const Vector& other) const;

        /**
         * @brief Computes inner dot product with another vector.
         * @param other Vector operand.
         * @return Scalar dot product.
         */
        T dot(const Vector& other) const;

        /**
         * @brief Computes sum of all vector elements.
         * @return Scalar sum.
         */
        T sum() const;

        /**
         * @brief Computes Euclidean L2 norm of vector.
         * @return Scalar norm.
         */
        T norm() const;

        /**
         * @brief Computes normalized vector with unit L2 norm.
         * @return Normalized Vector.
         */
        Vector normalize() const;

    private:
        dim_t len_ = length_;
        T* data_ = nullptr;
    };

    /** @brief 2-element integer vector. */
    using ivec2 = Vector<int, 2>;
    /** @brief 3-element integer vector. */
    using ivec3 = Vector<int, 3>;
    /** @brief 4-element integer vector. */
    using ivec4 = Vector<int, 4>;

    /** @brief 2-element single-precision float vector. */
    using fvec2 = Vector<float32, 2>;
    /** @brief 3-element single-precision float vector. */
    using fvec3 = Vector<float32, 3>;
    /** @brief 4-element single-precision float vector. */
    using fvec4 = Vector<float32, 4>;

    /** @brief 2-element double-precision float vector. */
    using dvec2 = Vector<float64, 2>;
    /** @brief 3-element double-precision float vector. */
    using dvec3 = Vector<float64, 3>;
    /** @brief 4-element double-precision float vector. */
    using dvec4 = Vector<float64, 4>;

    /** @brief 2-element half-precision float vector. */
    using hvec2 = Vector<float16, 2>;
    /** @brief 3-element half-precision float vector. */
    using hvec3 = Vector<float16, 3>;
    /** @brief 4-element half-precision float vector. */
    using hvec4 = Vector<float16, 4>;
} // namespace cum

#include "Vector.ipp"
