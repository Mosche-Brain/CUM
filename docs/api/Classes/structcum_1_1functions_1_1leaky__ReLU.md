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
| cumeric_t | **[operator()](/CUM/api/Classes/structcum_1_1functions_1_1leaky__ReLU/#function-operator())**(cumeric_t x) const |

## Public Functions Documentation

### function operator()

```cpp
cumeric_t operator()(
    cumeric_t x
) const
```


-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100