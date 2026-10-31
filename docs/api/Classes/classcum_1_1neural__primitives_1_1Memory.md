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
| using [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/) | **[Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor)** <br>[Descriptor]() describing the layout of this memory.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**()<br>Constructs an empty memory handle.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) & desc)<br>Constructs memory buffer according to descriptor using shared USM storage.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) & desc, void * data)<br>Constructs memory object wrapping existing raw data pointer.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) & desc, [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine)<br>Constructs memory buffer on specified compute engine.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) & desc, [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/) & engine, void * data)<br>Constructs memory object on engine wrapping existing raw data pointer.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) & desc, const Memory & source)<br>Constructs memory view over source memory object.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const [handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/) & handle)<br>Constructs memory object from backend handle.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**([handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/) & handle)<br>Constructs memory object from mutable backend handle.  |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(const Memory & other) |
| [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-operator=)**(const [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory) & other) |
| | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory)**(Memory && other) |
| [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-operator=)**([Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-memory) && other) |
| | **[~Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-~memory)**() |
| bool | **[valid](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-valid)**() const<br>Checks whether this memory object holds a valid backend memory handle.  |
| | **[operator bool](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-operator-bool)**() const<br>Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-valid).  |
| [Descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#using-descriptor) | **[descriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-descriptor)**() const<br>Returns the [MemoryDescriptor]() associated with this memory buffer.  |
| void * | **[data](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-data)**()<br>Returns pointer to mapped data buffer.  |
| const void * | **[data](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-data)**() const<br>Returns const pointer to mapped data buffer.  |
| template <typename T \> <br>T * | **[data](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-data)**()<br>Typed pointer accessor for the underlying data buffer.  |
| template <typename T \> <br>const T * | **[data](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-data)**() const<br>Typed const pointer accessor for the underlying data buffer.  |
| void | **[set_data](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-set-data)**(void * data)<br>Rebinds memory object to new raw data buffer.  |
| std::shared_ptr< [handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/) > | **[owner](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-owner)**() const<br>Returns shared pointer to owner handle if this is a view.  |
| const [handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/) & | **[handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-handle)**() const<br>Returns const reference to backend memory handle.  |
| [handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/) & | **[handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-handle)**()<br>Returns mutable reference to backend memory handle.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[cum::Tensor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#friend-cumtensor)**  |

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

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor. 


### function Memory

```cpp
Memory(
    const Descriptor & desc,
    void * data
)
```

Constructs memory object wrapping existing raw data pointer. 

**Parameters**: 

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor. 
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

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor. 
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

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor. 
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

  * **desc** [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) descriptor for the view. 
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

Boolean conversion equivalent to [valid()](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/#function-valid). 

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

Updated on 2026-10-31 at 18:51:12 +0100