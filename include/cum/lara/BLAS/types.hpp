/**
 * @file types.hpp
 * @brief Common BLAS enumerations and operation flags.
 * @details Defines compute modes, transposition, triangular matrix storage, diagonal unit flags,
 *          and side positioning for BLAS routines.
 * @note Derived from oneAPI oneMKL BLAS type definitions.
 */

#ifndef YANN_TYPES_HPP
#define YANN_TYPES_HPP

#include <cstdint>

namespace cum::blas
{
    /**
     * @enum compute_mode
     * @brief Compute precision and acceleration mode flags for BLAS execution.
     */
    enum class compute_mode : std::uint64_t
    {
        unset            = 0x0,
        float_to_bf16    = 0x1,
        float_to_bf16x2  = 0x2,
        float_to_bf16x3  = 0x4,
        float_to_tf32    = 0x10,
        complex_3m       = 0x10000,
        any              = 0xFFFFFFFF,
        standard         = 0x20000000'00000000,
        prefer_alternate = 0x40000000'00000000,
        force_alternate  = 0x80000000'00000000,
    };

    /**
     * @enum transpose
     * @brief Matrix transposition options for BLAS routines.
     */
    enum class transpose : char
    {
        nontrans  = 0, ///< Do not transpose: op(A) = A.
        trans     = 1, ///< Transpose: op(A) = A^T.
        conjtrans = 3, ///< Conjugate transpose: op(A) = A^H.
        N         = 0, ///< Alias for nontrans.
        T         = 1, ///< Alias for trans.
        C         = 3  ///< Alias for conjtrans.
    };

    /**
     * @enum uplo
     * @brief Specifies whether matrix upper or lower triangular part is stored.
     */
    enum class uplo : char
    {
        upper = 0, ///< Upper triangle stored.
        lower = 1, ///< Lower triangle stored.
        U     = 0, ///< Alias for upper.
        L     = 1  ///< Alias for lower.
    };

    /**
     * @enum diag
     * @brief Specifies whether matrix diagonal is unit.
     */
    enum class diag : char
    {
        nonunit = 0, ///< Matrix diagonal elements are not assumed to be 1.
        unit    = 1, ///< Matrix is assumed to have unit diagonal (elements are 1).
        N       = 0, ///< Alias for nonunit.
        U       = 1  ///< Alias for unit.
    };

    /**
     * @enum side
     * @brief Specifies multiplication side (left or right).
     */
    enum class side : char
    {
        left  = 0, ///< Matrix op on left: op(A) * B.
        right = 1, ///< Matrix op on right: B * op(A).
        L     = 0, ///< Alias for left.
        R     = 1  ///< Alias for right.
    };

    /**
     * @enum offset
     * @brief Storage offset mode for matrices.
     */
    enum class offset : char
    {
        row    = 0,
        column = 1,
        fix    = 2,
        R      = 0,
        C      = 1,
        F      = 2
    };

    /**
     * @enum index_base
     * @brief 0-based or 1-based indexing convention.
     */
    enum class index_base : char
    {
        zero = 0, ///< 0-based indexing (C/C++ convention).
        one  = 1, ///< 1-based indexing (Fortran convention).
    };
} // namespace cum::blas

#endif //YANN_TYPES_HPP
