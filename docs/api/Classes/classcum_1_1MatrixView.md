---
title: cum::MatrixView
summary: Lightweight, non-owning read view over a 2D matrix or existing data buffer. 

---

# cum::MatrixView



Lightweight, non-owning read view over a 2D matrix or existing data buffer.  [More...](#detailed-description)


`#include <MatrixView.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**(const [Matrix](Classes/classcum_1_1Matrix.md) & other)<br>Constructs a view over an existing [Matrix](Classes/classcum_1_1Matrix.md).  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**([Matrix](Classes/classcum_1_1Matrix.md) && other)<br>Move constructor.  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**(cumeric_t * source, [dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Constructs a view over a raw pointer buffer.  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, cumeric_t * source)<br>Constructs a view over a raw pointer buffer (dimensions first).  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**(const cumeric_t * source, [dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Constructs a view over a const raw pointer buffer.  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, const cumeric_t * source)<br>Constructs a view over a const raw pointer buffer (dimensions first).  |
| | **[MatrixView](Classes/classcum_1_1MatrixView.md#function-matrixview)**() =default<br>Default constructor creating an empty view.  |
| | **[~MatrixView](Classes/classcum_1_1MatrixView.md#function-~matrixview)**()<br>Destructor (does not free viewed memory).  |
| std::size_t | **[rows](Classes/classcum_1_1MatrixView.md#function-rows)**() const<br>Returns the number of rows in the view.  |
| std::size_t | **[cols](Classes/classcum_1_1MatrixView.md#function-cols)**() const<br>Returns the number of columns in the view.  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[row](Classes/classcum_1_1MatrixView.md#function-row)**(std::size_t i) const<br>Extracts a row as a new [Matrix](Classes/classcum_1_1Matrix.md).  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[col](Classes/classcum_1_1MatrixView.md#function-col)**(std::size_t i) const<br>Extracts a column as a new [Matrix](Classes/classcum_1_1Matrix.md).  |
| std::size_t | **[size](Classes/classcum_1_1MatrixView.md#function-size)**() const<br>Returns the total number of elements in the view.  |
| const cumeric_t * | **[data](Classes/classcum_1_1MatrixView.md#function-data)**() const<br>Returns const raw data pointer.  |
| const cumeric_t & | **[at](Classes/classcum_1_1MatrixView.md#function-at)**(const std::size_t row, const std::size_t col) const<br>Indexed const element access.  |
| const cumeric_t & | **[operator()](Classes/classcum_1_1MatrixView.md#function-operator())**(const std::size_t row, const std::size_t col) const<br>Function call operator for indexed const element access.  |
| [Matrix](Classes/classcum_1_1Matrix.md) & | **[set](Classes/classcum_1_1MatrixView.md#function-set)**(const [Matrix](Classes/classcum_1_1Matrix.md) & other)<br>Sets target matrix with viewed data.  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[transpose](Classes/classcum_1_1MatrixView.md#function-transpose)**() const |
| [Vector](Classes/classcum_1_1Vector.md) | **[flatten](Classes/classcum_1_1MatrixView.md#function-flatten)**() const |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[reshape](Classes/classcum_1_1MatrixView.md#function-reshape)**(std::size_t rows, std::size_t cols) const |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[cwiseProduct](Classes/classcum_1_1MatrixView.md#function-cwiseproduct)**(const [Matrix](Classes/classcum_1_1Matrix.md) & other) |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[transform](Classes/classcum_1_1MatrixView.md#function-transform)**(void(*)(cumeric_t *[data](Classes/classcum_1_1MatrixView.md#function-data), const std::size_t [size](Classes/classcum_1_1MatrixView.md#function-size)) func) const |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[transform](Classes/classcum_1_1MatrixView.md#function-transform)**(cumeric_t(*)(cumeric_t x) func) const |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[clip](Classes/classcum_1_1MatrixView.md#function-clip)**(cumeric_t min, cumeric_t max) const |
| cumeric_t | **[norm](Classes/classcum_1_1MatrixView.md#function-norm)**() |
| cumeric_t | **[squaredNorm](Classes/classcum_1_1MatrixView.md#function-squarednorm)**() |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[colwiseSum](Classes/classcum_1_1MatrixView.md#function-colwisesum)**() |
| [Vector](Classes/classcum_1_1Vector.md) | **[colwiseSum2vec](Classes/classcum_1_1MatrixView.md#function-colwisesum2vec)**() |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[rowwiseSum](Classes/classcum_1_1MatrixView.md#function-rowwisesum)**() |
| [Vector](Classes/classcum_1_1Vector.md) | **[rowwiseSum2vec](Classes/classcum_1_1MatrixView.md#function-rowwisesum2vec)**() |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[shuffleRows](Classes/classcum_1_1MatrixView.md#function-shufflerows)**() const |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator+](Classes/classcum_1_1MatrixView.md#friend-operator+)**(const [Matrix](Classes/classcum_1_1Matrix.md) & A, const [Matrix](Classes/classcum_1_1Matrix.md) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator-](Classes/classcum_1_1MatrixView.md#friend-operator-)**(const [Matrix](Classes/classcum_1_1Matrix.md) & A, const [Matrix](Classes/classcum_1_1Matrix.md) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator*](Classes/classcum_1_1MatrixView.md#friend-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md) & A, const [Matrix](Classes/classcum_1_1Matrix.md) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator*](Classes/classcum_1_1MatrixView.md#friend-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md) & mat, const cumeric_t & scalar)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator/](Classes/classcum_1_1MatrixView.md#friend-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md) & A, const [Matrix](Classes/classcum_1_1Matrix.md) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[operator/](Classes/classcum_1_1MatrixView.md#friend-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md) & mat, const cumeric_t & scalar)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[activation](Classes/classcum_1_1MatrixView.md#friend-activation)**(const [Matrix](Classes/classcum_1_1Matrix.md) & mat, const char * name)  |
| [Matrix](Classes/classcum_1_1Matrix.md) | **[activationInPlace](Classes/classcum_1_1MatrixView.md#friend-activationinplace)**([Matrix](Classes/classcum_1_1Matrix.md) & mat, const char * name)  |

## Detailed Description

```cpp
class cum::MatrixView;
```

Lightweight, non-owning read view over a 2D matrix or existing data buffer. 

Provides safe read access, row/column slicing, arithmetic with other matrices, and reductions without copying the underlying buffer. 

## Public Functions Documentation

### function MatrixView

```cpp
MatrixView(
    const Matrix & other
)
```

Constructs a view over an existing [Matrix](Classes/classcum_1_1Matrix.md). 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to view. 


### function MatrixView

```cpp
MatrixView(
    Matrix && other
)
```

Move constructor. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to view. 


### function MatrixView

```cpp
MatrixView(
    cumeric_t * source,
    dim_t rows,
    dim_t cols
)
```

Constructs a view over a raw pointer buffer. 

**Parameters**: 

  * **source** Pointer to data. 
  * **rows** Number of rows. 
  * **cols** Number of columns. 


### function MatrixView

```cpp
MatrixView(
    dim_t rows,
    dim_t cols,
    cumeric_t * source
)
```

Constructs a view over a raw pointer buffer (dimensions first). 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **source** Pointer to data. 


### function MatrixView

```cpp
MatrixView(
    const cumeric_t * source,
    dim_t rows,
    dim_t cols
)
```

Constructs a view over a const raw pointer buffer. 

**Parameters**: 

  * **source** Const pointer to data. 
  * **rows** Number of rows. 
  * **cols** Number of columns. 


### function MatrixView

```cpp
MatrixView(
    dim_t rows,
    dim_t cols,
    const cumeric_t * source
)
```

Constructs a view over a const raw pointer buffer (dimensions first). 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **source** Const pointer to data. 


### function MatrixView

```cpp
MatrixView() =default
```

Default constructor creating an empty view. 

### function ~MatrixView

```cpp
~MatrixView()
```

Destructor (does not free viewed memory). 

### function rows

```cpp
inline std::size_t rows() const
```

Returns the number of rows in the view. 

**Return**: Row count. 

### function cols

```cpp
inline std::size_t cols() const
```

Returns the number of columns in the view. 

**Return**: Column count. 

### function row

```cpp
Matrix row(
    std::size_t i
) const
```

Extracts a row as a new [Matrix](Classes/classcum_1_1Matrix.md). 

**Parameters**: 

  * **i** Row index. 


**Return**: Extracted row [Matrix](Classes/classcum_1_1Matrix.md). 

### function col

```cpp
Matrix col(
    std::size_t i
) const
```

Extracts a column as a new [Matrix](Classes/classcum_1_1Matrix.md). 

**Parameters**: 

  * **i** Column index. 


**Return**: Extracted column [Matrix](Classes/classcum_1_1Matrix.md). 

### function size

```cpp
inline std::size_t size() const
```

Returns the total number of elements in the view. 

**Return**: Total element count. 

### function data

```cpp
inline const cumeric_t * data() const
```

Returns const raw data pointer. 

**Return**: Const pointer to underlying data. 

### function at

```cpp
inline const cumeric_t & at(
    const std::size_t row,
    const std::size_t col
) const
```

Indexed const element access. 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Const reference to element. 

### function operator()

```cpp
inline const cumeric_t & operator()(
    const std::size_t row,
    const std::size_t col
) const
```

Function call operator for indexed const element access. 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Const reference to element. 

### function set

```cpp
Matrix & set(
    const Matrix & other
)
```

Sets target matrix with viewed data. 

**Parameters**: 

  * **other** Target matrix. 


**Return**: Reference to modified matrix. 

### function transpose

```cpp
Matrix transpose() const
```


### function flatten

```cpp
Vector flatten() const
```


### function reshape

```cpp
Matrix reshape(
    std::size_t rows,
    std::size_t cols
) const
```


### function cwiseProduct

```cpp
Matrix cwiseProduct(
    const Matrix & other
)
```


### function transform

```cpp
Matrix transform(
    void(*)(cumeric_t *data, const std::size_t size) func
) const
```


### function transform

```cpp
Matrix transform(
    cumeric_t(*)(cumeric_t x) func
) const
```


### function clip

```cpp
Matrix clip(
    cumeric_t min,
    cumeric_t max
) const
```


### function norm

```cpp
cumeric_t norm()
```


### function squaredNorm

```cpp
cumeric_t squaredNorm()
```


### function colwiseSum

```cpp
Matrix colwiseSum()
```


### function colwiseSum2vec

```cpp
Vector colwiseSum2vec()
```


### function rowwiseSum

```cpp
Matrix rowwiseSum()
```


### function rowwiseSum2vec

```cpp
Vector rowwiseSum2vec()
```


### function shuffleRows

```cpp
Matrix shuffleRows() const
```


## Friends

### friend operator+

```cpp
friend Matrix operator+(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator-

```cpp
friend Matrix operator-(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator*

```cpp
friend Matrix operator*(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator*

```cpp
friend Matrix operator*(
    const Matrix & mat,

    const cumeric_t & scalar
);
```


### friend operator/

```cpp
friend Matrix operator/(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator/

```cpp
friend Matrix operator/(
    const Matrix & mat,

    const cumeric_t & scalar
);
```


### friend activation

```cpp
friend Matrix activation(
    const Matrix & mat,

    const char * name
);
```


### friend activationInPlace

```cpp
friend Matrix activationInPlace(
    Matrix & mat,

    const char * name
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100