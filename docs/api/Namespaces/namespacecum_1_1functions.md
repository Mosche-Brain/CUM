---
title: cum::functions

---

# cum::functions



## Namespaces

| Name           |
| -------------- |
| **[cum::functions::cyclometric](/CUM/api/Namespaces/namespacecum_1_1functions_1_1cyclometric/)**  |
| **[cum::functions::exponential](/CUM/api/Namespaces/namespacecum_1_1functions_1_1exponential/)**  |
| **[cum::functions::hyperbolic](/CUM/api/Namespaces/namespacecum_1_1functions_1_1hyperbolic/)**  |
| **[cum::functions::linear_units](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/)**  |
| **[cum::functions::logistic](/CUM/api/Namespaces/namespacecum_1_1functions_1_1logistic/)**  |
| **[cum::functions::trigonometric](/CUM/api/Namespaces/namespacecum_1_1functions_1_1trigonometric/)**  |
| **[cum::functions::various](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::functions::activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/)** <br>Bundles activation function identifier, forward function, and derivative pointers.  |
| struct | **[cum::functions::GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/)** <br>Gaussian Error [Linear]() Unit activation functor: f(x) = x * P(X <= x).  |
| struct | **[cum::functions::leaky_ReLU](/CUM/api/Classes/structcum_1_1functions_1_1leaky__ReLU/)** <br>Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x.  |
| struct | **[cum::functions::Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/)** <br>[Linear]() / identity activation function functor: f(x) = x.  |
| struct | **[cum::functions::ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/)** <br>Rectified [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit activation functor: f(x) = max(0, x).  |
| struct | **[cum::functions::Sigmoid](/CUM/api/Classes/structcum_1_1functions_1_1Sigmoid/)** <br>Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)).  |
| struct | **[cum::functions::Tanh](/CUM/api/Classes/structcum_1_1functions_1_1Tanh/)** <br>Hyperbolic tangent activation functor: f(x) = tanh(x).  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum class std::uint8_t | **[function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id)** { undefined = 0, linear, relu, leaky_relu, gelu, elu, sqrt, exp, exp2, exp10, log, log2, log10, sin, cos, tan, sinh, cosh, tanh, asin, acos, atan, sigmoid}<br>Numerical identifier for activation and mathematical elementwise operations.  |
| typedef cumeric_t(*)(cumeric_t) | **[function_t](/CUM/api/Namespaces/namespacecum_1_1functions/#typedef-function-t)** <br>Scalar unary mathematical function pointer type.  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[get_function_by_name](/CUM/api/Namespaces/namespacecum_1_1functions/#function-get-function-by-name)**([activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) * activation, const char * name)<br>Resolves an activation function struct by string name (e.g. "relu", "sigmoid", "tanh").  |
| void | **[transformInPlace](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transforminplace)**(cumeric_t * v, [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) & func, std::size_t N)<br>Transforms vector in-place using an activation function definition.  |
| void | **[transform](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform)**(cumeric_t * r, const cumeric_t * v, std::size_t N, [function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Transforms vector `v` by applying activation `activation` into `r`.  |
| void | **[transform](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform)**(cumeric_t * r, const cumeric_t * v, std::size_t N, const [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) & activation)<br>Transforms vector `v` by applying activation struct `activation` into `r`.  |
| void | **[transform](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, std::size_t N, [function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Generic datatype vector transformation using activation identifier.  |
| void | **[transform](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, std::size_t N, const [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) & activation)<br>Generic datatype vector transformation using activation struct.  |
| void | **[transform_deriv](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform-deriv)**(cumeric_t * r, const cumeric_t * v, std::size_t N, [function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Evaluates activation derivative on vector `v` into `r`.  |
| void | **[transform_deriv](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform-deriv)**(cumeric_t * r, const cumeric_t * v, std::size_t N, const [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) & activation)<br>Evaluates activation derivative on vector `v` into `r` using activation struct.  |
| void | **[transform_deriv](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, std::size_t N, [function_id](/CUM/api/Namespaces/namespacecum_1_1functions/#enum-function-id) activation)<br>Generic datatype vector derivative evaluation.  |
| void | **[transform_deriv](/CUM/api/Namespaces/namespacecum_1_1functions/#function-transform-deriv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * r, const void * v, std::size_t N, const [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) & activation)<br>Generic datatype vector derivative evaluation using activation struct.  |

## Types Documentation

### enum function_id

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| undefined | 0| Unspecified / undefined function.   |
| linear | | Identity / linear: f(x) = x.   |
| relu | | Rectified [Linear]() Unit: f(x) = max(0, x).   |
| leaky_relu | | Leaky [ReLU]() with slope alpha: f(x) = x (x>=0) or alpha*x (x<0).   |
| gelu | | Gaussian Error [Linear]() Unit.   |
| elu | | Exponential [Linear]() Unit.   |
| sqrt | | Square root function: f(x) = sqrt(x).   |
| exp | | Natural exponential: f(x) = e^x.   |
| exp2 | | Base-2 exponential: f(x) = 2^x.   |
| exp10 | | Base-10 exponential: f(x) = 10^x.   |
| log | | Natural logarithm: f(x) = ln(x).   |
| log2 | | Base-2 logarithm: f(x) = log2(x).   |
| log10 | | Base-10 logarithm: f(x) = log10(x).   |
| sin | | Sine function.   |
| cos | | Cosine function.   |
| tan | | Tangent function.   |
| sinh | | Hyperbolic sine.   |
| cosh | | Hyperbolic cosine.   |
| tanh | | Hyperbolic tangent.   |
| asin | | Inverse sine (arcsine).   |
| acos | | Inverse cosine (arccosine).   |
| atan | | Inverse tangent (arctangent).   |
| sigmoid | | Logistic sigmoid: f(x) = 1 / (1 + e^-x).   |



Numerical identifier for activation and mathematical elementwise operations. 

### typedef function_t

```cpp
typedef cumeric_t(*) cum::functions::function_t(cumeric_t);
```

Scalar unary mathematical function pointer type. 


## Functions Documentation

### function get_function_by_name

```cpp
void get_function_by_name(
    activation_t * activation,
    const char * name
)
```

Resolves an activation function struct by string name (e.g. "relu", "sigmoid", "tanh"). 

**Parameters**: 

  * **activation** Pointer to output [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/) struct. 
  * **name** C-string containing function name. 


### function transformInPlace

```cpp
void transformInPlace(
    cumeric_t * v,
    activation_t & func,
    std::size_t N
)
```

Transforms vector in-place using an activation function definition. 

**Parameters**: 

  * **v** Buffer to transform in-place. 
  * **func** Activation function struct. 
  * **N** Number of elements. 


### function transform

```cpp
void transform(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N,
    function_id activation
)
```

Transforms vector `v` by applying activation `activation` into `r`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 
  * **activation** Activation function identifier. 


### function transform

```cpp
void transform(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N,
    const activation_t & activation
)
```

Transforms vector `v` by applying activation struct `activation` into `r`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 
  * **activation** Activation struct reference. 


### function transform

```cpp
void transform(
    datatype dtype,
    void * r,
    const void * v,
    std::size_t N,
    function_id activation
)
```

Generic datatype vector transformation using activation identifier. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **r** Output memory buffer. 
  * **v** Input memory buffer. 
  * **N** Element count. 
  * **activation** Activation function identifier. 


### function transform

```cpp
void transform(
    datatype dtype,
    void * r,
    const void * v,
    std::size_t N,
    const activation_t & activation
)
```

Generic datatype vector transformation using activation struct. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **r** Output memory buffer. 
  * **v** Input memory buffer. 
  * **N** Element count. 
  * **activation** Activation struct reference. 


### function transform_deriv

```cpp
void transform_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N,
    function_id activation
)
```

Evaluates activation derivative on vector `v` into `r`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 
  * **activation** Activation function identifier. 


### function transform_deriv

```cpp
void transform_deriv(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N,
    const activation_t & activation
)
```

Evaluates activation derivative on vector `v` into `r` using activation struct. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **N** Element count. 
  * **activation** Activation struct reference. 


### function transform_deriv

```cpp
void transform_deriv(
    datatype dtype,
    void * r,
    const void * v,
    std::size_t N,
    function_id activation
)
```

Generic datatype vector derivative evaluation. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **r** Output memory buffer. 
  * **v** Input memory buffer. 
  * **N** Element count. 
  * **activation** Activation function identifier. 


### function transform_deriv

```cpp
void transform_deriv(
    datatype dtype,
    void * r,
    const void * v,
    std::size_t N,
    const activation_t & activation
)
```

Generic datatype vector derivative evaluation using activation struct. 

**Parameters**: 

  * **dtype** Runtime datatype tag. 
  * **r** Output memory buffer. 
  * **v** Input memory buffer. 
  * **N** Element count. 
  * **activation** Activation struct reference. 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100