---
title: cum::neural_primitives

---

# cum::neural_primitives



## Namespaces

| Name           |
| -------------- |
| **[cum::neural_primitives::detail](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md)**  |
| **[cum::neural_primitives::handles](Namespaces/namespacecum_1_1neural__primitives_1_1handles.md)**  |
| **[cum::neural_primitives::neural_kernels](Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cum::neural_primitives::EltwiseKernel](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md)** <br>Pre-compiled elementwise neural operation kernel for repeated forward/backward execution.  |
| class | **[cum::neural_primitives::Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md)** <br>Compute execution engine encapsulating device accelerator execution context for primitives.  |
| class | **[cum::neural_primitives::Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md)** <br>Storage buffer managed by neural primitive engine according to a [Descriptor]().  |
| class | **[cum::neural_primitives::MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md)** <br>Encapsulates tensor shape, data type, and memory format layout for neural network primitives.  |
| class | **[cum::neural_primitives::Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md)** <br>Executable compute primitive representing a compiled neural network or tensor operation.  |
| class | **[cum::neural_primitives::PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md)** <br>Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters.  |
| class | **[cum::neural_primitives::Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md)** <br>Core N-dimensional array and deep learning tensor.  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose)** { forward = 64, forward_training = 64, forward_inference = 96, backward = 128, backward_data = 160, backward_weights = 192, backward_bias = 193}<br>Propagation mode for neural network primitives.  |
| enum class| **[Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo)** { undef = 0, eltwise_relu, eltwise_tanh, eltwise_elu, eltwise_square, eltwise_abs, eltwise_sqrt, eltwise_linear, eltwise_soft_relu, eltwise_logistic, eltwise_exp, eltwise_gelu_tanh, eltwise_gelu_erf, eltwise_swish, eltwise_mish, eltwise_log, eltwise_clip, eltwise_clip_v2, eltwise_pow, eltwise_round, eltwise_hardswish, eltwise_hardsigmoid, eltwise_relu_use_dst_for_bwd, eltwise_tanh_use_dst_for_bwd, eltwise_elu_use_dst_for_bwd, eltwise_sqrt_use_dst_for_bwd, eltwise_logistic_use_dst_for_bwd, eltwise_exp_use_dst_for_bwd, eltwise_clip_v2_use_dst_for_bwd, binary_add = 0x100, binary_sub, binary_mul, binary_div, binary_max, binary_min, binary_eq, binary_ne, binary_gt, binary_ge, binary_lt, binary_le, softmax_accurate = 0x200, softmax_log, reduction_max = 0x300, reduction_min, reduction_sum, reduction_mul, reduction_mean, reduction_norm_lp_max, reduction_norm_lp_sum, reduction_norm_lp_power_p_max, reduction_norm_lp_power_p_sum, eltwise_leaky_relu = eltwise_relu, eltwise_sigmoid = eltwise_logistic, eltwise_gelu = eltwise_gelu_tanh, eltwise_clamp = eltwise_clip}<br>Algorithm selector for elementwise, binary, softmax, and reduction primitives.  |

## Functions

|                | Name           |
| -------------- | -------------- |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind)<br>Executes generic elementwise primitive on raw backend handles out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & memory, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind)<br>Executes generic elementwise primitive on raw backend handle in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1neural__primitives.md#function-relu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1neural__primitives.md#function-relu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1neural__primitives.md#function-relu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1neural__primitives.md#function-relu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise)**([Tensor](Classes/classcum_1_1Tensor.md) & tensor, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu](Namespaces/namespacecum_1_1neural__primitives.md#function-relu)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu](Namespaces/namespacecum_1_1neural__primitives.md#function-elu)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu)**([Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square](Namespaces/namespacecum_1_1neural__primitives.md#function-square)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[exp](Namespaces/namespacecum_1_1neural__primitives.md#function-exp)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[log](Namespaces/namespacecum_1_1neural__primitives.md#function-log)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[abs](Namespaces/namespacecum_1_1neural__primitives.md#function-abs)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[clamp](Namespaces/namespacecum_1_1neural__primitives.md#function-clamp)**([Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t min, cumeric_t max) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & memory, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-relu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-relu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-square-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & dst_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[square_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-square-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-relu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-relu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[eltwise_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-eltwise-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & tensor, [functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) algorithm, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-relu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sigmoid_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sigmoid-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[tanh_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-tanh-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[gelu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-gelu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[elu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-elu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[leaky_relu_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-leaky-relu-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src, cumeric_t alpha) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sqrt_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-sqrt-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & src) |
| [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) | **[to_algo](Namespaces/namespacecum_1_1neural__primitives.md#function-to-algo)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) fn)<br>Maps a high-level [cum::functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) to its corresponding [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1)<br>Computes softmax on raw memory handles along specified axis out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & memory, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1)<br>Computes softmax on raw memory handle along specified axis in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & dst, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & src, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & r_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & memory, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & r_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & memory, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & desc, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1)<br>Computes softmax on [Tensor]() along specified axis out-of-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax)**([Tensor](Classes/classcum_1_1Tensor.md) & tensor, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1)<br>Computes softmax on [Tensor]() along specified axis in-place.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & src, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[softmax_diff](Namespaces/namespacecum_1_1neural__primitives.md#function-softmax-diff)**([Tensor](Classes/classcum_1_1Tensor.md) & tensor, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & C, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & c_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & C, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & c_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & C, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & c_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & C, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & c_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & C, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & c_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & A, const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & B, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & a_desc, const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & C, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & c_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & C, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & c_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & C, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & c_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & C, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & c_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & C, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & c_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & A, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & B, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & a_desc, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & b_desc) |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([Tensor](Classes/classcum_1_1Tensor.md) & C, const [Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>Computes tensor elementwise addition: `C` = `A` + `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([Tensor](Classes/classcum_1_1Tensor.md) & C, const [Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>Computes tensor elementwise subtraction: `C` = `A` - `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([Tensor](Classes/classcum_1_1Tensor.md) & C, const [Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>Computes tensor elementwise multiplication (Hadamard): `C` = `A` * `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([Tensor](Classes/classcum_1_1Tensor.md) & C, const [Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>Computes tensor elementwise division: `C` = `A` / `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([Tensor](Classes/classcum_1_1Tensor.md) & C, const [Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>Computes tensor matrix multiplication: `C` = `A` * `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[add](Namespaces/namespacecum_1_1neural__primitives.md#function-add)**([Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>In-place tensor elementwise addition: `A` += `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[sub](Namespaces/namespacecum_1_1neural__primitives.md#function-sub)**([Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>In-place tensor elementwise subtraction: `A` -= `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[mul](Namespaces/namespacecum_1_1neural__primitives.md#function-mul)**([Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>In-place tensor elementwise multiplication: `A` *= `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[div](Namespaces/namespacecum_1_1neural__primitives.md#function-div)**([Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>In-place tensor elementwise division: `A` /= `B`.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[matmul](Namespaces/namespacecum_1_1neural__primitives.md#function-matmul)**([Tensor](Classes/classcum_1_1Tensor.md) & A, const [Tensor](Classes/classcum_1_1Tensor.md) & B)<br>In-place tensor matrix multiplication: `A` = `A` * `B`.  |

## Types Documentation

### enum Purpose

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| forward | 64| Forward propagation (training-compatible, alias for forward_training).   |
| forward_training | 64| Forward propagation saving metadata/workspace needed for backward pass.   |
| forward_inference | 96| Forward propagation optimized for inference only.   |
| backward | 128| Backward propagation for all parameters.   |
| backward_data | 160| Backward propagation with respect to input data.   |
| backward_weights | 192| Backward propagation with respect to weights.   |
| backward_bias | 193| Backward propagation with respect to bias.   |



Propagation mode for neural network primitives. 

Values preserve compatibility with existing elementwise/reduction propagation flags. 


### enum Algo

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| undef | 0|   |
| eltwise_relu | |   |
| eltwise_tanh | |   |
| eltwise_elu | |   |
| eltwise_square | |   |
| eltwise_abs | |   |
| eltwise_sqrt | |   |
| eltwise_linear | |   |
| eltwise_soft_relu | |   |
| eltwise_logistic | |   |
| eltwise_exp | |   |
| eltwise_gelu_tanh | |   |
| eltwise_gelu_erf | |   |
| eltwise_swish | |   |
| eltwise_mish | |   |
| eltwise_log | |   |
| eltwise_clip | |   |
| eltwise_clip_v2 | |   |
| eltwise_pow | |   |
| eltwise_round | |   |
| eltwise_hardswish | |   |
| eltwise_hardsigmoid | |   |
| eltwise_relu_use_dst_for_bwd | |   |
| eltwise_tanh_use_dst_for_bwd | |   |
| eltwise_elu_use_dst_for_bwd | |   |
| eltwise_sqrt_use_dst_for_bwd | |   |
| eltwise_logistic_use_dst_for_bwd | |   |
| eltwise_exp_use_dst_for_bwd | |   |
| eltwise_clip_v2_use_dst_for_bwd | |   |
| binary_add | 0x100|   |
| binary_sub | |   |
| binary_mul | |   |
| binary_div | |   |
| binary_max | |   |
| binary_min | |   |
| binary_eq | |   |
| binary_ne | |   |
| binary_gt | |   |
| binary_ge | |   |
| binary_lt | |   |
| binary_le | |   |
| softmax_accurate | 0x200|   |
| softmax_log | |   |
| reduction_max | 0x300|   |
| reduction_min | |   |
| reduction_sum | |   |
| reduction_mul | |   |
| reduction_mean | |   |
| reduction_norm_lp_max | |   |
| reduction_norm_lp_sum | |   |
| reduction_norm_lp_power_p_max | |   |
| reduction_norm_lp_power_p_sum | |   |
| eltwise_leaky_relu | eltwise_relu|   |
| eltwise_sigmoid | eltwise_logistic|   |
| eltwise_gelu | eltwise_gelu_tanh|   |
| eltwise_clamp | eltwise_clip|   |



Algorithm selector for elementwise, binary, softmax, and reduction primitives. 


## Functions Documentation

### function eltwise

```cpp
__event__ eltwise(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```

Executes generic elementwise primitive on raw backend handles out-of-place. 

### function eltwise

```cpp
__event__ eltwise(
    handles::__memory__ & memory,
    const handles::__desc__ & desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```

Executes generic elementwise primitive on raw backend handle in-place. 

### function relu

```cpp
__event__ relu(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function relu

```cpp
__event__ relu(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function tanh

```cpp
__event__ tanh(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function tanh

```cpp
__event__ tanh(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function gelu

```cpp
__event__ gelu(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function gelu

```cpp
__event__ gelu(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function elu

```cpp
__event__ elu(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function elu

```cpp
__event__ elu(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc,
    cumeric_t alpha
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    handles::__memory__ & src,
    const handles::__desc__ & desc,
    cumeric_t alpha
)
```


### function sqrt

```cpp
__event__ sqrt(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function sqrt

```cpp
__event__ sqrt(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function square

```cpp
__event__ square(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function square

```cpp
__event__ square(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function exp

```cpp
__event__ exp(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function exp

```cpp
__event__ exp(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function log

```cpp
__event__ log(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function log

```cpp
__event__ log(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function abs

```cpp
__event__ abs(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function abs

```cpp
__event__ abs(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function clamp

```cpp
__event__ clamp(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc,
    cumeric_t min,
    cumeric_t max
)
```


### function clamp

```cpp
__event__ clamp(
    handles::__memory__ & src,
    const handles::__desc__ & desc,
    cumeric_t min,
    cumeric_t max
)
```


### function eltwise

```cpp
__event__ eltwise(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function relu

```cpp
__event__ relu(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function relu

```cpp
__event__ relu(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function tanh

```cpp
__event__ tanh(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function tanh

```cpp
__event__ tanh(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function gelu

```cpp
__event__ gelu(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function gelu

```cpp
__event__ gelu(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function elu

```cpp
__event__ elu(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function elu

```cpp
__event__ elu(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc,
    cumeric_t alpha
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    Memory & src,
    const MemoryDescriptor & desc,
    cumeric_t alpha
)
```


### function sqrt

```cpp
__event__ sqrt(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function sqrt

```cpp
__event__ sqrt(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function square

```cpp
__event__ square(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function square

```cpp
__event__ square(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function exp

```cpp
__event__ exp(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function exp

```cpp
__event__ exp(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function log

```cpp
__event__ log(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function log

```cpp
__event__ log(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function abs

```cpp
__event__ abs(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function abs

```cpp
__event__ abs(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function clamp

```cpp
__event__ clamp(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc,
    cumeric_t min,
    cumeric_t max
)
```


### function clamp

```cpp
__event__ clamp(
    Memory & src,
    const MemoryDescriptor & desc,
    cumeric_t min,
    cumeric_t max
)
```


### function eltwise

```cpp
__event__ eltwise(
    Tensor & dst,
    const Tensor & src,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function eltwise

```cpp
__event__ eltwise(
    Tensor & tensor,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function relu

```cpp
__event__ relu(
    Tensor & dst,
    const Tensor & src
)
```


### function sigmoid

```cpp
__event__ sigmoid(
    Tensor & dst,
    const Tensor & src
)
```


### function tanh

```cpp
__event__ tanh(
    Tensor & dst,
    const Tensor & src
)
```


### function tanh

```cpp
__event__ tanh(
    Tensor & src
)
```


### function gelu

```cpp
__event__ gelu(
    Tensor & dst,
    const Tensor & src
)
```


### function gelu

```cpp
__event__ gelu(
    Tensor & src
)
```


### function elu

```cpp
__event__ elu(
    Tensor & dst,
    const Tensor & src
)
```


### function elu

```cpp
__event__ elu(
    Tensor & src
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    Tensor & dst,
    const Tensor & src,
    cumeric_t alpha
)
```


### function leaky_relu

```cpp
__event__ leaky_relu(
    Tensor & src,
    cumeric_t alpha
)
```


### function sqrt

```cpp
__event__ sqrt(
    Tensor & dst,
    const Tensor & src
)
```


### function sqrt

```cpp
__event__ sqrt(
    Tensor & src
)
```


### function square

```cpp
__event__ square(
    Tensor & dst,
    const Tensor & src
)
```


### function square

```cpp
__event__ square(
    Tensor & src
)
```


### function exp

```cpp
__event__ exp(
    Tensor & dst,
    const Tensor & src
)
```


### function exp

```cpp
__event__ exp(
    Tensor & src
)
```


### function log

```cpp
__event__ log(
    Tensor & dst,
    const Tensor & src
)
```


### function log

```cpp
__event__ log(
    Tensor & src
)
```


### function abs

```cpp
__event__ abs(
    Tensor & dst,
    const Tensor & src
)
```


### function abs

```cpp
__event__ abs(
    Tensor & src
)
```


### function clamp

```cpp
__event__ clamp(
    Tensor & dst,
    const Tensor & src,
    cumeric_t min,
    cumeric_t max
)
```


### function clamp

```cpp
__event__ clamp(
    Tensor & src,
    cumeric_t min,
    cumeric_t max
)
```


### function eltwise_diff

```cpp
__event__ eltwise_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function eltwise_diff

```cpp
__event__ eltwise_diff(
    handles::__memory__ & memory,
    const handles::__desc__ & desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function relu_diff

```cpp
__event__ relu_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function relu_diff

```cpp
__event__ relu_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function sigmoid_diff

```cpp
__event__ sigmoid_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function sigmoid_diff

```cpp
__event__ sigmoid_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc,
    cumeric_t alpha
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc,
    cumeric_t alpha
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function square_diff

```cpp
__event__ square_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & dst_desc,
    const handles::__desc__ & src_desc
)
```


### function square_diff

```cpp
__event__ square_diff(
    handles::__memory__ & src,
    const handles::__desc__ & desc
)
```


### function eltwise_diff

```cpp
__event__ eltwise_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function relu_diff

```cpp
__event__ relu_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function relu_diff

```cpp
__event__ relu_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function sigmoid_diff

```cpp
__event__ sigmoid_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function sigmoid_diff

```cpp
__event__ sigmoid_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc,
    cumeric_t alpha
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    Memory & src,
    const MemoryDescriptor & desc,
    cumeric_t alpha
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & dst_desc,
    const MemoryDescriptor & src_desc
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    Memory & src,
    const MemoryDescriptor & desc
)
```


### function eltwise_diff

```cpp
__event__ eltwise_diff(
    Tensor & dst,
    const Tensor & src,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function eltwise_diff

```cpp
__event__ eltwise_diff(
    Tensor & tensor,
    functions::function_id algorithm,
    Purpose prop_kind
)
```


### function relu_diff

```cpp
__event__ relu_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function sigmoid_diff

```cpp
__event__ sigmoid_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function tanh_diff

```cpp
__event__ tanh_diff(
    Tensor & src
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Tensor & src
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function gelu_diff

```cpp
__event__ gelu_diff(
    Tensor & src
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function elu_diff

```cpp
__event__ elu_diff(
    Tensor & src
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    Tensor & dst,
    const Tensor & src,
    cumeric_t alpha
)
```


### function leaky_relu_diff

```cpp
__event__ leaky_relu_diff(
    Tensor & src,
    cumeric_t alpha
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    Tensor & dst,
    const Tensor & src
)
```


### function sqrt_diff

```cpp
__event__ sqrt_diff(
    Tensor & src
)
```


### function to_algo

```cpp
Algo to_algo(
    functions::function_id fn
)
```

Maps a high-level [cum::functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) to its corresponding [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo). 

**Parameters**: 

  * **fn** Activation or math function identifier. 


**Return**: Matching [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo), or [Algo::undef](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-undef) if unsupported by neural primitives. 

### function softmax

```cpp
__event__ softmax(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc,
    dim_t axis =-1
)
```

Computes softmax on raw memory handles along specified axis out-of-place. 

### function softmax

```cpp
__event__ softmax(
    handles::__memory__ & memory,
    const handles::__desc__ & desc,
    dim_t axis =-1
)
```

Computes softmax on raw memory handle along specified axis in-place. 

### function softmax_diff

```cpp
__event__ softmax_diff(
    handles::__memory__ & dst,
    const handles::__memory__ & src,
    const handles::__desc__ & r_desc,
    const handles::__desc__ & a_desc,
    dim_t axis =-1
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    handles::__memory__ & memory,
    const handles::__desc__ & desc,
    dim_t axis =-1
)
```


### function softmax

```cpp
__event__ softmax(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc,
    dim_t axis =-1
)
```


### function softmax

```cpp
__event__ softmax(
    Memory & src,
    const MemoryDescriptor & desc,
    dim_t axis =-1
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Memory & dst,
    const Memory & src,
    const MemoryDescriptor & r_desc,
    const MemoryDescriptor & a_desc,
    dim_t axis =-1
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Memory & memory,
    const MemoryDescriptor & desc,
    dim_t axis =-1
)
```


### function softmax

```cpp
__event__ softmax(
    Tensor & dst,
    const Tensor & src,
    dim_t axis =-1
)
```

Computes softmax on [Tensor]() along specified axis out-of-place. 

**Parameters**: 

  * **dst** Output destination [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **src** Input source [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **axis** Target dimension axis (-1 for last axis). 


**Return**: Asynchronous execution event. 

### function softmax

```cpp
__event__ softmax(
    Tensor & tensor,
    dim_t axis =-1
)
```

Computes softmax on [Tensor]() along specified axis in-place. 

**Parameters**: 

  * **tensor** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **axis** Target dimension axis (-1 for last axis). 


**Return**: Asynchronous execution event. 

### function softmax_diff

```cpp
__event__ softmax_diff(
    Tensor & dst,
    const Tensor & src,
    dim_t axis =-1
)
```


### function softmax_diff

```cpp
__event__ softmax_diff(
    Tensor & tensor,
    dim_t axis =-1
)
```


### function add

```cpp
__event__ add(
    handles::__memory__ & C,
    const handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & c_desc,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function sub

```cpp
__event__ sub(
    handles::__memory__ & C,
    const handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & c_desc,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function mul

```cpp
__event__ mul(
    handles::__memory__ & C,
    const handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & c_desc,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function div

```cpp
__event__ div(
    handles::__memory__ & C,
    const handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & c_desc,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function matmul

```cpp
__event__ matmul(
    handles::__memory__ & C,
    const handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & c_desc,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function add

```cpp
__event__ add(
    handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function sub

```cpp
__event__ sub(
    handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function mul

```cpp
__event__ mul(
    handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function div

```cpp
__event__ div(
    handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function matmul

```cpp
__event__ matmul(
    handles::__memory__ & A,
    const handles::__memory__ & B,
    const handles::__desc__ & a_desc,
    const handles::__desc__ & b_desc
)
```


### function add

```cpp
__event__ add(
    Memory & C,
    const Memory & A,
    const Memory & B,
    const MemoryDescriptor & c_desc,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function sub

```cpp
__event__ sub(
    Memory & C,
    const Memory & A,
    const Memory & B,
    const MemoryDescriptor & c_desc,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function mul

```cpp
__event__ mul(
    Memory & C,
    const Memory & A,
    const Memory & B,
    const MemoryDescriptor & c_desc,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function div

```cpp
__event__ div(
    Memory & C,
    const Memory & A,
    const Memory & B,
    const MemoryDescriptor & c_desc,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function matmul

```cpp
__event__ matmul(
    Memory & C,
    const Memory & A,
    const Memory & B,
    const MemoryDescriptor & c_desc,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function add

```cpp
__event__ add(
    Memory & A,
    const Memory & B,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function sub

```cpp
__event__ sub(
    Memory & A,
    const Memory & B,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function mul

```cpp
__event__ mul(
    Memory & A,
    const Memory & B,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function div

```cpp
__event__ div(
    Memory & A,
    const Memory & B,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function matmul

```cpp
__event__ matmul(
    Memory & A,
    const Memory & B,
    const MemoryDescriptor & a_desc,
    const MemoryDescriptor & b_desc
)
```


### function add

```cpp
__event__ add(
    Tensor & C,
    const Tensor & A,
    const Tensor & B
)
```

Computes tensor elementwise addition: `C` = `A` + `B`. 

**Parameters**: 

  * **C** Output destination [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **A** First input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **B** Second input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 

### function sub

```cpp
__event__ sub(
    Tensor & C,
    const Tensor & A,
    const Tensor & B
)
```

Computes tensor elementwise subtraction: `C` = `A` - `B`. 

**Parameters**: 

  * **C** Output destination [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **A** First input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **B** Second input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 

### function mul

```cpp
__event__ mul(
    Tensor & C,
    const Tensor & A,
    const Tensor & B
)
```

Computes tensor elementwise multiplication (Hadamard): `C` = `A` * `B`. 

**Parameters**: 

  * **C** Output destination [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **A** First input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **B** Second input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 

### function div

```cpp
__event__ div(
    Tensor & C,
    const Tensor & A,
    const Tensor & B
)
```

Computes tensor elementwise division: `C` = `A` / `B`. 

**Parameters**: 

  * **C** Output destination [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **A** Numerator [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **B** Denominator [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 

### function matmul

```cpp
__event__ matmul(
    Tensor & C,
    const Tensor & A,
    const Tensor & B
)
```

Computes tensor matrix multiplication: `C` = `A` * `B`. 

**Parameters**: 

  * **C** Output product [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **A** Left input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 
  * **B** Right input [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 

### function add

```cpp
__event__ add(
    Tensor & A,
    const Tensor & B
)
```

In-place tensor elementwise addition: `A` += `B`. 

**Parameters**: 

  * **A** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **B** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) to add. 


**Return**: Asynchronous execution event. 

### function sub

```cpp
__event__ sub(
    Tensor & A,
    const Tensor & B
)
```

In-place tensor elementwise subtraction: `A` -= `B`. 

**Parameters**: 

  * **A** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **B** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) to subtract. 


**Return**: Asynchronous execution event. 

### function mul

```cpp
__event__ mul(
    Tensor & A,
    const Tensor & B
)
```

In-place tensor elementwise multiplication: `A` *= `B`. 

**Parameters**: 

  * **A** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **B** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) multiplier. 


**Return**: Asynchronous execution event. 

### function div

```cpp
__event__ div(
    Tensor & A,
    const Tensor & B
)
```

In-place tensor elementwise division: `A` /= `B`. 

**Parameters**: 

  * **A** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **B** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) denominator. 


**Return**: Asynchronous execution event. 

### function matmul

```cpp
__event__ matmul(
    Tensor & A,
    const Tensor & B
)
```

In-place tensor matrix multiplication: `A` = `A` * `B`. 

**Parameters**: 

  * **A** Left matrix [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) modified in place. 
  * **B** Right matrix [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 


**Return**: Asynchronous execution event. 





-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100