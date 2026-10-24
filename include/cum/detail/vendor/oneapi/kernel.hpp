/**
 * @file kernel.hpp
 * @brief SYCL kernel wrapper definition for experimental::__kernel__.
 * @author Świadomy Mężczyzna
 */

#pragma once

#include <sycl/kernel.hpp>

namespace cum::experimental
{
    /**
     * @struct __kernel__
     * @brief SYCL kernel handle wrapper.
     */
    struct __kernel__
    {
        sycl::kernel kernel; ///< Underlying SYCL kernel object.

        /**
         * @brief Returns reference to underlying SYCL kernel.
         * @return SYCL kernel reference.
         */
        sycl::kernel& operator ()();
    };
} // namespace cum::experimental
