---
title: cum::neural_primitives::Memory
summary: Storage buffer managed by neural primitive engine according to a Descriptor. 

---

# cum::neural_primitives::Memory



Storage buffer managed by neural primitive engine according to a [Descriptor](). 


`#include <Memory.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md) | **[Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor)** <br>[Descriptor]() describing the layout of this memory.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**()<br>Constructs an empty memory handle.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) & desc)<br>Constructs memory buffer according to descriptor using shared USM storage.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) & desc, void * data)<br>Constructs memory object wrapping existing raw data pointer.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) & desc, [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine)<br>Constructs memory buffer on specified compute engine.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) & desc, [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md) & engine, void * data)<br>Constructs memory object on engine wrapping existing raw data pointer.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) & desc, const Memory & source)<br>Constructs memory view over source memory object.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & handle)<br>Constructs memory object from backend handle.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**([handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & handle)<br>Constructs memory object from mutable backend handle.  |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(const Memory & other) |
| [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-operator=)**(const [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory) & other) |
| | **[Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory)**(Memory && other) |
| [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-operator=)**([Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-memory) && other) |
| | **[~Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-~memory)**() |
| bool | **[valid](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-valid)**() const<br>Checks whether this memory object holds a valid backend memory handle.  |
| | **[operator bool](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-valid).  |
| [Descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#using-descriptor) | **[descriptor](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-descriptor)**() const<br>Returns the [MemoryDescriptor]() associated with this memory buffer.  |
| void * | **[data](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-data)**()<br>Returns pointer to mapped data buffer.  |
| const void * | **[data](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-data)**() const<br>Returns const pointer to mapped data buffer.  |
| template <typename T \> <br>T * | **[data](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-data)**()<br>Typed pointer accessor for the underlying data buffer.  |
| template <typename T \> <br>const T * | **[data](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-data)**() const<br>Typed const pointer accessor for the underlying data buffer.  |
| void | **[set_data](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-set-data)**(void * data)<br>Rebinds memory object to new raw data buffer.  |
| std::shared_ptr< [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) > | **[owner](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-owner)**() const<br>Returns shared pointer to owner handle if this is a view.  |
| const [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & | **[handle](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-handle)**() const<br>Returns const reference to backend memory handle.  |
| [handles::__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md) & | **[handle](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-handle)**()<br>Returns mutable reference to backend memory handle.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[cum::Tensor](Classes/classcum_1_1neural__primitives_1_1Memory.md#friend-cumtensor)**  |

## Public Types Documentation

### using Descriptor

```cpp
using cum::neural_primitives::Memory::Descriptor = MemoryDescriptor;
```

[Descriptor]() describing the layout of this memory. 

## Public Functions Documentation

### function Memory

```cpp
Memory()
```

Constructs an empty memory handle. 

### function Memory

```cpp
explicit Memory(
    const Descriptor & desc
)
```

Constructs memory buffer according to descriptor using shared USM storage. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor. 


### function Memory

```cpp
Memory(
    const Descriptor & desc,
    void * data
)
```

Constructs memory object wrapping existing raw data pointer. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor. 
  * **data** Pointer to existing memory. 


### function Memory

```cpp
Memory(
    const Descriptor & desc,
    Engine & engine
)
```

Constructs memory buffer on specified compute engine. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor. 
  * **engine** Target compute engine. 


### function Memory

```cpp
Memory(
    const Descriptor & desc,
    Engine & engine,
    void * data
)
```

Constructs memory object on engine wrapping existing raw data pointer. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor. 
  * **engine** Target compute engine. 
  * **data** Pointer to existing memory. 


### function Memory

```cpp
Memory(
    const Descriptor & desc,
    const Memory & source
)
```

Constructs memory view over source memory object. 

**Parameters**: 

  * **desc** [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) descriptor for the view. 
  * **source** Underlying source memory. 


### function Memory

```cpp
Memory(
    const handles::__memory__ & handle
)
```

Constructs memory object from backend handle. 

**Parameters**: 

  * **handle** Backend memory handle. 


### function Memory

```cpp
Memory(
    handles::__memory__ & handle
)
```

Constructs memory object from mutable backend handle. 

**Parameters**: 

  * **handle** Backend memory handle. 


### function Memory

```cpp
Memory(
    const Memory & other
)
```


### function operator=

```cpp
Memory & operator=(
    const Memory & other
)
```


### function Memory

```cpp
Memory(
    Memory && other
)
```


### function operator=

```cpp
Memory & operator=(
    Memory && other
)
```


### function ~Memory

```cpp
~Memory()
```


### function valid

```cpp
bool valid() const
```

Checks whether this memory object holds a valid backend memory handle. 

### function operator bool

```cpp
inline explicit operator bool() const
```

Boolean conversion equivalent to [valid()](Classes/classcum_1_1neural__primitives_1_1Memory.md#function-valid). 

### function descriptor

```cpp
Descriptor descriptor() const
```

Returns the [MemoryDescriptor]() associated with this memory buffer. 

### function data

```cpp
void * data()
```

Returns pointer to mapped data buffer. 

**Return**: Void pointer to memory buffer. 

### function data

```cpp
const void * data() const
```

Returns const pointer to mapped data buffer. 

**Return**: Const void pointer to memory buffer. 

### function data

```cpp
template <typename T >
inline T * data()
```

Typed pointer accessor for the underlying data buffer. 

### function data

```cpp
template <typename T >
inline const T * data() const
```

Typed const pointer accessor for the underlying data buffer. 

### function set_data

```cpp
void set_data(
    void * data
)
```

Rebinds memory object to new raw data buffer. 

**Parameters**: 

  * **data** Pointer to memory buffer. 


### function owner

```cpp
std::shared_ptr< handles::__memory__ > owner() const
```

Returns shared pointer to owner handle if this is a view. 

**Return**: Owner handle pointer. 

### function handle

```cpp
const handles::__memory__ & handle() const
```

Returns const reference to backend memory handle. 

**Return**: Backend handle. 

### function handle

```cpp
handles::__memory__ & handle()
```

Returns mutable reference to backend memory handle. 

**Return**: Backend handle. 

## Friends

### friend cum::Tensor

```cpp
friend class cum::Tensor(
    cum::Tensor 
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100