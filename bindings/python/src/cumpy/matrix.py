"""Matrix wrapper over cum_matrix_t."""

from __future__ import annotations

import ctypes
from ctypes import POINTER, byref
from typing import Iterable, Sequence
import weakref

from ._ffi import check, cum_matrix_p, cumeric_t, dim_t, lib


class Matrix:
    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(
        self,
        rows: int,
        cols: int,
        value: float | None = None,
        *,
        _ptr: cum_matrix_p | None = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._finalizer = weakref.finalize(self, lib.cum_matrix_destroy, _ptr)
            return

        ptr = cum_matrix_p()
        if value is None:
            check(lib.cum_matrix_create(byref(ptr), dim_t(rows), dim_t(cols)))
        else:
            check(lib.cum_matrix_create_filled(byref(ptr), dim_t(rows), dim_t(cols), cumeric_t(value)))
        self._ptr = ptr
        self._finalizer = weakref.finalize(self, lib.cum_matrix_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_matrix_p) -> Matrix:
        return cls(0, 0, _ptr=ptr)

    @classmethod
    def zeros(cls, rows: int, cols: int) -> Matrix:
        ptr = cum_matrix_p()
        check(lib.cum_matrix_create_zeros(byref(ptr), dim_t(rows), dim_t(cols)))
        return cls._from_ptr(ptr)

    @classmethod
    def ones(cls, rows: int, cols: int) -> Matrix:
        ptr = cum_matrix_p()
        check(lib.cum_matrix_create_ones(byref(ptr), dim_t(rows), dim_t(cols)))
        return cls._from_ptr(ptr)

    @classmethod
    def random(cls, rows: int, cols: int, low: float = -1.0, high: float = 1.0) -> Matrix:
        ptr = cum_matrix_p()
        check(lib.cum_matrix_create_random(byref(ptr), dim_t(rows), dim_t(cols), cumeric_t(low), cumeric_t(high)))
        return cls._from_ptr(ptr)

    @classmethod
    def from_data(cls, rows: int, cols: int, data: Iterable[float] | Sequence[Sequence[float]]) -> Matrix:
        items = list(data)
        if items and isinstance(items[0], (list, tuple)):
            flat = [float(x) for row in items for x in row]  # type: ignore[union-attr]
        else:
            flat = [float(x) for x in items]  # type: ignore[arg-type]
        expected = rows * cols
        if len(flat) != expected:
            raise ValueError(f"data length {len(flat)} does not match ({rows}, {cols}) ({expected})")
        arr = (cumeric_t * expected)(*flat)
        ptr = cum_matrix_p()
        check(lib.cum_matrix_create_from_data(byref(ptr), dim_t(rows), dim_t(cols), arr))
        return cls._from_ptr(ptr)

    def clone(self) -> Matrix:
        ptr = cum_matrix_p()
        check(lib.cum_matrix_clone(byref(ptr), self._ptr))
        return Matrix._from_ptr(ptr)

    def copy_from(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            raise TypeError("expected Matrix")
        check(lib.cum_matrix_copy(self._ptr, other._ptr))
        return self

    @property
    def rows(self) -> int:
        out = dim_t()
        check(lib.cum_matrix_rows(self._ptr, byref(out)))
        return int(out.value)

    @property
    def cols(self) -> int:
        out = dim_t()
        check(lib.cum_matrix_cols(self._ptr, byref(out)))
        return int(out.value)

    @property
    def shape(self) -> tuple[int, int]:
        return (self.rows, self.cols)

    @property
    def size(self) -> int:
        out = dim_t()
        check(lib.cum_matrix_size(self._ptr, byref(out)))
        return int(out.value)

    def __len__(self) -> int:
        return self.rows

    @property
    def data_ptr(self) -> int:
        raw = POINTER(cumeric_t)()
        check(lib.cum_matrix_mutable_data(self._ptr, byref(raw)))
        return ctypes.cast(raw, ctypes.c_void_p).value or 0

    def to_flat_list(self) -> list[float]:
        raw = POINTER(cumeric_t)()
        check(lib.cum_matrix_data(self._ptr, byref(raw)))
        return [float(raw[i]) for i in range(self.size)]

    def to_list(self) -> list[list[float]]:
        r, c = self.rows, self.cols
        flat = self.to_flat_list()
        return [flat[i * c : (i + 1) * c] for i in range(r)]

    def fill(self, value: float) -> Matrix:
        check(lib.cum_matrix_fill(self._ptr, cumeric_t(value)))
        return self

    def get(self, row: int, col: int) -> float:
        out = cumeric_t()
        check(lib.cum_matrix_get(self._ptr, dim_t(row), dim_t(col), byref(out)))
        return float(out.value)

    def set(self, row: int, col: int, value: float) -> None:
        check(lib.cum_matrix_set(self._ptr, dim_t(row), dim_t(col), cumeric_t(value)))

    def __getitem__(self, idx: tuple[int, int]) -> float:
        row, col = idx
        return self.get(row, col)

    def __setitem__(self, idx: tuple[int, int], value: float) -> None:
        row, col = idx
        self.set(row, col, value)

    def transpose(self) -> Matrix:
        out = Matrix.zeros(self.cols, self.rows)
        check(lib.cum_matrix_transpose(out._ptr, self._ptr))
        return out

    @property
    def T(self) -> Matrix:
        return self.transpose()

    def reshape(self, rows: int, cols: int) -> Matrix:
        out = Matrix.zeros(rows, cols)
        check(lib.cum_matrix_reshape(out._ptr, self._ptr, dim_t(rows), dim_t(cols)))
        return out

    def _binary(self, other: Matrix, c_fn, out_rows: int | None = None, out_cols: int | None = None) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        r = self.rows if out_rows is None else out_rows
        c = self.cols if out_cols is None else out_cols
        out = Matrix.zeros(r, c)
        check(c_fn(out._ptr, self._ptr, other._ptr))
        return out

    def _scalar(self, scalar: float, c_fn) -> Matrix:
        out = Matrix.zeros(self.rows, self.cols)
        check(c_fn(out._ptr, self._ptr, cumeric_t(scalar)))
        return out

    def __add__(self, other: Matrix | float | int) -> Matrix:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_matrix_add_scalar)
        if isinstance(other, Matrix):
            return self._binary(other, lib.cum_matrix_add)
        return NotImplemented

    def __radd__(self, other: float | int) -> Matrix:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_matrix_add_scalar)
        return NotImplemented

    def __sub__(self, other: Matrix | float | int) -> Matrix:
        if isinstance(other, (int, float)):
            return self._scalar(-float(other), lib.cum_matrix_add_scalar)
        if isinstance(other, Matrix):
            return self._binary(other, lib.cum_matrix_sub)
        return NotImplemented

    def __mul__(self, other: Matrix | float | int) -> Matrix:
        """Element-wise multiplication (or scalar multiplication). Use @ for matrix product."""
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_matrix_mul_scalar)
        if isinstance(other, Matrix):
            return self._binary(other, lib.cum_matrix_eltwise_mul)
        return NotImplemented

    def __rmul__(self, other: float | int) -> Matrix:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_matrix_mul_scalar)
        return NotImplemented

    def __matmul__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        return self._binary(other, lib.cum_matrix_mul, self.rows, other.cols)

    def matmul(self, other: Matrix) -> Matrix:
        res = self.__matmul__(other)
        if res is NotImplemented:
            raise TypeError("expected Matrix")
        return res

    def eltwise_mul(self, other: Matrix) -> Matrix:
        res = self._binary(other, lib.cum_matrix_eltwise_mul)
        if res is NotImplemented:
            raise TypeError("expected Matrix")
        return res

    def __truediv__(self, other: Matrix | float | int) -> Matrix:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_matrix_div_scalar)
        if isinstance(other, Matrix):
            return self._binary(other, lib.cum_matrix_div)
        return NotImplemented

    def __iadd__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        check(lib.cum_matrix_add_in_place(self._ptr, other._ptr))
        return self

    def __isub__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        check(lib.cum_matrix_sub_in_place(self._ptr, other._ptr))
        return self

    def __imul__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        check(lib.cum_matrix_eltwise_mul_in_place(self._ptr, other._ptr))
        return self

    def __imatmul__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        check(lib.cum_matrix_mul_in_place(self._ptr, other._ptr))
        return self

    def __itruediv__(self, other: Matrix) -> Matrix:
        if not isinstance(other, Matrix):
            return NotImplemented
        check(lib.cum_matrix_div_in_place(self._ptr, other._ptr))
        return self

    def __repr__(self) -> str:
        return f"Matrix(shape={self.shape}, data={self.to_list()})"
