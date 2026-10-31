# Core & Memory Architecture

Header: `<cum/Core.hpp>`

The Core module provides fundamental memory allocations and tensor primitives.

## Containers

- `cum::Vector<T>`: 1D contiguous dynamic array with custom device allocator support.
- `cum::Matrix<T>`: 2D matrix structure supporting row-major and column-major layouts.
- `cum::Tensor<T>`: N-Dimensional tensor abstraction with arbitrary strides and dimensions.
- `cum::MatrixView<T>`: Non-owning view over continuous or strided memory.

## Memory Management

Memory buffers can reside on:
- Host (Standard CPU memory)
- USM (Unified Shared Memory via SYCL / oneAPI)
- Device-specific memory (Intel GPUs, accelerator tiles)
