---
title: cum::experimental::__event__
summary: Opaque handle representing an in-flight or completed asynchronous device operation. 

---

# cum::experimental::__event__



Opaque handle representing an in-flight or completed asynchronous device operation. 


`#include <__event__.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--)**()<br>Default constructor creating an empty / completed event.  |
| | **[__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--)**(__event__ && other)<br>Move constructor.  |
| [__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--) & | **[operator=](Classes/classcum_1_1experimental_1_1____event____.md#function-operator=)**([__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--) && other)<br>Move assignment operator.  |
| | **[__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--)**(const __event__ & ) =delete |
| [__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--) & | **[operator=](Classes/classcum_1_1experimental_1_1____event____.md#function-operator=)**(const [__event__](Classes/classcum_1_1experimental_1_1____event____.md#function---event--) & ) =delete |
| | **[~__event__](Classes/classcum_1_1experimental_1_1____event____.md#function-~--event--)**() |
| void | **[wait](Classes/classcum_1_1experimental_1_1____event____.md#function-wait)**()<br>Blocks host thread until the asynchronous event and associated device kernels finish execution.  |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[cum::detail::event_handler](Classes/classcum_1_1experimental_1_1____event____.md#friend-cumdetailevent-handler)**  |

## Public Functions Documentation

### function __event__

```cpp
__event__()
```

Default constructor creating an empty / completed event. 

### function __event__

```cpp
__event__(
    __event__ && other
)
```

Move constructor. 

**Parameters**: 

  * **other** Event to move from. 


### function operator=

```cpp
__event__ & operator=(
    __event__ && other
)
```

Move assignment operator. 

**Parameters**: 

  * **other** Event to move from. 


**Return**: Reference to `*this`. 

### function __event__

```cpp
__event__(
    const __event__ & 
) =delete
```


### function operator=

```cpp
__event__ & operator=(
    const __event__ & 
) =delete
```


### function ~__event__

```cpp
~__event__()
```


### function wait

```cpp
void wait()
```

Blocks host thread until the asynchronous event and associated device kernels finish execution. 

## Friends

### friend cum::detail::event_handler

```cpp
friend class cum::detail::event_handler(
    cum::detail::event_handler 
);
```


-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100