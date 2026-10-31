---
title: Files

---

# Files




* **file [README.md](Files/README_8md.md#file-readme.md)** 
* **dir [include](Files/dir_d44c64559bbebec7f509842c48db8b23.md#dir-include)** 
    * **dir [include/cum](Files/dir_1375e77673132c034d5889f05152aed6.md#dir-include/cum)** 
        * **file [hpp](Files/Core_8hpp.md#file-core.hpp)** <br>Core types, dimension definitions, and datatype dispatching utilities for CUM. 
        * **file [hpp](Files/LinearAlgebra_8hpp.md#file-linearalgebra.hpp)** <br>High-level linear algebra (LARA) routines for vectors and matrices. 
        * **file [hpp](Files/Matrix_8hpp.md#file-matrix.hpp)** <br>Dynamic 2D dense matrix class with BLAS operations, elementwise activations, and reductions. 
        * **file [hpp](Files/MatrixView_8hpp.md#file-matrixview.hpp)** <br>Non-owning read-only view class over 2D matrix memory buffers. 
        * **file [hpp](Files/Tensor_8hpp.md#file-tensor.hpp)** <br>Dynamic N-dimensional tensor class with neural primitive descriptors and deep learning operations. 
        * **file [hpp](Files/Vector_8hpp.md#file-vector.hpp)** <br>Dynamic 1D dense vector class with BLAS operations and matrix interoperability. 
        * **file [hpp](Files/constants_8hpp.md#file-constants.hpp)** <br>Mathematical and numerical constants used across the CUM library. 
        * **file [hpp](Files/cum_8hpp.md#file-cum.hpp)** <br>Main entry-point header for runtime initialization and lifecycle management in CUM. 
        * **file [hpp](Files/datatypes_8hpp.md#file-datatypes.hpp)** <br>Datatype definitions, precision aliases, and type tagging utilities for CUM. 
        * **file [hpp](Files/functions_8hpp.md#file-functions.hpp)** <br>Master include header and functor definitions for neural activation and mathematical functions. 
        * **dir [include/cum/detail](Files/dir_6f77636cd866220f019dd59bfea1532f.md#dir-include/cum/detail)** 
            * **file [hpp](Files/detail_8hpp.md#file-detail.hpp)** <br>Internal implementation utilities and forward declarations. 
            * **dir [include/cum/detail/vendor](Files/dir_2aff694eb104526cf38f4315742aa9fe.md#dir-include/cum/detail/vendor)** 
                * **dir [include/cum/detail/vendor/cuda](Files/dir_d0826e03fe18818e7db60df113675187.md#dir-include/cum/detail/vendor/cuda)** 
                    * **file [hpp](Files/cuda_2float16_8hpp.md#file-float16.hpp)** <br>CUDA float16 vendor detail header. 
                * **dir [include/cum/detail/vendor/native](Files/dir_93b782031abef69e8ca288904d5e259e.md#dir-include/cum/detail/vendor/native)** 
                    * **file [hpp](Files/native_2float16_8hpp.md#file-float16.hpp)** <br>Native CPU float16 vendor detail header. 
                * **dir [include/cum/detail/vendor/oneapi](Files/dir_4752a9aa40398e67dae1d233b080e7b3.md#dir-include/cum/detail/vendor/oneapi)** 
                    * **file [hpp](Files/context_8hpp.md#file-context.hpp)** <br>Intel oneAPI SYCL and oneDNN runtime context and resource management. 
                    * **file [hpp](Files/conversion__helpers_8hpp.md#file-conversion-helpers.hpp)** <br>Bidirectional conversion helpers between CUM enums and oneDNN enumerations. 
                    * **file [hpp](Files/dtype__dispatch_8hpp.md#file-dtype-dispatch.hpp)** <br>SYCL and oneMKL datatype dispatchers, type mapping traits, and fallback kernel templates. 
                    * **file [hpp](Files/event_8hpp.md#file-event.hpp)** <br>oneAPI SYCL event integration header. 
                    * **file [hpp](Files/event__handler_8hpp.md#file-event-handler.hpp)** <br>Internal adapter bridging SYCL events with experimental::**event**. 
                    * **file [hpp](Files/oneapi_2float16_8hpp.md#file-float16.hpp)** <br>Intel oneAPI / SYCL half-precision floating point detail header. 
                    * **file [hpp](Files/kernel_8hpp.md#file-kernel.hpp)** <br>SYCL kernel wrapper definition for experimental::**kernel**. 
                    * **file [hpp](Files/detail_2vendor_2oneapi_2opaque__types_8hpp.md#file-opaque-types.hpp)** <br>oneDNN backend handle implementations for neural primitive structures. 
                    * **file [hpp](Files/primitive__descriptors__handles_8hpp.md#file-primitive-descriptors-handles.hpp)** <br>Internal oneDNN conversion helpers and Pimpl definition for PrimitiveDescriptor. 
        * **dir [include/cum/experimental](Files/dir_92a54216756546ee52f60a0c170e9e2a.md#dir-include/cum/experimental)** 
            * **file [hpp](Files/____event_____8hpp.md#file---event--.hpp)** <br>Opaque asynchronous compute event handle. 
            * **file [hpp](Files/____kernel_____8hpp.md#file---kernel--.hpp)** <br>Opaque structure declaration for kernel handle type. 
        * **dir [include/cum/functions](Files/dir_673004f0b94d6d8726e3b5f12db31982.md#dir-include/cum/functions)** 
            * **file [hpp](Files/cyclometric_8hpp.md#file-cyclometric.hpp)** <br>Inverse trigonometric (cyclometric) functions (asin, acos, atan) and their derivatives. 
            * **file [hpp](Files/exponential_8hpp.md#file-exponential.hpp)** <br>Exponential and logarithmic functions and their derivatives. 
            * **file [hpp](Files/function__id_8hpp.md#file-function-id.hpp)** <br>Function identifier enumeration and activation callback signatures. 
            * **file [hpp](Files/hyperbolic_8hpp.md#file-hyperbolic.hpp)** <br>Hyperbolic functions (tanh, sinh, cosh) and their derivatives. 
            * **file [hpp](Files/linear__units_8hpp.md#file-linear-units.hpp)** <br>Linear unit activation functions and their derivatives (ReLU, Leaky ReLU, GELU, ELU, Identity). 
            * **file [hpp](Files/logistic_8hpp.md#file-logistic.hpp)** <br>Logistic functions including Sigmoid and Softmax activations and their derivatives. 
            * **file [hpp](Files/transform_8hpp.md#file-transform.hpp)** <br>Unified elementwise transformation and derivative dispatch routines. 
            * **file [hpp](Files/trigonometric_8hpp.md#file-trigonometric.hpp)** <br>Trigonometric functions (sin, cos, tan) and their analytical derivatives. 
            * **file [hpp](Files/various_8hpp.md#file-various.hpp)** <br>Miscellaneous elementwise mathematical utilities (fill, clamp, clip, abs, min, max, equal, linspace). 
        * **dir [include/cum/generics](Files/dir_20b04809cc9e3b61a71b43aa0530581a.md#dir-include/cum/generics)** 
            * **file [hpp](Files/generics_2Matrix_8hpp.md#file-matrix.hpp)** <br>Templated generic 2D matrix class with fixed compile-time or dynamic dimensions. 
            * **file [ipp](Files/Matrix_8ipp.md#file-matrix.ipp)** <br>Template implementation for generic Matrix methods and operators. 
            * **file [hpp](Files/generics_2Vector_8hpp.md#file-vector.hpp)** <br>Templated generic vector class supporting both fixed compile-time and dynamic dimensions. 
            * **file [ipp](Files/Vector_8ipp.md#file-vector.ipp)** <br>Template implementation for generic Vector methods and operators. 
            * **file [hpp](Files/parallel_8hpp.md#file-parallel.hpp)** <br>Generic parallel algorithms and execution primitives. 
        * **dir [include/cum/lara](Files/dir_586a765ea80462aca7377be9af1f31c3.md#dir-include/cum/lara)** 
            * **file [hpp](Files/BLAS_8hpp.md#file-blas.hpp)** <br>Master include header for Basic Linear Algebra Subprograms (BLAS levels 1, 2, and 3). 
            * **dir [include/cum/lara/BLAS](Files/dir_8bb1ade4739f284db2470479437f959d.md#dir-include/cum/lara/blas)** 
                * **file [hpp](Files/level1_8hpp.md#file-level1.hpp)** <br>BLAS Level 1 vector-vector and vector-scalar operations. 
                * **file [hpp](Files/level2_8hpp.md#file-level2.hpp)** <br>BLAS Level 2 matrix-vector operations. 
                * **file [hpp](Files/level3_8hpp.md#file-level3.hpp)** <br>BLAS Level 3 matrix-matrix operations. 
                * **file [hpp](Files/types_8hpp.md#file-types.hpp)** <br>Common BLAS enumerations and operation flags. 
            * **file [hpp](Files/matops_8hpp.md#file-matops.hpp)** <br>High-level asynchronous matrix multiplication and transpose operations. 
            * **file [hpp](Files/lara_2reductions_8hpp.md#file-reductions.hpp)** <br>Asynchronous parallel reductions for matrices and vectors. 
            * **file [hpp](Files/vecops_8hpp.md#file-vecops.hpp)** <br>High-level asynchronous vector arithmetic operations (vadd, vsub, vmul, vdiv, batched operations). 
        * **dir [include/cum/neural_primitives](Files/dir_fe112122e37f6626a31cd8f129dab127.md#dir-include/cum/neural-primitives)** 
            * **file [hpp](Files/EltwiseKernel_8hpp.md#file-eltwisekernel.hpp)** <br>Elementwise kernel wrapper executing compiled neural primitives. 
            * **file [hpp](Files/Engine_8hpp.md#file-engine.hpp)** <br>Compute engine abstraction for deep learning primitives. 
            * **file [hpp](Files/Memory_8hpp.md#file-memory.hpp)** <br>Memory object abstraction for deep learning primitives. 
            * **file [hpp](Files/MemoryDescriptor_8hpp.md#file-memorydescriptor.hpp)** <br>Multi-dimensional tensor memory descriptor for neural primitives. 
            * **file [hpp](Files/Primitive_8hpp.md#file-primitive.hpp)** <br>Executable compute primitive abstraction for neural network and tensor operations. 
            * **file [hpp](Files/PrimitiveDescriptor_8hpp.md#file-primitivedescriptor.hpp)** <br>Unified descriptor factory and metadata query interface for neural network primitives. 
            * **file [hpp](Files/elementwise_8hpp.md#file-elementwise.hpp)** <br>Forward elementwise neural activation primitives. 
            * **file [hpp](Files/elementwise__diffs_8hpp.md#file-elementwise-diffs.hpp)** <br>Backward (gradient / derivative) elementwise neural activation primitives. 
            * **file [hpp](Files/neural__kernels_8hpp.md#file-neural-kernels.hpp)** <br>Fused deep learning neural network layer kernels and loss functions. 
            * **file [hpp](Files/neural__primitives_2opaque__types_8hpp.md#file-opaque-types.hpp)** <br>Forward declarations of backend-specific opaque handle types for neural primitives. 
            * **file [hpp](Files/neural__primitives_2reductions_8hpp.md#file-reductions.hpp)** <br>Softmax forward and backward reduction primitives for neural tensors. 
            * **file [hpp](Files/tensor__operations_8hpp.md#file-tensor-operations.hpp)** <br>Multi-dimensional tensor arithmetic and matrix multiplication operations. 
        * **file [hpp](Files/layout_8hpp.md#file-layout.hpp)** <br>Memory layout and tensor dimension order tags. 
        * **file [hpp](Files/memory_8hpp.md#file-memory.hpp)** <br>Memory allocation, deallocation, copying, and prefetching routines for host and device memory. 
        * **file [hpp](Files/neural__primitives_8hpp.md#file-neural-primitives.hpp)** <br>Master include header for CUM neural network and tensor primitives. 
        * **file [hpp](Files/random_8hpp.md#file-random.hpp)** <br>Random number generators for filling memory buffers with uniform and normal distributions. 
        * **file [hpp](Files/runtime_8hpp.md#file-runtime.hpp)** <br>[Device](Classes/structDevice.md) and queue abstractions and synchronization primitives. 



-------------------------------

Updated on 2026-10-31 at 18:07:42 +0100
