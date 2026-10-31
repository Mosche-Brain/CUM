---
title: include/cum/datatypes.hpp
summary: Datatype definitions, precision aliases, and type tagging utilities for CUM. 

---

# include/cum/datatypes.hpp

Datatype definitions, precision aliases, and type tagging utilities for CUM.  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cum](/CUM/api/Namespaces/namespacecum/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[fp8_e4_3m_impl](/CUM/api/Classes/structfp8__e4__3m__impl/)** <br>8-bit floating point emulation structure (E4M3 format representation).  |
| struct | **[cum::float16](/CUM/api/Classes/structcum_1_1float16/)** <br>Raw 16-bit fallback for half precision float.  |
| struct | **[cum::bfloat16](/CUM/api/Classes/structcum_1_1bfloat16/)** <br>Raw 16-bit fallback for [bfloat16]() precision float.  |

## Types

|                | Name           |
| -------------- | -------------- |
| typedef struct fp8_e4_3m_impl | **[fp8_e4_3m_impl](/CUM/api/Files/datatypes_8hpp/#typedef-fp8-e4-3m-impl)**  |

## Detailed Description

Datatype definitions, precision aliases, and type tagging utilities for CUM. 

**Author**: Świadomy Mężczyzna


Provides fixed-width floating point and integer aliases, emulation types (FP8/FP16/BF16), the runtime datatype tag enumeration, default numeric types, and type-to-tag traits. 

## Types Documentation

### typedef fp8_e4_3m_impl

```cpp
typedef struct fp8_e4_3m_impl fp8_e4_3m_impl;
```







-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
