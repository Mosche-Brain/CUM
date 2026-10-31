---
title: cum

---

# cum



## Namespaces

| Name           |
| -------------- |
| **[cum::blas](Namespaces/namespacecum_1_1blas.md)**  |
| **[cum::detail](Namespaces/namespacecum_1_1detail.md)**  |
| **[cum::experimental](Namespaces/namespacecum_1_1experimental.md)**  |
| **[cum::functions](Namespaces/namespacecum_1_1functions.md)**  |
| **[cum::internal](Namespaces/namespacecum_1_1internal.md)**  |
| **[cum::lara](Namespaces/namespacecum_1_1lara.md)**  |
| **[cum::memory](Namespaces/namespacecum_1_1memory.md)**  |
| **[cum::neural_primitives](Namespaces/namespacecum_1_1neural__primitives.md)**  |
| **[cum::random](Namespaces/namespacecum_1_1random.md)**  |
| **[cum::runtime](Namespaces/namespacecum_1_1runtime.md)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cum::bfloat16](Classes/structcum_1_1bfloat16.md)** <br>Raw 16-bit fallback for [bfloat16]() precision float.  |
| struct | **[cum::datatype_of](Classes/structcum_1_1datatype__of.md)** <br>Type trait mapping a static C++ type to its runtime [datatype](Namespaces/namespacecum.md#enum-datatype) enum tag.  |
| struct | **[cum::datatype_of< cum::bfloat16 >](Classes/structcum_1_1datatype__of_3_01cum_1_1bfloat16_01_4.md)**  |
| struct | **[cum::datatype_of< cum::float16 >](Classes/structcum_1_1datatype__of_3_01cum_1_1float16_01_4.md)**  |
| struct | **[cum::datatype_of< cum::float8 >](Classes/structcum_1_1datatype__of_3_01cum_1_1float8_01_4.md)**  |
| struct | **[cum::datatype_of< double >](Classes/structcum_1_1datatype__of_3_01double_01_4.md)**  |
| struct | **[cum::datatype_of< float >](Classes/structcum_1_1datatype__of_3_01float_01_4.md)**  |
| struct | **[cum::datatype_of< std::int16_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int16__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::int32_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int32__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::int64_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int64__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::int8_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int8__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::uint16_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint16__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::uint32_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint32__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::uint64_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint64__t_01_4.md)**  |
| struct | **[cum::datatype_of< std::uint8_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint8__t_01_4.md)**  |
| struct | **[cum::float16](Classes/structcum_1_1float16.md)** <br>Raw 16-bit fallback for half precision float.  |
| class | **[cum::Matrix](Classes/classcum_1_1Matrix.md)** <br>Templated generic dense matrix.  |
| class | **[cum::MatrixView](Classes/classcum_1_1MatrixView.md)** <br>Lightweight, non-owning read view over a 2D matrix or existing data buffer.  |
| class | **[cum::Tensor](Classes/classcum_1_1Tensor.md)** <br>Core N-dimensional array and deep learning tensor.  |
| class | **[cum::Vector](Classes/classcum_1_1Vector.md)** <br>Templated generic 1D dense vector.  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[DEVICE](Namespaces/namespacecum.md#enum-device)** { AUTO, CPU, GPU}<br>Target compute hardware accelerator or processing unit.  |
| enum class uint8_t | **[datatype](Namespaces/namespacecum.md#enum-datatype)** { FP64, FP32, FP16, BF16, FP8, S64, S32, S16, S8, U64, U32, U16, U8, UNDEF}<br>Runtime enumeration tags for supported numeric types.  |
| enum class unsigned char | **[layout](Namespaces/namespacecum.md#enum-layout)** { UNDEF, ANY, A, AB, BA, ABC, ACB, BAC, BCA, CBA, ABCD, ABDC, ACBD, ACDB, ADBC, BACD, BCDA, CDBA, DCAB, ABCDE, ABDEC, ACBDE, ACDEB, BACDE, BCDEA, CDEBA, DECAB, ABCED, ABCDEF, ABDFCE, ACBDEF, ABDEFC, DEFCAB, ABCDFE, ABCDEFG, ABCDEGF, ABCDEFGH, ABCDEFHG, ABCDEFGHI, ABCDEFGIH, ABCDEFGHIJ, ABCDEFGHJI, ABCDEFGHIJK, ABCDEFGHIKJ, ABCDEFGHIJKL, ABCDEFGHIJLK, X = A, NC = AB, CN = BA, NCW = ABC, NWC = ACB, NCHW = ABCD, NHWC = ACDB, CHWN = BCDA, NCDHW = ABCDE, NDHWC = ACDEB, OI = AB, IO = BA, OIW = ABC, OWI = ACB, WIO = CBA, IWO = BCA, OIHW = ABCD, HWIO = CDBA, OHWI = ACDB, IHWO = BCDA, IOHW = BACD, OIDHW = ABCDE, DHWIO = CDEBA, ODHWI = ACDEB, IODHW = BACDE, IDHWO = BCDEA, GOIW = ABCD, GOWI = ABDC, WIGO = DCAB, GOHWI = ABDEC, GOIHW = ABCDE, HWIGO = DECAB, GIOHW = ACBDE, GOIDHW = ABCDEF, GIODHW = ACBDEF, GODHWI = ABDEFC, DHWIGO = DEFCAB, TN = AB, NT = BA, TNC = ABC, NTC = BAC, LDNC = ABCD, LDIGO = ABCDE, LDGOI = ABDEC, LDIO = ABCD, LDOI = ABDC, LDGO = ABCD}<br>Memory layout and dimension permutation tags for multi-dimensional tensors.  |
| enum| **[MemoryAlingment](Namespaces/namespacecum.md#enum-memoryalingment)** { RowMajor, ColMajor}<br>Memory storage ordering (RowMajor vs ColMajor).  |
| using [experimental::__event__](Classes/classcum_1_1experimental_1_1____event____.md) | **[__event__](Namespaces/namespacecum.md#using---event--)** <br>Asynchronous execution event handle alias.  |
| using std::vector< std::reference_wrapper< [__event__](Namespaces/namespacecum.md#using---event--) > > | **[__events__](Namespaces/namespacecum.md#using---events--)** <br>Collection of references to dependent asynchronous events.  |
| using std::int64_t | **[dim_t](Namespaces/namespacecum.md#using-dim-t)** <br>Fundamental signed integer type for dimensions, sizes, and indexing.  |
| using std::vector< [dim_t](Namespaces/namespacecum.md#using-dim-t) > | **[Shape](Namespaces/namespacecum.md#using-shape)** <br>[Shape]() vector representing multi-dimensional tensor dimensions.  |
| using std::vector< [dim_t](Namespaces/namespacecum.md#using-dim-t) > | **[Dims](Namespaces/namespacecum.md#using-dims)** <br>Dimension vector alias for [Shape](Namespaces/namespacecum.md#using-shape).  |
| using double | **[float64](Namespaces/namespacecum.md#using-float64)** <br>64-bit double precision float alias.  |
| using float | **[float32](Namespaces/namespacecum.md#using-float32)** <br>32-bit single precision float alias.  |
| using [fp8_e4_3m_impl](Classes/structfp8__e4__3m__impl.md) | **[float8](Namespaces/namespacecum.md#using-float8)** <br>8-bit floating point alias.  |
| using signed long long | **[int64](Namespaces/namespacecum.md#using-int64)** <br>Signed 64-bit integer alias.  |
| using signed int | **[int32](Namespaces/namespacecum.md#using-int32)** <br>Signed 32-bit integer alias.  |
| using signed short | **[int16](Namespaces/namespacecum.md#using-int16)** <br>Signed 16-bit integer alias.  |
| using signed char | **[int8](Namespaces/namespacecum.md#using-int8)** <br>Signed 8-bit integer alias.  |
| using unsigned long long | **[uint64](Namespaces/namespacecum.md#using-uint64)** <br>Unsigned 64-bit integer alias.  |
| using unsigned int | **[uint32](Namespaces/namespacecum.md#using-uint32)** <br>Unsigned 32-bit integer alias.  |
| using unsigned short | **[uint16](Namespaces/namespacecum.md#using-uint16)** <br>Unsigned 16-bit integer alias.  |
| using unsigned char | **[uint8](Namespaces/namespacecum.md#using-uint8)** <br>Unsigned 8-bit integer alias.  |
| using [float64](Namespaces/namespacecum.md#using-float64) | **[f64](Namespaces/namespacecum.md#using-f64)** <br>Short alias for [float64](Namespaces/namespacecum.md#using-float64).  |
| using [float32](Namespaces/namespacecum.md#using-float32) | **[f32](Namespaces/namespacecum.md#using-f32)** <br>Short alias for [float32](Namespaces/namespacecum.md#using-float32).  |
| using [float16](Classes/structcum_1_1float16.md) | **[f16](Namespaces/namespacecum.md#using-f16)** <br>Short alias for [float16]().  |
| using [bfloat16](Classes/structcum_1_1bfloat16.md) | **[bf16](Namespaces/namespacecum.md#using-bf16)** <br>Short alias for [bfloat16]().  |
| using [float8](Namespaces/namespacecum.md#using-float8) | **[f8](Namespaces/namespacecum.md#using-f8)** <br>Short alias for [float8](Namespaces/namespacecum.md#using-float8).  |
| using [int64](Namespaces/namespacecum.md#using-int64) | **[i64](Namespaces/namespacecum.md#using-i64)** <br>Short alias for [int64](Namespaces/namespacecum.md#using-int64).  |
| using [int32](Namespaces/namespacecum.md#using-int32) | **[i32](Namespaces/namespacecum.md#using-i32)** <br>Short alias for [int32](Namespaces/namespacecum.md#using-int32).  |
| using [int16](Namespaces/namespacecum.md#using-int16) | **[i16](Namespaces/namespacecum.md#using-i16)** <br>Short alias for [int16](Namespaces/namespacecum.md#using-int16).  |
| using [int8](Namespaces/namespacecum.md#using-int8) | **[i8](Namespaces/namespacecum.md#using-i8)** <br>Short alias for [int8](Namespaces/namespacecum.md#using-int8).  |
| using [uint64](Namespaces/namespacecum.md#using-uint64) | **[u64](Namespaces/namespacecum.md#using-u64)** <br>Short alias for [uint64](Namespaces/namespacecum.md#using-uint64).  |
| using [uint32](Namespaces/namespacecum.md#using-uint32) | **[u32](Namespaces/namespacecum.md#using-u32)** <br>Short alias for [uint32](Namespaces/namespacecum.md#using-uint32).  |
| using [uint16](Namespaces/namespacecum.md#using-uint16) | **[u16](Namespaces/namespacecum.md#using-u16)** <br>Short alias for [uint16](Namespaces/namespacecum.md#using-uint16).  |
| using [uint8](Namespaces/namespacecum.md#using-uint8) | **[u8](Namespaces/namespacecum.md#using-u8)** <br>Short alias for [uint8](Namespaces/namespacecum.md#using-uint8).  |
| using [uint8](Namespaces/namespacecum.md#using-uint8) | **[byte](Namespaces/namespacecum.md#using-byte)** <br>8-bit byte alias.  |
| using [Vector](Classes/classcum_1_1Vector.md)< int, 2 > | **[ivec2](Namespaces/namespacecum.md#using-ivec2)** <br>2-element integer vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< int, 3 > | **[ivec3](Namespaces/namespacecum.md#using-ivec3)** <br>3-element integer vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< int, 4 > | **[ivec4](Namespaces/namespacecum.md#using-ivec4)** <br>4-element integer vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float32](Namespaces/namespacecum.md#using-float32), 2 > | **[fvec2](Namespaces/namespacecum.md#using-fvec2)** <br>2-element single-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float32](Namespaces/namespacecum.md#using-float32), 3 > | **[fvec3](Namespaces/namespacecum.md#using-fvec3)** <br>3-element single-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float32](Namespaces/namespacecum.md#using-float32), 4 > | **[fvec4](Namespaces/namespacecum.md#using-fvec4)** <br>4-element single-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float64](Namespaces/namespacecum.md#using-float64), 2 > | **[dvec2](Namespaces/namespacecum.md#using-dvec2)** <br>2-element double-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float64](Namespaces/namespacecum.md#using-float64), 3 > | **[dvec3](Namespaces/namespacecum.md#using-dvec3)** <br>3-element double-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float64](Namespaces/namespacecum.md#using-float64), 4 > | **[dvec4](Namespaces/namespacecum.md#using-dvec4)** <br>4-element double-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float16](Classes/structcum_1_1float16.md), 2 > | **[hvec2](Namespaces/namespacecum.md#using-hvec2)** <br>2-element half-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float16](Classes/structcum_1_1float16.md), 3 > | **[hvec3](Namespaces/namespacecum.md#using-hvec3)** <br>3-element half-precision float vector.  |
| using [Vector](Classes/classcum_1_1Vector.md)< [float16](Classes/structcum_1_1float16.md), 4 > | **[hvec4](Namespaces/namespacecum.md#using-hvec4)** <br>4-element half-precision float vector.  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename T ,typename F \> <br>decltype(auto) | **[invoke_or_ub](Namespaces/namespacecum.md#function-invoke-or-ub)**(F && f)<br>Invokes a generic functor instantiated with type `T`, or triggers undefined behavior path.  |
| template <typename F \> <br>decltype(auto) | **[dispatch_datatype](Namespaces/namespacecum.md#function-dispatch-datatype)**([datatype](Namespaces/namespacecum.md#enum-datatype) dt, F && f)<br>Runtime-to-compile-time datatype dispatcher.  |
| void | **[cum](Namespaces/namespacecum.md#function-cum)**([DEVICE](Namespaces/namespacecum.md#enum-device) device =[DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto))<br>Initializes the CUM library context for the specified compute device.  |
| void | **[recum](Namespaces/namespacecum.md#function-recum)**([DEVICE](Namespaces/namespacecum.md#enum-device) device =[DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto))<br>Reinitializes or switches the CUM library context to another compute device.  |
| void | **[decum](Namespaces/namespacecum.md#function-decum)**()<br>Finalizes and cleans up the CUM library runtime and allocated context resources.  |
| std::size_t | **[datatype_size](Namespaces/namespacecum.md#function-datatype-size)**([datatype](Namespaces/namespacecum.md#enum-datatype) type)<br>Computes the byte size of a specified runtime datatype tag.  |
| template <typename T \> <br>[datatype](Namespaces/namespacecum.md#enum-datatype) | **[type_tag](Namespaces/namespacecum.md#function-type-tag)**()<br>Resolves the runtime datatype tag corresponding to compile-time type `T`.  |
| dnnl::algorithm | **[dnnl_algorithm](Namespaces/namespacecum.md#function-dnnl-algorithm)**([functions::function_id](Namespaces/namespacecum_1_1functions.md#enum-function-id) id)<br>Converts CUM [functions::function_id]() to oneDNN algorithm enumeration.  |
| dnnl::memory::data_type | **[dnnl_data_type](Namespaces/namespacecum.md#function-dnnl-data-type)**([datatype](Namespaces/namespacecum.md#enum-datatype) dtype)<br>Converts CUM [datatype](Namespaces/namespacecum.md#enum-datatype) tag to oneDNN memory data_type.  |
| [datatype](Namespaces/namespacecum.md#enum-datatype) | **[cum_data_type](Namespaces/namespacecum.md#function-cum-data-type)**(dnnl::memory::data_type dtype)<br>Converts oneDNN memory data_type to CUM [datatype](Namespaces/namespacecum.md#enum-datatype) tag.  |
| dnnl::memory::format_tag | **[dnnl_format_tag](Namespaces/namespacecum.md#function-dnnl-format-tag)**([layout](Namespaces/namespacecum.md#enum-layout) format)<br>Converts CUM [layout](Namespaces/namespacecum.md#enum-layout) tag to oneDNN format_tag.  |
| [layout](Namespaces/namespacecum.md#enum-layout) | **[cum_format_tag](Namespaces/namespacecum.md#function-cum-format-tag)**(dnnl::memory::format_tag format)<br>Converts oneDNN format_tag to CUM [layout](Namespaces/namespacecum.md#enum-layout) tag.  |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > | **[operator+](Namespaces/namespacecum.md#function-operator+)**(const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > rhs) const |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > | **[operator-](Namespaces/namespacecum.md#function-operator-)**(const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > rhs) const |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > | **[operator*](Namespaces/namespacecum.md#function-operator*)**(const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > rhs) const |
| template <typename T ,dim_t rows_,dim_t cols_\> <br>[Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > | **[operator/](Namespaces/namespacecum.md#function-operator/)**(const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > & lhs, const [Matrix](Classes/classcum_1_1Matrix.md)< T, rows_, cols_ > rhs) const |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator+](Namespaces/namespacecum.md#function-operator+)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & rhs) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator-](Namespaces/namespacecum.md#function-operator-)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & rhs) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator*](Namespaces/namespacecum.md#function-operator*)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & rhs) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator/](Namespaces/namespacecum.md#function-operator/)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & rhs) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator*](Namespaces/namespacecum.md#function-operator*)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const std::type_identity_t< T > scalar) |
| template <typename T ,dim_t length_\> <br>[Vector](Classes/classcum_1_1Vector.md)< T, length_ > | **[operator/](Namespaces/namespacecum.md#function-operator/)**(const [Vector](Classes/classcum_1_1Vector.md)< T, length_ > & lhs, const std::type_identity_t< T > scalar) |

## Attributes

|                | Name           |
| -------------- | -------------- |
| [dim_t](Namespaces/namespacecum.md#using-dim-t) | **[Dynamic](Namespaces/namespacecum.md#variable-dynamic)** <br>Sentinel constant indicating dynamic (runtime) dimension sizing.  |

## Types Documentation

### enum DEVICE

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| AUTO | | Automatically select the best available device (GPU preferred, CPU fallback).   |
| CPU | | Host CPU execution.   |
| GPU | | GPU accelerator execution.   |



Target compute hardware accelerator or processing unit. 

### enum datatype

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| FP64 | | 64-bit IEEE double precision float.   |
| FP32 | | 32-bit IEEE single precision float.   |
| FP16 | | 16-bit IEEE half precision float.   |
| BF16 | | 16-bit Brain floating point format.   |
| FP8 | | 8-bit floating point format.   |
| S64 | | Signed 64-bit integer.   |
| S32 | | Signed 32-bit integer.   |
| S16 | | Signed 16-bit integer.   |
| S8 | | Signed 8-bit integer.   |
| U64 | | Unsigned 64-bit integer.   |
| U32 | | Unsigned 32-bit integer.   |
| U16 | | Unsigned 16-bit integer.   |
| U8 | | Unsigned 8-bit integer.   |
| UNDEF | | Undefined / uninitialized datatype.   |



Runtime enumeration tags for supported numeric types. 

### enum layout

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| UNDEF | | Undefined layout format.   |
| ANY | | Flexible/unspecified layout (chosen automatically by engine for performance).   |
| A | | 1D contiguous layout.   |
| AB | | 2D Row-Major format.   |
| BA | | 2D Column-Major format.   |
| ABC | |   |
| ACB | |   |
| BAC | |   |
| BCA | |   |
| CBA | |   |
| ABCD | |   |
| ABDC | |   |
| ACBD | |   |
| ACDB | |   |
| ADBC | |   |
| BACD | |   |
| BCDA | |   |
| CDBA | |   |
| DCAB | |   |
| ABCDE | |   |
| ABDEC | |   |
| ACBDE | |   |
| ACDEB | |   |
| BACDE | |   |
| BCDEA | |   |
| CDEBA | |   |
| DECAB | |   |
| ABCED | |   |
| ABCDEF | |   |
| ABDFCE | |   |
| ACBDEF | |   |
| ABDEFC | |   |
| DEFCAB | |   |
| ABCDFE | |   |
| ABCDEFG | |   |
| ABCDEGF | |   |
| ABCDEFGH | |   |
| ABCDEFHG | |   |
| ABCDEFGHI | |   |
| ABCDEFGIH | |   |
| ABCDEFGHIJ | |   |
| ABCDEFGHJI | |   |
| ABCDEFGHIJK | |   |
| ABCDEFGHIKJ | |   |
| ABCDEFGHIJKL | |   |
| ABCDEFGHIJLK | |   |
| X | A|   |
| NC | AB|   |
| CN | BA|   |
| NCW | ABC|   |
| NWC | ACB|   |
| NCHW | ABCD|   |
| NHWC | ACDB|   |
| CHWN | BCDA|   |
| NCDHW | ABCDE|   |
| NDHWC | ACDEB|   |
| OI | AB|   |
| IO | BA|   |
| OIW | ABC|   |
| OWI | ACB|   |
| WIO | CBA|   |
| IWO | BCA|   |
| OIHW | ABCD|   |
| HWIO | CDBA|   |
| OHWI | ACDB|   |
| IHWO | BCDA|   |
| IOHW | BACD|   |
| OIDHW | ABCDE|   |
| DHWIO | CDEBA|   |
| ODHWI | ACDEB|   |
| IODHW | BACDE|   |
| IDHWO | BCDEA|   |
| GOIW | ABCD|   |
| GOWI | ABDC|   |
| WIGO | DCAB|   |
| GOHWI | ABDEC|   |
| GOIHW | ABCDE|   |
| HWIGO | DECAB|   |
| GIOHW | ACBDE|   |
| GOIDHW | ABCDEF|   |
| GIODHW | ACBDEF|   |
| GODHWI | ABDEFC|   |
| DHWIGO | DEFCAB|   |
| TN | AB|   |
| NT | BA|   |
| TNC | ABC|   |
| NTC | BAC|   |
| LDNC | ABCD|   |
| LDIGO | ABCDE|   |
| LDGOI | ABDEC|   |
| LDIO | ABCD|   |
| LDOI | ABDC|   |
| LDGO | ABCD|   |



Memory layout and dimension permutation tags for multi-dimensional tensors. 

### enum MemoryAlingment

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| RowMajor | |   |
| ColMajor | |   |



Memory storage ordering (RowMajor vs ColMajor). 

### using __event__

```cpp
using cum::__event__ = experimental::__event__;
```

Asynchronous execution event handle alias. 

### using __events__

```cpp
using cum::__events__ = std::vector<std::reference_wrapper<__event__>>;
```

Collection of references to dependent asynchronous events. 

### using dim_t

```cpp
using cum::dim_t = std::int64_t;
```

Fundamental signed integer type for dimensions, sizes, and indexing. 

### using Shape

```cpp
using cum::Shape = std::vector<dim_t>;
```

[Shape]() vector representing multi-dimensional tensor dimensions. 

### using Dims

```cpp
using cum::Dims = std::vector<dim_t>;
```

Dimension vector alias for [Shape](Namespaces/namespacecum.md#using-shape). 

### using float64

```cpp
using cum::float64 = double;
```

64-bit double precision float alias. 

### using float32

```cpp
using cum::float32 = float;
```

32-bit single precision float alias. 

### using float8

```cpp
using cum::float8 = fp8_e4_3m_impl;
```

8-bit floating point alias. 

### using int64

```cpp
using cum::int64 = signed long long;
```

Signed 64-bit integer alias. 

### using int32

```cpp
using cum::int32 = signed int;
```

Signed 32-bit integer alias. 

### using int16

```cpp
using cum::int16 = signed short;
```

Signed 16-bit integer alias. 

### using int8

```cpp
using cum::int8 = signed char;
```

Signed 8-bit integer alias. 

### using uint64

```cpp
using cum::uint64 = unsigned long long;
```

Unsigned 64-bit integer alias. 

### using uint32

```cpp
using cum::uint32 = unsigned int;
```

Unsigned 32-bit integer alias. 

### using uint16

```cpp
using cum::uint16 = unsigned short;
```

Unsigned 16-bit integer alias. 

### using uint8

```cpp
using cum::uint8 = unsigned char;
```

Unsigned 8-bit integer alias. 

### using f64

```cpp
using cum::f64 = float64;
```

Short alias for [float64](Namespaces/namespacecum.md#using-float64). 

### using f32

```cpp
using cum::f32 = float32;
```

Short alias for [float32](Namespaces/namespacecum.md#using-float32). 

### using f16

```cpp
using cum::f16 = float16;
```

Short alias for [float16](). 

### using bf16

```cpp
using cum::bf16 = bfloat16;
```

Short alias for [bfloat16](). 

### using f8

```cpp
using cum::f8 = float8;
```

Short alias for [float8](Namespaces/namespacecum.md#using-float8). 

### using i64

```cpp
using cum::i64 = int64;
```

Short alias for [int64](Namespaces/namespacecum.md#using-int64). 

### using i32

```cpp
using cum::i32 = int32;
```

Short alias for [int32](Namespaces/namespacecum.md#using-int32). 

### using i16

```cpp
using cum::i16 = int16;
```

Short alias for [int16](Namespaces/namespacecum.md#using-int16). 

### using i8

```cpp
using cum::i8 = int8;
```

Short alias for [int8](Namespaces/namespacecum.md#using-int8). 

### using u64

```cpp
using cum::u64 = uint64;
```

Short alias for [uint64](Namespaces/namespacecum.md#using-uint64). 

### using u32

```cpp
using cum::u32 = uint32;
```

Short alias for [uint32](Namespaces/namespacecum.md#using-uint32). 

### using u16

```cpp
using cum::u16 = uint16;
```

Short alias for [uint16](Namespaces/namespacecum.md#using-uint16). 

### using u8

```cpp
using cum::u8 = uint8;
```

Short alias for [uint8](Namespaces/namespacecum.md#using-uint8). 

### using byte

```cpp
using cum::byte = uint8;
```

8-bit byte alias. 

### using ivec2

```cpp
using cum::ivec2 = Vector<int, 2>;
```

2-element integer vector. 

### using ivec3

```cpp
using cum::ivec3 = Vector<int, 3>;
```

3-element integer vector. 

### using ivec4

```cpp
using cum::ivec4 = Vector<int, 4>;
```

4-element integer vector. 

### using fvec2

```cpp
using cum::fvec2 = Vector<float32, 2>;
```

2-element single-precision float vector. 

### using fvec3

```cpp
using cum::fvec3 = Vector<float32, 3>;
```

3-element single-precision float vector. 

### using fvec4

```cpp
using cum::fvec4 = Vector<float32, 4>;
```

4-element single-precision float vector. 

### using dvec2

```cpp
using cum::dvec2 = Vector<float64, 2>;
```

2-element double-precision float vector. 

### using dvec3

```cpp
using cum::dvec3 = Vector<float64, 3>;
```

3-element double-precision float vector. 

### using dvec4

```cpp
using cum::dvec4 = Vector<float64, 4>;
```

4-element double-precision float vector. 

### using hvec2

```cpp
using cum::hvec2 = Vector<float16, 2>;
```

2-element half-precision float vector. 

### using hvec3

```cpp
using cum::hvec3 = Vector<float16, 3>;
```

3-element half-precision float vector. 

### using hvec4

```cpp
using cum::hvec4 = Vector<float16, 4>;
```

4-element half-precision float vector. 


## Functions Documentation

### function invoke_or_ub

```cpp
template <typename T ,
typename F >
decltype(auto) invoke_or_ub(
    F && f
)
```

Invokes a generic functor instantiated with type `T`, or triggers undefined behavior path. 

**Parameters**: 

  * **f** The generic callable to invoke. 


**Template Parameters**: 

  * **T** The type parameter to instantiate the functor with. 
  * **F** Functor type. 


**Return**: Result of invoking `f.template operator()<T>()`. 

### function dispatch_datatype

```cpp
template <typename F >
decltype(auto) dispatch_datatype(
    datatype dt,
    F && f
)
```

Runtime-to-compile-time datatype dispatcher. 

**Parameters**: 

  * **dt** The runtime datatype tag. 
  * **f** The generic callable invoked with the matching static C++ type. 


**Template Parameters**: 

  * **F** Functor type accepting a template type parameter `<T>()`. 


**Return**: Result of the dispatched call. 

Calls the provided generic lambda/functor `f` with the template argument corresponding to the runtime `dt` enum value. 


### function cum

```cpp
void cum(
    DEVICE device =DEVICE::AUTO
)
```

Initializes the CUM library context for the specified compute device. 

**Parameters**: 

  * **device** The target compute device ([DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto), [DEVICE::CPU](Namespaces/namespacecum.md#enumvalue-cpu), or [DEVICE::GPU](Namespaces/namespacecum.md#enumvalue-gpu)). Default is [DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto). 


### function recum

```cpp
void recum(
    DEVICE device =DEVICE::AUTO
)
```

Reinitializes or switches the CUM library context to another compute device. 

**Parameters**: 

  * **device** The target compute device to switch to. Default is [DEVICE::AUTO](Namespaces/namespacecum.md#enumvalue-auto). 


### function decum

```cpp
void decum()
```

Finalizes and cleans up the CUM library runtime and allocated context resources. 

### function datatype_size

```cpp
std::size_t datatype_size(
    datatype type
)
```

Computes the byte size of a specified runtime datatype tag. 

**Parameters**: 

  * **type** The runtime datatype tag. 


**Return**: Size in bytes of one element of the datatype. 

### function type_tag

```cpp
template <typename T >
datatype type_tag()
```

Resolves the runtime datatype tag corresponding to compile-time type `T`. 

**Template Parameters**: 

  * **T** The static C++ type. 


**Return**: The corresponding [datatype](Namespaces/namespacecum.md#enum-datatype) enum value. 

### function dnnl_algorithm

```cpp
dnnl::algorithm dnnl_algorithm(
    functions::function_id id
)
```

Converts CUM [functions::function_id]() to oneDNN algorithm enumeration. 

**Parameters**: 

  * **id** Function identifier. 


**Return**: Corresponding oneDNN algorithm. 

### function dnnl_data_type

```cpp
dnnl::memory::data_type dnnl_data_type(
    datatype dtype
)
```

Converts CUM [datatype](Namespaces/namespacecum.md#enum-datatype) tag to oneDNN memory data_type. 

**Parameters**: 

  * **dtype** CUM datatype tag. 


**Return**: Corresponding oneDNN memory::data_type. 

### function cum_data_type

```cpp
datatype cum_data_type(
    dnnl::memory::data_type dtype
)
```

Converts oneDNN memory data_type to CUM [datatype](Namespaces/namespacecum.md#enum-datatype) tag. 

**Parameters**: 

  * **dtype** oneDNN memory::data_type. 


**Return**: Corresponding CUM datatype tag. 

### function dnnl_format_tag

```cpp
dnnl::memory::format_tag dnnl_format_tag(
    layout format
)
```

Converts CUM [layout](Namespaces/namespacecum.md#enum-layout) tag to oneDNN format_tag. 

**Parameters**: 

  * **format** CUM layout tag. 


**Return**: Corresponding oneDNN format_tag. 

### function cum_format_tag

```cpp
layout cum_format_tag(
    dnnl::memory::format_tag format
)
```

Converts oneDNN format_tag to CUM [layout](Namespaces/namespacecum.md#enum-layout) tag. 

**Parameters**: 

  * **format** oneDNN format_tag. 


**Return**: Corresponding CUM layout tag. 

### function operator+

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
Matrix< T, rows_, cols_ > operator+(
    const Matrix< T, rows_, cols_ > & lhs,
    const Matrix< T, rows_, cols_ > rhs
) const
```


### function operator-

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
Matrix< T, rows_, cols_ > operator-(
    const Matrix< T, rows_, cols_ > & lhs,
    const Matrix< T, rows_, cols_ > rhs
) const
```


### function operator*

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
Matrix< T, rows_, cols_ > operator*(
    const Matrix< T, rows_, cols_ > & lhs,
    const Matrix< T, rows_, cols_ > rhs
) const
```


### function operator/

```cpp
template <typename T ,
dim_t rows_,
dim_t cols_>
Matrix< T, rows_, cols_ > operator/(
    const Matrix< T, rows_, cols_ > & lhs,
    const Matrix< T, rows_, cols_ > rhs
) const
```


### function operator+

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator+(
    const Vector< T, length_ > & lhs,
    const Vector< T, length_ > & rhs
)
```


**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Sum vector. 

### function operator-

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator-(
    const Vector< T, length_ > & lhs,
    const Vector< T, length_ > & rhs
)
```


**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Difference vector. 

### function operator*

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator*(
    const Vector< T, length_ > & lhs,
    const Vector< T, length_ > & rhs
)
```


**Parameters**: 

  * **v** First vector. 
  * **u** Second vector. 


**Return**: Product vector. 

### function operator/

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator/(
    const Vector< T, length_ > & lhs,
    const Vector< T, length_ > & rhs
)
```


**Parameters**: 

  * **v** Numerator vector. 
  * **u** Denominator vector. 


**Return**: Quotient vector. 

### function operator*

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator*(
    const Vector< T, length_ > & lhs,
    const std::type_identity_t< T > scalar
)
```


### function operator/

```cpp
template <typename T ,
dim_t length_>
Vector< T, length_ > operator/(
    const Vector< T, length_ > & lhs,
    const std::type_identity_t< T > scalar
)
```



## Attributes Documentation

### variable Dynamic

```cpp
dim_t Dynamic = -1;
```

Sentinel constant indicating dynamic (runtime) dimension sizing. 




-------------------------------

Updated on 2026-10-31 at 18:07:40 +0100