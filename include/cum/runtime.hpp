/**
 * @file runtime.hpp
 * @brief Device and queue abstractions and synchronization primitives.
 * @author jaro
 */

#ifndef YANN_RUNTIME_HPP
#define YANN_RUNTIME_HPP

namespace cum::runtime
{
    /**
     * @struct Device
     * @brief Opaque handle representing a compute device.
     */
    typedef struct Device Device;

    /**
     * @struct Queue
     * @brief Opaque handle representing a command execution queue.
     */
    typedef struct Queue Queue;

    /**
     * @brief Blocks host execution until all submitted asynchronous operations complete on the device queue.
     */
    void sync();
}

#endif //YANN_RUNTIME_HPP
