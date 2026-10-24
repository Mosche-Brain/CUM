/**
 * @file tensor_operations.hpp
 * @brief Multi-dimensional tensor arithmetic and matrix multiplication operations.
 * @author Świadomy Mężczyzna
 * @details Implements elementwise binary tensor arithmetic (add, sub, mul, div) and general tensor matrix multiplication (matmul)
 *          supporting raw backend handles, @ref Memory / @ref Descriptor pairs, and high-level @ref Tensor objects.
 */

#pragma once

#include "cum/neural_primitives/opaque_types.hpp"
#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/Descriptor.hpp"
#include "cum/Core.hpp"

namespace cum { class Tensor; }

namespace cum::neural_primitives
{
    /* Raw handles overloads */

    __event__ add(handles::__memory__& C, const handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& c_desc, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ sub(handles::__memory__& C, const handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& c_desc, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ mul(handles::__memory__& C, const handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& c_desc, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ div(handles::__memory__& C, const handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& c_desc, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ matmul(handles::__memory__& C, const handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& c_desc, const handles::__desc__& a_desc, const handles::__desc__& b_desc);

    __event__ add(handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ sub(handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ mul(handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ div(handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& a_desc, const handles::__desc__& b_desc);
    __event__ matmul(handles::__memory__& A, const handles::__memory__& B, const handles::__desc__& a_desc, const handles::__desc__& b_desc);

    /* RAII handles overloads */

    __event__ add(Memory& C, const Memory& A, const Memory& B, const Descriptor& c_desc, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ sub(Memory& C, const Memory& A, const Memory& B, const Descriptor& c_desc, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ mul(Memory& C, const Memory& A, const Memory& B, const Descriptor& c_desc, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ div(Memory& C, const Memory& A, const Memory& B, const Descriptor& c_desc, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ matmul(Memory& C, const Memory& A, const Memory& B, const Descriptor& c_desc, const Descriptor& a_desc, const Descriptor& b_desc);

    __event__ add(Memory& A, const Memory& B, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ sub(Memory& A, const Memory& B, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ mul(Memory& A, const Memory& B, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ div(Memory& A, const Memory& B, const Descriptor& a_desc, const Descriptor& b_desc);
    __event__ matmul(Memory& A, const Memory& B, const Descriptor& a_desc, const Descriptor& b_desc);

    /* Tensor overloads */

    /**
     * @brief Computes tensor elementwise addition: @p C = @p A + @p B.
     * @param C Output destination Tensor.
     * @param A First input Tensor.
     * @param B Second input Tensor.
     * @return Asynchronous execution event.
     */
    __event__ add(Tensor& C, const Tensor& A, const Tensor& B);

    /**
     * @brief Computes tensor elementwise subtraction: @p C = @p A - @p B.
     * @param C Output destination Tensor.
     * @param A First input Tensor.
     * @param B Second input Tensor.
     * @return Asynchronous execution event.
     */
    __event__ sub(Tensor& C, const Tensor& A, const Tensor& B);

    /**
     * @brief Computes tensor elementwise multiplication (Hadamard): @p C = @p A * @p B.
     * @param C Output destination Tensor.
     * @param A First input Tensor.
     * @param B Second input Tensor.
     * @return Asynchronous execution event.
     */
    __event__ mul(Tensor& C, const Tensor& A, const Tensor& B);

    /**
     * @brief Computes tensor elementwise division: @p C = @p A / @p B.
     * @param C Output destination Tensor.
     * @param A Numerator Tensor.
     * @param B Denominator Tensor.
     * @return Asynchronous execution event.
     */
    __event__ div(Tensor& C, const Tensor& A, const Tensor& B);

    /**
     * @brief Computes tensor matrix multiplication: @p C = @p A * @p B.
     * @param C Output product Tensor.
     * @param A Left input Tensor.
     * @param B Right input Tensor.
     * @return Asynchronous execution event.
     */
    __event__ matmul(Tensor& C, const Tensor& A, const Tensor& B);

    /**
     * @brief In-place tensor elementwise addition: @p A += @p B.
     * @param A Tensor modified in place.
     * @param B Tensor to add.
     * @return Asynchronous execution event.
     */
    __event__ add(Tensor& A, const Tensor& B);

    /**
     * @brief In-place tensor elementwise subtraction: @p A -= @p B.
     * @param A Tensor modified in place.
     * @param B Tensor to subtract.
     * @return Asynchronous execution event.
     */
    __event__ sub(Tensor& A, const Tensor& B);

    /**
     * @brief In-place tensor elementwise multiplication: @p A *= @p B.
     * @param A Tensor modified in place.
     * @param B Tensor multiplier.
     * @return Asynchronous execution event.
     */
    __event__ mul(Tensor& A, const Tensor& B);

    /**
     * @brief In-place tensor elementwise division: @p A /= @p B.
     * @param A Tensor modified in place.
     * @param B Tensor denominator.
     * @return Asynchronous execution event.
     */
    __event__ div(Tensor& A, const Tensor& B);

    /**
     * @brief In-place tensor matrix multiplication: @p A = @p A * @p B.
     * @param A Left matrix Tensor modified in place.
     * @param B Right matrix Tensor.
     * @return Asynchronous execution event.
     */
    __event__ matmul(Tensor& A, const Tensor& B);

} // namespace cum::neural_primitives
