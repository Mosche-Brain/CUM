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
#include <cum/cum.hpp>
#include <cum/Matrix.hpp>
#include <iostream>

int main() {
    // Initialize runtime on GPU (or cum::DEVICE::CPU)
    cum::cum(cum::DEVICE::GPU);

    // Create matrices
    cum::Matrix A(2048, 2048, 1.5);
    cum::Matrix B(2048, 2048, 2.0);

    // Matrix addition & multiplication (accelerated by oneMKL/SYCL)
    cum::Matrix Sum = A + B;
    cum::Matrix Prod = A * B;

    std::cout << "Element at (0, 0): " << Prod.at(0, 0) << std::endl;

    // Switch device to CPU on the fly
    cum::recum(cum::DEVICE::CPU);

    // Shutdown and clean up runtime
    cum::decum();
    return 0;
}
```

## Deep Learning Primitives Example

```cpp
#include <cum/cum.hpp>
#include <cum/neural_primitives/Primitive.hpp>
#include <cum/neural_primitives/Memory.hpp>

namespace dnn = cum::neural_primitives;

int main() {
    cum::cum(cum::DEVICE::GPU);

    // Create 2D memory descriptor for [6, 7] tensor
    dnn::Memory::Descriptor md({6, 7}, cum::datatype::F32, cum::layout::AB);

    // Define binary elementwise multiplication primitive (oneDNN)
    auto pd = dnn::Primitive::Descriptor::Binary(
        dnn::Algo::binary_mul, md, md, md
    );

    dnn::Primitive primitive(pd);
    primitive.compile();

    dnn::Memory A(md), B(md), C(md);
    primitive.execute(C, A, B);

    cum::decum();
    return 0;
}
```

---

## Next Steps

- Check out the [Getting Started](getting-started.md) guide to build and link CUM in your projects.
- Browse the [Module Guides](modules/index.md) for detailed architectural overviews.
- Inspect the full [C++ API Reference](api/index.md) generated automatically from the codebase.
- Learn about the [CumPy Python API](cumpy.md).
