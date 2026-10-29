/*
 * @author: jaro
 * @name:   Primitive
 * @file:   modules/cum/include/cum/neural_primitives/Primitive.cpp
 * @date:   19 September 2026 18:44:28
 */

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/primitive_descriptors_handles.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"

#include "cum/neural_primitives/Primitive.hpp"

#include "cum/detail/vendor/oneapi/opaque_types.hpp"

namespace cum::neural_primitives
{
    struct PrimitiveDescriptor::Impl
    {
        std::unique_ptr<dnnl::primitive_desc> desc;
    }; // this is redundant

    struct Primitive::Impl
    {
        std::unique_ptr<dnnl::primitive> primitive;

        ~Impl() = default;
    };

    Primitive::~Primitive() = default;

    Primitive::Primitive(const Descriptor& descriptor)
    {
        switch (descriptor.kind())
        {
            case Kind::binary:
            {
                const auto& pd = static_cast<const dnnl::binary::primitive_desc&>(
                    *descriptor._impl->desc
                );

                this->impl->primitive = std::make_unique<dnnl::binary>(pd);
                break;
            }
            case Kind::elementwise:
            {
                const auto& pd = static_cast<const dnnl::eltwise_forward::primitive_desc&>(
                    *descriptor._impl->desc
                );

                this->impl->primitive = std::make_unique<dnnl::eltwise_forward>(pd);
                break;
            }

            default:
                break;
        }
    }

    void Primitive::compile()
    {

    }

    __event__ Primitive::execute(Memory& dst, const Memory& arg0, const Memory& arg1, const Memory& arg2)
    {

    }

    __event__ Primitive::execute(Memory& dst, const Memory& arg0, const Memory& arg1)
    {
        sycl::event event = dnnl::sycl_interop::execute(
            *impl->primitive,
            internal::stream(),
            {
                { DNNL_ARG_DST, dst.handle().memory },
                { DNNL_ARG_SRC_0, arg0.handle().memory },
                { DNNL_ARG_SRC_1, arg1.handle().memory }
            }
        );

        return cum::detail::event_handler::create(std::move(event));
    }

    __event__ Primitive::execute(KVMap kv_map)
    {

    }


} // cum::neural_primitives