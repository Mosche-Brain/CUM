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
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**()<br>Default constructor.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Constructs dynamic matrix of given dimensions.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**(std::span< T > data)<br>Constructs matrix by copying data from a span view.  |
| | **[~Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-~matrix)**() |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[rows](/CUM/api/Classes/classcum_1_1Matrix/#function-rows)**() const<br>Returns number of rows.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[cols](/CUM/api/Classes/classcum_1_1Matrix/#function-cols)**() const<br>Returns number of columns.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[elements](/CUM/api/Classes/classcum_1_1Matrix/#function-elements)**() const<br>Returns total number of elements.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, cols_, rows_ > | **[transpose](/CUM/api/Classes/classcum_1_1Matrix/#function-transpose)**() const<br>Transposes matrix out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic), [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic) > | **[reshape](/CUM/api/Classes/classcum_1_1Matrix/#function-reshape)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols) const<br>Reshapes matrix into dynamic dimensions.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic), [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic) > | **[flatten](/CUM/api/Classes/classcum_1_1Matrix/#function-flatten)**() const<br>Flattens matrix into 1 x elements row matrix.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator+=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator+=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator-=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator-=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator*=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator*=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator/=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator/=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator*=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator*=)**(T scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, cols_ > & | **[operator/=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator/=)**(T scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, rows_, [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic) > | **[matmul](/CUM/api/Classes/classcum_1_1Matrix/#function-matmul)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< T, cols_, [Dynamic](/CUM/api/Namespaces/namespacecum/#variable-dynamic) > & other) const<br>Multiplies with another matrix: `result` = *this * other.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Constructs an uninitialized matrix of given dimensions.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, cumeric_t value)<br>Constructs a matrix of given dimensions filled with an initial scalar value.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, cumeric_t * source)<br>Constructs a matrix and copies data from a raw source buffer.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, const cumeric_t * source)<br>Constructs a matrix and copies data from a const raw source buffer.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, std::initializer_list< cumeric_t > elements)<br>Constructs a matrix from an initializer list of elements.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**(const Matrix & other)<br>Copy constructor performing deep copy of underlying buffer.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**(Matrix && other)<br>Move constructor transferring ownership of data buffer.  |
| | **[Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)**() =default<br>Default constructor creating an empty 0x0 matrix.  |
| | **[~Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-~matrix)**()<br>Destructor deallocating memory buffer.  |
| | **[operator Vector](/CUM/api/Classes/classcum_1_1Matrix/#function-operator-vector)**() const<br>Conversion operator from [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to [Vector]() (flattens into 1D vector).  |
| void | **[fill](/CUM/api/Classes/classcum_1_1Matrix/#function-fill)**(cumeric_t value)<br>Fills all matrix elements with a scalar value.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[rows](/CUM/api/Classes/classcum_1_1Matrix/#function-rows)**() const<br>Returns the number of rows.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[cols](/CUM/api/Classes/classcum_1_1Matrix/#function-cols)**() const<br>Returns the number of columns.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[row](/CUM/api/Classes/classcum_1_1Matrix/#function-row)**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) i) const<br>Extracts a row as a 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[col](/CUM/api/Classes/classcum_1_1Matrix/#function-col)**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) i) const<br>Extracts a column as a rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[size](/CUM/api/Classes/classcum_1_1Matrix/#function-size)**() const<br>Returns total number of elements (rows * cols).  |
| cumeric_t * | **[data](/CUM/api/Classes/classcum_1_1Matrix/#function-data)**()<br>Returns raw data pointer.  |
| const cumeric_t * | **[data](/CUM/api/Classes/classcum_1_1Matrix/#function-data)**() const<br>Returns const raw data pointer.  |
| cumeric_t & | **[at](/CUM/api/Classes/classcum_1_1Matrix/#function-at)**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) row, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) col)<br>Indexed element access (lvalue reference).  |
| const cumeric_t & | **[at](/CUM/api/Classes/classcum_1_1Matrix/#function-at)**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) row, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) col) const<br>Indexed element access (const reference).  |
| cumeric_t & | **[operator()](/CUM/api/Classes/classcum_1_1Matrix/#function-operator())**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) row, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) col)<br>Function call operator for indexed element access (lvalue reference).  |
| const cumeric_t & | **[operator()](/CUM/api/Classes/classcum_1_1Matrix/#function-operator())**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) row, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) col) const<br>Function call operator for indexed element access (const reference).  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[slice](/CUM/api/Classes/classcum_1_1Matrix/#function-slice)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) i, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) j, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols) const<br>Extracts a submatrix block starting at (i, j).  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[set](/CUM/api/Classes/classcum_1_1Matrix/#function-set)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other)<br>Deep-copies data from another matrix into `*this`.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator=)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) other)<br>Copy/move assignment operator via copy-and-swap idiom.  |
| void | **[swap](/CUM/api/Classes/classcum_1_1Matrix/#function-swap)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other)<br>Swaps internal state with another matrix.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator+=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator+=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator+=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator+=)**(const cumeric_t & scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator-=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator-=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator-=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator-=)**(const cumeric_t & scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator*=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator*=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator*=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator*=)**(const cumeric_t & scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator/=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator/=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[operator/=](/CUM/api/Classes/classcum_1_1Matrix/#function-operator/=)**(const cumeric_t & scalar) |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[transpose](/CUM/api/Classes/classcum_1_1Matrix/#function-transpose)**() const<br>Computes matrix transpose out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[transposeInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-transposeinplace)**()<br>Transposes matrix in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[flatten](/CUM/api/Classes/classcum_1_1Matrix/#function-flatten)**() const<br>Flattens matrix into 1 x (rows*cols) row matrix.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[reshape](/CUM/api/Classes/classcum_1_1Matrix/#function-reshape)**(const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols) const<br>Reshapes matrix into given dimensions out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[reshapeInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-reshapeinplace)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Reshapes matrix in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[cwiseProduct](/CUM/api/Classes/classcum_1_1Matrix/#function-cwiseproduct)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other)<br>Computes Hadamard (component-wise) product out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[cwiseProductInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-cwiseproductinplace)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & other)<br>Computes component-wise product in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[transform](/CUM/api/Classes/classcum_1_1Matrix/#function-transform)**(void(*)(cumeric_t *[data](/CUM/api/Classes/classcum_1_1Matrix/#function-data), const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t)[size](/CUM/api/Classes/classcum_1_1Matrix/#function-size)) func) const<br>Applies an elementwise array operation function out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[transformInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-transforminplace)**(void(*)(cumeric_t *[data](/CUM/api/Classes/classcum_1_1Matrix/#function-data), const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t)[size](/CUM/api/Classes/classcum_1_1Matrix/#function-size)) func)<br>Applies an elementwise array operation function in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[transform](/CUM/api/Classes/classcum_1_1Matrix/#function-transform)**(cumeric_t(*)(cumeric_t x) func) const<br>Applies a scalar transformation function to each element out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[transformInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-transforminplace)**(cumeric_t(*)(cumeric_t x) func)<br>Applies a scalar transformation function to each element in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[sin](/CUM/api/Classes/classcum_1_1Matrix/#function-sin)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[sinInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-sininplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[cos](/CUM/api/Classes/classcum_1_1Matrix/#function-cos)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[cosInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-cosinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[tan](/CUM/api/Classes/classcum_1_1Matrix/#function-tan)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[tanInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-taninplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[sinh](/CUM/api/Classes/classcum_1_1Matrix/#function-sinh)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[sinhInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-sinhinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[cosh](/CUM/api/Classes/classcum_1_1Matrix/#function-cosh)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[coshInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-coshinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[tanh](/CUM/api/Classes/classcum_1_1Matrix/#function-tanh)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[tanhInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-tanhinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[sqrt](/CUM/api/Classes/classcum_1_1Matrix/#function-sqrt)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[sqrtInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-sqrtinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[square](/CUM/api/Classes/classcum_1_1Matrix/#function-square)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[squareInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-squareinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[exp](/CUM/api/Classes/classcum_1_1Matrix/#function-exp)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[expInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-expinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[log](/CUM/api/Classes/classcum_1_1Matrix/#function-log)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[logInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-loginplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[relu](/CUM/api/Classes/classcum_1_1Matrix/#function-relu)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[reluInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-reluinplace)**() |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[rowwiseOpInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-rowwiseopinplace)**(void(*)(cumeric_t *[row](/CUM/api/Classes/classcum_1_1Matrix/#function-row), const cumeric_t *v, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t)[cols](/CUM/api/Classes/classcum_1_1Matrix/#function-cols)) op, const cumeric_t * arr)<br>Applies an in-place row-wise vector operation across each row.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[colwiseOpInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-colwiseopinplace)**(void(*)(cumeric_t *[col](/CUM/api/Classes/classcum_1_1Matrix/#function-col), const cumeric_t *v, const [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t)[rows](/CUM/api/Classes/classcum_1_1Matrix/#function-rows)) op, const cumeric_t * arr)<br>Applies an in-place column-wise vector operation across each column.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[clip](/CUM/api/Classes/classcum_1_1Matrix/#function-clip)**(const cumeric_t min, const cumeric_t max) const<br>Clamps all elements to [min, max] range out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[clipInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-clipinplace)**(const cumeric_t min, const cumeric_t max)<br>Clamps all elements to [min, max] range in-place.  |
| cumeric_t | **[norm](/CUM/api/Classes/classcum_1_1Matrix/#function-norm)**()<br>Computes Frobenius / L2 Euclidean norm.  |
| cumeric_t | **[squaredNorm](/CUM/api/Classes/classcum_1_1Matrix/#function-squarednorm)**()<br>Computes squared Frobenius norm.  |
| cumeric_t | **[sum](/CUM/api/Classes/classcum_1_1Matrix/#function-sum)**() const<br>Computes sum of all matrix elements.  |
| cumeric_t | **[sumAbs](/CUM/api/Classes/classcum_1_1Matrix/#function-sumabs)**() const<br>Computes sum of absolute values of all elements (L1 norm).  |
| cumeric_t | **[mean](/CUM/api/Classes/classcum_1_1Matrix/#function-mean)**() const<br>Computes arithmetic mean of all matrix elements.  |
| cumeric_t | **[amean](/CUM/api/Classes/classcum_1_1Matrix/#function-amean)**() const<br>Computes mean of absolute values of all matrix elements.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[colwiseSum](/CUM/api/Classes/classcum_1_1Matrix/#function-colwisesum)**()<br>Computes column-wise sums, returning a 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/) | **[colwiseSum2vec](/CUM/api/Classes/classcum_1_1Matrix/#function-colwisesum2vec)**()<br>Computes column-wise sums, returning a [Vector]().  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[rowwiseSum](/CUM/api/Classes/classcum_1_1Matrix/#function-rowwisesum)**()<br>Computes row-wise sums, returning a rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/).  |
| [Vector](/CUM/api/Classes/classcum_1_1Vector/) | **[rowwiseSum2vec](/CUM/api/Classes/classcum_1_1Matrix/#function-rowwisesum2vec)**()<br>Computes row-wise sums, returning a [Vector]().  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[shuffleRows](/CUM/api/Classes/classcum_1_1Matrix/#function-shufflerows)**() const<br>Shuffles rows randomly out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & | **[shuffleRowsInPlace](/CUM/api/Classes/classcum_1_1Matrix/#function-shufflerowsinplace)**()<br>Shuffles rows randomly in-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[Random](/CUM/api/Classes/classcum_1_1Matrix/#function-random)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols, cumeric_t min =-1_c, cumeric_t max =1_c)<br>Creates a matrix initialized with uniformly distributed random numbers.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[Zeros](/CUM/api/Classes/classcum_1_1Matrix/#function-zeros)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Creates a matrix filled with zeros.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[Ones](/CUM/api/Classes/classcum_1_1Matrix/#function-ones)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) rows, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) cols)<br>Creates a matrix filled with ones.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[Linspace](/CUM/api/Classes/classcum_1_1Matrix/#function-linspace)**(cumeric_t start, cumeric_t end, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) num)<br>Creates a 1 x num row vector matrix with values linearly spaced between start and end.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[Copy](/CUM/api/Classes/classcum_1_1Matrix/#function-copy)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat)<br>Creates an explicit deep copy of a matrix.  |
| const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[View](/CUM/api/Classes/classcum_1_1Matrix/#function-view)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat)<br>Creates a non-owning read view of an existing matrix.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > | **[operator+](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator+)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & lhs, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > | **[operator-](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator-)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & lhs, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > | **[operator*](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator*)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & lhs, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & rhs)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > | **[operator/](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator/)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & lhs, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix)< Type, height, width > & rhs)  |
| void | **[swap](/CUM/api/Classes/classcum_1_1Matrix/#friend-swap)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B) <br>Non-member swap function.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator+](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator+)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator+](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator+)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator+](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator+)**(const cumeric_t scalar, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator-](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator-)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator*](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator*)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator*](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator*)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator*](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator*)**(const cumeric_t scalar, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator/](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator/)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator/](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator/)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat, cumeric_t scalar)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[operator/](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator/)**(const cumeric_t scalar, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat)  |
| bool | **[operator==](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator==)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| bool | **[operator!=](/CUM/api/Classes/classcum_1_1Matrix/#friend-operator!=)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & A, const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & B)  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[activation](/CUM/api/Classes/classcum_1_1Matrix/#friend-activation)**(const [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat, const char * name) <br>Applies named neural activation function out-of-place.  |
| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) | **[activationInPlace](/CUM/api/Classes/classcum_1_1Matrix/#friend-activationinplace)**([Matrix](/CUM/api/Classes/classcum_1_1Matrix/#function-matrix) & mat, const char * name) <br>Applies named neural activation function in-place.  |

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

**Return**: Transposed [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) of dimensions cols_ x rows_. 

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


**Return**: Reshaped dynamic [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

### function flatten

```cpp
Matrix< T, Dynamic, Dynamic > flatten() const
```

Flattens matrix into 1 x elements row matrix. 

**Return**: Flattened dynamic [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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


**Return**: Product [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to copy from. 


### function Matrix

```cpp
Matrix(
    Matrix && other
)
```

Move constructor transferring ownership of data buffer. 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to move from. 


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

Conversion operator from [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to [Vector]() (flattens into 1D vector). 

**Return**: [Vector](/CUM/api/Classes/classcum_1_1Vector/) representation. 

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

Extracts a row as a 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Parameters**: 

  * **i** Zero-based row index. 


**Return**: 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

### function col

```cpp
Matrix col(
    const dim_t i
) const
```

Extracts a column as a rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Parameters**: 

  * **i** Zero-based column index. 


**Return**: rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to copy from. 


**Return**: Reference to `*this`. 

### function operator=

```cpp
Matrix & operator=(
    Matrix other
)
```

Copy/move assignment operator via copy-and-swap idiom. 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) passed by value. 


**Return**: Reference to `*this`. 

### function swap

```cpp
void swap(
    Matrix & other
)
```

Swaps internal state with another matrix. 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to swap with. 


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

**Return**: Transposed cols x rows [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

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

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) of identical dimensions. 


**Return**: Component-wise product matrix. 

### function cwiseProductInPlace

```cpp
Matrix & cwiseProductInPlace(
    const Matrix & other
)
```

Computes component-wise product in-place. 

**Parameters**: 

  * **other** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) of identical dimensions. 


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

Computes column-wise sums, returning a 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Return**: 1 x cols [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) containing sum of each column. 

### function colwiseSum2vec

```cpp
Vector colwiseSum2vec()
```

Computes column-wise sums, returning a [Vector](). 

**Return**: [Vector](/CUM/api/Classes/classcum_1_1Vector/) of column sums. 

### function rowwiseSum

```cpp
Matrix rowwiseSum()
```

Computes row-wise sums, returning a rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/). 

**Return**: rows x 1 [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) containing sum of each row. 

### function rowwiseSum2vec

```cpp
Vector rowwiseSum2vec()
```

Computes row-wise sums, returning a [Vector](). 

**Return**: [Vector](/CUM/api/Classes/classcum_1_1Vector/) of row sums. 

### function shuffleRows

```cpp
Matrix shuffleRows() const
```

Shuffles rows randomly out-of-place. 

**Return**: [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) with shuffled rows. 

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


**Return**: 1 x num [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) row vector. 

### function Copy

```cpp
static Matrix Copy(
    const Matrix & mat
)
```

Creates an explicit deep copy of a matrix. 

**Parameters**: 

  * **mat** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to copy. 


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

  * **mat** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) to activate in-place. 
  * **name** Activation function name. 


**Return**: Reference to modified matrix. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100