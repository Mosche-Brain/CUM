# CUM - **C**++ N**um**eric Library
Vendor agnostic C++ library providing linear algebra, eltwise operations, convenient data structures and deep learning primitives without template hell (we moved the problems from the compile time to the runtime)

### CUM modules
* `cum/lara` - Classic BLAS routines and some convenience wrappers.
* `cum/functions` - Elementwise functions and some general stuff.
* `cum/neural_primitives` - Set of primitives for deep learning and N-Dimensional tensors operation.
* `cum/` - Memory and runtime management and `Vector`/`Matrix`/`Tensor` class

### Current development goals
* Deep Learning primitives abstraction
* Generic types
* Multi-device queue
* Port for XTensa architecture for embbeded deployment (or maybe for bare metal ARM or RISC-V)

### Known issues
* FP8 and lower floating point precision tensors didn't work and wouldn't for some time.
* Generic types are unfinished.
* Some random things may not work for some reason.

### Installation and usage
 I will write a proper installation guide soon.

### Related projects ( most are not even existing )
* cumDNN *(also known as yann)*
* cumBLAS
* ~~cumLAPACK~~
* ~~cumFFT~~
* ~~cumGRAD~~
* cumPy
* ~~cumGL~~
* ~~cumGPT~~
* ~~cumAGI~~
* ~~cumMileniumRun~~
* Cumming Simulator 2023
* Cumming Simulator 2026
