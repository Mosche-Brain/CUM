/**
 * @file Primitive.hpp
 * @brief Base executable primitive abstraction for neural operations.
 * @author jaro
 */

#pragma once

#include <unordered_map>

#include "cum/Core.hpp"

#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum::neural_primitives
{
    /**
     * @class Primitive
     * @brief Executable compute primitive representing a compiled neural network operation.
     */
    class Primitive
    {
    public:
        /** @brief Decriptor */
        using Descriptor = PrimitiveDescriptor;

        /** @brief Arguments for primitive execution */
        enum class Argument { src, src0 = src, src1, dst, weights, bias};
        using KV = std::pair<Argument, Memory>; // Currently, I have no idea how to name it
        using KVMap = std::unordered_map<Argument, Memory>;

        Primitive();
        ~Primitive();

        Primitive(const Descriptor& descriptor);

        Primitive(const Primitive& other);

        /**
         * @brief Submits primitive execution to compute stream.
         * @return Asynchronous execution event.
         */
        __event__ execute(Memory& dst, const Memory& arg0, const Memory& arg1, const Memory& arg2);
        __event__ execute(Memory& dst, const Memory& arg0, const Memory& arg1);
        __event__ execute(KVMap kv_map);

        void compile();

        /**
         * @enum Kind
         * @brief Primitive operation category.
         */
        using Kind = Descriptor::Kind;
    protected:
        struct Impl;
        std::unique_ptr<Impl> impl;
    };
} // namespace cum::neural_primitives
