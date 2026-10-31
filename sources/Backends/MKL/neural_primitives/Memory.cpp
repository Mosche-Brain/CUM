//
// Created by jaro on 7/19/26.
//

#include <cstddef>
#include <new>
#include <stdexcept>

#include <sycl/sycl.hpp>
#include <oneapi/dnnl/dnnl_sycl.hpp>

#include "cum/detail/vendor/oneapi/opaque_types.hpp"
#include "cum/detail/vendor/oneapi/context.hpp"

#include "cum/neural_primitives/Memory.hpp"

namespace cum::neural_primitives
{
    namespace
    {
        std::shared_ptr<handles::__memory__> allocate_usm_memory(const dnnl::memory::desc& md, const dnnl::engine& eng)
        {
            const std::size_t bytes = md.get_size();
            if (bytes == 0)
            {
                return std::make_shared<handles::__memory__>(handles::__memory__{
                    dnnl::sycl_interop::make_memory(md, eng, dnnl::sycl_interop::memory_kind::usm, nullptr),
                    nullptr
                });
            }

            sycl::context ctx = dnnl::sycl_interop::get_context(eng);
            sycl::device dev = dnnl::sycl_interop::get_device(eng);
            void* raw = sycl::malloc_shared(bytes, dev, ctx);
            if (!raw)
                throw std::bad_alloc();

            std::shared_ptr<void> owned(raw, [ctx](void* p) noexcept {
                if (p)
                    sycl::free(p, ctx);
            });

            return std::make_shared<handles::__memory__>(handles::__memory__{
                dnnl::sycl_interop::make_memory(md, eng, dnnl::sycl_interop::memory_kind::usm, raw),
                std::move(owned)
            });
        }
    }

    Memory::Memory() = default;

    Memory::Memory(const Descriptor& desc)
        : handle_(allocate_usm_memory(desc.handle_->desc, internal::engine()))
    {
    }

    Memory::Memory(const Descriptor& desc, void* data)
        : handle_(std::make_shared<handles::__memory__>(handles::__memory__{
              dnnl::sycl_interop::make_memory(desc.handle_->desc, internal::engine(), dnnl::sycl_interop::memory_kind::usm, data),
              nullptr
          }))
    {
    }

    Memory::Memory(const Descriptor& desc, Engine& engine)
        : handle_(allocate_usm_memory(desc.handle_->desc, engine.handle->engine))
    {
    }

    Memory::Memory(const Descriptor& desc, Engine& engine, void* data)
        : handle_(std::make_shared<handles::__memory__>(handles::__memory__{
              dnnl::sycl_interop::make_memory(desc.handle_->desc, engine.handle->engine, dnnl::sycl_interop::memory_kind::usm, data),
              nullptr
          }))
    {
    }

    Memory::Memory(const Descriptor& desc, const Memory& source)
        : owner_(source.owner())
    {
        void* data = owner_ ? owner_->memory.get_data_handle() : nullptr;
        handle_ = std::make_shared<handles::__memory__>(handles::__memory__{
            dnnl::sycl_interop::make_memory(desc.handle_->desc, internal::engine(), dnnl::sycl_interop::memory_kind::usm, data),
            nullptr
        });
    }

    Memory::Memory(const handles::__memory__& handle)
        : handle_(std::make_shared<handles::__memory__>(handle))
    {
    }

    Memory::Memory(handles::__memory__& handle)
        : Memory(static_cast<const handles::__memory__&>(handle))
    {
    }

    Memory::Memory(const Memory& other) = default;
    Memory& Memory::operator=(const Memory& other) = default;

    Memory::Memory(Memory&& other) noexcept = default;
    Memory& Memory::operator=(Memory&& other) noexcept = default;

    Memory::~Memory() = default;

    bool Memory::valid() const noexcept
    {
        return handle_ != nullptr && static_cast<bool>(handle_->memory);
    }

    Memory::Descriptor Memory::descriptor() const
    {
        if (!valid())
            return Descriptor{};
        return Descriptor(handles::__desc__{handle_->memory.get_desc()});
    }

    void* Memory::data()
    {
        if (!valid())
            return nullptr;
        return handle_->memory.get_data_handle();
    }

    const void* Memory::data() const
    {
        if (!valid())
            return nullptr;
        return handle_->memory.get_data_handle();
    }

    void Memory::set_data(void* data)
    {
        if (!valid())
            throw std::runtime_error("Cannot call set_data on an uninitialized Memory object");
        handle_->owned_usm.reset();
        handle_->memory.set_data_handle(data);
    }

    const handles::__memory__& Memory::handle() const
    {
        return *handle_;
    }

    handles::__memory__& Memory::handle()
    {
        return *handle_;
    }

    std::shared_ptr<handles::__memory__> Memory::owner() const
    {
        return owner_ ? owner_ : handle_;
    }

} // namespace cum::neural_primitives
