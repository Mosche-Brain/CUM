---
title: cum::detail::event_handler
summary: Factory and accessor bridging SYCL asynchronous events with CUM's experimental::__event__. 

---

# cum::detail::event_handler



Factory and accessor bridging SYCL asynchronous events with CUM's [experimental::__event__](). 


`#include <event_handler.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [experimental::__event__](/CUM/api/Classes/classcum_1_1experimental_1_1____event____/) | **[create](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/#function-create)**(sycl::event && event)<br>Wraps an rvalue SYCL event into an [experimental::__event__]().  |
| bool | **[valid](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/#function-valid)**(const [experimental::__event__](/CUM/api/Classes/classcum_1_1experimental_1_1____event____/) & event)<br>Checks whether the wrapped event holds an active backend event handle.  |
| sycl::event & | **[handle](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/#function-handle)**([experimental::__event__](/CUM/api/Classes/classcum_1_1experimental_1_1____event____/) & event)<br>Extracts underlying SYCL event reference from an [experimental::__event__]().  |
| const sycl::event & | **[handle](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/#function-handle)**(const [experimental::__event__](/CUM/api/Classes/classcum_1_1experimental_1_1____event____/) & event)<br>Extracts underlying const SYCL event reference from an [experimental::__event__]().  |

## Public Functions Documentation

### function create

```cpp
static experimental::__event__ create(
    sycl::event && event
)
```

Wraps an rvalue SYCL event into an [experimental::__event__](). 

**Parameters**: 

  * **event** SYCL event. 


**Return**: Wrapped event handle. 

### function valid

```cpp
static bool valid(
    const experimental::__event__ & event
)
```

Checks whether the wrapped event holds an active backend event handle. 

**Parameters**: 

  * **event** Wrapped event handle. 


**Return**: True if initialized, false if default-constructed/empty. 

### function handle

```cpp
static sycl::event & handle(
    experimental::__event__ & event
)
```

Extracts underlying SYCL event reference from an [experimental::__event__](). 

**Parameters**: 

  * **event** Wrapped event handle. 


**Return**: Reference to underlying SYCL event. 

### function handle

```cpp
static const sycl::event & handle(
    const experimental::__event__ & event
)
```

Extracts underlying const SYCL event reference from an [experimental::__event__](). 

**Parameters**: 

  * **event** Wrapped event handle. 


**Return**: Const reference to underlying SYCL event. 

-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100