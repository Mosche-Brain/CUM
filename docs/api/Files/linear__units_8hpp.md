---
title: include/cum/functions/linear_units.hpp
summary: Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity). 

---

# include/cum/functions/linear_units.hpp

Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity).  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[cum](/CUM/api/Namespaces/namespacecum/)**  |
| **[cum::functions](/CUM/api/Namespaces/namespacecum_1_1functions/)**  |
| **[cum::functions::linear_units](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/)**  |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[leaky_relu_alpha](/CUM/api/Files/linear__units_8hpp/#define-leaky-relu-alpha)** <br>Default negative slope coefficient for Leaky ReLU.  |

## Detailed Description

Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity). 

**Author**: jaro


Provides both scalar operations and asynchronous parallel GPU/device vector kernels. 




## Macros Documentation

### define leaky_relu_alpha

```cpp
#define leaky_relu_alpha (cum::cumeric_t)0.01
```

Default negative slope coefficient for Leaky ReLU. 



-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
