"""Low-level ctypes bindings for libcum_C.so."""

from __future__ import annotations

import ctypes
from ctypes import (
    POINTER,
    c_bool,
    c_char,
    c_char_p,
    c_float,
    c_int,
    c_int64,
    c_size_t,
    c_void_p,
)
import os
from pathlib import Path
import site
import sys
import sysconfig

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


class _cum_memory_desc_t(ctypes.Structure):
    pass


class _cum_memory_t(ctypes.Structure):
    pass


class _cum_primitive_desc_t(ctypes.Structure):
    pass


class _cum_primitive_t(ctypes.Structure):
    pass


cum_tensor_p = POINTER(_cum_tensor_t)
cum_matrix_p = POINTER(_cum_matrix_t)
cum_vector_p = POINTER(_cum_vector_t)
cum_event_p = POINTER(_cum_event_t)
cum_memory_desc_p = POINTER(_cum_memory_desc_t)
cum_memory_p = POINTER(_cum_memory_t)
cum_primitive_desc_p = POINTER(_cum_primitive_desc_t)
cum_primitive_p = POINTER(_cum_primitive_t)


class cum_memory_arg_t(ctypes.Structure):
    _fields_ = [
        ("arg", c_int),
        ("memory", cum_memory_p),
    ]


class cum_tensor_arg_t(ctypes.Structure):
    _fields_ = [
        ("arg", c_int),
        ("tensor", cum_tensor_p),
    ]

# Status codes
CUM_STATUS_SUCCESS = 0
CUM_STATUS_INVALID_ARGUMENT = 1
CUM_STATUS_OUT_OF_MEMORY = 2
CUM_STATUS_RUNTIME_ERROR = 3
CUM_STATUS_NOT_IMPLEMENTED = 4


_INTEL_RUNTIME_LIBS = (
    "libintlc.so.5",
    "libimf.so",
    "libsvml.so",
    "libirng.so",
    "libhwloc.so.15",
    "libtcm.so.1",
    "libumf.so.1",
    "libtbb.so.12",
    "libOpenCL.so.1",
    "libur_loader.so.0",
    "libsycl.so.9",
    "libmkl_core.so.3",
    "libmkl_tbb_thread.so.3",
    "libmkl_intel_ilp64.so.3",
    "libmkl_sycl_vm.so.6",
    "libmkl_sycl_rng.so.6",
    "libmkl_sycl_blas.so.6",
)


def _runtime_lib_dirs(pkg_dir: Path) -> list[Path]:
    raw_dirs: list[Path] = [
        Path(sys.prefix) / "lib",
        Path(sysconfig.get_path("data")) / "lib",
        pkg_dir / "../../..",
        pkg_dir / "../../../../lib",
    ]
    user_base = getattr(site, "USER_BASE", None)
    if user_base:
        raw_dirs.append(Path(user_base) / "lib")

    seen: set[Path] = set()
    result: list[Path] = []
    for candidate in raw_dirs:
        try:
            resolved = candidate.resolve()
        except OSError:
            continue
        if resolved not in seen and resolved.is_dir():
            seen.add(resolved)
            result.append(resolved)
    return result


def _prepare_intel_runtime(pkg_dir: Path) -> None:
    if sys.platform == "win32":
        win_bin = Path(sys.prefix) / "Library" / "bin"
        if win_bin.is_dir() and hasattr(os, "add_dll_directory"):
            os.add_dll_directory(str(win_bin))
        return

    lib_dirs = _runtime_lib_dirs(pkg_dir)

    # Intel's PyPI `intel-opencl-rt` wheel ships an unpatched conda `.icd` file; register
    # `libintelocl.so` via OCL_ICD_FILENAMES so CPU SYCL works while keeping `/etc/OpenCL/vendors`.
    for lib_dir in lib_dirs:
        intel_ocl = lib_dir / "libintelocl.so"
        if intel_ocl.is_file():
            ocl_path = str(intel_ocl)
            existing = [p for p in os.environ.get("OCL_ICD_FILENAMES", "").split(os.pathsep) if p]
            if ocl_path not in existing and "libintelocl.so" not in existing:
                existing.append(ocl_path)
                os.environ["OCL_ICD_FILENAMES"] = os.pathsep.join(existing)
            break

    for soname in _INTEL_RUNTIME_LIBS:
        for lib_dir in lib_dirs:
            lib_file = lib_dir / soname
            if lib_file.is_file():
                try:
                    ctypes.CDLL(str(lib_file), mode=ctypes.RTLD_GLOBAL)
                except OSError:
                    pass
                break


def _find_library() -> ctypes.CDLL:
    pkg_dir = Path(__file__).resolve().parent
    _prepare_intel_runtime(pkg_dir)

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
_bind("cum_tensor_create_from_desc", [POINTER(cum_tensor_p), cum_memory_desc_p])
_bind("cum_tensor_destroy", [cum_tensor_p])
_bind("cum_tensor_copy", [cum_tensor_p, cum_tensor_p])
_bind("cum_tensor_clone", [POINTER(cum_tensor_p), cum_tensor_p])
_bind("cum_tensor_memory_desc", [cum_tensor_p, POINTER(cum_memory_desc_p)])
_bind("cum_tensor_memory", [cum_tensor_p, POINTER(cum_memory_p)])
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

# Neural Primitives: MemoryDescriptor
_bind("cum_memory_desc_create", [POINTER(cum_memory_desc_p), cum_shape_t, c_int, c_int])
_bind("cum_memory_desc_create_strided", [POINTER(cum_memory_desc_p), cum_shape_t, c_int, cum_shape_t])
_bind("cum_memory_desc_create_any", [POINTER(cum_memory_desc_p), cum_shape_t, c_int])
_bind("cum_memory_desc_clone", [POINTER(cum_memory_desc_p), cum_memory_desc_p])
_bind("cum_memory_desc_destroy", [cum_memory_desc_p])
_bind("cum_memory_desc_valid", [cum_memory_desc_p, POINTER(c_bool)])
_bind("cum_memory_desc_equal", [cum_memory_desc_p, cum_memory_desc_p, POINTER(c_bool)])
_bind("cum_memory_desc_size", [cum_memory_desc_p, POINTER(dim_t)])
_bind("cum_memory_desc_ndims", [cum_memory_desc_p, POINTER(dim_t)])
_bind("cum_memory_desc_shape", [cum_memory_desc_p, POINTER(dim_t), c_size_t, POINTER(c_size_t)])
_bind("cum_memory_desc_strides", [cum_memory_desc_p, POINTER(dim_t), c_size_t, POINTER(c_size_t)])
_bind("cum_memory_desc_datatype", [cum_memory_desc_p, POINTER(c_int)])
_bind("cum_memory_desc_layout", [cum_memory_desc_p, POINTER(c_int)])
_bind("cum_memory_desc_reshape", [POINTER(cum_memory_desc_p), cum_memory_desc_p, cum_shape_t])

# Neural Primitives: Memory
_bind("cum_memory_create", [POINTER(cum_memory_p), cum_memory_desc_p])
_bind("cum_memory_create_from_ptr", [POINTER(cum_memory_p), cum_memory_desc_p, c_void_p])
_bind("cum_memory_create_view", [POINTER(cum_memory_p), cum_memory_desc_p, cum_memory_p])
_bind("cum_memory_destroy", [cum_memory_p])
_bind("cum_memory_valid", [cum_memory_p, POINTER(c_bool)])
_bind("cum_memory_desc", [cum_memory_p, POINTER(cum_memory_desc_p)])
_bind("cum_memory_data", [cum_memory_p, POINTER(c_void_p)])
_bind("cum_memory_mutable_data", [cum_memory_p, POINTER(c_void_p)])
_bind("cum_memory_set_data", [cum_memory_p, c_void_p])

# Neural Primitives: PrimitiveDescriptor
_bind(
    "cum_primitive_desc_create_binary",
    [POINTER(cum_primitive_desc_p), c_int, cum_memory_desc_p, cum_memory_desc_p, cum_memory_desc_p],
)
_bind(
    "cum_primitive_desc_create_eltwise_forward",
    [POINTER(cum_primitive_desc_p), c_int, cum_memory_desc_p, cum_memory_desc_p, c_float, c_float, c_int],
)
_bind(
    "cum_primitive_desc_create_eltwise_backward",
    [
        POINTER(cum_primitive_desc_p),
        c_int,
        cum_memory_desc_p,
        cum_memory_desc_p,
        cum_memory_desc_p,
        cum_primitive_desc_p,
        c_float,
        c_float,
    ],
)
_bind(
    "cum_primitive_desc_create_matmul",
    [POINTER(cum_primitive_desc_p), cum_memory_desc_p, cum_memory_desc_p, cum_memory_desc_p, cum_memory_desc_p],
)
_bind(
    "cum_primitive_desc_create_softmax_forward",
    [POINTER(cum_primitive_desc_p), c_int, cum_memory_desc_p, cum_memory_desc_p, c_int, c_int],
)
_bind(
    "cum_primitive_desc_create_softmax_backward",
    [
        POINTER(cum_primitive_desc_p),
        c_int,
        cum_memory_desc_p,
        cum_memory_desc_p,
        cum_memory_desc_p,
        c_int,
        cum_primitive_desc_p,
    ],
)
_bind(
    "cum_primitive_desc_create_reduction",
    [POINTER(cum_primitive_desc_p), c_int, cum_memory_desc_p, cum_memory_desc_p, c_float, c_float],
)
_bind(
    "cum_primitive_desc_create_reorder",
    [POINTER(cum_primitive_desc_p), cum_memory_desc_p, cum_memory_desc_p],
)
_bind(
    "cum_primitive_desc_create_sum",
    [
        POINTER(cum_primitive_desc_p),
        cum_memory_desc_p,
        POINTER(cum_memory_desc_p),
        c_size_t,
        POINTER(c_float),
    ],
)
_bind(
    "cum_primitive_desc_create_concat",
    [
        POINTER(cum_primitive_desc_p),
        cum_memory_desc_p,
        POINTER(cum_memory_desc_p),
        c_size_t,
        c_int,
    ],
)
_bind("cum_primitive_desc_clone", [POINTER(cum_primitive_desc_p), cum_primitive_desc_p])
_bind("cum_primitive_desc_destroy", [cum_primitive_desc_p])
_bind("cum_primitive_desc_valid", [cum_primitive_desc_p, POINTER(c_bool)])
_bind("cum_primitive_desc_kind", [cum_primitive_desc_p, POINTER(c_int)])
_bind("cum_primitive_desc_purpose", [cum_primitive_desc_p, POINTER(c_int)])
_bind("cum_primitive_desc_algo", [cum_primitive_desc_p, POINTER(c_int)])
_bind("cum_primitive_desc_impl_info", [cum_primitive_desc_p, POINTER(c_char_p)])

for _q in ("src_desc", "dst_desc", "weights_desc", "diff_src_desc", "diff_dst_desc", "diff_weights_desc"):
    _bind(f"cum_primitive_desc_{_q}", [cum_primitive_desc_p, c_int, POINTER(cum_memory_desc_p)])

for _q in ("bias_desc", "workspace_desc", "scratchpad_desc"):
    _bind(f"cum_primitive_desc_{_q}", [cum_primitive_desc_p, POINTER(cum_memory_desc_p)])

# Neural Primitives: Primitive
_bind("cum_primitive_create", [POINTER(cum_primitive_p), cum_primitive_desc_p])
_bind("cum_primitive_clone", [POINTER(cum_primitive_p), cum_primitive_p])
_bind("cum_primitive_destroy", [cum_primitive_p])
_bind("cum_primitive_valid", [cum_primitive_p, POINTER(c_bool)])
_bind("cum_primitive_kind", [cum_primitive_p, POINTER(c_int)])
_bind("cum_primitive_get_desc", [cum_primitive_p, POINTER(cum_primitive_desc_p)])

_deps_t = POINTER(cum_event_p)
_out_ev_t = POINTER(cum_event_p)

_bind(
    "cum_primitive_execute",
    [cum_primitive_p, POINTER(cum_memory_arg_t), c_size_t, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_tensors",
    [cum_primitive_p, POINTER(cum_tensor_arg_t), c_size_t, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_unary",
    [cum_primitive_p, cum_tensor_p, cum_tensor_p, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_binary",
    [cum_primitive_p, cum_tensor_p, cum_tensor_p, cum_tensor_p, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_ternary",
    [cum_primitive_p, cum_tensor_p, cum_tensor_p, cum_tensor_p, cum_tensor_p, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_memory_unary",
    [cum_primitive_p, cum_memory_p, cum_memory_p, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_memory_binary",
    [cum_primitive_p, cum_memory_p, cum_memory_p, cum_memory_p, _deps_t, c_size_t, _out_ev_t],
)
_bind(
    "cum_primitive_execute_memory_ternary",
    [cum_primitive_p, cum_memory_p, cum_memory_p, cum_memory_p, cum_memory_p, _deps_t, c_size_t, _out_ev_t],
)


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
