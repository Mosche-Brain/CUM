/*
 * @author: jaro
 * @name:   PrimitiveDescriptor
 * @file:   include/cum/neural_primitives/PrimitiveDescriptor.hpp
 * @date:   28 October 2026 22:41:38
 */

#pragma once

#include "cum/Core.hpp"

#include "cum/neural_primitives/MemoryDescriptor.hpp"

namespace cum::neural_primitives
{
    /**
     * @enum prop_kind
     * @brief Propagation mode for neural network primitives.
     * @details Modeled after oneDNN propagation kind flags.
     */
    enum class prop_kind
    {
        undef             = 0,   ///< Undefined propagation kind.
        forward_training  = 64,  ///< Forward propagation for training mode (saves data for backpropagation).
        forward_inference = 96,  ///< Forward propagation for inference mode (omits training caches).
        forward           = 64,  ///< Forward propagation alias for forward_training.
        backward          = 128, ///< Backward propagation for all parameters.
        backward_data     = 160, ///< Backward propagation with respect to data.
        backward_weights  = 192, ///< Backward propagation with respect to weights.
        backward_bias     = 192  ///< Backward propagation with respect to bias.
    };

    enum class algo
    {
        undef = 0,

        eltwise_relu = 32,
        eltwise_tanh = 33,
        eltwise_elu = 34,
        eltwise_square = 35,
        eltwise_abs = 36,
        eltwise_sqrt = 37,
        eltwise_linear = 38,
        eltwise_soft_relu = 39,
        // eltwise_sex = 40,
        eltwise_logistic = 41,
        eltwise_exp = 42,
        eltwise_log = 45,

        binary_add = 131056,
        binary_sub = 131061,
        binary_mul = 131057,
        binary_div = 131060,
        binary_eq = 131066,
    };


    class PrimitiveDescriptor
    {
    public:
        PrimitiveDescriptor() = default;

        static PrimitiveDescriptor Binary(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2);
        static PrimitiveDescriptor Elementwise(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2, prop_kind prop_kind=prop_kind::forward);
        static PrimitiveDescriptor Reduction(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2, prop_kind prop_kind=prop_kind::forward);
        static PrimitiveDescriptor Convolution(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src, const Memory::Descriptor& weights, Shape strides, Shape padding, Shape padding, prop_kind prop_kind=prop_kind::forward);
    private:
        struct Impl;
        std::unique_ptr<Impl> _impl;
    };
} // cum

