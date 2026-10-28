/**
 * @file EltwiseKernel.hpp
 * @brief Elementwise kernel wrapper executing compiled neural primitives.
 * @author jaro
 * @details Supports forward and backward passes on @ref Tensor and @ref Memory objects with warmup caching.
 */

#pragma once

#include <memory>
#include "cum/neural_primitives/elementwise.hpp"

namespace cum::neural_primitives
{
    /**
     * @class EltwiseKernel
     * @brief Pre-compiled elementwise neural operation kernel for repeated forward/backward execution.
     */
    class EltwiseKernel
    {
    public:
        /**
         * @brief Constructs and compiles elementwise kernel for a given descriptor and algorithm.
         * @param desc Memory descriptor defining shape and layout.
         * @param algorithm Activation algorithm identifier.
         */
        EltwiseKernel(const MemoryDescriptor& desc, functions::function_id algorithm);

        /**
         * @brief Warms up and compiles device kernel pipelines.
         * @return Asynchronous execution event.
         */
        __event__ warmup();

        /**
         * @brief Executes forward pass out-of-place on Tensors.
         * @param dst Output tensor.
         * @param src Input tensor.
         * @return Asynchronous execution event.
         */
        __event__ forward(Tensor& dst, const Tensor& src);

        /**
         * @brief Executes forward pass in-place on Tensor.
         * @param src Tensor modified in place.
         * @return Asynchronous execution event.
         */
        __event__ forward(Tensor& src);

        /**
         * @brief Executes forward pass out-of-place on Memory objects.
         * @param dst Output memory.
         * @param src Input memory.
         * @return Asynchronous execution event.
         */
        __event__ forward(Memory& dst, const Memory& src);

        /**
         * @brief Executes forward pass in-place on Memory object.
         * @param src Memory modified in place.
         * @return Asynchronous execution event.
         */
        __event__ forward(Memory& src);

        /**
         * @brief Executes backward (gradient) pass out-of-place on Tensors.
         * @param dst Output gradient tensor.
         * @param src Input tensor.
         * @return Asynchronous execution event.
         */
        __event__ backward(Tensor& dst, const Tensor& src);

        /**
         * @brief Executes backward pass in-place on Tensor.
         * @param src Tensor modified in place.
         * @return Asynchronous execution event.
         */
        __event__ backward(Tensor& src);

        /**
         * @brief Executes backward pass out-of-place on Memory objects.
         * @param dst Output memory.
         * @param src Input memory.
         * @return Asynchronous execution event.
         */
        __event__ backward(Memory& dst, const Memory& src);

        /**
         * @brief Executes backward pass in-place on Memory object.
         * @param src Memory modified in place.
         * @return Asynchronous execution event.
         */
        __event__ backward(Memory& src);

    private:
        __event__ forward(handles::__memory__& dst, const handles::__memory__& src);
        __event__ backward(handles::__memory__& dst, const handles::__memory__& src);

        functions::function_id algorithm_;
        std::unique_ptr<MemoryDescriptor> desc;
    };
} // namespace cum::neural_primitives
