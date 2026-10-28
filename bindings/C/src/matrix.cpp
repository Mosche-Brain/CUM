#include "cum/cum.h"
#include "cum/Matrix.hpp"
#include "cum/runtime.hpp"
#include "cum/detail/opaques_impl.hpp"
#include "cum/detail/error.hpp"

using cum_c::guard;
using cum_c::invalid_argument;

namespace
{
    constexpr const char* null_matrix = "null matrix argument";

    bool valid_dims(dim_t rows, dim_t cols)
    {
        return rows > 0 && cols > 0;
    }

    /* Some cum::Matrix operations are submitted asynchronously; wait before returning to C. */
    template<typename Function>
    cum_status_t synced(Function&& function)
    {
        return guard([&] { function(); cum::runtime::sync(); });
    }

    /* cum::Matrix::cwiseProduct races with the host (missing synchronization), so the
     * element-wise product is computed on the host over the shared USM buffers. */
    cum::Matrix eltwise_product(const cum::Matrix& lhs, const cum::Matrix& rhs)
    {
        if(lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
            throw std::invalid_argument("matrix dimension mismatch");
        cum::runtime::sync();
        cum::Matrix result(lhs.rows(), lhs.cols());
        for(dim_t index = 0; index < lhs.size(); ++index)
            result.data()[index] = lhs.data()[index] * rhs.data()[index];
        return result;
    }

    cum_status_t emplace(cum_matrix_t** out, cum::Matrix&& matrix)
    {
        *out = new cum_matrix_t { std::move(matrix) };
        return CUM_STATUS_SUCCESS;
    }
}

extern "C"
{
    cum_status_t cum_matrix_create(cum_matrix_t** matrix, dim_t rows, dim_t cols)
    {
        if(matrix == nullptr || !valid_dims(rows, cols))
            return invalid_argument("invalid output pointer or dimensions");
        return guard([&] { emplace(matrix, cum::Matrix::Zeros(rows, cols)); });
    }

    cum_status_t cum_matrix_create_filled(cum_matrix_t** matrix, dim_t rows, dim_t cols, cumeric_t value)
    {
        if(matrix == nullptr || !valid_dims(rows, cols))
            return invalid_argument("invalid output pointer or dimensions");
        return guard([&] { emplace(matrix, cum::Matrix(rows, cols, value)); });
    }

    cum_status_t cum_matrix_create_zeros(cum_matrix_t** matrix, dim_t rows, dim_t cols)
    {
        return cum_matrix_create(matrix, rows, cols);
    }

    cum_status_t cum_matrix_create_ones(cum_matrix_t** matrix, dim_t rows, dim_t cols)
    {
        return cum_matrix_create_filled(matrix, rows, cols, 1.0f);
    }

    cum_status_t cum_matrix_create_random(
        cum_matrix_t** matrix, dim_t rows, dim_t cols, cumeric_t min, cumeric_t max)
    {
        if(matrix == nullptr || !valid_dims(rows, cols))
            return invalid_argument("invalid output pointer or dimensions");
        return guard([&] { emplace(matrix, cum::Matrix::Random(rows, cols, min, max)); });
    }

    cum_status_t cum_matrix_create_from_data(
        cum_matrix_t** matrix, dim_t rows, dim_t cols, const cumeric_t* data)
    {
        if(matrix == nullptr || data == nullptr || !valid_dims(rows, cols))
            return invalid_argument("invalid output pointer, data or dimensions");
        return guard([&] { emplace(matrix, cum::Matrix(rows, cols, data)); });
    }

    cum_status_t cum_matrix_destroy(cum_matrix_t* matrix)
    {
        delete matrix;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_copy(cum_matrix_t* dst, const cum_matrix_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_matrix);
        return guard([&] { dst->matrix.set(src->matrix); });
    }

    cum_status_t cum_matrix_clone(cum_matrix_t** dst, const cum_matrix_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_matrix);
        return guard([&] { emplace(dst, cum::Matrix(src->matrix)); });
    }

    cum_status_t cum_matrix_rows(const cum_matrix_t* matrix, dim_t* rows)
    {
        if(matrix == nullptr || rows == nullptr)
            return invalid_argument();
        *rows = matrix->matrix.rows();
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_cols(const cum_matrix_t* matrix, dim_t* cols)
    {
        if(matrix == nullptr || cols == nullptr)
            return invalid_argument();
        *cols = matrix->matrix.cols();
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_size(const cum_matrix_t* matrix, dim_t* size)
    {
        if(matrix == nullptr || size == nullptr)
            return invalid_argument();
        *size = matrix->matrix.size();
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_data(const cum_matrix_t* matrix, const cumeric_t** data)
    {
        if(matrix == nullptr || data == nullptr)
            return invalid_argument();
        *data = matrix->matrix.data();
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_mutable_data(cum_matrix_t* matrix, cumeric_t** data)
    {
        if(matrix == nullptr || data == nullptr)
            return invalid_argument();
        *data = matrix->matrix.data();
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_fill(cum_matrix_t* matrix, cumeric_t value)
    {
        if(matrix == nullptr)
            return invalid_argument(null_matrix);
        return synced([&] { matrix->matrix.fill(value); });
    }

    cum_status_t cum_matrix_get(const cum_matrix_t* matrix, dim_t row, dim_t col, cumeric_t* value)
    {
        if(matrix == nullptr || value == nullptr)
            return invalid_argument();
        if(row < 0 || col < 0 || row >= matrix->matrix.rows() || col >= matrix->matrix.cols())
            return invalid_argument("index out of range");
        *value = matrix->matrix.at(row, col);
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_set(cum_matrix_t* matrix, dim_t row, dim_t col, cumeric_t value)
    {
        if(matrix == nullptr)
            return invalid_argument(null_matrix);
        if(row < 0 || col < 0 || row >= matrix->matrix.rows() || col >= matrix->matrix.cols())
            return invalid_argument("index out of range");
        matrix->matrix.at(row, col) = value;
        return CUM_STATUS_SUCCESS;
    }

    cum_status_t cum_matrix_transpose(cum_matrix_t* dst, const cum_matrix_t* src)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_matrix);
        return synced([&] { dst->matrix = src->matrix.transpose(); });
    }

    cum_status_t cum_matrix_reshape(cum_matrix_t* dst, const cum_matrix_t* src, dim_t rows, dim_t cols)
    {
        if(dst == nullptr || src == nullptr)
            return invalid_argument(null_matrix);
        return synced([&] { dst->matrix = src->matrix.reshape(rows, cols); });
    }

    #define CUM_MATRIX_BINARY(name, expression) \
    cum_status_t name(cum_matrix_t* dst, const cum_matrix_t* lhs, const cum_matrix_t* rhs) \
    { \
        if(dst == nullptr || lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_matrix); \
        return synced([&] { dst->matrix = (expression); }); \
    }

    CUM_MATRIX_BINARY(cum_matrix_add, lhs->matrix + rhs->matrix)
    CUM_MATRIX_BINARY(cum_matrix_sub, lhs->matrix - rhs->matrix)
    CUM_MATRIX_BINARY(cum_matrix_mul, lhs->matrix * rhs->matrix)
    CUM_MATRIX_BINARY(cum_matrix_eltwise_mul, eltwise_product(lhs->matrix, rhs->matrix))
    CUM_MATRIX_BINARY(cum_matrix_div, lhs->matrix / rhs->matrix)

    #undef CUM_MATRIX_BINARY

    /* In-place variants are computed out of place and swapped in; this also supports
     * results whose shape differs from the left operand (matrix product). */
    #define CUM_MATRIX_IN_PLACE(name, expression) \
    cum_status_t name(cum_matrix_t* lhs, const cum_matrix_t* rhs) \
    { \
        if(lhs == nullptr || rhs == nullptr) \
            return invalid_argument(null_matrix); \
        return synced([&] { lhs->matrix = (expression); }); \
    }

    CUM_MATRIX_IN_PLACE(cum_matrix_add_in_place, lhs->matrix + rhs->matrix)
    CUM_MATRIX_IN_PLACE(cum_matrix_sub_in_place, lhs->matrix - rhs->matrix)
    CUM_MATRIX_IN_PLACE(cum_matrix_mul_in_place, lhs->matrix * rhs->matrix)
    CUM_MATRIX_IN_PLACE(cum_matrix_eltwise_mul_in_place, eltwise_product(lhs->matrix, rhs->matrix))
    CUM_MATRIX_IN_PLACE(cum_matrix_div_in_place, lhs->matrix / rhs->matrix)

    #undef CUM_MATRIX_IN_PLACE

    #define CUM_MATRIX_SCALAR(name, expression) \
    cum_status_t name(cum_matrix_t* dst, const cum_matrix_t* src, cumeric_t scalar) \
    { \
        if(dst == nullptr || src == nullptr) \
            return invalid_argument(null_matrix); \
        return synced([&] { dst->matrix = (expression); }); \
    }

    CUM_MATRIX_SCALAR(cum_matrix_add_scalar, src->matrix + scalar)
    CUM_MATRIX_SCALAR(cum_matrix_mul_scalar, src->matrix * scalar)
    CUM_MATRIX_SCALAR(cum_matrix_div_scalar, src->matrix / scalar)

    #undef CUM_MATRIX_SCALAR
}
