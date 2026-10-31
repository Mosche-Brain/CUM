---
title: cum::functions::leaky_ReLU
summary: Leaky Rectified Linear Unit activation functor: f(x) = x if x >= 0 else alpha * x. 

---

# cum::functions::leaky_ReLU



Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x. 


`#include <functions.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| cumeric_t | **[operator()](Classes/structcum_1_1functions_1_1leaky__ReLU.md#function-operator())**(cumeric_t x) const |

## Public Functions Documentation

### function operator()

```cpp
cumeric_t operator()(
    cumeric_t x
) const
```


-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100