# Neural Primitives

Header: `<cum/neural_primitives.hpp>`

The Neural Primitives module abstracts deep learning operations using Intel oneDNN.

## Core Concepts

- **`cum::neural_primitives::Engine`**: Device execution engine wrapping SYCL / CPU devices.
- **`cum::neural_primitives::Memory`**: Memory instance tagged with format tags and dimensions.
- **`cum::neural_primitives::MemoryDescriptor`**: Logical description of tensor shapes and memory formats (e.g. `nchw`, `nhwc`).
- **`cum::neural_primitives::Primitive`**: Executable operator kernel.

## Supported Primitive Kernels

- Convolution (Forward, Backward weights, Backward data)
- Pooling (Max, Average)
- Batch & Layer Normalization
- Activation & Eltwise transformations
- Softmax / LogSoftmax
