/**
 * @file MatrixView.hpp
 * @brief Non-owning read-only view class over 2D matrix memory buffers.
 * @author jaro
 */

#ifndef YANN_MATRIXVIEW_HPP
#define YANN_MATRIXVIEW_HPP

#include "Core.hpp"
#include "cum/Vector.hpp"
#include <initializer_list>
#include "cum/Matrix.hpp"

namespace cum
{
    /**
     * @class MatrixView
     * @brief Lightweight, non-owning read view over a 2D matrix or existing data buffer.
     * @details Provides safe read access, row/column slicing, arithmetic with other matrices,
     *          and reductions without copying the underlying buffer.
     */
    class MatrixView
    {
    public:
        /**
         * @brief Constructs a view over an existing Matrix.
         * @param other Matrix to view.
         */
        MatrixView(const Matrix& other);

        /**
         * @brief Move constructor.
         * @param other Matrix to view.
         */
        MatrixView(Matrix&& other) noexcept;

        /**
         * @brief Constructs a view over a raw pointer buffer.
         * @param source Pointer to data.
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        MatrixView(cumeric_t* source, dim_t rows, dim_t cols);

        /**
         * @brief Constructs a view over a raw pointer buffer (dimensions first).
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param source Pointer to data.
         */
        MatrixView(dim_t rows, dim_t cols, cumeric_t* source);

        /**
         * @brief Constructs a view over a const raw pointer buffer.
         * @param source Const pointer to data.
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        MatrixView(const cumeric_t* source, dim_t rows, dim_t cols);

        /**
         * @brief Constructs a view over a const raw pointer buffer (dimensions first).
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param source Const pointer to data.
         */
        MatrixView(dim_t rows, dim_t cols, const cumeric_t* source);

        /**
         * @brief Default constructor creating an empty view.
         */
        MatrixView() = default;

        /**
         * @brief Destructor (does not free viewed memory).
         */
        ~MatrixView();

        /**
         * @brief Returns the number of rows in the view.
         * @return Row count.
         */
        std::size_t rows() const { return rows_; }

        /**
         * @brief Returns the number of columns in the view.
         * @return Column count.
         */
        std::size_t cols() const { return cols_; }

        /**
         * @brief Extracts a row as a new Matrix.
         * @param i Row index.
         * @return Extracted row Matrix.
         */
        Matrix row(std::size_t i) const;

        /**
         * @brief Extracts a column as a new Matrix.
         * @param i Column index.
         * @return Extracted column Matrix.
         */
        Matrix col(std::size_t i) const;

        /**
         * @brief Returns the total number of elements in the view.
         * @return Total element count.
         */
        std::size_t size() const { return rows_ * cols_; }

        /* Accessors */

        /**
         * @brief Returns const raw data pointer.
         * @return Const pointer to underlying data.
         */
        const cumeric_t* data() const { return data_; };

        /**
         * @brief Indexed const element access.
         * @param row Row index.
         * @param col Column index.
         * @return Const reference to element.
         */
        const cumeric_t& at(const std::size_t row, const std::size_t col) const { return data_[get_idx(row, col)]; }

        /**
         * @brief Function call operator for indexed const element access.
         * @param row Row index.
         * @param col Column index.
         * @return Const reference to element.
         */
        const cumeric_t& operator () (const std::size_t row, const std::size_t col) const { return data_[get_idx(row, col)]; };

        /**
         * @brief Sets target matrix with viewed data.
         * @param other Target matrix.
         * @return Reference to modified matrix.
         */
        Matrix& set(const Matrix& other);

        /* Out-of-place arithmetic operators */
        friend Matrix operator + (const Matrix& A, const Matrix& B);
        friend Matrix operator - (const Matrix& A, const Matrix& B);
        friend Matrix operator * (const Matrix& A, const Matrix& B);
        friend Matrix operator * (const Matrix& mat, const cumeric_t& scalar);
        friend Matrix operator / (const Matrix& A, const Matrix& B);
        friend Matrix operator / (const Matrix& mat, const cumeric_t& scalar);

        /* Transformations */
        Matrix transpose() const;
        Vector flatten() const;
        Matrix reshape(std::size_t rows, std::size_t cols) const;

        friend Matrix activation(const Matrix& mat, const char* name);
        friend Matrix activationInPlace(Matrix& mat, const char* name);

        Matrix cwiseProduct(const Matrix& other);

        Matrix transform(void (*func)(cumeric_t* data, const std::size_t size)) const;
        Matrix transform(cumeric_t (*func)(cumeric_t x)) const;

        Matrix clip(cumeric_t min, cumeric_t max) const;

        cumeric_t norm();
        cumeric_t squaredNorm();

        Matrix colwiseSum();
        Vector colwiseSum2vec();
        Matrix rowwiseSum();
        Vector rowwiseSum2vec();

        Matrix shuffleRows() const;

    private:
        std::size_t get_idx(const std::size_t row, const std::size_t col) const { return row * cols_ + col; }

        std::size_t rows_, cols_;
        const cumeric_t* data_;
    };
} // namespace cum

#endif //YANN_MATRIXVIEW_HPP
