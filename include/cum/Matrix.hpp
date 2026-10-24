/**
 * @file Matrix.hpp
 * @brief Dynamic 2D dense matrix class with BLAS operations, elementwise activations, and reductions.
 */

#pragma once

#include "Core.hpp"
#include "cum/Vector.hpp"

#include <cstddef>
#include <initializer_list>

namespace cum
{
    class Vector;

    /**
     * @enum MemoryAlingment
     * @brief Memory storage ordering (RowMajor vs ColMajor).
     */
    enum MemoryAlingment { RowMajor, ColMajor }; // not used yet

    /**
     * @class Matrix
     * @brief 2D dense numerical matrix allocated in device unified memory.
     * @details Provides arithmetic operations, BLAS routines, in-place and out-of-place transformations,
     *          activation functions, slicing, and reductions.
     */
    class Matrix
    {
    public:
        /**
         * @brief Constructs an uninitialized matrix of given dimensions.
         * @param rows Number of rows.
         * @param cols Number of columns.
         */
        Matrix(dim_t rows, dim_t cols);

        /**
         * @brief Constructs a matrix of given dimensions filled with an initial scalar value.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param value Initial value for each element.
         */
        Matrix(dim_t rows, dim_t cols, cumeric_t value);

        /**
         * @brief Constructs a matrix and copies data from a raw source buffer.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param source Pointer to source data to copy from.
         */
        Matrix(dim_t rows, dim_t cols, cumeric_t* source);

        /**
         * @brief Constructs a matrix and copies data from a const raw source buffer.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param source Pointer to const source data to copy from.
         */
        Matrix(dim_t rows, dim_t cols, const cumeric_t* source);

        /**
         * @brief Constructs a matrix from an initializer list of elements.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param elements Initializer list of @ref cumeric_t elements.
         */
        Matrix(dim_t rows, dim_t cols, std::initializer_list<cumeric_t> elements);

        /**
         * @brief Copy constructor performing deep copy of underlying buffer.
         * @param other Matrix to copy from.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Move constructor transferring ownership of data buffer.
         * @param other Matrix to move from.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Default constructor creating an empty 0x0 matrix.
         */
        Matrix() = default;

        /**
         * @brief Destructor deallocating memory buffer.
         */
        ~Matrix();

        /* Functions for advanced initialization */

        /**
         * @brief Creates a matrix initialized with uniformly distributed random numbers.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param min Minimum random value (default -1.0).
         * @param max Maximum random value (default 1.0).
         * @return Randomly initialized matrix.
         */
        static Matrix Random(dim_t rows, dim_t cols, cumeric_t min = -1_c, cumeric_t max = 1_c);

        /**
         * @brief Creates a matrix filled with zeros.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @return Zero-filled matrix.
         */
        static Matrix Zeros(dim_t rows, dim_t cols);

        /**
         * @brief Creates a matrix filled with ones.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @return Ones-filled matrix.
         */
        static Matrix Ones(dim_t rows, dim_t cols);

        /**
         * @brief Creates a 1 x num row vector matrix with values linearly spaced between start and end.
         * @param start Initial value.
         * @param end Final value.
         * @param num Number of linearly spaced elements.
         * @return 1 x num Matrix row vector.
         */
        static Matrix Linspace(cumeric_t start, cumeric_t end, dim_t num);

        /**
         * @brief Creates an explicit deep copy of a matrix.
         * @param mat Matrix to copy.
         * @return Cloned matrix.
         */
        static Matrix Copy(const Matrix& mat);

        /**
         * @brief Creates a non-owning read view of an existing matrix.
         * @param mat Source matrix.
         * @return Const matrix view.
         */
        static const Matrix View(const Matrix& mat);

        /* Conversions */

        /**
         * @brief Conversion operator from Matrix to @ref Vector (flattens into 1D vector).
         * @return Vector representation.
         */
        operator Vector() const;

        /**
         * @brief Fills all matrix elements with a scalar value.
         * @param value Scalar value to write.
         */
        void fill(cumeric_t value);

        /**
         * @brief Returns the number of rows.
         * @return Row count.
         */
        dim_t rows() const { return rows_; }

        /**
         * @brief Returns the number of columns.
         * @return Column count.
         */
        dim_t cols() const { return cols_; }
        
        /**
         * @brief Extracts a row as a 1 x cols Matrix.
         * @param i Zero-based row index.
         * @return 1 x cols Matrix.
         */
        Matrix row(const dim_t i) const;

        /**
         * @brief Extracts a column as a rows x 1 Matrix.
         * @param i Zero-based column index.
         * @return rows x 1 Matrix.
         */
        Matrix col(const dim_t i) const;
        
        /**
         * @brief Returns total number of elements (rows * cols).
         * @return Total element count.
         */
        dim_t size() const { return rows_ * cols_; }
        
        /* Accessors */

        /**
         * @brief Returns raw data pointer.
         * @return Pointer to underlying @ref cumeric_t buffer.
         */
        cumeric_t* data() { return data_; };

        /**
         * @brief Returns const raw data pointer.
         * @return Const pointer to underlying @ref cumeric_t buffer.
         */
        const cumeric_t* data() const { return data_; };

        /**
         * @brief Indexed element access (lvalue reference).
         * @param row Row index.
         * @param col Column index.
         * @return Reference to the element at (row, col).
         */
        cumeric_t& at(const dim_t row, const dim_t col) { return data_[get_idx(row, col)]; }

        /**
         * @brief Indexed element access (const reference).
         * @param row Row index.
         * @param col Column index.
         * @return Const reference to the element at (row, col).
         */
        const cumeric_t& at(const dim_t row, const dim_t col) const { return data_[get_idx(row, col)]; }

        /**
         * @brief Function call operator for indexed element access (lvalue reference).
         * @param row Row index.
         * @param col Column index.
         * @return Reference to the element at (row, col).
         */
        cumeric_t& operator () (const dim_t row, const dim_t col) { return data_[get_idx(row, col)]; };

        /**
         * @brief Function call operator for indexed element access (const reference).
         * @param row Row index.
         * @param col Column index.
         * @return Const reference to the element at (row, col).
         */
        const cumeric_t& operator () (const dim_t row, const dim_t col) const { return data_[get_idx(row, col)]; };

        /**
         * @brief Extracts a submatrix block starting at (i, j).
         * @param i Starting row index.
         * @param j Starting column index.
         * @param rows Number of rows in submatrix.
         * @param cols Number of columns in submatrix.
         * @return Extracted submatrix.
         */
        Matrix slice(dim_t i, dim_t j, dim_t rows, dim_t cols) const;

        /* Assignment operators */

        /**
         * @brief Deep-copies data from another matrix into `*this`.
         * @param other Matrix to copy from.
         * @return Reference to `*this`.
         */
        Matrix& set(const Matrix& other);

        /**
         * @brief Copy/move assignment operator via copy-and-swap idiom.
         * @param other Matrix passed by value.
         * @return Reference to `*this`.
         */
        Matrix& operator = (Matrix other) noexcept;

        /**
         * @brief Swaps internal state with another matrix.
         * @param other Matrix to swap with.
         */
        void swap(Matrix& other);

        /**
         * @brief Non-member swap function.
         * @param A First matrix.
         * @param B Second matrix.
         */
        friend void swap(Matrix& A, Matrix& B);

        /* In-place arithmetic operators */
        Matrix& operator += (const Matrix& other);
        Matrix& operator += (const cumeric_t& scalar);
        Matrix& operator -= (const Matrix& other);
        Matrix& operator -= (const cumeric_t& scalar);
        Matrix& operator *= (const Matrix& other);
        Matrix& operator *= (const cumeric_t& scalar);
        Matrix& operator /= (const Matrix& other);
        Matrix& operator /= (const cumeric_t& scalar);
  
        /* Out-of-place arithmetic operators */
        friend Matrix operator + (const Matrix& A, const Matrix& B);
        friend Matrix operator + (const Matrix& mat, cumeric_t scalar);
        friend Matrix operator + (const cumeric_t scalar, const Matrix& mat);
        friend Matrix operator - (const Matrix& A, const Matrix& B);
        friend Matrix operator * (const Matrix& A, const Matrix& B);
        friend Matrix operator * (const Matrix& mat, cumeric_t scalar);
        friend Matrix operator * (const cumeric_t scalar, const Matrix& mat);
        friend Matrix operator / (const Matrix& A, const Matrix& B);
        friend Matrix operator / (const Matrix& mat, cumeric_t scalar);
        friend Matrix operator / (const cumeric_t scalar, const Matrix& mat);
        friend bool operator == (const Matrix& A, const Matrix& B);
        friend bool operator != (const Matrix& A, const Matrix& B);
        
        /* Dimension transformations */

        /**
         * @brief Computes matrix transpose out-of-place.
         * @return Transposed cols x rows Matrix.
         */
        Matrix transpose() const;

        /**
         * @brief Transposes matrix in-place.
         * @return Reference to `*this`.
         */
        Matrix& transposeInPlace();

        /**
         * @brief Flattens matrix into 1 x (rows*cols) row matrix.
         * @return Flattened matrix.
         */
        Matrix flatten() const;

        /**
         * @brief Reshapes matrix into given dimensions out-of-place.
         * @param rows New row count.
         * @param cols New column count.
         * @return Reshaped matrix.
         */
        Matrix reshape(const dim_t rows, const dim_t cols) const;

        /**
         * @brief Reshapes matrix in-place.
         * @param rows New row count.
         * @param cols New column count.
         * @return Reference to `*this`.
         */
        Matrix& reshapeInPlace(dim_t rows, dim_t cols);

        /**
         * @brief Applies named neural activation function out-of-place.
         * @param mat Input matrix.
         * @param name Activation function name (e.g. "relu", "sigmoid", "tanh").
         * @return Activated matrix.
         */
        friend Matrix activation(const Matrix& mat, const char* name);

        /**
         * @brief Applies named neural activation function in-place.
         * @param mat Matrix to activate in-place.
         * @param name Activation function name.
         * @return Reference to modified matrix.
         */
        friend Matrix activationInPlace(Matrix& mat, const char* name);

        /**
         * @brief Computes Hadamard (component-wise) product out-of-place.
         * @param other Matrix of identical dimensions.
         * @return Component-wise product matrix.
         */
        Matrix cwiseProduct(const Matrix& other);

        /**
         * @brief Computes component-wise product in-place.
         * @param other Matrix of identical dimensions.
         * @return Reference to `*this`.
         */
        Matrix& cwiseProductInPlace(const Matrix& other);

        /* Elementwise transformations */

        /**
         * @brief Applies an elementwise array operation function out-of-place.
         * @param func Function pointer accepting data pointer and size.
         * @return Transformed matrix.
         */
        Matrix transform(void (*func)(cumeric_t* data, const dim_t size)) const;

        /**
         * @brief Applies an elementwise array operation function in-place.
         * @param func Function pointer accepting data pointer and size.
         * @return Reference to `*this`.
         */
        Matrix& transformInPlace(void (*func)(cumeric_t* data, const dim_t size));

        /**
         * @brief Applies a scalar transformation function to each element out-of-place.
         * @param func Function pointer mapping scalar to scalar.
         * @return Transformed matrix.
         */
        Matrix transform(cumeric_t (*func)(cumeric_t x)) const;

        /**
         * @brief Applies a scalar transformation function to each element in-place.
         * @param func Function pointer mapping scalar to scalar.
         * @return Reference to `*this`.
         */
        Matrix& transformInPlace(cumeric_t (*func)(cumeric_t x));

        Matrix sin();
        Matrix& sinInPlace();

        Matrix cos();
        Matrix& cosInPlace();

        Matrix tan();
        Matrix& tanInPlace();

        Matrix sinh();
        Matrix& sinhInPlace();

        Matrix cosh();
        Matrix& coshInPlace();

        Matrix tanh();
        Matrix& tanhInPlace();

        Matrix sqrt();
        Matrix& sqrtInPlace();

        Matrix square();
        Matrix& squareInPlace();

        Matrix exp();
        Matrix& expInPlace();

        Matrix log();
        Matrix& logInPlace();

        Matrix relu();
        Matrix& reluInPlace();

        /**
         * @brief Applies an in-place row-wise vector operation across each row.
         * @param op Operation function receiving row pointer, vector pointer, and column count.
         * @param arr Row-length array operand.
         * @return Reference to `*this`.
         */
        Matrix& rowwiseOpInPlace(void (*op)(cumeric_t* row, const cumeric_t* v, const dim_t cols), const cumeric_t* arr);

        /**
         * @brief Applies an in-place column-wise vector operation across each column.
         * @param op Operation function receiving column pointer, vector pointer, and row count.
         * @param arr Column-length array operand.
         * @return Reference to `*this`.
         */
        Matrix& colwiseOpInPlace(void (*op)(cumeric_t* col, const cumeric_t* v, const dim_t rows), const cumeric_t* arr);

        /**
         * @brief Clamps all elements to [min, max] range out-of-place.
         * @param min Minimum boundary value.
         * @param max Maximum boundary value.
         * @return Clamped matrix.
         */
        Matrix clip(const cumeric_t min, const cumeric_t max) const;

        /**
         * @brief Clamps all elements to [min, max] range in-place.
         * @param min Minimum boundary value.
         * @param max Maximum boundary value.
         * @return Reference to `*this`.
         */
        Matrix& clipInPlace(const cumeric_t min, const cumeric_t max);

        /* Scalar reductions */

        /**
         * @brief Computes Frobenius / L2 Euclidean norm.
         * @return Norm value.
         */
        cumeric_t norm();

        /**
         * @brief Computes squared Frobenius norm.
         * @return Squared norm value.
         */
        cumeric_t squaredNorm();

        /**
         * @brief Computes sum of all matrix elements.
         * @return Scalar sum.
         */
        cumeric_t sum() const;

        /**
         * @brief Computes sum of absolute values of all elements (L1 norm).
         * @return L1 norm.
         */
        cumeric_t sumAbs() const;

        /**
         * @brief Computes arithmetic mean of all matrix elements.
         * @return Mean value.
         */
        cumeric_t mean() const;

        /**
         * @brief Computes mean of absolute values of all matrix elements.
         * @return Absolute mean value.
         */
        cumeric_t amean() const;

        /* Vector reductions */

        /**
         * @brief Computes column-wise sums, returning a 1 x cols Matrix.
         * @return 1 x cols Matrix containing sum of each column.
         */
        Matrix colwiseSum();

        /**
         * @brief Computes column-wise sums, returning a Vector.
         * @return Vector of column sums.
         */
        Vector colwiseSum2vec();

        /**
         * @brief Computes row-wise sums, returning a rows x 1 Matrix.
         * @return rows x 1 Matrix containing sum of each row.
         */
        Matrix rowwiseSum();

        /**
         * @brief Computes row-wise sums, returning a Vector.
         * @return Vector of row sums.
         */
        Vector rowwiseSum2vec();

        /**
         * @brief Shuffles rows randomly out-of-place.
         * @return Matrix with shuffled rows.
         */
        Matrix shuffleRows() const;

        /**
         * @brief Shuffles rows randomly in-place.
         * @return Reference to `*this`.
         */
        Matrix& shuffleRowsInPlace();

    private:
        dim_t get_idx(const dim_t row, const dim_t col) const { return row * cols_ + col; }

        dim_t rows_ = 0;
        dim_t cols_ = 0;
        cumeric_t* data_ = nullptr;
    };

} // namespace cum
