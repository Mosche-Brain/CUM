---
title: cum::memory

---

# cum::memory



## Functions

|                | Name           |
| -------------- | -------------- |
| cumeric_t * | **[allocate](/CUM/api/Namespaces/namespacecum_1_1memory/#function-allocate)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size)<br>Allocates device memory for an array of elements of default numeric type cumeric_t.  |
| [uint8](/CUM/api/Namespaces/namespacecum/#using-uint8) * | **[allocate_bytes](/CUM/api/Namespaces/namespacecum_1_1memory/#function-allocate-bytes)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size)<br>Allocates raw byte storage in device memory.  |
| void * | **[allocate](/CUM/api/Namespaces/namespacecum_1_1memory/#function-allocate)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size, [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype)<br>Allocates device memory buffer for elements of the specified runtime datatype.  |
| void | **[free](/CUM/api/Namespaces/namespacecum_1_1memory/#function-free)**(void * chunk)<br>Frees a previously allocated device memory chunk.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[memcopy](/CUM/api/Namespaces/namespacecum_1_1memory/#function-memcopy)**(void * dst, const void * src, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size)<br>Asynchronously copies memory between memory regions.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[prefetch](/CUM/api/Namespaces/namespacecum_1_1memory/#function-prefetch)**(void * chunk, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size)<br>Asynchronously prefetches device memory to the active device.  |
| template <typename T \> <br>T * | **[allocate](/CUM/api/Namespaces/namespacecum_1_1memory/#function-allocate)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) size)<br>Allocates device memory for an array of elements of static type `T`.  |


## Functions Documentation

### function allocate

```cpp
cumeric_t * allocate(
    dim_t size
)
```

Allocates device memory for an array of elements of default numeric type cumeric_t. 

**Parameters**: 

  * **size** Number of elements to allocate. 


**Return**: Pointer to the allocated memory buffer. 

### function allocate_bytes

```cpp
uint8 * allocate_bytes(
    dim_t size
)
```

Allocates raw byte storage in device memory. 

**Parameters**: 

  * **size** Number of bytes to allocate. 


**Return**: Pointer to the allocated byte array. 

### function allocate

```cpp
void * allocate(
    dim_t size,
    datatype dtype
)
```

Allocates device memory buffer for elements of the specified runtime datatype. 

**Parameters**: 

  * **size** Number of elements to allocate. 
  * **dtype** Runtime datatype tag determining the element size. 


**Return**: Untyped pointer to the allocated memory chunk. 

### function free

```cpp
void free(
    void * chunk
)
```

Frees a previously allocated device memory chunk. 

**Parameters**: 

  * **chunk** Pointer to the memory buffer to release. 


### function memcopy

```cpp
__event__ memcopy(
    void * dst,
    const void * src,
    dim_t size
)
```

Asynchronously copies memory between memory regions. 

**Parameters**: 

  * **dst** Destination memory buffer pointer. 
  * **src** Source memory buffer pointer. 
  * **size** Number of bytes to copy. 


**Return**: Asynchronous execution event handle. 

### function prefetch

```cpp
__event__ prefetch(
    void * chunk,
    dim_t size
)
```

Asynchronously prefetches device memory to the active device. 

**Parameters**: 

  * **chunk** Pointer to the memory buffer to prefetch. 
  * **size** Number of bytes to prefetch. 


**Return**: Asynchronous execution event handle. 

### function allocate

```cpp
template <typename T >
T * allocate(
    dim_t size
)
```

Allocates device memory for an array of elements of static type `T`. 

**Parameters**: 

  * **size** Number of elements of type `T` to allocate. 


**Template Parameters**: 

  * **T** The element type. 


**Return**: Pointer of type `T*` to the allocated memory. 





-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100