/**
 * @file MemoryDescriptor.hpp
 * @brief Multi-dimensional tensor memory descriptor for neural primitives.
 * @author jaro
 */

#ifndef YANN_TENSOR_DESCRIPTOR_HPP
#define YANN_TENSOR_DESCRIPTOR_HPP

#include <cstdint>
#include <memory>
#include <vector>

#include "cum/Core.hpp"
#include "cum/neural_primitives/opaque_types.hpp"

namespace cum { class Tensor; }

namespace cum::neural_primitives
{
    /**
     * @class MemoryDescriptor
     * @brief Encapsulates tensor shape, data type, and memory format layout for neural network primitives.
     */
    class MemoryDescriptor
    {
    public:
        /**
         * @brief Constructs an empty (zero) memory descriptor.
         */
        MemoryDescriptor();

        /**
         * @brief Constructs descriptor from dimensions, datatype, and layout format.
         * @param dims Shape vector.
         * @param dtype Element datatype tag.
         * @param format Memory layout tag (defaults to @ref layout::ANY).
         */
        MemoryDescriptor(Shape dims, datatype dtype, layout format = layout::ANY);

        /**
         * @brief Constructs descriptor with explicit per-dimension strides (in elements).
         * @param dims Shape vector.
         * @param dtype Element datatype tag.
         * @param strides Per-dimension stride vector.
         */
        MemoryDescriptor(Shape dims, datatype dtype, Shape strides);

        /**
         * @brief Creates a format-agnostic (`layout::ANY`) descriptor allowing primitives to pick an optimal layout.
         * @param dims Shape vector.
         * @param dtype Element datatype tag.
         * @return Format-agnostic memory descriptor.
         */
        static MemoryDescriptor Any(const Shape& dims, datatype dtype);

        /**
         * @brief Copy constructor.
         * @param other Descriptor to copy.
         */
        MemoryDescriptor(const MemoryDescriptor& other);

        /**
         * @brief Constructs descriptor from const backend descriptor handle.
         * @param handle Backend handle.
         */
        MemoryDescriptor(const handles::__desc__& handle);

        /**
         * @brief Constructs descriptor from const backend descriptor handle and layout format.
         * @param handle Backend handle.
         * @param format Memory layout format.
         */
        MemoryDescriptor(const handles::__desc__& handle, layout format);

        /**
         * @brief Constructs descriptor from backend descriptor handle.
         * @param handle Backend handle.
         */
        MemoryDescriptor(handles::__desc__& handle);

        /**
         * @brief Move constructor.
         * @param other Descriptor to move from.
         */
        MemoryDescriptor(MemoryDescriptor&& other) noexcept;

        MemoryDescriptor& operator=(const MemoryDescriptor& other);
        MemoryDescriptor& operator=(MemoryDescriptor&& other) noexcept;

        ~MemoryDescriptor();

        /**
         * @brief Checks whether this descriptor represents a non-empty memory layout.
         */
        [[nodiscard]] bool valid() const noexcept;

        /**
         * @brief Boolean conversion equivalent to @ref valid().
         */
        explicit operator bool() const noexcept { return valid(); }

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
         * @brief Returns per-dimension strides vector (empty if layout is opaque or `ANY`).
         * @return Stride vector in elements.
         */
        Shape strides() const;

        /**
         * @brief Returns leading stride of descriptor (or 0 if empty/unspecified).
         * @return Leading stride in elements.
         */
        dim_t stride() const;

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
         * @brief Returns submemory offset.
         * @return Offset in bytes.
         */
        dim_t offset() const;

        /**
         * @brief Reshapes descriptor out-of-place.
         * @param shape New shape.
         * @return Reshaped Descriptor.
         */
        MemoryDescriptor reshape(const Shape& shape) const;

        /**
         * @brief Reshapes descriptor in-place.
         * @param shape New shape.
         * @return Reference to `*this`.
         */
        MemoryDescriptor& reshape_in_place(const Shape& shape);

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

        bool operator==(const MemoryDescriptor& other) const noexcept;
        bool operator!=(const MemoryDescriptor& other) const noexcept;

    private:
        friend class Memory;
        friend class cum::Tensor;
        friend class PrimitiveDescriptor;

        std::unique_ptr<handles::__desc__> handle_;
        layout fmt = layout::UNDEF;
    };
} // namespace cum::neural_primitives

#endif //YANN_TENSOR_DESCRIPTOR_HPP
