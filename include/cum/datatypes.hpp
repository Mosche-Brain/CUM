/**
 * @file datatypes.hpp
 * @brief Datatype definitions, precision aliases, and type tagging utilities for CUM.
 * @author Świadomy Mężczyzna
 * @details Provides fixed-width floating point and integer aliases, emulation types (FP8/FP16/BF16),
 *          the runtime datatype tag enumeration, default numeric types, and type-to-tag traits.
 */

#pragma once

#include "cum/config.hpp"

#if __has_include(<stdfloat>)
#include <stdfloat>
#endif
#include <cstdint>
#include <type_traits>

#if defined(SYCL_LANGUAGE_VERSION)
#include <sycl/sycl.hpp>
#include <sycl/ext/oneapi/bfloat16.hpp>
#endif

#if !CUM_USE_FP64 && \
!CUM_USE_FP32 && \
!CUM_USE_FP16 && \
!CUM_USE_BF16 && \
!CUM_USE_INT8
    #error "No CUM numeric type was configured"
#endif

/**
 * @struct fp8_e4_3m_impl
 * @brief 8-bit floating point emulation structure (E4M3 format representation).
 */
typedef struct fp8_e4_3m_impl
{
    unsigned char data; ///< Raw 8-bit byte representation.

    /**
     * @brief Constructs an FP8 value from float.
     * @param val Single-precision float value to convert.
     */
    fp8_e4_3m_impl(float val) : data( (unsigned char) (val * 255)) {}

    /**
     * @brief Conversion operator to float (const).
     * @return Converted single-precision floating point value.
     */
    operator float() const { return (float) data; }

    /**
     * @brief Non-const conversion operator to float.
     * @return Converted single-precision floating point value.
     */
    operator float()
    {
        return 69;
    }
} fp8_e4_3m_impl;

namespace cum
{
    /** @brief 64-bit double precision float alias. */
    using float64 = double;
    /** @brief 32-bit single precision float alias. */
    using float32 = float;

#if defined(__STDCPP_FLOAT16_T__) && defined(__STDCPP_BFLOAT16_T__)
    /** @brief 16-bit half precision float alias (IEEE 754-2008). */
    using float16 = std::float16_t;
    /** @brief Brain floating-point 16-bit alias (bfloat16). */
    using bfloat16 = std::bfloat16_t;
#else
    /** @brief Raw 16-bit fallback for half precision float. */
    typedef struct { unsigned short raw; } float16;
    /** @brief Raw 16-bit fallback for bfloat16 precision float. */
    typedef struct { unsigned short raw; } bfloat16;
#endif

    /** @brief 8-bit floating point alias. */
    using float8 = fp8_e4_3m_impl;

    /** @brief Signed 64-bit integer alias. */
    using int64 = signed long long;
    /** @brief Signed 32-bit integer alias. */
    using int32 = signed int;
    /** @brief Signed 16-bit integer alias. */
    using int16 = signed short;
    /** @brief Signed 8-bit integer alias. */
    using int8  = signed char;
    
    /** @brief Unsigned 64-bit integer alias. */
    using uint64 = unsigned long long;
    /** @brief Unsigned 32-bit integer alias. */
    using uint32 = unsigned int;
    /** @brief Unsigned 16-bit integer alias. */
    using uint16 = unsigned short;
    /** @brief Unsigned 8-bit integer alias. */
    using uint8  = unsigned char;

    using f64   = float64;   ///< Short alias for float64.
    using f32   = float32;   ///< Short alias for float32.
    using f16   = float16;   ///< Short alias for float16.
    using bf16  = bfloat16;  ///< Short alias for bfloat16.
    using f8    = float8;    ///< Short alias for float8.

    using i64   = int64;     ///< Short alias for int64.
    using i32   = int32;     ///< Short alias for int32.
    using i16   = int16;     ///< Short alias for int16.
    using i8    = int8;      ///< Short alias for int8.

    using u64   = uint64;    ///< Short alias for uint64.
    using u32   = uint32;    ///< Short alias for uint32.
    using u16   = uint16;    ///< Short alias for uint16.
    using u8    = uint8;     ///< Short alias for uint8.

    using byte = uint8;      ///< 8-bit byte alias.

    /**
     * @enum datatype
     * @brief Runtime enumeration tags for supported numeric types.
     */
    enum class datatype : uint8_t 
    {
        /* Floating point */ 
        FP64, ///< 64-bit IEEE double precision float.
        FP32, ///< 32-bit IEEE single precision float.
        FP16, ///< 16-bit IEEE half precision float.
        BF16, ///< 16-bit Brain floating point format.
        FP8,  ///< 8-bit floating point format.
        
        /* Signed integers */
        S64,  ///< Signed 64-bit integer.
        S32,  ///< Signed 32-bit integer.
        S16,  ///< Signed 16-bit integer.
        S8,   ///< Signed 8-bit integer.
        
        /* Unsigned integers */
        U64,  ///< Unsigned 64-bit integer.
        U32,  ///< Unsigned 32-bit integer.
        U16,  ///< Unsigned 16-bit integer.
        U8,   ///< Unsigned 8-bit integer.
        
        UNDEF ///< Undefined / uninitialized datatype.
    };

#if CUM_USE_FP64
    /** @brief Primary active scalar type for numerical computations. */
    using cumeric_t = double;
    /** @brief Accumulator type for reduction operations. */
    using cummulative_t = double;
    /** @brief Default datatype tag. */
    constexpr datatype default_type = datatype::FP64;
#elif CUM_USE_FP32
    /** @brief Primary active scalar type for numerical computations. */
    using cumeric_t = float;
    /** @brief Tolerance epsilon for floating point equality and comparisons. */
    constexpr cumeric_t EPSILON = 1e-9f;
    /** @brief Accumulator type for reduction operations. */
    using cummulative_t = double;
    /** @brief Default datatype tag. */
    constexpr datatype default_type = datatype::FP32;
#elif CUM_USE_FP16
    /** @brief Primary active scalar type for numerical computations. */
    using cumeric_t = cum::float16;
    /** @brief Tolerance epsilon for floating point equality and comparisons. */
    constexpr cumeric_t EPSILON = 1e-4f16;
    /** @brief Accumulator type for reduction operations. */
    using cummulative_t = float;
    /** @brief Default datatype tag. */
    constexpr datatype default_type = datatype::FP16;
#elif CUM_USE_BF16
    /** @brief Primary active scalar type for numerical computations. */
    using cumeric_t = cum::bfloat16;
    /** @brief Tolerance epsilon for floating point equality and comparisons. */
    constexpr cumeric_t EPSILON = 1e-3bf16;
    /** @brief Accumulator type for reduction operations. */
    using cummulative_t = float;
    /** @brief Default datatype tag. */
    constexpr datatype default_type = datatype::BF16;
#elif CUM_USE_INT8
    /** @brief Primary active scalar type for numerical computations. */
    using cumeric_t = int8_t;
    /** @brief Tolerance epsilon for equality and comparisons. */
    constexpr cumeric_t EPSILON = 1e1;
    /** @brief Accumulator type for reduction operations. */
    using cummulative_t = float;
    /** @brief Default datatype tag. */
    constexpr datatype default_type = datatype::S8;
#endif

    /**
     * @brief Computes the byte size of a specified runtime datatype tag.
     * @param type The runtime datatype tag.
     * @return Size in bytes of one element of the datatype.
     */
    constexpr std::size_t datatype_size(datatype type)
    {
        switch (type)
        {
        case datatype::FP64: return 8;
        case datatype::FP32: return 4;
        case datatype::FP16: return 2;
        case datatype::BF16: return 2;
        case datatype::FP8:  return 1;

        case datatype::S64:  return 8;
        case datatype::S32:  return 4;
        case datatype::S16:  return 2;
        case datatype::S8:   return 1;

        case datatype::U64:  return 8;
        case datatype::U32:  return 4;
        case datatype::U16:  return 2;
        case datatype::U8:   return 1;

        case datatype::UNDEF:
        default:
            return 1;
        }
    }

    /**
     * @brief Resolves the runtime datatype tag corresponding to compile-time type @p T.
     * @tparam T The static C++ type.
     * @return The corresponding @ref datatype enum value.
     */
    template <typename T>
    constexpr datatype type_tag() noexcept
    {
        using U = std::remove_cvref_t<T>;

        if constexpr (std::is_same_v<U, float64>)
            return datatype::FP64;
        else if constexpr (std::is_same_v<U, float32>)
            return datatype::FP32;
        else if constexpr (std::is_same_v<U, float16>
#if defined(SYCL_LANGUAGE_VERSION)
            || std::is_same_v<U, sycl::half>
#endif
        )
            return datatype::FP16;
        else if constexpr (std::is_same_v<U, bfloat16>
#if defined(SYCL_LANGUAGE_VERSION)
            || std::is_same_v<U, sycl::ext::oneapi::bfloat16>
#endif
        )
            return datatype::BF16;
        else if constexpr (std::is_same_v<U, float8>)
            return datatype::FP8;
        else if constexpr (std::is_integral_v<U> && !std::is_same_v<U, bool>)
        {
            if constexpr (std::is_signed_v<U>)
            {
                if constexpr (sizeof(U) == 8) return datatype::S64;
                else if constexpr (sizeof(U) == 4) return datatype::S32;
                else if constexpr (sizeof(U) == 2) return datatype::S16;
                else if constexpr (sizeof(U) == 1) return datatype::S8;
            }
            else
            {
                if constexpr (sizeof(U) == 8) return datatype::U64;
                else if constexpr (sizeof(U) == 4) return datatype::U32;
                else if constexpr (sizeof(U) == 2) return datatype::U16;
                else if constexpr (sizeof(U) == 1) return datatype::U8;
            }
            return datatype::UNDEF;
        }
        else
            return datatype::UNDEF;
    }

} // namespace cum
