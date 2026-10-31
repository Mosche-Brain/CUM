---
title: cum::neural_primitives::Primitive::ArgBinding
summary: Zero-copy argument binding pairing an Argument slot with a Memory or Tensor reference. 

---

# cum::neural_primitives::Primitive::ArgBinding



Zero-copy argument binding pairing an [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) slot with a [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) or [Tensor]() reference. 


`#include <Primitive.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md#function-argbinding)**([Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) a, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & m) |
| | **[ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md#function-argbinding)**([Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) a, const [Tensor](Classes/classcum_1_1Tensor.md) & t) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) | **[arg](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md#variable-arg)**  |
| const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) * | **[memory](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md#variable-memory)**  |

## Public Functions Documentation

### function ArgBinding

```cpp
inline constexpr ArgBinding(
    Argument a,
    const Memory & m
)
```


### function ArgBinding

```cpp
ArgBinding(
    Argument a,
    const Tensor & t
)
```


## Public Attributes Documentation

### variable arg

```cpp
Argument arg;
```


### variable memory

```cpp
const Memory * memory = nullptr;
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100