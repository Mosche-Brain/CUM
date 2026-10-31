---
title: cum::functions::logistic

---

# cum::functions::logistic



## Functions

|                | Name           |
| -------------- | -------------- |
| cumeric_t | **[sigmoid](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid)**(cumeric_t x)<br>Evaluates scalar logistic sigmoid: f(x) = 1 / (1 + exp(-x)).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid)**(cumeric_t * r, const cumeric_t * v, const std::size_t N)<br>Computes vector sigmoid out-of-place: `r` = 1 / (1 + exp(-`v`)).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-in-place)**(cumeric_t * v, const std::size_t N)<br>Computes vector sigmoid in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax)**(cumeric_t * r, const cumeric_t * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>Computes vector softmax normalization out-of-place: `r_i` = exp(`v_i`) / sum(exp(`v`)).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-in-place)**(cumeric_t * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>Computes vector softmax normalization in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| cumeric_t | **[sigmoid_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv)**(cumeric_t x)<br>Evaluates sigmoid derivative from input `x:` f'(x) = sigmoid(x) * (1 - sigmoid(x)).  |
| cumeric_t | **[sigmoid_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result)**(cumeric_t x)<br>Evaluates sigmoid derivative directly from activated value `y` = sigmoid(x): f'(x) = y * (1 - y).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv)**(cumeric_t * r, const cumeric_t * v, std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-in-place)**(cumeric_t * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result)**(cumeric_t * r, const cumeric_t * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_from_result_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result-in-place)**(cumeric_t * v, std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_deriv_from_result_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-sigmoid-deriv-from-result-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-from-result)**(cumeric_t * r, const cumeric_t * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_from_result_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-from-result-in-place)**(cumeric_t * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-from-result)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_from_result](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-from-result)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_deriv_from_result_in_place](Namespaces/namespacecum_1_1functions_1_1logistic.md#function-softmax-deriv-from-result-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const std::size_t N) |


## Functions Documentation

### function sigmoid

```cpp
cumeric_t sigmoid(
    cumeric_t x
)
```

Evaluates scalar logistic sigmoid: f(x) = 1 / (1 + exp(-x)). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Result scalar in range (0, 1). 

### function sigmoid

```cpp
__event__ sigmoid(
    cumeric_t * r,
    const cumeric_t * v,
    const std::size_t N
)
```

Computes vector sigmoid out-of-place: `r` = 1 / (1 + exp(-`v`)). 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function sigmoid_in_place

```cpp
__event__ sigmoid_in_place(
    cumeric_t * v,
    const std::size_t N
)
```

Computes vector sigmoid in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function sigmoid

```cpp
__event__ sigmoid(
    datatype dtype,
    void * r,
    const void * v,
    const std::size_t N
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    datatype dtype,
    void * v,
    const std::size_t N
)
```


### function sigmoid_in_place

```cpp
__event__ sigmoid_in_place(
    datatype dtype,
    void * v,
    const std::size_t N
)
```


### function softmax

```cpp
__event__ softmax(
    cumeric_t * r,
    const cumeric_t * v,
    const dim_t N
)
```

Computes vector softmax normalization out-of-place: `r_i` = exp(`v_i`) / sum(exp(`v`)). 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function softmax_in_place

```cpp
__event__ softmax_in_place(
    cumeric_t * v,
    const dim_t N
)
```

Computes vector softmax normalization in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function softmax

```cpp
__event__ softmax(
    datatype dtype,
    void * r,
    const void * v,
    const dim_t N
)
```


### function softmax

```cpp
__event__ softmax(
    datatype dtype,
    void * v,
    const dim_t N
)
```


### function softmax_in_place

```cpp
__event__ softmax_in_place(
    datatype dtype,
    void * v,
    const dim_t N
)
```


### function sigmoid_deriv

```cpp
cumeric_t sigmoid_deriv(
    cumeric_t x
)
```

Evaluates sigmoid derivative from input `x:` f'(x) = sigmoid(x) * (1 - sigmoid(x)). 

**Parameters**: 

  * **x** Original input scalar before sigmoid. 


**Return**: Derivative scalar. 

### function sigmoid_deriv_from_result

```cpp
cumeric_t sigmoid_deriv_from_result(
    cumeric_t x
)
```

Evaluates sigmoid derivative directly from activated value `y` = sigmoid(x): f'(x) = y * (1 - y). 

**Parameters**: 

  * **x** Activated value (y). 


**Return**: Derivative scalar. 

### function sigmoid_deriv

```cpp
__event__ sigmoid_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N
)
```


### function sigmoid_deriv_in_place

```cpp
__event__ sigmoid_deriv_in_place(
    cumeric_t * v,
    const std::size_t N
)
```


### function sigmoid_deriv

```cpp
__event__ sigmoid_deriv(
    datatype dtype,
    void * r,
    const void * v,
    std::size_t N
)
```


### function sigmoid_deriv

```cpp
__event__ sigmoid_deriv(
    datatype dtype,
    void * v,
    const std::size_t N
)
```


### function sigmoid_deriv_in_place

```cpp
__event__ sigmoid_deriv_in_place(
    datatype dtype,
    void * v,
    const std::size_t N
)
```


### function sigmoid_deriv_from_result

```cpp
__event__ sigmoid_deriv_from_result(
    cumeric_t * r,
    const cumeric_t * v,
    const std::size_t N
)
```


### function sigmoid_deriv_from_result_in_place

```cpp
__event__ sigmoid_deriv_from_result_in_place(
    cumeric_t * v,
    std::size_t N
)
```


### function sigmoid_deriv_from_result

```cpp
__event__ sigmoid_deriv_from_result(
    datatype dtype,
    void * r,
    const void * v,
    const std::size_t N
)
```


### function sigmoid_deriv_from_result

```cpp
__event__ sigmoid_deriv_from_result(
    datatype dtype,
    void * v,
    std::size_t N
)
```


### function sigmoid_deriv_from_result_in_place

```cpp
__event__ sigmoid_deriv_from_result_in_place(
    datatype dtype,
    void * v,
    std::size_t N
)
```


### function softmax_deriv

```cpp
__event__ softmax_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function softmax_deriv_in_place

```cpp
__event__ softmax_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function softmax_deriv

```cpp
__event__ softmax_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function softmax_deriv

```cpp
__event__ softmax_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function softmax_deriv_in_place

```cpp
__event__ softmax_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function softmax_deriv_from_result

```cpp
__event__ softmax_deriv_from_result(
    cumeric_t * r,
    const cumeric_t * v,
    const std::size_t N
)
```


### function softmax_deriv_from_result_in_place

```cpp
__event__ softmax_deriv_from_result_in_place(
    cumeric_t * v,
    const std::size_t N
)
```


### function softmax_deriv_from_result

```cpp
__event__ softmax_deriv_from_result(
    datatype dtype,
    void * r,
    const void * v,
    const std::size_t N
)
```


### function softmax_deriv_from_result

```cpp
__event__ softmax_deriv_from_result(
    datatype dtype,
    void * v,
    const std::size_t N
)
```


### function softmax_deriv_from_result_in_place

```cpp
__event__ softmax_deriv_from_result_in_place(
    datatype dtype,
    void * v,
    const std::size_t N
)
```






-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100