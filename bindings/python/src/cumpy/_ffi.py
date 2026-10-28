"""Low-level ctypes bindings for libcum_C.so."""

from __future__ import annotations

import ctypes
from ctypes import POINTER, c_char, c_char_p, c_float, c_int, c_int64, c_size_t, c_void_p
import os
from pathlib import Path

cumeric_t = c_float
dim_t = c_int64


class cum_shape_t(ctypes.Structure):
    _fields_ = [
        ("dims", POINTER(dim_t)),
        ("rank", c_size_t),
    ]


class _cum_tensor_t(ctypes.Structure):
    pass


class _cum_matrix_t(ctypes.Structure):
    pass


class _cum_vector_t(ctypes.Structure):
    pass


class _cum_event_t(ctypes.Structure):
    pass


cum_tensor_p = POINTER(_cum_tensor_t)
cum_matrix_p = POINTER(_cum_matrix_t)
cum_vector_p = POINTER(_cum_vector_t)
cum_event_p = POINTER(_cum_event_t)

# Status codes
CUM_STATUS_SUCCESS = 0
CUM_STATUS_INVALID_ARGUMENT = 1
CUM_STATUS_OUT_OF_MEMORY = 2
CUM_STATUS_RUNTIME_ERROR = 3
CUM_STATUS_NOT_IMPLEMENTED = 4


def _find_library() -> ctypes.CDLL:
    pkg_dir = Path(__file__).resolve().parent
    candidates: list[Path] = []

    env_path = os.environ.get("CUM_C_LIBRARY")
    if env_path:
        candidates.append(Path(env_path))

    env_dir = os.environ.get("CUM_LIBRARY_DIR")
    if env_dir:
        candidates.append(Path(env_dir) / "libcum_C.so")

    candidates.append(pkg_dir / "libcum_C.so")

    if len(pkg_dir.parents) > 3:
        repo_root = pkg_dir.parents[3]
        for sub in ("build/release/bindings/C", "build/debug/bindings/C", "build/bindings/C"):
            candidates.append(repo_root / sub / "libcum_C.so")
    candidates.append(Path("/tmp/cuminstall/lib/libcum_C.so"))
    candidates.append(Path("/tmp/cumbuild/bindings/C/libcum_C.so"))

    for path in candidates:
        if path.is_file():
            # Preload sibling shared libraries if present in the same directory
            lib_dir = path.parent
            for dep in ("libcum_Core.so", "libcum_MKL.so"):
                dep_path = lib_dir / dep
                if dep_path.is_file():
                    ctypes.CDLL(str(dep_path), mode=ctypes.RTLD_GLOBAL)
            return ctypes.CDLL(str(path), mode=ctypes.RTLD_GLOBAL)

    return ctypes.CDLL("libcum_C.so", mode=ctypes.RTLD_GLOBAL)


lib = _find_library()


def _bind(name: str, argtypes: list, restype=c_int):
    fn = getattr(lib, name)
    fn.argtypes = argtypes
    fn.restype = restype
    return fn


# Core / Runtime
_bind("cum_init", [c_int])
_bind("cum_shutdown", [])
_bind("cum_last_error", [], c_char_p)
_bind("cum_synchronize", [])
_bind("cum_event_wait", [cum_event_p])
_bind("cum_event_destroy", [cum_event_p])
_bind("cum_memory_allocate", [dim_t, POINTER(POINTER(cumeric_t))])
_bind("cum_memory_free", [c_void_p])

# Tensor
_bind("cum_tensor_create", [POINTER(cum_tensor_p), cum_shape_t, c_int, c_int])
_bind("cum_tensor_create_zeros", [POINTER(cum_tensor_p), cum_shape_t])
_bind("cum_tensor_create_ones", [POINTER(cum_tensor_p), cum_shape_t])
_bind("cum_tensor_create_random", [POINTER(cum_tensor_p), cum_shape_t, cumeric_t, cumeric_t])
_bind("cum_tensor_create_from_data", [POINTER(cum_tensor_p), cum_shape_t, POINTER(cumeric_t)])
_bind("cum_tensor_destroy", [cum_tensor_p])
_bind("cum_tensor_copy", [cum_tensor_p, cum_tensor_p])
_bind("cum_tensor_clone", [POINTER(cum_tensor_p), cum_tensor_p])
_bind("cum_tensor_shape", [cum_tensor_p, POINTER(dim_t), c_size_t, POINTER(c_size_t)])
_bind("cum_tensor_size", [cum_tensor_p, POINTER(dim_t)])
_bind("cum_tensor_length", [cum_tensor_p, POINTER(dim_t)])
_bind("cum_tensor_datatype", [cum_tensor_p, POINTER(c_int)])
_bind("cum_tensor_layout", [cum_tensor_p, POINTER(c_int)])
_bind("cum_tensor_data", [cum_tensor_p, POINTER(c_void_p)])
_bind("cum_tensor_mutable_data", [cum_tensor_p, POINTER(c_void_p)])
_bind("cum_tensor_reshape", [cum_tensor_p, cum_tensor_p, cum_shape_t])
_bind("cum_tensor_transpose", [cum_tensor_p, cum_tensor_p])
_bind("cum_tensor_fill", [cum_tensor_p, cumeric_t])

for _op in ("add", "sub", "mul", "div", "mmul"):
    _bind(f"cum_tensor_{_op}", [cum_tensor_p, cum_tensor_p, cum_tensor_p])

for _op in ("add_in_place", "sub_in_place", "mul_in_place", "div_in_place"):
    _bind(f"cum_tensor_{_op}", [cum_tensor_p, cum_tensor_p])

for _op in ("add_scalar", "sub_scalar", "mul_scalar", "div_scalar"):
    _bind(f"cum_tensor_{_op}", [cum_tensor_p, cum_tensor_p, cumeric_t])

_bind("cum_tensor_scale", [cum_tensor_p, cumeric_t])

for _op in ("sqrt", "square", "abs", "log"):
    _bind(f"cum_tensor_{_op}", [cum_tensor_p, cum_tensor_p])

_bind("cum_tensor_clamp", [cum_tensor_p, cum_tensor_p, cumeric_t, cumeric_t])

for _op in ("sum", "mean", "norm"):
    _bind(f"cum_tensor_{_op}", [cum_tensor_p, POINTER(cumeric_t)])

# Matrix
_bind("cum_matrix_create", [POINTER(cum_matrix_p), dim_t, dim_t])
_bind("cum_matrix_create_filled", [POINTER(cum_matrix_p), dim_t, dim_t, cumeric_t])
_bind("cum_matrix_create_zeros", [POINTER(cum_matrix_p), dim_t, dim_t])
_bind("cum_matrix_create_ones", [POINTER(cum_matrix_p), dim_t, dim_t])
_bind("cum_matrix_create_random", [POINTER(cum_matrix_p), dim_t, dim_t, cumeric_t, cumeric_t])
_bind("cum_matrix_create_from_data", [POINTER(cum_matrix_p), dim_t, dim_t, POINTER(cumeric_t)])
_bind("cum_matrix_destroy", [cum_matrix_p])
_bind("cum_matrix_copy", [cum_matrix_p, cum_matrix_p])
_bind("cum_matrix_clone", [POINTER(cum_matrix_p), cum_matrix_p])
_bind("cum_matrix_rows", [cum_matrix_p, POINTER(dim_t)])
_bind("cum_matrix_cols", [cum_matrix_p, POINTER(dim_t)])
_bind("cum_matrix_size", [cum_matrix_p, POINTER(dim_t)])
_bind("cum_matrix_data", [cum_matrix_p, POINTER(POINTER(cumeric_t))])
_bind("cum_matrix_mutable_data", [cum_matrix_p, POINTER(POINTER(cumeric_t))])
_bind("cum_matrix_fill", [cum_matrix_p, cumeric_t])
_bind("cum_matrix_get", [cum_matrix_p, dim_t, dim_t, POINTER(cumeric_t)])
_bind("cum_matrix_set", [cum_matrix_p, dim_t, dim_t, cumeric_t])
_bind("cum_matrix_transpose", [cum_matrix_p, cum_matrix_p])
_bind("cum_matrix_reshape", [cum_matrix_p, cum_matrix_p, dim_t, dim_t])

for _op in ("add", "sub", "mul", "eltwise_mul", "div"):
    _bind(f"cum_matrix_{_op}", [cum_matrix_p, cum_matrix_p, cum_matrix_p])
    _bind(f"cum_matrix_{_op}_in_place", [cum_matrix_p, cum_matrix_p])

for _op in ("add_scalar", "mul_scalar", "div_scalar"):
    _bind(f"cum_matrix_{_op}", [cum_matrix_p, cum_matrix_p, cumeric_t])

# Vector
_bind("cum_vector_create", [POINTER(cum_vector_p), dim_t])
_bind("cum_vector_create_filled", [POINTER(cum_vector_p), dim_t, cumeric_t])
_bind("cum_vector_create_from_data", [POINTER(cum_vector_p), dim_t, POINTER(cumeric_t)])
_bind("cum_vector_destroy", [cum_vector_p])
_bind("cum_vector_clone", [POINTER(cum_vector_p), cum_vector_p])
_bind("cum_vector_length", [cum_vector_p, POINTER(dim_t)])
_bind("cum_vector_data", [cum_vector_p, POINTER(POINTER(cumeric_t))])
_bind("cum_vector_mutable_data", [cum_vector_p, POINTER(POINTER(cumeric_t))])
_bind("cum_vector_fill", [cum_vector_p, cumeric_t])

for _op in ("add", "sub", "mul", "div"):
    _bind(f"cum_vector_{_op}", [cum_vector_p, cum_vector_p, cum_vector_p])
    _bind(f"cum_vector_{_op}_in_place", [cum_vector_p, cum_vector_p])

_bind("cum_vector_scale", [cum_vector_p, cumeric_t])
_bind("cum_vector_dot", [cum_vector_p, cum_vector_p, POINTER(cumeric_t)])
_bind("cum_vector_sum", [cum_vector_p, POINTER(cumeric_t)])
_bind("cum_vector_norm", [cum_vector_p, POINTER(cumeric_t)])


def check(status: int) -> None:
    if status == CUM_STATUS_SUCCESS:
        return
    raw = lib.cum_last_error()
    msg = raw.decode("utf-8", errors="replace") if raw else "cum operation failed"
    if status == CUM_STATUS_INVALID_ARGUMENT:
        raise ValueError(msg)
    if status == CUM_STATUS_OUT_OF_MEMORY:
        raise MemoryError(msg)
    if status == CUM_STATUS_NOT_IMPLEMENTED:
        raise NotImplementedError(msg)
    raise RuntimeError(msg)


def make_shape(dims: tuple[int, ...] | list[int]) -> tuple[cum_shape_t, ctypes.Array]:
    rank = len(dims)
    arr_type = dim_t * rank
    buf = arr_type(*dims)
    return cum_shape_t(dims=buf, rank=rank), buf
