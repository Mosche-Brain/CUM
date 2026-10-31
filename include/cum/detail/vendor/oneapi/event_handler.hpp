/**
 * @file event_handler.hpp
 * @brief Internal adapter bridging SYCL events with experimental::__event__.
 * @author Świadomy Mężczyzna
 */

#pragma once

#include <memory>
#include <utility>

#include <sycl/event.hpp>

#include "cum/experimental/__event__.hpp"

namespace cum::detail
{
    /**
     * @class event_handler
     * @brief Factory and accessor bridging SYCL asynchronous events with CUM's @ref experimental::__event__.
     */
    class event_handler
    {
    public:
        /**
         * @brief Wraps an rvalue SYCL event into an @ref experimental::__event__.
         * @param event SYCL event.
         * @return Wrapped event handle.
         */
        static experimental::__event__ create(sycl::event&& event);

        /**
         * @brief Checks whether the wrapped event holds an active backend event handle.
         * @param event Wrapped event handle.
         * @return True if initialized, false if default-constructed/empty.
         */
        static bool valid(const experimental::__event__& event) noexcept;

        /**
         * @brief Extracts underlying SYCL event reference from an @ref experimental::__event__.
         * @param event Wrapped event handle.
         * @return Reference to underlying SYCL event.
         */
        static sycl::event& handle(experimental::__event__& event);

        /**
         * @brief Extracts underlying const SYCL event reference from an @ref experimental::__event__.
         * @param event Wrapped event handle.
         * @return Const reference to underlying SYCL event.
         */
        static const sycl::event& handle(const experimental::__event__& event);
    };
} // namespace cum::detail
