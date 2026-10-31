"""PrimitiveDescriptor and Primitive wrappers for cumpy.dnn."""

from __future__ import annotations

import ctypes
from ctypes import POINTER, byref, c_bool, c_char_p, c_float, c_int
from typing import Mapping, Sequence
import weakref

from .._ffi import (
    check,
    cum_event_p,
    cum_memory_arg_t,
    cum_memory_desc_p,
    cum_primitive_desc_p,
    cum_primitive_p,
    cum_tensor_arg_t,
    lib,
)
from ..event import Event
from ..tensor import Tensor
from .enums import Algo, Argument, PrimitiveKind, Purpose
from .memory import Memory, MemoryDescriptor

DescLike = MemoryDescriptor | Tensor | Memory
Operand = Tensor | Memory


def _as_desc(obj: DescLike) -> MemoryDescriptor:
    if isinstance(obj, MemoryDescriptor):
        return obj
    if isinstance(obj, (Tensor, Memory)):
        return obj.descriptor
    raise TypeError(f"expected MemoryDescriptor, Tensor, or Memory, got {type(obj).__name__}")


_NAMED_SLOT_MAP: dict[str, int] = {
    "src": int(Argument.SRC),
    "src0": int(Argument.SRC_0),
    "src_0": int(Argument.SRC_0),
    "src1": int(Argument.SRC_1),
    "src_1": int(Argument.SRC_1),
    "src2": int(Argument.SRC_2),
    "src_2": int(Argument.SRC_2),
    "src3": int(Argument.SRC_3),
    "src_3": int(Argument.SRC_3),
    "dst": int(Argument.DST),
    "dst0": int(Argument.DST_0),
    "dst_0": int(Argument.DST_0),
    "weights": int(Argument.WEIGHTS),
    "weight": int(Argument.WEIGHTS),
    "bias": int(Argument.BIAS),
    "workspace": int(Argument.WORKSPACE),
    "scratchpad": int(Argument.SCRATCHPAD),
    "diff_src": int(Argument.DIFF_SRC),
    "diff_src0": int(Argument.DIFF_SRC_0),
    "diff_src_0": int(Argument.DIFF_SRC_0),
    "diff_src1": int(Argument.DIFF_SRC_1),
    "diff_src_1": int(Argument.DIFF_SRC_1),
    "diff_dst": int(Argument.DIFF_DST),
    "diff_weights": int(Argument.DIFF_WEIGHTS),
    "diff_bias": int(Argument.DIFF_BIAS),
}


def _pack_deps(deps: Sequence[Event] | None):
    if not deps:
        return None, 0, None
    n = len(deps)
    arr = (cum_event_p * n)()
    for i, ev in enumerate(deps):
        if not isinstance(ev, Event):
            raise TypeError(f"deps[{i}] must be an Event, got {type(ev).__name__}")
        arr[i] = ev._ptr
    return arr, n, deps


class PrimitiveDescriptor:
    """Backend-resolved operation descriptor specifying layouts, datatypes, and algorithm parameters."""

    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(self, *, _ptr: cum_primitive_desc_p) -> None:
        self._ptr = _ptr
        self._finalizer = weakref.finalize(self, lib.cum_primitive_desc_destroy, _ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_primitive_desc_p) -> PrimitiveDescriptor:
        return cls(_ptr=ptr)

    def clone(self) -> PrimitiveDescriptor:
        ptr = cum_primitive_desc_p()
        check(lib.cum_primitive_desc_clone(byref(ptr), self._ptr))
        return PrimitiveDescriptor._from_ptr(ptr)

    # ------------------------------------------------------------------
    # Static / Class Factories
    # ------------------------------------------------------------------

    @classmethod
    def binary(
        cls,
        algo: Algo | int,
        dst: DescLike,
        src0: DescLike,
        src1: DescLike,
    ) -> PrimitiveDescriptor:
        d_md, s0_md, s1_md = _as_desc(dst), _as_desc(src0), _as_desc(src1)
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_binary(
                byref(ptr), int(algo), d_md._ptr, s0_md._ptr, s1_md._ptr
            )
        )
        return cls._from_ptr(ptr)

    @classmethod
    def eltwise_forward(
        cls,
        algo: Algo | int,
        dst: DescLike,
        src: DescLike,
        alpha: float = 0.0,
        beta: float = 0.0,
        purpose: Purpose | int = Purpose.FORWARD,
    ) -> PrimitiveDescriptor:
        d_md, s_md = _as_desc(dst), _as_desc(src)
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_eltwise_forward(
                byref(ptr),
                int(algo),
                d_md._ptr,
                s_md._ptr,
                c_float(alpha),
                c_float(beta),
                int(purpose),
            )
        )
        return cls._from_ptr(ptr)

    eltwise = eltwise_forward

    @classmethod
    def eltwise_backward(
        cls,
        algo: Algo | int,
        diff_src: DescLike,
        diff_dst: DescLike,
        data: DescLike,
        hint_fwd_pd: PrimitiveDescriptor | None = None,
        alpha: float = 0.0,
        beta: float = 0.0,
    ) -> PrimitiveDescriptor:
        ds_md, dd_md, data_md = _as_desc(diff_src), _as_desc(diff_dst), _as_desc(data)
        if hint_fwd_pd is not None and not isinstance(hint_fwd_pd, PrimitiveDescriptor):
            raise TypeError("hint_fwd_pd must be a PrimitiveDescriptor or None")
        hint_ptr = hint_fwd_pd._ptr if hint_fwd_pd is not None else cum_primitive_desc_p()
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_eltwise_backward(
                byref(ptr),
                int(algo),
                ds_md._ptr,
                dd_md._ptr,
                data_md._ptr,
                hint_ptr,
                c_float(alpha),
                c_float(beta),
            )
        )
        return cls._from_ptr(ptr)

    @classmethod
    def matmul(
        cls,
        dst: DescLike,
        src: DescLike,
        weights: DescLike,
        bias: DescLike | None = None,
    ) -> PrimitiveDescriptor:
        d_md, s_md, w_md = _as_desc(dst), _as_desc(src), _as_desc(weights)
        b_md = _as_desc(bias) if bias is not None else None
        b_ptr = b_md._ptr if b_md is not None else cum_memory_desc_p()
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_matmul(
                byref(ptr), d_md._ptr, s_md._ptr, w_md._ptr, b_ptr
            )
        )
        return cls._from_ptr(ptr)

    @classmethod
    def softmax_forward(
        cls,
        algo: Algo | int,
        dst: DescLike,
        src: DescLike,
        axis: int = -1,
        purpose: Purpose | int = Purpose.FORWARD,
    ) -> PrimitiveDescriptor:
        d_md, s_md = _as_desc(dst), _as_desc(src)
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_softmax_forward(
                byref(ptr), int(algo), d_md._ptr, s_md._ptr, int(axis), int(purpose)
            )
        )
        return cls._from_ptr(ptr)

    softmax = softmax_forward

    @classmethod
    def softmax_backward(
        cls,
        algo: Algo | int,
        diff_src: DescLike,
        diff_dst: DescLike,
        dst: DescLike,
        axis: int = -1,
        hint_fwd_pd: PrimitiveDescriptor | None = None,
    ) -> PrimitiveDescriptor:
        ds_md, dd_md, d_md = _as_desc(diff_src), _as_desc(diff_dst), _as_desc(dst)
        if hint_fwd_pd is not None and not isinstance(hint_fwd_pd, PrimitiveDescriptor):
            raise TypeError("hint_fwd_pd must be a PrimitiveDescriptor or None")
        hint_ptr = hint_fwd_pd._ptr if hint_fwd_pd is not None else cum_primitive_desc_p()
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_softmax_backward(
                byref(ptr), int(algo), ds_md._ptr, dd_md._ptr, d_md._ptr, int(axis), hint_ptr
            )
        )
        return cls._from_ptr(ptr)

    @classmethod
    def reduction(
        cls,
        algo: Algo | int,
        dst: DescLike,
        src: DescLike,
        p: float = 0.0,
        eps: float = 0.0,
    ) -> PrimitiveDescriptor:
        d_md, s_md = _as_desc(dst), _as_desc(src)
        ptr = cum_primitive_desc_p()
        check(
            lib.cum_primitive_desc_create_reduction(
                byref(ptr), int(algo), d_md._ptr, s_md._ptr, c_float(p), c_float(eps)
            )
        )
        return cls._from_ptr(ptr)

    @classmethod
    def reorder(cls, dst: DescLike, src: DescLike) -> PrimitiveDescriptor:
        d_md, s_md = _as_desc(dst), _as_desc(src)
        ptr = cum_primitive_desc_p()
        check(lib.cum_primitive_desc_create_reorder(byref(ptr), d_md._ptr, s_md._ptr))
        return cls._from_ptr(ptr)

    @classmethod
    def sum(
        cls,
        dst: DescLike,
        srcs: Sequence[DescLike],
        scales: Sequence[float] | None = None,
    ) -> PrimitiveDescriptor:
        if not srcs:
            raise ValueError("srcs must be non-empty")
        d_md = _as_desc(dst)
        mds = [_as_desc(s) for s in srcs]
        n = len(mds)
        src_arr = (cum_memory_desc_p * n)(*(m._ptr for m in mds))
        if scales is not None:
            sc_list = [float(x) for x in scales]
            if len(sc_list) != n:
                raise ValueError(f"scales length ({len(sc_list)}) must match srcs length ({n})")
            sc_arr = (c_float * n)(*sc_list)
            sc_ptr = ctypes.cast(sc_arr, POINTER(c_float))
        else:
            sc_arr = None
            sc_ptr = None
        ptr = cum_primitive_desc_p()
        check(lib.cum_primitive_desc_create_sum(byref(ptr), d_md._ptr, src_arr, n, sc_ptr))
        return cls._from_ptr(ptr)

    @classmethod
    def concat(
        cls,
        srcs: Sequence[DescLike],
        axis: int = 0,
        dst: DescLike | None = None,
    ) -> PrimitiveDescriptor:
        if not srcs:
            raise ValueError("srcs must be non-empty")
        mds = [_as_desc(s) for s in srcs]
        n = len(mds)
        src_arr = (cum_memory_desc_p * n)(*(m._ptr for m in mds))
        d_md = _as_desc(dst) if dst is not None else None
        d_ptr = d_md._ptr if d_md is not None else cum_memory_desc_p()
        ptr = cum_primitive_desc_p()
        check(lib.cum_primitive_desc_create_concat(byref(ptr), d_ptr, src_arr, n, int(axis)))
        return cls._from_ptr(ptr)

    # ------------------------------------------------------------------
    # Metadata & Descriptor Queries
    # ------------------------------------------------------------------

    @property
    def valid(self) -> bool:
        out = c_bool()
        check(lib.cum_primitive_desc_valid(self._ptr, byref(out)))
        return bool(out.value)

    def __bool__(self) -> bool:
        return self.valid

    @property
    def kind(self) -> PrimitiveKind:
        out = c_int()
        check(lib.cum_primitive_desc_kind(self._ptr, byref(out)))
        return PrimitiveKind(out.value)

    @property
    def purpose(self) -> Purpose:
        out = c_int()
        check(lib.cum_primitive_desc_purpose(self._ptr, byref(out)))
        return Purpose(out.value)

    @property
    def algo(self) -> Algo:
        out = c_int()
        check(lib.cum_primitive_desc_algo(self._ptr, byref(out)))
        return Algo(out.value)

    @property
    def impl_info(self) -> str:
        raw = c_char_p()
        check(lib.cum_primitive_desc_impl_info(self._ptr, byref(raw)))
        return raw.value.decode("utf-8", errors="replace") if raw.value else ""

    def src_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_src_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def dst_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_dst_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def weights_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_weights_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def bias_desc(self) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_bias_desc(self._ptr, byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def diff_src_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_diff_src_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def diff_dst_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_diff_dst_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def diff_weights_desc(self, index: int = 0) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_diff_weights_desc(self._ptr, int(index), byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def workspace_desc(self) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_workspace_desc(self._ptr, byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def scratchpad_desc(self) -> MemoryDescriptor:
        out = cum_memory_desc_p()
        check(lib.cum_primitive_desc_scratchpad_desc(self._ptr, byref(out)))
        return MemoryDescriptor._from_ptr(out)

    def __repr__(self) -> str:
        if not self.valid:
            return "PrimitiveDescriptor(empty)"
        return (
            f"PrimitiveDescriptor(kind={self.kind.name}, algo={self.algo.name}, "
            f"impl='{self.impl_info}')"
        )


class Primitive:
    """Compiled executable neural network or tensor primitive."""

    __slots__ = ("_ptr", "_finalizer", "__weakref__")

    def __init__(
        self,
        pd: PrimitiveDescriptor,
        *,
        _ptr: cum_primitive_p | None = None,
    ) -> None:
        if _ptr is not None:
            self._ptr = _ptr
            self._finalizer = weakref.finalize(self, lib.cum_primitive_destroy, _ptr)
            return
        if not isinstance(pd, PrimitiveDescriptor):
            raise TypeError("expected PrimitiveDescriptor")
        ptr = cum_primitive_p()
        check(lib.cum_primitive_create(byref(ptr), pd._ptr))
        self._ptr = ptr
        self._finalizer = weakref.finalize(self, lib.cum_primitive_destroy, ptr)

    @classmethod
    def _from_ptr(cls, ptr: cum_primitive_p) -> Primitive:
        return cls(None, _ptr=ptr)  # type: ignore[arg-type]

    def clone(self) -> Primitive:
        ptr = cum_primitive_p()
        check(lib.cum_primitive_clone(byref(ptr), self._ptr))
        return Primitive._from_ptr(ptr)

    @property
    def valid(self) -> bool:
        out = c_bool()
        check(lib.cum_primitive_valid(self._ptr, byref(out)))
        return bool(out.value)

    def __bool__(self) -> bool:
        return self.valid

    @property
    def kind(self) -> PrimitiveKind:
        out = c_int()
        check(lib.cum_primitive_kind(self._ptr, byref(out)))
        return PrimitiveKind(out.value)

    @property
    def descriptor(self) -> PrimitiveDescriptor:
        out = cum_primitive_desc_p()
        check(lib.cum_primitive_get_desc(self._ptr, byref(out)))
        return PrimitiveDescriptor._from_ptr(out)

    def execute(
        self,
        *operands: Operand | Sequence[Operand],
        args: Mapping[Argument | int, Operand] | Sequence[tuple[Argument | int, Operand]] | None = None,
        deps: Sequence[Event] | None = None,
        async_op: bool = False,
        **named_slots: Operand | Sequence[Operand],
    ) -> Event | None:
        """Executes the primitive synchronously (`async_op=False`) or asynchronously (`async_op=True`).

        Supports:
        - Positional operands: `prim.execute(dst, src0[, src1[, src2]])` or `prim.execute(dst, [s0, s1, ...])`
        - Explicit slot bindings: `prim.execute(args={Argument.DST: dst, Argument.SRC: src})`
        - Keyword slots: `prim.execute(dst=dst, src=src, weights=w, bias=b)` or `srcs=[s0, s1, ...]`
        """
        deps_arr, num_deps, _deps_keepalive = _pack_deps(deps)
        out_ev = cum_event_p()
        out_ev_ptr = byref(out_ev) if async_op else None

        # Fast positional path when no named/explicit bindings are given
        if args is None and not named_slots:
            # Variadic shorthand: execute(dst, [src0, src1, ...])
            if (
                len(operands) == 2
                and isinstance(operands[0], (Tensor, Memory))
                and isinstance(operands[1], (list, tuple))
            ):
                dst_op = operands[0]
                src_list = list(operands[1])
                pairs: list[tuple[int, Operand]] = [(int(Argument.DST), dst_op)]
                for i, s in enumerate(src_list):
                    pairs.append((Argument.multiple_src_at(i), s))
                return self._execute_pairs(pairs, deps_arr, num_deps, out_ev, out_ev_ptr, async_op)

            if all(isinstance(op, Tensor) for op in operands):
                t_ops: tuple[Tensor, ...] = operands  # type: ignore[assignment]
                if len(t_ops) == 2:
                    check(
                        lib.cum_primitive_execute_unary(
                            self._ptr, t_ops[0]._ptr, t_ops[1]._ptr, deps_arr, num_deps, out_ev_ptr
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None
                if len(t_ops) == 3:
                    check(
                        lib.cum_primitive_execute_binary(
                            self._ptr,
                            t_ops[0]._ptr,
                            t_ops[1]._ptr,
                            t_ops[2]._ptr,
                            deps_arr,
                            num_deps,
                            out_ev_ptr,
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None
                if len(t_ops) == 4:
                    check(
                        lib.cum_primitive_execute_ternary(
                            self._ptr,
                            t_ops[0]._ptr,
                            t_ops[1]._ptr,
                            t_ops[2]._ptr,
                            t_ops[3]._ptr,
                            deps_arr,
                            num_deps,
                            out_ev_ptr,
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None

            if all(isinstance(op, Memory) for op in operands):
                m_ops: tuple[Memory, ...] = operands  # type: ignore[assignment]
                if len(m_ops) == 2:
                    check(
                        lib.cum_primitive_execute_memory_unary(
                            self._ptr, m_ops[0]._ptr, m_ops[1]._ptr, deps_arr, num_deps, out_ev_ptr
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None
                if len(m_ops) == 3:
                    check(
                        lib.cum_primitive_execute_memory_binary(
                            self._ptr,
                            m_ops[0]._ptr,
                            m_ops[1]._ptr,
                            m_ops[2]._ptr,
                            deps_arr,
                            num_deps,
                            out_ev_ptr,
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None
                if len(m_ops) == 4:
                    check(
                        lib.cum_primitive_execute_memory_ternary(
                            self._ptr,
                            m_ops[0]._ptr,
                            m_ops[1]._ptr,
                            m_ops[2]._ptr,
                            m_ops[3]._ptr,
                            deps_arr,
                            num_deps,
                            out_ev_ptr,
                        )
                    )
                    return Event._from_ptr(out_ev) if async_op else None

            raise ValueError(
                "positional execute() expects 2, 3, or 4 Tensor/Memory operands "
                "(or `(dst, [src0, src1, ...])` for Sum/Concat)"
            )

        if operands:
            raise ValueError("cannot mix positional operands with `args=` or keyword slot arguments")

        pairs = []
        if args is not None:
            items = args.items() if isinstance(args, Mapping) else args
            for slot, op in items:
                if not isinstance(op, (Tensor, Memory)):
                    raise TypeError(f"argument for slot {slot} must be Tensor or Memory")
                pairs.append((int(slot), op))

        for name, val in named_slots.items():
            if name == "srcs":
                if not isinstance(val, (list, tuple)):
                    raise TypeError("`srcs` keyword slot must be a sequence of Tensor or Memory")
                for idx, item in enumerate(val):
                    if not isinstance(item, (Tensor, Memory)):
                        raise TypeError("elements of `srcs` must be Tensor or Memory")
                    pairs.append((Argument.multiple_src_at(idx), item))
                continue
            slot_id = _NAMED_SLOT_MAP.get(name)
            if slot_id is None:
                raise ValueError(f"unknown argument slot keyword {name!r}")
            if not isinstance(val, (Tensor, Memory)):
                raise TypeError(f"slot {name!r} expects Tensor or Memory")
            pairs.append((slot_id, val))

        return self._execute_pairs(pairs, deps_arr, num_deps, out_ev, out_ev_ptr, async_op)

    def _execute_pairs(
        self,
        pairs: list[tuple[int, Operand]],
        deps_arr,
        num_deps: int,
        out_ev: cum_event_p,
        out_ev_ptr,
        async_op: bool,
    ) -> Event | None:
        n = len(pairs)
        if all(isinstance(op, Tensor) for _, op in pairs):
            t_arr = (cum_tensor_arg_t * n)()
            for i, (slot, op) in enumerate(pairs):
                assert isinstance(op, Tensor)
                t_arr[i].arg = slot
                t_arr[i].tensor = op._ptr
            check(lib.cum_primitive_execute_tensors(self._ptr, t_arr, n, deps_arr, num_deps, out_ev_ptr))
            return Event._from_ptr(out_ev) if async_op else None

        # Mixed or Memory-only bindings: convert any Tensor operand to a temporary Memory handle
        mem_keepalive: list[Memory] = []
        m_arr = (cum_memory_arg_t * n)()
        for i, (slot, op) in enumerate(pairs):
            if isinstance(op, Tensor):
                mem_obj = op.memory()
                mem_keepalive.append(mem_obj)
            elif isinstance(op, Memory):
                mem_obj = op
            else:
                raise TypeError(f"expected Tensor or Memory, got {type(op).__name__}")
            m_arr[i].arg = slot
            m_arr[i].memory = mem_obj._ptr
        check(lib.cum_primitive_execute(self._ptr, m_arr, n, deps_arr, num_deps, out_ev_ptr))
        return Event._from_ptr(out_ev) if async_op else None

    __call__ = execute

    def __repr__(self) -> str:
        if not self.valid:
            return "Primitive(empty)"
        return f"Primitive(kind={self.kind.name})"
