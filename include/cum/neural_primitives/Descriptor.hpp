/**
 * @file Descriptor.hpp
 * @brief Multi-dimensional tensor memory descriptor for neural primitives.
 * @author jaro
 */

#ifndef YANN_TENSOR_DESCRIPTOR_HPP
#define YANN_TENSOR_DESCRIPTOR_HPP

#include <cstdint>
#include <vector>
#include <memory>

#include "cum/Core.hpp"
#include "cum/neural_primitives/opaque_types.hpp"

namespace cum::neural_primitives
{
    /**
     * @class Descriptor
     * @brief Encapsulates tensor shape, data type, and memory format layout for neural network primitives.
     */
    class Descriptor
    {
    public:
        /**
         * @brief Constructs descriptor from dimensions, datatype, and layout format.
         * @param dims Shape vector.
         * @param dtype Element datatype tag.
         * @param format Memory layout tag.
         */
        Descriptor(Shape dims, datatype dtype, layout format);

        /**
         * @brief Copy constructor.
         * @param other Descriptor to copy.
         */
        Descriptor(Descriptor& other);

        /**
         * @brief Constructs descriptor from const backend descriptor handle.
         * @param handle Backend handle.
         */
        Descriptor(const handles::__desc__& handle);

        /**
         * @brief Constructs descriptor from const backend descriptor handle and layout format.
         * @param handle Backend handle.
         * @param format Memory layout format.
         */
        Descriptor(const handles::__desc__& handle, layout format);

        /**
         * @brief Constructs descriptor from backend descriptor handle.
         * @param handle Backend handle.
         */
        Descriptor(handles::__desc__& handle);

        /**
         * @brief Move constructor.
         * @param other Descriptor to move from.
         */
        Descriptor(Descriptor&& other) noexcept;

        Descriptor& operator=(Descriptor&& other) noexcept;

        /**
         * @brief Returns total memory size in bytes required by descriptor.
         * @return Size in bytes.
         */
        dim_t size() const;

        /**
         * @brief Returns number of dimensions (rank).
         * @return Rank.
         */
        dim_t ndims() const;

        /**
         * @brief Returns shape dimensions vector.
         * @return Shape.
         */
        Shape shape() const;

        /**
         * @brief Returns element datatype tag.
         * @return Datatype tag.
         */
        datatype type() const;

        /**
         * @brief Returns memory layout format.
         * @return Layout format tag.
         */
        layout format() const;

        /**
         * @brief Returns stride of descriptor.
         * @return Stride.
         */
        dim_t stride() const;

        /**
         * @brief Returns memory offset.
         * @return Offset in bytes.
         */
        dim_t offset() const;

        /**
         * @brief Reshapes descriptor out-of-place.
         * @param shape New shape.
         * @return Reshaped Descriptor.
         */
        Descriptor reshape(const Shape& shape);

        /**
         * @brief Reshapes descriptor in-place.
         * @param shape New shape.
         * @return Reference to `*this`.
         */
        Descriptor& reshape_in_place(const Shape& shape);

        /**
         * @brief Returns const reference to backend handle.
         * @return Backend handle.
         */
        const handles::__desc__& handle() const;

        /**
         * @brief Returns mutable reference to backend handle.
         * @return Backend handle.
         */
        handles::__desc__& handle();

        Descriptor& operator = (Descriptor& other);
        ~Descriptor();

    private:
        friend class Memory;
        friend class Tensor;

        std::unique_ptr<handles::__desc__> handle_;
        layout fmt;
    };
} // namespace cum::neural_primitives

#endif //YANN_TENSOR_DESCRIPTOR_HPP
