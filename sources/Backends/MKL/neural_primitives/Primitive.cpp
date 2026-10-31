/**
 * @file Primitive.cpp
 * @brief oneDNN SYCL execution implementation for cum::neural_primitives::Primitive.
 * @author jaro
 */

#include <array>
#include <stdexcept>
#include <vector>

#include <oneapi/dnnl/dnnl.hpp>
#include <oneapi/dnnl/dnnl_sycl.hpp>

#include "cum/Tensor.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"
#include "cum/detail/vendor/oneapi/opaque_types.hpp"
#include "cum/detail/vendor/oneapi/primitive_descriptors_handles.hpp"

#include "cum/neural_primitives/Primitive.hpp"

namespace cum::neural_primitives
{
    namespace
    {
        int to_dnnl_arg(Primitive::Argument arg)
        {
            const int raw = static_cast<int>(arg);
            if (raw >= static_cast<int>(Primitive::Argument::multiple_src))
            {
                const int offset = raw - static_cast<int>(Primitive::Argument::multiple_src);
                return DNNL_ARG_MULTIPLE_SRC + offset;
            }

            switch (arg)
            {
                case Primitive::Argument::src0:         return DNNL_ARG_SRC_0;
                case Primitive::Argument::src1:         return DNNL_ARG_SRC_1;
                case Primitive::Argument::src2:         return DNNL_ARG_SRC_2;
                case Primitive::Argument::src3:         return DNNL_ARG_SRC_3;
                case Primitive::Argument::dst0:         return DNNL_ARG_DST_0;
                case Primitive::Argument::weights:      return DNNL_ARG_WEIGHTS;
                case Primitive::Argument::bias:         return DNNL_ARG_BIAS;
                case Primitive::Argument::workspace:    return DNNL_ARG_WORKSPACE;
                case Primitive::Argument::scratchpad:   return DNNL_ARG_SCRATCHPAD;
                case Primitive::Argument::diff_src0:    return DNNL_ARG_DIFF_SRC_0;
                case Primitive::Argument::diff_src1:    return DNNL_ARG_DIFF_SRC_1;
                case Primitive::Argument::diff_dst:     return DNNL_ARG_DIFF_DST;
                case Primitive::Argument::diff_weights: return DNNL_ARG_DIFF_WEIGHTS;
                case Primitive::Argument::diff_bias:    return DNNL_ARG_DIFF_BIAS;
                default:
                    throw std::invalid_argument("Unsupported Primitive::Argument slot");
            }
        }

        const Memory& require_tensor_memory(const Tensor& t, const char* role)
        {
            const auto& mem_ptr = t.memory();
            if (!mem_ptr || !mem_ptr->valid())
                throw std::invalid_argument(std::string("Tensor passed as '") + role + "' has no allocated Memory");
            return *mem_ptr;
        }

        Memory& require_tensor_memory_mut(Tensor& t, const char* role)
        {
            auto& mem_ptr = t.memory();
            if (!mem_ptr || !mem_ptr->valid())
                throw std::invalid_argument(std::string("Tensor passed as '") + role + "' has no allocated Memory");
            return *mem_ptr;
        }

        __event__ submit_exec_args(
            const dnnl::primitive& prim,
            const dnnl_exec_arg_t* c_args,
            int nargs,
            const __events__& deps)
        {
            std::vector<sycl::event> sycl_deps;
            if (!deps.empty())
            {
                sycl_deps.reserve(deps.size());
                for (const auto& ev_ref : deps)
                {
                    const __event__& ev = ev_ref.get();
                    if (cum::detail::event_handler::valid(ev))
                        sycl_deps.push_back(cum::detail::event_handler::handle(ev));
                }
            }

            sycl::event out_event;
            const dnnl_status_t status = dnnl_sycl_interop_primitive_execute(
                prim.get(),
                internal::stream().get(),
                nargs,
                c_args,
                &sycl_deps,
                &out_event
            );
            dnnl::error::wrap_c_api(status, "Failed to execute neural primitive on SYCL stream");
            return cum::detail::event_handler::create(std::move(out_event));
        }
    } // namespace

    struct Primitive::Impl
    {
        dnnl::primitive primitive{};
        Descriptor desc{};
    };

    Primitive::ArgBinding::ArgBinding(Argument a, const Tensor& t)
        : arg(a), memory(&require_tensor_memory(t, "ArgBinding"))
    {
    }

    Primitive::Primitive()
        : impl(std::make_unique<Impl>())
    {
    }

    Primitive::Primitive(const Descriptor& descriptor)
        : impl(std::make_unique<Impl>())
    {
        compile(descriptor);
    }

    Primitive::Primitive(const Primitive& other)
        : impl(other.impl ? std::make_unique<Impl>(*other.impl) : std::make_unique<Impl>())
    {
    }

    Primitive& Primitive::operator=(const Primitive& other)
    {
        if (this == &other)
            return *this;

        if (!other.impl)
            impl = std::make_unique<Impl>();
        else if (impl)
            *impl = *other.impl;
        else
            impl = std::make_unique<Impl>(*other.impl);

        return *this;
    }

    Primitive::Primitive(Primitive&& other) noexcept = default;
    Primitive& Primitive::operator=(Primitive&& other) noexcept = default;

    Primitive::~Primitive() = default;

    void Primitive::compile(const Descriptor& descriptor)
    {
        if (!descriptor.valid())
            throw std::invalid_argument("Cannot compile Primitive from an empty or invalid PrimitiveDescriptor");

        if (!impl)
            impl = std::make_unique<Impl>();

        impl->desc = descriptor;
        impl->primitive = dnnl::primitive(descriptor._impl->pd.get());
    }

    void Primitive::compile()
    {
        if (!impl || !impl->desc.valid())
            throw std::runtime_error("Cannot call Primitive::compile() without a valid PrimitiveDescriptor");

        if (!impl->primitive)
            impl->primitive = dnnl::primitive(impl->desc._impl->pd.get());
    }

    bool Primitive::valid() const noexcept
    {
        return impl != nullptr && static_cast<bool>(impl->primitive);
    }

    Primitive::Kind Primitive::kind() const noexcept
    {
        return impl ? impl->desc.kind() : Kind::undef;
    }

    const Primitive::Descriptor& Primitive::descriptor() const
    {
        if (!impl)
            throw std::runtime_error("Moved-from Primitive has no descriptor");
        return impl->desc;
    }

    __event__ Primitive::execute(std::span<const ArgBinding> args, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");

        constexpr std::size_t kStackCap = 8;
        std::array<dnnl_exec_arg_t, kStackCap> stack_args{};
        std::vector<dnnl_exec_arg_t> heap_args;

        dnnl_exec_arg_t* out = stack_args.data();
        if (args.size() > kStackCap)
        {
            heap_args.resize(args.size());
            out = heap_args.data();
        }

        for (std::size_t i = 0; i < args.size(); ++i)
        {
            const auto& binding = args[i];
            if (!binding.memory || !binding.memory->valid())
                throw std::invalid_argument("Null or uninitialized Memory bound to Primitive::execute");
            out[i] = dnnl_exec_arg_t{to_dnnl_arg(binding.arg), binding.memory->handle().memory.get()};
        }

        return submit_exec_args(impl->primitive, out, static_cast<int>(args.size()), deps);
    }

    __event__ Primitive::execute(std::initializer_list<ArgBinding> args, const __events__& deps) const
    {
        return execute(std::span<const ArgBinding>(args.begin(), args.size()), deps);
    }

    __event__ Primitive::execute(const KVMap& kv_map, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");

        std::vector<dnnl_exec_arg_t> c_args;
        c_args.reserve(kv_map.size());
        for (const auto& [arg, mem] : kv_map)
        {
            if (!mem.valid())
                throw std::invalid_argument("Uninitialized Memory in KVMap passed to Primitive::execute");
            c_args.push_back(dnnl_exec_arg_t{to_dnnl_arg(arg), mem.handle().memory.get()});
        }

        return submit_exec_args(impl->primitive, c_args.data(), static_cast<int>(c_args.size()), deps);
    }

    __event__ Primitive::execute(Memory& dst, const Memory& arg0, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");
        if (!dst.valid() || !arg0.valid())
            throw std::invalid_argument("Uninitialized Memory passed to unary Primitive::execute");

        const auto k = impl->desc.kind();
        if (detail::is_backward_purpose(impl->desc.purpose()))
            throw std::invalid_argument("Backward primitive requires 2 inputs (diff_dst and forward src/dst)");

        int src_slot = DNNL_ARG_SRC_0;
        if (k == Kind::sum || k == Kind::concat)
            src_slot = DNNL_ARG_MULTIPLE_SRC + 0;

        const std::array<dnnl_exec_arg_t, 2> c_args{{
            {DNNL_ARG_DST, dst.handle().memory.get()},
            {src_slot, arg0.handle().memory.get()}
        }};
        return submit_exec_args(impl->primitive, c_args.data(), 2, deps);
    }

    __event__ Primitive::execute(Memory& dst, const Memory& arg0, const Memory& arg1, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");
        if (!dst.valid() || !arg0.valid() || !arg1.valid())
            throw std::invalid_argument("Uninitialized Memory passed to 2-input Primitive::execute");

        const auto k = impl->desc.kind();
        const bool is_bwd = detail::is_backward_purpose(impl->desc.purpose());

        std::array<dnnl_exec_arg_t, 3> c_args{};
        switch (k)
        {
            case Kind::binary:
                c_args = {{
                    {DNNL_ARG_DST, dst.handle().memory.get()},
                    {DNNL_ARG_SRC_0, arg0.handle().memory.get()},
                    {DNNL_ARG_SRC_1, arg1.handle().memory.get()}
                }};
                break;

            case Kind::matmul:
                c_args = {{
                    {DNNL_ARG_DST, dst.handle().memory.get()},
                    {DNNL_ARG_SRC, arg0.handle().memory.get()},
                    {DNNL_ARG_WEIGHTS, arg1.handle().memory.get()}
                }};
                break;

            case Kind::elementwise:
                if (!is_bwd)
                    throw std::invalid_argument("Forward Elementwise primitive is unary; pass (dst, src)");
                c_args = {{
                    {DNNL_ARG_DIFF_SRC, dst.handle().memory.get()},
                    {DNNL_ARG_DIFF_DST, arg0.handle().memory.get()},
                    {detail::uses_dst_for_bwd(impl->desc.algorithm()) ? DNNL_ARG_DST : DNNL_ARG_SRC,
                     arg1.handle().memory.get()}
                }};
                break;

            case Kind::softmax:
                if (!is_bwd)
                    throw std::invalid_argument("Forward Softmax primitive is unary; pass (dst, src)");
                c_args = {{
                    {DNNL_ARG_DIFF_SRC, dst.handle().memory.get()},
                    {DNNL_ARG_DIFF_DST, arg0.handle().memory.get()},
                    {DNNL_ARG_DST, arg1.handle().memory.get()}
                }};
                break;

            case Kind::sum:
            case Kind::concat:
                c_args = {{
                    {DNNL_ARG_DST, dst.handle().memory.get()},
                    {DNNL_ARG_MULTIPLE_SRC + 0, arg0.handle().memory.get()},
                    {DNNL_ARG_MULTIPLE_SRC + 1, arg1.handle().memory.get()}
                }};
                break;

            default:
                throw std::invalid_argument("2-input positional Primitive::execute is not valid for this primitive kind");
        }

        return submit_exec_args(impl->primitive, c_args.data(), 3, deps);
    }

    __event__ Primitive::execute(Memory& dst, const Memory& arg0, const Memory& arg1, const Memory& arg2, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");
        if (!dst.valid() || !arg0.valid() || !arg1.valid() || !arg2.valid())
            throw std::invalid_argument("Uninitialized Memory passed to 3-input Primitive::execute");

        const auto k = impl->desc.kind();
        std::array<dnnl_exec_arg_t, 4> c_args{};

        switch (k)
        {
            case Kind::matmul:
                c_args = {{
                    {DNNL_ARG_DST, dst.handle().memory.get()},
                    {DNNL_ARG_SRC, arg0.handle().memory.get()},
                    {DNNL_ARG_WEIGHTS, arg1.handle().memory.get()},
                    {DNNL_ARG_BIAS, arg2.handle().memory.get()}
                }};
                break;

            case Kind::sum:
            case Kind::concat:
                c_args = {{
                    {DNNL_ARG_DST, dst.handle().memory.get()},
                    {DNNL_ARG_MULTIPLE_SRC + 0, arg0.handle().memory.get()},
                    {DNNL_ARG_MULTIPLE_SRC + 1, arg1.handle().memory.get()},
                    {DNNL_ARG_MULTIPLE_SRC + 2, arg2.handle().memory.get()}
                }};
                break;

            default:
                throw std::invalid_argument("3-input positional Primitive::execute is only supported for Matmul (with bias), Sum, and Concat");
        }

        return submit_exec_args(impl->primitive, c_args.data(), 4, deps);
    }

    __event__ Primitive::execute(Memory& dst, std::span<const Memory> srcs, const __events__& deps) const
    {
        if (!valid())
            throw std::runtime_error("Cannot execute an uncompiled or empty Primitive");
        if (!dst.valid())
            throw std::invalid_argument("Uninitialized destination Memory passed to Primitive::execute");

        std::vector<dnnl_exec_arg_t> c_args;
        c_args.reserve(srcs.size() + 1);
        c_args.push_back(dnnl_exec_arg_t{DNNL_ARG_DST, dst.handle().memory.get()});
        for (std::size_t i = 0; i < srcs.size(); ++i)
        {
            if (!srcs[i].valid())
                throw std::invalid_argument("Uninitialized source Memory in span passed to Primitive::execute");
            c_args.push_back(dnnl_exec_arg_t{DNNL_ARG_MULTIPLE_SRC + static_cast<int>(i), srcs[i].handle().memory.get()});
        }

        return submit_exec_args(impl->primitive, c_args.data(), static_cast<int>(c_args.size()), deps);
    }

    __event__ Primitive::execute(Tensor& dst, const Tensor& arg0, const __events__& deps) const
    {
        return execute(
            require_tensor_memory_mut(dst, "dst"),
            require_tensor_memory(arg0, "arg0"),
            deps
        );
    }

    __event__ Primitive::execute(Tensor& dst, const Tensor& arg0, const Tensor& arg1, const __events__& deps) const
    {
        return execute(
            require_tensor_memory_mut(dst, "dst"),
            require_tensor_memory(arg0, "arg0"),
            require_tensor_memory(arg1, "arg1"),
            deps
        );
    }

    __event__ Primitive::execute(Tensor& dst, const Tensor& arg0, const Tensor& arg1, const Tensor& arg2, const __events__& deps) const
    {
        return execute(
            require_tensor_memory_mut(dst, "dst"),
            require_tensor_memory(arg0, "arg0"),
            require_tensor_memory(arg1, "arg1"),
            require_tensor_memory(arg2, "arg2"),
            deps
        );
    }

} // namespace cum::neural_primitives
