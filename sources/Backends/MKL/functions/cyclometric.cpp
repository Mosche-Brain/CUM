/* Created by jaro on 7/19/26. */

#include <oneapi/mkl/vm.hpp>
#include <sycl/sycl.hpp>

#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/functions/cyclometric.hpp"

namespace cum::functions::cyclometric
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t asin(cumeric_t x)
    {
        return sycl::asin(x);
    }

    cumeric_t acos(cumeric_t x)
    {
        return sycl::acos(x);
    }

    cumeric_t atan(cumeric_t x)
    {
        return sycl::atan(x);
    }

    /* Parallel versions */

    __event__ asin(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::asin(q, len, vp, rp)) {
                return oneapi::mkl::vm::asin(q, len, vp, rp);
            },
            [](auto x) { return sycl::asin(x); }
        );
    }

    __event__ asin(datatype dtype, void* v, std::size_t N)
    {
        return asin(dtype, v, v, N);
    }

    __event__ asin_in_place(datatype dtype, void* v, std::size_t N)
    {
        return asin(dtype, v, v, N);
    }

    __event__ asin(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return asin(default_type, r, v, N);
    }

    __event__ asin_in_place(cumeric_t* v, std::size_t N)
    {
        return asin(default_type, v, v, N);
    }

    __event__ acos(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::acos(q, len, vp, rp)) {
                return oneapi::mkl::vm::acos(q, len, vp, rp);
            },
            [](auto x) { return sycl::acos(x); }
        );
    }

    __event__ acos(datatype dtype, void* v, std::size_t N)
    {
        return acos(dtype, v, v, N);
    }

    __event__ acos_in_place(datatype dtype, void* v, std::size_t N)
    {
        return acos(dtype, v, v, N);
    }

    __event__ acos(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return acos(default_type, r, v, N);
    }

    __event__ acos_in_place(cumeric_t* v, std::size_t N)
    {
        return acos(default_type, v, v, N);
    }

    __event__ atan(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::atan(q, len, vp, rp)) {
                return oneapi::mkl::vm::atan(q, len, vp, rp);
            },
            [](auto x) { return sycl::atan(x); }
        );
    }

    __event__ atan(datatype dtype, void* v, std::size_t N)
    {
        return atan(dtype, v, v, N);
    }

    __event__ atan_in_place(datatype dtype, void* v, std::size_t N)
    {
        return atan(dtype, v, v, N);
    }

    __event__ atan(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return atan(default_type, r, v, N);
    }

    __event__ atan_in_place(cumeric_t* v, std::size_t N)
    {
        return atan(default_type, v, v, N);
    }

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t asin_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1) / sycl::sqrt(static_cast<cumeric_t>(1) - x*x);
    }

    cumeric_t acos_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(-1) / sycl::sqrt(static_cast<cumeric_t>(1) - x*x);
    }
    cumeric_t atan_deriv(cumeric_t x)
    {
        return static_cast<cumeric_t>(1)/ (x*x + 1);
    }

    /* Parallel versions */

    __event__ asin_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / sycl::sqrt(T(1) - x * x);
        });
    }

    __event__ asin_deriv(datatype dtype, void* v, std::size_t N)
    {
        return asin_deriv(dtype, v, v, N);
    }

    __event__ asin_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return asin_deriv(dtype, v, v, N);
    }

    __event__ asin_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return asin_deriv(default_type, r, v, N);
    }

    __event__ asin_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return asin_deriv(default_type, v, v, N);
    }

    __event__ acos_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(-1) / sycl::sqrt(T(1) - x * x);
        });
    }

    __event__ acos_deriv(datatype dtype, void* v, std::size_t N)
    {
        return acos_deriv(dtype, v, v, N);
    }

    __event__ acos_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return acos_deriv(dtype, v, v, N);
    }

    __event__ acos_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return acos_deriv(default_type, r, v, N);
    }

    __event__ acos_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return acos_deriv(default_type, v, v, N);
    }

    __event__ atan_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / (x * x + T(1));
        });
    }

    __event__ atan_deriv(datatype dtype, void* v, std::size_t N)
    {
        return atan_deriv(dtype, v, v, N);
    }

    __event__ atan_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return atan_deriv(dtype, v, v, N);
    }

    __event__ atan_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return atan_deriv(default_type, r, v, N);
    }

    __event__ atan_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return atan_deriv(default_type, v, v, N);
    }
}