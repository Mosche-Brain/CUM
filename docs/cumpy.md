# CumPy (Python Bindings)

CumPy exposes CUM's high-performance tensor computing backends directly to Python.

## Installation

CumPy wheels are distributed via PyPI for `manylinux_2_28_x86_64`:

```bash
pip install cumpy
```

Runtime dependencies from the Intel oneAPI PyPI channel (`mkl`, `dpcpp-cpp-rt`, `tbb`, `umf`) are resolved and installed automatically.

## Usage Example

```python
import cumpy as cp

# Example matrix multiplication
a = cp.zeros((1024, 1024), dtype=cp.float32)
b = cp.ones((1024, 1024), dtype=cp.float32)

c = cp.matmul(a, b)
print("Result shape:", c.shape)
```
