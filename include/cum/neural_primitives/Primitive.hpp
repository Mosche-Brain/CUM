/**
 * @file Primitive.hpp
 * @brief Executable compute primitive abstraction for neural network and tensor operations.
 * @author jaro
 */

#pragma once

#include <initializer_list>
#include <memory>
#include <span>
#include <unordered_map>
#include <utility>

#include "cum/Core.hpp"
#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum { class Tensor; }

namespace cum::neural_primitives
{
    using cum::Tensor;
    /**
     * @class Primitive
     * @brief Executable compute primitive representing a compiled neural network or tensor operation.
     * @details Wraps a backend-compiled primitive created from a @ref PrimitiveDescriptor and executes
     *          asynchronously on the active compute stream, returning an @ref __event__.
     */
    class Primitive
    {
    public:
        /** @brief Descriptor type alias. */
        using Descriptor = PrimitiveDescriptor;

        /** @brief Operation category alias. */
        using Kind = Descriptor::Kind;

        /**
         * @enum Argument
         * @brief Named tensor slot identifiers for primitive execution.
         */
        enum class Argument : int
        {
            undef        = 0,
            src          = 1,    ///< Primary input tensor (alias for `src0`).
            src0         = 1,    ///< Input tensor #0.
            src1         = 2,    ///< Input tensor #1.
            src2         = 3,    ///< Input tensor #2.
            src3         = 4,    ///< Input tensor #3.
            dst          = 17,   ///< Primary output tensor (alias for `dst0`).
            dst0         = 17,   ///< Output tensor #0.
            weights      = 33,   ///< Weights tensor (e.g. RHS matrix `B` in `Matmul`).
            bias         = 41,   ///< Bias tensor.
            workspace    = 64,   ///< Workspace tensor shared between forward and backward passes.
            scratchpad   = 80,   ///< Scratchpad temporary buffer.
            diff_src     = 129,  ///< Output gradient w.r.t. primary input (`dx`).
            diff_src0    = 129,  ///< Output gradient w.r.t. input #0.
            diff_src1    = 130,  ///< Output gradient w.r.t. input #1.
            diff_dst     = 145,  ///< Upstream gradient w.r.t. output (`dy`).
            diff_weights = 161,  ///< Output gradient w.r.t. weights (`dW`).
            diff_bias    = 169,  ///< Output gradient w.r.t. bias (`db`).
            multiple_src = 1024  ///< Base slot for variadic sources (`Sum`, `Concat`): see @ref multiple_src_arg.
        };

        /**
         * @brief Computes the indexed variadic source slot (`Argument::multiple_src + index`) for `Sum` / `Concat`.
         */
        [[nodiscard]] static constexpr Argument multiple_src_arg(int index) noexcept
        {
            return static_cast<Argument>(static_cast<int>(Argument::multiple_src) + index);
        }

        /**
         * @struct ArgBinding
         * @brief Zero-copy argument binding pairing an @ref Argument slot with a @ref Memory or @ref Tensor reference.
         */
        struct ArgBinding
        {
            Argument arg;
            const Memory* memory = nullptr;

            constexpr ArgBinding(Argument a, const Memory& m) noexcept
                : arg(a), memory(&m) {}

            ArgBinding(Argument a, const Tensor& t);
        };

        using KV = std::pair<Argument, Memory>;
        using KVMap = std::unordered_map<Argument, Memory>;

        /**
         * @brief Constructs an empty, uncompiled primitive.
         */
        Primitive();

        /**
         * @brief Compiles an executable primitive from @p descriptor.
         */
        explicit Primitive(const Descriptor& descriptor);

        Primitive(const Primitive& other);
        Primitive& operator=(const Primitive& other);

        Primitive(Primitive&& other) noexcept;
        Primitive& operator=(Primitive&& other) noexcept;

        ~Primitive();

        /**
         * @brief Compiles (or recompiles) this primitive from @p descriptor.
         */
        void compile(const Descriptor& descriptor);

        /**
         * @brief Ensures the primitive is compiled from its stored descriptor.
         */
        void compile();

        /**
         * @brief Checks whether this primitive is compiled and ready to execute.
         */
        [[nodiscard]] bool valid() const noexcept;

        /**
         * @brief Boolean conversion equivalent to @ref valid().
         */
        explicit operator bool() const noexcept { return valid(); }

        /**
         * @brief Returns operation category of this primitive.
         */
        [[nodiscard]] Kind kind() const noexcept;

        /**
         * @brief Returns const reference to the @ref PrimitiveDescriptor from which this primitive was compiled.
         */
        [[nodiscard]] const Descriptor& descriptor() const;

        /* Named-argument execution (zero-copy span / initializer_list + KVMap compatibility) */

        /**
         * @brief Executes the primitive with explicit @ref ArgBinding pairs (accepts both @ref Memory and @ref Tensor).
         */
        __event__ execute(std::span<const ArgBinding> args, const __events__& deps = {}) const;

        /**
         * @brief Executes the primitive from a brace-initialized list of @ref ArgBinding pairs.
         */
        __event__ execute(std::initializer_list<ArgBinding> args, const __events__& deps = {}) const;

        /**
         * @brief Executes the primitive from a legacy `Argument -> Memory` map.
         */
        __event__ execute(const KVMap& kv_map, const __events__& deps = {}) const;

        /* Positional execution overloads: Memory */

        /**
         * @brief Executes a unary primitive (`Elementwise`, `Softmax`, `Reduction`, `Reorder`).
         */
        __event__ execute(Memory& dst, const Memory& arg0, const __events__& deps = {}) const;

        /**
         * @brief Executes a 2-input primitive (`Binary`, `Matmul` without bias, `ElementwiseBackward`, `SoftmaxBackward`, 2-input `Sum`/`Concat`).
         */
        __event__ execute(Memory& dst, const Memory& arg0, const Memory& arg1, const __events__& deps = {}) const;

        /**
         * @brief Executes a 3-input primitive (`Matmul` with bias, 3-input `Sum`/`Concat`).
         */
        __event__ execute(Memory& dst, const Memory& arg0, const Memory& arg1, const Memory& arg2, const __events__& deps = {}) const;

        /**
         * @brief Executes a variadic-source primitive (`Sum`, `Concat`) over a span of @ref Memory buffers.
         */
        __event__ execute(Memory& dst, std::span<const Memory> srcs, const __events__& deps = {}) const;

        /* Positional execution overloads: Tensor */

        /**
         * @brief Executes a unary primitive directly on @ref Tensor operands.
         */
        __event__ execute(Tensor& dst, const Tensor& arg0, const __events__& deps = {}) const;

        /**
         * @brief Executes a 2-input primitive directly on @ref Tensor operands.
         */
        __event__ execute(Tensor& dst, const Tensor& arg0, const Tensor& arg1, const __events__& deps = {}) const;

        /**
         * @brief Executes a 3-input primitive directly on @ref Tensor operands.
         */
        __event__ execute(Tensor& dst, const Tensor& arg0, const Tensor& arg1, const Tensor& arg2, const __events__& deps = {}) const;

    protected:
        struct Impl;
        std::unique_ptr<Impl> impl;
    };
} // namespace cum::neural_primitives
