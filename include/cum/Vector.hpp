/**
 * @file Vector.hpp
 * @brief Dynamic 1D dense vector class with BLAS operations and matrix interoperability.
 */

#pragma once

#include "cum/Matrix.hpp"

namespace cum
{
    class Matrix;

    /**
     * @class Vector
     * @brief 1D numeric dense vector allocated in unified device memory.
     * @details Provides vector arithmetic, dot product, normalization, and conversion to/from @ref Matrix.
     */
    class Vector
    {
    public:
        /**
         * @brief Constructs an uninitialized vector of the given length.
         * @param lenght Number of elements.
         */
        Vector(dim_t lenght);

        /**
         * @brief Constructs a vector of the given length filled with an initial scalar value.
         * @param lenght Number of elements.
         * @param value Initial value for each element.
         */
        Vector(std::size_t lenght, cumeric_t value);

        /**
         * @brief Default constructor creating an empty vector.
         */
        Vector() = default;

        /**
         * @brief Implicit conversion operator from Vector to 1D/column Matrix.
         * @return Matrix representation of the vector.
         */
        operator Matrix() const;
        
        /**
         * @brief Subscript access operator (lvalue reference).
         * @param index Element zero-based index.
         * @return Reference to the element.
         */
        cumeric_t& operator[](const std::size_t index) { return this->data_[index]; }

        /**
         * @brief Subscript access operator (const value).
         * @param index Element zero-based index.
         * @return Element value.
         */
        const cumeric_t operator[](const std::size_t index) const { return this->data_[index]; }

        /**
         * @brief Returns pointer to the underlying raw memory buffer.
         * @return Pointer to @ref cumeric_t elements.
         */
        cumeric_t* data() { return data_; }

        /**
         * @brief Returns the length (number of elements) of the vector.
         * @return Element count.
         */
        std::size_t lenght() const { return lenght_; }

        /**
         * @brief Returns the total size (number of elements) of the vector.
         * @return Element count.
         */
        std::size_t size()   const { return lenght_; }

        /**
         * @brief In-place vector addition (`this += other`).
         * @param other Vector to add.
         * @return Reference to `*this`.
         */
        Vector& operator += (const Vector& other);

        /**
         * @brief In-place matrix addition.
         * @param matrix Matrix to add.
         * @return Reference to `*this`.
         */
        Vector& operator += (Matrix& matrix);

        /**
         * @brief In-place vector subtraction (`this -= other`).
         * @param other Vector to subtract.
         * @return Reference to `*this`.
         */
        Vector& operator -= (const Vector& other);

        /**
         * @brief In-place elementwise vector multiplication.
         * @param other Vector to multiply with.
         * @return Reference to `*this`.
         */
        Vector& operator *= (const Vector& other);

        /**
         * @brief In-place scalar multiplication.
         * @param scalar Scalar multiplier.
         * @return Reference to `*this`.
         */
        Vector& operator *= (const cumeric_t& scalar);

        /**
         * @brief In-place elementwise vector division.
         * @param other Vector denominator.
         * @return Reference to `*this`.
         */
        Vector& operator /= (const Vector& other);

        /**
         * @brief Elementwise addition of two vectors.
         * @param v First vector.
         * @param u Second vector.
         * @return Sum vector.
         */
        friend Vector operator + (const Vector& v, const Vector& u);

        /**
         * @brief Addition of a vector and a matrix.
         * @param v Left vector operand.
         * @param A Right matrix operand.
         * @return Sum vector.
         */
        friend Vector operator + (const Vector& v, const Matrix& A);

        /**
         * @brief Elementwise subtraction of two vectors.
         * @param v First vector.
         * @param u Second vector.
         * @return Difference vector.
         */
        friend Vector operator - (const Vector& v, const Vector& u);

        /**
         * @brief Elementwise multiplication of two vectors.
         * @param v First vector.
         * @param u Second vector.
         * @return Product vector.
         */
        friend Vector operator * (const Vector& v, const Vector& u);

        /**
         * @brief Scalar multiplication of a vector.
         * @param v Vector.
         * @param scalar Scalar value.
         * @return Scaled vector.
         */
        friend Vector operator * (const Vector& v, const cumeric_t& scalar);

        /**
         * @brief Elementwise division of two vectors.
         * @param v Numerator vector.
         * @param u Denominator vector.
         * @return Quotient vector.
         */
        friend Vector operator / (const Vector& v, const Vector& u);

        /**
         * @brief Computes the dot (inner) product with another vector.
         * @param other Vector to compute dot product with.
         * @return Result vector containing the dot product.
         */
        Vector dot(const Vector& other);

        /**
         * @brief In-place dot product computation.
         * @param other Vector to compute dot product with.
         * @return Reference to `*this`.
         */
        Vector& dotInPlace(const Vector& other);

        /**
         * @brief Computes the sum of all elements in the vector.
         * @return Scalar sum.
         */
        cumeric_t sum();

        /**
         * @brief Normalizes the vector to unit L2 norm, returning a new vector.
         * @return Normalized vector.
         */
        Vector normalize();

        /**
         * @brief Normalizes the vector in-place.
         * @return Reference to `*this`.
         */
        Vector& normalizeInPlace();

    private:
        std::size_t lenght_;
        cumeric_t* data_;
    };
} // namespace cum
