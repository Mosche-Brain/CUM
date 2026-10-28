/**
 * @file Memory.hpp
 * @brief Memory object abstraction for deep learning primitives.
 * @author jaro
 * @details Encapsulates allocated device storage managed by the underlying neural primitive engine.
 */

#ifndef YANN_TENSOR_MEMORY_HPP
#define YANN_TENSOR_MEMORY_HPP

#include <memory>

#include "cum/neural_primitives/MemoryDescriptor.hpp"
#include "cum/neural_primitives/Engine.hpp"
#include "cum/neural_primitives/opaque_types.hpp"

namespace cum::neural_primitives
{
    /**
     * @class Memory
     * @brief Storage buffer managed by neural primitive engine according to a @ref Descriptor.
     */
    class Memory
    {
    public:
        /**
         * @brief Descriptor describing the layout of this memory (alias of neural_primitives::Descriptor).
         * @note ok.
         */
        using Descriptor = MemoryDescriptor;

        /**
         * @brief Constructs memory buffer according to descriptor.
         * @param desc Memory descriptor.
         */
        Memory(const Descriptor& desc);

        /**
         * @brief Constructs memory object wrapping existing raw data pointer.
         * @param desc Memory descriptor.
         * @param data Pointer to existing memory.
         */
        Memory(const Descriptor& desc, void* data);

        /**
         * @brief Constructs memory buffer on specified compute engine.
         * @param desc Memory descriptor.
         * @param engine Target compute engine.
         */
        Memory(const Descriptor& desc, Engine& engine);

        /**
         * @brief Constructs memory object on engine wrapping existing raw data pointer.
         * @param desc Memory descriptor.
         * @param engine Target compute engine.
         * @param data Pointer to existing memory.
         */
        Memory(const Descriptor& desc, Engine& engine, void* data);

        /**
         * @brief Constructs memory view over source memory object.
         * @param desc Memory descriptor for the view.
         * @param source Underlying source memory.
         */
        Memory(const Descriptor& desc, const Memory& source);

        /**
         * @brief Constructs memory object from backend handle.
         * @param handle Backend memory handle.
         */
        Memory(handles::__memory__& handle);

        ~Memory();

        /**
         * @brief Returns pointer to mapped data buffer.
         * @return Void pointer to memory buffer.
         */
        void* data();

        /**
         * @brief Returns const pointer to mapped data buffer.
         * @return Const void pointer to memory buffer.
         */
        const void* data() const;

        /**
         * @brief Rebinds memory object to new raw data buffer.
         * @param data Pointer to memory buffer.
         */
        void set_data(void* data);

        /**
         * @brief Returns shared pointer to owner handle if this is a view.
         * @return Owner handle pointer.
         */
        std::shared_ptr<handles::__memory__> owner() const;

        /**
         * @brief Returns const reference to backend memory handle.
         * @return Backend handle.
         */
        const handles::__memory__& handle() const;

        /**
         * @brief Returns mutable reference to backend memory handle.
         * @return Backend handle.
         */
        handles::__memory__& handle();

    private:
        friend class Tensor;

        std::shared_ptr<handles::__memory__> handle_;
        std::shared_ptr<handles::__memory__> owner_;
    };

} // namespace cum::neural_primitives

#endif //YANN_TENSOR_MEMORY_HPP
