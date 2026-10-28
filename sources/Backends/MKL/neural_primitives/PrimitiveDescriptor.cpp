/*
 * @author: jaro
 * @name:   PrimitiveDescriptor
 * @file:   include/cum/neural_primitives/PrimitiveDescriptor.cpp
 * @date:   28 October 2026 22:41:38
 */

#include <variant>

#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum::neural_primitives
{
    struct PrimitiveDescriptor::Impl
    {

    };

    static PrimitiveDescriptor PrimitiveDescriptor::Binary(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2)
    {

    }

    static PrimitiveDescriptor PrimitiveDescriptor::Elementwise(algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2)
    {

    }
} // cum