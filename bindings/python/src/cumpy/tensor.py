"""Tensor wrapper over cum_tensor_t."""

from __future__ import annotations

import ctypes
from ctypes import byref, c_int, c_size_t, c_void_p
from functools import reduce
import operator
import struct
from typing import TYPE_CHECKING, Iterable, Sequence
import weakref

from ._ffi import (
    check,
    cum_memory_desc_p,
    cum_memory_p,
    cum_tensor_p,
    cumeric_t,
    dim_t,
    lib,
    make_shape,
)
from .runtime import DataType, Layout

if TYPE_CHECKING:
    from .dnn.memory import Memory, MemoryDescriptor


_CTYPE_BY_DTYPE = {
    DataType.FP64: (ctypes.c_double, float),
    DataType.FP32: (ctypes.c_float, float),
    DataType.S64: (ctypes.c_int64, int),
    DataType.S32: (ctypes.c_int32, int),
    DataType.S16: (ctypes.c_int16, int),
    DataType.S8: (ctypes.c_int8, int),
    DataType.U64: (ctypes.c_uint64, int),
    DataType.U32: (ctypes.c_uint32, int),
    DataType.U16: (ctypes.c_uint16, int),
    DataType.U8: (ctypes.c_uint8, int),
}


def _read_typed_buffer(raw: c_void_p, count: int, dtype: DataType) -> list[float | int]:
    if count <= 0 or not raw.value:
        return []
    entry = _CTYPE_BY_DTYPE.get(dtype)
    if entry is not None:
        c_t, py_cast = entry
        arr = ctypes.cast(raw, ctypes.POINTER(c_t))
        return [py_cast(arr[i]) for i in range(count)]
    if dtype == DataType.FP16:
        buf = ctypes.string_at(raw, count * 2)
        return [float(x) for x in struct.unpack(f"<{count}e", buf)]
    if dtype == DataType.BF16:
        arr = ctypes.cast(raw, ctypes.POINTER(ctypes.c_uint16))
        return [
            float(struct.unpack("<f", struct.pack("<I", int(arr[i]) << 16))[0])
            for i in range(count)
        ]
    raise NotImplementedError(f"to_list() does not support dtype {dtype!r}")


def _prod(dims: Sequence[int]) -> int:
    return reduce(operator.mul, dims, 1)


class Tensor:
    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(
        self,
        shape: Sequence[int],
        dtype: DataType | int = DataType.FP32,
        layout: Layout | int = Layout.ANY,
        *,
        _ptr: cum_tensor_p | None = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._finalizer = weakref.finalize(self, lib.cum_tensor_destroy, _ptr)
            return

        c_shape, _buf = make_shape(tuple(shape))
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create(byref(ptr), c_shape, int(dtype), int(layout)))
        self._ptr = ptr
        self._finalizer = weakref.finalize(self, lib.cum_tensor_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_tensor_p) -> Tensor:
        return cls((), _ptr=ptr)

    @classmethod
    def zeros(cls, shape: Sequence[int]) -> Tensor:
        c_shape, _buf = make_shape(tuple(shape))
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create_zeros(byref(ptr), c_shape))
        return cls._from_ptr(ptr)

    @classmethod
    def ones(cls, shape: Sequence[int]) -> Tensor:
        c_shape, _buf = make_shape(tuple(shape))
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create_ones(byref(ptr), c_shape))
        return cls._from_ptr(ptr)

    @classmethod
    def random(cls, shape: Sequence[int], low: float = -1.0, high: float = 1.0) -> Tensor:
        c_shape, _buf = make_shape(tuple(shape))
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create_random(byref(ptr), c_shape, cumeric_t(low), cumeric_t(high)))
        return cls._from_ptr(ptr)

    @classmethod
    def from_data(cls, shape: Sequence[int], data: Iterable[float]) -> Tensor:
        dims = tuple(int(d) for d in shape)
        flat = [float(x) for x in data]
        expected = _prod(dims)
        if len(flat) != expected:
            raise ValueError(f"data length {len(flat)} does not match shape {dims} ({expected})")
        arr = (cumeric_t * expected)(*flat)
        c_shape, _buf = make_shape(dims)
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create_from_data(byref(ptr), c_shape, arr))
        return cls._from_ptr(ptr)

    @classmethod
    def from_descriptor(cls, desc: MemoryDescriptor) -> Tensor:
        """Allocates a Tensor matching a concrete neural-primitive MemoryDescriptor."""
        from .dnn.memory import MemoryDescriptor as _MemoryDescriptor

        if not isinstance(desc, _MemoryDescriptor):
            raise TypeError("expected MemoryDescriptor")
        ptr = cum_tensor_p()
        check(lib.cum_tensor_create_from_desc(byref(ptr), desc._ptr))
        return cls._from_ptr(ptr)

    @property
    def descriptor(self) -> MemoryDescriptor:
        """Returns the MemoryDescriptor describing this tensor's shape, dtype, and layout."""
        from .dnn.memory import MemoryDescriptor as _MemoryDescriptor

        md_ptr = cum_memory_desc_p()
        check(lib.cum_tensor_memory_desc(self._ptr, byref(md_ptr)))
        return _MemoryDescriptor._from_ptr(md_ptr)

    def memory(self) -> Memory:
        """Returns a Memory handle viewing this tensor's underlying USM buffer."""
        from .dnn.memory import Memory as _Memory

        mem_ptr = cum_memory_p()
        check(lib.cum_tensor_memory(self._ptr, byref(mem_ptr)))
        return _Memory._from_ptr(mem_ptr, keepalive=self)

    def clone(self) -> Tensor:
        ptr = cum_tensor_p()
        check(lib.cum_tensor_clone(byref(ptr), self._ptr))
        return Tensor._from_ptr(ptr)

    def copy_from(self, other: Tensor) -> Tensor:
        if not isinstance(other, Tensor):
            raise TypeError("expected Tensor")
        check(lib.cum_tensor_copy(self._ptr, other._ptr))
        return self

    @property
    def shape(self) -> tuple[int, ...]:
        rank = c_size_t()
        check(lib.cum_tensor_shape(self._ptr, None, 0, byref(rank)))
        n = rank.value
        dims = (dim_t * n)()
        check(lib.cum_tensor_shape(self._ptr, dims, n, byref(rank)))
        return tuple(int(dims[i]) for i in range(n))

    @property
    def rank(self) -> int:
        r = c_size_t()
        check(lib.cum_tensor_shape(self._ptr, None, 0, byref(r)))
        return int(r.value)

    @property
    def size(self) -> int:
        out = dim_t()
        check(lib.cum_tensor_size(self._ptr, byref(out)))
        return int(out.value)

    @property
    def length(self) -> int:
        out = dim_t()
        check(lib.cum_tensor_length(self._ptr, byref(out)))
        return int(out.value)

    def __len__(self) -> int:
        return self.length

    @property
    def dtype(self) -> DataType:
        out = c_int()
        check(lib.cum_tensor_datatype(self._ptr, byref(out)))
        return DataType(out.value)

    @property
    def layout(self) -> Layout:
        out = c_int()
        check(lib.cum_tensor_layout(self._ptr, byref(out)))
        return Layout(out.value)

    @property
    def data_ptr(self) -> int:
        raw = c_void_p()
        check(lib.cum_tensor_mutable_data(self._ptr, byref(raw)))
        return int(raw.value or 0)

    def to_list(self) -> list[float | int]:
        raw = c_void_p()
        check(lib.cum_tensor_data(self._ptr, byref(raw)))
        return _read_typed_buffer(raw, self.length, self.dtype)

    def fill(self, value: float) -> Tensor:
        check(lib.cum_tensor_fill(self._ptr, cumeric_t(value)))
        return self

    def reshape(self, shape: Sequence[int]) -> Tensor:
        c_shape, _buf = make_shape(tuple(shape))
        out = Tensor.zeros(shape)
        check(lib.cum_tensor_reshape(out._ptr, self._ptr, c_shape))
        return out

    def transpose(self) -> Tensor:
        s = self.shape
        out_shape = tuple(reversed(s)) if len(s) == 2 else s
        out = Tensor.zeros(out_shape)
        check(lib.cum_tensor_transpose(out._ptr, self._ptr))
        return out

    @property
    def T(self) -> Tensor:
        return self.transpose()

    def _binary(self, other: Tensor, c_fn, out_shape: Sequence[int] | None = None) -> Tensor:
        if not isinstance(other, Tensor):
            return NotImplemented
        out = Tensor.zeros(out_shape if out_shape is not None else self.shape)
        check(c_fn(out._ptr, self._ptr, other._ptr))
        return out

    def _scalar(self, scalar: float, c_fn) -> Tensor:
        out = Tensor.zeros(self.shape)
        check(c_fn(out._ptr, self._ptr, cumeric_t(scalar)))
        return out

    def __add__(self, other: Tensor | float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_add_scalar)
        if isinstance(other, Tensor):
            return self._binary(other, lib.cum_tensor_add)
        return NotImplemented

    def __radd__(self, other: float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_add_scalar)
        return NotImplemented

    def __sub__(self, other: Tensor | float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_sub_scalar)
        if isinstance(other, Tensor):
            return self._binary(other, lib.cum_tensor_sub)
        return NotImplemented

    def __mul__(self, other: Tensor | float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_mul_scalar)
        if isinstance(other, Tensor):
            return self._binary(other, lib.cum_tensor_mul)
        return NotImplemented

    def __rmul__(self, other: float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_mul_scalar)
        return NotImplemented

    def __truediv__(self, other: Tensor | float | int) -> Tensor:
        if isinstance(other, (int, float)):
            return self._scalar(float(other), lib.cum_tensor_div_scalar)
        if isinstance(other, Tensor):
            return self._binary(other, lib.cum_tensor_div)
        return NotImplemented

    def __matmul__(self, other: Tensor) -> Tensor:
        if not isinstance(other, Tensor):
            return NotImplemented
        a_s = self.shape
        b_s = other.shape
        out_shape = (*a_s[:-1], b_s[-1]) if len(a_s) >= 2 and len(b_s) >= 2 else a_s
        return self._binary(other, lib.cum_tensor_mmul, out_shape)

    def matmul(self, other: Tensor) -> Tensor:
        res = self.__matmul__(other)
        if res is NotImplemented:
            raise TypeError("expected Tensor")
        return res

    def __iadd__(self, other: Tensor) -> Tensor:
        if not isinstance(other, Tensor):
            return NotImplemented
        check(lib.cum_tensor_add_in_place(self._ptr, other._ptr))
        return self

    def __isub__(self, other: Tensor) -> Tensor:
        if not isinstance(other, Tensor):
            return NotImplemented
        check(lib.cum_tensor_sub_in_place(self._ptr, other._ptr))
        return self

    def __imul__(self, other: Tensor | float | int) -> Tensor:
        if isinstance(other, (int, float)):
            check(lib.cum_tensor_scale(self._ptr, cumeric_t(float(other))))
            return self
        if isinstance(other, Tensor):
            check(lib.cum_tensor_mul_in_place(self._ptr, other._ptr))
            return self
        return NotImplemented

    def __itruediv__(self, other: Tensor) -> Tensor:
        if not isinstance(other, Tensor):
            return NotImplemented
        check(lib.cum_tensor_div_in_place(self._ptr, other._ptr))
        return self

    def scale(self, scalar: float) -> Tensor:
        check(lib.cum_tensor_scale(self._ptr, cumeric_t(scalar)))
        return self

    def _unary(self, c_fn) -> Tensor:
        out = Tensor.zeros(self.shape)
        check(c_fn(out._ptr, self._ptr))
        return out

    def sqrt(self) -> Tensor:
        return self._unary(lib.cum_tensor_sqrt)

    def square(self) -> Tensor:
        return self._unary(lib.cum_tensor_square)

    def abs(self) -> Tensor:
        return self._unary(lib.cum_tensor_abs)

    def log(self) -> Tensor:
        return self._unary(lib.cum_tensor_log)

    def clamp(self, low: float, high: float) -> Tensor:
        out = Tensor.zeros(self.shape)
        check(lib.cum_tensor_clamp(out._ptr, self._ptr, cumeric_t(low), cumeric_t(high)))
        return out

    def sum(self) -> float:
        out = cumeric_t()
        check(lib.cum_tensor_sum(self._ptr, byref(out)))
        return float(out.value)

    def mean(self) -> float:
        out = cumeric_t()
        check(lib.cum_tensor_mean(self._ptr, byref(out)))
        return float(out.value)

    def norm(self) -> float:
        out = cumeric_t()
        check(lib.cum_tensor_norm(self._ptr, byref(out)))
        return float(out.value)

    def __repr__(self) -> str:
        return f"Tensor(shape={self.shape}, dtype={self.dtype.name}, data={self.to_list()})"
