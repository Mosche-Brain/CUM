//
// Created by jaro on 9/10/26.
//

#include <oneapi/dnnl/dnnl_sycl.hpp>

#include "cum/detail/vendor/oneapi/opaque_types.hpp"
#include "../../../../include/cum/detail/vendor/oneapi/context.hpp"

#include "cum/neural_primitives/Engine.hpp"


namespace cum::neural_primitives
{
    Engine::Engine()
    {
        this->handle = std::make_unique<handles::__engine__>(
            handles::__engine__{dnnl::sycl_interop::make_engine(internal::device(), internal::queue().get_context())}
        );
    }

    Engine::~Engine() = default;

    Engine::Engine(const Engine& other)
        : handle(other.handle ? std::make_unique<handles::__engine__>(*other.handle) : nullptr)
    {
    }

    Engine& Engine::operator=(const Engine& other)
    {
        if (this != &other)
        {
            handle = other.handle ? std::make_unique<handles::__engine__>(*other.handle) : nullptr;
        }
        return *this;
    }

    Engine::Engine(Engine&& other) noexcept = default;
    Engine& Engine::operator=(Engine&& other) noexcept = default;

    const handles::__engine__& Engine::native_handle() const
    {
        return *handle;
    }

    handles::__engine__& Engine::native_handle()
    {
        return *handle;
    }
} // cum