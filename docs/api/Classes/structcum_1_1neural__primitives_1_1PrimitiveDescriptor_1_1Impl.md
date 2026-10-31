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
| dnnl::primitive_desc_base | **[pd](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/#variable-pd)**  |
| [Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#enum-kind) | **[kind](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/#variable-kind)**  |
| [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) | **[purpose](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/#variable-purpose)**  |
| [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) | **[algo](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/#variable-algo)**  |
| bool | **[has_bias](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/#variable-has-bias)**  |

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

Updated on 2026-10-31 at 18:51:12 +0100