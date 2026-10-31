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
| | **[EltwiseKernel](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-eltwisekernel)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & desc, [functions::function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) algorithm)<br>Constructs and compiles elementwise kernel for a given descriptor and algorithm.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[warmup](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-warmup)**()<br>Warms up and compiles device kernel pipelines.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[forward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-forward)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & dst, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & src)<br>Executes forward pass out-of-place on Tensors.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[forward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-forward)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & src)<br>Executes forward pass in-place on [Tensor]().  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[forward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-forward)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & src)<br>Executes forward pass out-of-place on [Memory]() objects.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[forward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-forward)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & src)<br>Executes forward pass in-place on [Memory]() object.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[backward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-backward)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & dst, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & src)<br>Executes backward (gradient) pass out-of-place on Tensors.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[backward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-backward)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & src)<br>Executes backward pass in-place on [Tensor]().  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[backward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-backward)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & src)<br>Executes backward pass out-of-place on [Memory]() objects.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[backward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/#function-backward)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & src)<br>Executes backward pass in-place on [Memory]() object.  |

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

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor defining shape and layout. 
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

  * **src** [Tensor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Tensor/) modified in place. 


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

  * **src** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) modified in place. 


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

  * **src** [Tensor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Tensor/) modified in place. 


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

  * **src** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) modified in place. 


**Return**: Asynchronous execution event. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100