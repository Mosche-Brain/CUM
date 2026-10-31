"""Enumerations for cumpy.dnn neural primitives."""

from __future__ import annotations

from enum import IntEnum


class Purpose(IntEnum):
    """Propagation mode for neural network primitives."""

    FORWARD = 64
    FORWARD_TRAINING = 64
    FORWARD_INFERENCE = 96
    BACKWARD = 128
    BACKWARD_DATA = 160
    BACKWARD_WEIGHTS = 192
    BACKWARD_BIAS = 193


class Algo(IntEnum):
    """Algorithm selector for elementwise, binary, softmax, and reduction primitives."""

    UNDEF = 0

    # Elementwise algorithms (forward & backward)
    ELTWISE_RELU = 1
    ELTWISE_TANH = 2
    ELTWISE_ELU = 3
    ELTWISE_SQUARE = 4
    ELTWISE_ABS = 5
    ELTWISE_SQRT = 6
    ELTWISE_LINEAR = 7
    ELTWISE_SOFT_RELU = 8
    ELTWISE_LOGISTIC = 9
    ELTWISE_EXP = 10
    ELTWISE_GELU_TANH = 11
    ELTWISE_GELU_ERF = 12
    ELTWISE_SWISH = 13
    ELTWISE_MISH = 14
    ELTWISE_LOG = 15
    ELTWISE_CLIP = 16
    ELTWISE_CLIP_V2 = 17
    ELTWISE_POW = 18
    ELTWISE_ROUND = 19
    ELTWISE_HARDSWISH = 20
    ELTWISE_HARDSIGMOID = 21

    # Elementwise algorithms consuming forward destination `dst` in backward pass
    ELTWISE_RELU_USE_DST_FOR_BWD = 22
    ELTWISE_TANH_USE_DST_FOR_BWD = 23
    ELTWISE_ELU_USE_DST_FOR_BWD = 24
    ELTWISE_SQRT_USE_DST_FOR_BWD = 25
    ELTWISE_LOGISTIC_USE_DST_FOR_BWD = 26
    ELTWISE_EXP_USE_DST_FOR_BWD = 27
    ELTWISE_CLIP_V2_USE_DST_FOR_BWD = 28

    # Binary tensor operations
    BINARY_ADD = 0x100
    BINARY_SUB = 0x101
    BINARY_MUL = 0x102
    BINARY_DIV = 0x103
    BINARY_MAX = 0x104
    BINARY_MIN = 0x105
    BINARY_EQ = 0x106
    BINARY_NE = 0x107
    BINARY_GT = 0x108
    BINARY_GE = 0x109
    BINARY_LT = 0x10A
    BINARY_LE = 0x10B

    # Softmax operations
    SOFTMAX_ACCURATE = 0x200
    SOFTMAX_LOG = 0x201

    # Reduction operations
    REDUCTION_MAX = 0x300
    REDUCTION_MIN = 0x301
    REDUCTION_SUM = 0x302
    REDUCTION_MUL = 0x303
    REDUCTION_MEAN = 0x304
    REDUCTION_NORM_LP_MAX = 0x305
    REDUCTION_NORM_LP_SUM = 0x306
    REDUCTION_NORM_LP_POWER_P_MAX = 0x307
    REDUCTION_NORM_LP_POWER_P_SUM = 0x308

    # Ergonomic aliases
    ELTWISE_LEAKY_RELU = 1
    ELTWISE_SIGMOID = 9
    ELTWISE_SILU = 13
    ELTWISE_SOFTPLUS = 8
    ELTWISE_GELU = 11
    ELTWISE_CLAMP = 16


class PrimitiveKind(IntEnum):
    """Primitive operation category."""

    UNDEF = 0
    BINARY = 1
    ELEMENTWISE = 2
    MATMUL = 3
    SOFTMAX = 4
    REDUCTION = 5
    REORDER = 6
    SUM = 7
    CONCAT = 8


class Argument(IntEnum):
    """Named tensor/memory argument slots for Primitive execution."""

    UNDEF = 0
    SRC = 1
    SRC_0 = 1
    SRC_1 = 2
    SRC_2 = 3
    SRC_3 = 4
    DST = 17
    DST_0 = 17
    WEIGHTS = 33
    BIAS = 41
    WORKSPACE = 64
    SCRATCHPAD = 80
    DIFF_SRC = 129
    DIFF_SRC_0 = 129
    DIFF_SRC_1 = 130
    DIFF_DST = 145
    DIFF_WEIGHTS = 161
    DIFF_BIAS = 169
    MULTIPLE_SRC = 1024

    @classmethod
    def multiple_src_at(cls, index: int) -> int:
        """Returns the indexed variadic source slot (`Argument.MULTIPLE_SRC + index`) for Sum/Concat."""
        if index < 0:
            raise ValueError("multiple_src index must be non-negative")
        return int(cls.MULTIPLE_SRC) + int(index)
