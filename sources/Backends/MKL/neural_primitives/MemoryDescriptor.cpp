//
// Created by jaro on 7/19/26.
//

#include <array>
#include <numeric>
#include <stdexcept>

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/detail/vendor/oneapi/opaque_types.hpp"
#include "cum/detail/vendor/oneapi/conversion_helpers.hpp"

#include "cum/neural_primitives/MemoryDescriptor.hpp"

namespace cum::neural_primitives
{
    namespace
    {
        layout infer_cum_layout(const dnnl::memory::desc& md)
        {
            if (md.is_zero())
                return layout::UNDEF;

            const auto fk = md.get_format_kind();
            if (fk == dnnl::memory::format_kind::any)
                return layout::ANY;
            if (fk != dnnl::memory::format_kind::blocked)
                return layout::ANY;

            const auto dims = md.get_dims();
            const auto dt = md.get_data_type();
            const int ndims = md.get_ndims();

            auto matches_any_of = [&](std::initializer_list<layout> candidates) -> layout {
                for (layout cand : candidates)
                {
                    dnnl::memory::desc test_md(dims, dt, dnnl_format_tag(cand), /*allow_empty=*/true);
                    if (!test_md.is_zero() && test_md == md)
                        return cand;
                }
                return layout::ANY;
            };

            switch (ndims)
            {
                case 1: return matches_any_of({layout::A});
                case 2: return matches_any_of({layout::AB, layout::BA});
                case 3: return matches_any_of({layout::ABC, layout::ACB, layout::BAC, layout::BCA, layout::CBA});
                case 4: return matches_any_of({layout::ABCD, layout::ABDC, layout::ACBD, layout::ACDB, layout::ADBC, layout::BACD, layout::BCDA, layout::CDBA, layout::DCAB});
                case 5: return matches_any_of({layout::ABCDE, layout::ABDEC, layout::ACBDE, layout::ACDEB, layout::BACDE, layout::BCDEA, layout::CDEBA, layout::DECAB, layout::ABCED});
                case 6: return matches_any_of({layout::ABCDEF, layout::ABDFCE, layout::ACBDEF, layout::ABDEFC, layout::DEFCAB, layout::ABCDFE});
                default: return layout::ANY;
            }
        }
    }

    MemoryDescriptor::MemoryDescriptor()
        : handle_(std::make_unique<handles::__desc__>(handles::__desc__{dnnl::memory::desc{}})),
          fmt(layout::UNDEF)
    {
    }

    MemoryDescriptor::MemoryDescriptor(Shape dims, datatype dtype, layout format) : fmt(format)
    {
        handle_ = std::make_unique<handles::__desc__>(
            handles::__desc__{dnnl::memory::desc(dims, dnnl_data_type(dtype), dnnl_format_tag(format))}
        );
    }

    MemoryDescriptor::MemoryDescriptor(Shape dims, datatype dtype, Shape strides)
    {
        dnnl::memory::desc md(dims, dnnl_data_type(dtype), strides);
        fmt = infer_cum_layout(md);
        handle_ = std::make_unique<handles::__desc__>(handles::__desc__{std::move(md)});
    }

    MemoryDescriptor MemoryDescriptor::Any(const Shape& dims, datatype dtype)
    {
        return MemoryDescriptor(dims, dtype, layout::ANY);
    }

    MemoryDescriptor::MemoryDescriptor(const MemoryDescriptor& other)
        : handle_(other.handle_ ? std::make_unique<handles::__desc__>(other.handle_->desc) : nullptr),
          fmt(other.fmt)
    {
    }

    MemoryDescriptor::MemoryDescriptor(const handles::__desc__& handle)
        : handle_(std::make_unique<handles::__desc__>(handle)),
          fmt(infer_cum_layout(handle.desc))
    {
    }

    MemoryDescriptor::MemoryDescriptor(const handles::__desc__& handle, layout format)
        : handle_(std::make_unique<handles::__desc__>(handle)),
          fmt(format)
    {
    }

    MemoryDescriptor::MemoryDescriptor(handles::__desc__& handle)
        : MemoryDescriptor(static_cast<const handles::__desc__&>(handle))
    {
    }

    MemoryDescriptor::MemoryDescriptor(MemoryDescriptor&&) noexcept = default;
    MemoryDescriptor& MemoryDescriptor::operator=(MemoryDescriptor&&) noexcept = default;

    MemoryDescriptor& MemoryDescriptor::operator=(const MemoryDescriptor& other)
    {
        if (this == &other)
            return *this;

        this->fmt = other.fmt;
        this->handle_ = other.handle_ ? std::make_unique<handles::__desc__>(other.handle_->desc) : nullptr;
        return *this;
    }

    MemoryDescriptor::~MemoryDescriptor() = default;

    bool MemoryDescriptor::valid() const noexcept
    {
        return handle_ != nullptr && !handle_->desc.is_zero();
    }

    dim_t MemoryDescriptor::size() const
    {
        if (!valid())
            return 0;
        return static_cast<dim_t>(handle_->desc.get_size());
    }

    dim_t MemoryDescriptor::ndims() const
    {
        if (!valid())
            return 0;
        return handle_->desc.get_ndims();
    }

    Shape MemoryDescriptor::shape() const
    {
        if (!valid())
            return {};
        return handle_->desc.get_dims();
    }

    Shape MemoryDescriptor::strides() const
    {
        if (!valid() || handle_->desc.get_format_kind() != dnnl::memory::format_kind::blocked)
            return {};
        return handle_->desc.get_strides();
    }

    datatype MemoryDescriptor::type() const
    {
        if (!valid())
            return datatype::UNDEF;
        return cum_data_type(handle_->desc.get_data_type());
    }

    const handles::__desc__& MemoryDescriptor::handle() const
    {
        return *handle_;
    }

    handles::__desc__& MemoryDescriptor::handle()
    {
        return *handle_;
    }

    layout MemoryDescriptor::format() const
    {
        return fmt;
    }

    dim_t MemoryDescriptor::stride() const
    {
        const auto s = strides();
        return s.empty() ? 0 : s.front();
    }

    dim_t MemoryDescriptor::offset() const
    {
        if (!valid())
            return 0;
        return handle_->desc.get_submemory_offset();
    }

    MemoryDescriptor MemoryDescriptor::reshape(const Shape& shape) const
    {
        dnnl::memory::desc reshaped = handle_->desc.reshape(shape);
        const layout new_fmt = infer_cum_layout(reshaped);
        return MemoryDescriptor(handles::__desc__{std::move(reshaped)}, new_fmt);
    }

    MemoryDescriptor& MemoryDescriptor::reshape_in_place(const Shape& shape)
    {
        const auto old_dims = handle_->desc.get_dims();
        const dim_t prod_new = std::accumulate(shape.begin(), shape.end(), dim_t{1}, std::multiplies<dim_t>());
        const dim_t prod_old = std::accumulate(old_dims.begin(), old_dims.end(), dim_t{1}, std::multiplies<dim_t>());

        if (prod_new != prod_old)
            throw std::runtime_error("Cannot reshape tensor: products of old and new dimensions vector aren't equal");

        dnnl::memory::desc reshaped = handle_->desc.reshape(shape);
        fmt = infer_cum_layout(reshaped);
        handle_ = std::make_unique<handles::__desc__>(handles::__desc__{std::move(reshaped)});
        return *this;
    }

    bool MemoryDescriptor::operator==(const MemoryDescriptor& other) const noexcept
    {
        if (!handle_ && !other.handle_)
            return true;
        if (!handle_ || !other.handle_)
            return false;
        return handle_->desc == other.handle_->desc;
    }

    bool MemoryDescriptor::operator!=(const MemoryDescriptor& other) const noexcept
    {
        return !(*this == other);
    }

} // namespace cum::neural_primitives
