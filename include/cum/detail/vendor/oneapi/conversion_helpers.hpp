/**
 * @file conversion_helpers.hpp
 * @brief Bidirectional conversion helpers between CUM enums and oneDNN enumerations.
 * @author jaro
 * @details Translates algorithms, data types, and format layouts between CUM and Intel oneDNN.
 */

#ifndef YANN_CONVERSION_HELPERS_HPP
#define YANN_CONVERSION_HELPERS_HPP

#include <oneapi/dnnl/dnnl.hpp>

#include "cum/Core.hpp"
#include "cum/functions/function_id.hpp"

namespace cum
{
    /**
     * @brief Converts CUM @ref functions::function_id to oneDNN algorithm enumeration.
     * @param id Function identifier.
     * @return Corresponding oneDNN algorithm.
     */
    dnnl::algorithm dnnl_algorithm(functions::function_id id);

    /**
     * @brief Converts CUM @ref datatype tag to oneDNN memory data_type.
     * @param dtype CUM datatype tag.
     * @return Corresponding oneDNN memory::data_type.
     */
    dnnl::memory::data_type dnnl_data_type(datatype dtype);

    /**
     * @brief Converts oneDNN memory data_type to CUM @ref datatype tag.
     * @param dtype oneDNN memory::data_type.
     * @return Corresponding CUM datatype tag.
     */
    datatype cum_data_type(dnnl::memory::data_type dtype);

    /**
     * @brief Converts CUM @ref layout tag to oneDNN format_tag.
     * @param format CUM layout tag.
     * @return Corresponding oneDNN format_tag.
     */
    dnnl::memory::format_tag dnnl_format_tag(layout format);

    /**
     * @brief Converts oneDNN format_tag to CUM @ref layout tag.
     * @param format oneDNN format_tag.
     * @return Corresponding CUM layout tag.
     */
    layout cum_format_tag(dnnl::memory::format_tag format);

} // namespace cum

#endif //YANN_CONVERSION_HELPERS_HPP
