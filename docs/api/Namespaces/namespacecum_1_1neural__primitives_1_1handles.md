---
title: cum::neural_primitives::handles

---

# cum::neural_primitives::handles



## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::neural_primitives::handles::__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/)** <br>Underlying oneDNN memory wrapper with optional USM shared ownership.  |
| struct | **[cum::neural_primitives::handles::__engine__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____/)** <br>Underlying oneDNN engine wrapper.  |
| struct | **[cum::neural_primitives::handles::__stream__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____stream____/)** <br>Underlying oneDNN stream wrapper.  |
| struct | **[cum::neural_primitives::handles::__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/)** <br>Underlying oneDNN memory descriptor wrapper.  |

## Types

|                | Name           |
| -------------- | -------------- |
| typedef struct __memory__ | **[__memory__](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1handles/#typedef---memory--)** <br>Opaque backend handle for memory primitives.  |
| typedef struct __engine__ | **[__engine__](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1handles/#typedef---engine--)** <br>Opaque backend handle for compute execution engine.  |
| typedef struct __stream__ | **[__stream__](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1handles/#typedef---stream--)** <br>Opaque backend handle for command execution stream.  |
| typedef struct __desc__ | **[__desc__](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1handles/#typedef---desc--)** <br>Opaque backend handle for memory descriptors.  |

## Types Documentation

### typedef __memory__

```cpp
typedef struct __memory__ cum::neural_primitives::handles::__memory__;
```

Opaque backend handle for memory primitives. 

### typedef __engine__

```cpp
typedef struct __engine__ cum::neural_primitives::handles::__engine__;
```

Opaque backend handle for compute execution engine. 

### typedef __stream__

```cpp
typedef struct __stream__ cum::neural_primitives::handles::__stream__;
```

Opaque backend handle for command execution stream. 

### typedef __desc__

```cpp
typedef struct __desc__ cum::neural_primitives::handles::__desc__;
```

Opaque backend handle for memory descriptors. 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100