/**
 * @file cum.hpp
 * @brief Main entry-point header for runtime initialization and lifecycle management in CUM.
 * @details Provides functions to initialize, reconfigure, and finalize the CUM library context and device runtime.
 */

#pragma once

#if __has_include(<stdfloat>)
#include <stdfloat>
#endif

#include "cum/Core.hpp"

namespace cum
{
    /**
     * @brief Initializes the CUM library context for the specified compute device.
     * @param device The target compute device (DEVICE::AUTO, DEVICE::CPU, or DEVICE::GPU). Default is DEVICE::AUTO.
     */
    void cum(DEVICE device = DEVICE::AUTO);

    /**
     * @brief Reinitializes or switches the CUM library context to another compute device.
     * @param device The target compute device to switch to. Default is DEVICE::AUTO.
     */
    void recum(DEVICE device = DEVICE::AUTO);

    /**
     * @brief Finalizes and cleans up the CUM library runtime and allocated context resources.
     */
    void decum();
}
