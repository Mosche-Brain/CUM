---
title: Files

---

# Files




* **file [README.md](/CUM/api/Files/README_8md/#file-readme.md)** 
* **dir [include](/CUM/api/Files/dir_d44c64559bbebec7f509842c48db8b23/#dir-include)** 
    * **dir [include/cum](/CUM/api/Files/dir_1375e77673132c034d5889f05152aed6/#dir-include/cum)** 
        * **file [hpp](/CUM/api/Files/Core_8hpp/#file-core.hpp)** <br>Core types, dimension definitions, and datatype dispatching utilities for CUM. 
        * **file [hpp](/CUM/api/Files/LinearAlgebra_8hpp/#file-linearalgebra.hpp)** <br>High-level linear algebra (LARA) routines for vectors and matrices. 
        * **file [hpp](/CUM/api/Files/Matrix_8hpp/#file-matrix.hpp)** <br>Dynamic 2D dense matrix class with BLAS operations, elementwise activations, and reductions. 
        * **file [hpp](/CUM/api/Files/MatrixView_8hpp/#file-matrixview.hpp)** <br>Non-owning read-only view class over 2D matrix memory buffers. 
        * **file [hpp](/CUM/api/Files/Tensor_8hpp/#file-tensor.hpp)** <br>Dynamic N-dimensional tensor class with neural primitive descriptors and deep learning operations. 
        * **file [hpp](/CUM/api/Files/Vector_8hpp/#file-vector.hpp)** <br>Dynamic 1D dense vector class with BLAS operations and matrix interoperability. 
        * **file [hpp](/CUM/api/Files/constants_8hpp/#file-constants.hpp)** <br>Mathematical and numerical constants used across the CUM library. 
        * **file [hpp](/CUM/api/Files/cum_8hpp/#file-cum.hpp)** <br>Main entry-point header for runtime initialization and lifecycle management in CUM. 
        * **file [hpp](/CUM/api/Files/datatypes_8hpp/#file-datatypes.hpp)** <br>Datatype definitions, precision aliases, and type tagging utilities for CUM. 
        * **file [hpp](/CUM/api/Files/functions_8hpp/#file-functions.hpp)** <br>Master include header and functor definitions for neural activation and mathematical functions. 
        * **dir [include/cum/detail](/CUM/api/Files/dir_6f77636cd866220f019dd59bfea1532f/#dir-include/cum/detail)** 
            * **file [hpp](/CUM/api/Files/detail_8hpp/#file-detail.hpp)** <br>Internal implementation utilities and forward declarations. 
            * **dir [include/cum/detail/vendor](/CUM/api/Files/dir_2aff694eb104526cf38f4315742aa9fe/#dir-include/cum/detail/vendor)** 
                * **dir [include/cum/detail/vendor/cuda](/CUM/api/Files/dir_d0826e03fe18818e7db60df113675187/#dir-include/cum/detail/vendor/cuda)** 
                    * **file [hpp](/CUM/api/Files/cuda_2float16_8hpp/#file-float16.hpp)** <br>CUDA float16 vendor detail header. 
                * **dir [include/cum/detail/vendor/native](/CUM/api/Files/dir_93b782031abef69e8ca288904d5e259e/#dir-include/cum/detail/vendor/native)** 
                    * **file [hpp](/CUM/api/Files/native_2float16_8hpp/#file-float16.hpp)** <br>Native CPU float16 vendor detail header. 
                * **dir [include/cum/detail/vendor/oneapi](/CUM/api/Files/dir_4752a9aa40398e67dae1d233b080e7b3/#dir-include/cum/detail/vendor/oneapi)** 
                    * **file [hpp](/CUM/api/Files/context_8hpp/#file-context.hpp)** <br>Intel oneAPI SYCL and oneDNN runtime context and resource management. 
                    * **file [hpp](/CUM/api/Files/conversion__helpers_8hpp/#file-conversion-helpers.hpp)** <br>Bidirectional conversion helpers between CUM enums and oneDNN enumerations. 
                    * **file [hpp](/CUM/api/Files/dtype__dispatch_8hpp/#file-dtype-dispatch.hpp)** <br>SYCL and oneMKL datatype dispatchers, type mapping traits, and fallback kernel templates. 
                    * **file [hpp](/CUM/api/Files/event_8hpp/#file-event.hpp)** <br>oneAPI SYCL event integration header. 
                    * **file [hpp](/CUM/api/Files/event__handler_8hpp/#file-event-handler.hpp)** <br>Internal adapter bridging SYCL events with experimental::**event**. 
                    * **file [hpp](/CUM/api/Files/oneapi_2float16_8hpp/#file-float16.hpp)** <br>Intel oneAPI / SYCL half-precision floating point detail header. 
                    * **file [hpp](/CUM/api/Files/kernel_8hpp/#file-kernel.hpp)** <br>SYCL kernel wrapper definition for experimental::**kernel**. 
                    * **file [hpp](/CUM/api/Files/detail_2vendor_2oneapi_2opaque__types_8hpp/#file-opaque-types.hpp)** <br>oneDNN backend handle implementations for neural primitive structures. 
                    * **file [hpp](/CUM/api/Files/primitive__descriptors__handles_8hpp/#file-primitive-descriptors-handles.hpp)** <br>Internal oneDNN conversion helpers and Pimpl definition for PrimitiveDescriptor. 
        * **dir [include/cum/experimental](/CUM/api/Files/dir_92a54216756546ee52f60a0c170e9e2a/#dir-include/cum/experimental)** 
            * **file [hpp](/CUM/api/Files/____event_____8hpp/#file---event--.hpp)** <br>Opaque asynchronous compute event handle. 
            * **file [hpp](/CUM/api/Files/____kernel_____8hpp/#file---kernel--.hpp)** <br>Opaque structure declaration for kernel handle type. 
        * **dir [include/cum/functions](/CUM/api/Files/dir_673004f0b94d6d8726e3b5f12db31982/#dir-include/cum/functions)** 
            * **file [hpp](/CUM/api/Files/cyclometric_8hpp/#file-cyclometric.hpp)** <br>Inverse trigonometric (cyclometric) functions (asin, acos, atan) and their derivatives. 
            * **file [hpp](/CUM/api/Files/exponential_8hpp/#file-exponential.hpp)** <br>Exponential and logarithmic functions and their derivatives. 
            * **file [hpp](/CUM/api/Files/function__id_8hpp/#file-function-id.hpp)** <br>Function identifier enumeration and activation callback signatures. 
            * **file [hpp](/CUM/api/Files/hyperbolic_8hpp/#file-hyperbolic.hpp)** <br>Hyperbolic functions (tanh, sinh, cosh) and their derivatives. 
            * **file [hpp](/CUM/api/Files/linear__units_8hpp/#file-linear-units.hpp)** <br>Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity). 
            * **file [hpp](/CUM/api/Files/logistic_8hpp/#file-logistic.hpp)** <br>Logistic functions including Sigmoid and Softmax activations and their derivatives. 
            * **file [hpp](/CUM/api/Files/transform_8hpp/#file-transform.hpp)** <br>Unified elementwise transformation and derivative dispatch routines. 
            * **file [hpp](/CUM/api/Files/trigonometric_8hpp/#file-trigonometric.hpp)** <br>Trigonometric functions (sin, cos, tan) and their analytical derivatives. 
            * **file [hpp](/CUM/api/Files/various_8hpp/#file-various.hpp)** <br>Miscellaneous elementwise mathematical utilities (fill, clamp, clip, abs, min, max, equal, linspace). 
        * **dir [include/cum/generics](/CUM/api/Files/dir_20b04809cc9e3b61a71b43aa0530581a/#dir-include/cum/generics)** 
            * **file [hpp](/CUM/api/Files/generics_2Matrix_8hpp/#file-matrix.hpp)** <br>Templated generic 2D matrix class with fixed compile-time or dynamic dimensions. 
            * **file [ipp](/CUM/api/Files/Matrix_8ipp/#file-matrix.ipp)** <br>Template implementation for generic Matrix methods and operators. 
            * **file [hpp](/CUM/api/Files/generics_2Vector_8hpp/#file-vector.hpp)** <br>Templated generic vector class supporting both fixed compile-time and dynamic dimensions. 
            * **file [ipp](/CUM/api/Files/Vector_8ipp/#file-vector.ipp)** <br>Template implementation for generic Vector methods and operators. 
            * **file [hpp](/CUM/api/Files/parallel_8hpp/#file-parallel.hpp)** <br>Generic parallel algorithms and execution primitives. 
        * **dir [include/cum/lara](/CUM/api/Files/dir_586a765ea80462aca7377be9af1f31c3/#dir-include/cum/lara)** 
            * **file [hpp](/CUM/api/Files/BLAS_8hpp/#file-blas.hpp)** <br>Master include header for Basic Linear Algebra Subprograms (BLAS levels 1, 2, and 3). 
            * **dir [include/cum/lara/BLAS](/CUM/api/Files/dir_8bb1ade4739f284db2470479437f959d/#dir-include/cum/lara/blas)** 
                * **file [hpp](/CUM/api/Files/level1_8hpp/#file-level1.hpp)** <br>BLAS Level 1 vector-vector and vector-scalar operations. 
                * **file [hpp](/CUM/api/Files/level2_8hpp/#file-level2.hpp)** <br>BLAS Level 2 matrix-vector operations. 
                * **file [hpp](/CUM/api/Files/level3_8hpp/#file-level3.hpp)** <br>BLAS Level 3 matrix-matrix operations. 
                * **file [hpp](/CUM/api/Files/types_8hpp/#file-types.hpp)** <br>Common BLAS enumerations and operation flags. 
            * **file [hpp](/CUM/api/Files/matops_8hpp/#file-matops.hpp)** <br>High-level asynchronous matrix multiplication and transpose operations. 
            * **file [hpp](/CUM/api/Files/lara_2reductions_8hpp/#file-reductions.hpp)** <br>Asynchronous parallel reductions for matrices and vectors. 
            * **file [hpp](/CUM/api/Files/vecops_8hpp/#file-vecops.hpp)** <br>High-level asynchronous vector arithmetic operations (vadd, vsub, vmul, vdiv, batched operations). 
        * **dir [include/cum/neural_primitives](/CUM/api/Files/dir_fe112122e37f6626a31cd8f129dab127/#dir-include/cum/neural-primitives)** 
            * **file [hpp](/CUM/api/Files/EltwiseKernel_8hpp/#file-eltwisekernel.hpp)** <br>Elementwise kernel wrapper executing compiled neural primitives. 
            * **file [hpp](/CUM/api/Files/Engine_8hpp/#file-engine.hpp)** <br>Compute engine abstraction for deep learning primitives. 
            * **file [hpp](/CUM/api/Files/Memory_8hpp/#file-memory.hpp)** <br>Memory object abstraction for deep learning primitives. 
            * **file [hpp](/CUM/api/Files/MemoryDescriptor_8hpp/#file-memorydescriptor.hpp)** <br>Multi-dimensional tensor memory descriptor for neural primitives. 
            * **file [hpp](/CUM/api/Files/Primitive_8hpp/#file-primitive.hpp)** <br>Executable compute primitive abstraction for neural network and tensor operations. 
            * **file [hpp](/CUM/api/Files/PrimitiveDescriptor_8hpp/#file-primitivedescriptor.hpp)** <br>Unified descriptor factory and metadata query interface for neural network primitives. 
            * **file [hpp](/CUM/api/Files/elementwise_8hpp/#file-elementwise.hpp)** <br>Forward elementwise neural activation primitives. 
            * **file [hpp](/CUM/api/Files/elementwise__diffs_8hpp/#file-elementwise-diffs.hpp)** <br>Backward (gradient / derivative) elementwise neural activation primitives. 
            * **file [hpp](/CUM/api/Files/neural__kernels_8hpp/#file-neural-kernels.hpp)** <br>Fused deep learning neural network layer kernels and loss functions. 
            * **file [hpp](/CUM/api/Files/neural__primitives_2opaque__types_8hpp/#file-opaque-types.hpp)** <br>Forward declarations of backend-specific opaque handle types for neural primitives. 
            * **file [hpp](/CUM/api/Files/neural__primitives_2reductions_8hpp/#file-reductions.hpp)** <br>Softmax forward and backward reduction primitives for neural tensors. 
            * **file [hpp](/CUM/api/Files/tensor__operations_8hpp/#file-tensor-operations.hpp)** <br>Multi-dimensional tensor arithmetic and matrix multiplication operations. 
        * **file [hpp](/CUM/api/Files/layout_8hpp/#file-layout.hpp)** <br>Memory layout and tensor dimension order tags. 
        * **file [hpp](/CUM/api/Files/memory_8hpp/#file-memory.hpp)** <br>Memory allocation, deallocation, copying, and prefetching routines for host and device memory. 
        * **file [hpp](/CUM/api/Files/neural__primitives_8hpp/#file-neural-primitives.hpp)** <br>Master include header for CUM neural network and tensor primitives. 
        * **file [hpp](/CUM/api/Files/random_8hpp/#file-random.hpp)** <br>Random number generators for filling memory buffers with uniform and normal distributions. 
        * **file [hpp](/CUM/api/Files/runtime_8hpp/#file-runtime.hpp)** <br>[Device](/CUM/api/Classes/structDevice/) and queue abstractions and synchronization primitives. 



-------------------------------

Updated on 2026-10-31 at 18:51:12 +0100
