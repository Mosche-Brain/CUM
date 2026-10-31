# LARA - Linear Algebra Routines

Header: `<cum/lara/BLAS.hpp>`

LARA provides type-safe, ergonomic C++ wrappers around classic BLAS functionality backed by Intel oneMKL.

## Levels of BLAS Supported

### Level 1 (Vector-Vector)
- Scaled vector addition (`axpy`)
- Dot product (`dot`)
- Euclidean norm (`nrm2`)
- Vector scaling (`scal`)

### Level 2 (Matrix-Vector)
- General matrix-vector multiplication (`gemv`)
- Symmetric matrix-vector multiplication (`symv`)

### Level 3 (Matrix-Matrix)
- General matrix multiplication (`gemm`):
  \\[ C = \alpha A B + \beta C \\]
- Symmetric rank-k update (`syrk`)
- Triangular matrix solvers (`trsm`)
