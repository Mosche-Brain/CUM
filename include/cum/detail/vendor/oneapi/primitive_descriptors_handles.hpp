/**
 * @file primitive_descriptors_handles.hpp
 * @brief Internal oneDNN conversion helpers and Pimpl definition for PrimitiveDescriptor.
 * @author jaro
 */

#pragma once

#include <stdexcept>

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum::neural_primitives
{
    namespace detail
    {
        inline dnnl::algorithm dnnl_algorithm(Algo algorithm)
        {
            switch (algorithm)
            {
                case Algo::undef:                            return dnnl::algorithm::undef;

                case Algo::eltwise_relu:                     return dnnl::algorithm::eltwise_relu;
                case Algo::eltwise_tanh:                     return dnnl::algorithm::eltwise_tanh;
                case Algo::eltwise_elu:                      return dnnl::algorithm::eltwise_elu;
                case Algo::eltwise_square:                   return dnnl::algorithm::eltwise_square;
                case Algo::eltwise_abs:                      return dnnl::algorithm::eltwise_abs;
                case Algo::eltwise_sqrt:                     return dnnl::algorithm::eltwise_sqrt;
                case Algo::eltwise_linear:                   return dnnl::algorithm::eltwise_linear;
                case Algo::eltwise_soft_relu:                return dnnl::algorithm::eltwise_soft_relu;
                case Algo::eltwise_logistic:                 return dnnl::algorithm::eltwise_logistic;
                case Algo::eltwise_exp:                      return dnnl::algorithm::eltwise_exp;
                case Algo::eltwise_gelu_tanh:                return dnnl::algorithm::eltwise_gelu_tanh;
                case Algo::eltwise_gelu_erf:                 return dnnl::algorithm::eltwise_gelu_erf;
                case Algo::eltwise_swish:                    return dnnl::algorithm::eltwise_swish;
                case Algo::eltwise_mish:                     return dnnl::algorithm::eltwise_mish;
                case Algo::eltwise_log:                      return dnnl::algorithm::eltwise_log;
                case Algo::eltwise_clip:                     return dnnl::algorithm::eltwise_clip;
                case Algo::eltwise_clip_v2:                  return dnnl::algorithm::eltwise_clip_v2;
                case Algo::eltwise_pow:                      return dnnl::algorithm::eltwise_pow;
                case Algo::eltwise_round:                    return dnnl::algorithm::eltwise_round;
                case Algo::eltwise_hardswish:                return dnnl::algorithm::eltwise_hardswish;
                case Algo::eltwise_hardsigmoid:              return dnnl::algorithm::eltwise_hardsigmoid;

                case Algo::eltwise_relu_use_dst_for_bwd:     return dnnl::algorithm::eltwise_relu_use_dst_for_bwd;
                case Algo::eltwise_tanh_use_dst_for_bwd:     return dnnl::algorithm::eltwise_tanh_use_dst_for_bwd;
                case Algo::eltwise_elu_use_dst_for_bwd:      return dnnl::algorithm::eltwise_elu_use_dst_for_bwd;
                case Algo::eltwise_sqrt_use_dst_for_bwd:     return dnnl::algorithm::eltwise_sqrt_use_dst_for_bwd;
                case Algo::eltwise_logistic_use_dst_for_bwd: return dnnl::algorithm::eltwise_logistic_use_dst_for_bwd;
                case Algo::eltwise_exp_use_dst_for_bwd:      return dnnl::algorithm::eltwise_exp_use_dst_for_bwd;
                case Algo::eltwise_clip_v2_use_dst_for_bwd:  return dnnl::algorithm::eltwise_clip_v2_use_dst_for_bwd;

                case Algo::binary_add:                       return dnnl::algorithm::binary_add;
                case Algo::binary_sub:                       return dnnl::algorithm::binary_sub;
                case Algo::binary_mul:                       return dnnl::algorithm::binary_mul;
                case Algo::binary_div:                       return dnnl::algorithm::binary_div;
                case Algo::binary_max:                       return dnnl::algorithm::binary_max;
                case Algo::binary_min:                       return dnnl::algorithm::binary_min;
                case Algo::binary_eq:                        return dnnl::algorithm::binary_eq;
                case Algo::binary_ne:                        return dnnl::algorithm::binary_ne;
                case Algo::binary_gt:                        return dnnl::algorithm::binary_gt;
                case Algo::binary_ge:                        return dnnl::algorithm::binary_ge;
                case Algo::binary_lt:                        return dnnl::algorithm::binary_lt;
                case Algo::binary_le:                        return dnnl::algorithm::binary_le;

                case Algo::softmax_accurate:                 return dnnl::algorithm::softmax_accurate;
                case Algo::softmax_log:                      return dnnl::algorithm::softmax_log;

                case Algo::reduction_max:                    return dnnl::algorithm::reduction_max;
                case Algo::reduction_min:                    return dnnl::algorithm::reduction_min;
                case Algo::reduction_sum:                    return dnnl::algorithm::reduction_sum;
                case Algo::reduction_mul:                    return dnnl::algorithm::reduction_mul;
                case Algo::reduction_mean:                   return dnnl::algorithm::reduction_mean;
                case Algo::reduction_norm_lp_max:             return dnnl::algorithm::reduction_norm_lp_max;
                case Algo::reduction_norm_lp_sum:             return dnnl::algorithm::reduction_norm_lp_sum;
                case Algo::reduction_norm_lp_power_p_max:     return dnnl::algorithm::reduction_norm_lp_power_p_max;
                case Algo::reduction_norm_lp_power_p_sum:     return dnnl::algorithm::reduction_norm_lp_power_p_sum;
            }
            return dnnl::algorithm::undef;
        }

        inline dnnl::prop_kind dnnl_prop_kind(Purpose purpose)
        {
            switch (purpose)
            {
                case Purpose::forward:           return dnnl::prop_kind::forward_training;
                case Purpose::forward_inference: return dnnl::prop_kind::forward_inference;
                case Purpose::backward:          return dnnl::prop_kind::backward;
                case Purpose::backward_data:     return dnnl::prop_kind::backward_data;
                case Purpose::backward_weights:  return dnnl::prop_kind::backward_weights;
                case Purpose::backward_bias:     return dnnl::prop_kind::backward_bias;
            }
            return dnnl::prop_kind::undef;
        }

        [[nodiscard]] constexpr bool is_backward_purpose(Purpose purpose) noexcept
        {
            return purpose == Purpose::backward
                || purpose == Purpose::backward_data
                || purpose == Purpose::backward_weights
                || purpose == Purpose::backward_bias;
        }

        [[nodiscard]] constexpr bool uses_dst_for_bwd(Algo alg) noexcept
        {
            switch (alg)
            {
                case Algo::eltwise_relu_use_dst_for_bwd:
                case Algo::eltwise_tanh_use_dst_for_bwd:
                case Algo::eltwise_elu_use_dst_for_bwd:
                case Algo::eltwise_sqrt_use_dst_for_bwd:
                case Algo::eltwise_logistic_use_dst_for_bwd:
                case Algo::eltwise_exp_use_dst_for_bwd:
                case Algo::eltwise_clip_v2_use_dst_for_bwd:
                    return true;
                default:
                    return false;
            }
        }
    } // namespace detail

    /**
     * @brief Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp.
     * @details `dnnl::primitive_desc_base` wraps the refcounted C `dnnl_primitive_desc_t` handle without slicing.
     */
    struct PrimitiveDescriptor::Impl
    {
        dnnl::primitive_desc_base pd{};
        Kind kind = Kind::undef;
        Purpose purpose = Purpose::forward;
        Algo algo = Algo::undef;
        bool has_bias = false;
    };
} // namespace cum::neural_primitives
