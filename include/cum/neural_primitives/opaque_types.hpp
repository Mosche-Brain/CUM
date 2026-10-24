/**
 * @file opaque_types.hpp
 * @brief Forward declarations of backend-specific opaque handle types for neural primitives.
 * @author jaro
 */

#pragma once

namespace cum::neural_primitives::handles
{
    /** @brief Opaque backend handle for memory primitives. */
    typedef struct __memory__ __memory__;

    /** @brief Opaque backend handle for compute execution engine. */
    typedef struct __engine__ __engine__;

    /** @brief Opaque backend handle for command execution stream. */
    typedef struct __stream__ __stream__;

    /** @brief Opaque backend handle for memory descriptors. */
    typedef struct  __desc__   __desc__;
}
