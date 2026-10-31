/**
 * @file Engine.hpp
 * @brief Compute engine abstraction for deep learning primitives.
 * @author jaro
 */

#ifndef YANN_ENGINE_HPP
#define YANN_ENGINE_HPP

#include <memory>
#include "cum/neural_primitives/opaque_types.hpp"
#include "cum/Core.hpp"

namespace cum::neural_primitives
{
    /**
     * @class Engine
     * @brief Compute execution engine encapsulating device accelerator execution context for primitives.
     */
    class Engine
    {
    public:
        /**
         * @brief Constructs default compute engine for the active device.
         */
        Engine();

        ~Engine();

        Engine(const Engine& other);
        Engine& operator=(const Engine& other);

        Engine(Engine&& other) noexcept;
        Engine& operator=(Engine&& other) noexcept;

        /**
         * @brief Returns const reference to backend engine handle.
         */
        const handles::__engine__& native_handle() const;

        /**
         * @brief Returns mutable reference to backend engine handle.
         */
        handles::__engine__& native_handle();

    private:
        friend class Memory;
        friend class PrimitiveDescriptor;

        std::unique_ptr<handles::__engine__> handle;
    };
} // namespace cum::neural_primitives

#endif //YANN_ENGINE_HPP
