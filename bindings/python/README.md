# CumPy - Python bindings for CUM

Lightweight python binding over CUM library.

## Quickstart

### Installation

```sh
pip install cumpy
```

### Basic usage

```python
import cumpy as cp

cp.init(cp.Device.CPU)

a = cp.Tensor.from_data((2, 2), [1, 2, 3, 4])
b = cp.Tensor.ones((2, 2)) * 2.0

print(a + b)   # addition
print(a * b)   # element-wise multiplication
print(a @ b)   # matrix product
print(a.sum(), a.mean(), a.norm())

cp.shutdown()
```

## Features

* 

## Examples (avaible on github)

- `examples/basic_tensors.py` – creating tensors, arithmetics, unary functions, reductions, transpositions and `reshape`.
- `examples/matrix_and_vector.py` – operations on `Matrix` i `Vector`, indexing `m[r, c]` / `v[i]`, dot product, etc.
- `examples/linear_regression.py` – linear regresion trained with gradient descent using `Tensor`.
