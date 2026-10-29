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
    struct PrimitiveDescriptor::Impl
    {
        std::unique_ptr<dnnl::primitive_desc> desc;

        Impl() = default;

        Impl(const Impl& other) : desc(other.desc ? std::make_unique<dnnl::primitive_desc>(*other.desc) : nullptr) {}
        Impl& operator=(const Impl& other)
        {
            if (this != &other)
                desc = other.desc ? std::make_unique<dnnl::primitive_desc>(*other.desc) : nullptr;

            return *this;
        }

        Impl(Impl&&) noexcept = default;
        Impl& operator=(Impl&&) noexcept = default;
    };


    // PrimitiveDescriptor::PrimitiveDescriptor(PrimitiveDescriptor&&) noexcept
    // {
    //
    // }
    //
    // PrimitiveDescriptor& PrimitiveDescriptor::operator = (PrimitiveDescriptor&&) noexcept
    // {
    //
    // }

    PrimitiveDescriptor::~PrimitiveDescriptor() = default;

    PrimitiveDescriptor::PrimitiveDescriptor(PrimitiveDescriptor& other) : _impl(other._impl ? std::make_unique<Impl>(*other._impl) : nullptr) { }

    PrimitiveDescriptor& PrimitiveDescriptor::operator = (PrimitiveDescriptor& other)
    {
        if (this == &other) return *this;
        if (!other._impl)
            _impl.reset();
        else if (_impl)
            *_impl = *other._impl;
        else
            _impl = std::make_unique<Impl>(*other._impl);

        return *this;
    }

    PrimitiveDescriptor PrimitiveDescriptor::Binary(Algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src1, const Memory::Descriptor& src2)
    {
        PrimitiveDescriptor desc;

        desc._impl->desc = std::make_unique<dnnl::primitive_desc>(dnnl::binary::primitive_desc(
            internal::engine(),
            detail::dnnl_algorithm(alg),
            src1.handle().desc,
            src2.handle().desc,
            dst.handle().desc
        ));

        return desc;
    }

    PrimitiveDescriptor PrimitiveDescriptor::Elementwise(Algo alg, const Memory::Descriptor& dst, const Memory::Descriptor& src, Purpose prop_kind)
    {
        PrimitiveDescriptor desc;


        desc._impl->desc = std::make_unique<dnnl::primitive_desc>(dnnl::eltwise_forward::primitive_desc(
            internal::engine(),
            detail::dnnl_prop_kind(prop_kind),
            detail::dnnl_algorithm(alg),
            src.handle().desc,
            dst.handle().desc
        ));


        return desc;
    }

    PrimitiveDescriptor::Kind PrimitiveDescriptor::kind() const noexcept
    {
        return _kind;
    }
} // cum