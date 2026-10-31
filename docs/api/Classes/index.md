---
title: Classes

---

# Classes




* **struct [Device](Classes/structDevice.md)** <br>Opaque handle representing a compute device. 
* **struct [Queue](Classes/structQueue.md)** <br>Opaque handle representing a command execution queue. 
* **namespace [cum](Namespaces/namespacecum.md)** 
    * **class [Matrix](Classes/classcum_1_1Matrix.md)** <br>Templated generic dense matrix. 
    * **class [MatrixView](Classes/classcum_1_1MatrixView.md)** <br>Lightweight, non-owning read view over a 2D matrix or existing data buffer. 
    * **class [Tensor](Classes/classcum_1_1Tensor.md)** <br>Core N-dimensional array and deep learning tensor. 
    * **class [Vector](Classes/classcum_1_1Vector.md)** <br>Templated generic 1D dense vector. 
    * **struct [bfloat16](Classes/structcum_1_1bfloat16.md)** <br>Raw 16-bit fallback for [bfloat16]() precision float. 
    * **namespace [blas](Namespaces/namespacecum_1_1blas.md)** 
    * **struct [datatype_of](Classes/structcum_1_1datatype__of.md)** <br>Type trait mapping a static C++ type to its runtime [datatype](Namespaces/namespacecum.md#enum-datatype) enum tag. 
    * **struct [datatype_of< cum::bfloat16 >](Classes/structcum_1_1datatype__of_3_01cum_1_1bfloat16_01_4.md)** 
    * **struct [datatype_of< cum::float16 >](Classes/structcum_1_1datatype__of_3_01cum_1_1float16_01_4.md)** 
    * **struct [datatype_of< cum::float8 >](Classes/structcum_1_1datatype__of_3_01cum_1_1float8_01_4.md)** 
    * **struct [datatype_of< double >](Classes/structcum_1_1datatype__of_3_01double_01_4.md)** 
    * **struct [datatype_of< float >](Classes/structcum_1_1datatype__of_3_01float_01_4.md)** 
    * **struct [datatype_of< std::int16_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int16__t_01_4.md)** 
    * **struct [datatype_of< std::int32_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int32__t_01_4.md)** 
    * **struct [datatype_of< std::int64_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int64__t_01_4.md)** 
    * **struct [datatype_of< std::int8_t >](Classes/structcum_1_1datatype__of_3_01std_1_1int8__t_01_4.md)** 
    * **struct [datatype_of< std::uint16_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint16__t_01_4.md)** 
    * **struct [datatype_of< std::uint32_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint32__t_01_4.md)** 
    * **struct [datatype_of< std::uint64_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint64__t_01_4.md)** 
    * **struct [datatype_of< std::uint8_t >](Classes/structcum_1_1datatype__of_3_01std_1_1uint8__t_01_4.md)** 
    * **namespace [detail](Namespaces/namespacecum_1_1detail.md)** 
        * **class [event_handler](Classes/classcum_1_1detail_1_1event__handler.md)** <br>Factory and accessor bridging SYCL asynchronous events with CUM's [experimental::__event__](). 
    * **namespace [experimental](Namespaces/namespacecum_1_1experimental.md)** 
        * **class [__event__](Classes/classcum_1_1experimental_1_1____event____.md)** <br>Opaque handle representing an in-flight or completed asynchronous device operation. 
        * **struct [__kernel__](Classes/structcum_1_1experimental_1_1____kernel____.md)** <br>SYCL kernel handle wrapper. 
    * **struct [float16](Classes/structcum_1_1float16.md)** <br>Raw 16-bit fallback for half precision float. 
    * **namespace [functions](Namespaces/namespacecum_1_1functions.md)** 
        * **struct [GELU](Classes/structcum_1_1functions_1_1GELU.md)** <br>Gaussian Error [Linear]() Unit activation functor: f(x) = x * P(X <= x). 
        * **struct [Linear](Classes/structcum_1_1functions_1_1Linear.md)** <br>[Linear]() / identity activation function functor: f(x) = x. 
        * **struct [ReLU](Classes/structcum_1_1functions_1_1ReLU.md)** <br>Rectified [Linear](Classes/structcum_1_1functions_1_1Linear.md) Unit activation functor: f(x) = max(0, x). 
        * **struct [Sigmoid](Classes/structcum_1_1functions_1_1Sigmoid.md)** <br>Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)). 
        * **struct [Tanh](Classes/structcum_1_1functions_1_1Tanh.md)** <br>Hyperbolic tangent activation functor: f(x) = tanh(x). 
        * **struct [activation_t](Classes/structcum_1_1functions_1_1activation__t.md)** <br>Bundles activation function identifier, forward function, and derivative pointers. 
        * **namespace [cyclometric](Namespaces/namespacecum_1_1functions_1_1cyclometric.md)** 
        * **namespace [exponential](Namespaces/namespacecum_1_1functions_1_1exponential.md)** 
        * **namespace [hyperbolic](Namespaces/namespacecum_1_1functions_1_1hyperbolic.md)** 
        * **struct [leaky_ReLU](Classes/structcum_1_1functions_1_1leaky__ReLU.md)** <br>Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x. 
        * **namespace [linear_units](Namespaces/namespacecum_1_1functions_1_1linear__units.md)** 
        * **namespace [logistic](Namespaces/namespacecum_1_1functions_1_1logistic.md)** 
        * **namespace [trigonometric](Namespaces/namespacecum_1_1functions_1_1trigonometric.md)** 
        * **namespace [various](Namespaces/namespacecum_1_1functions_1_1various.md)** 
    * **namespace [internal](Namespaces/namespacecum_1_1internal.md)** 
        * **struct [Context](Classes/structcum_1_1internal_1_1Context.md)** <br>Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends. 
        * **struct [scalar_buffer](Classes/structcum_1_1internal_1_1scalar__buffer.md)** 
        * **struct [sycl_type_map](Classes/structcum_1_1internal_1_1sycl__type__map.md)** 
        * **struct [sycl_type_map< bfloat16 >](Classes/structcum_1_1internal_1_1sycl__type__map_3_01bfloat16_01_4.md)** 
        * **struct [sycl_type_map< float16 >](Classes/structcum_1_1internal_1_1sycl__type__map_3_01float16_01_4.md)** 
    * **namespace [lara](Namespaces/namespacecum_1_1lara.md)** 
    * **namespace [memory](Namespaces/namespacecum_1_1memory.md)** 
    * **namespace [neural_primitives](Namespaces/namespacecum_1_1neural__primitives.md)** 
        * **class [EltwiseKernel](Classes/classcum_1_1neural__primitives_1_1EltwiseKernel.md)** <br>Pre-compiled elementwise neural operation kernel for repeated forward/backward execution. 
        * **class [Engine](Classes/classcum_1_1neural__primitives_1_1Engine.md)** <br>Compute execution engine encapsulating device accelerator execution context for primitives. 
        * **class [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md)** <br>Storage buffer managed by neural primitive engine according to a [Descriptor](). 
        * **class [MemoryDescriptor](Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor.md)** <br>Encapsulates tensor shape, data type, and memory format layout for neural network primitives. 
        * **class [Primitive](Classes/classcum_1_1neural__primitives_1_1Primitive.md)** <br>Executable compute primitive representing a compiled neural network or tensor operation. 
            * **struct [ArgBinding](Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding.md)** <br>Zero-copy argument binding pairing an [Argument](Classes/classcum_1_1neural__primitives_1_1Primitive.md#enum-argument) slot with a [Memory](Classes/classcum_1_1neural__primitives_1_1Memory.md) or [Tensor]() reference. 
        * **class [PrimitiveDescriptor](Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor.md)** <br>Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters. 
            * **struct [Impl](Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl.md)** <br>Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp. 
        * **class [Tensor](Classes/classcum_1_1neural__primitives_1_1Tensor.md)** <br>Core N-dimensional array and deep learning tensor. 
        * **namespace [detail](Namespaces/namespacecum_1_1neural__primitives_1_1detail.md)** 
        * **namespace [handles](Namespaces/namespacecum_1_1neural__primitives_1_1handles.md)** 
            * **struct [__desc__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____.md)** <br>Underlying oneDNN memory descriptor wrapper. 
            * **struct [__engine__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____.md)** <br>Underlying oneDNN engine wrapper. 
            * **struct [__memory__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____.md)** <br>Underlying oneDNN memory wrapper with optional USM shared ownership. 
            * **struct [__stream__](Classes/structcum_1_1neural__primitives_1_1handles_1_1____stream____.md)** <br>Underlying oneDNN stream wrapper. 
        * **namespace [neural_kernels](Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels.md)** 
    * **namespace [random](Namespaces/namespacecum_1_1random.md)** 
    * **namespace [runtime](Namespaces/namespacecum_1_1runtime.md)** 
* **struct [fp8_e4_3m_impl](Classes/structfp8__e4__3m__impl.md)** <br>8-bit floating point emulation structure (E4M3 format representation). 



-------------------------------

Updated on 2026-10-31 at 18:07:42 +0100
