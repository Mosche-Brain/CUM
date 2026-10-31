---
title: cum::functions::various

---

# cum::functions::various



## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[fill](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-fill)**(cumeric_t * v, cumeric_t val, std::size_t N)<br>Fills vector `v` with constant scalar `val`.  |
| void | **[fill](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-fill)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, cumeric_t val, std::size_t N)<br>Fills generic memory buffer `v` with constant scalar `val`.  |
| cumeric_t | **[clamp](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-clamp)**(cumeric_t a, cumeric_t min, cumeric_t max)<br>Clamps scalar value `a` between `min` and `max`.  |
| void | **[clip](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-clip)**(cumeric_t * r, const cumeric_t * v, cumeric_t min, cumeric_t max, std::size_t N)<br>Clips vector elements between `min` and `max` out-of-place.  |
| void | **[clipInPlace](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-clipinplace)**(cumeric_t * v, cumeric_t min, cumeric_t max, std::size_t N)<br>Clips vector elements between `min` and `max` in-place.  |
| void | **[clip](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-clip)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, cumeric_t min, cumeric_t max, std::size_t N) |
| void | **[clipInPlace](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-clipinplace)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, cumeric_t min, cumeric_t max, std::size_t N) |
| cumeric_t | **[abs](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-abs)**(cumeric_t x)<br>Evaluates absolute value of scalar `x:` |x|.  |
| cumeric_t | **[min](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-min)**(cumeric_t a, cumeric_t b)<br>Returns minimum of two scalar values.  |
| cumeric_t | **[max](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-max)**(cumeric_t a, cumeric_t b)<br>Returns maximum of two scalar values.  |
| bool | **[equal](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-equal)**(const cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Compares two vectors for elementwise equality.  |
| bool | **[equal](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-equal)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, const void * v, const void * u, std::size_t N)<br>Compares two generic buffers for elementwise equality.  |
| void | **[linespace](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-linespace)**(cumeric_t * v, cumeric_t start, cumeric_t end, std::size_t N)<br>Generates linearly spaced values between `start` and `end` into `v`.  |
| void | **[linespace](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/#function-linespace)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * v, cumeric_t start, cumeric_t end, std::size_t N)<br>Generates linearly spaced values into generic buffer.  |


## Functions Documentation

### function fill

```cpp
void fill(
    cumeric_t * v,
    cumeric_t val,
    std::size_t N
)
```

Fills vector `v` with constant scalar `val`. 

**Parameters**: 

  * **v** Output vector buffer. 
  * **val** Scalar value to fill. 
  * **N** Element count. 


### function fill

```cpp
void fill(
    datatype dtype,
    void * v,
    cumeric_t val,
    std::size_t N
)
```

Fills generic memory buffer `v` with constant scalar `val`. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **v** Output memory buffer. 
  * **val** Scalar value to fill. 
  * **N** Element count. 


### function clamp

```cpp
cumeric_t clamp(
    cumeric_t a,
    cumeric_t min,
    cumeric_t max
)
```

Clamps scalar value `a` between `min` and `max`. 

**Parameters**: 

  * **a** Input scalar value. 
  * **min** Minimum boundary. 
  * **max** Maximum boundary. 


**Return**: Clamped value. 

### function clip

```cpp
void clip(
    cumeric_t * r,
    const cumeric_t * v,
    cumeric_t min,
    cumeric_t max,
    std::size_t N
)
```

Clips vector elements between `min` and `max` out-of-place. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **min** Minimum boundary. 
  * **max** Maximum boundary. 
  * **N** Element count. 


### function clipInPlace

```cpp
void clipInPlace(
    cumeric_t * v,
    cumeric_t min,
    cumeric_t max,
    std::size_t N
)
```

Clips vector elements between `min` and `max` in-place. 

**Parameters**: 

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **min** Minimum boundary. 
  * **max** Maximum boundary. 
  * **N** Element count. 


### function clip

```cpp
void clip(
    datatype dtype,
    void * r,
    const void * v,
    cumeric_t min,
    cumeric_t max,
    std::size_t N
)
```


### function clipInPlace

```cpp
void clipInPlace(
    datatype dtype,
    void * v,
    cumeric_t min,
    cumeric_t max,
    std::size_t N
)
```


### function abs

```cpp
cumeric_t abs(
    cumeric_t x
)
```

Evaluates absolute value of scalar `x:` |x|. 

**Parameters**: 

  * **x** Input scalar. 


**Return**: Absolute value. 

### function min

```cpp
cumeric_t min(
    cumeric_t a,
    cumeric_t b
)
```

Returns minimum of two scalar values. 

**Parameters**: 

  * **a** First value. 
  * **b** Second value. 


**Return**: Minimum value. 

### function max

```cpp
cumeric_t max(
    cumeric_t a,
    cumeric_t b
)
```

Returns maximum of two scalar values. 

**Parameters**: 

  * **a** First value. 
  * **b** Second value. 


**Return**: Maximum value. 

### function equal

```cpp
bool equal(
    const cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Compares two vectors for elementwise equality. 

**Parameters**: 

  * **v** First vector buffer. 
  * **u** Second vector buffer. 
  * **N** Element count. 


**Return**: True if all elements are equal, false otherwise. 

### function equal

```cpp
bool equal(
    datatype dtype,
    const void * v,
    const void * u,
    std::size_t N
)
```

Compares two generic buffers for elementwise equality. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **v** First memory buffer. 
  * **u** Second memory buffer. 
  * **N** Element count. 


**Return**: True if all elements are equal, false otherwise. 

### function linespace

```cpp
void linespace(
    cumeric_t * v,
    cumeric_t start,
    cumeric_t end,
    std::size_t N
)
```

Generates linearly spaced values between `start` and `end` into `v`. 

**Parameters**: 

  * **v** Output vector buffer. 
  * **start** Initial value. 
  * **end** Final value. 
  * **N** Number of points. 


### function linespace

```cpp
void linespace(
    datatype dtype,
    void * v,
    cumeric_t start,
    cumeric_t end,
    std::size_t N
)
```

Generates linearly spaced values into generic buffer. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **v** Output memory buffer. 
  * **start** Initial value. 
  * **end** Final value. 
  * **N** Number of points. 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100