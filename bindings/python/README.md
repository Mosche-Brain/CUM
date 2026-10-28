# CumPy - Python bindings for CUM

Lekki binding Pythona (`ctypes`) nad współdzieloną biblioteką `libcum_C.so`.

## Szybki start

```python
import cumpy as cp

cp.init(cp.Device.CPU)

a = cp.Tensor.from_data((2, 2), [1, 2, 3, 4])
b = cp.Tensor.ones((2, 2)) * 2.0

print(a + b)   # dodawanie
print(a * b)   # mnożenie element-po-elemencie
print(a @ b)   # iloczyn macierzowy
print(a.sum(), a.mean(), a.norm())

cp.shutdown()
```

## Przykłady

W katalogu `examples/` znajdują się gotowe skrypty:
- `examples/basic_tensors.py` – tworzenie tensorów, arytmetyka, funkcje unary, redukcje, transpozycja i `reshape`.
- `examples/matrix_and_vector.py` – operacje na `Matrix` i `Vector`, indeksowanie `m[r, c]` / `v[i]` oraz iloczyn skalarny.
- `examples/linear_regression.py` – uczenie regresji liniowej metodą spadku gradientowego na `Tensor`.
