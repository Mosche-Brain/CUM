# CUM - C++ Numeric Library

**Vendor-agnostic C++ library providing linear algebra, eltwise operations, convenient data structures, and deep learning primitives.**

> *"We moved the problems from compile time to runtime."*

---

## Key Highlights

- **Linear Algebra (LARA)**: BLAS Level 1, 2, 3 routines with modern, ergonomic C++ interfaces backed by Intel MKL / oneAPI.
- **Neural Primitives**: Deep learning operators (convolution, pooling, normalization, matrix multiplication) powered by Intel oneDNN.
- **Flexible Memory Management**: Unified memory abstraction supporting host, device, and shared allocations.
- **Python Bindings (CumPy)**: High-performance Python wheel compiled against Intel oneAPI runtime dependencies.

---

## Modules Overview

| Module | Include | Description |
|---|---|---|
| **Core** | `<cum/Core.hpp>` | Memory managers, runtime device handles, Vector, Matrix, Tensor abstractions |
| **LARA** | `<cum/lara/BLAS.hpp>` | Modern BLAS wrapper routines and matrix/vector operations |
| **Neural Primitives** | `<cum/neural_primitives.hpp>` | High-performance deep learning kernels and tensor operations (oneDNN) |
| **Functions** | `<cum/functions.hpp>` | Elementwise mathematical operations, activations, and transformations |

---

## Quick Example (C++)

```cpp
#include <cum/Core.hpp>
#include <cum/lara/BLAS.hpp>
#include <iostream>

int main() {
    // Initialize matrices
    cum::Matrix<float> A({3, 3});
    cum::Matrix<float> B({3, 3});
    cum::Matrix<float> C({3, 3});

    // Perform matrix multiplication C = A * B
    cum::lara::gemm(A, B, C);

    std::cout << "Computation finished successfully." << std::endl;
    return 0;
}
```

---

## Next Steps

- Check out the [Getting Started](getting-started.md) guide to build and link CUM in your projects.
- Browse the [Module Guides](modules/index.md) for detailed architectural overviews.
- Inspect the full [C++ API Reference](api/index.md) generated automatically from the codebase.
- Learn about the [CumPy Python API](cumpy.md).
