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
| struct | **[ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md)** <br>Zero-copy argument binding pairing an [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) slot with a [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) or [Tensor]() reference.  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class int | **[Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument)** { undef = 0, src = 1, src0 = 1, src1 = 2, src2 = 3, src3 = 4, dst = 17, dst0 = 17, weights = 33, bias = 41, workspace = 64, scratchpad = 80, diff_src = 129, diff_src0 = 129, diff_src1 = 130, diff_dst = 145, diff_weights = 161, diff_bias = 169, multiple_src = 1024}<br>Named tensor slot identifiers for primitive execution.  |
| using [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md) | **[Descriptor](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-descriptor)** <br>[Descriptor]() type alias.  |
| using [Descriptor::Kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#enum-kind) | **[Kind](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-kind)** <br>Operation category alias.  |
| using std::pair< [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument), [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) > | **[KV](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-kv)**  |
| using std::unordered_map< [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument), [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) > | **[KVMap](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-kvmap)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) | **[multiple_src_arg](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-multiple-src-arg)**(int index)<br>Computes the indexed variadic source slot (`[Argument::multiple_src](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enumvalue-multiple-src) + index`) for `Sum` / `Concat`.  |
| | **[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive)**()<br>Constructs an empty, uncompiled primitive.  |
| | **[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-descriptor) & descriptor)<br>Compiles an executable primitive from `descriptor`.  |
| | **[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive)**(const Primitive & other) |
| [Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-operator=)**(const [Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive) & other) |
| | **[Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive)**(Primitive && other) |
| [Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-operator=)**([Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-primitive) && other) |
| | **[~Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-~primitive)**() |
| void | **[compile](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-compile)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-descriptor) & descriptor)<br>Compiles (or recompiles) this primitive from `descriptor`.  |
| void | **[compile](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-compile)**()<br>Ensures the primitive is compiled from its stored descriptor.  |
| bool | **[valid](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-valid)**() const<br>Checks whether this primitive is compiled and ready to execute.  |
| | **[operator bool](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-valid).  |
| [Kind](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md#enum-kind) | **[kind](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-kind)**() const<br>Returns operation category of this primitive.  |
| const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-descriptor) & | **[descriptor](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-descriptor)**() const<br>Returns const reference to the [PrimitiveDescriptor]() from which this primitive was compiled.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**(std::span< const [ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md) > args, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes the primitive with explicit [ArgBinding]() pairs (accepts both [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) and [Tensor]()).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**(std::initializer_list< [ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md) > args, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes the primitive from a brace-initialized list of [ArgBinding]() pairs.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**(const [KVMap](Classes/classcum_1_1neural__primitives_1_1Primitive.md#using-kvmap) & kv_map, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes the primitive from a legacy `[Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) -> [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md)` map.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg0, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a unary primitive (`Elementwise`, `Softmax`, `Reduction`, `Reorder`).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg0, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg1, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a 2-input primitive (`Binary`, `Matmul` without bias, `ElementwiseBackward`, `SoftmaxBackward`, 2-input `Sum`/`Concat`).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg0, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg1, const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & arg2, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a 3-input primitive (`Matmul` with bias, 3-input `Sum`/`Concat`).  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) & dst, std::span< const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) > srcs, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a variadic-source primitive (`Sum`, `Concat`) over a span of [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) buffers.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & arg0, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a unary primitive directly on [Tensor]() operands.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & arg0, const [Tensor](Classes/classcum_1_1Tensor.md) & arg1, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a 2-input primitive directly on [Tensor]() operands.  |
| [__event__](Namespaces/namespacecum.md#using---event--) | **[execute](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-execute)**([Tensor](Classes/classcum_1_1Tensor.md) & dst, const [Tensor](Classes/classcum_1_1Tensor.md) & arg0, const [Tensor](Classes/classcum_1_1Tensor.md) & arg1, const [Tensor](Classes/classcum_1_1Tensor.md) & arg2, const [__events__](Namespaces/namespacecum.md#using---events--) & deps ={}) const<br>Executes a 3-input primitive directly on [Tensor]() operands.  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< Impl > | **[impl](Classes/classcum_1_1neural__primitives_1_1Primitive.md#variable-impl)**  |

## Detailed Description

```cpp
class cum::neural_primitives::Primitive;
```

Executable compute primitive representing a compiled neural network or tensor operation. 

Wraps a backend-compiled primitive created from a [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md) and executes asynchronously on the active compute stream, returning an [__event__](Namespaces/namespacecum.md#using---event--). 

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

Computes the indexed variadic source slot (`[Argument::multiple_src](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enumvalue-multiple-src) + index`) for `Sum` / `Concat`. 

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

Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1Primitive.md#function-valid). 

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

Executes the primitive with explicit [ArgBinding]() pairs (accepts both [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) and [Tensor]()). 

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

Executes the primitive from a legacy `[Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) -> [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md)` map. 

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

Executes a variadic-source primitive (`Sum`, `Concat`) over a span of [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) buffers. 

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

Updated on 2026-10-31 at 18:07:41 +0100