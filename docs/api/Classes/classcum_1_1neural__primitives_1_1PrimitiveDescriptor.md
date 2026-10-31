---
title: cum::neural_primitives::PrimitiveDescriptor
summary: Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters. 

---

# cum::neural_primitives::PrimitiveDescriptor



Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters.  [More...](#detailed-description)


`#include <PrimitiveDescriptor.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Impl](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md)** <br>Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp.  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[Kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#enum-kind)** { undef = 0, binary, elementwise, matmul, softmax, reduction, reorder, sum, concat}<br>[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md) operation category.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor)**() |
| | **[~PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-~primitivedescriptor)**() |
| | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor)**(const PrimitiveDescriptor & other) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-operator=)**(const [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & other) |
| | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor)**(PrimitiveDescriptor && other) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-operator=)**([PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) && other) |
| bool | **[valid](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-valid)**() const<br>Checks whether this descriptor holds a valid resolved primitive configuration.  |
| | **[operator bool](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-valid).  |
| [Kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#enum-kind) | **[kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-kind)**() const<br>Returns primitive operation category.  |
| [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) | **[purpose](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-purpose)**() const<br>Returns propagation mode (`forward`, `backward`, etc.).  |
| [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) | **[algorithm](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-algorithm)**() const<br>Returns algorithm tag (`[Algo::undef](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-undef)` for operations without sub-algorithms like `[Matmul]()` or `[Reorder]()`).  |
| std::string_view | **[impl_info](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-impl-info)**() const<br>Returns backend kernel implementation name selected for this descriptor.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[src_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-src-desc)**(int index =0) const<br>Queries resolved source memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[dst_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-dst-desc)**(int index =0) const<br>Queries resolved destination memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[weights_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-weights-desc)**(int index =0) const<br>Queries resolved weights memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[bias_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-bias-desc)**() const<br>Queries resolved bias memory descriptor (empty if primitive has no bias).  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[diff_src_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-diff-src-desc)**(int index =0) const<br>Queries resolved gradient-source (`diff_src`) memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[diff_dst_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-diff-dst-desc)**(int index =0) const<br>Queries resolved gradient-destination (`diff_dst`) memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[diff_weights_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-diff-weights-desc)**(int index =0) const<br>Queries resolved gradient-weights (`diff_weights`) memory descriptor at `index`.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[workspace_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-workspace-desc)**() const<br>Queries workspace memory descriptor required between forward and backward passes (empty if none).  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[scratchpad_desc](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-scratchpad-desc)**() const<br>Queries temporary scratchpad memory descriptor.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Binary](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-binary)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src0, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src1)<br>Creates a binary elementwise/broadcasting primitive descriptor (`dst = op(src0, src1)`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Binary](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-binary)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src0, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src1) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[ElementwiseForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwiseforward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, float alpha =0.0f, float beta =0.0f, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward))<br>Creates a forward elementwise primitive descriptor with optional `alpha` and `beta` parameters.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[ElementwiseForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwiseforward)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, float alpha =0.0f, float beta =0.0f, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward)) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Elementwise](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwise)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward))<br>Creates a forward elementwise primitive descriptor (default parameters `alpha = 0`, `beta = 0`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Elementwise](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwise)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, float alpha, float beta =0.0f, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward))<br>Creates a parameterized forward elementwise primitive descriptor.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[ElementwiseBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwisebackward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & data, const [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & hint_fwd_pd, float alpha =0.0f, float beta =0.0f)<br>Creates a backward elementwise primitive descriptor using an explicit forward descriptor hint.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[ElementwiseBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwisebackward)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & data, const [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & hint_fwd_pd, float alpha =0.0f, float beta =0.0f) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[ElementwiseBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwisebackward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & data, float alpha =0.0f, float beta =0.0f)<br>Creates a backward elementwise primitive descriptor (automatically synthesizing the forward hint).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Matmul](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-matmul)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & weights)<br>Creates a 2D or batched N-D matrix multiplication descriptor (`dst = src * weights`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Matmul](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-matmul)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & weights) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Matmul](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-matmul)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & weights, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & bias)<br>Creates a 2D or batched N-D matrix multiplication descriptor with additive bias (`dst = src * weights + bias`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Matmul](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-matmul)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & weights, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & bias) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[SoftmaxForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxforward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, int axis =-1, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward))<br>Creates a forward softmax or log-softmax primitive descriptor along `axis` (supports negative indexing, e.g. `-1`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[SoftmaxForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxforward)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, int axis =-1, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward)) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Softmax](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmax)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, int axis =-1, [Purpose](Namespaces/namespacecum_1_1neural__primitives.md#enum-purpose) prop_kind =[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward))<br>Alias for [SoftmaxForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxforward).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[SoftmaxBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxbackward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, int axis, const [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & hint_fwd_pd)<br>Creates a backward softmax/log-softmax descriptor using an explicit forward descriptor hint.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[SoftmaxBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxbackward)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, int axis, const [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) & hint_fwd_pd) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[SoftmaxBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxbackward)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_src, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & diff_dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, int axis =-1)<br>Creates a backward softmax/log-softmax descriptor (automatically synthesizing the forward hint).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Reduction](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reduction)**([Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, float p =0.0f, float eps =0.0f)<br>Creates a tensor reduction descriptor (`dst` must have the same rank as `src` with reduced axes set to `1`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Reduction](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reduction)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, [Algo](Namespaces/namespacecum_1_1neural__primitives.md#enum-algo) alg, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src, float p =0.0f, float eps =0.0f) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Reorder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reorder)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src)<br>Creates a layout and/or datatype conversion (`[Reorder]()`) primitive descriptor on the active engine.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Reorder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reorder)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & dst_engine, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & src_engine, const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & src)<br>Creates a cross-engine or explicit-engine `[Reorder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reorder)` primitive descriptor.  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Sum](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-sum)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, std::span< const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, std::span< const float > scales ={})<br>Creates a scaled multi-tensor summation descriptor (`dst = sum_i(scales[i] * srcs[i])`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Sum](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-sum)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, std::initializer_list< [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, std::initializer_list< float > scales ={}) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Concat](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-concat)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, std::span< const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, int axis =0)<br>Creates an out-of-place tensor concatenation descriptor along `axis` (supports negative indexing).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Concat](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-concat)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & dst, std::initializer_list< [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, int axis =0) |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Concat](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-concat)**(std::span< const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, int axis =0)<br>Creates a concatenation descriptor with automatically deduced destination descriptor (`pd.dst_desc()`).  |
| [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor) | **[Concat](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-concat)**(std::initializer_list< [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > srcs, int axis =0) |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-primitivedescriptor)**(std::unique_ptr< [Impl](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md) > impl) |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [Impl](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md) > | **[_impl](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#variable--impl)**  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Primitive](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#friend-primitive)**  |
| struct | **[PrimitiveDescriptorBuilder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#friend-primitivedescriptorbuilder)**  |

## Detailed Description

```cpp
class cum::neural_primitives::PrimitiveDescriptor;
```

Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters. 

Constructed via static factory methods (`[Binary](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-binary)`, `[Elementwise](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwise)`, `[ElementwiseBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-elementwisebackward)`, `[Matmul](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-matmul)`, `[Softmax](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmax)`, `[SoftmaxBackward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxbackward)`, `[Reduction](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reduction)`, `[Reorder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reorder)`, `[Sum](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-sum)`, `[Concat](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-concat)`) and compiled into an executable [Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md). 

## Public Types Documentation

### enum Kind

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| undef | 0|   |
| binary | |   |
| elementwise | |   |
| matmul | |   |
| softmax | |   |
| reduction | |   |
| reorder | |   |
| sum | |   |
| concat | |   |



[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md) operation category. 

## Public Functions Documentation

### function PrimitiveDescriptor

```cpp
PrimitiveDescriptor()
```


### function ~PrimitiveDescriptor

```cpp
~PrimitiveDescriptor()
```


### function PrimitiveDescriptor

```cpp
PrimitiveDescriptor(
    const PrimitiveDescriptor & other
)
```


### function operator=

```cpp
PrimitiveDescriptor & operator=(
    const PrimitiveDescriptor & other
)
```


### function PrimitiveDescriptor

```cpp
PrimitiveDescriptor(
    PrimitiveDescriptor && other
)
```


### function operator=

```cpp
PrimitiveDescriptor & operator=(
    PrimitiveDescriptor && other
)
```


### function valid

```cpp
bool valid() const
```

Checks whether this descriptor holds a valid resolved primitive configuration. 

### function operator bool

```cpp
inline explicit operator bool() const
```

Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-valid). 

### function kind

```cpp
Kind kind() const
```

Returns primitive operation category. 

### function purpose

```cpp
Purpose purpose() const
```

Returns propagation mode (`forward`, `backward`, etc.). 

### function algorithm

```cpp
Algo algorithm() const
```

Returns algorithm tag (`[Algo::undef](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-undef)` for operations without sub-algorithms like `[Matmul]()` or `[Reorder]()`). 

### function impl_info

```cpp
std::string_view impl_info() const
```

Returns backend kernel implementation name selected for this descriptor. 

### function src_desc

```cpp
MemoryDescriptor src_desc(
    int index =0
) const
```

Queries resolved source memory descriptor at `index`. 

### function dst_desc

```cpp
MemoryDescriptor dst_desc(
    int index =0
) const
```

Queries resolved destination memory descriptor at `index`. 

### function weights_desc

```cpp
MemoryDescriptor weights_desc(
    int index =0
) const
```

Queries resolved weights memory descriptor at `index`. 

### function bias_desc

```cpp
MemoryDescriptor bias_desc() const
```

Queries resolved bias memory descriptor (empty if primitive has no bias). 

### function diff_src_desc

```cpp
MemoryDescriptor diff_src_desc(
    int index =0
) const
```

Queries resolved gradient-source (`diff_src`) memory descriptor at `index`. 

### function diff_dst_desc

```cpp
MemoryDescriptor diff_dst_desc(
    int index =0
) const
```

Queries resolved gradient-destination (`diff_dst`) memory descriptor at `index`. 

### function diff_weights_desc

```cpp
MemoryDescriptor diff_weights_desc(
    int index =0
) const
```

Queries resolved gradient-weights (`diff_weights`) memory descriptor at `index`. 

### function workspace_desc

```cpp
MemoryDescriptor workspace_desc() const
```

Queries workspace memory descriptor required between forward and backward passes (empty if none). 

### function scratchpad_desc

```cpp
MemoryDescriptor scratchpad_desc() const
```

Queries temporary scratchpad memory descriptor. 

### function Binary

```cpp
static PrimitiveDescriptor Binary(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src0,
    const MemoryDescriptor & src1
)
```

Creates a binary elementwise/broadcasting primitive descriptor (`dst = op(src0, src1)`). 

### function Binary

```cpp
static PrimitiveDescriptor Binary(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src0,
    const MemoryDescriptor & src1
)
```


### function ElementwiseForward

```cpp
static PrimitiveDescriptor ElementwiseForward(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    float alpha =0.0f,
    float beta =0.0f,
    Purpose prop_kind =Purpose::forward
)
```

Creates a forward elementwise primitive descriptor with optional `alpha` and `beta` parameters. 

**Parameters**: 

  * **alg** Elementwise algorithm (`eltwise_relu`, `eltwise_elu`, `eltwise_clip`, `eltwise_linear`, etc.). 
  * **dst** Destination memory descriptor. 
  * **src** Source memory descriptor. 
  * **alpha** Algorithm parameter (e.g. negative slope for Leaky ReLU, scale for ELU/Swish/Linear/Pow, lower bound for Clip). 
  * **beta** Secondary algorithm parameter (e.g. shift for Linear, exponent for Pow, upper bound for Clip). 
  * **prop_kind** Forward propagation mode (`[Purpose::forward](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward)` or `[Purpose::forward_inference](Namespaces/namespacecum_1_1neural__primitives.md#enumvalue-forward-inference)`). 


### function ElementwiseForward

```cpp
static PrimitiveDescriptor ElementwiseForward(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    float alpha =0.0f,
    float beta =0.0f,
    Purpose prop_kind =Purpose::forward
)
```


### function Elementwise

```cpp
static PrimitiveDescriptor Elementwise(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    Purpose prop_kind =Purpose::forward
)
```

Creates a forward elementwise primitive descriptor (default parameters `alpha = 0`, `beta = 0`). 

### function Elementwise

```cpp
static PrimitiveDescriptor Elementwise(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    float alpha,
    float beta =0.0f,
    Purpose prop_kind =Purpose::forward
)
```

Creates a parameterized forward elementwise primitive descriptor. 

### function ElementwiseBackward

```cpp
static PrimitiveDescriptor ElementwiseBackward(
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & data,
    const PrimitiveDescriptor & hint_fwd_pd,
    float alpha =0.0f,
    float beta =0.0f
)
```

Creates a backward elementwise primitive descriptor using an explicit forward descriptor hint. 

**Parameters**: 

  * **alg** Elementwise algorithm. 
  * **diff_src** Output gradient w.r.t. input (`dx`) memory descriptor. 
  * **diff_dst** Upstream gradient w.r.t. output (`dy`) memory descriptor. 
  * **data** Forward `src` descriptor (or forward `dst` descriptor for `*_use_dst_for_bwd` algorithms). 
  * **hint_fwd_pd** Matching forward elementwise primitive descriptor. 
  * **alpha** Algorithm `alpha` parameter. 
  * **beta** Algorithm `beta` parameter. 


### function ElementwiseBackward

```cpp
static PrimitiveDescriptor ElementwiseBackward(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & data,
    const PrimitiveDescriptor & hint_fwd_pd,
    float alpha =0.0f,
    float beta =0.0f
)
```


### function ElementwiseBackward

```cpp
static PrimitiveDescriptor ElementwiseBackward(
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & data,
    float alpha =0.0f,
    float beta =0.0f
)
```

Creates a backward elementwise primitive descriptor (automatically synthesizing the forward hint). 

### function Matmul

```cpp
static PrimitiveDescriptor Matmul(
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    const MemoryDescriptor & weights
)
```

Creates a 2D or batched N-D matrix multiplication descriptor (`dst = src * weights`). 

### function Matmul

```cpp
static PrimitiveDescriptor Matmul(
    Engine & engine,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    const MemoryDescriptor & weights
)
```


### function Matmul

```cpp
static PrimitiveDescriptor Matmul(
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    const MemoryDescriptor & weights,
    const MemoryDescriptor & bias
)
```

Creates a 2D or batched N-D matrix multiplication descriptor with additive bias (`dst = src * weights + bias`). 

### function Matmul

```cpp
static PrimitiveDescriptor Matmul(
    Engine & engine,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    const MemoryDescriptor & weights,
    const MemoryDescriptor & bias
)
```


### function SoftmaxForward

```cpp
static PrimitiveDescriptor SoftmaxForward(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    int axis =-1,
    Purpose prop_kind =Purpose::forward
)
```

Creates a forward softmax or log-softmax primitive descriptor along `axis` (supports negative indexing, e.g. `-1`). 

### function SoftmaxForward

```cpp
static PrimitiveDescriptor SoftmaxForward(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    int axis =-1,
    Purpose prop_kind =Purpose::forward
)
```


### function Softmax

```cpp
static PrimitiveDescriptor Softmax(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    int axis =-1,
    Purpose prop_kind =Purpose::forward
)
```

Alias for [SoftmaxForward](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-softmaxforward). 

### function SoftmaxBackward

```cpp
static PrimitiveDescriptor SoftmaxBackward(
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & dst,
    int axis,
    const PrimitiveDescriptor & hint_fwd_pd
)
```

Creates a backward softmax/log-softmax descriptor using an explicit forward descriptor hint. 

### function SoftmaxBackward

```cpp
static PrimitiveDescriptor SoftmaxBackward(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & dst,
    int axis,
    const PrimitiveDescriptor & hint_fwd_pd
)
```


### function SoftmaxBackward

```cpp
static PrimitiveDescriptor SoftmaxBackward(
    Algo alg,
    const MemoryDescriptor & diff_src,
    const MemoryDescriptor & diff_dst,
    const MemoryDescriptor & dst,
    int axis =-1
)
```

Creates a backward softmax/log-softmax descriptor (automatically synthesizing the forward hint). 

### function Reduction

```cpp
static PrimitiveDescriptor Reduction(
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    float p =0.0f,
    float eps =0.0f
)
```

Creates a tensor reduction descriptor (`dst` must have the same rank as `src` with reduced axes set to `1`). 

**Parameters**: 

  * **alg** Reduction algorithm (`reduction_sum`, `reduction_mean`, `reduction_max`, `reduction_min`, `reduction_mul`, `reduction_norm_lp_*`). 
  * **dst** Reduced destination memory descriptor. 
  * **src** Input source memory descriptor. 
  * **p** Power parameter for Lp-norm reductions (>= 1.0 when applicable). 
  * **eps** Epsilon parameter for Lp-norm reductions. 


### function Reduction

```cpp
static PrimitiveDescriptor Reduction(
    Engine & engine,
    Algo alg,
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src,
    float p =0.0f,
    float eps =0.0f
)
```


### function Reorder

```cpp
static PrimitiveDescriptor Reorder(
    const MemoryDescriptor & dst,
    const MemoryDescriptor & src
)
```

Creates a layout and/or datatype conversion (`[Reorder]()`) primitive descriptor on the active engine. 

### function Reorder

```cpp
static PrimitiveDescriptor Reorder(
    Engine & dst_engine,
    const MemoryDescriptor & dst,
    Engine & src_engine,
    const MemoryDescriptor & src
)
```

Creates a cross-engine or explicit-engine `[Reorder](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#function-reorder)` primitive descriptor. 

### function Sum

```cpp
static PrimitiveDescriptor Sum(
    const MemoryDescriptor & dst,
    std::span< const MemoryDescriptor > srcs,
    std::span< const float > scales ={}
)
```

Creates a scaled multi-tensor summation descriptor (`dst = sum_i(scales[i] * srcs[i])`). 

**Parameters**: 

  * **dst** Destination memory descriptor (may use `[layout::ANY](Namespaces/namespacecum.md#enumvalue-any)`). 
  * **srcs** Span of input memory descriptors. 
  * **scales** Optional per-input scale factors (defaults to `1.0f` for every input if empty). 


### function Sum

```cpp
static PrimitiveDescriptor Sum(
    const MemoryDescriptor & dst,
    std::initializer_list< MemoryDescriptor > srcs,
    std::initializer_list< float > scales ={}
)
```


### function Concat

```cpp
static PrimitiveDescriptor Concat(
    const MemoryDescriptor & dst,
    std::span< const MemoryDescriptor > srcs,
    int axis =0
)
```

Creates an out-of-place tensor concatenation descriptor along `axis` (supports negative indexing). 

### function Concat

```cpp
static PrimitiveDescriptor Concat(
    const MemoryDescriptor & dst,
    std::initializer_list< MemoryDescriptor > srcs,
    int axis =0
)
```


### function Concat

```cpp
static PrimitiveDescriptor Concat(
    std::span< const MemoryDescriptor > srcs,
    int axis =0
)
```

Creates a concatenation descriptor with automatically deduced destination descriptor (`pd.dst_desc()`). 

### function Concat

```cpp
static PrimitiveDescriptor Concat(
    std::initializer_list< MemoryDescriptor > srcs,
    int axis =0
)
```


## Protected Functions Documentation

### function PrimitiveDescriptor

```cpp
explicit PrimitiveDescriptor(
    std::unique_ptr< Impl > impl
)
```


## Protected Attributes Documentation

### variable _impl

```cpp
std::unique_ptr< Impl > _impl;
```


## Friends

### friend Primitive

```cpp
friend class Primitive(
    Primitive 
);
```


### friend PrimitiveDescriptorBuilder

```cpp
friend struct PrimitiveDescriptorBuilder(
    PrimitiveDescriptorBuilder 
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100