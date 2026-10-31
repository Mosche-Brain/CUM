---
title: cum::neural_primitives::handles::__memory__
summary: Underlying oneDNN memory wrapper with optional USM shared ownership. 

---

# cum::neural_primitives::handles::__memory__



Underlying oneDNN memory wrapper with optional USM shared ownership. 


`#include <opaque_types.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| dnnl::memory | **[memory](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md#variable-memory)**  |
| std::shared_ptr< void > | **[owned_usm](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md#variable-owned-usm)**  |

## Public Attributes Documentation

### variable memory

```cpp
dnnl::memory memory;
```


### variable owned_usm

```cpp
std::shared_ptr< void > owned_usm = nullptr;
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100