/**
 * @file Primitive.hpp
 * @brief Base executable primitive abstraction for neural operations.
 * @author jaro
 */

#ifndef YANN_PRIMITIVE_HPP
#define YANN_PRIMITIVE_HPP

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
        /** @brief Decriptor*/
        using Descriptor = PrimitiveDescriptor;

        Primitive();

        /** @brief Creates binary operation primitive. */
        static Primitive binary();

        /** @brief Creates elementwise operation primitive. */
        static Primitive eltwise();

        /** @brief Creates matrix multiplication primitive. */
        static Primitive matmul();

        Primitive(const Primitive& other);

        /**
         * @brief Submits primitive execution to compute stream.
         * @return Asynchronous execution event.
         */
        __event__ execute();

        /**
         * @enum Kind
         * @brief Primitive operation category.
         */
        enum class Kind { binary, elementwise, matmul, softmax, sum, reduction, reorder };
    };
} // namespace cum::neural_primitives

#endif //YANN_PRIMITIVE_HPP
