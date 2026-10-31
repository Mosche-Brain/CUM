"""MemoryDescriptor and Memory wrappers for cumpy.dnn."""

from __future__ import annotations

import ctypes
from ctypes import byref, c_bool, c_int, c_size_t, c_void_p
from functools import reduce
import operator
from typing import Any, Iterable, Sequence
import weakref

from .._ffi import (
    check,
    cum_memory_desc_p,
    cum_memory_p,
    dim_t,
    lib,
    make_shape,
)
from ..runtime import DataType, Layout
from ..tensor import _CTYPE_BY_DTYPE, _read_typed_buffer


def _prod(dims: Sequence[int]) -> int:
    return reduce(operator.mul, dims, 1)


class MemoryDescriptor:
    """Multi-dimensional tensor shape, datatype, and physical layout descriptor."""

    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(
        self,
        shape: Sequence[int],
        dtype: DataType | int = DataType.FP32,
        layout: Layout | int = Layout.ANY,
        *,
        strides: Sequence[int] | None = None,
        _ptr: cum_memory_desc_p | None = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._finalizer = weakref.finalize(self, lib.cum_memory_desc_destroy, _ptr)
            return

        c_shape, _shape_buf = make_shape(tuple(int(d) for d in shape))
        ptr = cum_memory_desc_p()
        if strides is not None:
            c_strides, _stride_buf = make_shape(tuple(int(s) for s in strides))
            check(lib.cum_memory_desc_create_strided(byref(ptr), c_shape, int(dtype), c_strides))
        else:
            check(lib.cum_memory_desc_create(byref(ptr), c_shape, int(dtype), int(layout)))
        self._ptr = ptr
        self._finalizer = weakref.finalize(self, lib.cum_memory_desc_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_memory_desc_p) -> MemoryDescriptor:
        return cls((), _ptr=ptr)

    @classmethod
    def any(cls, shape: Sequence[int], dtype: DataType | int = DataType.FP32) -> MemoryDescriptor:
        """Creates a format-agnostic (`Layout.ANY`) descriptor for primitive layout resolution."""
        c_shape, _buf = make_shape(tuple(int(d) for d in shape))
        ptr = cum_memory_desc_p()
        check(lib.cum_memory_desc_create_any(byref(ptr), c_shape, int(dtype)))
        return cls._from_ptr(ptr)

    @classmethod
    def from_strides(
        cls,
        shape: Sequence[int],
        strides: Sequence[int],
        dtype: DataType | int = DataType.FP32,
    ) -> MemoryDescriptor:
        """Creates a descriptor with explicit per-dimension strides (in elements)."""
        return cls(shape, dtype=dtype, strides=strides)

    def clone(self) -> MemoryDescriptor:
        ptr = cum_memory_desc_p()
        check(lib.cum_memory_desc_clone(byref(ptr), self._ptr))
        return MemoryDescriptor._from_ptr(ptr)

    def reshape(self, shape: Sequence[int]) -> MemoryDescriptor:
        c_shape, _buf = make_shape(tuple(int(d) for d in shape))
        ptr = cum_memory_desc_p()
        check(lib.cum_memory_desc_reshape(byref(ptr), self._ptr, c_shape))
        return MemoryDescriptor._from_ptr(ptr)

    @property
    def valid(self) -> bool:
        out = c_bool()
        check(lib.cum_memory_desc_valid(self._ptr, byref(out)))
        return bool(out.value)

    def __bool__(self) -> bool:
        return self.valid

    @property
    def size(self) -> int:
        """Byte size required by this descriptor (0 when empty or `Layout.ANY`)."""
        out = dim_t()
        check(lib.cum_memory_desc_size(self._ptr, byref(out)))
        return int(out.value)

    @property
    def ndims(self) -> int:
        out = dim_t()
        check(lib.cum_memory_desc_ndims(self._ptr, byref(out)))
        return int(out.value)

    @property
    def rank(self) -> int:
        return self.ndims

    @property
    def shape(self) -> tuple[int, ...]:
        rank = c_size_t()
        check(lib.cum_memory_desc_shape(self._ptr, None, 0, byref(rank)))
        n = rank.value
        if n == 0:
            return ()
        dims = (dim_t * n)()
        check(lib.cum_memory_desc_shape(self._ptr, dims, n, byref(rank)))
        return tuple(int(dims[i]) for i in range(n))

    @property
    def strides(self) -> tuple[int, ...]:
        rank = c_size_t()
        check(lib.cum_memory_desc_strides(self._ptr, None, 0, byref(rank)))
        n = rank.value
        if n == 0:
            return ()
        st = (dim_t * n)()
        check(lib.cum_memory_desc_strides(self._ptr, st, n, byref(rank)))
        return tuple(int(st[i]) for i in range(n))

    @property
    def dtype(self) -> DataType:
        out = c_int()
        check(lib.cum_memory_desc_datatype(self._ptr, byref(out)))
        return DataType(out.value)

    @property
    def layout(self) -> Layout:
        out = c_int()
        check(lib.cum_memory_desc_layout(self._ptr, byref(out)))
        return Layout(out.value)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, MemoryDescriptor):
            return NotImplemented
        out = c_bool()
        check(lib.cum_memory_desc_equal(self._ptr, other._ptr, byref(out)))
        return bool(out.value)

    def __repr__(self) -> str:
        if not self.valid:
            return "MemoryDescriptor(empty)"
        return (
            f"MemoryDescriptor(shape={self.shape}, dtype={self.dtype.name}, "
            f"layout={self.layout.name}, strides={self.strides})"
        )


class Memory:
    """Device-accessible USM buffer managed according to a MemoryDescriptor."""

    __slots__ = ("_ptr", "_keepalive", "_finalizer", "__weakref__")

    def __init__(
        self,
        desc: MemoryDescriptor,
        *,
        _ptr: cum_memory_p | None = None,
        _keepalive: Any = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._keepalive = _keepalive
            self._finalizer = weakref.finalize(self, lib.cum_memory_destroy, _ptr)
            return

        if not isinstance(desc, MemoryDescriptor):
            raise TypeError("expected MemoryDescriptor")
        ptr = cum_memory_p()
        check(lib.cum_memory_create(byref(ptr), desc._ptr))
        self._ptr = ptr
        self._keepalive = None
        self._finalizer = weakref.finalize(self, lib.cum_memory_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_memory_p, keepalive: Any = None) -> Memory:
        return cls(None, _ptr=ptr, _keepalive=keepalive)  # type: ignore[arg-type]

    @classmethod
    def from_ptr(
        cls,
        desc: MemoryDescriptor,
        data_ptr: int,
        *,
        keepalive: Any = None,
    ) -> Memory:
        """Wraps an external device-accessible raw pointer without taking ownership."""
        if not isinstance(desc, MemoryDescriptor):
            raise TypeError("expected MemoryDescriptor")
        ptr = cum_memory_p()
        check(lib.cum_memory_create_from_ptr(byref(ptr), desc._ptr, c_void_p(int(data_ptr))))
        return cls._from_ptr(ptr, keepalive=keepalive)

    @classmethod
    def view(cls, view_desc: MemoryDescriptor, source: Memory) -> Memory:
        """Creates a memory view over `source` with descriptor `view_desc`."""
        if not isinstance(view_desc, MemoryDescriptor) or not isinstance(source, Memory):
            raise TypeError("expected (MemoryDescriptor, Memory)")
        ptr = cum_memory_p()
        check(lib.cum_memory_create_view(byref(ptr), view_desc._ptr, source._ptr))
        return cls._from_ptr(ptr, keepalive=source)

    @property
    def valid(self) -> bool:
        out = c_bool()
        check(lib.cum_memory_valid(self._ptr, byref(out)))
        return bool(out.value)

    def __bool__(self) -> bool:
        return self.valid

    @property
    def descriptor(self) -> MemoryDescriptor:
        md_ptr = cum_memory_desc_p()
        check(lib.cum_memory_desc(self._ptr, byref(md_ptr)))
        return MemoryDescriptor._from_ptr(md_ptr)

    @property
    def shape(self) -> tuple[int, ...]:
        return self.descriptor.shape

    @property
    def dtype(self) -> DataType:
        return self.descriptor.dtype

    @property
    def layout(self) -> Layout:
        return self.descriptor.layout

    @property
    def size(self) -> int:
        return self.descriptor.size

    @property
    def data_ptr(self) -> int:
        raw = c_void_p()
        check(lib.cum_memory_mutable_data(self._ptr, byref(raw)))
        return int(raw.value or 0)

    def set_data(self, data_ptr: int, *, keepalive: Any = None) -> Memory:
        check(lib.cum_memory_set_data(self._ptr, c_void_p(int(data_ptr))))
        self._keepalive = keepalive
        return self

    def copy_from_list(self, values: Iterable[float | int]) -> Memory:
        """Copies flat host values into this memory buffer (matching its element dtype)."""
        md = self.descriptor
        count = _prod(md.shape)
        flat = list(values)
        if len(flat) != count:
            raise ValueError(f"expected {count} elements for shape {md.shape}, got {len(flat)}")
        entry = _CTYPE_BY_DTYPE.get(md.dtype)
        if entry is None:
            raise NotImplementedError(f"copy_from_list() does not support dtype {md.dtype!r}")
        c_t, py_cast = entry
        raw = c_void_p()
        check(lib.cum_memory_mutable_data(self._ptr, byref(raw)))
        if not raw.value:
            raise RuntimeError("memory has null data pointer")
        arr = ctypes.cast(raw, ctypes.POINTER(c_t))
        for i, val in enumerate(flat):
            arr[i] = py_cast(val)
        return self

    def to_list(self) -> list[float | int]:
        md = self.descriptor
        raw = c_void_p()
        check(lib.cum_memory_data(self._ptr, byref(raw)))
        return _read_typed_buffer(raw, _prod(md.shape), md.dtype)

    def __repr__(self) -> str:
        if not self.valid:
            return "Memory(empty)"
        md = self.descriptor
        return f"Memory(shape={md.shape}, dtype={md.dtype.name}, layout={md.layout.name})"
