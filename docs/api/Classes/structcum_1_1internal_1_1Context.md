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
| | **[Context](Classes/structcum_1_1internal_1_1Context.md#function-context)**([DEVICE](Namespaces/namespacecum.md#enum-device) device =[DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto))<br>Initializes oneAPI runtime context on the target device.  |
| | **[~Context](Classes/structcum_1_1internal_1_1Context.md#function-~context)**() |
| void | **[setDevice](Classes/structcum_1_1internal_1_1Context.md#function-setdevice)**([DEVICE](Namespaces/namespacecum.md#enum-device) device)<br>Switches the active compute hardware device.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| std::once_flag | **[initialized](Classes/structcum_1_1internal_1_1Context.md#variable-initialized)**  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[cache_size](Classes/structcum_1_1internal_1_1Context.md#variable-cache-size)**  |
| cumeric_t * | **[zeros](Classes/structcum_1_1internal_1_1Context.md#variable-zeros)**  |
| cumeric_t * | **[ones](Classes/structcum_1_1internal_1_1Context.md#variable-ones)**  |
| cumeric_t * | **[cache](Classes/structcum_1_1internal_1_1Context.md#variable-cache)**  |
| sycl::queue | **[queue](Classes/structcum_1_1internal_1_1Context.md#variable-queue)** <br>SYCL execution queue.  |
| sycl::context | **[context](Classes/structcum_1_1internal_1_1Context.md#variable-context)** <br>SYCL compute context.  |
| sycl::device | **[device](Classes/structcum_1_1internal_1_1Context.md#variable-device)** <br>SYCL selected hardware device.  |
| dnnl::engine | **[engine](Classes/structcum_1_1internal_1_1Context.md#variable-engine)** <br>oneDNN execution engine.  |
| dnnl::stream | **[stream](Classes/structcum_1_1internal_1_1Context.md#variable-stream)** <br>oneDNN command stream.  |
| oneapi::mkl::rng::device::philox4x32x10< 1 > | **[rng](Classes/structcum_1_1internal_1_1Context.md#variable-rng)** <br>[Device](Classes/structDevice.md) Philox random number generator.  |

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

[Device](Classes/structDevice.md) Philox random number generator. 

-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100