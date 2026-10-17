/* Created by jaro on 7/20/26. */
#include <cstdint>
#include <stdexcept>

#include "cum/functions/linear_units.hpp"
#include "cum/functions/trigonometric.hpp"
#include "cum/functions/cyclometric.hpp"
#include "cum/functions/hyperbolic.hpp"
#include "cum/functions/exponential.hpp"
#include "cum/functions/logistic.hpp"
#include "cum/functions/linear_units.hpp"
#include "cum/functions/various.hpp"

#include "cum/detail/vendor/oneapi/dtype_dispatch.hpp"
#include "cum/functions/transform.hpp"

namespace cum::functions
{
    void transform(datatype dtype, void* r, const void* v, const std::size_t N, const activation_t& activation)
    {
        if (activation.name != function_id::undefined)
        {
            transform(dtype, r, v, N, activation.name);
        }
        else if (activation.function != nullptr)
        {
            internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
                auto* r_ptr = static_cast<SyclT*>(r);
                auto* v_ptr = static_cast<const SyclT*>(v);
                #pragma omp parallel for
                for (std::size_t i = 0; i < N; ++i)
                    r_ptr[i] = static_cast<SyclT>(activation.function(static_cast<cumeric_t>(static_cast<internal::math_compute_t<SyclT>>(v_ptr[i]))));
            });
        }
        else
        {
            throw std::runtime_error("Unknown activation type (transform), used " + std::to_string(static_cast<unsigned char>(activation.name)));
        }
    }

    void transform_deriv(datatype dtype, void* r, const void* v, const std::size_t N, const activation_t& activation)
    {
        if (activation.name != function_id::undefined)
        {
            transform_deriv(dtype, r, v, N, activation.name);
        }
        else if (activation.derivative != nullptr)
        {
            internal::dispatch_sycl_datatype(dtype, [&]<typename SyclT>() {
                auto* r_ptr = static_cast<SyclT*>(r);
                auto* v_ptr = static_cast<const SyclT*>(v);
                #pragma omp parallel for
                for (std::size_t i = 0; i < N; ++i)
                    r_ptr[i] = static_cast<SyclT>(activation.derivative(static_cast<cumeric_t>(static_cast<internal::math_compute_t<SyclT>>(v_ptr[i]))));
            });
        }
        else
        {
            throw std::runtime_error("Unknown activation type (transform_deriv)");
        }
    }

    void transform(datatype dtype, void* r, const void* v, const std::size_t N, const function_id activation)
    {
        switch (activation)
        {
            case function_id::linear:
            {
                linear_units::identity(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::relu:
            {
                linear_units::relu(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::leaky_relu:
            {
                linear_units::leaky_relu(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::gelu:
            {
                linear_units::gelu(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::elu:
            {
                linear_units::elu(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::exp:
            {
                exponential::exp(dtype, r, v, N);
                break;
            }
            case function_id::exp2:
            {
                exponential::exp2(dtype, r, v, N);
                break;
            }
            case function_id::exp10:
            {
                exponential::exp10(dtype, r, v, N);
                break;
            }
            case function_id::log:
            {
                exponential::log(dtype, r, v, N);
                break;
            }
            case function_id::log2:
            {
                exponential::log2(dtype, r, v, N);
                break;
            }
            case function_id::log10:
            {
                exponential::log10(dtype, r, v, N);
                break;
            }
            case function_id::sigmoid:
            {
                logistic::sigmoid(dtype, r, v, N);
                break;
            }
            case function_id::sin:
            {
                trigonometric::sin(dtype, r, v, N);
                break;
            }
            case function_id::cos:
            {
                trigonometric::cos(dtype, r, v, N);
                break;
            }
            case function_id::tan:
            {
                trigonometric::tan(dtype, r, v, N);
                break;
            }
            case function_id::sinh:
            {
                hyperbolic::sinh(dtype, r, v, N);
                break;
            }
            case function_id::cosh:
            {
                hyperbolic::cosh(dtype, r, v, N);
                break;
            }
            case function_id::tanh:
            {
                hyperbolic::tanh(dtype, r, v, N);
                break;
            }
            case function_id::asin:
            {
                cyclometric::asin(dtype, r, v, N);
                break;
            }
            case function_id::acos:
            {
                cyclometric::acos(dtype, r, v, N);
                break;
            }
            case function_id::atan:
            {
                cyclometric::atan(dtype, r, v, N);
                break;
            }
            default:
            {
                throw std::runtime_error("Unknown activation function (transform(datatype, void*, const void*, std::size_t, function_id))");
            }
        }
    }

    void transform_deriv(datatype dtype, void* r, const void* v, const std::size_t N, const function_id activation)
    {
        switch (activation)
        {
            case function_id::linear:
            {
                linear_units::identity_deriv(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::relu:
            {
                linear_units::relu_deriv(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::leaky_relu:
            {
                linear_units::leaky_relu_deriv(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::gelu:
            {
                linear_units::gelu_deriv(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::elu:
            {
                linear_units::elu_deriv(dtype, r, v, static_cast<dim_t>(N));
                break;
            }
            case function_id::exp:
            {
                exponential::exp_deriv(dtype, r, v, N);
                break;
            }
            case function_id::exp2:
            {
                exponential::exp2_deriv(dtype, r, v, N);
                break;
            }
            case function_id::exp10:
            {
                exponential::exp10_deriv(dtype, r, v, N);
                break;
            }
            case function_id::log:
            {
                exponential::log_deriv(dtype, r, v, N);
                break;
            }
            case function_id::log2:
            {
                exponential::log2_deriv(dtype, r, v, N);
                break;
            }
            case function_id::log10:
            {
                exponential::log10_deriv(dtype, r, v, N);
                break;
            }
            case function_id::sigmoid:
            {
                logistic::sigmoid_deriv(dtype, r, v, N);
                break;
            }
            case function_id::sin:
            {
                trigonometric::sin_deriv(dtype, r, v, N);
                break;
            }
            case function_id::cos:
            {
                trigonometric::cos_deriv(dtype, r, v, N);
                break;
            }
            case function_id::tan:
            {
                trigonometric::tan_deriv(dtype, r, v, N);
                break;
            }
            case function_id::sinh:
            {
                hyperbolic::sinh_deriv(dtype, r, v, N);
                break;
            }
            case function_id::cosh:
            {
                hyperbolic::cosh_deriv(dtype, r, v, N);
                break;
            }
            case function_id::tanh:
            {
                hyperbolic::tanh_deriv(dtype, r, v, N);
                break;
            }
            case function_id::asin:
            {
                cyclometric::asin_deriv(dtype, r, v, N);
                break;
            }
            case function_id::acos:
            {
                cyclometric::acos_deriv(dtype, r, v, N);
                break;
            }
            case function_id::atan:
            {
                cyclometric::atan_deriv(dtype, r, v, N);
                break;
            }
            default:
            {
                throw std::runtime_error("Unknown activation function (in transform_deriv(datatype, void*, const void*, std::size_t, function_id))");
            }
        }
    }

    void transform(cumeric_t* r, const cumeric_t* v, const std::size_t N, const activation_t& activation)
    {
        transform(default_type, r, v, N, activation);
    }

    void transform_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N, const activation_t& activation)
    {
        transform_deriv(default_type, r, v, N, activation);
    }

    void transform(cumeric_t* r, const cumeric_t* v, const std::size_t N, const function_id activation)
    {
        transform(default_type, r, v, N, activation);
    }

    void transform_deriv(cumeric_t* r, const cumeric_t* v, const std::size_t N, const function_id activation)
    {
        transform_deriv(default_type, r, v, N, activation);
    }

}

