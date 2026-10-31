---
title: cum::neural_primitives::MemoryDescriptor
summary: Encapsulates tensor shape, data type, and memory format layout for neural network primitives. 

---

# cum::neural_primitives::MemoryDescriptor



Encapsulates tensor shape, data type, and memory format layout for neural network primitives. 


`#include <MemoryDescriptor.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**()<br>Constructs an empty (zero) memory descriptor.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**([Shape](Namespaces/namespacecum.md#using-shape) dims, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype, [layout](Namespaces/namespacecum.md#enum-layout) format =[layout::ANY](Namespaces/namespacecum.md#enumvalue-any))<br>Constructs descriptor from dimensions, datatype, and layout format.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**([Shape](Namespaces/namespacecum.md#using-shape) dims, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype, [Shape](Namespaces/namespacecum.md#using-shape) strides)<br>Constructs descriptor with explicit per-dimension strides (in elements).  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**(const MemoryDescriptor & other)<br>Copy constructor.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**(const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & handle)<br>Constructs descriptor from const backend descriptor handle.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**(const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & handle, [layout](Namespaces/namespacecum.md#enum-layout) format)<br>Constructs descriptor from const backend descriptor handle and layout format.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**([handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & handle)<br>Constructs descriptor from backend descriptor handle.  |
| | **[MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor)**(MemoryDescriptor && other)<br>Move constructor.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-operator=)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & other) |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-operator=)**([MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) && other) |
| | **[~MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-~memorydescriptor)**() |
| bool | **[valid](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-valid)**() const<br>Checks whether this descriptor represents a non-empty memory layout.  |
| | **[operator bool](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-valid).  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[size](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-size)**() const<br>Returns total memory size in bytes required by descriptor.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[ndims](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-ndims)**() const<br>Returns number of dimensions (rank).  |
| [Shape](Namespaces/namespacecum.md#using-shape) | **[shape](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-shape)**() const<br>Returns shape dimensions vector.  |
| [Shape](Namespaces/namespacecum.md#using-shape) | **[strides](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-strides)**() const<br>Returns per-dimension strides vector (empty if layout is opaque or `ANY`).  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[stride](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-stride)**() const<br>Returns leading stride of descriptor (or 0 if empty/unspecified).  |
| [datatype](Namespaces/namespacecum.md#enum-datatype) | **[type](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-type)**() const<br>Returns element datatype tag.  |
| [layout](Namespaces/namespacecum.md#enum-layout) | **[format](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-format)**() const<br>Returns memory layout format.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[offset](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-offset)**() const<br>Returns submemory offset.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) | **[reshape](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-reshape)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape) const<br>Reshapes descriptor out-of-place.  |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & | **[reshape_in_place](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-reshape-in-place)**(const [Shape](Namespaces/namespacecum.md#using-shape) & shape)<br>Reshapes descriptor in-place.  |
| const [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & | **[handle](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-handle)**() const<br>Returns const reference to backend handle.  |
| [handles::__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md) & | **[handle](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-handle)**()<br>Returns mutable reference to backend handle.  |
| bool | **[operator==](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-operator==)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & other) const |
| bool | **[operator!=](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-operator!=)**(const [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) & other) const |
| [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-memorydescriptor) | **[Any](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-any)**(const [Shape](Namespaces/namespacecum.md#using-shape) & dims, [datatype](Namespaces/namespacecum.md#enum-datatype) dtype)<br>Creates a format-agnostic (`[layout::ANY](Namespaces/namespacecum.md#enumvalue-any)`) descriptor allowing primitives to pick an optimal layout.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Memory](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#friend-memory)**  |
| class | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#friend-primitivedescriptor)**  |

## Public Functions Documentation

### function MemoryDescriptor

```cpp
MemoryDescriptor()
```

Constructs an empty (zero) memory descriptor. 

### function MemoryDescriptor

```cpp
MemoryDescriptor(
    Shape dims,
    datatype dtype,
    layout format =layout::ANY
)
```

Constructs descriptor from dimensions, datatype, and layout format. 

**Parameters**: 

  * **dims** [Shape](Namespaces/namespacecum.md#using-shape) vector. 
  * **dtype** Element datatype tag. 
  * **format** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout tag (defaults to [layout::ANY](Namespaces/namespacecum.md#enumvalue-any)). 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    Shape dims,
    datatype dtype,
    Shape strides
)
```

Constructs descriptor with explicit per-dimension strides (in elements). 

**Parameters**: 

  * **dims** [Shape](Namespaces/namespacecum.md#using-shape) vector. 
  * **dtype** Element datatype tag. 
  * **strides** Per-dimension stride vector. 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    const MemoryDescriptor & other
)
```

Copy constructor. 

**Parameters**: 

  * **other** Descriptor to copy. 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    const handles::__desc__ & handle
)
```

Constructs descriptor from const backend descriptor handle. 

**Parameters**: 

  * **handle** Backend handle. 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    const handles::__desc__ & handle,
    layout format
)
```

Constructs descriptor from const backend descriptor handle and layout format. 

**Parameters**: 

  * **handle** Backend handle. 
  * **format** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) layout format. 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    handles::__desc__ & handle
)
```

Constructs descriptor from backend descriptor handle. 

**Parameters**: 

  * **handle** Backend handle. 


### function MemoryDescriptor

```cpp
MemoryDescriptor(
    MemoryDescriptor && other
)
```

Move constructor. 

**Parameters**: 

  * **other** Descriptor to move from. 


### function operator=

```cpp
MemoryDescriptor & operator=(
    const MemoryDescriptor & other
)
```


### function operator=

```cpp
MemoryDescriptor & operator=(
    MemoryDescriptor && other
)
```


### function ~MemoryDescriptor

```cpp
~MemoryDescriptor()
```


### function valid

```cpp
bool valid() const
```

Checks whether this descriptor represents a non-empty memory layout. 

### function operator bool

```cpp
inline explicit operator bool() const
```

Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md#function-valid). 

### function size

```cpp
dim_t size() const
```

Returns total memory size in bytes required by descriptor. 

**Return**: Size in bytes. 

### function ndims

```cpp
dim_t ndims() const
```

Returns number of dimensions (rank). 

**Return**: Rank. 

### function shape

```cpp
Shape shape() const
```

Returns shape dimensions vector. 

**Return**: [Shape](Namespaces/namespacecum.md#using-shape). 

### function strides

```cpp
Shape strides() const
```

Returns per-dimension strides vector (empty if layout is opaque or `ANY`). 

**Return**: Stride vector in elements. 

### function stride

```cpp
dim_t stride() const
```

Returns leading stride of descriptor (or 0 if empty/unspecified). 

**Return**: Leading stride in elements. 

### function type

```cpp
datatype type() const
```

Returns element datatype tag. 

**Return**: Datatype tag. 

### function format

```cpp
layout format() const
```

Returns memory layout format. 

**Return**: Layout format tag. 

### function offset

```cpp
dim_t offset() const
```

Returns submemory offset. 

**Return**: Offset in bytes. 

### function reshape

```cpp
MemoryDescriptor reshape(
    const Shape & shape
) const
```

Reshapes descriptor out-of-place. 

**Parameters**: 

  * **shape** New shape. 


**Return**: Reshaped Descriptor. 

### function reshape_in_place

```cpp
MemoryDescriptor & reshape_in_place(
    const Shape & shape
)
```

Reshapes descriptor in-place. 

**Parameters**: 

  * **shape** New shape. 


**Return**: Reference to `*this`. 

### function handle

```cpp
const handles::__desc__ & handle() const
```

Returns const reference to backend handle. 

**Return**: Backend handle. 

### function handle

```cpp
handles::__desc__ & handle()
```

Returns mutable reference to backend handle. 

**Return**: Backend handle. 

### function operator==

```cpp
bool operator==(
    const MemoryDescriptor & other
) const
```


### function operator!=

```cpp
bool operator!=(
    const MemoryDescriptor & other
) const
```


### function Any

```cpp
static MemoryDescriptor Any(
    const Shape & dims,
    datatype dtype
)
```

Creates a format-agnostic (`[layout::ANY](Namespaces/namespacecum.md#enumvalue-any)`) descriptor allowing primitives to pick an optimal layout. 

**Parameters**: 

  * **dims** [Shape](Namespaces/namespacecum.md#using-shape) vector. 
  * **dtype** Element datatype tag. 


**Return**: Format-agnostic memory descriptor. 

## Friends

### friend Memory

```cpp
friend class Memory(
    Memory 
);
```


### friend PrimitiveDescriptor

```cpp
friend class PrimitiveDescriptor(
    PrimitiveDescriptor 
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100