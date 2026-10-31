"""High-level functional interface over cumpy.dnn neural primitives."""

from __future__ import annotations

from typing import Sequence

from ..event import Event
from ..runtime import DataType, Layout
from ..tensor import Tensor
from .enums import Algo, Argument, Purpose
from .memory import Memory, MemoryDescriptor
from .primitive import Primitive, PrimitiveDescriptor

TensorOrAsync = Tensor | tuple[Tensor, Event]


def _default_layout(rank: int) -> Layout:
    table = {
        1: Layout.A,
        2: Layout.AB,
        3: Layout.ABC,
        4: Layout.ABCD,
        5: Layout.ABCDE,
        6: Layout.ABCDEF,
        7: Layout.ABCDEFG,
    }
    return table.get(rank, Layout.ANY)


def _contiguous_strides(shape: Sequence[int]) -> tuple[int, ...]:
    if not shape:
        return ()
    strides = [1] * len(shape)
    running = 1
    for i in range(len(shape) - 1, -1, -1):
        strides[i] = running
        running *= int(shape[i])
    return tuple(strides)


def _finish(out: Tensor, ev: Event | None, async_op: bool) -> TensorOrAsync:
    if async_op:
        assert ev is not None
        return out, ev
    return out


def _ensure_unary_out(x: Tensor, out: Tensor | None) -> Tensor:
    if out is not None:
        if not isinstance(out, Tensor):
            raise TypeError("`out` must be a Tensor")
        return out
    return Tensor.from_descriptor(x.descriptor)


# ---------------------------------------------------------------------------
# Elementwise Forward Activations & Math
# ---------------------------------------------------------------------------


def eltwise(
    x: Tensor,
    algo: Algo | int,
    *,
    alpha: float = 0.0,
    beta: float = 0.0,
    purpose: Purpose | int = Purpose.FORWARD,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Executes an elementwise forward primitive (`dst = op(x)`)."""
    if not isinstance(x, Tensor):
        raise TypeError("expected Tensor")
    dst = _ensure_unary_out(x, out)
    pd = PrimitiveDescriptor.eltwise_forward(
        algo, dst.descriptor, x.descriptor, alpha=alpha, beta=beta, purpose=purpose
    )
    prim = Primitive(pd)
    ev = prim.execute(dst, x, deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def relu(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_RELU, alpha=0.0, out=out, deps=deps, async_op=async_op)


def leaky_relu(
    x: Tensor,
    negative_slope: float = 0.01,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(
        x, Algo.ELTWISE_LEAKY_RELU, alpha=float(negative_slope), out=out, deps=deps, async_op=async_op
    )


def sigmoid(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_SIGMOID, out=out, deps=deps, async_op=async_op)


def tanh(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_TANH, out=out, deps=deps, async_op=async_op)


def gelu(
    x: Tensor,
    *,
    approximate: str = "tanh",
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if approximate == "tanh":
        alg = Algo.ELTWISE_GELU_TANH
    elif approximate in ("none", "erf"):
        alg = Algo.ELTWISE_GELU_ERF
    else:
        raise ValueError("`approximate` must be 'tanh', 'erf', or 'none'")
    return eltwise(x, alg, out=out, deps=deps, async_op=async_op)


def elu(
    x: Tensor,
    alpha: float = 1.0,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_ELU, alpha=float(alpha), out=out, deps=deps, async_op=async_op)


def swish(
    x: Tensor,
    alpha: float = 1.0,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_SWISH, alpha=float(alpha), out=out, deps=deps, async_op=async_op)


def silu(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return swish(x, alpha=1.0, out=out, deps=deps, async_op=async_op)


def softplus(
    x: Tensor,
    beta: float = 1.0,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(
        x, Algo.ELTWISE_SOFT_RELU, alpha=float(beta), out=out, deps=deps, async_op=async_op
    )


def mish(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_MISH, out=out, deps=deps, async_op=async_op)


def hardswish(
    x: Tensor,
    alpha: float = 1.0 / 6.0,
    beta: float = 0.5,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(
        x,
        Algo.ELTWISE_HARDSWISH,
        alpha=float(alpha),
        beta=float(beta),
        out=out,
        deps=deps,
        async_op=async_op,
    )


def hardsigmoid(
    x: Tensor,
    alpha: float = 1.0 / 6.0,
    beta: float = 0.5,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(
        x,
        Algo.ELTWISE_HARDSIGMOID,
        alpha=float(alpha),
        beta=float(beta),
        out=out,
        deps=deps,
        async_op=async_op,
    )


def clamp(
    x: Tensor,
    min_val: float,
    max_val: float,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(
        x,
        Algo.ELTWISE_CLIP,
        alpha=float(min_val),
        beta=float(max_val),
        out=out,
        deps=deps,
        async_op=async_op,
    )


clip = clamp


def exp(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_EXP, out=out, deps=deps, async_op=async_op)


def log(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_LOG, out=out, deps=deps, async_op=async_op)


def sqrt(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_SQRT, out=out, deps=deps, async_op=async_op)


def square(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_SQUARE, out=out, deps=deps, async_op=async_op)


def abs(
    x: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise(x, Algo.ELTWISE_ABS, out=out, deps=deps, async_op=async_op)


# ---------------------------------------------------------------------------
# Elementwise Backward Helpers
# ---------------------------------------------------------------------------


def eltwise_backward(
    grad_output: Tensor,
    data: Tensor,
    algo: Algo | int,
    *,
    alpha: float = 0.0,
    beta: float = 0.0,
    hint_fwd_pd: PrimitiveDescriptor | None = None,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Computes elementwise activation backward pass (`diff_src = f'(data) * grad_output`)."""
    if not isinstance(grad_output, Tensor) or not isinstance(data, Tensor):
        raise TypeError("expected Tensor operands")
    diff_src = _ensure_unary_out(data, out)
    pd = PrimitiveDescriptor.eltwise_backward(
        algo,
        diff_src.descriptor,
        grad_output.descriptor,
        data.descriptor,
        hint_fwd_pd=hint_fwd_pd,
        alpha=alpha,
        beta=beta,
    )
    prim = Primitive(pd)
    ev = prim.execute(diff_src, grad_output, data, deps=deps, async_op=async_op)
    return _finish(diff_src, ev, async_op)


def relu_backward(
    grad_output: Tensor,
    src: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise_backward(
        grad_output, src, Algo.ELTWISE_RELU, alpha=0.0, out=out, deps=deps, async_op=async_op
    )


def leaky_relu_backward(
    grad_output: Tensor,
    src: Tensor,
    negative_slope: float = 0.01,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return eltwise_backward(
        grad_output,
        src,
        Algo.ELTWISE_LEAKY_RELU,
        alpha=float(negative_slope),
        out=out,
        deps=deps,
        async_op=async_op,
    )


def sigmoid_backward(
    grad_output: Tensor,
    src: Tensor,
    *,
    use_dst: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    alg = Algo.ELTWISE_LOGISTIC_USE_DST_FOR_BWD if use_dst else Algo.ELTWISE_LOGISTIC
    return eltwise_backward(grad_output, src, alg, out=out, deps=deps, async_op=async_op)


def tanh_backward(
    grad_output: Tensor,
    src: Tensor,
    *,
    use_dst: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    alg = Algo.ELTWISE_TANH_USE_DST_FOR_BWD if use_dst else Algo.ELTWISE_TANH
    return eltwise_backward(grad_output, src, alg, out=out, deps=deps, async_op=async_op)


def gelu_backward(
    grad_output: Tensor,
    src: Tensor,
    *,
    approximate: str = "tanh",
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if approximate == "tanh":
        alg = Algo.ELTWISE_GELU_TANH
    elif approximate in ("none", "erf"):
        alg = Algo.ELTWISE_GELU_ERF
    else:
        raise ValueError("`approximate` must be 'tanh', 'erf', or 'none'")
    return eltwise_backward(grad_output, src, alg, out=out, deps=deps, async_op=async_op)


def elu_backward(
    grad_output: Tensor,
    src: Tensor,
    alpha: float = 1.0,
    *,
    use_dst: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    alg = Algo.ELTWISE_ELU_USE_DST_FOR_BWD if use_dst else Algo.ELTWISE_ELU
    return eltwise_backward(
        grad_output, src, alg, alpha=float(alpha), out=out, deps=deps, async_op=async_op
    )


# ---------------------------------------------------------------------------
# Binary Operations (with Broadcasting)
# ---------------------------------------------------------------------------


def _broadcast_shapes(s0: tuple[int, ...], s1: tuple[int, ...]) -> tuple[int, ...]:
    rank = max(len(s0), len(s1))
    p0 = (1,) * (rank - len(s0)) + s0
    p1 = (1,) * (rank - len(s1)) + s1
    out: list[int] = []
    for d0, d1 in zip(p0, p1):
        if d0 == d1:
            out.append(d0)
        elif d0 == 1:
            out.append(d1)
        elif d1 == 1:
            out.append(d0)
        else:
            raise ValueError(f"shapes {s0} and {s1} are not broadcast-compatible")
    return tuple(out)


def _pad_rank_view(t: Tensor, target_rank: int) -> Memory:
    md = t.descriptor
    if md.rank == target_rank:
        return t.memory()
    pad = target_rank - md.rank
    st = md.strides
    if not st:
        st = _contiguous_strides(md.shape)
    lead_stride = st[0] * md.shape[0] if md.shape else 1
    padded_shape = (1,) * pad + md.shape
    padded_strides = (lead_stride,) * pad + st
    view_md = MemoryDescriptor.from_strides(padded_shape, padded_strides, dtype=md.dtype)
    return Memory.view(view_md, t.memory())


def binary_op(
    a: Tensor,
    b: Tensor,
    algo: Algo | int,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Executes a binary primitive (`add`, `sub`, `mul`, `div`, `max`, `min`, comparisons) with broadcasting."""
    if not isinstance(a, Tensor) or not isinstance(b, Tensor):
        raise TypeError("expected Tensor operands")
    bcast_shape = _broadcast_shapes(a.shape, b.shape)
    rank = len(bcast_shape)
    if out is None:
        dst = Tensor(bcast_shape, dtype=a.dtype, layout=_default_layout(rank))
    else:
        if out.shape != bcast_shape:
            raise ValueError(f"`out` shape {out.shape} does not match broadcast shape {bcast_shape}")
        dst = out

    if a.rank == rank and b.rank == rank:
        pd = PrimitiveDescriptor.binary(algo, dst.descriptor, a.descriptor, b.descriptor)
        prim = Primitive(pd)
        ev = prim.execute(dst, a, b, deps=deps, async_op=async_op)
        return _finish(dst, ev, async_op)

    m0 = _pad_rank_view(a, rank)
    m1 = _pad_rank_view(b, rank)
    dst_mem = dst.memory()
    pd = PrimitiveDescriptor.binary(algo, dst_mem.descriptor, m0.descriptor, m1.descriptor)
    prim = Primitive(pd)
    ev = prim.execute(dst_mem, m0, m1, deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def add(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_ADD, out=out, deps=deps, async_op=async_op)


def sub(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_SUB, out=out, deps=deps, async_op=async_op)


def mul(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_MUL, out=out, deps=deps, async_op=async_op)


def div(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_DIV, out=out, deps=deps, async_op=async_op)


def maximum(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_MAX, out=out, deps=deps, async_op=async_op)


def minimum(
    a: Tensor,
    b: Tensor,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return binary_op(a, b, Algo.BINARY_MIN, out=out, deps=deps, async_op=async_op)


# ---------------------------------------------------------------------------
# Matmul & Linear
# ---------------------------------------------------------------------------


def _prepare_bias_view(bias: Tensor, dst_rank: int, out_features: int) -> Memory:
    b_shape = bias.shape
    if len(b_shape) == dst_rank:
        return bias.memory()
    if len(b_shape) == 1 and b_shape[0] == out_features:
        b_md = bias.descriptor
        st0 = b_md.strides[0] if b_md.strides else 1
        view_shape = (1,) * (dst_rank - 1) + (out_features,)
        view_strides = (out_features * st0,) * (dst_rank - 1) + (st0,)
        view_md = MemoryDescriptor.from_strides(view_shape, view_strides, dtype=b_md.dtype)
        return Memory.view(view_md, bias.memory())
    raise ValueError(
        f"bias shape {b_shape} must be 1D ({out_features},) or rank-{dst_rank} broadcastable to output"
    )


def matmul(
    a: Tensor,
    b: Tensor,
    bias: Tensor | None = None,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """2D or batched N-D matrix multiplication (`out = a @ b [+ bias]`)."""
    if not isinstance(a, Tensor) or not isinstance(b, Tensor):
        raise TypeError("expected Tensor operands")
    if a.rank < 2 or b.rank < 2 or a.rank != b.rank:
        raise ValueError(f"matmul expects equal-rank (>=2) tensors, got {a.shape} and {b.shape}")
    if a.shape[-1] != b.shape[-2]:
        raise ValueError(f"inner matmul dimensions mismatch: {a.shape} vs {b.shape}")

    batch_shape = _broadcast_shapes(a.shape[:-2], b.shape[:-2]) if a.rank > 2 else ()
    out_shape = (*batch_shape, a.shape[-2], b.shape[-1])
    dst_rank = len(out_shape)

    if out is None:
        any_dst = MemoryDescriptor.any(out_shape, dtype=a.dtype)
        bias_mem = _prepare_bias_view(bias, dst_rank, b.shape[-1]) if bias is not None else None
        pd = PrimitiveDescriptor.matmul(
            any_dst, a.descriptor, b.descriptor, bias_mem.descriptor if bias_mem is not None else None
        )
        dst = Tensor.from_descriptor(pd.dst_desc())
    else:
        if out.shape != out_shape:
            raise ValueError(f"`out` shape {out.shape} does not match expected {out_shape}")
        dst = out
        bias_mem = _prepare_bias_view(bias, dst_rank, b.shape[-1]) if bias is not None else None
        pd = PrimitiveDescriptor.matmul(
            dst.descriptor,
            a.descriptor,
            b.descriptor,
            bias_mem.descriptor if bias_mem is not None else None,
        )

    prim = Primitive(pd)
    if bias_mem is None:
        ev = prim.execute(dst, a, b, deps=deps, async_op=async_op)
    else:
        ev = prim.execute(
            dst=dst.memory(),
            src=a.memory(),
            weights=b.memory(),
            bias=bias_mem,
            deps=deps,
            async_op=async_op,
        )
    return _finish(dst, ev, async_op)


def linear(
    input: Tensor,
    weight: Tensor,
    bias: Tensor | None = None,
    *,
    transpose_weight: bool = True,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Applies a linear transformation:

    - When `transpose_weight=True` (default, PyTorch convention): `weight` has shape
      `(out_features, in_features)` and computes `input @ weight.T + bias` via a zero-copy
      strided descriptor view fused directly into oneDNN Matmul.
    - When `transpose_weight=False`: `weight` has shape `(in_features, out_features)` and
      computes `input @ weight + bias`.
    """
    if not isinstance(input, Tensor) or not isinstance(weight, Tensor):
        raise TypeError("expected Tensor operands")
    if input.rank < 2 or weight.rank != 2:
        raise ValueError(
            f"linear expects input rank >= 2 and 2D weight, got {input.shape} and {weight.shape}"
        )

    w_md = weight.descriptor
    w_strides = w_md.strides if w_md.strides else _contiguous_strides(w_md.shape)
    if transpose_weight:
        out_features, in_features = w_md.shape
        logical_w_shape = (in_features, out_features)
        logical_w_strides = (w_strides[1], w_strides[0])
    else:
        in_features, out_features = w_md.shape
        logical_w_shape = (in_features, out_features)
        logical_w_strides = w_strides

    if input.shape[-1] != in_features:
        raise ValueError(
            f"linear input last dim ({input.shape[-1]}) does not match in_features ({in_features})"
        )

    dst_rank = input.rank
    lead_w_stride = max(logical_w_shape[0] * logical_w_strides[0], logical_w_shape[1] * logical_w_strides[1])
    bcast_w_shape = (1,) * (dst_rank - 2) + logical_w_shape
    bcast_w_strides = (lead_w_stride,) * (dst_rank - 2) + logical_w_strides
    w_view_md = MemoryDescriptor.from_strides(bcast_w_shape, bcast_w_strides, dtype=w_md.dtype)
    w_mem = Memory.view(w_view_md, weight.memory())

    out_shape = (*input.shape[:-1], out_features)
    bias_mem = _prepare_bias_view(bias, dst_rank, out_features) if bias is not None else None

    if out is None:
        any_dst = MemoryDescriptor.any(out_shape, dtype=input.dtype)
        pd = PrimitiveDescriptor.matmul(
            any_dst,
            input.descriptor,
            w_view_md,
            bias_mem.descriptor if bias_mem is not None else None,
        )
        dst = Tensor.from_descriptor(pd.dst_desc())
    else:
        if out.shape != out_shape:
            raise ValueError(f"`out` shape {out.shape} does not match expected {out_shape}")
        dst = out
        pd = PrimitiveDescriptor.matmul(
            dst.descriptor,
            input.descriptor,
            w_view_md,
            bias_mem.descriptor if bias_mem is not None else None,
        )

    prim = Primitive(pd)
    slots: dict[str, Memory] = {
        "dst": dst.memory(),
        "src": input.memory(),
        "weights": w_mem,
    }
    if bias_mem is not None:
        slots["bias"] = bias_mem
    ev = prim.execute(deps=deps, async_op=async_op, **slots)
    return _finish(dst, ev, async_op)


# ---------------------------------------------------------------------------
# Softmax & Log-Softmax (Forward & Backward)
# ---------------------------------------------------------------------------


def softmax(
    x: Tensor,
    axis: int = -1,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if not isinstance(x, Tensor):
        raise TypeError("expected Tensor")
    dst = _ensure_unary_out(x, out)
    pd = PrimitiveDescriptor.softmax_forward(
        Algo.SOFTMAX_ACCURATE, dst.descriptor, x.descriptor, axis=axis
    )
    prim = Primitive(pd)
    ev = prim.execute(dst, x, deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def log_softmax(
    x: Tensor,
    axis: int = -1,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if not isinstance(x, Tensor):
        raise TypeError("expected Tensor")
    dst = _ensure_unary_out(x, out)
    pd = PrimitiveDescriptor.softmax_forward(
        Algo.SOFTMAX_LOG, dst.descriptor, x.descriptor, axis=axis
    )
    prim = Primitive(pd)
    ev = prim.execute(dst, x, deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def softmax_backward(
    grad_output: Tensor,
    output: Tensor,
    axis: int = -1,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if not isinstance(grad_output, Tensor) or not isinstance(output, Tensor):
        raise TypeError("expected Tensor operands")
    diff_src = _ensure_unary_out(output, out)
    pd = PrimitiveDescriptor.softmax_backward(
        Algo.SOFTMAX_ACCURATE,
        diff_src.descriptor,
        grad_output.descriptor,
        output.descriptor,
        axis=axis,
    )
    prim = Primitive(pd)
    ev = prim.execute(diff_src, grad_output, output, deps=deps, async_op=async_op)
    return _finish(diff_src, ev, async_op)


def log_softmax_backward(
    grad_output: Tensor,
    output: Tensor,
    axis: int = -1,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if not isinstance(grad_output, Tensor) or not isinstance(output, Tensor):
        raise TypeError("expected Tensor operands")
    diff_src = _ensure_unary_out(output, out)
    pd = PrimitiveDescriptor.softmax_backward(
        Algo.SOFTMAX_LOG,
        diff_src.descriptor,
        grad_output.descriptor,
        output.descriptor,
        axis=axis,
    )
    prim = Primitive(pd)
    ev = prim.execute(diff_src, grad_output, output, deps=deps, async_op=async_op)
    return _finish(diff_src, ev, async_op)


# ---------------------------------------------------------------------------
# Reductions
# ---------------------------------------------------------------------------


def _normalize_axes(rank: int, axis: int | Sequence[int] | None) -> tuple[int, ...]:
    if axis is None:
        return tuple(range(rank))
    raw = [axis] if isinstance(axis, int) else list(axis)
    if not raw:
        raise ValueError("reduction axis sequence cannot be empty")
    normed: list[int] = []
    for ax in raw:
        idx = ax + rank if ax < 0 else ax
        if idx < 0 or idx >= rank:
            raise ValueError(f"axis {ax} out of bounds for tensor of rank {rank}")
        if idx not in normed:
            normed.append(idx)
    return tuple(sorted(normed))


def _reduce(
    x: Tensor,
    algo: Algo,
    *,
    axis: int | Sequence[int] | None = None,
    keepdims: bool = False,
    p: float = 0.0,
    eps: float = 0.0,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    if not isinstance(x, Tensor):
        raise TypeError("expected Tensor")
    src_shape = x.shape
    rank = len(src_shape)
    axes = _normalize_axes(rank, axis)
    axes_set = set(axes)

    reduced_shape = tuple(1 if i in axes_set else d for i, d in enumerate(src_shape))
    if keepdims:
        final_shape = reduced_shape
    else:
        squeezed = tuple(d for i, d in enumerate(src_shape) if i not in axes_set)
        final_shape = squeezed if squeezed else (1,)

    if out is None:
        dst = Tensor(final_shape, dtype=x.dtype, layout=_default_layout(len(final_shape)))
    else:
        if out.shape != final_shape:
            raise ValueError(f"`out` shape {out.shape} does not match reduced shape {final_shape}")
        dst = out

    dst_red_md = MemoryDescriptor.from_strides(
        reduced_shape, _contiguous_strides(reduced_shape), dtype=dst.dtype
    )
    dst_red_mem = Memory.view(dst_red_md, dst.memory())

    # Degenerate case: all reduced dimensions already had extent 1 (oneDNN requires src_dims != dst_dims)
    if reduced_shape == src_shape and algo in (
        Algo.REDUCTION_SUM,
        Algo.REDUCTION_MEAN,
        Algo.REDUCTION_MAX,
        Algo.REDUCTION_MIN,
        Algo.REDUCTION_MUL,
    ):
        pd = PrimitiveDescriptor.reorder(dst_red_md, x.descriptor)
        prim = Primitive(pd)
        ev = prim.execute(dst_red_mem, x.memory(), deps=deps, async_op=async_op)
        return _finish(dst, ev, async_op)

    pd = PrimitiveDescriptor.reduction(algo, dst_red_md, x.descriptor, p=p, eps=eps)
    prim = Primitive(pd)
    ev = prim.execute(dst_red_mem, x.memory(), deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def reduce_sum(
    x: Tensor,
    axis: int | Sequence[int] | None = None,
    *,
    keepdims: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return _reduce(
        x, Algo.REDUCTION_SUM, axis=axis, keepdims=keepdims, out=out, deps=deps, async_op=async_op
    )


def reduce_mean(
    x: Tensor,
    axis: int | Sequence[int] | None = None,
    *,
    keepdims: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return _reduce(
        x, Algo.REDUCTION_MEAN, axis=axis, keepdims=keepdims, out=out, deps=deps, async_op=async_op
    )


def reduce_max(
    x: Tensor,
    axis: int | Sequence[int] | None = None,
    *,
    keepdims: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return _reduce(
        x, Algo.REDUCTION_MAX, axis=axis, keepdims=keepdims, out=out, deps=deps, async_op=async_op
    )


def reduce_min(
    x: Tensor,
    axis: int | Sequence[int] | None = None,
    *,
    keepdims: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return _reduce(
        x, Algo.REDUCTION_MIN, axis=axis, keepdims=keepdims, out=out, deps=deps, async_op=async_op
    )


def reduce_mul(
    x: Tensor,
    axis: int | Sequence[int] | None = None,
    *,
    keepdims: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    return _reduce(
        x, Algo.REDUCTION_MUL, axis=axis, keepdims=keepdims, out=out, deps=deps, async_op=async_op
    )


def reduce_lp_norm(
    x: Tensor,
    p: float = 2.0,
    axis: int | Sequence[int] | None = None,
    *,
    eps: float = 0.0,
    keepdims: bool = False,
    power_p: bool = False,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    alg = Algo.REDUCTION_NORM_LP_POWER_P_SUM if power_p else Algo.REDUCTION_NORM_LP_SUM
    return _reduce(
        x,
        alg,
        axis=axis,
        keepdims=keepdims,
        p=float(p),
        eps=float(eps),
        out=out,
        deps=deps,
        async_op=async_op,
    )


# ---------------------------------------------------------------------------
# Concat, Scaled Multi-Tensor Sum, & Reorder
# ---------------------------------------------------------------------------


def concat(
    tensors: Sequence[Tensor],
    axis: int = 0,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Concatenates a non-empty sequence of tensors along `axis`."""
    if not tensors:
        raise ValueError("concat expects at least one tensor")
    for t in tensors:
        if not isinstance(t, Tensor):
            raise TypeError("all elements of `tensors` must be Tensor")
    pd = PrimitiveDescriptor.concat(
        [t.descriptor for t in tensors],
        axis=axis,
        dst=out.descriptor if out is not None else None,
    )
    dst = out if out is not None else Tensor.from_descriptor(pd.dst_desc())
    prim = Primitive(pd)
    ev = prim.execute(dst, list(tensors), deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def sum_tensors(
    tensors: Sequence[Tensor],
    scales: Sequence[float] | None = None,
    *,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Computes `sum_i(scales[i] * tensors[i])` using a single fused Sum primitive."""
    if not tensors:
        raise ValueError("sum_tensors expects at least one tensor")
    for t in tensors:
        if not isinstance(t, Tensor):
            raise TypeError("all elements of `tensors` must be Tensor")
    target_desc = out.descriptor if out is not None else MemoryDescriptor.any(tensors[0].shape, tensors[0].dtype)
    pd = PrimitiveDescriptor.sum(target_desc, [t.descriptor for t in tensors], scales=scales)
    dst = out if out is not None else Tensor.from_descriptor(pd.dst_desc())
    prim = Primitive(pd)
    ev = prim.execute(dst, list(tensors), deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)


def reorder(
    x: Tensor,
    *,
    dtype: DataType | int | None = None,
    layout: Layout | int | None = None,
    desc: MemoryDescriptor | None = None,
    out: Tensor | None = None,
    deps: Sequence[Event] | None = None,
    async_op: bool = False,
) -> TensorOrAsync:
    """Converts tensor physical layout and/or element datatype using a Reorder primitive."""
    if not isinstance(x, Tensor):
        raise TypeError("expected Tensor")
    if out is not None:
        dst = out
    elif desc is not None:
        dst = Tensor.from_descriptor(desc)
    else:
        target_dtype = x.dtype if dtype is None else DataType(int(dtype))
        target_layout = x.layout if layout is None else Layout(int(layout))
        target_md = MemoryDescriptor(x.shape, dtype=target_dtype, layout=target_layout)
        dst = Tensor.from_descriptor(target_md)
    pd = PrimitiveDescriptor.reorder(dst.descriptor, x.descriptor)
    prim = Primitive(pd)
    ev = prim.execute(dst, x, deps=deps, async_op=async_op)
    return _finish(dst, ev, async_op)
