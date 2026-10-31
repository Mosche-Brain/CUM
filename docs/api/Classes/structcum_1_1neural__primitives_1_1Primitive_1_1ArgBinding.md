---
title: cum::neural_primitives::Primitive::ArgBinding
summary: Zero-copy argument binding pairing an Argument slot with a Memory or Tensor reference. 

---

# cum::neural_primitives::Primitive::ArgBinding



Zero-copy argument binding pairing an [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) slot with a [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) or [Tensor]() reference. 


`#include <Primitive.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/#function-argbinding)**([Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) a, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & m) |
| | **[ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/#function-argbinding)**([Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) a, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & t) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) | **[arg](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/#variable-arg)**  |
| const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) * | **[memory](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/#variable-memory)**  |

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

Updated on 2026-10-31 at 18:51:12 +0100