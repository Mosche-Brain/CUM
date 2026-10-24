/**
 * @file context.hpp
 * @brief Intel oneAPI SYCL and oneDNN runtime context and resource management.
 * @details Manages SYCL queue, context, device, oneDNN engine and stream, constant buffers, and Philox RNG.
 */

#pragma once

#include <oneapi/dnnl/dnnl_common.hpp>
#include <oneapi/mkl.hpp>
#include <oneapi/dnnl/dnnl.hpp>
#include <oneapi/dnnl/dnnl_sycl.hpp>

#include <memory>
#include <mutex>
#include <oneapi/mkl/rng/device.hpp>

#include "cum/Core.hpp"

namespace cum::internal
{
    /**
     * @struct Context
     * @brief Singleton hardware and runtime execution context for oneAPI / SYCL / oneDNN backends.
     */
    struct Context
    {
        /**
         * @brief Initializes oneAPI runtime context on the target device.
         * @param device Compute device selector.
         */
        explicit Context(DEVICE device=DEVICE::AUTO);
        ~Context();

        std::once_flag initialized;

        dim_t cache_size;
        cumeric_t* zeros;
        cumeric_t* ones;
        cumeric_t* cache;

        /**
         * @brief Switches the active compute hardware device.
         * @param device Target device.
         */
        void setDevice(DEVICE device);

        sycl::queue queue;                                ///< SYCL execution queue.
        sycl::context context;                            ///< SYCL compute context.
        sycl::device device;                              ///< SYCL selected hardware device.
        dnnl::engine engine;                              ///< oneDNN execution engine.
        dnnl::stream stream;                              ///< oneDNN command stream.
        oneapi::mkl::rng::device::philox4x32x10<1> rng;  ///< Device Philox random number generator.
    };

    /**
     * @brief Returns reference to thread-safe global context instance.
     * @param device Target device.
     * @return Context reference.
     */
    Context& context(DEVICE device=DEVICE::AUTO);

    sycl::context& getSyclContext();
    sycl::device& device();
    sycl::queue& getQueue();
    dnnl::engine& getEngine();
    dnnl::stream& getStream();

    oneapi::mkl::rng::device::philox4x32x10<1>& getRNG();

    cumeric_t* getZeros();
    cumeric_t* getOnes();

    const cumeric_t* zeros();
    const cumeric_t* ones();
    cumeric_t* cache();

    sycl::context& sycl_context();
    sycl::queue& queue();
    dnnl::engine& engine();
    dnnl::stream& stream();
} // namespace cum::internal
