//
// Created by jaro on 7/19/26.
//

#include "cum/Core.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/functions/hyperbolic.hpp"

#include <oneapi/mkl/vm.hpp>
#include <sycl/sycl.hpp>
#include <utility>

namespace cum::functions::hyperbolic
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t tanh(cumeric_t x)
    {
        return sycl::tanh(x);
    }

    cumeric_t sinh(cumeric_t x)
    {
        return sycl::sinh(x);
    }

    cumeric_t cosh(cumeric_t x)
    {
        return sycl::cosh(x);
    }

    /* Parallel versions */

    __event__ tanh(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::tanh(q, len, vp, rp)) {
                return oneapi::mkl::vm::tanh(q, len, vp, rp);
            },
            [](auto x) { return sycl::tanh(x); }
        );
    }

    __event__ tanh(datatype dtype, void* v, const std::size_t N)
    {
        return tanh(dtype, v, v, N);
    }

    __event__ tanh_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return tanh(dtype, v, v, N);
    }

    __event__ tanh(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return tanh(default_type, r, v, N);
    }

    __event__ tanh_in_place(cumeric_t* v, const std::size_t N)
    {
        return tanh(default_type, v, v, N);
    }

    __event__ sinh(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::sinh(q, len, vp, rp)) {
                return oneapi::mkl::vm::sinh(q, len, vp, rp);
            },
            [](auto x) { return sycl::sinh(x); }
        );
    }

    __event__ sinh(datatype dtype, void* v, const std::size_t N)
    {
        return sinh(dtype, v, v, N);
    }

    __event__ sinh_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sinh(dtype, v, v, N);
    }

    __event__ sinh(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sinh(default_type, r, v, N);
    }

    __event__ sinh_in_place(cumeric_t* v, const std::size_t N)
    {
        return sinh(default_type, v, v, N);
    }

    __event__ cosh(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::cosh(q, len, vp, rp)) {
                return oneapi::mkl::vm::cosh(q, len, vp, rp);
            },
            [](auto x) { return sycl::cosh(x); }
        );
    }

    __event__ cosh(datatype dtype, void* v, const std::size_t N)
    {
        return cosh(dtype, v, v, N);
    }

    __event__ cosh_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return cosh(dtype, v, v, N);
    }

    __event__ cosh(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return cosh(default_type, r, v, N);
    }

    __event__ cosh_in_place(cumeric_t* v, const std::size_t N)
    {
        return cosh(default_type, v, v, N);
    }

    /* ========================== It's Derivatives ========================== */

    /* Scalar versions */

    cumeric_t tanh_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) - hyperbolic::tanh(x) * hyperbolic::tanh(x);
    }

    cumeric_t tanh_deriv_from_result(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) - x * x;
    }

    cumeric_t sinh_deriv(cumeric_t x)
    {
        return cosh(x);
    }

    cumeric_t cosh_deriv(cumeric_t x)
    {
        return sinh(x);
    }

    /* Parallel versions */

    __event__ tanh_deriv(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            T t = sycl::tanh(x);
            return T(1) - t * t;
        });
    }

    __event__ tanh_deriv(datatype dtype, void* v, const std::size_t N)
    {
        return tanh_deriv(dtype, v, v, N);
    }

    __event__ tanh_deriv_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return tanh_deriv(dtype, v, v, N);
    }

    __event__ tanh_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return tanh_deriv(default_type, r, v, N);
    }

    __event__ tanh_deriv_in_place(cumeric_t* v, const std::size_t N)
    {
        return tanh_deriv(default_type, v, v, N);
    }

    __event__ tanh_deriv_from_result(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) - x * x;
        });
    }

    __event__ tanh_deriv_from_result(datatype dtype, void* v, const std::size_t N)
    {
        return tanh_deriv_from_result(dtype, v, v, N);
    }

    __event__ tanh_deriv_from_result_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return tanh_deriv_from_result(dtype, v, v, N);
    }

    __event__ tanh_deriv_from_result(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return tanh_deriv_from_result(default_type, r, v, N);
    }

    __event__ tanh_deriv_from_result_in_place(cumeric_t* v, const std::size_t N)
    {
        return tanh_deriv_from_result(default_type, v, v, N);
    }

    __event__ sinh_deriv(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return cosh(dtype, r, v, N);
    }

    __event__ sinh_deriv(datatype dtype, void* v, const std::size_t N)
    {
        return cosh(dtype, v, v, N);
    }

    __event__ sinh_deriv_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return cosh(dtype, v, v, N);
    }

    __event__ sinh_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return cosh(default_type, r, v, N);
    }

    __event__ sinh_deriv_in_place(cumeric_t* v, const std::size_t N)
    {
        return cosh(default_type, v, v, N);
    }

    __event__ cosh_deriv(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return sinh(dtype, r, v, N);
    }

    __event__ cosh_deriv(datatype dtype, void* v, const std::size_t N)
    {
        return sinh(dtype, v, v, N);
    }

    __event__ cosh_deriv_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sinh(dtype, v, v, N);
    }

    __event__ cosh_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sinh(default_type, r, v, N);
    }

    __event__ cosh_deriv_in_place(cumeric_t* v, const std::size_t N)
    {
        return sinh(default_type, v, v, N);
    }

}