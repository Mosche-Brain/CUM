---
title: cum::functions::activation_t
summary: Bundles activation function identifier, forward function, and derivative pointers. 

---

# cum::functions::activation_t



Bundles activation function identifier, forward function, and derivative pointers. 


`#include <function_id.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) | **[name](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/#variable-name)** <br>Identifier of the activation function.  |
| [function_t](/CUM/api/Namespaces/namespacecum_1_1functions/#typedef-function-t) | **[function](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/#variable-function)** <br>Forward evaluation function pointer.  |
| [function_t](/CUM/api/Namespaces/namespacecum_1_1functions/#typedef-function-t) | **[derivative](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/#variable-derivative)** <br>Derivative evaluation function pointer.  |

## Public Attributes Documentation

### variable name

```cpp
function_id name;
```

Identifier of the activation function. 

### variable function

```cpp
function_t function;
```

Forward evaluation function pointer. 

### variable derivative

```cpp
function_t derivative;
```

Derivative evaluation function pointer. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100