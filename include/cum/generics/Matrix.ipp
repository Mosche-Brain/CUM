/**
 * @file Matrix.ipp
 * @brief Template implementation for generic Matrix methods and operators.
 * @author jaro
 */

#pragma once

#include "cum/LinearAlgebra.hpp"
#include "cum/memory.hpp"

#include "cum/lara/matops.hpp"
#include "cum/lara/vecops.hpp"
#include "cum/lara/BLAS/level3.hpp"

#include "cum/generics/Matrix.hpp"

namespace cum
{
    namespace detail
    {
        template<typename T, dim_t rows_, dim_t cols_>
        Matrix<T, rows_, cols_> make_matrix_like([[maybe_unused]] dim_t rows, [[maybe_unused]] dim_t cols)
        {
            if constexpr (rows_ == Dynamic && cols_ == Dynamic)
                return Matrix<T, rows_, cols_>(rows, cols);
            else
                return Matrix<T, rows_, cols_>();
        }
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>::Matrix() : _rows(rows_), _cols(cols_), data_(memory::allocate(rows_ * cols_))
    {
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>::Matrix(dim_t rows, dim_t cols)
    {
        if (rows_ != Dynamic && rows_ != rows)
            throw std::invalid_argument("rows_ != Dynamic && rows_ != rows");
        if (cols_ != Dynamic && cols_ != cols)
            throw std::invalid_argument("cols_ != Dynamic && cols_ != cols");

        _rows = rows;
        _cols = cols;
        data_ = memory::allocate(rows * cols);
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>::~Matrix()
    {
        memory::free(data_);
    }

    template <typename T, dim_t rows_, dim_t cols_>
    constexpr dim_t Matrix<T, rows_, cols_>::rows() const noexcept
    {
        if constexpr (rows_ == Dynamic)
            return _rows;
        else
            return rows_;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    constexpr dim_t Matrix<T, rows_, cols_>::cols() const noexcept
    {
        if constexpr (cols_ == Dynamic)
            return _cols;
        else
            return cols_;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    constexpr dim_t Matrix<T, rows_, cols_>::elements() const noexcept
    {
        if constexpr (cols_ == Dynamic || rows_ == Dynamic)
            return _cols * _rows;
        else
            return cols_ * rows_;
    }


    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, cols_, rows_> Matrix<T, rows_, cols_>::transpose() const
    {
        Matrix<T, cols_, rows_> temp;
        lara::transpose(temp.data_, data_, this->rows(), this->cols());
        return temp;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_> operator + (const Matrix<T, rows_, cols_>& lhs, const Matrix<T, rows_, cols_> rhs) const
    {
        auto result = detail::make_matrix_like<T, rows_, cols_>(lhs.rows(), lhs.cols());
        lara::vsub(result.data_, lhs.data_, rhs.data_, this->elements());
        return result;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_> operator - (const Matrix<T, rows_, cols_>& lhs, const Matrix<T, rows_, cols_> rhs) const
    {
        auto result = detail::make_matrix_like<T, rows_, cols_>(lhs.rows(), lhs.cols());
        lara::vsub(result.data_, lhs.data_, rhs.data_, this->elements());
        return result;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_> operator * (const Matrix<T, rows_, cols_>& lhs, const Matrix<T, rows_, cols_> rhs) const
    {
        auto result = detail::make_matrix_like<T, rows_, cols_>(lhs.rows(), lhs.cols());
        lara::vmul(result.data_, lhs.data_, rhs.data_, this->elements());
        return result;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_> operator / (const Matrix<T, rows_, cols_>& lhs, const Matrix<T, rows_, cols_> rhs) const
    {
        auto result = detail::make_matrix_like<T, rows_, cols_>(lhs.rows(), lhs.cols());
        lara::vdiv(result.data_, lhs.data_, rhs.data_, this->elements());
        return result;
    }


    // in-place operators

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>& Matrix<T, rows_, cols_>::operator += (const Matrix<T, rows_, cols_>& rhs)
    {
        lara::vadd(data_, data_, rhs.data_, this->elements());
        return *this;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>& Matrix<T, rows_, cols_>::operator -= (const Matrix<T, rows_, cols_>& rhs)
    {
        lara::vsub(data_, data_, rhs.data_, this->elements());
        return *this;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>& Matrix<T, rows_, cols_>::operator *= (const Matrix<T, rows_, cols_>& rhs)
    {
        lara::vmul(data_, rhs.data_, this->rows(), rhs.cols(), this->cols());
        return *this;
    }

    template <typename T, dim_t rows_, dim_t cols_>
    Matrix<T, rows_, cols_>& Matrix<T, rows_, cols_>::operator /= (const Matrix<T, rows_, cols_>& rhs)
    {
        lara::vdiv(data_, data_, rhs.data_, this->elements());
    }

}
