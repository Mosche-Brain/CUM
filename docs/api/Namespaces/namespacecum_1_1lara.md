---
title: cum::lara

---

# cum::lara



## Functions

|                | Name           |
| -------------- | -------------- |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mmul](Namespaces/namespacecum_1_1lara.md#function-mmul)**(cumeric_t * C, const cumeric_t * A, const cumeric_t * B, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) k, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={})<br>Asynchronous matrix multiplication: `C` = `A` * `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mmul](Namespaces/namespacecum_1_1lara.md#function-mmul)**(cumeric_t * A, const cumeric_t * B, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) k)<br>In-place matrix multiplication: `A` = `A` * `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mmul](Namespaces/namespacecum_1_1lara.md#function-mmul)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * C, const void * A, const void * B, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) k, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={}) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mmul](Namespaces/namespacecum_1_1lara.md#function-mmul)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * A, const void * B, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) k, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={}) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mtrans](Namespaces/namespacecum_1_1lara.md#function-mtrans)**(cumeric_t * At, const cumeric_t * A, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={})<br>Asynchronous matrix transpose: `At` = `A^T`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mtrans](Namespaces/namespacecum_1_1lara.md#function-mtrans)**(cumeric_t * A, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={})<br>Asynchronous in-place matrix transpose for square matrices.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mtrans](Namespaces/namespacecum_1_1lara.md#function-mtrans)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * At, const void * A, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={}) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mtrans](Namespaces/namespacecum_1_1lara.md#function-mtrans)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * A, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [__events__](Namespaces/namespacecum.md#using---events--) depencies ={}) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[rwise_sum](Namespaces/namespacecum_1_1lara.md#function-rwise-sum)**(cumeric_t * r, cumeric_t * mat, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes row-wise sums of matrix `mat` into vector `r`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[cwise_sum](Namespaces/namespacecum_1_1lara.md#function-cwise-sum)**(cumeric_t * r, cumeric_t * mat, [dim_t](Namespaces/namespacecum.md#using-dim-t) m, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes column-wise sums of matrix `mat` into vector `r`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sum](Namespaces/namespacecum_1_1lara.md#function-sum)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes sum of all elements in vector `v`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[asum](Namespaces/namespacecum_1_1lara.md#function-asum)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes sum of absolute values (L1 norm) of vector `v`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mean](Namespaces/namespacecum_1_1lara.md#function-mean)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes arithmetic mean of elements in vector `v`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[amean](Namespaces/namespacecum_1_1lara.md#function-amean)**(cumeric_t * r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Computes mean of absolute values of elements in vector `v`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd](Namespaces/namespacecum_1_1lara.md#function-vadd)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous elementwise vector addition: `r` = `v` + `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd](Namespaces/namespacecum_1_1lara.md#function-vadd)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd](Namespaces/namespacecum_1_1lara.md#function-vadd)**(cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous in-place vector addition: `v` += `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd](Namespaces/namespacecum_1_1lara.md#function-vadd)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size)<br>Batched vector addition out-of-place across `batch_size` vectors.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**(cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size)<br>Batched vector addition in-place across `batch_size` vectors.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**(cumeric_t * r, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_r, const cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size)<br>Strided batched vector addition out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_r, const void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**(cumeric_t * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vadd_batch](Namespaces/namespacecum_1_1lara.md#function-vadd-batch)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vsub](Namespaces/namespacecum_1_1lara.md#function-vsub)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous elementwise vector subtraction: `r` = `v` - `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vsub](Namespaces/namespacecum_1_1lara.md#function-vsub)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vsub](Namespaces/namespacecum_1_1lara.md#function-vsub)**(cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous in-place vector subtraction: `v` -= `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vsub](Namespaces/namespacecum_1_1lara.md#function-vsub)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vmul](Namespaces/namespacecum_1_1lara.md#function-vmul)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous elementwise vector multiplication: `r` = `v` * `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vmul](Namespaces/namespacecum_1_1lara.md#function-vmul)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vmul](Namespaces/namespacecum_1_1lara.md#function-vmul)**(cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous in-place vector multiplication: `v` *= `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vmul](Namespaces/namespacecum_1_1lara.md#function-vmul)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vdiv](Namespaces/namespacecum_1_1lara.md#function-vdiv)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous elementwise vector division: `r` = `v` / `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vdiv](Namespaces/namespacecum_1_1lara.md#function-vdiv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vdiv](Namespaces/namespacecum_1_1lara.md#function-vdiv)**(cumeric_t * v, const cumeric_t * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n)<br>Asynchronous in-place vector division: `v` /= `u`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[vdiv](Namespaces/namespacecum_1_1lara.md#function-vdiv)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * v, const void * u, [dim_t](Namespaces/namespacecum.md#using-dim-t) n) |
| void | **[add](Namespaces/namespacecum_1_1lara.md#function-add)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise vector addition: `r` = `v` + `u`.  |
| void | **[addInPlace](Namespaces/namespacecum_1_1lara.md#function-addinplace)**(cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes in-place elementwise vector addition: `v` += `u`.  |
| void | **[add](Namespaces/namespacecum_1_1lara.md#function-add)**(cumeric_t * r, const cumeric_t * v, const cumeric_t & a, std::size_t N)<br>Adds scalar `a` to each element of vector `v:``r` = `v` + `a`.  |
| void | **[addInPlace](Namespaces/namespacecum_1_1lara.md#function-addinplace)**(cumeric_t * v, const cumeric_t & a, std::size_t N)<br>Adds scalar `a` to each element of vector `v` in-place: `v` += `a`.  |
| void | **[sum](Namespaces/namespacecum_1_1lara.md#function-sum)**(cumeric_t & r, const cumeric_t * v, std::size_t N)<br>Computes the sum of all elements in vector `v`.  |
| void | **[asum](Namespaces/namespacecum_1_1lara.md#function-asum)**(cumeric_t & r, const cumeric_t * v, std::size_t N)<br>Computes the sum of absolute values (L1 norm) of vector `v`.  |
| void | **[cwiseProduct](Namespaces/namespacecum_1_1lara.md#function-cwiseproduct)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise (Hadamard) product: `r` = `v` * `u`.  |
| void | **[cwiseProductInPlace](Namespaces/namespacecum_1_1lara.md#function-cwiseproductinplace)**(cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise product in-place: `v` *= `u`.  |
| void | **[scale](Namespaces/namespacecum_1_1lara.md#function-scale)**(cumeric_t * r, const cumeric_t * v, const cumeric_t & a, const std::size_t n)<br>Multiplies vector elements by scalar: `r` = `v` * `a`.  |
| void | **[scaleInPlace](Namespaces/namespacecum_1_1lara.md#function-scaleinplace)**(cumeric_t * v, const cumeric_t & a, const std::size_t n)<br>Multiplies vector elements by scalar in-place: `v` *= `a`.  |
| void | **[sub](Namespaces/namespacecum_1_1lara.md#function-sub)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise subtraction: `r` = `v` - `u`.  |
| void | **[subInPlace](Namespaces/namespacecum_1_1lara.md#function-subinplace)**(cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise subtraction in-place: `v` -= `u`.  |
| void | **[div](Namespaces/namespacecum_1_1lara.md#function-div)**(cumeric_t * r, const cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise division: `r` = `v` / `u`.  |
| void | **[divInPlace](Namespaces/namespacecum_1_1lara.md#function-divinplace)**(cumeric_t * v, const cumeric_t * u, std::size_t N)<br>Computes elementwise division in-place: `v` /= `u`.  |
| void | **[argmax](Namespaces/namespacecum_1_1lara.md#function-argmax)**(cumeric_t * r, const cumeric_t * v, std::size_t N)<br>Finds the index of the maximum element in vector `v`.  |
| void | **[argmin](Namespaces/namespacecum_1_1lara.md#function-argmin)**(cumeric_t * r, const cumeric_t * v, std::size_t N)<br>Finds the index of the minimum element in vector `v`.  |
| void | **[matAdd](Namespaces/namespacecum_1_1lara.md#function-matadd)**(cumeric_t * C, const cumeric_t * A, const cumeric_t * B, std::size_t rows, std::size_t cols)<br>Computes matrix addition: `C` = `A` + `B`.  |
| void | **[matAddInPlace](Namespaces/namespacecum_1_1lara.md#function-mataddinplace)**(cumeric_t * A, const cumeric_t * B, std::size_t rows, std::size_t cols)<br>Computes matrix addition in-place: `A` += `B`.  |
| void | **[addRowVectorInPlace](Namespaces/namespacecum_1_1lara.md#function-addrowvectorinplace)**(cumeric_t * matrix, const cumeric_t * row_vector, std::size_t rows, std::size_t cols)<br>Adds a row vector to every row of matrix `matrix` in-place.  |
| void | **[matSub](Namespaces/namespacecum_1_1lara.md#function-matsub)**(cumeric_t * C, const cumeric_t * A, const cumeric_t * B, std::size_t rows, std::size_t cols)<br>Computes matrix subtraction: `C` = `A` - `B`.  |
| void | **[matSubInPlace](Namespaces/namespacecum_1_1lara.md#function-matsubinplace)**(cumeric_t * A, const cumeric_t * B, std::size_t rows, std::size_t cols)<br>Computes matrix subtraction in-place: `A` -= `B`.  |
| void | **[matMul](Namespaces/namespacecum_1_1lara.md#function-matmul)**(cumeric_t * C, const cumeric_t * A, const cumeric_t * B, std::size_t m, std::size_t n, std::size_t k)<br>Computes general matrix multiplication (GEMM): `C` = `A` * `B`.  |
| void | **[matMulInPlace](Namespaces/namespacecum_1_1lara.md#function-matmulinplace)**(cumeric_t * A, const cumeric_t * B, std::size_t m, std::size_t n, std::size_t k)<br>In-place matrix multiplication: `A` = `A` * `B`.  |
| void | **[matVecMul](Namespaces/namespacecum_1_1lara.md#function-matvecmul)**(cumeric_t * r, const cumeric_t * A, const cumeric_t * v, std::size_t rows, std::size_t cols)<br>Computes matrix-vector multiplication (GEMV): `r` = `A` * `v`.  |
| void | **[matScale](Namespaces/namespacecum_1_1lara.md#function-matscale)**(cumeric_t * mat, const cumeric_t * old, const cumeric_t & a, const std::size_t & rows, const std::size_t & cols)<br>Scales all elements of matrix: `mat` = `old` * `a`.  |
| void | **[matScaleInPlace](Namespaces/namespacecum_1_1lara.md#function-matscaleinplace)**(cumeric_t * mat, const cumeric_t & a, const std::size_t & rows, const std::size_t & cols)<br>Scales all elements of matrix in-place: `mat` *= `a`.  |
| void | **[transpose](Namespaces/namespacecum_1_1lara.md#function-transpose)**(cumeric_t * A, const cumeric_t * B, std::size_t rows, std::size_t cols)<br>Computes matrix transpose: `A` = `B^T`.  |
| void | **[transposeInPlace](Namespaces/namespacecum_1_1lara.md#function-transposeinplace)**(cumeric_t * mat, std::size_t rows, std::size_t cols)<br>Transposes square matrix in-place.  |
| void | **[rowwiseOpInPlace](Namespaces/namespacecum_1_1lara.md#function-rowwiseopinplace)**(cumeric_t * mat, const cumeric_t * arr, std::size_t rows, std::size_t cols, void(*)(cumeric_t *row, const cumeric_t *v, const std::size_t cols) op)<br>Applies row-wise custom operation across rows in-place.  |
| void | **[colwiseOpInPlace](Namespaces/namespacecum_1_1lara.md#function-colwiseopinplace)**(cumeric_t * mat, const cumeric_t * arr, std::size_t rows, std::size_t cols, void(*)(cumeric_t *col, const cumeric_t *v, const std::size_t rows) op)<br>Applies column-wise custom operation across columns in-place.  |
| void | **[rowwiseSum](Namespaces/namespacecum_1_1lara.md#function-rowwisesum)**(cumeric_t * r, const cumeric_t * mat, std::size_t rows, std::size_t cols)<br>Computes row-wise sums into vector `r`.  |
| void | **[colwiseSum](Namespaces/namespacecum_1_1lara.md#function-colwisesum)**(cumeric_t * r, const cumeric_t * mat, std::size_t rows, std::size_t cols)<br>Computes column-wise sums into vector `r`.  |
| void | **[transform](Namespaces/namespacecum_1_1lara.md#function-transform)**(cumeric_t * mat, const cumeric_t * old, void(*)(cumeric_t *data, const std::size_t size) func)<br>Applies buffer transformation function out-of-place.  |
| void | **[transformInPlace](Namespaces/namespacecum_1_1lara.md#function-transforminplace)**(cumeric_t * mat, void(*)(cumeric_t *data, const std::size_t size) func)<br>Applies buffer transformation function in-place.  |
| void | **[transform](Namespaces/namespacecum_1_1lara.md#function-transform)**(cumeric_t * mat, const cumeric_t * old, cumeric_t(*)(cumeric_t x) func, std::size_t N)<br>Applies scalar function to all elements out-of-place.  |
| void | **[transformInPlace](Namespaces/namespacecum_1_1lara.md#function-transforminplace)**(cumeric_t * mat, cumeric_t(*)(cumeric_t x) func, std::size_t N)<br>Applies scalar function to all elements in-place.  |
| void | **[norm](Namespaces/namespacecum_1_1lara.md#function-norm)**(cumeric_t & r, const cumeric_t * v, std::size_t N)<br>Computes Euclidean L2 norm of vector: `r` = ||`v||_2`.  |
| void | **[normInplace](Namespaces/namespacecum_1_1lara.md#function-norminplace)**(cumeric_t * v, std::size_t N)<br>Computes Euclidean L2 norm in-place.  |
| void | **[squaredNorm](Namespaces/namespacecum_1_1lara.md#function-squarednorm)**(cumeric_t & r, const cumeric_t * v, std::size_t N)<br>Computes squared Euclidean L2 norm: `r` = ||`v||_2^2`.  |
| void | **[normalize](Namespaces/namespacecum_1_1lara.md#function-normalize)**(cumeric_t * r, const cumeric_t * v, std::size_t N)<br>Normalizes vector to unit L2 norm out-of-place: `r` = `v` / ||`v||_2`.  |
| void | **[normalizeInPlace](Namespaces/namespacecum_1_1lara.md#function-normalizeinplace)**(cumeric_t * v, std::size_t N)<br>Normalizes vector to unit L2 norm in-place: `v` /= ||`v||_2`.  |


## Functions Documentation

### function mmul

```cpp
__event__ mmul(
    cumeric_t * C,
    const cumeric_t * A,
    const cumeric_t * B,
    dim_t m,
    dim_t n,
    dim_t k,
    __events__ depencies ={}
)
```

Asynchronous matrix multiplication: `C` = `A` * `B`. 

**Parameters**: 

  * **C** Output matrix buffer (m x n). 
  * **A** Left input matrix buffer (m x k). 
  * **B** Right input matrix buffer (k x n). 
  * **m** Rows of A and C. 
  * **n** Columns of B and C. 
  * **k** Inner dimension. 
  * **depencies** Event dependencies to wait on before executing. 


**Return**: Asynchronous execution event. 

### function mmul

```cpp
__event__ mmul(
    cumeric_t * A,
    const cumeric_t * B,
    dim_t m,
    dim_t n,
    dim_t k
)
```

In-place matrix multiplication: `A` = `A` * `B`. 

**Parameters**: 

  * **A** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **B** Right input matrix buffer. 
  * **m** Rows of A. 
  * **n** Columns of B. 
  * **k** Inner dimension. 


**Return**: Asynchronous execution event. 

### function mmul

```cpp
__event__ mmul(
    datatype dtype,
    void * C,
    const void * A,
    const void * B,
    dim_t m,
    dim_t n,
    dim_t k,
    __events__ depencies ={}
)
```


### function mmul

```cpp
__event__ mmul(
    datatype dtype,
    void * A,
    const void * B,
    dim_t m,
    dim_t n,
    dim_t k,
    __events__ depencies ={}
)
```


### function mtrans

```cpp
__event__ mtrans(
    cumeric_t * At,
    const cumeric_t * A,
    dim_t m,
    dim_t n,
    __events__ depencies ={}
)
```

Asynchronous matrix transpose: `At` = `A^T`. 

**Parameters**: 

  * **At** Output transposed buffer (n x m). 
  * **A** Input matrix buffer (m x n). 
  * **m** Rows of input matrix A. 
  * **n** Columns of input matrix A. 
  * **depencies** Event dependencies. 


**Return**: Asynchronous execution event. 

### function mtrans

```cpp
__event__ mtrans(
    cumeric_t * A,
    dim_t m,
    dim_t n,
    __events__ depencies ={}
)
```

Asynchronous in-place matrix transpose for square matrices. 

**Parameters**: 

  * **A** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **m** Rows of matrix A. 
  * **n** Columns of matrix A. 
  * **depencies** Event dependencies. 


**Return**: Asynchronous execution event. 

### function mtrans

```cpp
__event__ mtrans(
    datatype dtype,
    void * At,
    const void * A,
    dim_t m,
    dim_t n,
    __events__ depencies ={}
)
```


### function mtrans

```cpp
__event__ mtrans(
    datatype dtype,
    void * A,
    dim_t m,
    dim_t n,
    __events__ depencies ={}
)
```


### function rwise_sum

```cpp
__event__ rwise_sum(
    cumeric_t * r,
    cumeric_t * mat,
    dim_t m,
    dim_t n
)
```

Computes row-wise sums of matrix `mat` into vector `r`. 

**Parameters**: 

  * **r** Output vector buffer of length `m`. 
  * **mat** Input matrix buffer of dimensions `m` x `n`. 
  * **m** Row count. 
  * **n** Column count. 


**Return**: Asynchronous execution event. 

### function cwise_sum

```cpp
__event__ cwise_sum(
    cumeric_t * r,
    cumeric_t * mat,
    dim_t m,
    dim_t n
)
```

Computes column-wise sums of matrix `mat` into vector `r`. 

**Parameters**: 

  * **r** Output vector buffer of length `n`. 
  * **mat** Input matrix buffer of dimensions `m` x `n`. 
  * **m** Row count. 
  * **n** Column count. 


**Return**: Asynchronous execution event. 

### function sum

```cpp
__event__ sum(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t n
)
```

Computes sum of all elements in vector `v`. 

**Parameters**: 

  * **r** Output scalar result pointer. 
  * **v** Input vector buffer. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Asynchronous execution event. 

### function asum

```cpp
__event__ asum(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t n
)
```

Computes sum of absolute values (L1 norm) of vector `v`. 

**Parameters**: 

  * **r** Output scalar result pointer. 
  * **v** Input vector buffer. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Asynchronous execution event. 

### function mean

```cpp
__event__ mean(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t n
)
```

Computes arithmetic mean of elements in vector `v`. 

**Parameters**: 

  * **r** Output scalar result pointer. 
  * **v** Input vector buffer. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Asynchronous execution event. 

### function amean

```cpp
__event__ amean(
    cumeric_t * r,
    const cumeric_t * v,
    dim_t n
)
```

Computes mean of absolute values of elements in vector `v`. 

**Parameters**: 

  * **r** Output scalar result pointer. 
  * **v** Input vector buffer. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 


**Return**: Asynchronous execution event. 

### function vadd

```cpp
__event__ vadd(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous elementwise vector addition: `r` = `v` + `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** Second input vector buffer. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vadd

```cpp
__event__ vadd(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    dim_t n
)
```


### function vadd

```cpp
__event__ vadd(
    cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous in-place vector addition: `v` += `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** [Vector](Classes/classcum_1_1Vector.md) buffer to add. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vadd

```cpp
__event__ vadd(
    datatype dtype,
    void * v,
    const void * u,
    dim_t n
)
```


### function vadd_batch

```cpp
__event__ vadd_batch(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    dim_t n,
    dim_t batch_size
)
```

Batched vector addition out-of-place across `batch_size` vectors. 

**Parameters**: 

  * **r** Output batch buffer. 
  * **v** First input batch buffer. 
  * **u** Second input batch buffer. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 
  * **batch_size** Number of vectors in batch. 


**Return**: Asynchronous execution event. 

### function vadd_batch

```cpp
__event__ vadd_batch(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    dim_t n,
    dim_t batch_size
)
```


### function vadd_batch

```cpp
__event__ vadd_batch(
    cumeric_t * v,
    const cumeric_t * u,
    dim_t n,
    dim_t batch_size
)
```

Batched vector addition in-place across `batch_size` vectors. 

**Parameters**: 

  * **v** Batch buffer modified in place. 
  * **u** Batch buffer to add. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 
  * **batch_size** Number of vectors in batch. 


**Return**: Asynchronous execution event. 

### function vadd_batch

```cpp
__event__ vadd_batch(
    datatype dtype,
    void * v,
    const void * u,
    dim_t n,
    dim_t batch_size
)
```


### function vadd_batch

```cpp
__event__ vadd_batch(
    cumeric_t * r,
    dim_t stride_r,
    const cumeric_t * v,
    dim_t stride_v,
    const cumeric_t * u,
    dim_t stride_u,
    dim_t n,
    dim_t batch_size
)
```

Strided batched vector addition out-of-place. 

**Parameters**: 

  * **r** Output batch buffer. 
  * **stride_r** Stride between batch vectors in r. 
  * **v** First input batch buffer. 
  * **stride_v** Stride between batch vectors in v. 
  * **u** Second input batch buffer. 
  * **stride_u** Stride between batch vectors in u. 
  * **n** [Vector](Classes/classcum_1_1Vector.md) length. 
  * **batch_size** Number of vectors in batch. 


**Return**: Asynchronous execution event. 

### function vadd_batch

```cpp
__event__ vadd_batch(
    datatype dtype,
    void * r,
    dim_t stride_r,
    const void * v,
    dim_t stride_v,
    const void * u,
    dim_t stride_u,
    dim_t n,
    dim_t batch_size
)
```


### function vadd_batch

```cpp
__event__ vadd_batch(
    cumeric_t * v,
    dim_t stride_v,
    const cumeric_t * u,
    dim_t stride_u,
    dim_t n,
    dim_t batch_size
)
```


### function vadd_batch

```cpp
__event__ vadd_batch(
    datatype dtype,
    void * v,
    dim_t stride_v,
    const void * u,
    dim_t stride_u,
    dim_t n,
    dim_t batch_size
)
```


### function vsub

```cpp
__event__ vsub(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous elementwise vector subtraction: `r` = `v` - `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** [Vector](Classes/classcum_1_1Vector.md) buffer to subtract. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vsub

```cpp
__event__ vsub(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    dim_t n
)
```


### function vsub

```cpp
__event__ vsub(
    cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous in-place vector subtraction: `v` -= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** [Vector](Classes/classcum_1_1Vector.md) buffer to subtract. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vsub

```cpp
__event__ vsub(
    datatype dtype,
    void * v,
    const void * u,
    dim_t n
)
```


### function vmul

```cpp
__event__ vmul(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous elementwise vector multiplication: `r` = `v` * `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** Second input vector buffer. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vmul

```cpp
__event__ vmul(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    dim_t n
)
```


### function vmul

```cpp
__event__ vmul(
    cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous in-place vector multiplication: `v` *= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** [Vector](Classes/classcum_1_1Vector.md) multiplier buffer. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vmul

```cpp
__event__ vmul(
    datatype dtype,
    void * v,
    const void * u,
    dim_t n
)
```


### function vdiv

```cpp
__event__ vdiv(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous elementwise vector division: `r` = `v` / `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Numerator vector buffer. 
  * **u** Denominator vector buffer. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vdiv

```cpp
__event__ vdiv(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    dim_t n
)
```


### function vdiv

```cpp
__event__ vdiv(
    cumeric_t * v,
    const cumeric_t * u,
    dim_t n
)
```

Asynchronous in-place vector division: `v` /= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** Denominator vector buffer. 
  * **n** Number of elements. 


**Return**: Asynchronous execution event. 

### function vdiv

```cpp
__event__ vdiv(
    datatype dtype,
    void * v,
    const void * u,
    dim_t n
)
```


### function add

```cpp
void add(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise vector addition: `r` = `v` + `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** Second input vector buffer. 
  * **N** Number of elements. 


### function addInPlace

```cpp
void addInPlace(
    cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes in-place elementwise vector addition: `v` += `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** [Vector](Classes/classcum_1_1Vector.md) buffer to add. 
  * **N** Number of elements. 


### function add

```cpp
void add(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t & a,
    std::size_t N
)
```

Adds scalar `a` to each element of vector `v:``r` = `v` + `a`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **a** Scalar value to add. 
  * **N** Number of elements. 


### function addInPlace

```cpp
void addInPlace(
    cumeric_t * v,
    const cumeric_t & a,
    std::size_t N
)
```

Adds scalar `a` to each element of vector `v` in-place: `v` += `a`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **a** Scalar value to add. 
  * **N** Number of elements. 


### function sum

```cpp
void sum(
    cumeric_t & r,
    const cumeric_t * v,
    std::size_t N
)
```

Computes the sum of all elements in vector `v`. 

**Parameters**: 

  * **r** Output scalar result. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function asum

```cpp
void asum(
    cumeric_t & r,
    const cumeric_t * v,
    std::size_t N
)
```

Computes the sum of absolute values (L1 norm) of vector `v`. 

**Parameters**: 

  * **r** Output scalar result. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function cwiseProduct

```cpp
void cwiseProduct(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise (Hadamard) product: `r` = `v` * `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** Second input vector buffer. 
  * **N** Number of elements. 


### function cwiseProductInPlace

```cpp
void cwiseProductInPlace(
    cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise product in-place: `v` *= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** Input vector buffer multiplier. 
  * **N** Number of elements. 


### function scale

```cpp
void scale(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t & a,
    const std::size_t n
)
```

Multiplies vector elements by scalar: `r` = `v` * `a`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Input vector buffer. 
  * **a** Scalar multiplier. 
  * **n** Number of elements. 


### function scaleInPlace

```cpp
void scaleInPlace(
    cumeric_t * v,
    const cumeric_t & a,
    const std::size_t n
)
```

Multiplies vector elements by scalar in-place: `v` *= `a`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **a** Scalar multiplier. 
  * **n** Number of elements. 


### function sub

```cpp
void sub(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise subtraction: `r` = `v` - `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** First input vector buffer. 
  * **u** Second input vector buffer. 
  * **N** Number of elements. 


### function subInPlace

```cpp
void subInPlace(
    cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise subtraction in-place: `v` -= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** Input vector buffer to subtract. 
  * **N** Number of elements. 


### function div

```cpp
void div(
    cumeric_t * r,
    const cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise division: `r` = `v` / `u`. 

**Parameters**: 

  * **r** Output vector buffer. 
  * **v** Numerator vector buffer. 
  * **u** Denominator vector buffer. 
  * **N** Number of elements. 


### function divInPlace

```cpp
void divInPlace(
    cumeric_t * v,
    const cumeric_t * u,
    std::size_t N
)
```

Computes elementwise division in-place: `v` /= `u`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer modified in place. 
  * **u** Denominator vector buffer. 
  * **N** Number of elements. 


### function argmax

```cpp
void argmax(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N
)
```

Finds the index of the maximum element in vector `v`. 

**Parameters**: 

  * **r** Output scalar storing the index. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function argmin

```cpp
void argmin(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N
)
```

Finds the index of the minimum element in vector `v`. 

**Parameters**: 

  * **r** Output scalar storing the index. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function matAdd

```cpp
void matAdd(
    cumeric_t * C,
    const cumeric_t * A,
    const cumeric_t * B,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix addition: `C` = `A` + `B`. 

**Parameters**: 

  * **C** Output matrix buffer. 
  * **A** First input matrix. 
  * **B** Second input matrix. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matAddInPlace

```cpp
void matAddInPlace(
    cumeric_t * A,
    const cumeric_t * B,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix addition in-place: `A` += `B`. 

**Parameters**: 

  * **A** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **B** [Matrix](Classes/classcum_1_1Matrix.md) to add. 
  * **rows** Row count. 
  * **cols** Column count. 


### function addRowVectorInPlace

```cpp
void addRowVectorInPlace(
    cumeric_t * matrix,
    const cumeric_t * row_vector,
    std::size_t rows,
    std::size_t cols
)
```

Adds a row vector to every row of matrix `matrix` in-place. 

**Parameters**: 

  * **matrix** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **row_vector** Row vector of length `cols`. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matSub

```cpp
void matSub(
    cumeric_t * C,
    const cumeric_t * A,
    const cumeric_t * B,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix subtraction: `C` = `A` - `B`. 

**Parameters**: 

  * **C** Output matrix buffer. 
  * **A** First input matrix. 
  * **B** [Matrix](Classes/classcum_1_1Matrix.md) to subtract. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matSubInPlace

```cpp
void matSubInPlace(
    cumeric_t * A,
    const cumeric_t * B,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix subtraction in-place: `A` -= `B`. 

**Parameters**: 

  * **A** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **B** [Matrix](Classes/classcum_1_1Matrix.md) to subtract. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matMul

```cpp
void matMul(
    cumeric_t * C,
    const cumeric_t * A,
    const cumeric_t * B,
    std::size_t m,
    std::size_t n,
    std::size_t k
)
```

Computes general matrix multiplication (GEMM): `C` = `A` * `B`. 

**Parameters**: 

  * **C** Output matrix buffer of size `m` x `n`. 
  * **A** Left input matrix of size `m` x `k`. 
  * **B** Right input matrix of size `k` x `n`. 
  * **m** Number of rows of A and C. 
  * **n** Number of columns of B and C. 
  * **k** Number of columns of A and rows of B. 


### function matMulInPlace

```cpp
void matMulInPlace(
    cumeric_t * A,
    const cumeric_t * B,
    std::size_t m,
    std::size_t n,
    std::size_t k
)
```

In-place matrix multiplication: `A` = `A` * `B`. 

**Parameters**: 

  * **A** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **B** Right input matrix. 
  * **m** Rows of A. 
  * **n** Columns of B. 
  * **k** Columns of A. 


### function matVecMul

```cpp
void matVecMul(
    cumeric_t * r,
    const cumeric_t * A,
    const cumeric_t * v,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix-vector multiplication (GEMV): `r` = `A` * `v`. 

**Parameters**: 

  * **r** Output vector of length `rows`. 
  * **A** Input matrix of size `rows` x `cols`. 
  * **v** Input vector of length `cols`. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matScale

```cpp
void matScale(
    cumeric_t * mat,
    const cumeric_t * old,
    const cumeric_t & a,
    const std::size_t & rows,
    const std::size_t & cols
)
```

Scales all elements of matrix: `mat` = `old` * `a`. 

**Parameters**: 

  * **mat** Output matrix buffer. 
  * **old** Input matrix buffer. 
  * **a** Scalar multiplier. 
  * **rows** Row count. 
  * **cols** Column count. 


### function matScaleInPlace

```cpp
void matScaleInPlace(
    cumeric_t * mat,
    const cumeric_t & a,
    const std::size_t & rows,
    const std::size_t & cols
)
```

Scales all elements of matrix in-place: `mat` *= `a`. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **a** Scalar multiplier. 
  * **rows** Row count. 
  * **cols** Column count. 


### function transpose

```cpp
void transpose(
    cumeric_t * A,
    const cumeric_t * B,
    std::size_t rows,
    std::size_t cols
)
```

Computes matrix transpose: `A` = `B^T`. 

**Parameters**: 

  * **A** Output matrix buffer of size `cols` x `rows`. 
  * **B** Input matrix buffer of size `rows` x `cols`. 
  * **rows** Number of rows in B. 
  * **cols** Number of columns in B. 


### function transposeInPlace

```cpp
void transposeInPlace(
    cumeric_t * mat,
    std::size_t rows,
    std::size_t cols
)
```

Transposes square matrix in-place. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **rows** Row count. 
  * **cols** Column count. 


### function rowwiseOpInPlace

```cpp
void rowwiseOpInPlace(
    cumeric_t * mat,
    const cumeric_t * arr,
    std::size_t rows,
    std::size_t cols,
    void(*)(cumeric_t *row, const cumeric_t *v, const std::size_t cols) op
)
```

Applies row-wise custom operation across rows in-place. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **arr** Row-length array operand. 
  * **rows** Row count. 
  * **cols** Column count. 
  * **op** Function pointer performing row-level computation. 


### function colwiseOpInPlace

```cpp
void colwiseOpInPlace(
    cumeric_t * mat,
    const cumeric_t * arr,
    std::size_t rows,
    std::size_t cols,
    void(*)(cumeric_t *col, const cumeric_t *v, const std::size_t rows) op
)
```

Applies column-wise custom operation across columns in-place. 

**Parameters**: 

  * **mat** [Matrix](Classes/classcum_1_1Matrix.md) buffer modified in place. 
  * **arr** Column-length array operand. 
  * **rows** Row count. 
  * **cols** Column count. 
  * **op** Function pointer performing column-level computation. 


### function rowwiseSum

```cpp
void rowwiseSum(
    cumeric_t * r,
    const cumeric_t * mat,
    std::size_t rows,
    std::size_t cols
)
```

Computes row-wise sums into vector `r`. 

**Parameters**: 

  * **r** Output vector of length `rows`. 
  * **mat** Input matrix of size `rows` x `cols`. 
  * **rows** Row count. 
  * **cols** Column count. 


### function colwiseSum

```cpp
void colwiseSum(
    cumeric_t * r,
    const cumeric_t * mat,
    std::size_t rows,
    std::size_t cols
)
```

Computes column-wise sums into vector `r`. 

**Parameters**: 

  * **r** Output vector of length `cols`. 
  * **mat** Input matrix of size `rows` x `cols`. 
  * **rows** Row count. 
  * **cols** Column count. 


### function transform

```cpp
void transform(
    cumeric_t * mat,
    const cumeric_t * old,
    void(*)(cumeric_t *data, const std::size_t size) func
)
```

Applies buffer transformation function out-of-place. 

**Parameters**: 

  * **mat** Output buffer. 
  * **old** Input buffer. 
  * **func** Transformation function pointer. 


### function transformInPlace

```cpp
void transformInPlace(
    cumeric_t * mat,
    void(*)(cumeric_t *data, const std::size_t size) func
)
```

Applies buffer transformation function in-place. 

**Parameters**: 

  * **mat** Buffer modified in place. 
  * **func** Transformation function pointer. 


### function transform

```cpp
void transform(
    cumeric_t * mat,
    const cumeric_t * old,
    cumeric_t(*)(cumeric_t x) func,
    std::size_t N
)
```

Applies scalar function to all elements out-of-place. 

**Parameters**: 

  * **mat** Output buffer. 
  * **old** Input buffer. 
  * **func** Scalar transformation function pointer. 
  * **N** Number of elements. 


### function transformInPlace

```cpp
void transformInPlace(
    cumeric_t * mat,
    cumeric_t(*)(cumeric_t x) func,
    std::size_t N
)
```

Applies scalar function to all elements in-place. 

**Parameters**: 

  * **mat** Buffer modified in place. 
  * **func** Scalar transformation function pointer. 
  * **N** Number of elements. 


### function norm

```cpp
void norm(
    cumeric_t & r,
    const cumeric_t * v,
    std::size_t N
)
```

Computes Euclidean L2 norm of vector: `r` = ||`v||_2`. 

**Parameters**: 

  * **r** Output scalar norm. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function normInplace

```cpp
void normInplace(
    cumeric_t * v,
    std::size_t N
)
```

Computes Euclidean L2 norm in-place. 

**Parameters**: 

  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function squaredNorm

```cpp
void squaredNorm(
    cumeric_t & r,
    const cumeric_t * v,
    std::size_t N
)
```

Computes squared Euclidean L2 norm: `r` = ||`v||_2^2`. 

**Parameters**: 

  * **r** Output scalar squared norm. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function normalize

```cpp
void normalize(
    cumeric_t * r,
    const cumeric_t * v,
    std::size_t N
)
```

Normalizes vector to unit L2 norm out-of-place: `r` = `v` / ||`v||_2`. 

**Parameters**: 

  * **r** Output normalized vector. 
  * **v** Input vector buffer. 
  * **N** Number of elements. 


### function normalizeInPlace

```cpp
void normalizeInPlace(
    cumeric_t * v,
    std::size_t N
)
```

Normalizes vector to unit L2 norm in-place: `v` /= ||`v||_2`. 

**Parameters**: 

  * **v** [Vector](Classes/classcum_1_1Vector.md) buffer normalized in place. 
  * **N** Number of elements. 






-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100