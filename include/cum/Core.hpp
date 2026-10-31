/**
 * @file Core.hpp
 * @brief Core types, dimension definitions, and datatype dispatching utilities for CUM.
 * @details Defines target device enumerations, event alias types, shape representations,
 *          and compile-time / runtime datatype dispatchers.
 */

#pragma once

#include "cum/config.hpp"
#include "cum/datatypes.hpp"
#include <cstdint>
#if __has_include(<stdfloat>)
#include <stdfloat>
#endif
#include <utility>
#include <vector>

#include "cum/experimental/__event__.hpp"
#include "cum/layout.hpp"
#include "cum/datatypes.hpp"

namespace cum
{
    /**
     * @enum DEVICE
     * @brief Target compute hardware accelerator or processing unit.
     */
    enum class DEVICE
    {
        AUTO, ///< Automatically select the best available device (GPU preferred, CPU fallback).
        CPU,  ///< Host CPU execution.
        GPU   ///< GPU accelerator execution.
    };

    /**
     * @brief Asynchronous execution event handle alias.
     */
    using __event__ = experimental::__event__;

    /**
     * @brief Collection of references to dependent asynchronous events.
     */
    using __events__ = std::vector<std::reference_wrapper<__event__>>;

    /**
     * @brief Fundamental signed integer type for dimensions, sizes, and indexing.
     */
    using dim_t = std::int64_t;

    /**
     * @brief Shape vector representing multi-dimensional tensor dimensions.
     */
    using Shape = std::vector<dim_t>;

    /**
     * @brief Dimension vector alias for Shape.
     */
    using Dims = std::vector<dim_t>;

    /**
     * @brief Invokes a generic functor instantiated with type @p T, or triggers undefined behavior path.
     * @tparam T The type parameter to instantiate the functor with.
     * @tparam F Functor type.
     * @param f The generic callable to invoke.
     * @return Result of invoking `f.template operator()<T>()`.
     */
    template <typename T, typename F>
    decltype(auto) invoke_or_ub(F&& f)
    {
        if constexpr (requires { std::forward<F>(f).template operator()<T>(); }) {
            return std::forward<F>(f).template operator()<T>();
        } else {
            std::unreachable();
            if constexpr (requires { std::forward<F>(f).template operator()<cumeric_t>(); }) {
                return std::forward<F>(f).template operator()<cumeric_t>();
            }
        }
    }

    /**
     * @brief Runtime-to-compile-time datatype dispatcher.
     * @details Calls the provided generic lambda/functor `f` with the template argument corresponding
     *          to the runtime @p dt enum value.
     * @tparam F Functor type accepting a template type parameter `<T>()`.
     * @param dt The runtime datatype tag.
     * @param f The generic callable invoked with the matching static C++ type.
     * @return Result of the dispatched call.
     */
    template <typename F>
    decltype(auto) dispatch_datatype(datatype dt, F&& f)
    {
        (void)&invoke_or_ub<double, F>;
        (void)&invoke_or_ub<float, F>;
        (void)&invoke_or_ub<float16, F>;
        (void)&invoke_or_ub<bfloat16, F>;
        (void)&invoke_or_ub<float8, F>;
        (void)&invoke_or_ub<std::int64_t, F>;
        (void)&invoke_or_ub<std::int32_t, F>;
        (void)&invoke_or_ub<std::int16_t, F>;
        (void)&invoke_or_ub<std::int8_t, F>;
        (void)&invoke_or_ub<std::uint64_t, F>;
        (void)&invoke_or_ub<std::uint32_t, F>;
        (void)&invoke_or_ub<std::uint16_t, F>;
        (void)&invoke_or_ub<std::uint8_t, F>;
        (void)&invoke_or_ub<cumeric_t, F>;

        switch (dt)
        {
            case datatype::FP64: return invoke_or_ub<double>(std::forward<F>(f));
            case datatype::FP32: return invoke_or_ub<float>(std::forward<F>(f));
            case datatype::FP16: return invoke_or_ub<float16>(std::forward<F>(f));
            case datatype::BF16: return invoke_or_ub<bfloat16>(std::forward<F>(f));
            case datatype::FP8:  return invoke_or_ub<float8>(std::forward<F>(f));
            case datatype::S64:  return invoke_or_ub<std::int64_t>(std::forward<F>(f));
            case datatype::S32:  return invoke_or_ub<std::int32_t>(std::forward<F>(f));
            case datatype::S16:  return invoke_or_ub<std::int16_t>(std::forward<F>(f));
            case datatype::S8:   return invoke_or_ub<std::int8_t>(std::forward<F>(f));
            case datatype::U64:  return invoke_or_ub<std::uint64_t>(std::forward<F>(f));
            case datatype::U32:  return invoke_or_ub<std::uint32_t>(std::forward<F>(f));
            case datatype::U16:  return invoke_or_ub<std::uint16_t>(std::forward<F>(f));
            case datatype::U8:   return invoke_or_ub<std::uint8_t>(std::forward<F>(f));
            default:             return invoke_or_ub<cumeric_t>(std::forward<F>(f));
        }
    }
} // namespace cum

/**
 * @brief User-defined literal for floating point values converting to default @c cumeric_t.
 * @param val Floating point literal value.
 * @return Value cast to @c cum::cumeric_t.
 */
inline cum::cumeric_t operator""_c(long double val) 
{
    return static_cast<cum::cumeric_t>(val);
}

/**
 * @brief User-defined literal for integer values converting to default @c cumeric_t.
 * @param val Integer literal value.
 * @return Value cast to @c cum::cumeric_t.
 */
inline cum::cumeric_t operator""_c(unsigned long long val) 
{
    return static_cast<cum::cumeric_t>(val);
}
