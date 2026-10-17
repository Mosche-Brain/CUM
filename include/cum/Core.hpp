#pragma once

#include "cum/config.hpp"
#include "cum/datatypes.hpp"
#include <cstdint>
#include <stdfloat>
#include <utility>
#include <vector>


#include "cum/experimental/__event__.hpp"
#include "cum/layout.hpp"
#include "cum/datatypes.hpp"


namespace cum
{
    enum class DEVICE { AUTO, CPU, GPU };

    using __event__ = experimental::__event__;
    using __events__ = std::vector<std::reference_wrapper<__event__>>;

    using dim_t = std::int64_t;
    using Shape = std::vector<dim_t>;
    using Dims = std::vector<dim_t>;


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

inline cum::cumeric_t operator"" _c(long double val) 
{
    return static_cast<cum::cumeric_t>(val);
}

inline cum::cumeric_t operator"" _c(unsigned long long val) 
{
    return static_cast<cum::cumeric_t>(val);
}