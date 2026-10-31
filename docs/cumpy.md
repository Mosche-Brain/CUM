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

# Initialize backend on CPU or GPU
cp.init(cp.Device.CPU)

# Create tensors from data
a = cp.Tensor.from_data((2, 2), [1.0, 2.0, 3.0, 4.0])
b = cp.Tensor.from_data((2, 2), [5.0, 6.0, 7.0, 8.0])

# Perform tensor operations
c = a + b      # Elementwise addition
d = a @ b      # Matrix multiplication
e = a * 2.0    # Scalar multiplication

print("Matrix multiplication result:", d.to_list())
print("Shape:", d.shape)

# Clean up runtime
cp.shutdown()
```
