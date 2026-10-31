---
title: cum::runtime

---

# cum::runtime



## Types

|                | Name           |
| -------------- | -------------- |
| typedef struct [Device](/CUM/api/Namespaces/namespacecum_1_1runtime/#typedef-device) | **[Device](/CUM/api/Namespaces/namespacecum_1_1runtime/#typedef-device)**  |
| typedef struct [Queue](/CUM/api/Namespaces/namespacecum_1_1runtime/#typedef-queue) | **[Queue](/CUM/api/Namespaces/namespacecum_1_1runtime/#typedef-queue)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[sync](/CUM/api/Namespaces/namespacecum_1_1runtime/#function-sync)**()<br>Blocks host execution until all submitted asynchronous operations complete on the device queue.  |

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

Updated on 2026-10-31 at 18:51:12 +0100