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
            handles::__engine__{dnnl::sycl_interop::make_engine(internal::device(), internal::queue().get_context())
        });
    }
} // cum