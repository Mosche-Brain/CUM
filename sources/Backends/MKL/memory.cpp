#include <sycl/sycl.hpp>

#include "../../../include/cum/detail/vendor/oneapi/context.hpp"
#include "cum/detail/vendor/oneapi/event_handler.hpp"

#include "cum/memory.hpp"

namespace cum::memory
{
    cumeric_t* allocate(dim_t size)
    {
        return sycl::malloc_shared<cumeric_t>(size, internal::getQueue());
    }

    void* allocate(const dim_t size, const datatype dtype)
    {
        return dispatch_datatype(dtype, [&]<typename T>() -> void*
        {
            return sycl::malloc_shared<T>(size, internal::getQueue());
        });
    }

    uint8_t* allocate_bytes(const dim_t size)
    {
        return sycl::malloc_shared<uint8_t>(size, internal::getQueue());
    }

    void free(void* chunk)
    {
        sycl::free(chunk, internal::getQueue());
    }

    __event__ memcopy(void* dst, const void* src, const dim_t size)
    {
        sycl::event event = internal::getQueue().memcpy(dst, src, size);

        return detail::event_handler::create(std::move(event));
    }

    __event__ prefetch(void* chunk, dim_t size)
    {
        sycl::event event = internal::getQueue().prefetch(chunk, size);

        return detail::event_handler::create(std::move(event));
    }
}
