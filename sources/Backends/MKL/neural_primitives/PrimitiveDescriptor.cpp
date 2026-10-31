/**
 * @file PrimitiveDescriptor.cpp
 * @brief oneDNN implementation of unified PrimitiveDescriptor factories and queries.
 * @author jaro
 */

#include <stdexcept>
#include <vector>

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/opaque_types.hpp"
#include "cum/detail/vendor/oneapi/primitive_descriptors_handles.hpp"

#include "cum/neural_primitives/PrimitiveDescriptor.hpp"

namespace cum::neural_primitives
{
    struct PrimitiveDescriptorBuilder
    {
        static PrimitiveDescriptor make(
            dnnl::primitive_desc_base&& pd,
            PrimitiveDescriptor::Kind kind,
            Purpose purpose = Purpose::forward,
            Algo algo = Algo::undef,
            bool has_bias = false);
    };

    namespace
    {
        int normalize_axis(int axis, dim_t ndims)
        {
            const int rank = static_cast<int>(ndims);
            if (rank <= 0)
                throw std::invalid_argument("Cannot resolve axis on an empty or 0-dimensional descriptor");
            const int norm = axis < 0 ? (axis + rank) : axis;
            if (norm < 0 || norm >= rank)
                throw std::out_of_range("Axis index is out of bounds for tensor rank");
            return norm;
        }

        PrimitiveDescriptor make_pd(
            dnnl::primitive_desc_base&& pd,
            PrimitiveDescriptor::Kind kind,
            Purpose purpose = Purpose::forward,
            Algo algo = Algo::undef,
            bool has_bias = false)
        {
            return PrimitiveDescriptorBuilder::make(std::move(pd), kind, purpose, algo, has_bias);
        }

        PrimitiveDescriptor create_binary(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src0,
            const MemoryDescriptor& src1)
        {
            dnnl::binary::primitive_desc pd(
                eng,
                detail::dnnl_algorithm(alg),
                src0.handle().desc,
                src1.handle().desc,
                dst.handle().desc
            );
            return make_pd(std::move(pd), PrimitiveDescriptor::Kind::binary, Purpose::forward, alg);
        }

        PrimitiveDescriptor create_eltwise_fwd(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float alpha,
            float beta,
            Purpose prop_kind)
        {
            dnnl::eltwise_forward::primitive_desc pd(
                eng,
                detail::dnnl_prop_kind(prop_kind),
                detail::dnnl_algorithm(alg),
                src.handle().desc,
                dst.handle().desc,
                alpha,
                beta
            );
            return make_pd(std::move(pd), PrimitiveDescriptor::Kind::elementwise, prop_kind, alg);
        }

        PrimitiveDescriptor create_eltwise_bwd(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& data,
            const_dnnl_primitive_desc_t hint_c_pd,
            float alpha,
            float beta)
        {
            if (!hint_c_pd)
                throw std::invalid_argument("ElementwiseBackward requires a valid forward hint PrimitiveDescriptor");

            dnnl_primitive_desc_t c_pd = nullptr;
            const dnnl_status_t status = dnnl_eltwise_backward_primitive_desc_create(
                &c_pd,
                eng.get(),
                dnnl::convert_to_c(detail::dnnl_algorithm(alg)),
                diff_src.handle().desc.get(),
                diff_dst.handle().desc.get(),
                data.handle().desc.get(),
                alpha,
                beta,
                hint_c_pd,
                nullptr
            );
            dnnl::error::wrap_c_api(status, "Failed to create oneDNN eltwise_backward primitive descriptor");
            return make_pd(dnnl::primitive_desc_base(c_pd), PrimitiveDescriptor::Kind::elementwise, Purpose::backward_data, alg);
        }

        PrimitiveDescriptor create_matmul(
            const dnnl::engine& eng,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            const MemoryDescriptor& weights,
            const MemoryDescriptor* bias)
        {
            if (bias && bias->valid())
            {
                dnnl::matmul::primitive_desc pd(
                    eng,
                    src.handle().desc,
                    weights.handle().desc,
                    bias->handle().desc,
                    dst.handle().desc
                );
                return make_pd(std::move(pd), PrimitiveDescriptor::Kind::matmul, Purpose::forward, Algo::undef, /*has_bias=*/true);
            }

            dnnl::matmul::primitive_desc pd(
                eng,
                src.handle().desc,
                weights.handle().desc,
                dst.handle().desc
            );
            return make_pd(std::move(pd), PrimitiveDescriptor::Kind::matmul, Purpose::forward, Algo::undef, /*has_bias=*/false);
        }

        PrimitiveDescriptor create_softmax_fwd(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            int axis,
            Purpose prop_kind)
        {
            const dim_t rank = src.ndims() > 0 ? src.ndims() : dst.ndims();
            const int norm_axis = normalize_axis(axis, rank);
            dnnl::softmax_forward::primitive_desc pd(
                eng,
                detail::dnnl_prop_kind(prop_kind),
                detail::dnnl_algorithm(alg),
                src.handle().desc,
                dst.handle().desc,
                norm_axis
            );
            return make_pd(std::move(pd), PrimitiveDescriptor::Kind::softmax, prop_kind, alg);
        }

        PrimitiveDescriptor create_softmax_bwd(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& diff_src,
            const MemoryDescriptor& diff_dst,
            const MemoryDescriptor& dst,
            int axis,
            const_dnnl_primitive_desc_t hint_c_pd)
        {
            if (!hint_c_pd)
                throw std::invalid_argument("SoftmaxBackward requires a valid forward hint PrimitiveDescriptor");

            const int norm_axis = normalize_axis(axis, dst.ndims());
            dnnl_primitive_desc_t c_pd = nullptr;
            const dnnl_status_t status = dnnl_softmax_backward_primitive_desc_create(
                &c_pd,
                eng.get(),
                dnnl::convert_to_c(detail::dnnl_algorithm(alg)),
                diff_src.handle().desc.get(),
                diff_dst.handle().desc.get(),
                dst.handle().desc.get(),
                norm_axis,
                hint_c_pd,
                nullptr
            );
            dnnl::error::wrap_c_api(status, "Failed to create oneDNN softmax_backward primitive descriptor");
            return make_pd(dnnl::primitive_desc_base(c_pd), PrimitiveDescriptor::Kind::softmax, Purpose::backward_data, alg);
        }

        PrimitiveDescriptor create_reduction(
            const dnnl::engine& eng,
            Algo alg,
            const MemoryDescriptor& dst,
            const MemoryDescriptor& src,
            float p,
            float eps)
        {
            dnnl::reduction::primitive_desc pd(
                eng,
                detail::dnnl_algorithm(alg),
                src.handle().desc,
                dst.handle().desc,
                p,
                eps
            );
            return make_pd(std::move(pd), PrimitiveDescriptor::Kind::reduction, Purpose::forward, alg);
        }
    } // namespace

    Algo to_algo(functions::function_id fn) noexcept
    {
        switch (fn)
        {
            case functions::function_id::linear:     return Algo::eltwise_linear;
            case functions::function_id::relu:       return Algo::eltwise_relu;
            case functions::function_id::leaky_relu: return Algo::eltwise_leaky_relu;
            case functions::function_id::gelu:       return Algo::eltwise_gelu_tanh;
            case functions::function_id::elu:        return Algo::eltwise_elu;
            case functions::function_id::sqrt:       return Algo::eltwise_sqrt;
            case functions::function_id::exp:        return Algo::eltwise_exp;
            case functions::function_id::log:        return Algo::eltwise_log;
            case functions::function_id::tanh:       return Algo::eltwise_tanh;
            case functions::function_id::sigmoid:    return Algo::eltwise_logistic;
            default:                                 return Algo::undef;
        }
    }

    PrimitiveDescriptor::PrimitiveDescriptor()
        : _impl(std::make_unique<Impl>())
    {
    }

    PrimitiveDescriptor::PrimitiveDescriptor(std::unique_ptr<Impl> impl) noexcept
        : _impl(std::move(impl))
    {
    }

    PrimitiveDescriptor PrimitiveDescriptorBuilder::make(
        dnnl::primitive_desc_base&& pd,
        PrimitiveDescriptor::Kind kind,
        Purpose purpose,
        Algo algo,
        bool has_bias)
    {
        auto impl = std::make_unique<PrimitiveDescriptor::Impl>();
        impl->pd = std::move(pd);
        impl->kind = kind;
        impl->purpose = purpose;
        impl->algo = algo;
        impl->has_bias = has_bias;
        return PrimitiveDescriptor(std::move(impl));
    }

    PrimitiveDescriptor::~PrimitiveDescriptor() = default;

    PrimitiveDescriptor::PrimitiveDescriptor(const PrimitiveDescriptor& other)
        : _impl(other._impl ? std::make_unique<Impl>(*other._impl) : std::make_unique<Impl>())
    {
    }

    PrimitiveDescriptor& PrimitiveDescriptor::operator=(const PrimitiveDescriptor& other)
    {
        if (this == &other)
            return *this;

        if (!other._impl)
            _impl = std::make_unique<Impl>();
        else if (_impl)
            *_impl = *other._impl;
        else
            _impl = std::make_unique<Impl>(*other._impl);

        return *this;
    }

    PrimitiveDescriptor::PrimitiveDescriptor(PrimitiveDescriptor&&) noexcept = default;
    PrimitiveDescriptor& PrimitiveDescriptor::operator=(PrimitiveDescriptor&&) noexcept = default;

    bool PrimitiveDescriptor::valid() const noexcept
    {
        return _impl != nullptr && static_cast<bool>(_impl->pd);
    }

    PrimitiveDescriptor::Kind PrimitiveDescriptor::kind() const noexcept
    {
        return _impl ? _impl->kind : Kind::undef;
    }

    Purpose PrimitiveDescriptor::purpose() const noexcept
    {
        return _impl ? _impl->purpose : Purpose::forward;
    }

    Algo PrimitiveDescriptor::algorithm() const noexcept
    {
        return _impl ? _impl->algo : Algo::undef;
    }

    std::string_view PrimitiveDescriptor::impl_info() const
    {
        if (!valid())
            return {};
        const char* info = _impl->pd.impl_info_str();
        return info ? std::string_view{info} : std::string_view{};
    }

    MemoryDescriptor PrimitiveDescriptor::src_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.src_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::dst_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.dst_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::weights_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.weights_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::bias_desc() const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.weights_desc(1)});
    }

    MemoryDescriptor PrimitiveDescriptor::diff_src_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.diff_src_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::diff_dst_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.diff_dst_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::diff_weights_desc(int index) const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.diff_weights_desc(index)});
    }

    MemoryDescriptor PrimitiveDescriptor::workspace_desc() const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.workspace_desc()});
    }

    MemoryDescriptor PrimitiveDescriptor::scratchpad_desc() const
    {
        if (!valid())
            return MemoryDescriptor{};
        return MemoryDescriptor(handles::__desc__{_impl->pd.scratchpad_desc()});
    }

    /* Binary */

    PrimitiveDescriptor PrimitiveDescriptor::Binary(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src0,
        const MemoryDescriptor& src1)
    {
        return create_binary(internal::engine(), alg, dst, src0, src1);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Binary(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src0,
        const MemoryDescriptor& src1)
    {
        return create_binary(engine.handle->engine, alg, dst, src0, src1);
    }

    /* Elementwise */

    PrimitiveDescriptor PrimitiveDescriptor::ElementwiseForward(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        float alpha,
        float beta,
        Purpose prop_kind)
    {
        return create_eltwise_fwd(internal::engine(), alg, dst, src, alpha, beta, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::ElementwiseForward(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        float alpha,
        float beta,
        Purpose prop_kind)
    {
        return create_eltwise_fwd(engine.handle->engine, alg, dst, src, alpha, beta, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Elementwise(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        Purpose prop_kind)
    {
        return ElementwiseForward(alg, dst, src, 0.0f, 0.0f, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Elementwise(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        float alpha,
        float beta,
        Purpose prop_kind)
    {
        return ElementwiseForward(alg, dst, src, alpha, beta, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::ElementwiseBackward(
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& data,
        const PrimitiveDescriptor& hint_fwd_pd,
        float alpha,
        float beta)
    {
        return create_eltwise_bwd(
            internal::engine(),
            alg,
            diff_src,
            diff_dst,
            data,
            hint_fwd_pd.valid() ? hint_fwd_pd._impl->pd.get() : nullptr,
            alpha,
            beta
        );
    }

    PrimitiveDescriptor PrimitiveDescriptor::ElementwiseBackward(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& data,
        const PrimitiveDescriptor& hint_fwd_pd,
        float alpha,
        float beta)
    {
        return create_eltwise_bwd(
            engine.handle->engine,
            alg,
            diff_src,
            diff_dst,
            data,
            hint_fwd_pd.valid() ? hint_fwd_pd._impl->pd.get() : nullptr,
            alpha,
            beta
        );
    }

    PrimitiveDescriptor PrimitiveDescriptor::ElementwiseBackward(
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& data,
        float alpha,
        float beta)
    {
        auto fwd_hint = ElementwiseForward(alg, data, data, alpha, beta, Purpose::forward_training);
        return ElementwiseBackward(alg, diff_src, diff_dst, data, fwd_hint, alpha, beta);
    }

    /* Matmul */

    PrimitiveDescriptor PrimitiveDescriptor::Matmul(
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        const MemoryDescriptor& weights)
    {
        return create_matmul(internal::engine(), dst, src, weights, nullptr);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Matmul(
        Engine& engine,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        const MemoryDescriptor& weights)
    {
        return create_matmul(engine.handle->engine, dst, src, weights, nullptr);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Matmul(
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        const MemoryDescriptor& weights,
        const MemoryDescriptor& bias)
    {
        return create_matmul(internal::engine(), dst, src, weights, &bias);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Matmul(
        Engine& engine,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        const MemoryDescriptor& weights,
        const MemoryDescriptor& bias)
    {
        return create_matmul(engine.handle->engine, dst, src, weights, &bias);
    }

    /* Softmax */

    PrimitiveDescriptor PrimitiveDescriptor::SoftmaxForward(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        int axis,
        Purpose prop_kind)
    {
        return create_softmax_fwd(internal::engine(), alg, dst, src, axis, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::SoftmaxForward(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        int axis,
        Purpose prop_kind)
    {
        return create_softmax_fwd(engine.handle->engine, alg, dst, src, axis, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Softmax(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        int axis,
        Purpose prop_kind)
    {
        return SoftmaxForward(alg, dst, src, axis, prop_kind);
    }

    PrimitiveDescriptor PrimitiveDescriptor::SoftmaxBackward(
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& dst,
        int axis,
        const PrimitiveDescriptor& hint_fwd_pd)
    {
        return create_softmax_bwd(
            internal::engine(),
            alg,
            diff_src,
            diff_dst,
            dst,
            axis,
            hint_fwd_pd.valid() ? hint_fwd_pd._impl->pd.get() : nullptr
        );
    }

    PrimitiveDescriptor PrimitiveDescriptor::SoftmaxBackward(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& dst,
        int axis,
        const PrimitiveDescriptor& hint_fwd_pd)
    {
        return create_softmax_bwd(
            engine.handle->engine,
            alg,
            diff_src,
            diff_dst,
            dst,
            axis,
            hint_fwd_pd.valid() ? hint_fwd_pd._impl->pd.get() : nullptr
        );
    }

    PrimitiveDescriptor PrimitiveDescriptor::SoftmaxBackward(
        Algo alg,
        const MemoryDescriptor& diff_src,
        const MemoryDescriptor& diff_dst,
        const MemoryDescriptor& dst,
        int axis)
    {
        auto fwd_hint = SoftmaxForward(alg, dst, dst, axis, Purpose::forward_training);
        return SoftmaxBackward(alg, diff_src, diff_dst, dst, axis, fwd_hint);
    }

    /* Reduction */

    PrimitiveDescriptor PrimitiveDescriptor::Reduction(
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        float p,
        float eps)
    {
        return create_reduction(internal::engine(), alg, dst, src, p, eps);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Reduction(
        Engine& engine,
        Algo alg,
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src,
        float p,
        float eps)
    {
        return create_reduction(engine.handle->engine, alg, dst, src, p, eps);
    }

    /* Reorder */

    PrimitiveDescriptor PrimitiveDescriptor::Reorder(
        const MemoryDescriptor& dst,
        const MemoryDescriptor& src)
    {
        dnnl::reorder::primitive_desc pd(
            internal::engine(),
            src.handle().desc,
            internal::engine(),
            dst.handle().desc
        );
        return make_pd(std::move(pd), Kind::reorder);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Reorder(
        Engine& dst_engine,
        const MemoryDescriptor& dst,
        Engine& src_engine,
        const MemoryDescriptor& src)
    {
        dnnl::reorder::primitive_desc pd(
            src_engine.handle->engine,
            src.handle().desc,
            dst_engine.handle->engine,
            dst.handle().desc
        );
        return make_pd(std::move(pd), Kind::reorder);
    }

    /* Sum & Concat */

    PrimitiveDescriptor PrimitiveDescriptor::Sum(
        const MemoryDescriptor& dst,
        std::span<const MemoryDescriptor> srcs,
        std::span<const float> scales)
    {
        if (srcs.empty())
            throw std::invalid_argument("PrimitiveDescriptor::Sum requires at least one source descriptor");

        std::vector<dnnl::memory::desc> dnnl_srcs;
        dnnl_srcs.reserve(srcs.size());
        for (const auto& s : srcs)
            dnnl_srcs.push_back(s.handle().desc);

        std::vector<float> scale_vec;
        if (scales.empty())
        {
            scale_vec.assign(srcs.size(), 1.0f);
        }
        else
        {
            if (scales.size() != srcs.size())
                throw std::invalid_argument("PrimitiveDescriptor::Sum: scales count must match srcs count");
            scale_vec.assign(scales.begin(), scales.end());
        }

        if (dst.valid() && dst.format() != layout::ANY)
        {
            dnnl::sum::primitive_desc pd(internal::engine(), dst.handle().desc, scale_vec, dnnl_srcs);
            return make_pd(std::move(pd), Kind::sum);
        }

        dnnl::sum::primitive_desc pd(internal::engine(), scale_vec, dnnl_srcs);
        return make_pd(std::move(pd), Kind::sum);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Sum(
        const MemoryDescriptor& dst,
        std::initializer_list<MemoryDescriptor> srcs,
        std::initializer_list<float> scales)
    {
        return Sum(
            dst,
            std::span<const MemoryDescriptor>(srcs.begin(), srcs.size()),
            std::span<const float>(scales.begin(), scales.size())
        );
    }

    PrimitiveDescriptor PrimitiveDescriptor::Concat(
        const MemoryDescriptor& dst,
        std::span<const MemoryDescriptor> srcs,
        int axis)
    {
        if (srcs.empty())
            throw std::invalid_argument("PrimitiveDescriptor::Concat requires at least one source descriptor");

        const int norm_axis = normalize_axis(axis, srcs.front().ndims());
        std::vector<dnnl::memory::desc> dnnl_srcs;
        dnnl_srcs.reserve(srcs.size());
        for (const auto& s : srcs)
            dnnl_srcs.push_back(s.handle().desc);

        if (dst.valid() && dst.format() != layout::ANY)
        {
            dnnl::concat::primitive_desc pd(internal::engine(), dst.handle().desc, norm_axis, dnnl_srcs);
            return make_pd(std::move(pd), Kind::concat);
        }

        dnnl::concat::primitive_desc pd(internal::engine(), norm_axis, dnnl_srcs);
        return make_pd(std::move(pd), Kind::concat);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Concat(
        const MemoryDescriptor& dst,
        std::initializer_list<MemoryDescriptor> srcs,
        int axis)
    {
        return Concat(dst, std::span<const MemoryDescriptor>(srcs.begin(), srcs.size()), axis);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Concat(
        std::span<const MemoryDescriptor> srcs,
        int axis)
    {
        return Concat(MemoryDescriptor{}, srcs, axis);
    }

    PrimitiveDescriptor PrimitiveDescriptor::Concat(
        std::initializer_list<MemoryDescriptor> srcs,
        int axis)
    {
        return Concat(MemoryDescriptor{}, std::span<const MemoryDescriptor>(srcs.begin(), srcs.size()), axis);
    }

} // namespace cum::neural_primitives
