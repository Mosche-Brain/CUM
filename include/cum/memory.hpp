/**
 * @file memory.hpp
 * @brief Memory allocation, deallocation, copying, and prefetching routines for host and device memory.
 * @details Provides unified device memory management functions supporting USM (Unified Shared Memory),
 *          typed and generic allocations, and asynchronous copy/prefetch events.
 */

#pragma once

#include "cum/Core.hpp"

namespace cum::memory
{
    /**
     * @brief Allocates device memory for an array of elements of default numeric type @ref cumeric_t.
     * @param size Number of elements to allocate.
     * @return Pointer to the allocated memory buffer.
     */
    cumeric_t* allocate(dim_t size);

    /**
     * @brief Allocates raw byte storage in device memory.
     * @param size Number of bytes to allocate.
     * @return Pointer to the allocated byte array.
     */
    uint8* allocate_bytes(dim_t size);

    /**
     * @brief Allocates device memory buffer for elements of the specified runtime datatype.
     * @param size Number of elements to allocate.
     * @param dtype Runtime datatype tag determining the element size.
     * @return Untyped pointer to the allocated memory chunk.
     */
    void* allocate(dim_t size, datatype dtype);

    /**
     * @brief Frees a previously allocated device memory chunk.
     * @param chunk Pointer to the memory buffer to release.
     */
    void free(void* chunk);

    /**
     * @brief Asynchronously copies memory between memory regions.
     * @param dst Destination memory buffer pointer.
     * @param src Source memory buffer pointer.
     * @param size Number of bytes to copy.
     * @return Asynchronous execution event handle.
     */
    __event__ memcopy(void* dst, const void* src, dim_t size);

    /**
     * @brief Asynchronously prefetches device memory to the active device.
     * @param chunk Pointer to the memory buffer to prefetch.
     * @param size Number of bytes to prefetch.
     * @return Asynchronous execution event handle.
     */
    __event__ prefetch(void* chunk, dim_t size);

    /**
     * @brief Allocates device memory for an array of elements of static type @p T.
     * @tparam T The element type.
     * @param size Number of elements of type @p T to allocate.
     * @return Pointer of type @p T* to the allocated memory.
     */
    template <typename T>
    T* allocate(dim_t size)
    {
        return static_cast<T*>(static_cast<void*>(allocate_bytes(size * static_cast<dim_t>(sizeof(T)))));
    }
}
