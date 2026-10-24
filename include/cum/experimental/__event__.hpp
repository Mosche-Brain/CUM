/**
 * @file __event__.hpp
 * @brief Opaque asynchronous compute event handle.
 * @author Swiadomy-Mężczyzna
 * @details Implements moveable, non-copyable asynchronous event wrapper with pimpl pattern
 *          used to track asynchronous GPU/device queue kernel execution.
 */

#pragma once

#include <memory>

namespace cum::detail
{
    class event_handler;
}

namespace cum::experimental 
{
    /**
     * @class __event__
     * @brief Opaque handle representing an in-flight or completed asynchronous device operation.
     */
    class __event__
    {
    public:
        /**
         * @brief Default constructor creating an empty / completed event.
         */
        __event__() noexcept;

        /**
         * @brief Move constructor.
         * @param other Event to move from.
         */
        __event__(__event__&& other) noexcept;

        /**
         * @brief Move assignment operator.
         * @param other Event to move from.
         * @return Reference to `*this`.
         */
        __event__& operator=(__event__&& other) noexcept;

        __event__(const __event__&) = delete;
        __event__& operator=(const __event__&) = delete;

        ~__event__();

        /**
         * @brief Blocks host thread until the asynchronous event and associated device kernels finish execution.
         */
        void wait();

    private:
        struct Impl;
        
        std::unique_ptr<Impl> handle;

        explicit __event__(std::unique_ptr<Impl> handle) noexcept;

        friend class cum::detail::event_handler;
    };
} // namespace cum::experimental
