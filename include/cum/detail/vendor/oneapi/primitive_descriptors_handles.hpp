/*
 * @author: jaro
 * @name:   primitive_descriptors_handles
 * @file:   include/cum/detail/vendor/oneapi/primitive_descriptors_handles.hpp
 * @date:   29 October 2026 21:10:36
 */

#pragma once

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"

#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum::neural_primitives
{
    namespace detail
    {
        inline dnnl::algorithm dnnl_algorithm(Algo algorithm)
        {
            return static_cast<dnnl::algorithm>(algorithm);
        }

        inline dnnl::prop_kind dnnl_prop_kind(Purpose purpose)
        {
            return static_cast<dnnl::prop_kind>(purpose);
        }
    }


    struct PrimitiveDescriptor::Impl
    {
        explicit Impl(Kind k) : kind(k) {}

        Kind kind;
    };

    struct BinaryDescriptor : PrimitiveDescriptor::Impl
    {
        BinaryDescriptor(dnnl::engine engine, Algo alg, const dnnl::memory::desc& src1, const dnnl::memory::desc& src2, const dnnl::memory::desc& dst) : Impl(PrimitiveDescriptor::Kind::binary)
        {
            desc = dnnl::binary::primitive_desc(engine, detail::dnnl_algorithm(alg), src1, src2, dst);
        }

        BinaryDescriptor(Algo alg, const dnnl::memory::desc& src1, const dnnl::memory::desc& src2, const dnnl::memory::desc& dst) : BinaryDescriptor(internal::engine(), alg, src1, src2, dst) {}

        dnnl::binary::primitive_desc desc;
    };

    struct ElementwiseDescriptor : PrimitiveDescriptor::Impl
    {
        ElementwiseDescriptor(dnnl::engine engine, Algo alg, const dnnl::memory::desc& dst, const dnnl::memory::desc& src, Purpose purpose) : Impl(PrimitiveDescriptor::Kind::elementwise)
        {
            desc = dnnl::eltwise_forward::primitive_desc(engine, detail::dnnl_prop_kind(purpose), detail::dnnl_algorithm(alg), src, dst);
        }

        ElementwiseDescriptor(Algo alg, const dnnl::memory::desc& dst, const dnnl::memory::desc& src, Purpose purpose) : ElementwiseDescriptor(internal::engine(), alg, dst, src, purpose) {}

        dnnl::eltwise_forward::primitive_desc desc;
    };

    struct ConvolutionDescriptor : PrimitiveDescriptor::Impl
    {
        dnnl::convolution_forward::primitive_desc desc;
    };

    struct SoftmaxDescriptor : PrimitiveDescriptor::Impl
    {
        dnnl::softmax_forward::primitive_desc desc;
    };
}