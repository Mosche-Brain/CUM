---
title: cum::neural_primitives::Engine
summary: Compute execution engine encapsulating device accelerator execution context for primitives. 

---

# cum::neural_primitives::Engine



Compute execution engine encapsulating device accelerator execution context for primitives. 


`#include <Engine.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine)**()<br>Constructs default compute engine for the active device.  |
| | **[~Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-~engine)**() |
| | **[Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine)**(const Engine & other) |
| [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-operator=)**(const [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine) & other) |
| | **[Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine)**(Engine && other) |
| [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine) & | **[operator=](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-operator=)**([Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-engine) && other) |
| const [handles::__engine__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____.md) & | **[native_handle](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-native-handle)**() const<br>Returns const reference to backend engine handle.  |
| [handles::__engine__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____.md) & | **[native_handle](Classes/classcum_1_1neural__primitives_1_1Engine.md#function-native-handle)**()<br>Returns mutable reference to backend engine handle.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Memory](Classes/classcum_1_1neural__primitives_1_1Engine.md#friend-memory)**  |
| class | **[PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1Engine.md#friend-primitivedescriptor)**  |

## Public Functions Documentation

### function Engine

```cpp
Engine()
```

Constructs default compute engine for the active device. 

### function ~Engine

```cpp
~Engine()
```


### function Engine

```cpp
Engine(
    const Engine & other
)
```


### function operator=

```cpp
Engine & operator=(
    const Engine & other
)
```


### function Engine

```cpp
Engine(
    Engine && other
)
```


### function operator=

```cpp
Engine & operator=(
    Engine && other
)
```


### function native_handle

```cpp
const handles::__engine__ & native_handle() const
```

Returns const reference to backend engine handle. 

### function native_handle

```cpp
handles::__engine__ & native_handle()
```

Returns mutable reference to backend engine handle. 

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