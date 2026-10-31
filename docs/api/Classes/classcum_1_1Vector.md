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
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**()<br>Default constructor.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) len)<br>Constructs dynamic vector of specified length.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**(const Vector & other)<br>Copy constructor.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**(Vector && other)<br>Move constructor.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator=](/CUM/api/Classes/classcum_1_1Vector/#function-operator=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator=](/CUM/api/Classes/classcum_1_1Vector/#function-operator=)**([Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) && other) |
| | **[~Vector](/CUM/api/Classes/classcum_1_1Vector/#function-~vector)**() |
| T & | **[operator[]](/CUM/api/Classes/classcum_1_1Vector/#function-operator[])**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) index) |
| const T | **[operator[]](/CUM/api/Classes/classcum_1_1Vector/#function-operator[])**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) index) const |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[length](/CUM/api/Classes/classcum_1_1Vector/#function-length)**() const |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[size](/CUM/api/Classes/classcum_1_1Vector/#function-size)**() const |
| T * | **[data](/CUM/api/Classes/classcum_1_1Vector/#function-data)**() |
| const T * | **[data](/CUM/api/Classes/classcum_1_1Vector/#function-data)**() const |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator+=](/CUM/api/Classes/classcum_1_1Vector/#function-operator+=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator-=](/CUM/api/Classes/classcum_1_1Vector/#function-operator-=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator*=](/CUM/api/Classes/classcum_1_1Vector/#function-operator*=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator*=](/CUM/api/Classes/classcum_1_1Vector/#function-operator*=)**(T scalar) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator/=](/CUM/api/Classes/classcum_1_1Vector/#function-operator/=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator/=](/CUM/api/Classes/classcum_1_1Vector/#function-operator/=)**(T scalar) |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[cross](/CUM/api/Classes/classcum_1_1Vector/#function-cross)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) const<br>Computes 3D vector cross product.  |
| T | **[dot](/CUM/api/Classes/classcum_1_1Vector/#function-dot)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other) const<br>Computes inner dot product with another vector.  |
| T | **[sum](/CUM/api/Classes/classcum_1_1Vector/#function-sum)**() const<br>Computes sum of all vector elements.  |
| T | **[norm](/CUM/api/Classes/classcum_1_1Vector/#function-norm)**() const<br>Computes Euclidean L2 norm of vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[normalize](/CUM/api/Classes/classcum_1_1Vector/#function-normalize)**() const<br>Computes normalized vector with unit L2 norm.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lenght)<br>Constructs an uninitialized vector of the given length.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**(std::size_t lenght, cumeric_t value)<br>Constructs a vector of the given length filled with an initial scalar value.  |
| | **[Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)**() =default<br>Default constructor creating an empty vector.  |
| | **[operator Matrix](/CUM/api/Classes/classcum_1_1Vector/#function-operator-matrix)**() const<br>Implicit conversion operator from [Vector](/CUM/api/Classes/classcum_1_1Vector/) to 1D/column [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| cumeric_t & | **[operator[]](/CUM/api/Classes/classcum_1_1Vector/#function-operator[])**(const std::size_t index)<br>Subscript access operator (lvalue reference).  |
| const cumeric_t | **[operator[]](/CUM/api/Classes/classcum_1_1Vector/#function-operator[])**(const std::size_t index) const<br>Subscript access operator (const value).  |
| cumeric_t * | **[data](/CUM/api/Classes/classcum_1_1Vector/#function-data)**()<br>Returns pointer to the underlying raw memory buffer.  |
| std::size_t | **[lenght](/CUM/api/Classes/classcum_1_1Vector/#function-lenght)**() const<br>Returns the length (number of elements) of the vector.  |
| std::size_t | **[size](/CUM/api/Classes/classcum_1_1Vector/#function-size)**() const<br>Returns the total size (number of elements) of the vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator+=](/CUM/api/Classes/classcum_1_1Vector/#function-operator+=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>In-place vector addition (`this += other`).  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator+=](/CUM/api/Classes/classcum_1_1Vector/#function-operator+=)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & matrix)<br>In-place matrix addition.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator-=](/CUM/api/Classes/classcum_1_1Vector/#function-operator-=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>In-place vector subtraction (`this -= other`).  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator*=](/CUM/api/Classes/classcum_1_1Vector/#function-operator*=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>In-place elementwise vector multiplication.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator*=](/CUM/api/Classes/classcum_1_1Vector/#function-operator*=)**(const cumeric_t & scalar)<br>In-place scalar multiplication.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[operator/=](/CUM/api/Classes/classcum_1_1Vector/#function-operator/=)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>In-place elementwise vector division.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[dot](/CUM/api/Classes/classcum_1_1Vector/#function-dot)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>Computes the dot (inner) product with another vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[dotInPlace](/CUM/api/Classes/classcum_1_1Vector/#function-dotinplace)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & other)<br>In-place dot product computation.  |
| cumeric_t | **[sum](/CUM/api/Classes/classcum_1_1Vector/#function-sum)**()<br>Computes the sum of all elements in the vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[normalize](/CUM/api/Classes/classcum_1_1Vector/#function-normalize)**()<br>Normalizes the vector to unit L2 norm, returning a new vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & | **[normalizeInPlace](/CUM/api/Classes/classcum_1_1Vector/#function-normalizeinplace)**()<br>Normalizes the vector in-place.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[random](/CUM/api/Classes/classcum_1_1Vector/#function-random)**(T min =static_cast< T >(-1), T max =static_cast< T >(1))<br>Creates random vector with fixed compile-time length.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[random](/CUM/api/Classes/classcum_1_1Vector/#function-random)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) len, T min, T max)<br>Creates random dynamic vector of specified length.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[zeros](/CUM/api/Classes/classcum_1_1Vector/#function-zeros)**()<br>Creates zero-filled vector with fixed compile-time length.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[zeros](/CUM/api/Classes/classcum_1_1Vector/#function-zeros)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) len)<br>Creates zero-filled dynamic vector of specified length.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[ones](/CUM/api/Classes/classcum_1_1Vector/#function-ones)**()<br>Creates ones-filled vector with fixed compile-time length.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[ones](/CUM/api/Classes/classcum_1_1Vector/#function-ones)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) len)<br>Creates ones-filled dynamic vector of specified length.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator+](/CUM/api/Classes/classcum_1_1Vector/#friend-operator+)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & u)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator-](/CUM/api/Classes/classcum_1_1Vector/#friend-operator-)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & u)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator*](/CUM/api/Classes/classcum_1_1Vector/#friend-operator*)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & u)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator*](/CUM/api/Classes/classcum_1_1Vector/#friend-operator*)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, std::type_identity_t< U > scalar)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator/](/CUM/api/Classes/classcum_1_1Vector/#friend-operator/)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & u)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > | **[operator/](/CUM/api/Classes/classcum_1_1Vector/#friend-operator/)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector)< U, L > & v, std::type_identity_t< U > scalar)  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator+](/CUM/api/Classes/classcum_1_1Vector/#friend-operator+)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & u) <br>Elementwise addition of two vectors.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator+](/CUM/api/Classes/classcum_1_1Vector/#friend-operator+)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & A) <br>Addition of a vector and a matrix.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator-](/CUM/api/Classes/classcum_1_1Vector/#friend-operator-)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & u) <br>Elementwise subtraction of two vectors.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator*](/CUM/api/Classes/classcum_1_1Vector/#friend-operator*)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & u) <br>Elementwise multiplication of two vectors.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator*](/CUM/api/Classes/classcum_1_1Vector/#friend-operator*)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const cumeric_t & scalar) <br>Scalar multiplication of a vector.  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) | **[operator/](/CUM/api/Classes/classcum_1_1Vector/#friend-operator/)**(const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & v, const [Vector](/CUM/api/Classes/classcum_1_1Vector/#function-vector) & u) <br>Elementwise division of two vectors.  |

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


Provides vector arithmetic, dot product, normalization, and conversion to/from [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to copy from. 


### function Vector

```cpp
Vector(
    Vector && other
)
```

Move constructor. 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to move from. 


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


**Return**: Cross product [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

### function dot

```cpp
T dot(
    const Vector & other
) const
```

Computes inner dot product with another vector. 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) operand. 


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

**Return**: Normalized [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

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

Implicit conversion operator from [Vector](/CUM/api/Classes/classcum_1_1Vector/) to 1D/column [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Return**: [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) representation of the vector. 

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

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to add. 


**Return**: Reference to `*this`. 

### function operator+=

```cpp
Vector & operator+=(
    Matrix & matrix
)
```

In-place matrix addition. 

**Parameters**: 

  * **matrix** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to add. 


**Return**: Reference to `*this`. 

### function operator-=

```cpp
Vector & operator-=(
    const Vector & other
)
```

In-place vector subtraction (`this -= other`). 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to subtract. 


**Return**: Reference to `*this`. 

### function operator*=

```cpp
Vector & operator*=(
    const Vector & other
)
```

In-place elementwise vector multiplication. 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to multiply with. 


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

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) denominator. 


**Return**: Reference to `*this`. 

### function dot

```cpp
Vector dot(
    const Vector & other
)
```

Computes the dot (inner) product with another vector. 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to compute dot product with. 


**Return**: Result vector containing the dot product. 

### function dotInPlace

```cpp
Vector & dotInPlace(
    const Vector & other
)
```

In-place dot product computation. 

**Parameters**: 

  * **other** [Vector](/CUM/api/Classes/classcum_1_1Vector/) to compute dot product with. 


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


**Return**: Random [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

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

  * **len** [Vector](/CUM/api/Classes/classcum_1_1Vector/) length. 
  * **min** Minimum random bound. 
  * **max** Maximum random bound. 


**Return**: Random [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

### function zeros

```cpp
static Vector zeros()
```

Creates zero-filled vector with fixed compile-time length. 

**Return**: Zero-filled [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

### function zeros

```cpp
static Vector zeros(
    dim_t len
)
```

Creates zero-filled dynamic vector of specified length. 

**Parameters**: 

  * **len** [Vector](/CUM/api/Classes/classcum_1_1Vector/) length. 


**Return**: Zero-filled [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

### function ones

```cpp
static Vector ones()
```

Creates ones-filled vector with fixed compile-time length. 

**Return**: Ones-filled [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

### function ones

```cpp
static Vector ones(
    dim_t len
)
```

Creates ones-filled dynamic vector of specified length. 

**Parameters**: 

  * **len** [Vector](/CUM/api/Classes/classcum_1_1Vector/) length. 


**Return**: Ones-filled [Vector](/CUM/api/Classes/classcum_1_1Vector/). 

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

  * **v** [Vector](/CUM/api/Classes/classcum_1_1Vector/). 
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

Updated on 2026-10-31 at 18:51:12 +0100