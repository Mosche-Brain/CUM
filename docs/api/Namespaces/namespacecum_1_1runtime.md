---
title: cum::runtime

---

# cum::runtime



## Types

|                | Name           |
| -------------- | -------------- |
| typedef struct [Device](Namespaces/namespacecum_1_1runtime.md#typedef-device) | **[Device](Namespaces/namespacecum_1_1runtime.md#typedef-device)**  |
| typedef struct [Queue](Namespaces/namespacecum_1_1runtime.md#typedef-queue) | **[Queue](Namespaces/namespacecum_1_1runtime.md#typedef-queue)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[sync](Namespaces/namespacecum_1_1runtime.md#function-sync)**()<br>Blocks host execution until all submitted asynchronous operations complete on the device queue.  |

## Types Documentation

### typedef Device

```cpp
typedef struct Device cum::runtime::Device;
```


### typedef Queue

```cpp
typedef struct Queue cum::runtime::Queue;
```



## Functions Documentation

### function sync

```cpp
void sync()
```

Blocks host execution until all submitted asynchronous operations complete on the device queue. 





-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100