//
// Created by jaro on 7/19/26.
//
#include "cum/Core.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/memory.hpp"
#include "cum/functions/hyperbolic.hpp"
#include "cum/functions/linear_units.hpp"

#include <oneapi/mkl/vm/usm.hpp>

const cum::cumeric_t M_SQRT_2_OVER_PI = 0.79788456;
const cum::cumeric_t M_SQRT_2_OVER_PI_A = 0.044715;

namespace cum::functions::linear_units
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t identity(cumeric_t x)
    {
        return x;
    }

    cumeric_t relu(cumeric_t x)
    {
        return sycl::fmax(static_cast<cumeric_t>(x), static_cast<cumeric_t>(0));
    }

    cumeric_t leaky_relu(cumeric_t x)
    {
        return x > static_cast<cumeric_t>(0) ? x : leaky_relu_alpha * x;
    }

    cumeric_t gelu(cumeric_t x)
    {
        return static_cast<cumeric_t>(0.5) * x * (static_cast<cumeric_t>(1.0) + sycl::tanh(M_SQRT_2_OVER_PI * (x + M_SQRT_2_OVER_PI_A * x * x * x)));
    }

    cumeric_t elu(cumeric_t x)
    {
        return 0; // placeholder
    }

    /* Parallel versions */

    __event__ identity(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            return x;
        });
    }

    __event__ identity(datatype dtype, void* v, dim_t N)
    {
        return identity(dtype, v, v, N);
    }

    __event__ identity_in_place(datatype dtype, void* v, dim_t N)
    {
        return identity(dtype, v, v, N);
    }

    __event__ identity(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return identity(default_type, r, v, N);
    }

    __event__ identity_in_place(cumeric_t* v, dim_t N)
    {
        return identity(default_type, v, v, N);
    }

    __event__ relu(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return x > T(0) ? x : T(0);
        });
    }

    __event__ relu(datatype dtype, void* v, dim_t N)
    {
        return relu(dtype, v, v, N);
    }

    __event__ relu_in_place(datatype dtype, void* v, dim_t N)
    {
        return relu(dtype, v, v, N);
    }

    __event__ relu(cumeric_t* r, const cumeric_t* v, const dim_t N)
    {
        return relu(default_type, r, v, N);
    }

    __event__ relu_in_place(cumeric_t* v, dim_t N)
    {
        return relu(default_type, v, v, N);
    }

    __event__ leaky_relu(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return x > T(0) ? x : T(0.01) * x;
        });
    }

    __event__ leaky_relu(datatype dtype, void* v, dim_t N)
    {
        return leaky_relu(dtype, v, v, N);
    }

    __event__ leaky_relu_in_place(datatype dtype, void* v, dim_t N)
    {
        return leaky_relu(dtype, v, v, N);
    }

    __event__ leaky_relu(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return leaky_relu(default_type, r, v, N);
    }

    __event__ leaky_relu_in_place(cumeric_t* v, dim_t N)
    {
        return leaky_relu(default_type, v, v, N);
    }

    __event__ gelu(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            constexpr T sqrt_2_over_pi = T(0.79788456);
            constexpr T a = T(0.044715);
            return T(0.5) * x * (T(1.0) + sycl::tanh(sqrt_2_over_pi * (x + a * x * x * x)));
        });
    }

    __event__ gelu(datatype dtype, void* v, dim_t N)
    {
        return gelu(dtype, v, v, N);
    }

    __event__ gelu_in_place(datatype dtype, void* v, dim_t N)
    {
        return gelu(dtype, v, v, N);
    }

    __event__ gelu(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return gelu(default_type, r, v, N);
    }

    __event__ gelu_in_place(cumeric_t* v, dim_t N)
    {
        return gelu(default_type, v, v, N);
    }

    __event__ elu(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return T(0);
        });
    }

    __event__ elu(datatype dtype, void* v, dim_t N)
    {
        return elu(dtype, v, v, N);
    }

    __event__ elu_in_place(datatype dtype, void* v, dim_t N)
    {
        return elu(dtype, v, v, N);
    }

    __event__ elu(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return elu(default_type, r, v, N);
    }

    __event__ elu_in_place(cumeric_t* v, dim_t N)
    {
        return elu(default_type, v, v, N);
    }

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t identity_deriv(cumeric_t x)
    {
        return 1;
    }

    cumeric_t relu_deriv(cumeric_t x)
    {
        return x > static_cast<cumeric_t>(0) ? 1 : 0;
    }

    cumeric_t leaky_relu_deriv(cumeric_t x)
    {
        return x > static_cast<cumeric_t>(0) ? static_cast<cumeric_t>(1) : leaky_relu_alpha;
    }

    cumeric_t gelu_deriv(cumeric_t x)
    {
        cumeric_t tanh_arg = M_SQRT_2_OVER_PI * (x + M_SQRT_2_OVER_PI_A * x * x * x);
        cumeric_t tanh_val = sycl::tanh(tanh_arg);
        cumeric_t sech_squared = 1 - tanh_val * tanh_val;
        return static_cast<cumeric_t>(0.5) * (static_cast<cumeric_t>(1.0) + tanh_val) + (M_SQRT_2_OVER_PI * (x + 3 * M_SQRT_2_OVER_PI_A * x * x) * sech_squared) / static_cast<cumeric_t>(6.0);
    }

    cumeric_t elu_deriv(cumeric_t x)
    {
        return 0; // placeholder
    }

    /* Parallel versions */

    __event__ identity_deriv(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return T(1);
        });
    }

    __event__ identity_deriv(datatype dtype, void* v, dim_t N)
    {
        return identity_deriv(dtype, v, v, N);
    }

    __event__ identity_deriv_in_place(datatype dtype, void* v, dim_t N)
    {
        return identity_deriv(dtype, v, v, N);
    }

    __event__ identity_deriv(cumeric_t* r, const cumeric_t* v, const dim_t N)
    {
        return identity_deriv(default_type, r, v, N);
    }

    __event__ identity_deriv_in_place(cumeric_t* v, dim_t N)
    {
        return identity_deriv(default_type, v, v, N);
    }

    __event__ relu_deriv(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return x > T(0) ? T(1) : T(0);
        });
    }

    __event__ relu_deriv(datatype dtype, void* v, dim_t N)
    {
        return relu_deriv(dtype, v, v, N);
    }

    __event__ relu_deriv_in_place(datatype dtype, void* v, dim_t N)
    {
        return relu_deriv(dtype, v, v, N);
    }

    __event__ relu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return relu_deriv(default_type, r, v, N);
    }

    __event__ relu_deriv_in_place(cumeric_t* v, dim_t N)
    {
        return relu_deriv(default_type, v, v, N);
    }

    __event__ leaky_relu_deriv(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return x > T(0) ? T(1) : T(0.01);
        });
    }

    __event__ leaky_relu_deriv(datatype dtype, void* v, dim_t N)
    {
        return leaky_relu_deriv(dtype, v, v, N);
    }

    __event__ leaky_relu_deriv_in_place(datatype dtype, void* v, dim_t N)
    {
        return leaky_relu_deriv(dtype, v, v, N);
    }

    __event__ leaky_relu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return leaky_relu_deriv(default_type, r, v, N);
    }

    __event__ leaky_relu_deriv_in_place(cumeric_t* v, dim_t N)
    {
        return leaky_relu_deriv(default_type, v, v, N);
    }

    __event__ gelu_deriv(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            constexpr T sqrt_2_over_pi = T(0.79788456);
            constexpr T a = T(0.044715);
            T tanh_arg = sqrt_2_over_pi * (x + a * x * x * x);
            T tanh_val = sycl::tanh(tanh_arg);
            T sech_squared = T(1) - tanh_val * tanh_val;
            return T(0.5) * (T(1.0) + tanh_val) + (sqrt_2_over_pi * (x + T(3) * a * x * x) * sech_squared) / T(6.0);
        });
    }

    __event__ gelu_deriv(datatype dtype, void* v, dim_t N)
    {
        return gelu_deriv(dtype, v, v, N);
    }

    __event__ gelu_deriv_in_place(datatype dtype, void* v, dim_t N)
    {
        return gelu_deriv(dtype, v, v, N);
    }

    __event__ gelu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return gelu_deriv(default_type, r, v, N);
    }

    __event__ gelu_deriv_in_place(cumeric_t* v, dim_t N)
    {
        return gelu_deriv(default_type, v, v, N);
    }

    __event__ elu_deriv(datatype dtype, void* r, const void* v, dim_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, static_cast<std::size_t>(N), [](auto x) {
            using T = decltype(x);
            return T(0);
        });
    }

    __event__ elu_deriv(datatype dtype, void* v, dim_t N)
    {
        return elu_deriv(dtype, v, v, N);
    }

    __event__ elu_deriv_in_place(datatype dtype, void* v, dim_t N)
    {
        return elu_deriv(dtype, v, v, N);
    }

    __event__ elu_deriv(cumeric_t* r, const cumeric_t* v, dim_t N)
    {
        return elu_deriv(default_type, r, v, N);
    }

    __event__ elu_deriv_in_place(cumeric_t* v, dim_t N)
    {
        return elu_deriv(default_type, v, v, N);
    }
}

