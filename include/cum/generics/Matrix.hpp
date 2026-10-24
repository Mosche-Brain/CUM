/**
 * @file Matrix.hpp
 * @brief Templated generic 2D matrix class with fixed compile-time or dynamic dimensions.
 * @author jaro
 * @details Implements arithmetic, transposition, reshaping, flattening, and matrix multiplication (matmul).
 */

#pragma once

#include <span>

#include "cum/Core.hpp"

namespace cum
{
    /**
     * @class Matrix
     * @brief Templated generic dense matrix.
     * @tparam T Element type.
     * @tparam rows_ Row dimension (default Dynamic for runtime sizing).
     * @tparam cols_ Column dimension (default Dynamic for runtime sizing).
     */
    template<typename T, dim_t rows_, dim_t cols_>
    class Matrix
    {
    public:
        /**
         * @brief Default constructor.
         */
        Matrix();

        /**
         * @brief Constructs dynamic matrix of given dimensions.
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        Matrix(dim_t rows, dim_t cols);

        /**
         * @brief Constructs matrix by copying data from a span view.
         * @param data Source span view.
         */
        Matrix(std::span<T> data);

        ~Matrix();

        /**
         * @brief Returns number of rows.
         * @return Row count.
         */
        constexpr dim_t rows() const noexcept;

        /**
         * @brief Returns number of columns.
         * @return Column count.
         */
        constexpr dim_t cols() const noexcept;

        /**
         * @brief Returns total number of elements.
         * @return Element count.
         */
        constexpr dim_t elements() const noexcept;

        /**
         * @brief Transposes matrix out-of-place.
         * @return Transposed Matrix of dimensions cols_ x rows_.
         */
        Matrix<T, cols_, rows_> transpose() const;

        /**
         * @brief Reshapes matrix into dynamic dimensions.
         * @param rows New row count.
         * @param cols New column count.
         * @return Reshaped dynamic Matrix.
         */
        Matrix<T, Dynamic, Dynamic> reshape(dim_t rows, dim_t cols) const;

        /**
         * @brief Flattens matrix into 1 x elements row matrix.
         * @return Flattened dynamic Matrix.
         */
        Matrix<T, Dynamic, Dynamic> flatten() const;

        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator + (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator - (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator * (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator / (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);

        // In-place operators
        Matrix<T, rows_, cols_>& operator += (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator -= (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator *= (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator /= (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator *= (T scalar);
        Matrix<T, rows_, cols_>& operator /= (T scalar);

        /**
         * @brief Multiplies with another matrix: @p result = *this * other.
         * @param other Right matrix operand.
         * @return Product Matrix.
         */
        Matrix<T, rows_, Dynamic> matmul(const Matrix<T, cols_, Dynamic>& other) const;

    private:
        dim_t _rows;
        dim_t _cols;
        T* data_;
    };
} // namespace cum

#include "cum/generics/Matrix.ipp"
