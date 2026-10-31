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
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**()<br>Constructs an empty (zero) memory descriptor.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**([Shape](/CUM/api/Namespaces/namespacecum/#using-shape) dims, [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [layout](/CUM/api/Namespaces/namespacecum/#enum-layout) format =[layout::ANY](/CUM/api/Namespaces/namespacecum/#enumvalue-any))<br>Constructs descriptor from dimensions, datatype, and layout format.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**([Shape](/CUM/api/Namespaces/namespacecum/#using-shape) dims, [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) strides)<br>Constructs descriptor with explicit per-dimension strides (in elements).  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**(const MemoryDescriptor & other)<br>Copy constructor.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**(const [handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/) & handle)<br>Constructs descriptor from const backend descriptor handle.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**(const [handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/) & handle, [layout](/CUM/api/Namespaces/namespacecum/#enum-layout) format)<br>Constructs descriptor from const backend descriptor handle and layout format.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**([handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/) & handle)<br>Constructs descriptor from backend descriptor handle.  |
| | **[MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor)**(MemoryDescriptor && other)<br>Move constructor.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-operator=)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & other) |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-operator=)**([MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) && other) |
| | **[~MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-~memorydescriptor)**() |
| bool | **[valid](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-valid)**() const<br>Checks whether this descriptor represents a non-empty memory layout.  |
| | **[operator bool](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-valid).  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[size](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-size)**() const<br>Returns total memory size in bytes required by descriptor.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[ndims](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-ndims)**() const<br>Returns number of dimensions (rank).  |
| [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) | **[shape](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-shape)**() const<br>Returns shape dimensions vector.  |
| [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) | **[strides](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-strides)**() const<br>Returns per-dimension strides vector (empty if layout is opaque or `ANY`).  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[stride](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-stride)**() const<br>Returns leading stride of descriptor (or 0 if empty/unspecified).  |
| [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) | **[type](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-type)**() const<br>Returns element datatype tag.  |
| [layout](/CUM/api/Namespaces/namespacecum/#enum-layout) | **[format](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-format)**() const<br>Returns memory layout format.  |
| [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) | **[offset](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-offset)**() const<br>Returns submemory offset.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) | **[reshape](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-reshape)**(const [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) & shape) const<br>Reshapes descriptor out-of-place.  |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & | **[reshape_in_place](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-reshape-in-place)**(const [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) & shape)<br>Reshapes descriptor in-place.  |
| const [handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/) & | **[handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-handle)**() const<br>Returns const reference to backend handle.  |
| [handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/) & | **[handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-handle)**()<br>Returns mutable reference to backend handle.  |
| bool | **[operator==](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-operator==)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & other) const |
| bool | **[operator!=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-operator!=)**(const [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) & other) const |
| [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-memorydescriptor) | **[Any](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-any)**(const [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) & dims, [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype)<br>Creates a format-agnostic (`[layout::ANY](/CUM/api/Namespaces/namespacecum/#enumvalue-any)`) descriptor allowing primitives to pick an optimal layout.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#friend-memory)**  |
| class | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#friend-primitivedescriptor)**  |

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

  * **dims** [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) vector. 
  * **dtype** Element datatype tag. 
  * **format** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) layout tag (defaults to [layout::ANY](/CUM/api/Namespaces/namespacecum/#enumvalue-any)). 


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

  * **dims** [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) vector. 
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
  * **format** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) layout format. 


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

Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/#function-valid). 

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

**Return**: [Shape](/CUM/api/Namespaces/namespacecum/#using-shape). 

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

Creates a format-agnostic (`[layout::ANY](/CUM/api/Namespaces/namespacecum/#enumvalue-any)`) descriptor allowing primitives to pick an optimal layout. 

**Parameters**: 

  * **dims** [Shape](/CUM/api/Namespaces/namespacecum/#using-shape) vector. 
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

Updated on 2026-10-31 at 18:51:12 +0100