---
title: include/cum/Core.hpp
summary: Core types, dimension definitions, and datatype dispatching utilities for CUM. 

---

# include/cum/Core.hpp

Core types, dimension definitions, and datatype dispatching utilities for CUM.  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cum](/CUM/api/Namespaces/namespacecum/)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| cum::cumeric_t | **[operator""_c](/CUM/api/Files/Core_8hpp/#function-operator""-c)**(long double val)<br>User-defined literal for floating point values converting to default `cumeric_t`.  |
| cum::cumeric_t | **[operator""_c](/CUM/api/Files/Core_8hpp/#function-operator""-c)**(unsigned long long val)<br>User-defined literal for integer values converting to default `cumeric_t`.  |

## Detailed Description

Core types, dimension definitions, and datatype dispatching utilities for CUM. 

Defines target device enumerations, event alias types, shape representations, and compile-time / runtime datatype dispatchers. 


## Functions Documentation

### function operator""_c

```cpp
inline cum::cumeric_t operator""_c(
    long double val
)
```

User-defined literal for floating point values converting to default `cumeric_t`. 

**Parameters**: 

  * **val** Floating point literal value. 


**Return**: Value cast to `cum::cumeric_t`. 

### function operator""_c

```cpp
inline cum::cumeric_t operator""_c(
    unsigned long long val
)
```

User-defined literal for integer values converting to default `cumeric_t`. 

**Parameters**: 

  * **val** Integer literal value. 


**Return**: Value cast to `cum::cumeric_t`. 





-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
