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

namespace cum::neural_primitives
{
    struct Primitive::Impl
    {

    };

    struct BinaryPrimitiveImpl final : Primitive::Impl
    {
        dnnl::binary primitive;
    };

    struct ElementwisePrimitiveImpl final : Primitive::Impl
    {
        dnnl::eltwise_forward primitive;
    };

    struct ElementwiseBackwardPrimitiveImpl final : Primitive::Impl
    {
        dnnl::eltwise_forward primitive;
    };

    struct PoolingPrimitiveImpl final : Primitive::Impl
    {
        dnnl::pooling_forward primitive;
    };

    struct ConvolutionPrimitiveImpl final : Primitive::Impl
    {
        dnnl::convolution_forward primitive;
    };

    struct ConvolutionBackwardPrimitiveImpl final : Primitive::Impl
    {
        dnnl::convolution_forward primitive;
    };

    Primitive::Primitive(const Descriptor& descriptor)
    {
        switch (descriptor.kind())
        {
            case Kind::binary:
            {
                const dnnl::binary::primitive_desc& pd = static_cast<const BinaryDescriptor*>(descriptor._impl.get())->desc;
                this->impl = std::make_unique<BinaryPrimitiveImpl>();

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
        sycl::event event = dnnl::sycl_interop::execute()
    }

    __event__ Primitive::execute(KVMap kv_map)
    {

    }


} // cum::neural_primitives