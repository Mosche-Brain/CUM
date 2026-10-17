//
// Created by jaro on 7/19/26.
//

#include "cum/Core.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

#include <oneapi/mkl/vm.hpp>
#include <sycl/sycl.hpp>

#include "cum/functions/exponential.hpp"

namespace cum::functions::exponential
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t exp(cumeric_t x)
    {
        return sycl::exp(x);
    }

    cumeric_t exp2(cumeric_t x)
    {
        return sycl::exp2(x);
    }

    cumeric_t exp10(cumeric_t x)
    {
        return sycl::exp10(x);
    }

    cumeric_t log(cumeric_t x) // base e
    {
        return sycl::log(x);
    }

    cumeric_t log2(cumeric_t x)
    {
        return sycl::log2(x);
    }

    cumeric_t log10(cumeric_t x)
    {
        return sycl::log10(x);
    }

    /* Parallel versions */

    __event__ exp(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::exp(q, len, vp, rp)) {
                return oneapi::mkl::vm::exp(q, len, vp, rp);
            },
            [](auto x) { return sycl::exp(x); }
        );
    }

    __event__ exp(datatype dtype, void* v, const std::size_t N)
    {
        return exp(dtype, v, v, N);
    }

    __event__ exp_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return exp(dtype, v, v, N);
    }

    __event__ exp(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return exp(default_type, r, v, N);
    }

    __event__ exp_in_place(cumeric_t* v, const std::size_t N)
    {
        return exp(default_type, v, v, N);
    }

    __event__ exp2(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::exp2(q, len, vp, rp)) {
                return oneapi::mkl::vm::exp2(q, len, vp, rp);
            },
            [](auto x) { return sycl::exp2(x); }
        );
    }

    __event__ exp2(datatype dtype, void* v, const std::size_t N)
    {
        return exp2(dtype, v, v, N);
    }

    __event__ exp2_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return exp2(dtype, v, v, N);
    }

    __event__ exp2(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return exp2(default_type, r, v, N);
    }

    __event__ exp2_in_place(cumeric_t* v, const std::size_t N)
    {
        return exp2(default_type, v, v, N);
    }

    __event__ exp10(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::exp10(q, len, vp, rp)) {
                return oneapi::mkl::vm::exp10(q, len, vp, rp);
            },
            [](auto x) { return sycl::exp10(x); }
        );
    }

    __event__ exp10(datatype dtype, void* v, const std::size_t N)
    {
        return exp10(dtype, v, v, N);
    }

    __event__ exp10_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return exp10(dtype, v, v, N);
    }

    __event__ exp10(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return exp10(default_type, r, v, N);
    }

    __event__ exp10_in_place(cumeric_t* v, const std::size_t N)
    {
        return exp10(default_type, v, v, N);
    }

    __event__ log(datatype dtype, void* r, const void* v, const std::size_t N) // base e
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::ln(q, len, vp, rp)) {
                return oneapi::mkl::vm::ln(q, len, vp, rp);
            },
            [](auto x) { return sycl::log(x); }
        );
    }

    __event__ log(datatype dtype, void* v, const std::size_t N)
    {
        return log(dtype, v, v, N);
    }

    __event__ log_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return log(dtype, v, v, N);
    }

    __event__ log(cumeric_t* r, const cumeric_t* v, const std::size_t N) // base e
    {
        return log(default_type, r, v, N);
    }

    __event__ log_in_place(cumeric_t* v, const std::size_t N)
    {
        return log(default_type, v, v, N);
    }

    __event__ log2(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::log2(q, len, vp, rp)) {
                return oneapi::mkl::vm::log2(q, len, vp, rp);
            },
            [](auto x) { return sycl::log2(x); }
        );
    }

    __event__ log2(datatype dtype, void* v, const std::size_t N)
    {
        return log2(dtype, v, v, N);
    }

    __event__ log2_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return log2(dtype, v, v, N);
    }

    __event__ log2(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return log2(default_type, r, v, N);
    }

    __event__ log2_in_place(cumeric_t* v, const std::size_t N)
    {
        return log2(default_type, v, v, N);
    }

    __event__ log10(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::log10(q, len, vp, rp)) {
                return oneapi::mkl::vm::log10(q, len, vp, rp);
            },
            [](auto x) { return sycl::log10(x); }
        );
    }

    __event__ log10(datatype dtype, void* v, const std::size_t N)
    {
        return log10(dtype, v, v, N);
    }

    __event__ log10_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return log10(dtype, v, v, N);
    }

    __event__ log10(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return log10(default_type, r, v, N);
    }

    __event__ log10_in_place(cumeric_t* v, const std::size_t N)
    {
        return log10(default_type, v, v, N);
    }

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t exp_deriv(cumeric_t x)
    {
        return sycl::exp(x);
    }

    cumeric_t exp_deriv_from_result(cumeric_t x)
    {
        return x;
    }

    cumeric_t exp2_deriv(cumeric_t x)
    {
        return sycl::log(static_cast<cumeric_t>(2)) * exp2(x);
    }

    cumeric_t exp2_deriv_from_result(cumeric_t x)
    {
        return sycl::log(static_cast<cumeric_t>(2)) * x;
    }

    cumeric_t exp10_deriv(cumeric_t x)
    {
        return sycl::log(static_cast<cumeric_t>(10)) * exp10(x);
    }

    cumeric_t exp10_deriv_from_result(cumeric_t x)
    {
        return sycl::log(static_cast<cumeric_t>(10)) * x;
    }

    cumeric_t log_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) / x;
    }

    cumeric_t log2_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) / (sycl::log(static_cast<cumeric_t>(2))*x);
    }

    cumeric_t log10_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) / (sycl::log(static_cast<cumeric_t>(10))*x);
    }

    /* Parallel versions */

    __event__ exp_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return exp(dtype, r, v, N);
    }

    __event__ exp_deriv(datatype dtype, void* v, std::size_t N)
    {
        return exp(dtype, v, v, N);
    }

    __event__ exp_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return exp(dtype, v, v, N);
    }

    __event__ exp_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return exp(default_type, r, v, N);
    }

    __event__ exp_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return exp(default_type, v, v, N);
    }

    __event__ exp2_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return sycl::log(T(2)) * sycl::exp2(x);
        });
    }

    __event__ exp2_deriv(datatype dtype, void* v, std::size_t N)
    {
        return exp2_deriv(dtype, v, v, N);
    }

    __event__ exp2_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return exp2_deriv(dtype, v, v, N);
    }

    __event__ exp2_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return exp2_deriv(default_type, r, v, N);
    }

    __event__ exp2_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return exp2_deriv(default_type, v, v, N);
    }

    __event__ exp10_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return sycl::log(T(10)) * sycl::exp10(x);
        });
    }

    __event__ exp10_deriv(datatype dtype, void* v, std::size_t N)
    {
        return exp10_deriv(dtype, v, v, N);
    }

    __event__ exp10_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return exp10_deriv(dtype, v, v, N);
    }

    __event__ exp10_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return exp10_deriv(default_type, r, v, N);
    }

    __event__ exp10_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return exp10_deriv(default_type, v, v, N);
    }

    __event__ log_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / x;
        });
    }

    __event__ log_deriv(datatype dtype, void* v, std::size_t N)
    {
        return log_deriv(dtype, v, v, N);
    }

    __event__ log_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return log_deriv(dtype, v, v, N);
    }

    __event__ log_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return log_deriv(default_type, r, v, N);
    }

    __event__ log_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return log_deriv(default_type, v, v, N);
    }

    __event__ log2_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / (sycl::log(T(2)) * x);
        });
    }

    __event__ log2_deriv(datatype dtype, void* v, std::size_t N)
    {
        return log2_deriv(dtype, v, v, N);
    }

    __event__ log2_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return log2_deriv(dtype, v, v, N);
    }

    __event__ log2_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return log2_deriv(default_type, r, v, N);
    }

    __event__ log2_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return log2_deriv(default_type, v, v, N);
    }

    __event__ log10_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / (sycl::log(T(10)) * x);
        });
    }

    __event__ log10_deriv(datatype dtype, void* v, std::size_t N)
    {
        return log10_deriv(dtype, v, v, N);
    }

    __event__ log10_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return log10_deriv(dtype, v, v, N);
    }

    __event__ log10_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return log10_deriv(default_type, r, v, N);
    }

    __event__ log10_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return log10_deriv(default_type, v, v, N);
    }
}