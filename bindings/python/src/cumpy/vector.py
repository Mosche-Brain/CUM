"""Vector wrapper over cum_vector_t."""

from __future__ import annotations

import ctypes
from ctypes import POINTER, byref
from typing import Iterable
import weakref

from ._ffi import check, cum_vector_p, cumeric_t, dim_t, lib


class Vector:
    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(
        self,
        length: int,
        value: float | None = None,
        *,
        _ptr: cum_vector_p | None = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._finalizer = weakref.finalize(self, lib.cum_vector_destroy, _ptr)
            return

        ptr = cum_vector_p()
        if value is None:
            check(lib.cum_vector_create(byref(ptr), dim_t(length)))
        else:
            check(lib.cum_vector_create_filled(byref(ptr), dim_t(length), cumeric_t(value)))
        self._ptr = ptr
        self._finalizer = weakref.finalize(self, lib.cum_vector_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_vector_p) -> Vector:
        return cls(0, _ptr=ptr)

    @classmethod
    def zeros(cls, length: int) -> Vector:
        return cls(length, 0.0)

    @classmethod
    def ones(cls, length: int) -> Vector:
        return cls(length, 1.0)

    @classmethod
    def from_data(cls, data: Iterable[float]) -> Vector:
        flat = [float(x) for x in data]
        n = len(flat)
        arr = (cumeric_t * n)(*flat)
        ptr = cum_vector_p()
        check(lib.cum_vector_create_from_data(byref(ptr), dim_t(n), arr))
        return cls._from_ptr(ptr)

    def clone(self) -> Vector:
        ptr = cum_vector_p()
        check(lib.cum_vector_clone(byref(ptr), self._ptr))
        return Vector._from_ptr(ptr)

    @property
    def length(self) -> int:
        out = dim_t()
        check(lib.cum_vector_length(self._ptr, byref(out)))
        return int(out.value)

    @property
    def size(self) -> int:
        return self.length

    @property
    def shape(self) -> tuple[int]:
        return (self.length,)

    def __len__(self) -> int:
        return self.length

    @property
    def data_ptr(self) -> int:
        raw = POINTER(cumeric_t)()
        check(lib.cum_vector_mutable_data(self._ptr, byref(raw)))
        return ctypes.cast(raw, ctypes.c_void_p).value or 0

    def to_list(self) -> list[float]:
        raw = POINTER(cumeric_t)()
        check(lib.cum_vector_data(self._ptr, byref(raw)))
        return [float(raw[i]) for i in range(self.length)]

    def __getitem__(self, idx: int) -> float:
        n = self.length
        if idx < 0:
            idx += n
        if idx < 0 or idx >= n:
            raise IndexError("vector index out of range")
        raw = POINTER(cumeric_t)()
        check(lib.cum_vector_data(self._ptr, byref(raw)))
        return float(raw[idx])

    def __setitem__(self, idx: int, value: float) -> None:
        n = self.length
        if idx < 0:
            idx += n
        if idx < 0 or idx >= n:
            raise IndexError("vector index out of range")
        raw = POINTER(cumeric_t)()
        check(lib.cum_vector_mutable_data(self._ptr, byref(raw)))
        raw[idx] = cumeric_t(value)

    def fill(self, value: float) -> Vector:
        check(lib.cum_vector_fill(self._ptr, cumeric_t(value)))
        return self

    def _binary(self, other: Vector, c_fn) -> Vector:
        if not isinstance(other, Vector):
            return NotImplemented
        out = Vector.zeros(self.length)
        check(c_fn(out._ptr, self._ptr, other._ptr))
        return out

    def __add__(self, other: Vector) -> Vector:
        return self._binary(other, lib.cum_vector_add)

    def __sub__(self, other: Vector) -> Vector:
        return self._binary(other, lib.cum_vector_sub)

    def __mul__(self, other: Vector | float | int) -> Vector:
        if isinstance(other, (int, float)):
            out = self.clone()
            out.scale(float(other))
            return out
        return self._binary(other, lib.cum_vector_mul)

    def __rmul__(self, other: float | int) -> Vector:
        if isinstance(other, (int, float)):
            out = self.clone()
            out.scale(float(other))
            return out
        return NotImplemented

    def __truediv__(self, other: Vector) -> Vector:
        return self._binary(other, lib.cum_vector_div)

    def __matmul__(self, other: Vector) -> float:
        if not isinstance(other, Vector):
            return NotImplemented
        return self.dot(other)

    def __iadd__(self, other: Vector) -> Vector:
        if not isinstance(other, Vector):
            return NotImplemented
        check(lib.cum_vector_add_in_place(self._ptr, other._ptr))
        return self

    def __isub__(self, other: Vector) -> Vector:
        if not isinstance(other, Vector):
            return NotImplemented
        check(lib.cum_vector_sub_in_place(self._ptr, other._ptr))
        return self

    def __imul__(self, other: Vector | float | int) -> Vector:
        if isinstance(other, (int, float)):
            return self.scale(float(other))
        if isinstance(other, Vector):
            check(lib.cum_vector_mul_in_place(self._ptr, other._ptr))
            return self
        return NotImplemented

    def __itruediv__(self, other: Vector) -> Vector:
        if not isinstance(other, Vector):
            return NotImplemented
        check(lib.cum_vector_div_in_place(self._ptr, other._ptr))
        return self

    def scale(self, scalar: float) -> Vector:
        check(lib.cum_vector_scale(self._ptr, cumeric_t(scalar)))
        return self

    def dot(self, other: Vector) -> float:
        if not isinstance(other, Vector):
            raise TypeError("expected Vector")
        out = cumeric_t()
        check(lib.cum_vector_dot(self._ptr, other._ptr, byref(out)))
        return float(out.value)

    def sum(self) -> float:
        out = cumeric_t()
        check(lib.cum_vector_sum(self._ptr, byref(out)))
        return float(out.value)

    def norm(self) -> float:
        out = cumeric_t()
        check(lib.cum_vector_norm(self._ptr, byref(out)))
        return float(out.value)

    def __repr__(self) -> str:
        return f"Vector(length={self.length}, data={self.to_list()})"
