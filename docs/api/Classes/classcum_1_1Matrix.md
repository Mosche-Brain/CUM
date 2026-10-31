---
title: cum::Matrix
summary: Templated generic dense matrix. 

---

# cum::Matrix



Templated generic dense matrix.  [More...](#detailed-description)


`#include <Matrix.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**()<br>Default constructor.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Constructs dynamic matrix of given dimensions.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**(std::span< T > data)<br>Constructs matrix by copying data from a span view.  |
| | **[~Matrix](Classes/classcum_1_1Matrix.md#function-~matrix)**() |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[rows](Classes/classcum_1_1Matrix.md#function-rows)**() const<br>Returns number of rows.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[cols](Classes/classcum_1_1Matrix.md#function-cols)**() const<br>Returns number of columns.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[elements](Classes/classcum_1_1Matrix.md#function-elements)**() const<br>Returns total number of elements.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, cols_, rows_ > | **[transpose](Classes/classcum_1_1Matrix.md#function-transpose)**() const<br>Transposes matrix out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, [Dynamic](Namespaces/namespacecum.md#variable-dynamic), [Dynamic](Namespaces/namespacecum.md#variable-dynamic) > | **[reshape](Classes/classcum_1_1Matrix.md#function-reshape)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols) const<br>Reshapes matrix into dynamic dimensions.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, [Dynamic](Namespaces/namespacecum.md#variable-dynamic), [Dynamic](Namespaces/namespacecum.md#variable-dynamic) > | **[flatten](Classes/classcum_1_1Matrix.md#function-flatten)**() const<br>Flattens matrix into 1 x elements row matrix.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator+=](Classes/classcum_1_1Matrix.md#function-operator+=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator-=](Classes/classcum_1_1Matrix.md#function-operator-=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator*=](Classes/classcum_1_1Matrix.md#function-operator*=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator/=](Classes/classcum_1_1Matrix.md#function-operator/=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator*=](Classes/classcum_1_1Matrix.md#function-operator*=)**(T scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, cols_ > & | **[operator/=](Classes/classcum_1_1Matrix.md#function-operator/=)**(T scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, rows_, [Dynamic](Namespaces/namespacecum.md#variable-dynamic) > | **[matmul](Classes/classcum_1_1Matrix.md#function-matmul)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< T, cols_, [Dynamic](Namespaces/namespacecum.md#variable-dynamic) > & other) const<br>Multiplies with another matrix: `result` = *this * other.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Constructs an uninitialized matrix of given dimensions.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, cumeric_t value)<br>Constructs a matrix of given dimensions filled with an initial scalar value.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, cumeric_t * source)<br>Constructs a matrix and copies data from a raw source buffer.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, const cumeric_t * source)<br>Constructs a matrix and copies data from a const raw source buffer.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, std::initializer_list< cumeric_t > elements)<br>Constructs a matrix from an initializer list of elements.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**(const Matrix & other)<br>Copy constructor performing deep copy of underlying buffer.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**(Matrix && other)<br>Move constructor transferring ownership of data buffer.  |
| | **[Matrix](Classes/classcum_1_1Matrix.md#function-matrix)**() =default<br>Default constructor creating an empty 0x0 matrix.  |
| | **[~Matrix](Classes/classcum_1_1Matrix.md#function-~matrix)**()<br>Destructor deallocating memory buffer.  |
| | **[operator Vector](Classes/classcum_1_1Matrix.md#function-operator-vector)**() const<br>Conversion operator from [Matrix](Classes/classcum_1_1Matrix.md) to [Vector]() (flattens into 1D vector).  |
| void | **[fill](Classes/classcum_1_1Matrix.md#function-fill)**(cumeric_t value)<br>Fills all matrix elements with a scalar value.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[rows](Classes/classcum_1_1Matrix.md#function-rows)**() const<br>Returns the number of rows.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[cols](Classes/classcum_1_1Matrix.md#function-cols)**() const<br>Returns the number of columns.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[row](Classes/classcum_1_1Matrix.md#function-row)**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) i) const<br>Extracts a row as a 1 x cols [Matrix](Classes/classcum_1_1Matrix.md).  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[col](Classes/classcum_1_1Matrix.md#function-col)**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) i) const<br>Extracts a column as a rows x 1 [Matrix](Classes/classcum_1_1Matrix.md).  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[size](Classes/classcum_1_1Matrix.md#function-size)**() const<br>Returns total number of elements (rows * cols).  |
| cumeric_t * | **[data](Classes/classcum_1_1Matrix.md#function-data)**()<br>Returns raw data pointer.  |
| const cumeric_t * | **[data](Classes/classcum_1_1Matrix.md#function-data)**() const<br>Returns const raw data pointer.  |
| cumeric_t & | **[at](Classes/classcum_1_1Matrix.md#function-at)**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) row, const [dim_t](Namespaces/namespacecum.md#using-dim-t) col)<br>Indexed element access (lvalue reference).  |
| const cumeric_t & | **[at](Classes/classcum_1_1Matrix.md#function-at)**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) row, const [dim_t](Namespaces/namespacecum.md#using-dim-t) col) const<br>Indexed element access (const reference).  |
| cumeric_t & | **[operator()](Classes/classcum_1_1Matrix.md#function-operator())**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) row, const [dim_t](Namespaces/namespacecum.md#using-dim-t) col)<br>Function call operator for indexed element access (lvalue reference).  |
| const cumeric_t & | **[operator()](Classes/classcum_1_1Matrix.md#function-operator())**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) row, const [dim_t](Namespaces/namespacecum.md#using-dim-t) col) const<br>Function call operator for indexed element access (const reference).  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[slice](Classes/classcum_1_1Matrix.md#function-slice)**([dim_t](Namespaces/namespacecum.md#using-dim-t) i, [dim_t](Namespaces/namespacecum.md#using-dim-t) j, [dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols) const<br>Extracts a submatrix block starting at (i, j).  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[set](Classes/classcum_1_1Matrix.md#function-set)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other)<br>Deep-copies data from another matrix into `*this`.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator=](Classes/classcum_1_1Matrix.md#function-operator=)**([Matrix](Classes/classcum_1_1Matrix.md#function-matrix) other)<br>Copy/move assignment operator via copy-and-swap idiom.  |
| void | **[swap](Classes/classcum_1_1Matrix.md#function-swap)**([Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other)<br>Swaps internal state with another matrix.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator+=](Classes/classcum_1_1Matrix.md#function-operator+=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator+=](Classes/classcum_1_1Matrix.md#function-operator+=)**(const cumeric_t & scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator-=](Classes/classcum_1_1Matrix.md#function-operator-=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator-=](Classes/classcum_1_1Matrix.md#function-operator-=)**(const cumeric_t & scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator*=](Classes/classcum_1_1Matrix.md#function-operator*=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator*=](Classes/classcum_1_1Matrix.md#function-operator*=)**(const cumeric_t & scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator/=](Classes/classcum_1_1Matrix.md#function-operator/=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[operator/=](Classes/classcum_1_1Matrix.md#function-operator/=)**(const cumeric_t & scalar) |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[transpose](Classes/classcum_1_1Matrix.md#function-transpose)**() const<br>Computes matrix transpose out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[transposeInPlace](Classes/classcum_1_1Matrix.md#function-transposeinplace)**()<br>Transposes matrix in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[flatten](Classes/classcum_1_1Matrix.md#function-flatten)**() const<br>Flattens matrix into 1 x (rows*cols) row matrix.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[reshape](Classes/classcum_1_1Matrix.md#function-reshape)**(const [dim_t](Namespaces/namespacecum.md#using-dim-t) rows, const [dim_t](Namespaces/namespacecum.md#using-dim-t) cols) const<br>Reshapes matrix into given dimensions out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[reshapeInPlace](Classes/classcum_1_1Matrix.md#function-reshapeinplace)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Reshapes matrix in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[cwiseProduct](Classes/classcum_1_1Matrix.md#function-cwiseproduct)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other)<br>Computes Hadamard (component-wise) product out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[cwiseProductInPlace](Classes/classcum_1_1Matrix.md#function-cwiseproductinplace)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & other)<br>Computes component-wise product in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[transform](Classes/classcum_1_1Matrix.md#function-transform)**(void(*)(cumeric_t *[data](Classes/classcum_1_1Matrix.md#function-data), const [dim_t](Namespaces/namespacecum.md#using-dim-t)[size](Classes/classcum_1_1Matrix.md#function-size)) func) const<br>Applies an elementwise array operation function out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[transformInPlace](Classes/classcum_1_1Matrix.md#function-transforminplace)**(void(*)(cumeric_t *[data](Classes/classcum_1_1Matrix.md#function-data), const [dim_t](Namespaces/namespacecum.md#using-dim-t)[size](Classes/classcum_1_1Matrix.md#function-size)) func)<br>Applies an elementwise array operation function in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[transform](Classes/classcum_1_1Matrix.md#function-transform)**(cumeric_t(*)(cumeric_t x) func) const<br>Applies a scalar transformation function to each element out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[transformInPlace](Classes/classcum_1_1Matrix.md#function-transforminplace)**(cumeric_t(*)(cumeric_t x) func)<br>Applies a scalar transformation function to each element in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[sin](Classes/classcum_1_1Matrix.md#function-sin)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[sinInPlace](Classes/classcum_1_1Matrix.md#function-sininplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[cos](Classes/classcum_1_1Matrix.md#function-cos)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[cosInPlace](Classes/classcum_1_1Matrix.md#function-cosinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[tan](Classes/classcum_1_1Matrix.md#function-tan)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[tanInPlace](Classes/classcum_1_1Matrix.md#function-taninplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[sinh](Classes/classcum_1_1Matrix.md#function-sinh)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[sinhInPlace](Classes/classcum_1_1Matrix.md#function-sinhinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[cosh](Classes/classcum_1_1Matrix.md#function-cosh)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[coshInPlace](Classes/classcum_1_1Matrix.md#function-coshinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[tanh](Classes/classcum_1_1Matrix.md#function-tanh)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[tanhInPlace](Classes/classcum_1_1Matrix.md#function-tanhinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[sqrt](Classes/classcum_1_1Matrix.md#function-sqrt)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[sqrtInPlace](Classes/classcum_1_1Matrix.md#function-sqrtinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[square](Classes/classcum_1_1Matrix.md#function-square)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[squareInPlace](Classes/classcum_1_1Matrix.md#function-squareinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[exp](Classes/classcum_1_1Matrix.md#function-exp)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[expInPlace](Classes/classcum_1_1Matrix.md#function-expinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[log](Classes/classcum_1_1Matrix.md#function-log)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[logInPlace](Classes/classcum_1_1Matrix.md#function-loginplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[relu](Classes/classcum_1_1Matrix.md#function-relu)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[reluInPlace](Classes/classcum_1_1Matrix.md#function-reluinplace)**() |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[rowwiseOpInPlace](Classes/classcum_1_1Matrix.md#function-rowwiseopinplace)**(void(*)(cumeric_t *[row](Classes/classcum_1_1Matrix.md#function-row), const cumeric_t *v, const [dim_t](Namespaces/namespacecum.md#using-dim-t)[cols](Classes/classcum_1_1Matrix.md#function-cols)) op, const cumeric_t * arr)<br>Applies an in-place row-wise vector operation across each row.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[colwiseOpInPlace](Classes/classcum_1_1Matrix.md#function-colwiseopinplace)**(void(*)(cumeric_t *[col](Classes/classcum_1_1Matrix.md#function-col), const cumeric_t *v, const [dim_t](Namespaces/namespacecum.md#using-dim-t)[rows](Classes/classcum_1_1Matrix.md#function-rows)) op, const cumeric_t * arr)<br>Applies an in-place column-wise vector operation across each column.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[clip](Classes/classcum_1_1Matrix.md#function-clip)**(const cumeric_t min, const cumeric_t max) const<br>Clamps all elements to [min, max] range out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[clipInPlace](Classes/classcum_1_1Matrix.md#function-clipinplace)**(const cumeric_t min, const cumeric_t max)<br>Clamps all elements to [min, max] range in-place.  |
| cumeric_t | **[norm](Classes/classcum_1_1Matrix.md#function-norm)**()<br>Computes Frobenius / L2 Euclidean norm.  |
| cumeric_t | **[squaredNorm](Classes/classcum_1_1Matrix.md#function-squarednorm)**()<br>Computes squared Frobenius norm.  |
| cumeric_t | **[sum](Classes/classcum_1_1Matrix.md#function-sum)**() const<br>Computes sum of all matrix elements.  |
| cumeric_t | **[sumAbs](Classes/classcum_1_1Matrix.md#function-sumabs)**() const<br>Computes sum of absolute values of all elements (L1 norm).  |
| cumeric_t | **[mean](Classes/classcum_1_1Matrix.md#function-mean)**() const<br>Computes arithmetic mean of all matrix elements.  |
| cumeric_t | **[amean](Classes/classcum_1_1Matrix.md#function-amean)**() const<br>Computes mean of absolute values of all matrix elements.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[colwiseSum](Classes/classcum_1_1Matrix.md#function-colwisesum)**()<br>Computes column-wise sums, returning a 1 x cols [Matrix](Classes/classcum_1_1Matrix.md).  |
| [Vector](Classes/classcum_1_1Vector.md) | **[colwiseSum2vec](Classes/classcum_1_1Matrix.md#function-colwisesum2vec)**()<br>Computes column-wise sums, returning a [Vector]().  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[rowwiseSum](Classes/classcum_1_1Matrix.md#function-rowwisesum)**()<br>Computes row-wise sums, returning a rows x 1 [Matrix](Classes/classcum_1_1Matrix.md).  |
| [Vector](Classes/classcum_1_1Vector.md) | **[rowwiseSum2vec](Classes/classcum_1_1Matrix.md#function-rowwisesum2vec)**()<br>Computes row-wise sums, returning a [Vector]().  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[shuffleRows](Classes/classcum_1_1Matrix.md#function-shufflerows)**() const<br>Shuffles rows randomly out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & | **[shuffleRowsInPlace](Classes/classcum_1_1Matrix.md#function-shufflerowsinplace)**()<br>Shuffles rows randomly in-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[Random](Classes/classcum_1_1Matrix.md#function-random)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, cumeric_t min =-1_c, cumeric_t max =1_c)<br>Creates a matrix initialized with uniformly distributed random numbers.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[Zeros](Classes/classcum_1_1Matrix.md#function-zeros)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Creates a matrix filled with zeros.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[Ones](Classes/classcum_1_1Matrix.md#function-ones)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols)<br>Creates a matrix filled with ones.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[Linspace](Classes/classcum_1_1Matrix.md#function-linspace)**(cumeric_t start, cumeric_t end, [dim_t](Namespaces/namespacecum.md#using-dim-t) num)<br>Creates a 1 x num row vector matrix with values linearly spaced between start and end.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[Copy](Classes/classcum_1_1Matrix.md#function-copy)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat)<br>Creates an explicit deep copy of a matrix.  |
| const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[View](Classes/classcum_1_1Matrix.md#function-view)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat)<br>Creates a non-owning read view of an existing matrix.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > | **[operator+](Classes/classcum_1_1Matrix.md#friend-operator+)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > | **[operator-](Classes/classcum_1_1Matrix.md#friend-operator-)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > | **[operator*](Classes/classcum_1_1Matrix.md#friend-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > | **[operator/](Classes/classcum_1_1Matrix.md#friend-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix)< Type, height, width > & rhs)  |
| void | **[swap](Classes/classcum_1_1Matrix.md#friend-swap)**([Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B) <br>Non-member swap function.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator+](Classes/classcum_1_1Matrix.md#friend-operator+)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator+](Classes/classcum_1_1Matrix.md#friend-operator+)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator+](Classes/classcum_1_1Matrix.md#friend-operator+)**(const cumeric_t scalar, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator-](Classes/classcum_1_1Matrix.md#friend-operator-)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator*](Classes/classcum_1_1Matrix.md#friend-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator*](Classes/classcum_1_1Matrix.md#friend-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator*](Classes/classcum_1_1Matrix.md#friend-operator*)**(const cumeric_t scalar, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator/](Classes/classcum_1_1Matrix.md#friend-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator/](Classes/classcum_1_1Matrix.md#friend-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[operator/](Classes/classcum_1_1Matrix.md#friend-operator/)**(const cumeric_t scalar, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat)  |
| bool | **[operator==](Classes/classcum_1_1Matrix.md#friend-operator==)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| bool | **[operator!=](Classes/classcum_1_1Matrix.md#friend-operator!=)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & A, const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & B)  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[activation](Classes/classcum_1_1Matrix.md#friend-activation)**(const [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat, const char * name) <br>Applies named neural activation function out-of-place.  |
| [Matrix](Classes/classcum_1_1Matrix.md#function-matrix) | **[activationInPlace](Classes/classcum_1_1Matrix.md#friend-activationinplace)**([Matrix](Classes/classcum_1_1Matrix.md#function-matrix) & mat, const char * name) <br>Applies named neural activation function in-place.  |

## Detailed Description

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
class cum::Matrix;
```

Templated generic dense matrix. 

**Template Parameters**: 

  * **T** Element type. 
  * **rows_** Row dimension (default Dynamic for runtime sizing). 
  * **cols_** Column dimension (default Dynamic for runtime sizing).


2D dense numerical matrix allocated in device unified memory.


Provides arithmetic operations, BLAS routines, in-place and out-of-place transformations, activation functions, slicing, and reductions. 

## Public Functions Documentation

### function Matrix

```cpp
Matrix()
```

Default constructor. 

### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols
)
```

Constructs dynamic matrix of given dimensions. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 


### function Matrix

```cpp
Matrix(
    std::span< T > data
)
```

Constructs matrix by copying data from a span view. 

**Parameters**: 

  * **data** Source span view. 


### function ~Matrix

```cpp
~Matrix()
```


### function rows

```cpp
dim_t rows() const
```

Returns number of rows. 

**Return**: Row count. 

### function cols

```cpp
dim_t cols() const
```

Returns number of columns. 

**Return**: Column count. 

### function elements

```cpp
dim_t elements() const
```

Returns total number of elements. 

**Return**: Element count. 

### function transpose

```cpp
Matrix< T, cols_, rows_ > transpose() const
```

Transposes matrix out-of-place. 

**Return**: Transposed [Matrix](Classes/classcum_1_1Matrix.md) of dimensions cols_ x rows_. 

### function reshape

```cpp
Matrix< T, Dynamic, Dynamic > reshape(
    dim_t rows,
    dim_t cols
) const
```

Reshapes matrix into dynamic dimensions. 

**Parameters**: 

  * **rows** New row count. 
  * **cols** New column count. 


**Return**: Reshaped dynamic [Matrix](Classes/classcum_1_1Matrix.md). 

### function flatten

```cpp
Matrix< T, Dynamic, Dynamic > flatten() const
```

Flattens matrix into 1 x elements row matrix. 

**Return**: Flattened dynamic [Matrix](Classes/classcum_1_1Matrix.md). 

### function operator+=

```cpp
Matrix< T, rows_, cols_ > & operator+=(
    const Matrix< T, rows_, cols_ > & other
)
```


### function operator-=

```cpp
Matrix< T, rows_, cols_ > & operator-=(
    const Matrix< T, rows_, cols_ > & other
)
```


### function operator*=

```cpp
Matrix< T, rows_, cols_ > & operator*=(
    const Matrix< T, rows_, cols_ > & other
)
```


### function operator/=

```cpp
Matrix< T, rows_, cols_ > & operator/=(
    const Matrix< T, rows_, cols_ > & other
)
```


### function operator*=

```cpp
Matrix< T, rows_, cols_ > & operator*=(
    T scalar
)
```


### function operator/=

```cpp
Matrix< T, rows_, cols_ > & operator/=(
    T scalar
)
```


### function matmul

```cpp
Matrix< T, rows_, Dynamic > matmul(
    const Matrix< T, cols_, Dynamic > & other
) const
```

Multiplies with another matrix: `result` = *this * other. 

**Parameters**: 

  * **other** Right matrix operand. 


**Return**: Product [Matrix](Classes/classcum_1_1Matrix.md). 

### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols
)
```

Constructs an uninitialized matrix of given dimensions. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 


### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols,
    cumeric_t value
)
```

Constructs a matrix of given dimensions filled with an initial scalar value. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **value** Initial value for each element. 


### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols,
    cumeric_t * source
)
```

Constructs a matrix and copies data from a raw source buffer. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **source** Pointer to source data to copy from. 


### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols,
    const cumeric_t * source
)
```

Constructs a matrix and copies data from a const raw source buffer. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **source** Pointer to const source data to copy from. 


### function Matrix

```cpp
Matrix(
    dim_t rows,
    dim_t cols,
    std::initializer_list< cumeric_t > elements
)
```

Constructs a matrix from an initializer list of elements. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **elements** Initializer list of cumeric_t elements. 


### function Matrix

```cpp
Matrix(
    const Matrix & other
)
```

Copy constructor performing deep copy of underlying buffer. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to copy from. 


### function Matrix

```cpp
Matrix(
    Matrix && other
)
```

Move constructor transferring ownership of data buffer. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to move from. 


### function Matrix

```cpp
Matrix() =default
```

Default constructor creating an empty 0x0 matrix. 

### function ~Matrix

```cpp
~Matrix()
```

Destructor deallocating memory buffer. 

### function operator Vector

```cpp
operator Vector() const
```

Conversion operator from [Matrix](Classes/classcum_1_1Matrix.md) to [Vector]() (flattens into 1D vector). 

**Return**: [Vector](Classes/classcum_1_1Vector.md) representation. 

### function fill

```cpp
void fill(
    cumeric_t value
)
```

Fills all matrix elements with a scalar value. 

**Parameters**: 

  * **value** Scalar value to write. 


### function rows

```cpp
inline dim_t rows() const
```

Returns the number of rows. 

**Return**: Row count. 

### function cols

```cpp
inline dim_t cols() const
```

Returns the number of columns. 

**Return**: Column count. 

### function row

```cpp
Matrix row(
    const dim_t i
) const
```

Extracts a row as a 1 x cols [Matrix](Classes/classcum_1_1Matrix.md). 

**Parameters**: 

  * **i** Zero-based row index. 


**Return**: 1 x cols [Matrix](Classes/classcum_1_1Matrix.md). 

### function col

```cpp
Matrix col(
    const dim_t i
) const
```

Extracts a column as a rows x 1 [Matrix](Classes/classcum_1_1Matrix.md). 

**Parameters**: 

  * **i** Zero-based column index. 


**Return**: rows x 1 [Matrix](Classes/classcum_1_1Matrix.md). 

### function size

```cpp
inline dim_t size() const
```

Returns total number of elements (rows * cols). 

**Return**: Total element count. 

### function data

```cpp
inline cumeric_t * data()
```

Returns raw data pointer. 

**Return**: Pointer to underlying cumeric_t buffer. 

### function data

```cpp
inline const cumeric_t * data() const
```

Returns const raw data pointer. 

**Return**: Const pointer to underlying cumeric_t buffer. 

### function at

```cpp
inline cumeric_t & at(
    const dim_t row,
    const dim_t col
)
```

Indexed element access (lvalue reference). 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Reference to the element at (row, col). 

### function at

```cpp
inline const cumeric_t & at(
    const dim_t row,
    const dim_t col
) const
```

Indexed element access (const reference). 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Const reference to the element at (row, col). 

### function operator()

```cpp
inline cumeric_t & operator()(
    const dim_t row,
    const dim_t col
)
```

Function call operator for indexed element access (lvalue reference). 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Reference to the element at (row, col). 

### function operator()

```cpp
inline const cumeric_t & operator()(
    const dim_t row,
    const dim_t col
) const
```

Function call operator for indexed element access (const reference). 

**Parameters**: 

  * **row** Row index. 
  * **col** Column index. 


**Return**: Const reference to the element at (row, col). 

### function slice

```cpp
Matrix slice(
    dim_t i,
    dim_t j,
    dim_t rows,
    dim_t cols
) const
```

Extracts a submatrix block starting at (i, j). 

**Parameters**: 

  * **i** Starting row index. 
  * **j** Starting column index. 
  * **rows** Number of rows in submatrix. 
  * **cols** Number of columns in submatrix. 


**Return**: Extracted submatrix. 

### function set

```cpp
Matrix & set(
    const Matrix & other
)
```

Deep-copies data from another matrix into `*this`. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to copy from. 


**Return**: Reference to `*this`. 

### function operator=

```cpp
Matrix & operator=(
    Matrix other
)
```

Copy/move assignment operator via copy-and-swap idiom. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) passed by value. 


**Return**: Reference to `*this`. 

### function swap

```cpp
void swap(
    Matrix & other
)
```

Swaps internal state with another matrix. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) to swap with. 


### function operator+=

```cpp
Matrix & operator+=(
    const Matrix & other
)
```


### function operator+=

```cpp
Matrix & operator+=(
    const cumeric_t & scalar
)
```


### function operator-=

```cpp
Matrix & operator-=(
    const Matrix & other
)
```


### function operator-=

```cpp
Matrix & operator-=(
    const cumeric_t & scalar
)
```


### function operator*=

```cpp
Matrix & operator*=(
    const Matrix & other
)
```


### function operator*=

```cpp
Matrix & operator*=(
    const cumeric_t & scalar
)
```


### function operator/=

```cpp
Matrix & operator/=(
    const Matrix & other
)
```


### function operator/=

```cpp
Matrix & operator/=(
    const cumeric_t & scalar
)
```


### function transpose

```cpp
Matrix transpose() const
```

Computes matrix transpose out-of-place. 

**Return**: Transposed cols x rows [Matrix](Classes/classcum_1_1Matrix.md). 

### function transposeInPlace

```cpp
Matrix & transposeInPlace()
```

Transposes matrix in-place. 

**Return**: Reference to `*this`. 

### function flatten

```cpp
Matrix flatten() const
```

Flattens matrix into 1 x (rows*cols) row matrix. 

**Return**: Flattened matrix. 

### function reshape

```cpp
Matrix reshape(
    const dim_t rows,
    const dim_t cols
) const
```

Reshapes matrix into given dimensions out-of-place. 

**Parameters**: 

  * **rows** New row count. 
  * **cols** New column count. 


**Return**: Reshaped matrix. 

### function reshapeInPlace

```cpp
Matrix & reshapeInPlace(
    dim_t rows,
    dim_t cols
)
```

Reshapes matrix in-place. 

**Parameters**: 

  * **rows** New row count. 
  * **cols** New column count. 


**Return**: Reference to `*this`. 

### function cwiseProduct

```cpp
Matrix cwiseProduct(
    const Matrix & other
)
```

Computes Hadamard (component-wise) product out-of-place. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) of identical dimensions. 


**Return**: Component-wise product matrix. 

### function cwiseProductInPlace

```cpp
Matrix & cwiseProductInPlace(
    const Matrix & other
)
```

Computes component-wise product in-place. 

**Parameters**: 

  * **other** [Matrix](Classes/classcum_1_1Matrix.md) of identical dimensions. 


**Return**: Reference to `*this`. 

### function transform

```cpp
Matrix transform(
    void(*)(cumeric_t *data, const dim_tsize) func
) const
```

Applies an elementwise array operation function out-of-place. 

**Parameters**: 

  * **func** Function pointer accepting data pointer and size. 


**Return**: Transformed matrix. 

### function transformInPlace

```cpp
Matrix & transformInPlace(
    void(*)(cumeric_t *data, const dim_tsize) func
)
```

Applies an elementwise array operation function in-place. 

**Parameters**: 

  * **func** Function pointer accepting data pointer and size. 


**Return**: Reference to `*this`. 

### function transform

```cpp
Matrix transform(
    cumeric_t(*)(cumeric_t x) func
) const
```

Applies a scalar transformation function to each element out-of-place. 

**Parameters**: 

  * **func** Function pointer mapping scalar to scalar. 


**Return**: Transformed matrix. 

### function transformInPlace

```cpp
Matrix & transformInPlace(
    cumeric_t(*)(cumeric_t x) func
)
```

Applies a scalar transformation function to each element in-place. 

**Parameters**: 

  * **func** Function pointer mapping scalar to scalar. 


**Return**: Reference to `*this`. 

### function sin

```cpp
Matrix sin()
```


### function sinInPlace

```cpp
Matrix & sinInPlace()
```


### function cos

```cpp
Matrix cos()
```


### function cosInPlace

```cpp
Matrix & cosInPlace()
```


### function tan

```cpp
Matrix tan()
```


### function tanInPlace

```cpp
Matrix & tanInPlace()
```


### function sinh

```cpp
Matrix sinh()
```


### function sinhInPlace

```cpp
Matrix & sinhInPlace()
```


### function cosh

```cpp
Matrix cosh()
```


### function coshInPlace

```cpp
Matrix & coshInPlace()
```


### function tanh

```cpp
Matrix tanh()
```


### function tanhInPlace

```cpp
Matrix & tanhInPlace()
```


### function sqrt

```cpp
Matrix sqrt()
```


### function sqrtInPlace

```cpp
Matrix & sqrtInPlace()
```


### function square

```cpp
Matrix square()
```


### function squareInPlace

```cpp
Matrix & squareInPlace()
```


### function exp

```cpp
Matrix exp()
```


### function expInPlace

```cpp
Matrix & expInPlace()
```


### function log

```cpp
Matrix log()
```


### function logInPlace

```cpp
Matrix & logInPlace()
```


### function relu

```cpp
Matrix relu()
```


### function reluInPlace

```cpp
Matrix & reluInPlace()
```


### function rowwiseOpInPlace

```cpp
Matrix & rowwiseOpInPlace(
    void(*)(cumeric_t *row, const cumeric_t *v, const dim_tcols) op,
    const cumeric_t * arr
)
```

Applies an in-place row-wise vector operation across each row. 

**Parameters**: 

  * **op** Operation function receiving row pointer, vector pointer, and column count. 
  * **arr** Row-length array operand. 


**Return**: Reference to `*this`. 

### function colwiseOpInPlace

```cpp
Matrix & colwiseOpInPlace(
    void(*)(cumeric_t *col, const cumeric_t *v, const dim_trows) op,
    const cumeric_t * arr
)
```

Applies an in-place column-wise vector operation across each column. 

**Parameters**: 

  * **op** Operation function receiving column pointer, vector pointer, and row count. 
  * **arr** Column-length array operand. 


**Return**: Reference to `*this`. 

### function clip

```cpp
Matrix clip(
    const cumeric_t min,
    const cumeric_t max
) const
```

Clamps all elements to [min, max] range out-of-place. 

**Parameters**: 

  * **min** Minimum boundary value. 
  * **max** Maximum boundary value. 


**Return**: Clamped matrix. 

### function clipInPlace

```cpp
Matrix & clipInPlace(
    const cumeric_t min,
    const cumeric_t max
)
```

Clamps all elements to [min, max] range in-place. 

**Parameters**: 

  * **min** Minimum boundary value. 
  * **max** Maximum boundary value. 


**Return**: Reference to `*this`. 

### function norm

```cpp
cumeric_t norm()
```

Computes Frobenius / L2 Euclidean norm. 

**Return**: Norm value. 

### function squaredNorm

```cpp
cumeric_t squaredNorm()
```

Computes squared Frobenius norm. 

**Return**: Squared norm value. 

### function sum

```cpp
cumeric_t sum() const
```

Computes sum of all matrix elements. 

**Return**: Scalar sum. 

### function sumAbs

```cpp
cumeric_t sumAbs() const
```

Computes sum of absolute values of all elements (L1 norm). 

**Return**: L1 norm. 

### function mean

```cpp
cumeric_t mean() const
```

Computes arithmetic mean of all matrix elements. 

**Return**: Mean value. 

### function amean

```cpp
cumeric_t amean() const
```

Computes mean of absolute values of all matrix elements. 

**Return**: Absolute mean value. 

### function colwiseSum

```cpp
Matrix colwiseSum()
```

Computes column-wise sums, returning a 1 x cols [Matrix](Classes/classcum_1_1Matrix.md). 

**Return**: 1 x cols [Matrix](Classes/classcum_1_1Matrix.md) containing sum of each column. 

### function colwiseSum2vec

```cpp
Vector colwiseSum2vec()
```

Computes column-wise sums, returning a [Vector](). 

**Return**: [Vector](Classes/classcum_1_1Vector.md) of column sums. 

### function rowwiseSum

```cpp
Matrix rowwiseSum()
```

Computes row-wise sums, returning a rows x 1 [Matrix](Classes/classcum_1_1Matrix.md). 

**Return**: rows x 1 [Matrix](Classes/classcum_1_1Matrix.md) containing sum of each row. 

### function rowwiseSum2vec

```cpp
Vector rowwiseSum2vec()
```

Computes row-wise sums, returning a [Vector](). 

**Return**: [Vector](Classes/classcum_1_1Vector.md) of row sums. 

### function shuffleRows

```cpp
Matrix shuffleRows() const
```

Shuffles rows randomly out-of-place. 

**Return**: [Matrix](Classes/classcum_1_1Matrix.md) with shuffled rows. 

### function shuffleRowsInPlace

```cpp
Matrix & shuffleRowsInPlace()
```

Shuffles rows randomly in-place. 

**Return**: Reference to `*this`. 

### function Random

```cpp
static Matrix Random(
    dim_t rows,
    dim_t cols,
    cumeric_t min =-1_c,
    cumeric_t max =1_c
)
```

Creates a matrix initialized with uniformly distributed random numbers. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **min** Minimum random value (default -1.0). 
  * **max** Maximum random value (default 1.0). 


**Return**: Randomly initialized matrix. 

### function Zeros

```cpp
static Matrix Zeros(
    dim_t rows,
    dim_t cols
)
```

Creates a matrix filled with zeros. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 


**Return**: Zero-filled matrix. 

### function Ones

```cpp
static Matrix Ones(
    dim_t rows,
    dim_t cols
)
```

Creates a matrix filled with ones. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 


**Return**: Ones-filled matrix. 

### function Linspace

```cpp
static Matrix Linspace(
    cumeric_t start,
    cumeric_t end,
    dim_t num
)
```

Creates a 1 x num row vector matrix with values linearly spaced between start and end. 

**Parameters**: 

  * **start** Initial value. 
  * **end** Final value. 
  * **num** Number of linearly spaced elements. 


**Return**: 1 x num [Matrix](Classes/classcum_1_1Matrix.md) row vector. 

### function Copy

```cpp
static Matrix Copy(
    const Matrix & mat
)
```

Creates an explicit deep copy of a matrix. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) to copy. 


**Return**: Cloned matrix. 

### function View

```cpp
static const Matrix View(
    const Matrix & mat
)
```

Creates a non-owning read view of an existing matrix. 

**Parameters**: 

  * **mat** Source matrix. 


**Return**: Const matrix view. 

## Friends

### friend operator+

```cpp
friend Matrix< Type, height, width > operator+(
    const Matrix< Type, height, width > & lhs,

    const Matrix< Type, height, width > & rhs
);
```


### friend operator-

```cpp
friend Matrix< Type, height, width > operator-(
    const Matrix< Type, height, width > & lhs,

    const Matrix< Type, height, width > & rhs
);
```


### friend operator*

```cpp
friend Matrix< Type, height, width > operator*(
    const Matrix< Type, height, width > & lhs,

    const Matrix< Type, height, width > & rhs
);
```


### friend operator/

```cpp
friend Matrix< Type, height, width > operator/(
    const Matrix< Type, height, width > & lhs,

    const Matrix< Type, height, width > & rhs
);
```


### friend swap

```cpp
friend void swap(
    Matrix & A,

    Matrix & B
);
```

Non-member swap function. 

**Parameters**: 

  * **A** First matrix. 
  * **B** Second matrix. 


### friend operator+

```cpp
friend Matrix operator+(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator+

```cpp
friend Matrix operator+(
    const Matrix & mat,

    cumeric_t scalar
);
```


### friend operator+

```cpp
friend Matrix operator+(
    const cumeric_t scalar,

    const Matrix & mat
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

    cumeric_t scalar
);
```


### friend operator*

```cpp
friend Matrix operator*(
    const cumeric_t scalar,

    const Matrix & mat
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

    cumeric_t scalar
);
```


### friend operator/

```cpp
friend Matrix operator/(
    const cumeric_t scalar,

    const Matrix & mat
);
```


### friend operator==

```cpp
friend bool operator==(
    const Matrix & A,

    const Matrix & B
);
```


### friend operator!=

```cpp
friend bool operator!=(
    const Matrix & A,

    const Matrix & B
);
```


### friend activation

```cpp
friend Matrix activation(
    const Matrix & mat,

    const char * name
);
```

Applies named neural activation function out-of-place. 

**Parameters**: 

  * **mat** Input matrix. 
  * **name** Activation function name (e.g. "relu", "sigmoid", "tanh"). 


**Return**: Activated matrix. 

### friend activationInPlace

```cpp
friend Matrix activationInPlace(
    Matrix & mat,

    const char * name
);
```

Applies named neural activation function in-place. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) to activate in-place. 
  * **name** Activation function name. 


**Return**: Reference to modified matrix. 

-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100