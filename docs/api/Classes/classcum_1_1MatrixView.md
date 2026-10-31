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
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & other)<br>Constructs a view over an existing [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/) && other)<br>Move constructor.  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**(cumeric_t * source, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Constructs a view over a raw pointer buffer.  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, cumeric_t * source)<br>Constructs a view over a raw pointer buffer (dimensions first).  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**(const cumeric_t * source, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Constructs a view over a const raw pointer buffer.  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, const cumeric_t * source)<br>Constructs a view over a const raw pointer buffer (dimensions first).  |
| | **[MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-matrixview)**() =default<br>Default constructor creating an empty view.  |
| | **[~MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/#function-~matrixview)**()<br>Destructor (does not free viewed memory).  |
| std::size_t | **[rows](/CUM/api/Classes/classcum_1_1MatrixView/#function-rows)**() const<br>Returns the number of rows in the view.  |
| std::size_t | **[cols](/CUM/api/Classes/classcum_1_1MatrixView/#function-cols)**() const<br>Returns the number of columns in the view.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[row](/CUM/api/Classes/classcum_1_1MatrixView/#function-row)**(std::size_t i) const<br>Extracts a row as a new [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[col](/CUM/api/Classes/classcum_1_1MatrixView/#function-col)**(std::size_t i) const<br>Extracts a column as a new [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| std::size_t | **[size](/CUM/api/Classes/classcum_1_1MatrixView/#function-size)**() const<br>Returns the total number of elements in the view.  |
| const cumeric_t * | **[data](/CUM/api/Classes/classcum_1_1MatrixView/#function-data)**() const<br>Returns const raw data pointer.  |
| const cumeric_t & | **[at](/CUM/api/Classes/classcum_1_1MatrixView/#function-at)**(const std::size_t row, const std::size_t col) const<br>Indexed const element access.  |
| const cumeric_t & | **[operator()](/CUM/api/Classes/classcum_1_1MatrixView/#function-operator())**(const std::size_t row, const std::size_t col) const<br>Function call operator for indexed const element access.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & | **[set](/CUM/api/Classes/classcum_1_1MatrixView/#function-set)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & other)<br>Sets target matrix with viewed data.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[transpose](/CUM/api/Classes/classcum_1_1MatrixView/#function-transpose)**() const |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/) | **[flatten](/CUM/api/Classes/classcum_1_1MatrixView/#function-flatten)**() const |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[reshape](/CUM/api/Classes/classcum_1_1MatrixView/#function-reshape)**(std::size_t rows, std::size_t cols) const |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[cwiseProduct](/CUM/api/Classes/classcum_1_1MatrixView/#function-cwiseproduct)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[transform](/CUM/api/Classes/classcum_1_1MatrixView/#function-transform)**(void(*)(cumeric_t *[data](/CUM/api/Classes/classcum_1_1MatrixView/#function-data), const std::size_t [size](/CUM/api/Classes/classcum_1_1MatrixView/#function-size)) func) const |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[transform](/CUM/api/Classes/classcum_1_1MatrixView/#function-transform)**(cumeric_t(*)(cumeric_t x) func) const |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[clip](/CUM/api/Classes/classcum_1_1MatrixView/#function-clip)**(cumeric_t min, cumeric_t max) const |
| cumeric_t | **[norm](/CUM/api/Classes/classcum_1_1MatrixView/#function-norm)**() |
| cumeric_t | **[squaredNorm](/CUM/api/Classes/classcum_1_1MatrixView/#function-squarednorm)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[colwiseSum](/CUM/api/Classes/classcum_1_1MatrixView/#function-colwisesum)**() |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/) | **[colwiseSum2vec](/CUM/api/Classes/classcum_1_1MatrixView/#function-colwisesum2vec)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[rowwiseSum](/CUM/api/Classes/classcum_1_1MatrixView/#function-rowwisesum)**() |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/) | **[rowwiseSum2vec](/CUM/api/Classes/classcum_1_1MatrixView/#function-rowwisesum2vec)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[shuffleRows](/CUM/api/Classes/classcum_1_1MatrixView/#function-shufflerows)**() const |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator+](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator+)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator-](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator-)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator*](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator*)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator*](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator*)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & mat, const cumeric_t & scalar)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator/](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator/)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[operator/](/CUM/api/Classes/classcum_1_1MatrixView/#friend-operator/)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & mat, const cumeric_t & scalar)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[activation](/CUM/api/Classes/classcum_1_1MatrixView/#friend-activation)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & mat, const char * name)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) | **[activationInPlace](/CUM/api/Classes/classcum_1_1MatrixView/#friend-activationinplace)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/) & mat, const char * name)  |

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

Constructs a view over an existing [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to view. 


### function MatrixView

```cpp
MatrixView(
    Matrix && other
)
```

Move constructor. 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to view. 


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

Extracts a row as a new [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Parameters**: 

  * **i** Row index. 


**Return**: Extracted row [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

### function col

```cpp
Matrix col(
    std::size_t i
) const
```

Extracts a column as a new [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Parameters**: 

  * **i** Column index. 


**Return**: Extracted column [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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

Updated on 2026-10-31 at 18:51:12 +0100