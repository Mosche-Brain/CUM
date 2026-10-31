---
title: cum::Vector
summary: Templated generic 1D dense vector. 

---

# cum::Vector



Templated generic 1D dense vector.  [More...](#detailed-description)


`#include <Vector.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**()<br>Default constructor.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**([dim_t](Namespaces/namespacecum.md#using-dim-t) len)<br>Constructs dynamic vector of specified length.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**(const Vector & other)<br>Copy constructor.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**(Vector && other)<br>Move constructor.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator=](Classes/classcum_1_1Vector.md#function-operator=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator=](Classes/classcum_1_1Vector.md#function-operator=)**([Vector](Classes/classcum_1_1Vector.md#function-vector) && other) |
| | **[~Vector](Classes/classcum_1_1Vector.md#function-~vector)**() |
| T & | **[operator[]](Classes/classcum_1_1Vector.md#function-operator[])**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) index) |
| const T | **[operator[]](Classes/classcum_1_1Vector.md#function-operator[])**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) index) const |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[length](Classes/classcum_1_1Vector.md#function-length)**() const |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[size](Classes/classcum_1_1Vector.md#function-size)**() const |
| T * | **[data](Classes/classcum_1_1Vector.md#function-data)**() |
| const T * | **[data](Classes/classcum_1_1Vector.md#function-data)**() const |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator+=](Classes/classcum_1_1Vector.md#function-operator+=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator-=](Classes/classcum_1_1Vector.md#function-operator-=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator*=](Classes/classcum_1_1Vector.md#function-operator*=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator*=](Classes/classcum_1_1Vector.md#function-operator*=)**(T scalar) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator/=](Classes/classcum_1_1Vector.md#function-operator/=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator/=](Classes/classcum_1_1Vector.md#function-operator/=)**(T scalar) |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[cross](Classes/classcum_1_1Vector.md#function-cross)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) const<br>Computes 3D vector cross product.  |
| T | **[dot](Classes/classcum_1_1Vector.md#function-dot)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other) const<br>Computes inner dot product with another vector.  |
| T | **[sum](Classes/classcum_1_1Vector.md#function-sum)**() const<br>Computes sum of all vector elements.  |
| T | **[norm](Classes/classcum_1_1Vector.md#function-norm)**() const<br>Computes Euclidean L2 norm of vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[normalize](Classes/classcum_1_1Vector.md#function-normalize)**() const<br>Computes normalized vector with unit L2 norm.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**([dim_t](Namespaces/namespacecum.md#using-dim-t) lenght)<br>Constructs an uninitialized vector of the given length.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**(std::size_t lenght, cumeric_t value)<br>Constructs a vector of the given length filled with an initial scalar value.  |
| | **[Vector](Classes/classcum_1_1Vector.md#function-vector)**() =default<br>Default constructor creating an empty vector.  |
| | **[operator Matrix](Classes/classcum_1_1Vector.md#function-operator-matrix)**() const<br>Implicit conversion operator from [Vector](Classes/classcum_1_1Vector.md) to 1D/column [Matrix](Classes/classcum_1_1Matrix.md).  |
| cumeric_t & | **[operator[]](Classes/classcum_1_1Vector.md#function-operator[])**(const std::size_t index)<br>Subscript access operator (lvalue reference).  |
| const cumeric_t | **[operator[]](Classes/classcum_1_1Vector.md#function-operator[])**(const std::size_t index) const<br>Subscript access operator (const value).  |
| cumeric_t * | **[data](Classes/classcum_1_1Vector.md#function-data)**()<br>Returns pointer to the underlying raw memory buffer.  |
| std::size_t | **[lenght](Classes/classcum_1_1Vector.md#function-lenght)**() const<br>Returns the length (number of elements) of the vector.  |
| std::size_t | **[size](Classes/classcum_1_1Vector.md#function-size)**() const<br>Returns the total size (number of elements) of the vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator+=](Classes/classcum_1_1Vector.md#function-operator+=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>In-place vector addition (`this += other`).  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator+=](Classes/classcum_1_1Vector.md#function-operator+=)**([Matrix](Classes/classcum_1_1Matrix.md) & matrix)<br>In-place matrix addition.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator-=](Classes/classcum_1_1Vector.md#function-operator-=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>In-place vector subtraction (`this -= other`).  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator*=](Classes/classcum_1_1Vector.md#function-operator*=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>In-place elementwise vector multiplication.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator*=](Classes/classcum_1_1Vector.md#function-operator*=)**(const cumeric_t & scalar)<br>In-place scalar multiplication.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[operator/=](Classes/classcum_1_1Vector.md#function-operator/=)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>In-place elementwise vector division.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[dot](Classes/classcum_1_1Vector.md#function-dot)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>Computes the dot (inner) product with another vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[dotInPlace](Classes/classcum_1_1Vector.md#function-dotinplace)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & other)<br>In-place dot product computation.  |
| cumeric_t | **[sum](Classes/classcum_1_1Vector.md#function-sum)**()<br>Computes the sum of all elements in the vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[normalize](Classes/classcum_1_1Vector.md#function-normalize)**()<br>Normalizes the vector to unit L2 norm, returning a new vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) & | **[normalizeInPlace](Classes/classcum_1_1Vector.md#function-normalizeinplace)**()<br>Normalizes the vector in-place.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[random](Classes/classcum_1_1Vector.md#function-random)**(T min =static_cast< T >(-1), T max =static_cast< T >(1))<br>Creates random vector with fixed compile-time length.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[random](Classes/classcum_1_1Vector.md#function-random)**([dim_t](Namespaces/namespacecum.md#using-dim-t) len, T min, T max)<br>Creates random dynamic vector of specified length.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[zeros](Classes/classcum_1_1Vector.md#function-zeros)**()<br>Creates zero-filled vector with fixed compile-time length.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[zeros](Classes/classcum_1_1Vector.md#function-zeros)**([dim_t](Namespaces/namespacecum.md#using-dim-t) len)<br>Creates zero-filled dynamic vector of specified length.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[ones](Classes/classcum_1_1Vector.md#function-ones)**()<br>Creates ones-filled vector with fixed compile-time length.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[ones](Classes/classcum_1_1Vector.md#function-ones)**([dim_t](Namespaces/namespacecum.md#using-dim-t) len)<br>Creates ones-filled dynamic vector of specified length.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator+](Classes/classcum_1_1Vector.md#friend-operator+)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & u)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator-](Classes/classcum_1_1Vector.md#friend-operator-)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & u)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator*](Classes/classcum_1_1Vector.md#friend-operator*)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & u)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator*](Classes/classcum_1_1Vector.md#friend-operator*)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, std::type_identity_t< U > scalar)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator/](Classes/classcum_1_1Vector.md#friend-operator/)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & u)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > | **[operator/](Classes/classcum_1_1Vector.md#friend-operator/)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector)< U, L > & v, std::type_identity_t< U > scalar)  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator+](Classes/classcum_1_1Vector.md#friend-operator+)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector) & u) <br>Elementwise addition of two vectors.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator+](Classes/classcum_1_1Vector.md#friend-operator+)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const [Matrix](Classes/classcum_1_1Matrix.md) & A) <br>Addition of a vector and a matrix.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator-](Classes/classcum_1_1Vector.md#friend-operator-)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector) & u) <br>Elementwise subtraction of two vectors.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator*](Classes/classcum_1_1Vector.md#friend-operator*)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector) & u) <br>Elementwise multiplication of two vectors.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator*](Classes/classcum_1_1Vector.md#friend-operator*)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const cumeric_t & scalar) <br>Scalar multiplication of a vector.  |
| [Vector](Classes/classcum_1_1Vector.md#function-vector) | **[operator/](Classes/classcum_1_1Vector.md#friend-operator/)**(const [Vector](Classes/classcum_1_1Vector.md#function-vector) & v, const [Vector](Classes/classcum_1_1Vector.md#function-vector) & u) <br>Elementwise division of two vectors.  |

## Detailed Description

```cpp
template <typename T ,
dim_t length_ =Dynamic>
class cum::Vector;
```

Templated generic 1D dense vector. 

**Template Parameters**: 

  * **T** Element type. 
  * **length_** Dimension length (default is Dynamic for runtime sizing).


1D numeric dense vector allocated in unified device memory.


Provides vector arithmetic, dot product, normalization, and conversion to/from [Matrix](Classes/classcum_1_1Matrix.md). 

## Public Functions Documentation

### function Vector

```cpp
Vector()
```

Default constructor. 

### function Vector

```cpp
Vector(
    dim_t len
)
```

Constructs dynamic vector of specified length. 

**Parameters**: 

  * **len** Length of the vector. 


### function Vector

```cpp
Vector(
    const Vector & other
)
```

Copy constructor. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to copy from. 


### function Vector

```cpp
Vector(
    Vector && other
)
```

Move constructor. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to move from. 


### function operator=

```cpp
Vector & operator=(
    const Vector & other
)
```


### function operator=

```cpp
Vector & operator=(
    Vector && other
)
```


### function ~Vector

```cpp
~Vector()
```


### function operator[]

```cpp
inline T & operator[](
    const dim_t index
)
```


### function operator[]

```cpp
inline const T operator[](
    const dim_t index
) const
```


### function length

```cpp
inline dim_t length() const
```


### function size

```cpp
inline dim_t size() const
```


### function data

```cpp
inline T * data()
```


### function data

```cpp
inline const T * data() const
```


### function operator+=

```cpp
Vector & operator+=(
    const Vector & other
)
```


### function operator-=

```cpp
Vector & operator-=(
    const Vector & other
)
```


### function operator*=

```cpp
Vector & operator*=(
    const Vector & other
)
```


### function operator*=

```cpp
Vector & operator*=(
    T scalar
)
```


### function operator/=

```cpp
Vector & operator/=(
    const Vector & other
)
```


### function operator/=

```cpp
Vector & operator/=(
    T scalar
)
```


### function cross

```cpp
Vector cross(
    const Vector & other
) const
```

Computes 3D vector cross product. 

**Parameters**: 

  * **other** Right-hand side vector. 


**Return**: Cross product [Vector](Classes/classcum_1_1Vector.md). 

### function dot

```cpp
T dot(
    const Vector & other
) const
```

Computes inner dot product with another vector. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) operand. 


**Return**: Scalar dot product. 

### function sum

```cpp
T sum() const
```

Computes sum of all vector elements. 

**Return**: Scalar sum. 

### function norm

```cpp
T norm() const
```

Computes Euclidean L2 norm of vector. 

**Return**: Scalar norm. 

### function normalize

```cpp
Vector normalize() const
```

Computes normalized vector with unit L2 norm. 

**Return**: Normalized [Vector](Classes/classcum_1_1Vector.md). 

### function Vector

```cpp
Vector(
    dim_t lenght
)
```

Constructs an uninitialized vector of the given length. 

**Parameters**: 

  * **lenght** Number of elements. 


### function Vector

```cpp
Vector(
    std::size_t lenght,
    cumeric_t value
)
```

Constructs a vector of the given length filled with an initial scalar value. 

**Parameters**: 

  * **lenght** Number of elements. 
  * **value** Initial value for each element. 


### function Vector

```cpp
Vector() =default
```

Default constructor creating an empty vector. 

### function operator Matrix

```cpp
operator Matrix() const
```

Implicit conversion operator from [Vector](Classes/classcum_1_1Vector.md) to 1D/column [Matrix](Classes/classcum_1_1Matrix.md). 

**Return**: [Matrix](Classes/classcum_1_1Matrix.md) representation of the vector. 

### function operator[]

```cpp
inline cumeric_t & operator[](
    const std::size_t index
)
```

Subscript access operator (lvalue reference). 

**Parameters**: 

  * **index** Element zero-based index. 


**Return**: Reference to the element. 

### function operator[]

```cpp
inline const cumeric_t operator[](
    const std::size_t index
) const
```

Subscript access operator (const value). 

**Parameters**: 

  * **index** Element zero-based index. 


**Return**: Element value. 

### function data

```cpp
inline cumeric_t * data()
```

Returns pointer to the underlying raw memory buffer. 

**Return**: Pointer to cumeric_t elements. 

### function lenght

```cpp
inline std::size_t lenght() const
```

Returns the length (number of elements) of the vector. 

**Return**: Element count. 

### function size

```cpp
inline std::size_t size() const
```

Returns the total size (number of elements) of the vector. 

**Return**: Element count. 

### function operator+=

```cpp
Vector & operator+=(
    const Vector & other
)
```

In-place vector addition (`this += other`). 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to add. 


**Return**: Reference to `*this`. 

### function operator+=

```cpp
Vector & operator+=(
    Matrix & matrix
)
```

In-place matrix addition. 

**Parameters**: 

  * **matrix** [Matrix](Classes/classcum_1_1Matrix.md) to add. 


**Return**: Reference to `*this`. 

### function operator-=

```cpp
Vector & operator-=(
    const Vector & other
)
```

In-place vector subtraction (`this -= other`). 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to subtract. 


**Return**: Reference to `*this`. 

### function operator*=

```cpp
Vector & operator*=(
    const Vector & other
)
```

In-place elementwise vector multiplication. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to multiply with. 


**Return**: Reference to `*this`. 

### function operator*=

```cpp
Vector & operator*=(
    const cumeric_t & scalar
)
```

In-place scalar multiplication. 

**Parameters**: 

  * **scalar** Scalar multiplier. 


**Return**: Reference to `*this`. 

### function operator/=

```cpp
Vector & operator/=(
    const Vector & other
)
```

In-place elementwise vector division. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) denominator. 


**Return**: Reference to `*this`. 

### function dot

```cpp
Vector dot(
    const Vector & other
)
```

Computes the dot (inner) product with another vector. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to compute dot product with. 


**Return**: Result vector containing the dot product. 

### function dotInPlace

```cpp
Vector & dotInPlace(
    const Vector & other
)
```

In-place dot product computation. 

**Parameters**: 

  * **other** [Vector](Classes/classcum_1_1Vector.md) to compute dot product with. 


**Return**: Reference to `*this`. 

### function sum

```cpp
cumeric_t sum()
```

Computes the sum of all elements in the vector. 

**Return**: Scalar sum. 

### function normalize

```cpp
Vector normalize()
```

Normalizes the vector to unit L2 norm, returning a new vector. 

**Return**: Normalized vector. 

### function normalizeInPlace

```cpp
Vector & normalizeInPlace()
```

Normalizes the vector in-place. 

**Return**: Reference to `*this`. 

### function random

```cpp
static Vector random(
    T min =static_cast< T >(-1),
    T max =static_cast< T >(1)
)
```

Creates random vector with fixed compile-time length. 

**Parameters**: 

  * **min** Minimum random bound. 
  * **max** Maximum random bound. 


**Return**: Random [Vector](Classes/classcum_1_1Vector.md). 

### function random

```cpp
static Vector random(
    dim_t len,
    T min,
    T max
)
```

Creates random dynamic vector of specified length. 

**Parameters**: 

  * **len** [Vector](Classes/classcum_1_1Vector.md) length. 
  * **min** Minimum random bound. 
  * **max** Maximum random bound. 


**Return**: Random [Vector](Classes/classcum_1_1Vector.md). 

### function zeros

```cpp
static Vector zeros()
```

Creates zero-filled vector with fixed compile-time length. 

**Return**: Zero-filled [Vector](Classes/classcum_1_1Vector.md). 

### function zeros

```cpp
static Vector zeros(
    dim_t len
)
```

Creates zero-filled dynamic vector of specified length. 

**Parameters**: 

  * **len** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Zero-filled [Vector](Classes/classcum_1_1Vector.md). 

### function ones

```cpp
static Vector ones()
```

Creates ones-filled vector with fixed compile-time length. 

**Return**: Ones-filled [Vector](Classes/classcum_1_1Vector.md). 

### function ones

```cpp
static Vector ones(
    dim_t len
)
```

Creates ones-filled dynamic vector of specified length. 

**Parameters**: 

  * **len** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Ones-filled [Vector](Classes/classcum_1_1Vector.md). 

## Friends

### friend operator+

```cpp
friend Vector< U, L > operator+(
    const Vector< U, L > & v,

    const Vector< U, L > & u
);
```


### friend operator-

```cpp
friend Vector< U, L > operator-(
    const Vector< U, L > & v,

    const Vector< U, L > & u
);
```


### friend operator*

```cpp
friend Vector< U, L > operator*(
    const Vector< U, L > & v,

    const Vector< U, L > & u
);
```


### friend operator*

```cpp
friend Vector< U, L > operator*(
    const Vector< U, L > & v,

    std::type_identity_t< U > scalar
);
```


### friend operator/

```cpp
friend Vector< U, L > operator/(
    const Vector< U, L > & v,

    const Vector< U, L > & u
);
```


### friend operator/

```cpp
friend Vector< U, L > operator/(
    const Vector< U, L > & v,

    std::type_identity_t< U > scalar
);
```


### friend operator+

```cpp
friend Vector operator+(
    const Vector & v,

    const Vector & u
);
```

Elementwise addition of two vectors. 

**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Sum vector. 

### friend operator+

```cpp
friend Vector operator+(
    const Vector & v,

    const Matrix & A
);
```

Addition of a vector and a matrix. 

**Parameters**: 

  * **v** Left vector operand. 
  * **A** Right matrix operand. 


**Return**: Sum vector. 

### friend operator-

```cpp
friend Vector operator-(
    const Vector & v,

    const Vector & u
);
```

Elementwise subtraction of two vectors. 

**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Difference vector. 

### friend operator*

```cpp
friend Vector operator*(
    const Vector & v,

    const Vector & u
);
```

Elementwise multiplication of two vectors. 

**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Product vector. 

### friend operator*

```cpp
friend Vector operator*(
    const Vector & v,

    const cumeric_t & scalar
);
```

Scalar multiplication of a vector. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md). 
  * **scalar** Scalar value. 


**Return**: Scaled vector. 

### friend operator/

```cpp
friend Vector operator/(
    const Vector & v,

    const Vector & u
);
```

Elementwise division of two vectors. 

**Parameters**: 

  * **v** Numerator vector. 
  * **u** Denominator vector. 


**Return**: Quotient vector. 

-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100