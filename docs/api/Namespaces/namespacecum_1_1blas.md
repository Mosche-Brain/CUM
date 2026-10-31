---
title: cum::blas

---

# cum::blas



## Types

|                | Name           |
| -------------- | -------------- |
| enum class std::uint64_t | **[compute_mode](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-compute-mode)** { unset = 0x0, float_to_bf16 = 0x1, float_to_bf16x2 = 0x2, float_to_bf16x3 = 0x4, float_to_tf32 = 0x10, complex_3m = 0x10000, any = 0xFFFFFFFF, standard = 0x20000000'00000000, prefer_alternate = 0x40000000'00000000, force_alternate = 0x80000000'00000000}<br>Compute precision and acceleration mode flags for BLAS execution.  |
| enum class char | **[transpose](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-transpose)** { nontrans = 0, trans = 1, conjtrans = 3, N = 0, T = 1, C = 3}<br>[Matrix](/CUM/api/Classes/classcum_1_1Matrix/) transposition options for BLAS routines.  |
| enum class char | **[uplo](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-uplo)** { upper = 0, lower = 1, U = 0, L = 1}<br>Specifies whether matrix upper or lower triangular part is stored.  |
| enum class char | **[diag](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-diag)** { nonunit = 0, unit = 1, N = 0, U = 1}<br>Specifies whether matrix diagonal is unit.  |
| enum class char | **[side](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-side)** { left = 0, right = 1, L = 0, R = 1}<br>Specifies multiplication side (left or right).  |
| enum class char | **[offset](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-offset)** { row = 0, column = 1, fix = 2, R = 0, C = 1, F = 2}<br>Storage offset mode for matrices.  |
| enum class char | **[index_base](/CUM/api/Namespaces/namespacecum_1_1blas/#enum-index-base)** { zero = 0, one = 1}<br>0-based or 1-based indexing convention.  |

## Functions

|                | Name           |
| -------------- | -------------- |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy)<br>Computes vector-scalar multiply and accumulate: `y` = `alpha` * `x` + `y`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, cumeric_t * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy)<br>Computes scaled vector addition: `y` = `alpha` * `x` + `beta` * `y`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[axpy](/CUM/api/Namespaces/namespacecum_1_1blas/#function-axpy)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, const void * beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[dot](/CUM/api/Namespaces/namespacecum_1_1blas/#function-dot)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, const cumeric_t * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy, cumeric_t * result)<br>Computes dot product of two vectors: `result` = `x^T` * `y`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[dot](/CUM/api/Namespaces/namespacecum_1_1blas/#function-dot)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, const void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy, void * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[asum](/CUM/api/Namespaces/namespacecum_1_1blas/#function-asum)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t * result)<br>Computes sum of magnitudes (L1 norm): `result` = sum(|x_i|).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[asum](/CUM/api/Namespaces/namespacecum_1_1blas/#function-asum)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[nrm2](/CUM/api/Namespaces/namespacecum_1_1blas/#function-nrm2)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t * result)<br>Computes Euclidean L2 norm: `result` = ||x||_2.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[nrm2](/CUM/api/Namespaces/namespacecum_1_1blas/#function-nrm2)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[iamax](/CUM/api/Namespaces/namespacecum_1_1blas/#function-iamax)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) * result)<br>Finds the index of the first element having the maximum absolute value.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[iamax](/CUM/api/Namespaces/namespacecum_1_1blas/#function-iamax)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[iamin](/CUM/api/Namespaces/namespacecum_1_1blas/#function-iamin)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) * result)<br>Finds the index of the first element having the minimum absolute value.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[iamin](/CUM/api/Namespaces/namespacecum_1_1blas/#function-iamin)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[amax](/CUM/api/Namespaces/namespacecum_1_1blas/#function-amax)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t * result)<br>Computes maximum absolute value in vector.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[amax](/CUM/api/Namespaces/namespacecum_1_1blas/#function-amax)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[amin](/CUM/api/Namespaces/namespacecum_1_1blas/#function-amin)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t * result)<br>Computes minimum absolute value in vector.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[amin](/CUM/api/Namespaces/namespacecum_1_1blas/#function-amin)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, void * result) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[scal](/CUM/api/Namespaces/namespacecum_1_1blas/#function-scal)**([dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx)<br>Scales a vector by a scalar: `x` = `alpha` * `x`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[scal](/CUM/api/Namespaces/namespacecum_1_1blas/#function-scal)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[scal](/CUM/api/Namespaces/namespacecum_1_1blas/#function-scal)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemv)**(char transa, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const cumeric_t * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, cumeric_t * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy)<br>Computes general matrix-vector product (GEMV): `y` = `alpha` * op(A) * `x` + `beta` * `y`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char transa, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const void * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char transa, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, const void * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, const void * beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symv)**(char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const cumeric_t * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, cumeric_t * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy)<br>Computes symmetric matrix-vector product (SYMV): `y` = `alpha` * `A` * `x` + `beta` * `y`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const void * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, cumeric_t beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, const void * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx, const void * beta, void * y, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incy) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[trmv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-trmv)**(char vertical, char transa, char diag, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const cumeric_t * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, cumeric_t * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx)<br>Computes triangular matrix-vector product (TRMV): `x` = op(A) * `x`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[trmv](/CUM/api/Namespaces/namespacecum_1_1blas/#function-trmv)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char vertical, char transa, char diag, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * A, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, void * x, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) incx) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemm)**(char transpose_a, char transpose_b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, cumeric_t alpha, const cumeric_t * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const cumeric_t * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, cumeric_t beta, cumeric_t * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc)<br>General matrix-matrix multiplication (GEMM): `c` = `alpha` * op(a) * op(b) + `beta` * `c`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char transpose_a, char transpose_b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, cumeric_t alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, cumeric_t beta, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[gemm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-gemm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char transpose_a, char transpose_b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, const void * alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, const void * beta, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symm)**(char horizontal, char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, cumeric_t alpha, const cumeric_t * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const cumeric_t * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, cumeric_t beta, cumeric_t * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc)<br>Symmetric matrix-matrix multiplication (SYMM): `c` = `alpha` * `a` * `b` + `beta` * `c`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char horizontal, char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, cumeric_t alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, cumeric_t beta, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[symm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-symm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char horizontal, char vertical, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) k, const void * alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb, const void * beta, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldc) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[trmm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-trmm)**(char horizontal, char vertical, char transpose_a, char diagonal, cumeric_t * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const cumeric_t * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const cumeric_t * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb)<br>Triangular matrix-matrix multiplication (TRMM): `b` = `alpha` * op(a) * `b`.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[trmm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-trmm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char horizontal, char vertical, char transpose_a, char diagonal, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, cumeric_t alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb) |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[trmm](/CUM/api/Namespaces/namespacecum_1_1blas/#function-trmm)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, char horizontal, char vertical, char transpose_a, char diagonal, void * c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) m, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) n, const void * alpha, const void * a, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) lda, const void * b, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) ldb) |

## Types Documentation

### enum compute_mode

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| unset | 0x0|   |
| float_to_bf16 | 0x1|   |
| float_to_bf16x2 | 0x2|   |
| float_to_bf16x3 | 0x4|   |
| float_to_tf32 | 0x10|   |
| complex_3m | 0x10000|   |
| any | 0xFFFFFFFF|   |
| standard | 0x20000000'00000000|   |
| prefer_alternate | 0x40000000'00000000|   |
| force_alternate | 0x80000000'00000000|   |



Compute precision and acceleration mode flags for BLAS execution. 

### enum transpose

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| nontrans | 0| Do not transpose: op(A) = A.   |
| trans | 1| Transpose: op(A) = A^T.   |
| conjtrans | 3| Conjugate transpose: op(A) = A^H.   |
| N | 0| Alias for nontrans.   |
| T | 1| Alias for trans.   |
| C | 3| Alias for conjtrans.   |



[Matrix](/CUM/api/Classes/classcum_1_1Matrix/) transposition options for BLAS routines. 

### enum uplo

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| upper | 0| Upper triangle stored.   |
| lower | 1| Lower triangle stored.   |
| U | 0| Alias for upper.   |
| L | 1| Alias for lower.   |



Specifies whether matrix upper or lower triangular part is stored. 

### enum diag

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| nonunit | 0| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) diagonal elements are not assumed to be 1.   |
| unit | 1| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) is assumed to have unit diagonal (elements are 1).   |
| N | 0| Alias for nonunit.   |
| U | 1| Alias for unit.   |



Specifies whether matrix diagonal is unit. 

### enum side

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| left | 0| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) op on left: op(A) * B.   |
| right | 1| [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) op on right: B * op(A).   |
| L | 0| Alias for left.   |
| R | 1| Alias for right.   |



Specifies multiplication side (left or right). 

### enum offset

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| row | 0|   |
| column | 1|   |
| fix | 2|   |
| R | 0|   |
| C | 1|   |
| F | 2|   |



Storage offset mode for matrices. 

### enum index_base

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| zero | 0| 0-based indexing (C/C++ convention).   |
| one | 1| 1-based indexing (Fortran convention).   |



0-based or 1-based indexing convention. 


## Functions Documentation

### function axpy

```cpp
__event__ axpy(
    dim_t n,
    cumeric_t alpha,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t * y,
    dim_t incy
)
```

Computes vector-scalar multiply and accumulate: `y` = `alpha` * `x` + `y`. 

**Parameters**: 

  * **n** Number of elements. 
  * **alpha** Scalar multiplier. 
  * **x** Input vector buffer. 
  * **incx** Stride between elements of x. 
  * **y** Output/accumulator vector buffer. 
  * **incy** Stride between elements of y. 


**Return**: Asynchronous execution event. 

### function axpy

```cpp
__event__ axpy(
    datatype dtype,
    dim_t n,
    cumeric_t alpha,
    const void * x,
    dim_t incx,
    void * y,
    dim_t incy
)
```


### function axpy

```cpp
__event__ axpy(
    datatype dtype,
    dim_t n,
    const void * alpha,
    const void * x,
    dim_t incx,
    void * y,
    dim_t incy
)
```


### function axpy

```cpp
__event__ axpy(
    dim_t n,
    cumeric_t alpha,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t beta,
    cumeric_t * y,
    dim_t incy
)
```

Computes scaled vector addition: `y` = `alpha` * `x` + `beta` * `y`. 

**Parameters**: 

  * **n** Number of elements. 
  * **alpha** Scalar multiplier for x. 
  * **x** Input vector buffer. 
  * **incx** Stride between elements of x. 
  * **beta** Scalar multiplier for y. 
  * **y** Output/accumulator vector buffer. 
  * **incy** Stride between elements of y. 


**Return**: Asynchronous execution event. 

### function axpy

```cpp
__event__ axpy(
    datatype dtype,
    dim_t n,
    cumeric_t alpha,
    const void * x,
    dim_t incx,
    cumeric_t beta,
    void * y,
    dim_t incy
)
```


### function axpy

```cpp
__event__ axpy(
    datatype dtype,
    dim_t n,
    const void * alpha,
    const void * x,
    dim_t incx,
    const void * beta,
    void * y,
    dim_t incy
)
```


### function dot

```cpp
__event__ dot(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    const cumeric_t * y,
    dim_t incy,
    cumeric_t * result
)
```

Computes dot product of two vectors: `result` = `x^T` * `y`. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** First vector buffer. 
  * **incx** Stride of x. 
  * **y** Second vector buffer. 
  * **incy** Stride of y. 
  * **result** Pointer to output scalar result. 


**Return**: Asynchronous execution event. 

### function dot

```cpp
__event__ dot(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    const void * y,
    dim_t incy,
    void * result
)
```


### function asum

```cpp
__event__ asum(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t * result
)
```

Computes sum of magnitudes (L1 norm): `result` = sum(|x_i|). 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output scalar result. 


**Return**: Asynchronous execution event. 

### function asum

```cpp
__event__ asum(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    void * result
)
```


### function nrm2

```cpp
__event__ nrm2(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t * result
)
```

Computes Euclidean L2 norm: `result` = ||x||_2. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output scalar result. 


**Return**: Asynchronous execution event. 

### function nrm2

```cpp
__event__ nrm2(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    void * result
)
```


### function iamax

```cpp
__event__ iamax(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    dim_t * result
)
```

Finds the index of the first element having the maximum absolute value. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output index. 


**Return**: Asynchronous execution event. 

### function iamax

```cpp
__event__ iamax(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    dim_t * result
)
```


### function iamin

```cpp
__event__ iamin(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    dim_t * result
)
```

Finds the index of the first element having the minimum absolute value. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output index. 


**Return**: Asynchronous execution event. 

### function iamin

```cpp
__event__ iamin(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    dim_t * result
)
```


### function amax

```cpp
__event__ amax(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t * result
)
```

Computes maximum absolute value in vector. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output scalar result. 


**Return**: Asynchronous execution event. 

### function amax

```cpp
__event__ amax(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    void * result
)
```


### function amin

```cpp
__event__ amin(
    dim_t n,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t * result
)
```

Computes minimum absolute value in vector. 

**Parameters**: 

  * **n** Number of elements. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer. 
  * **incx** Stride of x. 
  * **result** Pointer to output scalar result. 


**Return**: Asynchronous execution event. 

### function amin

```cpp
__event__ amin(
    datatype dtype,
    dim_t n,
    const void * x,
    dim_t incx,
    void * result
)
```


### function scal

```cpp
__event__ scal(
    dim_t n,
    cumeric_t alpha,
    cumeric_t * x,
    dim_t incx
)
```

Scales a vector by a scalar: `x` = `alpha` * `x`. 

**Parameters**: 

  * **n** Number of elements. 
  * **alpha** Scalar multiplier. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer scaled in place. 
  * **incx** Stride of x. 


**Return**: Asynchronous execution event. 

### function scal

```cpp
__event__ scal(
    datatype dtype,
    dim_t n,
    cumeric_t alpha,
    void * x,
    dim_t incx
)
```


### function scal

```cpp
__event__ scal(
    datatype dtype,
    dim_t n,
    const void * alpha,
    void * x,
    dim_t incx
)
```


### function gemv

```cpp
__event__ gemv(
    char transa,
    dim_t m,
    dim_t n,
    cumeric_t alpha,
    const cumeric_t * A,
    dim_t lda,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t beta,
    cumeric_t * y,
    dim_t incy
)
```

Computes general matrix-vector product (GEMV): `y` = `alpha` * op(A) * `x` + `beta` * `y`. 

**Parameters**: 

  * **transa** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) transposition flag ('N' or 'T'). 
  * **m** Number of rows of matrix A. 
  * **n** Number of columns of matrix A. 
  * **alpha** Scalar multiplier for op(A)*x. 
  * **A** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) buffer of leading dimension `lda`. 
  * **lda** Leading dimension of matrix A. 
  * **x** Input vector buffer. 
  * **incx** Stride of vector x. 
  * **beta** Scalar multiplier for vector y. 
  * **y** Output/accumulator vector buffer. 
  * **incy** Stride of vector y. 


**Return**: Asynchronous execution event. 

### function gemv

```cpp
__event__ gemv(
    datatype dtype,
    char transa,
    dim_t m,
    dim_t n,
    cumeric_t alpha,
    const void * A,
    dim_t lda,
    const void * x,
    dim_t incx,
    cumeric_t beta,
    void * y,
    dim_t incy
)
```


### function gemv

```cpp
__event__ gemv(
    datatype dtype,
    char transa,
    dim_t m,
    dim_t n,
    const void * alpha,
    const void * A,
    dim_t lda,
    const void * x,
    dim_t incx,
    const void * beta,
    void * y,
    dim_t incy
)
```


### function symv

```cpp
__event__ symv(
    char vertical,
    dim_t n,
    cumeric_t alpha,
    const cumeric_t * A,
    dim_t lda,
    const cumeric_t * x,
    dim_t incx,
    cumeric_t beta,
    cumeric_t * y,
    dim_t incy
)
```

Computes symmetric matrix-vector product (SYMV): `y` = `alpha` * `A` * `x` + `beta` * `y`. 

**Parameters**: 

  * **vertical** Triangle specification ('U' or 'L'). 
  * **n** Order of matrix A. 
  * **alpha** Scalar multiplier. 
  * **A** Symmetric matrix buffer. 
  * **lda** Leading dimension of A. 
  * **x** Input vector buffer. 
  * **incx** Stride of vector x. 
  * **beta** Scalar multiplier for y. 
  * **y** Output/accumulator vector buffer. 
  * **incy** Stride of vector y. 


**Return**: Asynchronous execution event. 

### function symv

```cpp
__event__ symv(
    datatype dtype,
    char vertical,
    dim_t n,
    cumeric_t alpha,
    const void * A,
    dim_t lda,
    const void * x,
    dim_t incx,
    cumeric_t beta,
    void * y,
    dim_t incy
)
```


### function symv

```cpp
__event__ symv(
    datatype dtype,
    char vertical,
    dim_t n,
    const void * alpha,
    const void * A,
    dim_t lda,
    const void * x,
    dim_t incx,
    const void * beta,
    void * y,
    dim_t incy
)
```


### function trmv

```cpp
__event__ trmv(
    char vertical,
    char transa,
    char diag,
    dim_t n,
    const cumeric_t * A,
    dim_t lda,
    cumeric_t * x,
    dim_t incx
)
```

Computes triangular matrix-vector product (TRMV): `x` = op(A) * `x`. 

**Parameters**: 

  * **vertical** Triangle specification ('U' or 'L'). 
  * **transa** Transpose flag ('N' or 'T'). 
  * **diag** Unit diagonal flag ('U' or 'N'). 
  * **n** Order of matrix A. 
  * **A** Triangular matrix buffer. 
  * **lda** Leading dimension of A. 
  * **x** [Vector](/CUM/api/Classes/classcum_1_1Vector/) buffer modified in place. 
  * **incx** Stride of vector x. 


**Return**: Asynchronous execution event. 

### function trmv

```cpp
__event__ trmv(
    datatype dtype,
    char vertical,
    char transa,
    char diag,
    dim_t n,
    const void * A,
    dim_t lda,
    void * x,
    dim_t incx
)
```


### function gemm

```cpp
__event__ gemm(
    char transpose_a,
    char transpose_b,
    dim_t m,
    dim_t n,
    dim_t k,
    cumeric_t alpha,
    const cumeric_t * a,
    dim_t lda,
    const cumeric_t * b,
    dim_t ldb,
    cumeric_t beta,
    cumeric_t * c,
    dim_t ldc
)
```

General matrix-matrix multiplication (GEMM): `c` = `alpha` * op(a) * op(b) + `beta` * `c`. 

**Parameters**: 

  * **transpose_a** Transpose flag for matrix A ('N' or 'T'). 
  * **transpose_b** Transpose flag for matrix B ('N' or 'T'). 
  * **m** Rows of op(A) and C. 
  * **n** Columns of op(B) and C. 
  * **k** Columns of op(A) and rows of op(B). 
  * **alpha** Scalar multiplier for A*B. 
  * **a** Left matrix buffer. 
  * **lda** Leading dimension of A. 
  * **b** Right matrix buffer. 
  * **ldb** Leading dimension of B. 
  * **beta** Scalar multiplier for C. 
  * **c** Output matrix buffer. 
  * **ldc** Leading dimension of C. 


**Return**: Asynchronous execution event. 

### function gemm

```cpp
__event__ gemm(
    datatype dtype,
    char transpose_a,
    char transpose_b,
    dim_t m,
    dim_t n,
    dim_t k,
    cumeric_t alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb,
    cumeric_t beta,
    void * c,
    dim_t ldc
)
```


### function gemm

```cpp
__event__ gemm(
    datatype dtype,
    char transpose_a,
    char transpose_b,
    dim_t m,
    dim_t n,
    dim_t k,
    const void * alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb,
    const void * beta,
    void * c,
    dim_t ldc
)
```


### function symm

```cpp
__event__ symm(
    char horizontal,
    char vertical,
    dim_t m,
    dim_t n,
    dim_t k,
    cumeric_t alpha,
    const cumeric_t * a,
    dim_t lda,
    const cumeric_t * b,
    dim_t ldb,
    cumeric_t beta,
    cumeric_t * c,
    dim_t ldc
)
```

Symmetric matrix-matrix multiplication (SYMM): `c` = `alpha` * `a` * `b` + `beta` * `c`. 

**Parameters**: 

  * **horizontal** Side multiplier position ('L' or 'R'). 
  * **vertical** Triangle specification ('U' or 'L'). 
  * **m** Rows of C. 
  * **n** Columns of C. 
  * **k** Inner dimension. 
  * **alpha** Scalar multiplier. 
  * **a** Symmetric matrix buffer. 
  * **lda** Leading dimension of A. 
  * **b** General matrix buffer. 
  * **ldb** Leading dimension of B. 
  * **beta** Scalar multiplier for C. 
  * **c** Output matrix buffer. 
  * **ldc** Leading dimension of C. 


**Return**: Asynchronous execution event. 

### function symm

```cpp
__event__ symm(
    datatype dtype,
    char horizontal,
    char vertical,
    dim_t m,
    dim_t n,
    dim_t k,
    cumeric_t alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb,
    cumeric_t beta,
    void * c,
    dim_t ldc
)
```


### function symm

```cpp
__event__ symm(
    datatype dtype,
    char horizontal,
    char vertical,
    dim_t m,
    dim_t n,
    dim_t k,
    const void * alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb,
    const void * beta,
    void * c,
    dim_t ldc
)
```


### function trmm

```cpp
__event__ trmm(
    char horizontal,
    char vertical,
    char transpose_a,
    char diagonal,
    cumeric_t * c,
    dim_t m,
    dim_t n,
    cumeric_t alpha,
    const cumeric_t * a,
    dim_t lda,
    const cumeric_t * b,
    dim_t ldb
)
```

Triangular matrix-matrix multiplication (TRMM): `b` = `alpha` * op(a) * `b`. 

**Parameters**: 

  * **horizontal** Side specification ('L' or 'R'). 
  * **vertical** Triangle specification ('U' or 'L'). 
  * **transpose_a** Transpose flag for A ('N' or 'T'). 
  * **diagonal** Diagonal unit flag ('U' or 'N'). 
  * **c** [Matrix](/CUM/api/Classes/classcum_1_1Matrix/) buffer. 
  * **m** Rows of C. 
  * **n** Columns of C. 
  * **alpha** Scalar multiplier. 
  * **a** Triangular matrix buffer. 
  * **lda** Leading dimension of A. 
  * **b** Right matrix buffer. 
  * **ldb** Leading dimension of B. 


**Return**: Asynchronous execution event. 

### function trmm

```cpp
__event__ trmm(
    datatype dtype,
    char horizontal,
    char vertical,
    char transpose_a,
    char diagonal,
    void * c,
    dim_t m,
    dim_t n,
    cumeric_t alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb
)
```


### function trmm

```cpp
__event__ trmm(
    datatype dtype,
    char horizontal,
    char vertical,
    char transpose_a,
    char diagonal,
    void * c,
    dim_t m,
    dim_t n,
    const void * alpha,
    const void * a,
    dim_t lda,
    const void * b,
    dim_t ldb
)
```






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100