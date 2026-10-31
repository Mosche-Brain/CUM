---
title: cum::neural_primitives::Primitive
summary: Executable compute primitive representing a compiled neural network or tensor operation. 

---

# cum::neural_primitives::Primitive



Executable compute primitive representing a compiled neural network or tensor operation.  [More...](#detailed-description)


`#include <Primitive.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/)** <br>Zero-copy argument binding pairing an [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) slot with a [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) or [Tensor]() reference.  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class int | **[Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument)** { undef = 0, src = 1, src0 = 1, src1 = 2, src2 = 3, src3 = 4, dst = 17, dst0 = 17, weights = 33, bias = 41, workspace = 64, scratchpad = 80, diff_src = 129, diff_src0 = 129, diff_src1 = 130, diff_dst = 145, diff_weights = 161, diff_bias = 169, multiple_src = 1024}<br>Named tensor slot identifiers for primitive execution.  |
| using [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/) | **[Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-descriptor)** <br>[Descriptor]() type alias.  |
| using [Descriptor::Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#enum-kind) | **[Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-kind)** <br>Operation category alias.  |
| using std::pair< [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument), [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) > | **[KV](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-kv)**  |
| using std::unordered_map< [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument), [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) > | **[KVMap](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-kvmap)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) | **[multiple_src_arg](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-multiple-src-arg)**(int index)<br>Computes the indexed variadic source slot (`[Argument::multiple_src](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enumvalue-multiple-src) + index`) for `Sum` / `Concat`.  |
| | **[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive)**()<br>Constructs an empty, uncompiled primitive.  |
| | **[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-descriptor) & descriptor)<br>Compiles an executable primitive from `descriptor`.  |
| | **[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive)**(const Primitive & other) |
| [Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-operator=)**(const [Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive) & other) |
| | **[Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive)**(Primitive && other) |
| [Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-operator=)**([Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-primitive) && other) |
| | **[~Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-~primitive)**() |
| void | **[compile](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-compile)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-descriptor) & descriptor)<br>Compiles (or recompiles) this primitive from `descriptor`.  |
| void | **[compile](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-compile)**()<br>Ensures the primitive is compiled from its stored descriptor.  |
| bool | **[valid](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-valid)**() const<br>Checks whether this primitive is compiled and ready to execute.  |
| | **[operator bool](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-valid).  |
| [Kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/#enum-kind) | **[kind](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-kind)**() const<br>Returns operation category of this primitive.  |
| const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-descriptor) & | **[descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-descriptor)**() const<br>Returns const reference to the [PrimitiveDescriptor]() from which this primitive was compiled.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**(std::span< const [ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/) > args, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes the primitive with explicit [ArgBinding]() pairs (accepts both [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) and [Tensor]()).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**(std::initializer_list< [ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/) > args, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes the primitive from a brace-initialized list of [ArgBinding]() pairs.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**(const [KVMap](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#using-kvmap) & kv_map, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes the primitive from a legacy `[Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) -> [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/)` map.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg0, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a unary primitive (`Elementwise`, `Softmax`, `Reduction`, `Reorder`).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg0, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg1, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a 2-input primitive (`Binary`, `Matmul` without bias, `ElementwiseBackward`, `SoftmaxBackward`, 2-input `Sum`/`Concat`).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg0, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg1, const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & arg2, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a 3-input primitive (`Matmul` with bias, 3-input `Sum`/`Concat`).  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) & dst, std::span< const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) > srcs, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a variadic-source primitive (`Sum`, `Concat`) over a span of [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) buffers.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & dst, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg0, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a unary primitive directly on [Tensor]() operands.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & dst, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg0, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg1, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a 2-input primitive directly on [Tensor]() operands.  |
| [__event__](/CUM/api/Namespaces/namespacecum/#using---event--) | **[execute](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-execute)**([Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & dst, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg0, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg1, const [Tensor](/CUM/api/Classes/classcum_1_1Tensor/) & arg2, const [__events__](/CUM/api/Namespaces/namespacecum/#using---events--) & deps ={}) const<br>Executes a 3-input primitive directly on [Tensor]() operands.  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< Impl > | **[impl](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#variable-impl)**  |

## Detailed Description

```cpp
class cum::neural_primitives::Primitive;
```

Executable compute primitive representing a compiled neural network or tensor operation. 

Wraps a backend-compiled primitive created from a [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/) and executes asynchronously on the active compute stream, returning an [__event__](/CUM/api/Namespaces/namespacecum/#using---event--). 

## Public Types Documentation

### enum Argument

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| undef | 0|   |
| src | 1| Primary input tensor (alias for `src0`).   |
| src0 | 1| Input tensor #0.   |
| src1 | 2| Input tensor #1.   |
| src2 | 3| Input tensor #2.   |
| src3 | 4| Input tensor #3.   |
| dst | 17| Primary output tensor (alias for `dst0`).   |
| dst0 | 17| Output tensor #0.   |
| weights | 33| Weights tensor (e.g. RHS matrix `B` in `Matmul`).   |
| bias | 41| Bias tensor.   |
| workspace | 64| Workspace tensor shared between forward and backward passes.   |
| scratchpad | 80| Scratchpad temporary buffer.   |
| diff_src | 129| Output gradient w.r.t. primary input (`dx`).   |
| diff_src0 | 129| Output gradient w.r.t. input #0.   |
| diff_src1 | 130| Output gradient w.r.t. input #1.   |
| diff_dst | 145| Upstream gradient w.r.t. output (`dy`).   |
| diff_weights | 161| Output gradient w.r.t. weights (`dW`).   |
| diff_bias | 169| Output gradient w.r.t. bias (`db`).   |
| multiple_src | 1024| Base slot for variadic sources (`Sum`, `Concat`): see [multiple_src_arg]().   |



Named tensor slot identifiers for primitive execution. 

### using Descriptor

```cpp
using cum::neural_primitives::Primitive::Descriptor = PrimitiveDescriptor;
```

[Descriptor]() type alias. 

### using Kind

```cpp
using cum::neural_primitives::Primitive::Kind = Descriptor::Kind;
```

Operation category alias. 

### using KV

```cpp
using cum::neural_primitives::Primitive::KV = std::pair<Argument, Memory>;
```


### using KVMap

```cpp
using cum::neural_primitives::Primitive::KVMap = std::unordered_map<Argument, Memory>;
```


## Public Functions Documentation

### function multiple_src_arg

```cpp
static inline Argument multiple_src_arg(
    int index
)
```

Computes the indexed variadic source slot (`[Argument::multiple_src](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enumvalue-multiple-src) + index`) for `Sum` / `Concat`. 

### function Primitive

```cpp
Primitive()
```

Constructs an empty, uncompiled primitive. 

### function Primitive

```cpp
explicit Primitive(
    const Descriptor & descriptor
)
```

Compiles an executable primitive from `descriptor`. 

### function Primitive

```cpp
Primitive(
    const Primitive & other
)
```


### function operator=

```cpp
Primitive & operator=(
    const Primitive & other
)
```


### function Primitive

```cpp
Primitive(
    Primitive && other
)
```


### function operator=

```cpp
Primitive & operator=(
    Primitive && other
)
```


### function ~Primitive

```cpp
~Primitive()
```


### function compile

```cpp
void compile(
    const Descriptor & descriptor
)
```

Compiles (or recompiles) this primitive from `descriptor`. 

### function compile

```cpp
void compile()
```

Ensures the primitive is compiled from its stored descriptor. 

### function valid

```cpp
bool valid() const
```

Checks whether this primitive is compiled and ready to execute. 

### function operator bool

```cpp
inline explicit operator bool() const
```

Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#function-valid). 

### function kind

```cpp
Kind kind() const
```

Returns operation category of this primitive. 

### function descriptor

```cpp
const Descriptor & descriptor() const
```

Returns const reference to the [PrimitiveDescriptor]() from which this primitive was compiled. 

### function execute

```cpp
__event__ execute(
    std::span< const ArgBinding > args,
    const __events__ & deps ={}
) const
```

Executes the primitive with explicit [ArgBinding]() pairs (accepts both [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) and [Tensor]()). 

### function execute

```cpp
__event__ execute(
    std::initializer_list< ArgBinding > args,
    const __events__ & deps ={}
) const
```

Executes the primitive from a brace-initialized list of [ArgBinding]() pairs. 

### function execute

```cpp
__event__ execute(
    const KVMap & kv_map,
    const __events__ & deps ={}
) const
```

Executes the primitive from a legacy `[Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) -> [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/)` map. 

### function execute

```cpp
__event__ execute(
    Memory & dst,
    const Memory & arg0,
    const __events__ & deps ={}
) const
```

Executes a unary primitive (`Elementwise`, `Softmax`, `Reduction`, `Reorder`). 

### function execute

```cpp
__event__ execute(
    Memory & dst,
    const Memory & arg0,
    const Memory & arg1,
    const __events__ & deps ={}
) const
```

Executes a 2-input primitive (`Binary`, `Matmul` without bias, `ElementwiseBackward`, `SoftmaxBackward`, 2-input `Sum`/`Concat`). 

### function execute

```cpp
__event__ execute(
    Memory & dst,
    const Memory & arg0,
    const Memory & arg1,
    const Memory & arg2,
    const __events__ & deps ={}
) const
```

Executes a 3-input primitive (`Matmul` with bias, 3-input `Sum`/`Concat`). 

### function execute

```cpp
__event__ execute(
    Memory & dst,
    std::span< const Memory > srcs,
    const __events__ & deps ={}
) const
```

Executes a variadic-source primitive (`Sum`, `Concat`) over a span of [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) buffers. 

### function execute

```cpp
__event__ execute(
    Tensor & dst,
    const Tensor & arg0,
    const __events__ & deps ={}
) const
```

Executes a unary primitive directly on [Tensor]() operands. 

### function execute

```cpp
__event__ execute(
    Tensor & dst,
    const Tensor & arg0,
    const Tensor & arg1,
    const __events__ & deps ={}
) const
```

Executes a 2-input primitive directly on [Tensor]() operands. 

### function execute

```cpp
__event__ execute(
    Tensor & dst,
    const Tensor & arg0,
    const Tensor & arg1,
    const Tensor & arg2,
    const __events__ & deps ={}
) const
```

Executes a 3-input primitive directly on [Tensor]() operands. 

## Protected Attributes Documentation

### variable impl

```cpp
std::unique_ptr< Impl > impl;
```


-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100