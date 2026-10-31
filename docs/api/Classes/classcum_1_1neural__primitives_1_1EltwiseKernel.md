---
title: cum::neural_primitives::EltwiseKernel
summary: Pre-compiled elementwise neural operation kernel for repeated forward/backward execution. 

---

# cum::neural_primitives::EltwiseKernel



Pre-compiled elementwise neural operation kernel for repeated forward/backward execution. 


`#include <EltwiseKernel.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[EltwiseKernel](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-eltwisekernel)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm)<br>Constructs and compiles elementwise kernel for a given descriptor and algorithm.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[warmup](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-warmup)**()<br>Warms up and compiles device kernel pipelines.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[forward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-forward)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src)<br>Executes forward pass out-of-place on Tensors.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[forward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-forward)**([Tensor](Classes/classcum_1_1Tensor.md) & src)<br>Executes forward pass in-place on [Tensor]().  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[forward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-forward)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src)<br>Executes forward pass out-of-place on [Memory]() objects.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[forward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-forward)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src)<br>Executes forward pass in-place on [Memory]() object.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[backward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-backward)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src)<br>Executes backward (gradient) pass out-of-place on Tensors.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[backward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-backward)**([Tensor](Classes/classcum_1_1Tensor.md) & src)<br>Executes backward pass in-place on [Tensor]().  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[backward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-backward)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src)<br>Executes backward pass out-of-place on [Memory]() objects.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[backward](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md#function-backward)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src)<br>Executes backward pass in-place on [Memory]() object.  |

## Public Functions Documentation

### function EltwiseKernel

```cpp
EltwiseKernel(
    const MemoryDescriptor & desc,
    functions::function_id algorithm
)
```

Constructs and compiles elementwise kernel for a given descriptor and algorithm. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor defining shape and layout. 
  * **algorithm** Activation algorithm identifier. 


### function warmup

```cpp
__event__ warmup()
```

Warms up and compiles device kernel pipelines. 

**Return**: Asynchronous execution event. 

### function forward

```cpp
__event__ forward(
    Tensor & dst,
    const Tensor & src
)
```

Executes forward pass out-of-place on Tensors. 

**Parameters**: 

  * **dst** Output tensor. 
  * **src** Input tensor. 


**Return**: Asynchronous execution event. 

### function forward

```cpp
__event__ forward(
    Tensor & src
)
```

Executes forward pass in-place on [Tensor](). 

**Parameters**: 

  * **src** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 


**Return**: Asynchronous execution event. 

### function forward

```cpp
__event__ forward(
    Memory & dst,
    const Memory & src
)
```

Executes forward pass out-of-place on [Memory]() objects. 

**Parameters**: 

  * **dst** Output memory. 
  * **src** Input memory. 


**Return**: Asynchronous execution event. 

### function forward

```cpp
__event__ forward(
    Memory & src
)
```

Executes forward pass in-place on [Memory]() object. 

**Parameters**: 

  * **src** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) modified in place. 


**Return**: Asynchronous execution event. 

### function backward

```cpp
__event__ backward(
    Tensor & dst,
    const Tensor & src
)
```

Executes backward (gradient) pass out-of-place on Tensors. 

**Parameters**: 

  * **dst** Output gradient tensor. 
  * **src** Input tensor. 


**Return**: Asynchronous execution event. 

### function backward

```cpp
__event__ backward(
    Tensor & src
)
```

Executes backward pass in-place on [Tensor](). 

**Parameters**: 

  * **src** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 


**Return**: Asynchronous execution event. 

### function backward

```cpp
__event__ backward(
    Memory & dst,
    const Memory & src
)
```

Executes backward pass out-of-place on [Memory]() objects. 

**Parameters**: 

  * **dst** Output memory. 
  * **src** Input memory. 


**Return**: Asynchronous execution event. 

### function backward

```cpp
__event__ backward(
    Memory & src
)
```

Executes backward pass in-place on [Memory]() object. 

**Parameters**: 

  * **src** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) modified in place. 


**Return**: Asynchronous execution event. 

-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100