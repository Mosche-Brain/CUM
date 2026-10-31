---
title: cum::neural_primitives::Tensor
summary: Core N-dimensional array and deep learning tensor. 

---

# cum::neural_primitives::Tensor



Core N-dimensional array and deep learning tensor.  [More...](#detailed-description)


`#include <Tensor.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any)) =default<br>Constructs an uninitialized [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) with the given shape, datatype, and layout.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**() =default<br>Default constructor creating an empty tensor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([neural_primitives::MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) & descriptor)<br>Constructs a [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) backed by an existing neural primitive descriptor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**(cumeric_t value, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::A](Namespaces/namespacecum.md#enumvalue-a)) =default<br>Constructs a 0D scalar tensor holding a single scalar value.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([dim_t](Namespaces/namespacecum.md#using-dim-t) lenght, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::A](Namespaces/namespacecum.md#enumvalue-a)) =default<br>Constructs a 1D vector tensor of the given length.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::AB](Namespaces/namespacecum.md#enumvalue-ab)) =default<br>Constructs a 2D matrix tensor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([dim_t](Namespaces/namespacecum.md#using-dim-t) axis0, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis1, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis2, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ABC](Namespaces/namespacecum.md#enumvalue-abc)) =default<br>Constructs a 3D rank-3 tensor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([dim_t](Namespaces/namespacecum.md#using-dim-t) axis0, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis1, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis2, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis3, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ABCD](Namespaces/namespacecum.md#enumvalue-abcd)) =default<br>Constructs a 4D rank-4 tensor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**([dim_t](Namespaces/namespacecum.md#using-dim-t) axis0, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis1, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis2, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis3, [dim_t](Namespaces/namespacecum.md#using-dim-t) axis4, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ABCDE](Namespaces/namespacecum.md#enumvalue-abcde)) =default<br>Constructs a 5D rank-5 tensor.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**(const Tensor & tensor)<br>Copy constructor performing deep copy of tensor descriptor and memory buffer.  |
| | **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**(Tensor && tensor)<br>Move constructor transferring resource ownership without copying memory.  |
| template <typename T ,dim_t... dims\> <br>| **[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor)**(const std::vector< T > & values)<br>Template constructor initializing a multi-dimensional tensor from a flat vector of values.  |
| | **[~Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-~tensor)**()<br>Destructor releasing tensor memory.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[cast](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-cast)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype)<br>Converts tensor elements to another datatype in-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[prefetch](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-prefetch)**()<br>Prefetches tensor memory to the active device.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[to_host](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-to-host)**()<br>Migrates tensor memory to host CPU.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[to_device](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-to-device)**()<br>Migrates tensor memory to device accelerator.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[size](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-size)**() const<br>Returns total memory size in bytes.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[rank](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-rank)**() const<br>Returns tensor rank (number of dimensions).  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[dims](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-dims)**() const<br>Returns tensor rank (number of dimensions).  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[lenght](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-lenght)**() const<br>Returns length of first dimension.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[elements](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-elements)**() const<br>Returns total number of elements.  |
| [Shape](Namespaces/namespacecum.md#using-shape) | **[shape](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-shape)**() const<br>Returns vector of dimension lengths.  |
| [layout](Namespaces/namespacecum.md#enum-layout) | **[format](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-format)**() const<br>Returns memory layout format.  |
| [datatype](Namespaces/namespacecum.md#enum-datatype) | **[type](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-type)**() const<br>Returns element datatype.  |
| bool | **[is_scalar](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-is-scalar)**() const<br>Checks whether tensor is a 0D scalar or 1-element tensor.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[rows](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-rows)**() const<br>Returns height (row count) for 2D+ tensors.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[cols](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-cols)**() const<br>Returns width (column count) for 2D+ tensors.  |
| std::unique_ptr< [neural_primitives::MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > & | **[descriptor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-descriptor)**()<br>Returns mutable reference to descriptor pointer.  |
| const std::unique_ptr< [neural_primitives::MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) > & | **[descriptor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-descriptor)**() const<br>Returns const reference to descriptor pointer.  |
| std::unique_ptr< [neural_primitives::Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) > & | **[memory](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-memory)**()<br>Returns mutable reference to memory object pointer.  |
| const std::unique_ptr< [neural_primitives::Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) > & | **[memory](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-memory)**() const<br>Returns const reference to memory object pointer.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[clone](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-clone)**() const<br>Creates a deep copy clone of the tensor.  |
| template <typename T \> <br>T * | **[data](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-data)**()<br>Returns typed pointer to underlying memory buffer.  |
| template <typename T \> <br>const T * | **[data](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-data)**() const<br>Returns typed const pointer to underlying memory buffer.  |
| const void * | **[data](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-data)**() const<br>Returns raw untyped const data pointer.  |
| void * | **[data](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-data)**()<br>Returns raw untyped data pointer.  |
| template <typename T \> <br>T & | **[at](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-at)**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices)<br>Accesses element at specified multi-dimensional coordinate with type check.  |
| template <typename T \> <br>const T & | **[at](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-at)**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices) const<br>Accesses element at specified multi-dimensional coordinate with type check (const).  |
| cumeric_t & | **[at](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-at)**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices)<br>Accesses element as cumeric_t at specified multi-dimensional coordinate.  |
| const cumeric_t & | **[at](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-at)**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices) const<br>Accesses element as cumeric_t at specified multi-dimensional coordinate (const).  |
| cumeric_t | **[get_value](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-get-value)**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices) const<br>Reads scalar value at specified coordinate.  |
| cumeric_t & | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices) |
| const cumeric_t & | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**(const [Shape](Namespaces/namespacecum.md#using-shape) & indices) const |
| cumeric_t | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**([dim_t](Namespaces/namespacecum.md#using-dim-t) row, [dim_t](Namespaces/namespacecum.md#using-dim-t) col) const |
| cumeric_t | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**([dim_t](Namespaces/namespacecum.md#using-dim-t) idx0, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx1, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx2) const |
| cumeric_t | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**([dim_t](Namespaces/namespacecum.md#using-dim-t) idx0, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx1, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx2, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx3) const |
| cumeric_t | **[operator()](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator())**([dim_t](Namespaces/namespacecum.md#using-dim-t) idx0, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx1, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx2, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx3, [dim_t](Namespaces/namespacecum.md#using-dim-t) idx4) const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[batch](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-batch)**([dim_t](Namespaces/namespacecum.md#using-dim-t) index) const<br>Extracts a batch slice along axis 0.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[channel](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-channel)**([dim_t](Namespaces/namespacecum.md#using-dim-t) index) const<br>Extracts a channel slice along axis 1.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[row](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-row)**([dim_t](Namespaces/namespacecum.md#using-dim-t) index) const<br>Extracts a row slice.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[col](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-col)**([dim_t](Namespaces/namespacecum.md#using-dim-t) index) const<br>Extracts a column slice.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[slice](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-slice)**(const [Shape](Namespaces/namespacecum.md#using-shape) & offset, const [Shape](Namespaces/namespacecum.md#using-shape) & shape) const<br>Extracts a sub-tensor slice specified by offset and shape.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[reshape](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-reshape)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape) const<br>Returns a reshaped tensor out-of-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[reshape_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-reshape-in-place)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape)<br>Reshapes tensor in-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[transpose](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-transpose)**() const<br>Transposes tensor dimensions out-of-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[transpose_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-transpose-in-place)**()<br>Transposes tensor dimensions in-place.  |
| cumeric_t | **[sum](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-sum)**() const<br>Computes sum of all elements.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[sum](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-sum)**([dim_t](Namespaces/namespacecum.md#using-dim-t) axis, bool keed_dims =true) const<br>Computes reduction sum along a specified axis.  |
| cumeric_t | **[mean](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-mean)**() const<br>Computes arithmetic mean of all elements.  |
| cumeric_t | **[amean](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-amean)**() const<br>Computes mean of absolute values.  |
| cumeric_t | **[norm](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-norm)**() const<br>Computes Euclidean L2 norm.  |
| cumeric_t | **[squaredNorm](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-squarednorm)**() const<br>Computes squared Euclidean L2 norm.  |
| cumeric_t | **[squared_norm](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-squared-norm)**() const<br>Computes squared Euclidean L2 norm (snake_case alias).  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[softmax](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-softmax)**([dim_t](Namespaces/namespacecum.md#using-dim-t) axis =-1) const<br>Computes softmax activation along a specified axis.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[colwise_sum](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-colwise-sum)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[rowwise_sum](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-rowwise-sum)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[channelwise_sum](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-channelwise-sum)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[elementwise](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-elementwise)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) function) const<br>Applies elementwise neural activation function out-of-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[elementwise_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-elementwise-in-place)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) function)<br>Applies elementwise neural activation function in-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[elementwise_diff](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-elementwise-diff)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) function) const<br>Computes elementwise activation derivative out-of-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[elementwise_diff_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-elementwise-diff-in-place)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) function)<br>Computes elementwise activation derivative in-place.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[fill](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-fill)**(cumeric_t scalar)<br>Fills all tensor elements with a scalar value.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[multiply](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-multiply)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor) const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[cwiseProduct](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-cwiseproduct)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor) const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[cwise_product_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-cwise-product-in-place)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[sqrt](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-sqrt)**() const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[sqrt_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-sqrt-in-place)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[square](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-square)**() const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[square_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-square-in-place)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[abs](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-abs)**() const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[abs_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-abs-in-place)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[clamp](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-clamp)**(cumeric_t min, cumeric_t max) const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[clamp_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-clamp-in-place)**(cumeric_t min, cumeric_t max) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[log](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-log)**() const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[log_in_place](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-log-in-place)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[scale](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-scale)**(cumeric_t scalar) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[matmul](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-matmul)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) const<br>Performs matrix or batched tensor multiplication with another tensor.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator+](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator+)**() |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator-](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator-)**() const |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator+=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator+=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator-=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator-=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator*=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator*=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator/=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator/=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator/=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator/=)**(cumeric_t scalar) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & other) |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-operator=)**([Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) && other) |
| template <datatype T,layout layout\> <br>[Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[create_tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-create-tensor)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape)<br>Factory creating a tensor with compile-time specified datatype and layout tags.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[take_memory](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-take-memory)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, void * data, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =[datatype::FP32](Namespaces/namespacecum.md#enumvalue-fp32), [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Wraps existing non-owned memory buffer without allocating new storage.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[copy_memory](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-copy-memory)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, void * data, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =[datatype::FP32](Namespaces/namespacecum.md#enumvalue-fp32), [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Creates a tensor by allocating storage and copying data from an external buffer.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[make_cube](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-make-cube)**([dim_t](Namespaces/namespacecum.md#using-dim-t) width, [dim_t](Namespaces/namespacecum.md#using-dim-t) height, [dim_t](Namespaces/namespacecum.md#using-dim-t) deepth, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::OI](Namespaces/namespacecum.md#enumvalue-oi)) =default<br>Creates a 3D cube tensor.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[make_matrix](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-make-matrix)**([dim_t](Namespaces/namespacecum.md#using-dim-t) rows, [dim_t](Namespaces/namespacecum.md#using-dim-t) cols, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::OI](Namespaces/namespacecum.md#enumvalue-oi)) =default<br>Creates a 2D matrix tensor.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[make_vector](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-make-vector)**([dim_t](Namespaces/namespacecum.md#using-dim-t) lenght, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::X](Namespaces/namespacecum.md#enumvalue-x)) =default<br>Creates a 1D vector tensor.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[make_scalar](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-make-scalar)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype =default_type, [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::X](Namespaces/namespacecum.md#enumvalue-x)) =default<br>Creates a 0D scalar tensor.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[Random](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-random)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, cumeric_t min =-1_c, cumeric_t max =1_c, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =[datatype::FP32](Namespaces/namespacecum.md#enumvalue-fp32), [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Creates a tensor filled with uniformly distributed random numbers.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[Zeros](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-zeros)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =[datatype::FP32](Namespaces/namespacecum.md#enumvalue-fp32), [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Creates a tensor filled with zeros.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[Ones](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-ones)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype =[datatype::FP32](Namespaces/namespacecum.md#enumvalue-fp32), [layout](Namespaces/namespacecum.md#enum-layout) layout =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Creates a tensor filled with ones.  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[Linspace](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-linspace)**(cumeric_t start, cumeric_t end, [dim_t](Namespaces/namespacecum.md#using-dim-t) num)<br>Creates a 1D vector tensor with linearly spaced values.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator+](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator+)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator+](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator+)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor, cumeric_t scalar)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator+](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator+)**(cumeric_t scalar, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator-](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator-)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator-](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator-)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor, cumeric_t scalar)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator-](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator-)**(cumeric_t scalar, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator*](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator*)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator*](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator*)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor, cumeric_t scalar)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator*](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator*)**(cumeric_t scalar, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator/](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator/)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator/](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator/)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor, cumeric_t scalar)  |
| [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) | **[operator/](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator/)**(cumeric_t scalar, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & tensor)  |
| bool | **[operator==](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator==)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |
| bool | **[operator!=](Classes/classcum_1_1neural__primitives_1_1Tensor.md#friend-operator!=)**(const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & A, const [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md#function-tensor) & B)  |

## Detailed Description

```cpp
class cum::neural_primitives::Tensor;
```

Core N-dimensional array and deep learning tensor. 

Encapsulates shape, memory layout, element datatype, unified memory allocation, and integration with neural primitive kernels (oneDNN / BLAS). 

## Public Functions Documentation

### function Tensor

```cpp
Tensor(
    const Shape & shape,
    datatype dtype =default_type,
    layout layout =layout::ANY
) =default
```

Constructs an uninitialized [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) with the given shape, datatype, and layout. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions vector. 
  * **dtype** Element datatype tag (default is default_type). 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag (default is [layout::ANY](Namespaces/namespacecum.md#enumvalue-any)). 


### function Tensor

```cpp
Tensor() =default
```

Default constructor creating an empty tensor. 

### function Tensor

```cpp
Tensor(
    neural_primitives::MemoryDescriptor & descriptor
)
```

Constructs a [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) backed by an existing neural primitive descriptor. 

**Parameters**: 

  * **descriptor** Neural primitive memory descriptor. 


### function Tensor

```cpp
Tensor(
    cumeric_t value,
    datatype dtype =default_type,
    layout layout =layout::A
) =default
```

Constructs a 0D scalar tensor holding a single scalar value. 

**Parameters**: 

  * **value** Scalar initial value. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    dim_t lenght,
    datatype dtype =default_type,
    layout layout =layout::A
) =default
```

Constructs a 1D vector tensor of the given length. 

**Parameters**: 

  * **lenght** Number of elements. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    dim_t rows,
    dim_t cols,
    datatype dtype =default_type,
    layout layout =layout::AB
) =default
```

Constructs a 2D matrix tensor. 

**Parameters**: 

  * **rows** Number of rows. 
  * **cols** Number of columns. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    dim_t axis0,
    dim_t axis1,
    dim_t axis2,
    datatype dtype =default_type,
    layout layout =layout::ABC
) =default
```

Constructs a 3D rank-3 tensor. 

**Parameters**: 

  * **axis0** Extent along axis 0. 
  * **axis1** Extent along axis 1. 
  * **axis2** Extent along axis 2. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    dim_t axis0,
    dim_t axis1,
    dim_t axis2,
    dim_t axis3,
    datatype dtype =default_type,
    layout layout =layout::ABCD
) =default
```

Constructs a 4D rank-4 tensor. 

**Parameters**: 

  * **axis0** Extent along axis 0. 
  * **axis1** Extent along axis 1. 
  * **axis2** Extent along axis 2. 
  * **axis3** Extent along axis 3. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    dim_t axis0,
    dim_t axis1,
    dim_t axis2,
    dim_t axis3,
    dim_t axis4,
    datatype dtype =default_type,
    layout layout =layout::ABCDE
) =default
```

Constructs a 5D rank-5 tensor. 

**Parameters**: 

  * **axis0** Extent along axis 0. 
  * **axis1** Extent along axis 1. 
  * **axis2** Extent along axis 2. 
  * **axis3** Extent along axis 3. 
  * **axis4** Extent along axis 4. 
  * **dtype** Element datatype. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout. 


### function Tensor

```cpp
Tensor(
    const Tensor & tensor
)
```

Copy constructor performing deep copy of tensor descriptor and memory buffer. 

**Parameters**: 

  * **tensor** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) to copy from. 


### function Tensor

```cpp
Tensor(
    Tensor && tensor
)
```

Move constructor transferring resource ownership without copying memory. 

**Parameters**: 

  * **tensor** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) to move from. 


### function Tensor

```cpp
template <typename T ,
dim_t... dims>
Tensor(
    const std::vector< T > & values
)
```

Template constructor initializing a multi-dimensional tensor from a flat vector of values. 

**Parameters**: 

  * **values** Initial element values. 


**Template Parameters**: 

  * **T** Element type. 
  * **dims** Variadic dimension list defining tensor shape. 


### function ~Tensor

```cpp
~Tensor()
```

Destructor releasing tensor memory. 

### function cast

```cpp
Tensor & cast(
    datatype dtype
)
```

Converts tensor elements to another datatype in-place. 

**Parameters**: 

  * **dtype** Target datatype. 


**Return**: Reference to `*this`. 

### function prefetch

```cpp
Tensor & prefetch()
```

Prefetches tensor memory to the active device. 

**Return**: Reference to `*this`. 

### function to_host

```cpp
Tensor & to_host()
```

Migrates tensor memory to host CPU. 

**Return**: Reference to `*this`. 

### function to_device

```cpp
Tensor & to_device()
```

Migrates tensor memory to device accelerator. 

**Return**: Reference to `*this`. 

### function size

```cpp
dim_t size() const
```

Returns total memory size in bytes. 

**Return**: Size in bytes. 

### function rank

```cpp
dim_t rank() const
```

Returns tensor rank (number of dimensions). 

**Return**: Number of axes. 

### function dims

```cpp
dim_t dims() const
```

Returns tensor rank (number of dimensions). 

**Return**: Number of axes. 

### function lenght

```cpp
dim_t lenght() const
```

Returns length of first dimension. 

**Return**: Length. 

### function elements

```cpp
dim_t elements() const
```

Returns total number of elements. 

**Return**: Element count. 

### function shape

```cpp
Shape shape() const
```

Returns vector of dimension lengths. 

**Return**: [Shape](Namespaces/namespacecum.md#using-shape) vector. 

### function format

```cpp
layout format() const
```

Returns memory layout format. 

**Return**: Layout tag. 

### function type

```cpp
datatype type() const
```

Returns element datatype. 

**Return**: Datatype tag. 

### function is_scalar

```cpp
bool is_scalar() const
```

Checks whether tensor is a 0D scalar or 1-element tensor. 

**Return**: True if scalar, false otherwise. 

### function rows

```cpp
dim_t rows() const
```

Returns height (row count) for 2D+ tensors. 

**Return**: Rows. 

### function cols

```cpp
dim_t cols() const
```

Returns width (column count) for 2D+ tensors. 

**Return**: Columns. 

### function descriptor

```cpp
std::unique_ptr< neural_primitives::MemoryDescriptor > & descriptor()
```

Returns mutable reference to descriptor pointer. 

**Return**: Unique pointer reference to neural_primitives::Descriptor. 

### function descriptor

```cpp
const std::unique_ptr< neural_primitives::MemoryDescriptor > & descriptor() const
```

Returns const reference to descriptor pointer. 

**Return**: Const unique pointer reference to neural_primitives::Descriptor. 

### function memory

```cpp
std::unique_ptr< neural_primitives::Memory > & memory()
```

Returns mutable reference to memory object pointer. 

**Return**: Unique pointer reference to [neural_primitives::Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md). 

### function memory

```cpp
const std::unique_ptr< neural_primitives::Memory > & memory() const
```

Returns const reference to memory object pointer. 

**Return**: Const unique pointer reference to [neural_primitives::Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md). 

### function clone

```cpp
Tensor clone() const
```

Creates a deep copy clone of the tensor. 

**Return**: Cloned [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function data

```cpp
template <typename T >
inline T * data()
```

Returns typed pointer to underlying memory buffer. 

**Template Parameters**: 

  * **T** Target pointer type. 


**Return**: Typed pointer. 

### function data

```cpp
template <typename T >
inline const T * data() const
```

Returns typed const pointer to underlying memory buffer. 

**Template Parameters**: 

  * **T** Target pointer type. 


**Return**: Typed const pointer. 

### function data

```cpp
const void * data() const
```

Returns raw untyped const data pointer. 

**Return**: Const void pointer. 

### function data

```cpp
void * data()
```

Returns raw untyped data pointer. 

**Return**: Void pointer. 

### function at

```cpp
template <typename T >
T & at(
    const Shape & indices
)
```

Accesses element at specified multi-dimensional coordinate with type check. 

**Parameters**: 

  * **indices** Coordinate indices. 


**Template Parameters**: 

  * **T** Element type. 


**Return**: Reference to element of type `T`. 

### function at

```cpp
template <typename T >
const T & at(
    const Shape & indices
) const
```

Accesses element at specified multi-dimensional coordinate with type check (const). 

**Parameters**: 

  * **indices** Coordinate indices. 


**Template Parameters**: 

  * **T** Element type. 


**Return**: Const reference to element of type `T`. 

### function at

```cpp
cumeric_t & at(
    const Shape & indices
)
```

Accesses element as cumeric_t at specified multi-dimensional coordinate. 

**Parameters**: 

  * **indices** Coordinate indices. 


**Return**: Reference to cumeric_t element. 

### function at

```cpp
const cumeric_t & at(
    const Shape & indices
) const
```

Accesses element as cumeric_t at specified multi-dimensional coordinate (const). 

**Parameters**: 

  * **indices** Coordinate indices. 


**Return**: Const reference to cumeric_t element. 

### function get_value

```cpp
cumeric_t get_value(
    const Shape & indices
) const
```

Reads scalar value at specified coordinate. 

**Parameters**: 

  * **indices** Coordinate indices. 


**Return**: Scalar value. 

### function operator()

```cpp
cumeric_t & operator()(
    const Shape & indices
)
```


### function operator()

```cpp
const cumeric_t & operator()(
    const Shape & indices
) const
```


### function operator()

```cpp
cumeric_t operator()(
    dim_t row,
    dim_t col
) const
```


### function operator()

```cpp
cumeric_t operator()(
    dim_t idx0,
    dim_t idx1,
    dim_t idx2
) const
```


### function operator()

```cpp
cumeric_t operator()(
    dim_t idx0,
    dim_t idx1,
    dim_t idx2,
    dim_t idx3
) const
```


### function operator()

```cpp
cumeric_t operator()(
    dim_t idx0,
    dim_t idx1,
    dim_t idx2,
    dim_t idx3,
    dim_t idx4
) const
```


### function batch

```cpp
Tensor batch(
    dim_t index
) const
```

Extracts a batch slice along axis 0. 

**Parameters**: 

  * **index** Batch index. 


**Return**: Sub-tensor. 

### function channel

```cpp
Tensor channel(
    dim_t index
) const
```

Extracts a channel slice along axis 1. 

**Parameters**: 

  * **index** Channel index. 


**Return**: Sub-tensor. 

### function row

```cpp
Tensor row(
    dim_t index
) const
```

Extracts a row slice. 

**Parameters**: 

  * **index** Row index. 


**Return**: Sub-tensor. 

### function col

```cpp
Tensor col(
    dim_t index
) const
```

Extracts a column slice. 

**Parameters**: 

  * **index** Column index. 


**Return**: Sub-tensor. 

### function slice

```cpp
Tensor slice(
    const Shape & offset,
    const Shape & shape
) const
```

Extracts a sub-tensor slice specified by offset and shape. 

**Parameters**: 

  * **offset** Starting coordinate offset. 
  * **shape** Slice dimensions. 


**Return**: Sub-tensor slice. 

### function reshape

```cpp
Tensor reshape(
    const Shape & shape
) const
```

Returns a reshaped tensor out-of-place. 

**Parameters**: 

  * **shape** New shape. 


**Return**: Reshaped [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function reshape_in_place

```cpp
Tensor & reshape_in_place(
    const Shape & shape
)
```

Reshapes tensor in-place. 

**Parameters**: 

  * **shape** New shape. 


**Return**: Reference to `*this`. 

### function transpose

```cpp
Tensor transpose() const
```

Transposes tensor dimensions out-of-place. 

**Return**: Transposed [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function transpose_in_place

```cpp
Tensor & transpose_in_place()
```

Transposes tensor dimensions in-place. 

**Return**: Reference to `*this`. 

### function sum

```cpp
cumeric_t sum() const
```

Computes sum of all elements. 

**Return**: Scalar sum. 

### function sum

```cpp
Tensor sum(
    dim_t axis,
    bool keed_dims =true
) const
```

Computes reduction sum along a specified axis. 

**Parameters**: 

  * **axis** Target dimension index. 
  * **keed_dims** Whether to retain reduced dimension with length 1. 


**Return**: Reduced [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function mean

```cpp
cumeric_t mean() const
```

Computes arithmetic mean of all elements. 

**Return**: Scalar mean. 

### function amean

```cpp
cumeric_t amean() const
```

Computes mean of absolute values. 

**Return**: Scalar mean. 

### function norm

```cpp
cumeric_t norm() const
```

Computes Euclidean L2 norm. 

**Return**: L2 norm. 

### function squaredNorm

```cpp
cumeric_t squaredNorm() const
```

Computes squared Euclidean L2 norm. 

**Return**: Squared L2 norm. 

### function squared_norm

```cpp
cumeric_t squared_norm() const
```

Computes squared Euclidean L2 norm (snake_case alias). 

**Return**: Squared L2 norm. 

### function softmax

```cpp
Tensor softmax(
    dim_t axis =-1
) const
```

Computes softmax activation along a specified axis. 

**Parameters**: 

  * **axis** Axis along which softmax is applied (-1 for last axis). 


**Return**: Softmax [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function colwise_sum

```cpp
Tensor colwise_sum()
```


### function rowwise_sum

```cpp
Tensor rowwise_sum()
```


### function channelwise_sum

```cpp
Tensor channelwise_sum()
```


### function elementwise

```cpp
Tensor elementwise(
    functions::function_id function
) const
```

Applies elementwise neural activation function out-of-place. 

**Parameters**: 

  * **function** Activation function identifier enum. 


**Return**: Activated [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function elementwise_in_place

```cpp
Tensor & elementwise_in_place(
    functions::function_id function
)
```

Applies elementwise neural activation function in-place. 

**Parameters**: 

  * **function** Activation function identifier enum. 


**Return**: Reference to `*this`. 

### function elementwise_diff

```cpp
Tensor elementwise_diff(
    functions::function_id function
) const
```

Computes elementwise activation derivative out-of-place. 

**Parameters**: 

  * **function** Activation function identifier enum. 


**Return**: Derivative [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function elementwise_diff_in_place

```cpp
Tensor & elementwise_diff_in_place(
    functions::function_id function
)
```

Computes elementwise activation derivative in-place. 

**Parameters**: 

  * **function** Activation function identifier enum. 


**Return**: Reference to `*this`. 

### function fill

```cpp
Tensor & fill(
    cumeric_t scalar
)
```

Fills all tensor elements with a scalar value. 

**Parameters**: 

  * **scalar** Fill value. 


**Return**: Reference to `*this`. 

### function multiply

```cpp
Tensor multiply(
    const Tensor & tensor
) const
```


### function cwiseProduct

```cpp
Tensor cwiseProduct(
    const Tensor & tensor
) const
```


### function cwise_product_in_place

```cpp
Tensor & cwise_product_in_place(
    const Tensor & other
)
```


### function sqrt

```cpp
Tensor sqrt() const
```


### function sqrt_in_place

```cpp
Tensor & sqrt_in_place()
```


### function square

```cpp
Tensor square() const
```


### function square_in_place

```cpp
Tensor & square_in_place()
```


### function abs

```cpp
Tensor abs() const
```


### function abs_in_place

```cpp
Tensor & abs_in_place()
```


### function clamp

```cpp
Tensor clamp(
    cumeric_t min,
    cumeric_t max
) const
```


### function clamp_in_place

```cpp
Tensor & clamp_in_place(
    cumeric_t min,
    cumeric_t max
)
```


### function log

```cpp
Tensor log() const
```


### function log_in_place

```cpp
Tensor & log_in_place()
```


### function scale

```cpp
Tensor & scale(
    cumeric_t scalar
)
```


### function matmul

```cpp
Tensor matmul(
    const Tensor & other
) const
```

Performs matrix or batched tensor multiplication with another tensor. 

**Parameters**: 

  * **other** Right-hand side tensor operand. 


**Return**: [Matrix](Classes/classcum_1_1Matrix.md) multiplication result [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function operator+

```cpp
Tensor operator+()
```


### function operator-

```cpp
Tensor operator-() const
```


### function operator+=

```cpp
Tensor & operator+=(
    const Tensor & other
)
```


### function operator-=

```cpp
Tensor & operator-=(
    const Tensor & other
)
```


### function operator*=

```cpp
Tensor & operator*=(
    const Tensor & other
)
```


### function operator/=

```cpp
Tensor & operator/=(
    const Tensor & other
)
```


### function operator/=

```cpp
Tensor & operator/=(
    cumeric_t scalar
)
```


### function operator=

```cpp
Tensor & operator=(
    const Tensor & other
)
```


### function operator=

```cpp
Tensor & operator=(
    Tensor && other
)
```


### function create_tensor

```cpp
template <datatype T,
layout layout>
static Tensor create_tensor(
    const Shape & shape
)
```

Factory creating a tensor with compile-time specified datatype and layout tags. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 


**Template Parameters**: 

  * **T** Runtime datatype enum value. 
  * **[layout](Namespaces/namespacecum.md#enum-layout)** Layout tag enum value. 


**Return**: Newly created [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function take_memory

```cpp
static Tensor take_memory(
    const Shape & shape,
    void * data,
    datatype dtype =datatype::FP32,
    layout layout =layout::ANY
)
```

Wraps existing non-owned memory buffer without allocating new storage. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 
  * **data** Pointer to external memory. 
  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) viewing external memory. 

### function copy_memory

```cpp
static Tensor copy_memory(
    const Shape & shape,
    void * data,
    datatype dtype =datatype::FP32,
    layout layout =layout::ANY
)
```

Creates a tensor by allocating storage and copying data from an external buffer. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 
  * **data** Pointer to external source memory. 
  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: Newly allocated [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) with copied contents. 

### function make_cube

```cpp
static Tensor make_cube(
    dim_t width,
    dim_t height,
    dim_t deepth,
    datatype dtype =default_type,
    layout layout =layout::OI
) =default
```

Creates a 3D cube tensor. 

**Parameters**: 

  * **width** Dimension along width. 
  * **height** Dimension along height. 
  * **deepth** Dimension along depth. 
  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: 3D [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function make_matrix

```cpp
static Tensor make_matrix(
    dim_t rows,
    dim_t cols,
    datatype dtype =default_type,
    layout layout =layout::OI
) =default
```

Creates a 2D matrix tensor. 

**Parameters**: 

  * **rows** Row count. 
  * **cols** Column count. 
  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: 2D [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function make_vector

```cpp
static Tensor make_vector(
    dim_t lenght,
    datatype dtype =default_type,
    layout layout =layout::X
) =default
```

Creates a 1D vector tensor. 

**Parameters**: 

  * **lenght** Length of vector. 
  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: 1D [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function make_scalar

```cpp
static Tensor make_scalar(
    datatype dtype =default_type,
    layout layout =layout::X
) =default
```

Creates a 0D scalar tensor. 

**Parameters**: 

  * **dtype** Datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: 0D scalar [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function Random

```cpp
static Tensor Random(
    const Shape & shape,
    cumeric_t min =-1_c,
    cumeric_t max =1_c,
    datatype dtype =datatype::FP32,
    layout layout =layout::ANY
)
```

Creates a tensor filled with uniformly distributed random numbers. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 
  * **min** Minimum random bound (default -1.0). 
  * **max** Maximum random bound (default 1.0). 
  * **dtype** Element datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: Randomly initialized [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function Zeros

```cpp
static Tensor Zeros(
    const Shape & shape,
    datatype dtype =datatype::FP32,
    layout layout =layout::ANY
)
```

Creates a tensor filled with zeros. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 
  * **dtype** Element datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: Zero-filled [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function Ones

```cpp
static Tensor Ones(
    const Shape & shape,
    datatype dtype =datatype::FP32,
    layout layout =layout::ANY
)
```

Creates a tensor filled with ones. 

**Parameters**: 

  * **shape** [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md) dimensions. 
  * **dtype** Element datatype tag. 
  * **layout** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag. 


**Return**: Ones-filled [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

### function Linspace

```cpp
static Tensor Linspace(
    cumeric_t start,
    cumeric_t end,
    dim_t num
)
```

Creates a 1D vector tensor with linearly spaced values. 

**Parameters**: 

  * **start** Initial value. 
  * **end** Final value. 
  * **num** Number of values. 


**Return**: 1D vector [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md). 

## Friends

### friend operator+

```cpp
friend Tensor operator+(
    const Tensor & A,

    const Tensor & B
);
```


### friend operator+

```cpp
friend Tensor operator+(
    const Tensor & tensor,

    cumeric_t scalar
);
```


### friend operator+

```cpp
friend Tensor operator+(
    cumeric_t scalar,

    const Tensor & tensor
);
```


### friend operator-

```cpp
friend Tensor operator-(
    const Tensor & A,

    const Tensor & B
);
```


### friend operator-

```cpp
friend Tensor operator-(
    const Tensor & tensor,

    cumeric_t scalar
);
```


### friend operator-

```cpp
friend Tensor operator-(
    cumeric_t scalar,

    const Tensor & tensor
);
```


### friend operator*

```cpp
friend Tensor operator*(
    const Tensor & A,

    const Tensor & B
);
```


### friend operator*

```cpp
friend Tensor operator*(
    const Tensor & tensor,

    cumeric_t scalar
);
```


### friend operator*

```cpp
friend Tensor operator*(
    cumeric_t scalar,

    const Tensor & tensor
);
```


### friend operator/

```cpp
friend Tensor operator/(
    const Tensor & A,

    const Tensor & B
);
```


### friend operator/

```cpp
friend Tensor operator/(
    const Tensor & tensor,

    cumeric_t scalar
);
```


### friend operator/

```cpp
friend Tensor operator/(
    cumeric_t scalar,

    const Tensor & tensor
);
```


### friend operator==

```cpp
friend bool operator==(
    const Tensor & A,

    const Tensor & B
);
```


### friend operator!=

```cpp
friend bool operator!=(
    const Tensor & A,

    const Tensor & B
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100