---
title: cum::random

---

# cum::random



## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[uniform](/CUM/api/Namespaces/namespacecum_1_1random/#function-uniform)**(cumeric_t * buff, const std::size_t N, const cumeric_t min =-1._c, const cumeric_t max =1._c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) seed =2137)<br>Generates uniformly distributed random values into a typed buffer.  |
| void | **[uniform](/CUM/api/Namespaces/namespacecum_1_1random/#function-uniform)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * buff, const std::size_t N, const cumeric_t min =-1._c, const cumeric_t max =1._c, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) seed =2137)<br>Generates uniformly distributed random values into a generic buffer with scalar bounds.  |
| void | **[uniform](/CUM/api/Namespaces/namespacecum_1_1random/#function-uniform)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * buff, const std::size_t N, const void * min, const void * max, [dim_t](/CUM/api/Namespaces/namespacecum/#using-dim-t) seed =2137)<br>Generates uniformly distributed random values into a generic buffer with typed raw bound pointers.  |
| void | **[normal](/CUM/api/Namespaces/namespacecum_1_1random/#function-normal)**(cumeric_t * buff, const std::size_t N, const cumeric_t sigma, std::size_t seed =2137)<br>Generates normally distributed random values (zero mean) into a typed buffer.  |
| void | **[normal](/CUM/api/Namespaces/namespacecum_1_1random/#function-normal)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * buff, const std::size_t N, const cumeric_t sigma, std::size_t seed =2137)<br>Generates normally distributed random values (zero mean) into a generic buffer with scalar standard deviation.  |
| void | **[normal](/CUM/api/Namespaces/namespacecum_1_1random/#function-normal)**([datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) dtype, void * buff, const std::size_t N, const void * sigma, std::size_t seed =2137)<br>Generates normally distributed random values into a generic buffer with a pointer to standard deviation.  |


## Functions Documentation

### function uniform

```cpp
void uniform(
    cumeric_t * buff,
    const std::size_t N,
    const cumeric_t min =-1._c,
    const cumeric_t max =1._c,
    dim_t seed =2137
)
```

Generates uniformly distributed random values into a typed buffer. 

**Parameters**: 

  * **buff** Destination buffer of cumeric_t elements. 
  * **N** Number of elements to generate. 
  * **min** Lower bound of the uniform distribution (default -1.0). 
  * **max** Upper bound of the uniform distribution (default 1.0). 
  * **seed** Random generator seed (default 2137). 


### function uniform

```cpp
void uniform(
    datatype dtype,
    void * buff,
    const std::size_t N,
    const cumeric_t min =-1._c,
    const cumeric_t max =1._c,
    dim_t seed =2137
)
```

Generates uniformly distributed random values into a generic buffer with scalar bounds. 

**Parameters**: 

  * **dtype** Runtime datatype tag of elements in the buffer. 
  * **buff** Destination memory buffer. 
  * **N** Number of elements to generate. 
  * **min** Lower bound scalar value (default -1.0). 
  * **max** Upper bound scalar value (default 1.0). 
  * **seed** Random generator seed (default 2137). 


### function uniform

```cpp
void uniform(
    datatype dtype,
    void * buff,
    const std::size_t N,
    const void * min,
    const void * max,
    dim_t seed =2137
)
```

Generates uniformly distributed random values into a generic buffer with typed raw bound pointers. 

**Parameters**: 

  * **dtype** Runtime datatype tag of elements in the buffer. 
  * **buff** Destination memory buffer. 
  * **N** Number of elements to generate. 
  * **min** Pointer to the lower bound value in the matching datatype. 
  * **max** Pointer to the upper bound value in the matching datatype. 
  * **seed** Random generator seed (default 2137). 


### function normal

```cpp
void normal(
    cumeric_t * buff,
    const std::size_t N,
    const cumeric_t sigma,
    std::size_t seed =2137
)
```

Generates normally distributed random values (zero mean) into a typed buffer. 

**Parameters**: 

  * **buff** Destination buffer of cumeric_t elements. 
  * **N** Number of elements to generate. 
  * **sigma** Standard deviation of the normal distribution. 
  * **seed** Random generator seed (default 2137). 


### function normal

```cpp
void normal(
    datatype dtype,
    void * buff,
    const std::size_t N,
    const cumeric_t sigma,
    std::size_t seed =2137
)
```

Generates normally distributed random values (zero mean) into a generic buffer with scalar standard deviation. 

**Parameters**: 

  * **dtype** Runtime datatype tag of elements in the buffer. 
  * **buff** Destination memory buffer. 
  * **N** Number of elements to generate. 
  * **sigma** Standard deviation of the normal distribution. 
  * **seed** Random generator seed (default 2137). 


### function normal

```cpp
void normal(
    datatype dtype,
    void * buff,
    const std::size_t N,
    const void * sigma,
    std::size_t seed =2137
)
```

Generates normally distributed random values into a generic buffer with a pointer to standard deviation. 

**Parameters**: 

  * **dtype** Runtime datatype tag of elements in the buffer. 
  * **buff** Destination memory buffer. 
  * **N** Number of elements to generate. 
  * **sigma** Pointer to standard deviation value in the matching datatype. 
  * **seed** Random generator seed (default 2137). 






-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100