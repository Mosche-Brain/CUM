/*
 * @author: jaro
 * @name:   Matrix
 * @file:   include/cum/generics/Matrix.hpp
 * @date:   18 October 2026 08:25:22
 */

#pragma once

#include <span>

#include "cum/Core.hpp"

namespace cum
{
    constexpr dim_t Dynamic = -1;
    template<typename T, dim_t rows_, dim_t cols_>
    class Matrix
    {
    public:
        Matrix();
        Matrix(dim_t rows, dim_t cols); // For dynamic size
        Matrix(std::span<T> data); // copy data from the view

        ~Matrix();

        constexpr dim_t rows() const noexcept;
        constexpr dim_t cols() const noexcept;
        constexpr dim_t elements() const noexcept;

        Matrix<T, cols_, rows_> transpose() const;
        Matrix<T, Dynamic, Dynamic> reshape(dim_t rows, dim_t cols) const;
        Matrix<T, Dynamic, Dynamic> flatten() const;


        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator + (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator - (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator * (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);
        template<typename Type, dim_t height, dim_t width>
        friend Matrix<Type, height, width> operator / (const Matrix<Type, height, width>& lhs, const Matrix<Type, height, width>& rhs);

        // friend Matrix operator * (const Matrix<T, cols_, Dynamic>& other) const;
        // friend Matrix operator * (T scalar) const;

        // in place operators
        Matrix<T, rows_, cols_>& operator += (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator -= (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator *= (const Matrix<T, rows_, cols_>& other); // eltwise
        Matrix<T, rows_, cols_>& operator /= (const Matrix<T, rows_, cols_>& other);
        Matrix<T, rows_, cols_>& operator *= (T scalar);
        Matrix<T, rows_, cols_>& operator /= (T scalar);

        Matrix<T, rows_, Dynamic> matmul(const Matrix<T, cols_, Dynamic>& other) const;

    private:
        // constexpr rws_()

        dim_t _rows;
        dim_t _cols;
        T* data_;
    };
} // cum

#include "cum/generics/Matrix.ipp"