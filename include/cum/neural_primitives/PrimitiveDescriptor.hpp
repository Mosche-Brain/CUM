/**
 * @file PrimitiveDescriptor.hpp
 * @brief Unified descriptor factory and metadata query interface for neural network primitives.
 * @author jaro
 */

#pragma once

#include <initializer_list>
#include <memory>
#include <span>
#include <string_view>

#include "cum/Core.hpp"
#include "cum/functions/function_id.hpp"
#include "cum/neural_primitives/Engine.hpp"
#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/MemoryDescriptor.hpp"

namespace cum::neural_primitives
{
    /**
     * @enum Purpose
     * @brief Propagation mode for neural network primitives.
     * @details Values preserve compatibility with existing elementwise/reduction propagation flags.
     */
    enum class Purpose
    {
        forward           = 64,  ///< Forward propagation (training-compatible, alias for forward_training).
        forward_training  = 64,  ///< Forward propagation saving metadata/workspace needed for backward pass.
        forward_inference = 96,  ///< Forward propagation optimized for inference only.
        backward          = 128, ///< Backward propagation for all parameters.
        backward_data     = 160, ///< Backward propagation with respect to input data.
        backward_weights  = 192, ///< Backward propagation with respect to weights.
        backward_bias     = 193  ///< Backward propagation with respect to bias.
    };

    /**
     * @enum Algo
     * @brief Algorithm selector for elementwise, binary, softmax, and reduction primitives.
     */
    enum class Algo
    {
        undef = 0,

        /* Elementwise algorithms (forward & backward) */
        eltwise_relu,
        eltwise_tanh,
        eltwise_elu,
        eltwise_square,
        eltwise_abs,
        eltwise_sqrt,
        eltwise_linear,
        eltwise_soft_relu,
        eltwise_logistic,
        eltwise_exp,
        eltwise_gelu_tanh,
        eltwise_gelu_erf,
        eltwise_swish,
        eltwise_mish,
        eltwise_log,
        eltwise_clip,
        eltwise_clip_v2,
        eltwise_pow,
        eltwise_round,
        eltwise_hardswish,
        eltwise_hardsigmoid,

        /* Elementwise algorithms consuming forward destination `dst` in backward pass */
        eltwise_relu_use_dst_for_bwd,
        eltwise_tanh_use_dst_for_bwd,
        eltwise_elu_use_dst_for_bwd,
        eltwise_sqrt_use_dst_for_bwd,
        eltwise_logistic_use_dst_for_bwd,
        eltwise_exp_use_dst_for_bwd,
        eltwise_clip_v2_use_dst_for_bwd,

        /* Binary tensor operations (supporting per-dimension broadcast) */
        binary_add = 0x100,
        binary_sub,
        binary_mul,
        binary_div,
        binary_max,
        binary_min,
        binary_eq,
        binary_ne,
        binary_gt,
        binary_ge,
        binary_lt,
        binary_le,

        /* Softmax operations */
        softmax_accurate = 0x200,
        softmax_log,

        /* Reduction operations */
        reduction_max = 0x300,
        reduction_min,
        reduction_sum,
        reduction_mul,
        reduction_mean,
        reduction_norm_lp_max,
        reduction_norm_lp_sum,
        reduction_norm_lp_power_p_max,
        reduction_norm_lp_power_p_sum,

        /* Ergonomic elementwise aliases (kept last so auto-numbered enumerators never collide) */
        eltwise_leaky_relu = eltwise_relu,
        eltwise_sigmoid    = eltwise_logistic,
        eltwise_gelu       = eltwise_gelu_tanh,
        eltwise_clamp      = eltwise_clip
    };

    /**
     * @brief Maps a high-level @ref cum::functions::function_id to its corresponding @ref Algo.
     * @param fn Activation or math function identifier.
     * @return Matching @ref Algo, or @ref Algo::undef if unsupported by neural primitives.
     */
    [[nodiscard]] Algo to_algo(functions::function_id fn) noexcept;

    /**
     * @class PrimitiveDescriptor
     * @brief Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters.
     * @details Constructed via static factory methods (`Binary`, `Elementwise`, `ElementwiseBackward`,
     *          `Matmul`, `Softmax`, `SoftmaxBackward`, `Reduction`, `Reorder`, `Sum`, `Concat`) and compiled
     *          into an executable @ref Primitive.
     */
    class PrimitiveDescriptor
    {
    public:
        /**
         * @enum Kind
         * @brief Primitive operation category.
         */
        enum class Kind
        {
            undef = 0,
            binary,
            elementwise,
            matmul,
            softmax,
            reduction,
            reorder,
            sum,
            concat
        };

        PrimitiveDescriptor();
        ~PrimitiveDescriptor();

        PrimitiveDescriptor(const PrimitiveDescriptor& other);
        PrimitiveDescriptor& operator=(const PrimitiveDescriptor& other);

        PrimitiveDescriptor(PrimitiveDescriptor&& other) noexcept;
        PrimitiveDescriptor& operator=(PrimitiveDescriptor&& other) noexcept;

        /* Inspection & Metadata Queries */

        /**
         * @brief Checks whether this descriptor holds a valid resolved primitive configuration.
         */
        [[nodiscard]] bool valid() const noexcept;

        /**
         * @brief Boolean conversion equivalent to @ref valid().
         */
        explicit operator bool() const noexcept { return valid(); }

        /**
         * @brief Returns primitive operation category.
         */
        [[nodiscard]] Kind kind() const noexcept;

        /**
         * @brief Returns propagation mode (`forward`, `backward`, etc.).
         */
        [[nodiscard]] Purpose purpose() const noexcept;

        /**
         * @brief Returns algorithm tag (`Algo::undef` for operations without sub-algorithms like `Matmul` or `Reorder`).
         */
        [[nodiscard]] Algo algorithm() const noexcept;

        /**
         * @brief Returns backend kernel implementation name selected for this descriptor.
         */
        [[nodiscard]] std::string_view impl_info() const;

        /**
         * @brief Queries resolved source memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor src_desc(int index = 0) const;

        /**
         * @brief Queries resolved destination memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor dst_desc(int index = 0) const;

        /**
         * @brief Queries resolved weights memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor weights_desc(int index = 0) const;

        /**
         * @brief Queries resolved bias memory descriptor (empty if primitive has no bias).
         */
        [[nodiscard]] MemoryDescriptor bias_desc() const;

        /**
         * @brief Queries resolved gradient-source (`diff_src`) memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor diff_src_desc(int index = 0) const;

        /**
         * @brief Queries resolved gradient-destination (`diff_dst`) memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor diff_dst_desc(int index = 0) const;

        /**
         * @brief Queries resolved gradient-weights (`diff_weights`) memory descriptor at @p index.
         */
        [[nodiscard]] MemoryDescriptor diff_weights_desc(int index = 0) const;

        /**
         * @brief Queries workspace memory descriptor required between forward and backward passes (empty if none).
         */
        [[nodiscard]] MemoryDescriptor workspace_desc() const;

        /**
         * @brief Queries temporary scratchpad memory descriptor.
         */
        [[nodiscard]] MemoryDescriptor scratchpad_desc() const;

        /* Static Factories: Binary */

        /**
         * @brief Creates a binary elementwise/broadcasting primitive descriptor (`dst = op(src0, src1)`).
         */
        static PrimitiveDescriptor Binary(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src0,
            const MemoryDescriptor& src1
        );

        static PrimitiveDescriptor Binary(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src0,
            const MemoryDescriptor& src1
        );

        /* Static Factories: Elementwise (Forward & Backward) */

        /**
         * @brief Creates a forward elementwise primitive descriptor with optional @p alpha and @p beta parameters.
         * @param alg Elementwise algorithm (`eltwise_relu`, `eltwise_elu`, `eltwise_clip`, `eltwise_linear`, etc.).
         * @param dst Destination memory descriptor.
         * @param src Source memory descriptor.
         * @param alpha Algorithm parameter (e.g. negative slope for Leaky ReLU, scale for ELU/Swish/Linear/Pow, lower bound for Clip).
         * @param beta Secondary algorithm parameter (e.g. shift for Linear, exponent for Pow, upper bound for Clip).
         * @param prop_kind Forward propagation mode (`Purpose::forward` or `Purpose::forward_inference`).
         */
        static PrimitiveDescriptor ElementwiseForward(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float alpha = 0.0f,
            float beta = 0.0f,
            Purpose prop_kind = Purpose::forward
        );

        static PrimitiveDescriptor ElementwiseForward(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float alpha = 0.0f,
            float beta = 0.0f,
            Purpose prop_kind = Purpose::forward
        );

        /**
         * @brief Creates a forward elementwise primitive descriptor (default parameters `alpha = 0`, `beta = 0`).
         */
        static PrimitiveDescriptor Elementwise(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            Purpose prop_kind = Purpose::forward
        );

        /**
         * @brief Creates a parameterized forward elementwise primitive descriptor.
         */
        static PrimitiveDescriptor Elementwise(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float alpha,
            float beta = 0.0f,
            Purpose prop_kind = Purpose::forward
        );

        /**
         * @brief Creates a backward elementwise primitive descriptor using an explicit forward descriptor hint.
         * @param alg Elementwise algorithm.
         * @param diff_src Output gradient w.r.t. input (`dx`) memory descriptor.
         * @param diff_dst Upstream gradient w.r.t. output (`dy`) memory descriptor.
         * @param data Forward `src` descriptor (or forward `dst` descriptor for `*_use_dst_for_bwd` algorithms).
         * @param hint_fwd_pd Matching forward elementwise primitive descriptor.
         * @param alpha Algorithm `alpha` parameter.
         * @param beta Algorithm `beta` parameter.
         */
        static PrimitiveDescriptor ElementwiseBackward(
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& data,
            const PrimitiveDescriptor& hint_fwd_pd,
            float alpha = 0.0f,
            float beta = 0.0f
        );

        static PrimitiveDescriptor ElementwiseBackward(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& data,
            const PrimitiveDescriptor& hint_fwd_pd,
            float alpha = 0.0f,
            float beta = 0.0f
        );

        /**
         * @brief Creates a backward elementwise primitive descriptor (automatically synthesizing the forward hint).
         */
        static PrimitiveDescriptor ElementwiseBackward(
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& data,
            float alpha = 0.0f,
            float beta = 0.0f
        );

        /* Static Factories: Matmul */

        /**
         * @brief Creates a 2D or batched N-D matrix multiplication descriptor (`dst = src * weights`).
         */
        static PrimitiveDescriptor Matmul(
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            const MemoryDescriptor& weights
        );

        static PrimitiveDescriptor Matmul(
            Engine& engine,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            const MemoryDescriptor& weights
        );

        /**
         * @brief Creates a 2D or batched N-D matrix multiplication descriptor with additive bias (`dst = src * weights + bias`).
         */
        static PrimitiveDescriptor Matmul(
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            const MemoryDescriptor& weights,
            const MemoryDescriptor& bias
        );

        static PrimitiveDescriptor Matmul(
            Engine& engine,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            const MemoryDescriptor& weights,
            const MemoryDescriptor& bias
        );

        /* Static Factories: Softmax (Forward & Backward) */

        /**
         * @brief Creates a forward softmax or log-softmax primitive descriptor along @p axis (supports negative indexing, e.g. `-1`).
         */
        static PrimitiveDescriptor SoftmaxForward(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            int axis = -1,
            Purpose prop_kind = Purpose::forward
        );

        static PrimitiveDescriptor SoftmaxForward(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            int axis = -1,
            Purpose prop_kind = Purpose::forward
        );

        /**
         * @brief Alias for @ref SoftmaxForward.
         */
        static PrimitiveDescriptor Softmax(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            int axis = -1,
            Purpose prop_kind = Purpose::forward
        );

        /**
         * @brief Creates a backward softmax/log-softmax descriptor using an explicit forward descriptor hint.
         */
        static PrimitiveDescriptor SoftmaxBackward(
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& dst,
            int axis,
            const PrimitiveDescriptor& hint_fwd_pd
        );

        static PrimitiveDescriptor SoftmaxBackward(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& dst,
            int axis,
            const PrimitiveDescriptor& hint_fwd_pd
        );

        /**
         * @brief Creates a backward softmax/log-softmax descriptor (automatically synthesizing the forward hint).
         */
        static PrimitiveDescriptor SoftmaxBackward(
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& dst,
            int axis = -1
        );

        /* Static Factories: Reduction */

        /**
         * @brief Creates a tensor reduction descriptor (`dst` must have the same rank as `src` with reduced axes set to `1`).
         * @param alg Reduction algorithm (`reduction_sum`, `reduction_mean`, `reduction_max`, `reduction_min`, `reduction_mul`, `reduction_norm_lp_*`).
         * @param dst Reduced destination memory descriptor.
         * @param src Input source memory descriptor.
         * @param p Power parameter for Lp-norm reductions (>= 1.0 when applicable).
         * @param eps Epsilon parameter for Lp-norm reductions.
         */
        static PrimitiveDescriptor Reduction(
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float p = 0.0f,
            float eps = 0.0f
        );

        static PrimitiveDescriptor Reduction(
            Engine& engine,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float p = 0.0f,
            float eps = 0.0f
        );

        /* Static Factories: Reorder */

        /**
         * @brief Creates a layout and/or datatype conversion (`Reorder`) primitive descriptor on the active engine.
         */
        static PrimitiveDescriptor Reorder(
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src
        );

        /**
         * @brief Creates a cross-engine or explicit-engine `Reorder` primitive descriptor.
         */
        static PrimitiveDescriptor Reorder(
            Engine& dst_engine,
            const MemoryDescriptor& dst,
            Engine& src_engine,
            const MemoryDescriptor& src
        );

        /* Static Factories: Sum & Concat */

        /**
         * @brief Creates a scaled multi-tensor summation descriptor (`dst = sum_i(scales[i] * srcs[i])`).
         * @param dst Destination memory descriptor (may use `layout::ANY`).
         * @param srcs Span of input memory descriptors.
         * @param scales Optional per-input scale factors (defaults to `1.0f` for every input if empty).
         */
        static PrimitiveDescriptor Sum(
            const MemoryDescriptor& dst,
            std::span<const MemoryDescriptor> srcs,
            std::span<const float> scales = {}
        );

        static PrimitiveDescriptor Sum(
            const MemoryDescriptor& dst,
            std::initializer_list<MemoryDescriptor> srcs,
            std::initializer_list<float> scales = {}
        );

        /**
         * @brief Creates an out-of-place tensor concatenation descriptor along @p axis (supports negative indexing).
         */
        static PrimitiveDescriptor Concat(
            const MemoryDescriptor& dst,
            std::span<const MemoryDescriptor> srcs,
            int axis = 0
        );

        static PrimitiveDescriptor Concat(
            const MemoryDescriptor& dst,
            std::initializer_list<MemoryDescriptor> srcs,
            int axis = 0
        );

        /**
         * @brief Creates a concatenation descriptor with automatically deduced destination descriptor (`pd.dst_desc()`).
         */
        static PrimitiveDescriptor Concat(
            std::span<const MemoryDescriptor> srcs,
            int axis = 0
        );

        static PrimitiveDescriptor Concat(
            std::initializer_list<MemoryDescriptor> srcs,
            int axis = 0
        );

        friend class Primitive;
        friend struct PrimitiveDescriptorBuilder;

    protected:
        struct Impl;
        explicit PrimitiveDescriptor(std::unique_ptr<Impl> impl) noexcept;
        std::unique_ptr<Impl> _impl;
    };
} // namespace cum::neural_primitives
