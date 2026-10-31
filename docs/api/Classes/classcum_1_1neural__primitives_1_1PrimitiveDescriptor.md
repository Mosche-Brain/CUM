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
| struct | **[Impl](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/)** <br>Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp.  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#enum-kind)** { undef = 0, binary, elementwise, matmul, softmax, reduction, reorder, sum, concat}<br>[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/) operation category.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor)**() |
| | **[~PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-~primitivedescriptor)**() |
| | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor)**(const PrimitiveDescriptor & other) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-operator=)**(const [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & other) |
| | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor)**(PrimitiveDescriptor && other) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-operator=)**([PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) && other) |
| bool | **[valid](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-valid)**() const<br>Checks whether this descriptor holds a valid resolved primitive configuration.  |
| | **[operator bool](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-valid).  |
| [Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#enum-kind) | **[kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-kind)**() const<br>Returns primitive operation category.  |
| [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) | **[purpose](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-purpose)**() const<br>Returns propagation mode (`forward`, `backward`, etc.).  |
| [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) | **[algorithm](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-algorithm)**() const<br>Returns algorithm tag (`[Algo::undef](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-undef)` for operations without sub-algorithms like `[Matmul]()` or `[Reorder]()`).  |
| std::string_view | **[impl_info](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-impl-info)**() const<br>Returns backend kernel implementation name selected for this descriptor.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[src_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-src-desc)**(int index =0) const<br>Queries resolved source memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[dst_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-dst-desc)**(int index =0) const<br>Queries resolved destination memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[weights_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-weights-desc)**(int index =0) const<br>Queries resolved weights memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[bias_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-bias-desc)**() const<br>Queries resolved bias memory descriptor (empty if primitive has no bias).  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[diff_src_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-diff-src-desc)**(int index =0) const<br>Queries resolved gradient-source (`diff_src`) memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[diff_dst_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-diff-dst-desc)**(int index =0) const<br>Queries resolved gradient-destination (`diff_dst`) memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[diff_weights_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-diff-weights-desc)**(int index =0) const<br>Queries resolved gradient-weights (`diff_weights`) memory descriptor at `index`.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[workspace_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-workspace-desc)**() const<br>Queries workspace memory descriptor required between forward and backward passes (empty if none).  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[scratchpad_desc](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-scratchpad-desc)**() const<br>Queries temporary scratchpad memory descriptor.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Binary](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-binary)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src0, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src1)<br>Creates a binary elementwise/broadcasting primitive descriptor (`dst = op(src0, src1)`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Binary](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-binary)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src0, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src1) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[ElementwiseForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwiseforward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, float alpha =0.0f, float beta =0.0f, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward))<br>Creates a forward elementwise primitive descriptor with optional `alpha` and `beta` parameters.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[ElementwiseForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwiseforward)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, float alpha =0.0f, float beta =0.0f, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward)) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Elementwise](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwise)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward))<br>Creates a forward elementwise primitive descriptor (default parameters `alpha = 0`, `beta = 0`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Elementwise](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwise)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, float alpha, float beta =0.0f, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward))<br>Creates a parameterized forward elementwise primitive descriptor.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[ElementwiseBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwisebackward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & data, const [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & hint_fwd_pd, float alpha =0.0f, float beta =0.0f)<br>Creates a backward elementwise primitive descriptor using an explicit forward descriptor hint.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[ElementwiseBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwisebackward)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & data, const [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & hint_fwd_pd, float alpha =0.0f, float beta =0.0f) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[ElementwiseBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwisebackward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & data, float alpha =0.0f, float beta =0.0f)<br>Creates a backward elementwise primitive descriptor (automatically synthesizing the forward hint).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Matmul](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-matmul)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & weights)<br>Creates a 2D or batched N-D matrix multiplication descriptor (`dst = src * weights`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Matmul](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-matmul)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & weights) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Matmul](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-matmul)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & weights, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & bias)<br>Creates a 2D or batched N-D matrix multiplication descriptor with additive bias (`dst = src * weights + bias`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Matmul](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-matmul)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & weights, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & bias) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[SoftmaxForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxforward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, int axis =-1, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward))<br>Creates a forward softmax or log-softmax primitive descriptor along `axis` (supports negative indexing, e.g. `-1`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[SoftmaxForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxforward)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, int axis =-1, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward)) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Softmax](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmax)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, int axis =-1, [Purpose](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-purpose) prop_kind =[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward))<br>Alias for [SoftmaxForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxforward).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[SoftmaxBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxbackward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, int axis, const [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & hint_fwd_pd)<br>Creates a backward softmax/log-softmax descriptor using an explicit forward descriptor hint.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[SoftmaxBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxbackward)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, int axis, const [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) & hint_fwd_pd) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[SoftmaxBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxbackward)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_src, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & diff_dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, int axis =-1)<br>Creates a backward softmax/log-softmax descriptor (automatically synthesizing the forward hint).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Reduction](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reduction)**([Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, float p =0.0f, float eps =0.0f)<br>Creates a tensor reduction descriptor (`dst` must have the same rank as `src` with reduced axes set to `1`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Reduction](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reduction)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, [Algo](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enum-algo) alg, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src, float p =0.0f, float eps =0.0f) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Reorder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reorder)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src)<br>Creates a layout and/or datatype conversion (`[Reorder]()`) primitive descriptor on the active engine.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Reorder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reorder)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & dst_engine, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & src_engine, const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & src)<br>Creates a cross-engine or explicit-engine `[Reorder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reorder)` primitive descriptor.  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Sum](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-sum)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, std::span< const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, std::span< const float > scales ={})<br>Creates a scaled multi-tensor summation descriptor (`dst = sum_i(scales[i] * srcs[i])`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Sum](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-sum)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, std::initializer_list< [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, std::initializer_list< float > scales ={}) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Concat](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-concat)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, std::span< const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, int axis =0)<br>Creates an out-of-place tensor concatenation descriptor along `axis` (supports negative indexing).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Concat](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-concat)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) & dst, std::initializer_list< [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, int axis =0) |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Concat](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-concat)**(std::span< const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, int axis =0)<br>Creates a concatenation descriptor with automatically deduced destination descriptor (`pd.dst_desc()`).  |
| [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor) | **[Concat](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-concat)**(std::initializer_list< [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) > srcs, int axis =0) |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-primitivedescriptor)**(std::unique_ptr< [Impl](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/) > impl) |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [Impl](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/) > | **[_impl](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#variable--impl)**  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#friend-primitive)**  |
| struct | **[PrimitiveDescriptorBuilder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#friend-primitivedescriptorbuilder)**  |

## Detailed Description

```cpp
class cum::neural_primitives::PrimitiveDescriptor;
```

Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters. 

Constructed via static factory methods (`[Binary](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-binary)`, `[Elementwise](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwise)`, `[ElementwiseBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-elementwisebackward)`, `[Matmul](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-matmul)`, `[Softmax](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmax)`, `[SoftmaxBackward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxbackward)`, `[Reduction](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reduction)`, `[Reorder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reorder)`, `[Sum](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-sum)`, `[Concat](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-concat)`) and compiled into an executable [Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/). 

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



[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/) operation category. 

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

Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-valid). 

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

Returns algorithm tag (`[Algo::undef](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-undef)` for operations without sub-algorithms like `[Matmul]()` or `[Reorder]()`). 

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
  * **prop_kind** Forward propagation mode (`[Purpose::forward](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward)` or `[Purpose::forward_inference](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/#enumvalue-forward-inference)`). 


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

Alias for [SoftmaxForward](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-softmaxforward). 

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

Creates a cross-engine or explicit-engine `[Reorder](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#function-reorder)` primitive descriptor. 

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

  * **dst** Destination memory descriptor (may use `[layout::ANY](/CUM/api/Namespaces/namespacecum/#enumvalue-any)`). 
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

Updated on 2026-10-31 at 18:51:12 +0100