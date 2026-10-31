---
title: cum::functions::linear_units

---

# cum::functions::linear_units



## Functions

|                | Name           |
| -------------- | -------------- |
| cumeric_t | **[identity](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity)**(cumeric_t x)<br>Evaluates scalar identity: f(x) = x.  |
| cumeric_t | **[relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu)**(cumeric_t x)<br>Evaluates scalar [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/): f(x) = max(0, x).  |
| cumeric_t | **[leaky_relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu)**(cumeric_t x)<br>Evaluates scalar Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/): f(x) = x if x >= 0 else alpha * x.  |
| cumeric_t | **[gelu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu)**(cumeric_t x)<br>Evaluates scalar Gaussian Error [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit ([GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/)).  |
| cumeric_t | **[elu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu)**(cumeric_t x)<br>Evaluates scalar Exponential [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit (ELU).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) identity out-of-place: `r` = `v`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) identity in-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/)[ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) out-of-place: `r` = max(0, `v`).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/)[ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) in-place: `v` = max(0, `v`).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) out-of-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) in-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/)[GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/) out-of-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/)[GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/) in-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) ELU out-of-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N)<br>[Vector](/CUM/api/Classes/classcum_1_1Vector/) ELU in-place.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| cumeric_t | **[identity_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv)**(cumeric_t x) |
| cumeric_t | **[relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv)**(cumeric_t x) |
| cumeric_t | **[leaky_relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv)**(cumeric_t x) |
| cumeric_t | **[gelu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv)**(cumeric_t x) |
| cumeric_t | **[elu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv)**(cumeric_t x) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[identity_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-identity-deriv-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[relu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-relu-deriv-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[leaky_relu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-leaky-relu-deriv-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gelu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-gelu-deriv-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv-in-place)**(cumeric_t * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_deriv](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[elu_deriv_in_place](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/#function-elu-deriv-in-place)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) N) |


## Functions Documentation

### function identity

```cpp
cumeric_t identity(
    cumeric_t x
)
```

Evaluates scalar identity: f(x) = x. 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function relu

```cpp
cumeric_t relu(
    cumeric_t x
)
```

Evaluates scalar [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/): f(x) = max(0, x). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function leaky_relu

```cpp
cumeric_t leaky_relu(
    cumeric_t x
)
```

Evaluates scalar Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/): f(x) = x if x >= 0 else alpha * x. 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function gelu

```cpp
cumeric_t gelu(
    cumeric_t x
)
```

Evaluates scalar Gaussian Error [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit ([GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/)). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function elu

```cpp
cumeric_t elu(
    cumeric_t x
)
```

Evaluates scalar Exponential [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit (ELU). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function identity

```cpp
__event__ identity(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) identity out-of-place: `r` = `v`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function identity_in_place

```cpp
__event__ identity_in_place(
    cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) identity in-place. 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function identity

```cpp
__event__ identity(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function identity

```cpp
__event__ identity(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function identity_in_place

```cpp
__event__ identity_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function relu

```cpp
__event__ relu(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/)[ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) out-of-place: `r` = max(0, `v`). 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function relu_in_place

```cpp
__event__ relu_in_place(
    cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/)[ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) in-place: `v` = max(0, `v`). 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function relu

```cpp
__event__ relu(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function relu

```cpp
__event__ relu(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function relu_in_place

```cpp
__event__ relu_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) out-of-place. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function leaky_relu_in_place

```cpp
__event__ leaky_relu_in_place(
    cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) Leaky [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/) in-place. 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function leaky_relu

```cpp
__event__ leaky_relu(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function leaky_relu_in_place

```cpp
__event__ leaky_relu_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function gelu

```cpp
__event__ gelu(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/)[GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/) out-of-place. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function gelu_in_place

```cpp
__event__ gelu_in_place(
    cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/)[GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/) in-place. 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function gelu

```cpp
__event__ gelu(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function gelu

```cpp
__event__ gelu(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function gelu_in_place

```cpp
__event__ gelu_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function elu

```cpp
__event__ elu(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) ELU out-of-place. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function elu_in_place

```cpp
__event__ elu_in_place(
    cumeric_t * v,
    dim_t N
)
```

[Vector](/CUM/api/Classes/classcum_1_1Vector/) ELU in-place. 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **N** Element count. 


**Return**: Asynchronous execution event. 

### function elu

```cpp
__event__ elu(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function elu

```cpp
__event__ elu(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function elu_in_place

```cpp
__event__ elu_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function identity_deriv

```cpp
cumeric_t identity_deriv(
    cumeric_t x
)
```


### function relu_deriv

```cpp
cumeric_t relu_deriv(
    cumeric_t x
)
```


### function leaky_relu_deriv

```cpp
cumeric_t leaky_relu_deriv(
    cumeric_t x
)
```


### function gelu_deriv

```cpp
cumeric_t gelu_deriv(
    cumeric_t x
)
```


### function elu_deriv

```cpp
cumeric_t elu_deriv(
    cumeric_t x
)
```


### function identity_deriv

```cpp
__event__ identity_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function identity_deriv_in_place

```cpp
__event__ identity_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function identity_deriv

```cpp
__event__ identity_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function identity_deriv

```cpp
__event__ identity_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function identity_deriv_in_place

```cpp
__event__ identity_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function relu_deriv

```cpp
__event__ relu_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function relu_deriv_in_place

```cpp
__event__ relu_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function relu_deriv

```cpp
__event__ relu_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function relu_deriv

```cpp
__event__ relu_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function relu_deriv_in_place

```cpp
__event__ relu_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function leaky_relu_deriv

```cpp
__event__ leaky_relu_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function leaky_relu_deriv_in_place

```cpp
__event__ leaky_relu_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function leaky_relu_deriv

```cpp
__event__ leaky_relu_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function leaky_relu_deriv

```cpp
__event__ leaky_relu_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function leaky_relu_deriv_in_place

```cpp
__event__ leaky_relu_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function gelu_deriv

```cpp
__event__ gelu_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function gelu_deriv_in_place

```cpp
__event__ gelu_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function gelu_deriv

```cpp
__event__ gelu_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function gelu_deriv

```cpp
__event__ gelu_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function gelu_deriv_in_place

```cpp
__event__ gelu_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function elu_deriv

```cpp
__event__ elu_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t N
)
```


### function elu_deriv_in_place

```cpp
__event__ elu_deriv_in_place(
    cumeric_t * v,
    dim_t N
)
```


### function elu_deriv

```cpp
__event__ elu_deriv(
    datatype dtype,
    void * r,
    const void * v,
    dim_t N
)
```


### function elu_deriv

```cpp
__event__ elu_deriv(
    datatype dtype,
    void * v,
    dim_t N
)
```


### function elu_deriv_in_place

```cpp
__event__ elu_deriv_in_place(
    datatype dtype,
    void * v,
    dim_t N
)
```






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100