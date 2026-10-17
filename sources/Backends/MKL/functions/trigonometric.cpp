//
// Created by jaro on 7/19/26.
//

#include <oneapi/mkl/vm.hpp>
#include <sycl/sycl.hpp>

#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/functions/trigonometric.hpp"

namespace cum::functions::trigonometric
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t sin(cumeric_t x)
    {
        return sycl::sin(x);
    }


    cumeric_t cos(cumeric_t x)
    {
        return sycl::cos(x);
    }

    cumeric_t tan(cumeric_t x)
    {
        return sycl::tan(x);
    }

    /* Parallelized versions */

    __event__ sin(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::sin(q, len, vp, rp)) {
                return oneapi::mkl::vm::sin(q, len, vp, rp);
            },
            [](auto x) { return sycl::sin(x); }
        );
    }

    __event__ sin(datatype dtype, void* v, const std::size_t N)
    {
        return sin(dtype, v, v, N);
    }

    __event__ sin_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sin(dtype, v, v, N);
    }

    __event__ sin(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sin(default_type, r, v, N);
    }

    __event__ sin_in_place(cumeric_t* v, const std::size_t N)
    {
        return sin(default_type, v, v, N);
    }

    __event__ cos(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::cos(q, len, vp, rp)) {
                return oneapi::mkl::vm::cos(q, len, vp, rp);
            },
            [](auto x) { return sycl::cos(x); }
        );
    }

    __event__ cos(datatype dtype, void* v, const std::size_t N)
    {
        return cos(dtype, v, v, N);
    }

    __event__ cos_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return cos(dtype, v, v, N);
    }

    __event__ cos(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return cos(default_type, r, v, N);
    }

    __event__ cos_in_place(cumeric_t* v, const std::size_t N)
    {
        return cos(default_type, v, v, N);
    }

    __event__ tan(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_vm_unary(dtype, r, v, N,
            [](auto& q, dim_t len, const auto* vp, auto* rp) -> decltype(oneapi::mkl::vm::tan(q, len, vp, rp)) {
                return oneapi::mkl::vm::tan(q, len, vp, rp);
            },
            [](auto x) { return sycl::tan(x); }
        );
    }

    __event__ tan(datatype dtype, void* v, std::size_t N)
    {
        return tan(dtype, v, v, N);
    }

    __event__ tan_in_place(datatype dtype, void* v, std::size_t N)
    {
        return tan(dtype, v, v, N);
    }

    __event__ tan(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return tan(default_type, r, v, N);
    }

    __event__ tan_in_place(cumeric_t* v, std::size_t N)
    {
        return tan(default_type, v, v, N);
    }

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t sin_deriv(cumeric_t x)
    {
        return sycl::cos(x);
    }

    cumeric_t cos_deriv(cumeric_t x)
    {
        return -sycl::sin(x);
    }

    cumeric_t tan_deriv(cumeric_t x)
    {
        cumeric_t t = sycl::tan(x);
        return 1._c + t * t;
    }

    cumeric_t tan_deriv_from_result(cumeric_t x)
    {
        return 1._c + x * x;
    }

    /* Parallelized versions */

    __event__ sin_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return cos(dtype, r, v, N);
    }

    __event__ sin_deriv(datatype dtype, void* v, std::size_t N)
    {
        return cos(dtype, v, v, N);
    }

    __event__ sin_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return cos(dtype, v, v, N);
    }

    __event__ sin_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return cos(default_type, r, v, N);
    }

    __event__ sin_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return cos(default_type, v, v, N);
    }

    __event__ cos_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            return -sycl::sin(x);
        });
    }

    __event__ cos_deriv(datatype dtype, void* v, std::size_t N)
    {
        return cos_deriv(dtype, v, v, N);
    }

    __event__ cos_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return cos_deriv(dtype, v, v, N);
    }

    __event__ cos_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return cos_deriv(default_type, r, v, N);
    }

    __event__ cos_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return cos_deriv(default_type, v, v, N);
    }

    __event__ tan_deriv(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            T t = sycl::tan(x);
            return T(1) + t * t;
        });
    }

    __event__ tan_deriv(datatype dtype, void* v, std::size_t N)
    {
        return tan_deriv(dtype, v, v, N);
    }

    __event__ tan_deriv_in_place(datatype dtype, void* v, std::size_t N)
    {
        return tan_deriv(dtype, v, v, N);
    }

    __event__ tan_deriv(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return tan_deriv(default_type, r, v, N);
    }

    __event__ tan_deriv_in_place(cumeric_t* v, std::size_t N)
    {
        return tan_deriv(default_type, v, v, N);
    }

    __event__ tan_deriv_from_result(datatype dtype, void* r, const void* v, std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) + x * x;
        });
    }

    __event__ tan_deriv_from_result(datatype dtype, void* v, std::size_t N)
    {
        return tan_deriv_from_result(dtype, v, v, N);
    }

    __event__ tan_deriv_in_place_from_result(datatype dtype, void* v, std::size_t N)
    {
        return tan_deriv_from_result(dtype, v, v, N);
    }

    __event__ tan_deriv_from_result(cumeric_t* r, const cumeric_t* v, std::size_t N)
    {
        return tan_deriv_from_result(default_type, r, v, N);
    }

    __event__ tan_deriv_in_place_from_result(cumeric_t* v, std::size_t N)
    {
        return tan_deriv_from_result(default_type, v, v, N);
    }
}

