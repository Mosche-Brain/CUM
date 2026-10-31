---
title: cum::internal::Context
summary: Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends. 

---

# cum::internal::Context



Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends. 


`#include <context.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Context](/CUM/api/Classes/structcum_1_1internal_1_1Context/#function-context)**([DEVICE](/CUM/api/Namespaces/namespacecum/#enum-device) device =[DEVICE::AUTO](/CUM/api/Namespaces/namespacecum/#enumvalue-auto))<br>Initializes oneAPI runtime context on the target device.  |
| | **[~Context](/CUM/api/Classes/structcum_1_1internal_1_1Context/#function-~context)**() |
| void | **[setDevice](/CUM/api/Classes/structcum_1_1internal_1_1Context/#function-setdevice)**([DEVICE](/CUM/api/Namespaces/namespacecum/#enum-device) device)<br>Switches the active compute hardware device.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| std::once_flag | **[initialized](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-initialized)**  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[cache_size](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-cache-size)**  |
| cumeric_t * | **[zeros](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-zeros)**  |
| cumeric_t * | **[ones](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-ones)**  |
| cumeric_t * | **[cache](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-cache)**  |
| sycl::queue | **[queue](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-queue)** <br>SYCL execution queue.  |
| sycl::context | **[context](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-context)** <br>SYCL compute context.  |
| sycl::device | **[device](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-device)** <br>SYCL selected hardware device.  |
| dnnl::engine | **[engine](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-engine)** <br>oneDNN execution engine.  |
| dnnl::stream | **[stream](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-stream)** <br>oneDNN command stream.  |
| oneapi::mkl::rng::device::philox4x32x10< 1 > | **[rng](/CUM/api/Classes/structcum_1_1internal_1_1Context/#variable-rng)** <br>[Device](/CUM/api/Classes/structDevice/) Philox random number generator.  |

## Public Functions Documentation

### function Context

```cpp
explicit Context(
    DEVICE device =DEVICE::AUTO
)
```

Initializes oneAPI runtime context on the target device. 

**Parameters**: 

  * **device** Compute device selector. 


### function ~Context

```cpp
~Context()
```


### function setDevice

```cpp
void setDevice(
    DEVICE device
)
```

Switches the active compute hardware device. 

**Parameters**: 

  * **device** Target device. 


## Public Attributes Documentation

### variable initialized

```cpp
std::once_flag initialized;
```


### variable cache_size

```cpp
dim_t cache_size;
```


### variable zeros

```cpp
cumeric_t * zeros;
```


### variable ones

```cpp
cumeric_t * ones;
```


### variable cache

```cpp
cumeric_t * cache;
```


### variable queue

```cpp
sycl::queue queue;
```

SYCL execution queue. 

### variable context

```cpp
sycl::context context;
```

SYCL compute context. 

### variable device

```cpp
sycl::device device;
```

SYCL selected hardware device. 

### variable engine

```cpp
dnnl::engine engine;
```

oneDNN execution engine. 

### variable stream

```cpp
dnnl::stream stream;
```

oneDNN command stream. 

### variable rng

```cpp
oneapi::mkl::rng::device::philox4x32x10< 1 > rng;
```

[Device](/CUM/api/Classes/structDevice/) Philox random number generator. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100