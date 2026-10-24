/**
 * @file random.hpp
 * @brief Random number generators for filling memory buffers with uniform and normal distributions.
 * @details Supports typed (@ref cumeric_t) and generic runtime datatype buffers, with configurable seeds and bounds.
 */

#pragma once

#include "cum/Core.hpp"

namespace cum::random
{
    /**
     * @brief Generates uniformly distributed random values into a typed buffer.
     * @param buff Destination buffer of @ref cumeric_t elements.
     * @param N Number of elements to generate.
     * @param min Lower bound of the uniform distribution (default -1.0).
     * @param max Upper bound of the uniform distribution (default 1.0).
     * @param seed Random generator seed (default 2137).
     */
    void uniform(cumeric_t* buff, const std::size_t N, const cumeric_t min=-1._c, const cumeric_t max=1._c, dim_t seed=2137);

    /**
     * @brief Generates uniformly distributed random values into a generic buffer with scalar bounds.
     * @param dtype Runtime datatype tag of elements in the buffer.
     * @param buff Destination memory buffer.
     * @param N Number of elements to generate.
     * @param min Lower bound scalar value (default -1.0).
     * @param max Upper bound scalar value (default 1.0).
     * @param seed Random generator seed (default 2137).
     */
    void uniform(datatype dtype, void* buff, const std::size_t N, const cumeric_t min=-1._c, const cumeric_t max=1._c, dim_t seed=2137);

    /**
     * @brief Generates uniformly distributed random values into a generic buffer with typed raw bound pointers.
     * @param dtype Runtime datatype tag of elements in the buffer.
     * @param buff Destination memory buffer.
     * @param N Number of elements to generate.
     * @param min Pointer to the lower bound value in the matching datatype.
     * @param max Pointer to the upper bound value in the matching datatype.
     * @param seed Random generator seed (default 2137).
     */
    void uniform(datatype dtype, void* buff, const std::size_t N, const void* min, const void* max, dim_t seed=2137);

    /**
     * @brief Generates normally distributed random values (zero mean) into a typed buffer.
     * @param buff Destination buffer of @ref cumeric_t elements.
     * @param N Number of elements to generate.
     * @param sigma Standard deviation of the normal distribution.
     * @param seed Random generator seed (default 2137).
     */
    void normal(cumeric_t* buff, const std::size_t N, const cumeric_t sigma, std::size_t seed=2137);

    /**
     * @brief Generates normally distributed random values (zero mean) into a generic buffer with scalar standard deviation.
     * @param dtype Runtime datatype tag of elements in the buffer.
     * @param buff Destination memory buffer.
     * @param N Number of elements to generate.
     * @param sigma Standard deviation of the normal distribution.
     * @param seed Random generator seed (default 2137).
     */
    void normal(datatype dtype, void* buff, const std::size_t N, const cumeric_t sigma, std::size_t seed=2137);

    /**
     * @brief Generates normally distributed random values into a generic buffer with a pointer to standard deviation.
     * @param dtype Runtime datatype tag of elements in the buffer.
     * @param buff Destination memory buffer.
     * @param N Number of elements to generate.
     * @param sigma Pointer to standard deviation value in the matching datatype.
     * @param seed Random generator seed (default 2137).
     */
    void normal(datatype dtype, void* buff, const std::size_t N, const void* sigma, std::size_t seed=2137);
}
