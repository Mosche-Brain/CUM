---
title: cum::experimental::__kernel__
summary: SYCL kernel handle wrapper. 

---

# cum::experimental::__kernel__



SYCL kernel handle wrapper.  [More...](#detailed-description)


`#include <kernel.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| sycl::kernel & | **[operator()](/CUM/api/Classes/structcum_1_1experimental_1_1____kernel____/#function-operator())**()<br>Returns reference to underlying SYCL kernel.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| sycl::kernel | **[kernel](/CUM/api/Classes/structcum_1_1experimental_1_1____kernel____/#variable-kernel)** <br>Underlying SYCL kernel object.  |

## Detailed Description

```cpp
struct cum::experimental::__kernel__;
```

SYCL kernel handle wrapper. 

Opaque backend kernel handle for device kernel dispatch. 

## Public Functions Documentation

### function operator()

```cpp
sycl::kernel & operator()()
```

Returns reference to underlying SYCL kernel. 

**Return**: SYCL kernel reference. 

## Public Attributes Documentation

### variable kernel

```cpp
sycl::kernel kernel;
```

Underlying SYCL kernel object. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100