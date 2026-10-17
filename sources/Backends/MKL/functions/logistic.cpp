/* Created by jaro on 7/19/26. */

#include "cum/Core.hpp"

#include "cum/lara/BLAS/level1.hpp"
#include "cum/lara/reductions.hpp"
#include "cum/functions/exponential.hpp"

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"

#include "cum/functions/logistic.hpp"

namespace cum::functions::logistic
{
    /* ========================== Base Functions ========================== */

    /* Scalar versions */

    cumeric_t sigmoid(cumeric_t x)
    {
        return static_cast<cumeric_t>(1.0) / (static_cast<cumeric_t>(1.0) + sycl::exp(-x));
    }

    /* Parallel versions */

    __event__ sigmoid(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return T(1) / (T(1) + sycl::exp(-x));
        });
    }

    __event__ sigmoid(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid(dtype, v, v, N);
    }

    __event__ sigmoid_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid(dtype, v, v, N);
    }

    __event__ sigmoid(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sigmoid(default_type, r, v, N);
    }

    __event__ sigmoid_in_place(cumeric_t* v, const std::size_t N)
    {
        return sigmoid(default_type, v, v, N);
    }

    __event__ softmax(datatype dtype, void* r, const void* v, const dim_t N)
    {
        if (dtype == default_type) {
            exponential::exp(static_cast<cumeric_t*>(r), static_cast<const cumeric_t*>(v), static_cast<std::size_t>(N)).wait();
            cumeric_t sum_exp_v = 0;
            lara::sum(&sum_exp_v, static_cast<cumeric_t*>(r), N);
            return blas::scal(N, static_cast<cumeric_t>(1) / sum_exp_v, static_cast<cumeric_t*>(r), 1);
        }
        exponential::exp(dtype, r, v, static_cast<std::size_t>(N)).wait();
        sycl::event event = internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() -> sycl::event {
            auto& q = internal::getQueue();
            auto* r_ptr = static_cast<SyclT*>(r);
            using ComputeT = internal::math_compute_t<SyclT>;
            ComputeT total = ComputeT(0);
            for (dim_t i = 0; i < N; ++i) {
                total += static_cast<ComputeT>(r_ptr[i]);
            }
            const ComputeT inv_sum = ComputeT(1) / total;
            return q.parallel_for(sycl::range<1>(static_cast<std::size_t>(N)), [=](sycl::id<1> idx) {
                r_ptr[idx] = static_cast<SyclT>(static_cast<ComputeT>(r_ptr[idx]) * inv_sum);
            });
        });
        return detail::event_handler::create(std::move(event));
    }

    __event__ softmax(datatype dtype, void* v, const dim_t N)
    {
        return softmax(dtype, v, v, N);
    }

    __event__ softmax_in_place(datatype dtype, void* v, const dim_t N)
    {
        return exponential::exp_in_place(dtype, v, static_cast<std::size_t>(N));
    }

    __event__ softmax(cumeric_t* r, const cumeric_t* v, const dim_t N)
    {
        return softmax(default_type, r, v, N);
    }

    __event__ softmax_in_place(cumeric_t* v, const dim_t N)
    {
        return softmax_in_place(default_type, v, N);
    }

    /* ========================== Derivatives ========================== */

    /* Scalar versions */

    cumeric_t sigmoid_deriv(cumeric_t x)
    {
        return sigmoid(x) * (static_cast<cumeric_t>(1.0) - sigmoid(x));
    }

    cumeric_t sigmoid_deriv_from_result(cumeric_t x)
    {
        return x * (static_cast<cumeric_t>(1.0) - x);
    }

    /* Parallel versions */

    __event__ sigmoid_deriv(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            T s = T(1) / (T(1) + sycl::exp(-x));
            return s * (T(1) - s);
        });
    }

    __event__ sigmoid_deriv(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv(dtype, v, v, N);
    }

    __event__ sigmoid_deriv_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv(dtype, v, v, N);
    }

    __event__ sigmoid_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sigmoid_deriv(default_type, r, v, N);
    }

    __event__ sigmoid_deriv_in_place(cumeric_t* v, const std::size_t N)
    {
        return sigmoid_deriv(default_type, v, v, N);
    }

    __event__ sigmoid_deriv_from_result(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return internal::dispatch_unary_math(dtype, r, v, N, [](auto x) {
            using T = decltype(x);
            return x * (T(1) - x);
        });
    }

    __event__ sigmoid_deriv_from_result(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(dtype, v, v, N);
    }

    __event__ sigmoid_deriv_from_result_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(dtype, v, v, N);
    }

    __event__ sigmoid_deriv_from_result(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(default_type, r, v, N);
    }

    __event__ sigmoid_deriv_from_result_in_place(cumeric_t* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(default_type, v, v, N);
    }

    __event__ softmax_deriv(datatype dtype, void* r, const void* v, const dim_t N)
    {
        return sigmoid_deriv(dtype, r, v, static_cast<std::size_t>(N));
    }

    __event__ softmax_deriv(datatype dtype, void* v, const dim_t N)
    {
        return sigmoid_deriv(dtype, v, v, static_cast<std::size_t>(N));
    }

    __event__ softmax_deriv_in_place(datatype dtype, void* v, const dim_t N)
    {
        return sigmoid_deriv(dtype, v, v, static_cast<std::size_t>(N));
    }

    __event__ softmax_deriv(cumeric_t* r, const cumeric_t* v, const dim_t N)
    {
        return softmax_deriv(default_type, r, v, N);
    }

    __event__ softmax_deriv_in_place(cumeric_t* v, const dim_t N)
    {
        return softmax_deriv(default_type, v, v, N);
    }

    __event__ softmax_deriv_from_result(datatype dtype, void* r, const void* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(dtype, r, v, N);
    }

    __event__ softmax_deriv_from_result(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(dtype, v, v, N);
    }

    __event__ softmax_deriv_from_result_in_place(datatype dtype, void* v, const std::size_t N)
    {
        return sigmoid_deriv_from_result(dtype, v, v, N);
    }

    __event__ softmax_deriv_from_result(cumeric_t* r, const cumeric_t* v, const std::size_t N)
    {
        return softmax_deriv_from_result(default_type, r, v, N);
    }

    __event__ softmax_deriv_from_result_in_place(cumeric_t* v, const std::size_t N)
    {
        return softmax_deriv_from_result(default_type, v, v, N);
    }

}

