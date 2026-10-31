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
| | **[Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine)**()<br>Constructs default compute engine for the active device.  |
| | **[~Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-~engine)**() |
| | **[Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine)**(const Engine & other) |
| [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-operator=)**(const [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine) & other) |
| | **[Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine)**(Engine && other) |
| [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine) & | **[operator=](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-operator=)**([Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-engine) && other) |
| const [handles::__engine__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____/) & | **[native_handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-native-handle)**() const<br>Returns const reference to backend engine handle.  |
| [handles::__engine__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____/) & | **[native_handle](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#function-native-handle)**()<br>Returns mutable reference to backend engine handle.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#friend-memory)**  |
| class | **[PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/#friend-primitivedescriptor)**  |

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

Updated on 2026-10-31 at 18:51:12 +0100