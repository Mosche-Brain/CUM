---
title: cum::neural_primitives::PrimitiveDescriptor::Impl
summary: Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp. 

---

# cum::neural_primitives::PrimitiveDescriptor::Impl



Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp.  [More...](#detailed-description)


`#include <primitive_descriptors_handles.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| dnnl::primitive_desc_base | **[pd](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md#variable-pd)**  |
| [Kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#enum-kind) | **[kind](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md#variable-kind)**  |
| [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) | **[purpose](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md#variable-purpose)**  |
| [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) | **[algo](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md#variable-algo)**  |
| bool | **[has_bias](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md#variable-has-bias)**  |

## Detailed Description

```cpp
struct cum::neural_primitives::PrimitiveDescriptor::Impl;
```

Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp. 

`dnnl::primitive_desc_base` wraps the refcounted C `dnnl_primitive_desc_t` handle without slicing. 

## Public Attributes Documentation

### variable pd

```cpp
dnnl::primitive_desc_base pd {};
```


### variable kind

```cpp
Kind kind = Kind::undef;
```


### variable purpose

```cpp
Purpose purpose = Purpose::forward;
```


### variable algo

```cpp
Algo algo = Algo::undef;
```


### variable has_bias

```cpp
bool has_bias = false;
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100