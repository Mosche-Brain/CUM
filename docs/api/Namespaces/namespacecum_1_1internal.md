---
title: cum::internal

---

# cum::internal



## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::internal::Context](Classes/structcum_1_1internal_1_1Context.md)** <br>Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends.  |
| struct | **[cum::internal::scalar_buffer](Classes/structcum_1_1internal_1_1scalar__buffer.md)**  |
| struct | **[cum::internal::sycl_type_map](Classes/structcum_1_1internal_1_1sycl__type__map.md)**  |
| struct | **[cum::internal::sycl_type_map< bfloat16 >](Classes/structcum_1_1internal_1_1sycl__type__map_3_01bfloat16_01_4.md)**  |
| struct | **[cum::internal::sycl_type_map< float16 >](Classes/structcum_1_1internal_1_1sycl__type__map_3_01float16_01_4.md)**  |

## Types

|                | Name           |
| -------------- | -------------- |
| template <typename T \> <br>using typename [sycl_type_map](Classes/structcum_1_1internal_1_1sycl__type__map.md)< T >::type | **[sycl_type_t](Namespaces/namespacecum_1_1internal.md#using-sycl-type-t)**  |
| template <typename SyclT \> <br>using std::conditional_t< std::is_same_v< SyclT, double >, double, float > | **[math_compute_t](Namespaces/namespacecum_1_1internal.md#using-math-compute-t)**  |
| template <typename SyclT \> <br>using std::conditional_t< std::is_integral_v< SyclT >, SyclT, std::conditional_t< std::is_same_v< SyclT, double >, double, float > > | **[blas_compute_t](Namespaces/namespacecum_1_1internal.md#using-blas-compute-t)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| [Context](Classes/structcum_1_1internal_1_1Context.md) & | **[context](Namespaces/namespacecum_1_1internal.md#function-context)**([DEVICE](Namespaces/namespacecum.md#enum-device) device =[DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto))<br>Returns reference to thread-safe global context instance.  |
| sycl::context & | **[getSyclContext](Namespaces/namespacecum_1_1internal.md#function-getsyclcontext)**() |
| sycl::device & | **[device](Namespaces/namespacecum_1_1internal.md#function-device)**() |
| sycl::queue & | **[getQueue](Namespaces/namespacecum_1_1internal.md#function-getqueue)**() |
| dnnl::engine & | **[getEngine](Namespaces/namespacecum_1_1internal.md#function-getengine)**() |
| dnnl::stream & | **[getStream](Namespaces/namespacecum_1_1internal.md#function-getstream)**() |
| oneapi::mkl::rng::device::philox4x32x10< 1 > & | **[getRNG](Namespaces/namespacecum_1_1internal.md#function-getrng)**() |
| cumeric_t * | **[getZeros](Namespaces/namespacecum_1_1internal.md#function-getzeros)**() |
| cumeric_t * | **[getOnes](Namespaces/namespacecum_1_1internal.md#function-getones)**() |
| const cumeric_t * | **[zeros](Namespaces/namespacecum_1_1internal.md#function-zeros)**() |
| const cumeric_t * | **[ones](Namespaces/namespacecum_1_1internal.md#function-ones)**() |
| cumeric_t * | **[cache](Namespaces/namespacecum_1_1internal.md#function-cache)**() |
| sycl::context & | **[sycl_context](Namespaces/namespacecum_1_1internal.md#function-sycl-context)**() |
| sycl::queue & | **[queue](Namespaces/namespacecum_1_1internal.md#function-queue)**() |
| dnnl::engine & | **[engine](Namespaces/namespacecum_1_1internal.md#function-engine)**() |
| dnnl::stream & | **[stream](Namespaces/namespacecum_1_1internal.md#function-stream)**() |
| template <typename F \> <br>decltype(auto) | **[dispatch_sycl_datatype](Namespaces/namespacecum_1_1internal.md#function-dispatch-sycl-datatype)**([datatype](Namespaces/namespacecum.md#enum-datatype) dt, F && f)<br>Dispatches runtime datatype to compile-time SYCL mapped type.  |
| template <typename MklCall ,typename FallbackOp \> <br>[__event__](Namespaces/namespacecum.md#using---event--) | **[dispatch_vm_binary](Namespaces/namespacecum_1_1internal.md#function-dispatch-vm-binary)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const void * u, const [dim_t](Namespaces/namespacecum.md#using-dim-t) n, MklCall && mkl_call, FallbackOp && fallback_op)<br>Dispatches binary vector-matrix or elementwise operations to oneMKL or SYCL fallback kernel.  |
| template <typename MklCall ,typename FallbackOp \> <br>[__event__](Namespaces/namespacecum.md#using---event--) | **[dispatch_vm_binary_batch](Namespaces/namespacecum_1_1internal.md#function-dispatch-vm-binary-batch)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_r, const void * v, const [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_v, const void * u, const [dim_t](Namespaces/namespacecum.md#using-dim-t) stride_u, const [dim_t](Namespaces/namespacecum.md#using-dim-t) n, const [dim_t](Namespaces/namespacecum.md#using-dim-t) batch_size, MklCall && mkl_call, FallbackOp && fallback_op)<br>Dispatches batched binary operations to oneMKL or 2D parallel_for SYCL fallback kernel.  |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[blas_vec_index](Namespaces/namespacecum_1_1internal.md#function-blas-vec-index)**([dim_t](Namespaces/namespacecum.md#using-dim-t) i, [dim_t](Namespaces/namespacecum.md#using-dim-t) n, [dim_t](Namespaces/namespacecum.md#using-dim-t) inc) |
| [scalar_buffer](Classes/structcum_1_1internal_1_1scalar__buffer.md) | **[to_scalar_buffer](Namespaces/namespacecum_1_1internal.md#function-to-scalar-buffer)**([datatype](Namespaces/namespacecum.md#enum-datatype) dt, cumeric_t val) |
| oneapi::mkl::transpose | **[to_mkl_transpose](Namespaces/namespacecum_1_1internal.md#function-to-mkl-transpose)**(char c) |
| oneapi::mkl::uplo | **[to_mkl_uplo](Namespaces/namespacecum_1_1internal.md#function-to-mkl-uplo)**(char c) |
| oneapi::mkl::diag | **[to_mkl_diag](Namespaces/namespacecum_1_1internal.md#function-to-mkl-diag)**(char c) |
| oneapi::mkl::side | **[to_mkl_side](Namespaces/namespacecum_1_1internal.md#function-to-mkl-side)**(char c) |
| template <typename MklCall ,typename FallbackOp \> <br>[__event__](Namespaces/namespacecum.md#using---event--) | **[dispatch_vm_unary](Namespaces/namespacecum_1_1internal.md#function-dispatch-vm-unary)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const std::size_t n, MklCall && mkl_call, FallbackOp && fallback_op)<br>Dispatches unary vector operations to oneMKL or 1D parallel_for SYCL fallback kernel.  |
| template <typename Op \> <br>[__event__](Namespaces/namespacecum.md#using---event--) | **[dispatch_unary_math](Namespaces/namespacecum_1_1internal.md#function-dispatch-unary-math)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype, void * r, const void * v, const std::size_t n, Op && op)<br>Dispatches generic unary mathematical functor across array elements using SYCL parallel_for.  |

## Types Documentation

### using sycl_type_t

```cpp
template <typename T >
using cum::internal::sycl_type_t = typename sycl_type_map<T>::type;
```


### using math_compute_t

```cpp
template <typename SyclT >
using cum::internal::math_compute_t = std::conditional_t<std::is_same_v<SyclT, double>, double, float>;
```


### using blas_compute_t

```cpp
template <typename SyclT >
using cum::internal::blas_compute_t = std::conditional_t<
       std::is_integral_v<SyclT>,
       SyclT,
       std::conditional_t<std::is_same_v<SyclT, double>, double, float>>;
```



## Functions Documentation

### function context

```cpp
Context & context(
    DEVICE device =DEVICE::AUTO
)
```

Returns reference to thread-safe global context instance. 

**Parameters**: 

  * **device** Target device. 


**Return**: [Context](Classes/structcum_1_1internal_1_1Context.md) reference. 

### function getSyclContext

```cpp
sycl::context & getSyclContext()
```


### function device

```cpp
sycl::device & device()
```


### function getQueue

```cpp
sycl::queue & getQueue()
```


### function getEngine

```cpp
dnnl::engine & getEngine()
```


### function getStream

```cpp
dnnl::stream & getStream()
```


### function getRNG

```cpp
oneapi::mkl::rng::device::philox4x32x10< 1 > & getRNG()
```


### function getZeros

```cpp
cumeric_t * getZeros()
```


### function getOnes

```cpp
cumeric_t * getOnes()
```


### function zeros

```cpp
const cumeric_t * zeros()
```


### function ones

```cpp
const cumeric_t * ones()
```


### function cache

```cpp
cumeric_t * cache()
```


### function sycl_context

```cpp
sycl::context & sycl_context()
```


### function queue

```cpp
sycl::queue & queue()
```


### function engine

```cpp
dnnl::engine & engine()
```


### function stream

```cpp
dnnl::stream & stream()
```


### function dispatch_sycl_datatype

```cpp
template <typename F >
decltype(auto) dispatch_sycl_datatype(
    datatype dt,
    F && f
)
```

Dispatches runtime datatype to compile-time SYCL mapped type. 

**Parameters**: 

  * **dt** Runtime datatype tag. 
  * **f** Functor called with mapped SYCL type (e.g. sycl::half). 


**Template Parameters**: 

  * **F** Generic functor type. 


**Return**: Result of invoking functor f. 

### function dispatch_vm_binary

```cpp
template <typename MklCall ,
typename FallbackOp >
__event__ dispatch_vm_binary(
    datatype dtype,
    void * r,
    const void * v,
    const void * u,
    const dim_t n,
    MklCall && mkl_call,
    FallbackOp && fallback_op
)
```

Dispatches binary vector-matrix or elementwise operations to oneMKL or SYCL fallback kernel. 

### function dispatch_vm_binary_batch

```cpp
template <typename MklCall ,
typename FallbackOp >
__event__ dispatch_vm_binary_batch(
    datatype dtype,
    void * r,
    const dim_t stride_r,
    const void * v,
    const dim_t stride_v,
    const void * u,
    const dim_t stride_u,
    const dim_t n,
    const dim_t batch_size,
    MklCall && mkl_call,
    FallbackOp && fallback_op
)
```

Dispatches batched binary operations to oneMKL or 2D parallel_for SYCL fallback kernel. 

### function blas_vec_index

```cpp
dim_t blas_vec_index(
    dim_t i,
    dim_t n,
    dim_t inc
)
```


### function to_scalar_buffer

```cpp
inline scalar_buffer to_scalar_buffer(
    datatype dt,
    cumeric_t val
)
```


### function to_mkl_transpose

```cpp
oneapi::mkl::transpose to_mkl_transpose(
    char c
)
```


### function to_mkl_uplo

```cpp
oneapi::mkl::uplo to_mkl_uplo(
    char c
)
```


### function to_mkl_diag

```cpp
oneapi::mkl::diag to_mkl_diag(
    char c
)
```


### function to_mkl_side

```cpp
oneapi::mkl::side to_mkl_side(
    char c
)
```


### function dispatch_vm_unary

```cpp
template <typename MklCall ,
typename FallbackOp >
__event__ dispatch_vm_unary(
    datatype dtype,
    void * r,
    const void * v,
    const std::size_t n,
    MklCall && mkl_call,
    FallbackOp && fallback_op
)
```

Dispatches unary vector operations to oneMKL or 1D parallel_for SYCL fallback kernel. 

### function dispatch_unary_math

```cpp
template <typename Op >
__event__ dispatch_unary_math(
    datatype dtype,
    void * r,
    const void * v,
    const std::size_t n,
    Op && op
)
```

Dispatches generic unary mathematical functor across array elements using SYCL parallel_for. 





-------------------------------

Updated on 2026-10-31 at 18:07:41 +0100