---
title: cum::functions::linear_units

---

# cum::functions::linear_units



## Functions

|                | Name           |
| -------------- | -------------- |
| cumeric_t | **[identity](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity)**(cumeric_t x)<br>Evaluates scalar identity: f(x) = x.  |
| cumeric_t | **[relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu)**(cumeric_t x)<br>Evaluates scalar [ReLU](Classes/structcum_1_1functions_1_1ReLU.md): f(x) = max(0, x).  |
| cumeric_t | **[leaky_relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu)**(cumeric_t x)<br>Evaluates scalar Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md): f(x) = x if x >= 0 else alpha * x.  |
| cumeric_t | **[gelu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu)**(cumeric_t x)<br>Evaluates scalar Gaussian Error [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit ([GELU](Classes/structcum_1_1functions_1_1GELU.md)).  |
| cumeric_t | **[elu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu)**(cumeric_t x)<br>Evaluates scalar Exponential [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit (ELU).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) identity out-of-place: `r` = `v`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) identity in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md)[ReLU](Classes/structcum_1_1functions_1_1ReLU.md) out-of-place: `r` = max(0, `v`).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md)[ReLU](Classes/structcum_1_1functions_1_1ReLU.md) in-place: `v` = max(0, `v`).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md) out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md) in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md)[GELU](Classes/structcum_1_1functions_1_1GELU.md) out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md)[GELU](Classes/structcum_1_1functions_1_1GELU.md) in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) ELU out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N)<br>[Vector](Classes/classcum_1_1Vector.md) ELU in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| cumeric_t | **[identity_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv)**(cumeric_t x) |
| cumeric_t | **[relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv)**(cumeric_t x) |
| cumeric_t | **[leaky_relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv)**(cumeric_t x) |
| cumeric_t | **[gelu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv)**(cumeric_t x) |
| cumeric_t | **[elu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv)**(cumeric_t x) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[identity_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-identity-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-relu-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-leaky-relu-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-gelu-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv-in-place)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_deriv](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_deriv_in_place](Namespaces/namespacecum_1_1functions_1_1linear__units.md#function-elu-deriv-in-place)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) N) |


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

Evaluates scalar [ReLU](Classes/structcum_1_1functions_1_1ReLU.md): f(x) = max(0, x). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function leaky_relu

```cpp
cumeric_t leaky_relu(
    cumeric_t x
)
```

Evaluates scalar Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md): f(x) = x if x >= 0 else alpha * x. 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function gelu

```cpp
cumeric_t gelu(
    cumeric_t x
)
```

Evaluates scalar Gaussian Error [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit ([GELU](Classes/structcum_1_1functions_1_1GELU.md)). 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Output scalar. 

### function elu

```cpp
cumeric_t elu(
    cumeric_t x
)
```

Evaluates scalar Exponential [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit (ELU). 

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

[Vector](Classes/classcum_1_1Vector.md) identity out-of-place: `r` = `v`. 

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

[Vector](Classes/classcum_1_1Vector.md) identity in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer. 
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

[Vector](Classes/classcum_1_1Vector.md)[ReLU](Classes/structcum_1_1functions_1_1ReLU.md) out-of-place: `r` = max(0, `v`). 

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

[Vector](Classes/classcum_1_1Vector.md)[ReLU](Classes/structcum_1_1functions_1_1ReLU.md) in-place: `v` = max(0, `v`). 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
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

[Vector](Classes/classcum_1_1Vector.md) Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md) out-of-place. 

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

[Vector](Classes/classcum_1_1Vector.md) Leaky [ReLU](Classes/structcum_1_1functions_1_1ReLU.md) in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
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

[Vector](Classes/classcum_1_1Vector.md)[GELU](Classes/structcum_1_1functions_1_1GELU.md) out-of-place. 

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

[Vector](Classes/classcum_1_1Vector.md)[GELU](Classes/structcum_1_1functions_1_1GELU.md) in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
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

[Vector](Classes/classcum_1_1Vector.md) ELU out-of-place. 

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

[Vector](Classes/classcum_1_1Vector.md) ELU in-place. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
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

Updated on 2026-10-31 at 18:07:41 +0100