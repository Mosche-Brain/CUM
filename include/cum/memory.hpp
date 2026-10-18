#pragma once

#include "cum/Core.hpp"

namespace cum::memory
{
    cumeric_t* allocate(dim_t size);

    uint8* allocate_bytes(dim_t size);

    void* allocate(dim_t size, datatype dtype);

    void free(void* chunk);

    __event__ memcopy(void* dst, const void* src, dim_t size);
    __event__ prefetch(void* chunk, dim_t size);

    template <typename T>
    T* allocate(dim_t size)
    {
        return static_cast<T*>(static_cast<void*>(allocate_bytes(size * static_cast<dim_t>(sizeof(T)))));
    }
}