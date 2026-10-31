---
title: fp8_e4_3m_impl
summary: 8-bit floating point emulation structure (E4M3 format representation). 

---

# fp8_e4_3m_impl



8-bit floating point emulation structure (E4M3 format representation). 


`#include <datatypes.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[fp8_e4_3m_impl](Classes/structfp8__e4__3m__impl.md#function-fp8-e4-3m-impl)**(float val)<br>Constructs an FP8 value from float.  |
| | **[operator float](Classes/structfp8__e4__3m__impl.md#function-operator-float)**() const<br>Conversion operator to float (const).  |
| | **[operator float](Classes/structfp8__e4__3m__impl.md#function-operator-float)**()<br>Non-const conversion operator to float.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| unsigned char | **[data](Classes/structfp8__e4__3m__impl.md#variable-data)** <br>Raw 8-bit byte representation.  |

## Public Functions Documentation

### function fp8_e4_3m_impl

```cpp
inline fp8_e4_3m_impl(
    float val
)
```

Constructs an FP8 value from float. 

**Parameters**: 

  * **val** Single-precision float value to convert. 


### function operator float

```cpp
inline operator float() const
```

Conversion operator to float (const). 

**Return**: Converted single-precision floating point value. 

### function operator float

```cpp
inline operator float()
```

Non-const conversion operator to float. 

**Return**: Converted single-precision floating point value. 

## Public Attributes Documentation

### variable data

```cpp
unsigned char data;
```

Raw 8-bit byte representation. 

-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100