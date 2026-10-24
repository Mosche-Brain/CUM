/**
 * @file opaque_types.hpp
 * @brief oneDNN backend handle implementations for neural primitive structures.
 * @author jaro
 */

#pragma once

#include <oneapi/dnnl/dnnl.hpp>
#include <oneapi/dnnl/dnnl_common.hpp>

#include "cum/neural_primitives/opaque_types.hpp"

namespace cum::neural_primitives::handles
{
    /** @brief Underlying oneDNN memory wrapper. */
    struct __memory__ { dnnl::memory memory; };

    /** @brief Underlying oneDNN engine wrapper. */
    struct __engine__ { dnnl::engine engine; };

    /** @brief Underlying oneDNN stream wrapper. */
    struct __stream__ { dnnl::stream stream; };

    /** @brief Underlying oneDNN memory descriptor wrapper. */
    struct  __desc__  { dnnl::memory::desc desc; };
}
