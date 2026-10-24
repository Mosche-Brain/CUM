/**
 * @file various.hpp
 * @brief Miscellaneous elementwise mathematical utilities (fill, clamp, clip, abs, min, max, equal, linspace).
 * @author jaro
 */

#pragma once

#include "cum/Core.hpp"

namespace cum::functions::various
{
    /**
     * @brief Fills vector @p v with constant scalar @p val.
     * @param v Output vector buffer.
     * @param val Scalar value to fill.
     * @param N Element count.
     */
    void fill(cumeric_t* v, cumeric_t val, std::size_t N);

    /**
     * @brief Fills generic memory buffer @p v with constant scalar @p val.
     * @param dtype Runtime datatype tag.
     * @param v Output memory buffer.
     * @param val Scalar value to fill.
     * @param N Element count.
     */
    void fill(datatype dtype, void* v, cumeric_t val, std::size_t N);

    /**
     * @brief Clamps scalar value @p a between @p min and @p max.
     * @param a Input scalar value.
     * @param min Minimum boundary.
     * @param max Maximum boundary.
     * @return Clamped value.
     */
    cumeric_t clamp(cumeric_t a, cumeric_t min, cumeric_t max);

    /**
     * @brief Clips vector elements between @p min and @p max out-of-place.
     * @param r Output vector buffer.
     * @param v Input vector buffer.
     * @param min Minimum boundary.
     * @param max Maximum boundary.
     * @param N Element count.
     */
    void clip(cumeric_t* r, const cumeric_t* v, cumeric_t min, cumeric_t max, std::size_t N);

    /**
     * @brief Clips vector elements between @p min and @p max in-place.
     * @param v Vector buffer modified in place.
     * @param min Minimum boundary.
     * @param max Maximum boundary.
     * @param N Element count.
     */
    void clipInPlace(cumeric_t* v, cumeric_t min, cumeric_t max, std::size_t N);

    void clip(datatype dtype, void* r, const void* v, cumeric_t min, cumeric_t max, std::size_t N);
    void clipInPlace(datatype dtype, void* v, cumeric_t min, cumeric_t max, std::size_t N);

    /**
     * @brief Evaluates absolute value of scalar @p x: |x|.
     * @param x Input scalar.
     * @return Absolute value.
     */
    cumeric_t abs(cumeric_t x);

    /**
     * @brief Returns minimum of two scalar values.
     * @param a First value.
     * @param b Second value.
     * @return Minimum value.
     */
    cumeric_t min(cumeric_t a, cumeric_t b);

    /**
     * @brief Returns maximum of two scalar values.
     * @param a First value.
     * @param b Second value.
     * @return Maximum value.
     */
    cumeric_t max(cumeric_t a, cumeric_t b);

    /**
     * @brief Compares two vectors for elementwise equality.
     * @param v First vector buffer.
     * @param u Second vector buffer.
     * @param N Element count.
     * @return True if all elements are equal, false otherwise.
     */
    bool equal(const cumeric_t* v, const cumeric_t* u, std::size_t N);

    /**
     * @brief Compares two generic buffers for elementwise equality.
     * @param dtype Runtime datatype tag.
     * @param v First memory buffer.
     * @param u Second memory buffer.
     * @param N Element count.
     * @return True if all elements are equal, false otherwise.
     */
    bool equal(datatype dtype, const void* v, const void* u, std::size_t N);

    /**
     * @brief Generates linearly spaced values between @p start and @p end into @p v.
     * @param v Output vector buffer.
     * @param start Initial value.
     * @param end Final value.
     * @param N Number of points.
     */
    void linespace(cumeric_t* v, cumeric_t start, cumeric_t end, std::size_t N);

    /**
     * @brief Generates linearly spaced values into generic buffer.
     * @param dtype Runtime datatype tag.
     * @param v Output memory buffer.
     * @param start Initial value.
     * @param end Final value.
     * @param N Number of points.
     */
    void linespace(datatype dtype, void* v, cumeric_t start, cumeric_t end, std::size_t N);

} // namespace cum::functions::various
