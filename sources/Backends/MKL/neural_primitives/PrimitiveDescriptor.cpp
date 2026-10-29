/*
 * @author: jaro
 * @name:   PrimitiveDescriptor
 * @file:   include/cum/neural_primitives/PrimitiveDescriptor.cpp
 * @date:   28 October 2026 22:41:38
 */

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/opaque_types.hpp"

#include "cum/neural_primitives/Primitive.hpp"

#include "cum/neural_primitives/PrimitiveDescriptor.hpp"
#include "cum/detail/vendor/oneapi/primitive_descriptors_handles.hpp"

namespace cum::neural_primitives
{
    PrimitiveDescriptor PrimitiveDescriptor::Binary(Algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2)
    {
        PrimitiveDescriptor desc;

        desc._impl = std::make_unique<BinaryDescriptor>(
            internal::engine(),
            alg,
            src1.handle().desc,
            src2.handle().desc,
            dst.handle().desc
        );

        return desc;
    }

    PrimitiveDescriptor PrimitiveDescriptor::Elementwise(Algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src, Purpose prop_kind)
    {
        PrimitiveDescriptor desc;

        desc._impl = std::make_unique<ElementwiseDescriptor>(
            alg, dst.handle().desc, src.handle().desc, prop_kind
        );

        return desc;
    }

    PrimitiveDescriptor::Kind PrimitiveDescriptor::kind() const noexcept
    {
        return _impl->kind;
    }
} // cum