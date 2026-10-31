---
title: Classes

---

# Classes




* **struct [Device](/CUM/api/Classes/structDevice/)** <br>Opaque handle representing a compute device. 
* **struct [Queue](/CUM/api/Classes/structQueue/)** <br>Opaque handle representing a command execution queue. 
* **namespace [cum](/CUM/api/Namespaces/namespacecum/)** 
    * **class [Matrix](/CUM/api/Classes/classcum_1_1Matrix/)** <br>Templated generic dense matrix. 
    * **class [MatrixView](/CUM/api/Classes/classcum_1_1MatrixView/)** <br>Lightweight, non-owning read view over a 2D matrix or existing data buffer. 
    * **class [Tensor](/CUM/api/Classes/classcum_1_1Tensor/)** <br>Core N-dimensional array and deep learning tensor. 
    * **class [Vector](/CUM/api/Classes/classcum_1_1Vector/)** <br>Templated generic 1D dense vector. 
    * **struct [bfloat16](/CUM/api/Classes/structcum_1_1bfloat16/)** <br>Raw 16-bit fallback for [bfloat16]() precision float. 
    * **namespace [blas](/CUM/api/Namespaces/namespacecum_1_1blas/)** 
    * **struct [datatype_of](/CUM/api/Classes/structcum_1_1datatype__of/)** <br>Type trait mapping a static C++ type to its runtime [datatype](/CUM/api/Namespaces/namespacecum/#enum-datatype) enum tag. 
    * **struct [datatype_of< cum::bfloat16 >](/CUM/api/Classes/structcum_1_1datatype__of_3_01cum_1_1bfloat16_01_4/)** 
    * **struct [datatype_of< cum::float16 >](/CUM/api/Classes/structcum_1_1datatype__of_3_01cum_1_1float16_01_4/)** 
    * **struct [datatype_of< cum::float8 >](/CUM/api/Classes/structcum_1_1datatype__of_3_01cum_1_1float8_01_4/)** 
    * **struct [datatype_of< double >](/CUM/api/Classes/structcum_1_1datatype__of_3_01double_01_4/)** 
    * **struct [datatype_of< float >](/CUM/api/Classes/structcum_1_1datatype__of_3_01float_01_4/)** 
    * **struct [datatype_of< std::int16_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1int16__t_01_4/)** 
    * **struct [datatype_of< std::int32_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1int32__t_01_4/)** 
    * **struct [datatype_of< std::int64_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1int64__t_01_4/)** 
    * **struct [datatype_of< std::int8_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1int8__t_01_4/)** 
    * **struct [datatype_of< std::uint16_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1uint16__t_01_4/)** 
    * **struct [datatype_of< std::uint32_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1uint32__t_01_4/)** 
    * **struct [datatype_of< std::uint64_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1uint64__t_01_4/)** 
    * **struct [datatype_of< std::uint8_t >](/CUM/api/Classes/structcum_1_1datatype__of_3_01std_1_1uint8__t_01_4/)** 
    * **namespace [detail](/CUM/api/Namespaces/namespacecum_1_1detail/)** 
        * **class [event_handler](/CUM/api/Classes/classcum_1_1detail_1_1event__handler/)** <br>Factory and accessor bridging SYCL asynchronous events with CUM's [experimental::__event__](). 
    * **namespace [experimental](/CUM/api/Namespaces/namespacecum_1_1experimental/)** 
        * **class [__event__](/CUM/api/Classes/classcum_1_1experimental_1_1____event____/)** <br>Opaque handle representing an in-flight or completed asynchronous device operation. 
        * **struct [__kernel__](/CUM/api/Classes/structcum_1_1experimental_1_1____kernel____/)** <br>SYCL kernel handle wrapper. 
    * **struct [float16](/CUM/api/Classes/structcum_1_1float16/)** <br>Raw 16-bit fallback for half precision float. 
    * **namespace [functions](/CUM/api/Namespaces/namespacecum_1_1functions/)** 
        * **struct [GELU](/CUM/api/Classes/structcum_1_1functions_1_1GELU/)** <br>Gaussian Error [Linear]() Unit activation functor: f(x) = x * P(X <= x). 
        * **struct [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/)** <br>[Linear]() / identity activation function functor: f(x) = x. 
        * **struct [ReLU](/CUM/api/Classes/structcum_1_1functions_1_1ReLU/)** <br>Rectified [Linear](/CUM/api/Classes/structcum_1_1functions_1_1Linear/) Unit activation functor: f(x) = max(0, x). 
        * **struct [Sigmoid](/CUM/api/Classes/structcum_1_1functions_1_1Sigmoid/)** <br>Logistic sigmoid activation functor: f(x) = 1 / (1 + exp(-x)). 
        * **struct [Tanh](/CUM/api/Classes/structcum_1_1functions_1_1Tanh/)** <br>Hyperbolic tangent activation functor: f(x) = tanh(x). 
        * **struct [activation_t](/CUM/api/Classes/structcum_1_1functions_1_1activation__t/)** <br>Bundles activation function identifier, forward function, and derivative pointers. 
        * **namespace [cyclometric](/CUM/api/Namespaces/namespacecum_1_1functions_1_1cyclometric/)** 
        * **namespace [exponential](/CUM/api/Namespaces/namespacecum_1_1functions_1_1exponential/)** 
        * **namespace [hyperbolic](/CUM/api/Namespaces/namespacecum_1_1functions_1_1hyperbolic/)** 
        * **struct [leaky_ReLU](/CUM/api/Classes/structcum_1_1functions_1_1leaky__ReLU/)** <br>Leaky Rectified [Linear]() Unit activation functor: f(x) = x if x >= 0 else alpha * x. 
        * **namespace [linear_units](/CUM/api/Namespaces/namespacecum_1_1functions_1_1linear__units/)** 
        * **namespace [logistic](/CUM/api/Namespaces/namespacecum_1_1functions_1_1logistic/)** 
        * **namespace [trigonometric](/CUM/api/Namespaces/namespacecum_1_1functions_1_1trigonometric/)** 
        * **namespace [various](/CUM/api/Namespaces/namespacecum_1_1functions_1_1various/)** 
    * **namespace [internal](/CUM/api/Namespaces/namespacecum_1_1internal/)** 
        * **struct [Context](/CUM/api/Classes/structcum_1_1internal_1_1Context/)** <br>Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends. 
        * **struct [scalar_buffer](/CUM/api/Classes/structcum_1_1internal_1_1scalar__buffer/)** 
        * **struct [sycl_type_map](/CUM/api/Classes/structcum_1_1internal_1_1sycl__type__map/)** 
        * **struct [sycl_type_map< bfloat16 >](/CUM/api/Classes/structcum_1_1internal_1_1sycl__type__map_3_01bfloat16_01_4/)** 
        * **struct [sycl_type_map< float16 >](/CUM/api/Classes/structcum_1_1internal_1_1sycl__type__map_3_01float16_01_4/)** 
    * **namespace [lara](/CUM/api/Namespaces/namespacecum_1_1lara/)** 
    * **namespace [memory](/CUM/api/Namespaces/namespacecum_1_1memory/)** 
    * **namespace [neural_primitives](/CUM/api/Namespaces/namespacecum_1_1neural__primitives/)** 
        * **class [EltwiseKernel](/CUM/api/Classes/classcum_1_1neural__primitives_1_1EltwiseKernel/)** <br>Pre-compiled elementwise neural operation kernel for repeated forward/backward execution. 
        * **class [Engine](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Engine/)** <br>Compute execution engine encapsulating device accelerator execution context for primitives. 
        * **class [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/)** <br>Storage buffer managed by neural primitive engine according to a [Descriptor](). 
        * **class [MemoryDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1MemoryDescriptor/)** <br>Encapsulates tensor shape, data type, and memory format layout for neural network primitives. 
        * **class [Primitive](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/)** <br>Executable compute primitive representing a compiled neural network or tensor operation. 
            * **struct [ArgBinding](/CUM/api/Classes/structcum_1_1neural__primitives_1_1Primitive_1_1ArgBinding/)** <br>Zero-copy argument binding pairing an [Argument](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Primitive/#enum-argument) slot with a [Memory](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Memory/) or [Tensor]() reference. 
        * **class [PrimitiveDescriptor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1PrimitiveDescriptor/)** <br>Backend-resolved operation descriptor specifying shapes, layouts, datatypes, and algorithm parameters. 
            * **struct [Impl](/CUM/api/Classes/structcum_1_1neural__primitives_1_1PrimitiveDescriptor_1_1Impl/)** <br>Single unified Pimpl definition shared across PrimitiveDescriptor.cpp and Primitive.cpp. 
        * **class [Tensor](/CUM/api/Classes/classcum_1_1neural__primitives_1_1Tensor/)** <br>Core N-dimensional array and deep learning tensor. 
        * **namespace [detail](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1detail/)** 
        * **namespace [handles](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1handles/)** 
            * **struct [__desc__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____desc____/)** <br>Underlying oneDNN memory descriptor wrapper. 
            * **struct [__engine__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____engine____/)** <br>Underlying oneDNN engine wrapper. 
            * **struct [__memory__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____memory____/)** <br>Underlying oneDNN memory wrapper with optional USM shared ownership. 
            * **struct [__stream__](/CUM/api/Classes/structcum_1_1neural__primitives_1_1handles_1_1____stream____/)** <br>Underlying oneDNN stream wrapper. 
        * **namespace [neural_kernels](/CUM/api/Namespaces/namespacecum_1_1neural__primitives_1_1neural__kernels/)** 
    * **namespace [random](/CUM/api/Namespaces/namespacecum_1_1random/)** 
    * **namespace [runtime](/CUM/api/Namespaces/namespacecum_1_1runtime/)** 
* **struct [fp8_e4_3m_impl](/CUM/api/Classes/structfp8__e4__3m__impl/)** <br>8-bit floating point emulation structure (E4M3 format representation). 



-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
