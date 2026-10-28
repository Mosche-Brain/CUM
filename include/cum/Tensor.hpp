/**
 * @file Tensor.hpp
 * @brief Dynamic N-dimensional tensor class with neural primitive descriptors and deep learning operations.
 * @author jaro
 * @details Represents arbitrary rank, multi-datatype, strided N-dimensional tensors with automatic or custom
 *          memory layouts, device execution, neural network primitives, and mathematical kernels.
 */

#pragma once

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <valarray>

#include "Matrix.hpp"
#include "cum/Core.hpp"
#include "cum/memory.hpp"
#include "cum/neural_primitives/MemoryDescriptor.hpp"
#include "cum/neural_primitives/Memory.hpp"
#include "cum/neural_primitives/opaque_types.hpp"
#include "functions/function_id.hpp"

/* TODO:
 *  Add templated overloads for member functions returning cumeric_t
 */

namespace cum
{
    /**
     * @struct datatype_of
     * @brief Type trait mapping a static C++ type to its runtime @ref datatype enum tag.
     * @tparam T The static C++ type.
     */
    template<typename T>
    struct datatype_of;

    /**
     * @class Tensor
     * @brief Core N-dimensional array and deep learning tensor.
     * @details Encapsulates shape, memory layout, element datatype, unified memory allocation,
     *          and integration with neural primitive kernels (oneDNN / BLAS).
     */
    class Tensor
    {
    public:
        /* Constructors */

        /**
         * @brief Constructs an uninitialized Tensor with the given shape, datatype, and layout.
         * @param shape Tensor dimensions vector.
         * @param dtype Element datatype tag (default is @ref default_type).
         * @param layout Memory layout tag (default is layout::ANY).
         */
        Tensor(const Shape& shape, datatype dtype = default_type, layout layout = layout::ANY);

        /**
         * @brief Default constructor creating an empty tensor.
         */
        Tensor() = default;

        /**
         * @brief Constructs a Tensor backed by an existing neural primitive descriptor.
         * @param descriptor Neural primitive memory descriptor.
         */
        Tensor(neural_primitives::MemoryDescriptor& descriptor);

        /**
         * @brief Constructs a 0D scalar tensor holding a single scalar value.
         * @param value Scalar initial value.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(cumeric_t value, datatype dtype = default_type, layout layout = layout::A);

        /**
         * @brief Constructs a 1D vector tensor of the given length.
         * @param lenght Number of elements.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(dim_t lenght, datatype dtype = default_type, layout layout = layout::A);

        /**
         * @brief Constructs a 2D matrix tensor.
         * @param rows Number of rows.
         * @param cols Number of columns.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(dim_t rows, dim_t cols, datatype dtype = default_type, layout layout = layout::AB);

        /**
         * @brief Constructs a 3D rank-3 tensor.
         * @param axis0 Extent along axis 0.
         * @param axis1 Extent along axis 1.
         * @param axis2 Extent along axis 2.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(dim_t axis0, dim_t axis1, dim_t axis2, datatype dtype = default_type, layout layout = layout::ABC);

        /**
         * @brief Constructs a 4D rank-4 tensor.
         * @param axis0 Extent along axis 0.
         * @param axis1 Extent along axis 1.
         * @param axis2 Extent along axis 2.
         * @param axis3 Extent along axis 3.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(dim_t axis0, dim_t axis1, dim_t axis2, dim_t axis3, datatype dtype = default_type, layout layout = layout::ABCD);

        /**
         * @brief Constructs a 5D rank-5 tensor.
         * @param axis0 Extent along axis 0.
         * @param axis1 Extent along axis 1.
         * @param axis2 Extent along axis 2.
         * @param axis3 Extent along axis 3.
         * @param axis4 Extent along axis 4.
         * @param dtype Element datatype.
         * @param layout Memory layout.
         */
        Tensor(dim_t axis0, dim_t axis1, dim_t axis2, dim_t axis3, dim_t axis4, datatype dtype = default_type, layout layout = layout::ABCDE);

        /**
         * @brief Copy constructor performing deep copy of tensor descriptor and memory buffer.
         * @param tensor Tensor to copy from.
         */
        Tensor(const Tensor& tensor);

        /**
         * @brief Move constructor transferring resource ownership without copying memory.
         * @param tensor Tensor to move from.
         */
        Tensor(Tensor&& tensor) noexcept;

        /**
         * @brief Template constructor initializing a multi-dimensional tensor from a flat vector of values.
         * @tparam T Element type.
         * @tparam dims Variadic dimension list defining tensor shape.
         * @param values Initial element values.
         */
        template<typename T, dim_t... dims>
        Tensor(const std::vector<T>& values);

        /**
         * @brief Destructor releasing tensor memory.
         */
        ~Tensor();

        /* Factories */

        /**
         * @brief Factory creating a tensor with compile-time specified datatype and layout tags.
         * @tparam T Runtime datatype enum value.
         * @tparam layout Layout tag enum value.
         * @param shape Tensor dimensions.
         * @return Newly created Tensor.
         */
        template<datatype T, layout layout>
        static Tensor create_tensor(const Shape& shape);

        /**
         * @brief Wraps existing non-owned memory buffer without allocating new storage.
         * @param shape Tensor dimensions.
         * @param data Pointer to external memory.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return Tensor viewing external memory.
         */
        static Tensor take_memory(const Shape& shape, void* data, datatype dtype = datatype::FP32, layout layout = layout::ANY);

        /**
         * @brief Creates a tensor by allocating storage and copying data from an external buffer.
         * @param shape Tensor dimensions.
         * @param data Pointer to external source memory.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return Newly allocated Tensor with copied contents.
         */
        static Tensor copy_memory(const Shape& shape, void* data, datatype dtype = datatype::FP32, layout layout = layout::ANY);

        /**
         * @brief Creates a 3D cube tensor.
         * @param width Dimension along width.
         * @param height Dimension along height.
         * @param deepth Dimension along depth.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return 3D Tensor.
         */
        static Tensor make_cube(dim_t width, dim_t height, dim_t deepth, datatype dtype = default_type, layout layout = layout::OI);

        /**
         * @brief Creates a 2D matrix tensor.
         * @param rows Row count.
         * @param cols Column count.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return 2D Tensor.
         */
        static Tensor make_matrix(dim_t rows, dim_t cols, datatype dtype = default_type, layout layout = layout::OI);

        /**
         * @brief Creates a 1D vector tensor.
         * @param lenght Length of vector.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return 1D Tensor.
         */
        static Tensor make_vector(dim_t lenght, datatype dtype = default_type, layout layout = layout::X);

        /**
         * @brief Creates a 0D scalar tensor.
         * @param dtype Datatype tag.
         * @param layout Memory layout tag.
         * @return 0D scalar Tensor.
         */
        static Tensor make_scalar(datatype dtype = default_type, layout layout = layout::X);

        /**
         * @brief Creates a tensor filled with uniformly distributed random numbers.
         * @param shape Tensor dimensions.
         * @param min Minimum random bound (default -1.0).
         * @param max Maximum random bound (default 1.0).
         * @param dtype Element datatype tag.
         * @param layout Memory layout tag.
         * @return Randomly initialized Tensor.
         */
        static Tensor Random(const Shape& shape, cumeric_t min = -1_c, cumeric_t max = 1_c, datatype dtype = datatype::FP32, layout layout = layout::ANY);

        /**
         * @brief Creates a tensor filled with zeros.
         * @param shape Tensor dimensions.
         * @param dtype Element datatype tag.
         * @param layout Memory layout tag.
         * @return Zero-filled Tensor.
         */
        static Tensor Zeros(const Shape& shape, datatype dtype = datatype::FP32, layout layout = layout::ANY);

        /**
         * @brief Creates a tensor filled with ones.
         * @param shape Tensor dimensions.
         * @param dtype Element datatype tag.
         * @param layout Memory layout tag.
         * @return Ones-filled Tensor.
         */
        static Tensor Ones(const Shape& shape, datatype dtype = datatype::FP32, layout layout = layout::ANY);

        /**
         * @brief Creates a 1D vector tensor with linearly spaced values.
         * @param start Initial value.
         * @param end Final value.
         * @param num Number of values.
         * @return 1D vector Tensor.
         */
        static Tensor Linspace(cumeric_t start, cumeric_t end, dim_t num);

        /* Memory Operations */

        /**
         * @brief Converts tensor elements to another datatype in-place.
         * @param dtype Target datatype.
         * @return Reference to `*this`.
         */
        Tensor& cast(datatype dtype);

        /**
         * @brief Prefetches tensor memory to the active device.
         * @return Reference to `*this`.
         */
        Tensor& prefetch();

        /**
         * @brief Migrates tensor memory to host CPU.
         * @return Reference to `*this`.
         */
        Tensor& to_host();

        /**
         * @brief Migrates tensor memory to device accelerator.
         * @return Reference to `*this`.
         */
        Tensor& to_device();

        /* Getters */

        /**
         * @brief Returns total memory size in bytes.
         * @return Size in bytes.
         */
        dim_t size() const;

        /**
         * @brief Returns tensor rank (number of dimensions).
         * @return Number of axes.
         */
        dim_t rank() const;

        /**
         * @brief Returns tensor rank (number of dimensions).
         * @return Number of axes.
         */
        dim_t dims() const;

        /**
         * @brief Returns length of first dimension.
         * @return Length.
         */
        dim_t lenght() const;

        /**
         * @brief Returns total number of elements.
         * @return Element count.
         */
        dim_t elements() const;

        /**
         * @brief Returns vector of dimension lengths.
         * @return Shape vector.
         */
        Shape shape() const;

        /**
         * @brief Returns memory layout format.
         * @return Layout tag.
         */
        layout format() const;

        /**
         * @brief Returns element datatype.
         * @return Datatype tag.
         */
        datatype type() const;

        /**
         * @brief Checks whether tensor is a 0D scalar or 1-element tensor.
         * @return True if scalar, false otherwise.
         */
        bool is_scalar() const;

        /**
         * @brief Returns height (row count) for 2D+ tensors.
         * @return Rows.
         */
        dim_t rows() const;

        /**
         * @brief Returns width (column count) for 2D+ tensors.
         * @return Columns.
         */
        dim_t cols() const;

        /**
         * @brief Returns mutable reference to descriptor pointer.
         * @return Unique pointer reference to @ref neural_primitives::Descriptor.
         */
        std::unique_ptr<neural_primitives::MemoryDescriptor>& descriptor();

        /**
         * @brief Returns mutable reference to memory object pointer.
         * @return Unique pointer reference to @ref neural_primitives::Memory.
         */
        std::unique_ptr<neural_primitives::Memory>& memory();

        /**
         * @brief Returns const reference to descriptor pointer.
         * @return Const unique pointer reference to @ref neural_primitives::Descriptor.
         */
        const std::unique_ptr<neural_primitives::MemoryDescriptor>& descriptor() const;

        /**
         * @brief Returns const reference to memory object pointer.
         * @return Const unique pointer reference to @ref neural_primitives::Memory.
         */
        const std::unique_ptr<neural_primitives::Memory>& memory() const;

        /**
         * @brief Creates a deep copy clone of the tensor.
         * @return Cloned Tensor.
         */
        Tensor clone() const;

        /* Accessors */

        /**
         * @brief Returns typed pointer to underlying memory buffer.
         * @tparam T Target pointer type.
         * @return Typed pointer.
         */
        template<typename T>
        T* data() { return static_cast<T*>(data()); }

        /**
         * @brief Returns typed const pointer to underlying memory buffer.
         * @tparam T Target pointer type.
         * @return Typed const pointer.
         */
        template<typename T>
        const T* data() const { return static_cast<const T*>(data()); }

        /**
         * @brief Accesses element at specified multi-dimensional coordinate with type check.
         * @tparam T Element type.
         * @param indices Coordinate indices.
         * @return Reference to element of type @p T.
         */
        template<typename T>
        T& at(const Shape& indices);

        /**
         * @brief Accesses element at specified multi-dimensional coordinate with type check (const).
         * @tparam T Element type.
         * @param indices Coordinate indices.
         * @return Const reference to element of type @p T.
         */
        template<typename T>
        const T& at(const Shape& indices) const;

        /**
         * @brief Returns raw untyped const data pointer.
         * @return Const void pointer.
         */
        const void* data() const;

        /**
         * @brief Returns raw untyped data pointer.
         * @return Void pointer.
         */
        void* data();

        /**
         * @brief Accesses element as @ref cumeric_t at specified multi-dimensional coordinate.
         * @param indices Coordinate indices.
         * @return Reference to @ref cumeric_t element.
         */
        cumeric_t& at(const Shape& indices);

        /**
         * @brief Accesses element as @ref cumeric_t at specified multi-dimensional coordinate (const).
         * @param indices Coordinate indices.
         * @return Const reference to @ref cumeric_t element.
         */
        const cumeric_t& at(const Shape& indices) const;

        /**
         * @brief Reads scalar value at specified coordinate.
         * @param indices Coordinate indices.
         * @return Scalar value.
         */
        cumeric_t get_value(const Shape& indices) const;

        cumeric_t& operator () (const Shape& indices);
        const cumeric_t& operator () (const Shape& indices) const;
        
        cumeric_t operator ()(dim_t row, dim_t col) const;
        cumeric_t operator ()(dim_t idx0, dim_t idx1, dim_t idx2) const;
        cumeric_t operator ()(dim_t idx0, dim_t idx1, dim_t idx2, dim_t idx3) const;
        cumeric_t operator ()(dim_t idx0, dim_t idx1, dim_t idx2, dim_t idx3, dim_t idx4) const;

        /**
         * @brief Extracts a batch slice along axis 0.
         * @param index Batch index.
         * @return Sub-tensor.
         */
        Tensor batch(dim_t index) const;

        /**
         * @brief Extracts a channel slice along axis 1.
         * @param index Channel index.
         * @return Sub-tensor.
         */
        Tensor channel(dim_t index) const;

        /**
         * @brief Extracts a row slice.
         * @param index Row index.
         * @return Sub-tensor.
         */
        Tensor row(dim_t index) const;

        /**
         * @brief Extracts a column slice.
         * @param index Column index.
         * @return Sub-tensor.
         */
        Tensor col(dim_t index) const;

        /* Reshaping and Slicing */

        /**
         * @brief Extracts a sub-tensor slice specified by offset and shape.
         * @param offset Starting coordinate offset.
         * @param shape Slice dimensions.
         * @return Sub-tensor slice.
         */
        Tensor slice(const Shape& offset, const Shape& shape) const;

        /**
         * @brief Returns a reshaped tensor out-of-place.
         * @param shape New shape.
         * @return Reshaped Tensor.
         */
        Tensor reshape(const Shape& shape) const;

        /**
         * @brief Reshapes tensor in-place.
         * @param shape New shape.
         * @return Reference to `*this`.
         */
        Tensor& reshape_in_place(const Shape& shape);

        /**
         * @brief Transposes tensor dimensions out-of-place.
         * @return Transposed Tensor.
         */
        Tensor transpose() const;

        /**
         * @brief Transposes tensor dimensions in-place.
         * @return Reference to `*this`.
         */
        Tensor& transpose_in_place();

        /* Reductions */

        /**
         * @brief Computes sum of all elements.
         * @return Scalar sum.
         */
        cumeric_t sum() const;

        /**
         * @brief Computes arithmetic mean of all elements.
         * @return Scalar mean.
         */
        cumeric_t mean() const;

        /**
         * @brief Computes mean of absolute values.
         * @return Scalar mean.
         */
        cumeric_t amean() const;

        /**
         * @brief Computes Euclidean L2 norm.
         * @return L2 norm.
         */
        cumeric_t norm() const;

        /**
         * @brief Computes squared Euclidean L2 norm.
         * @return Squared L2 norm.
         */
        cumeric_t squaredNorm() const;

        /**
         * @brief Computes squared Euclidean L2 norm (snake_case alias).
         * @return Squared L2 norm.
         */
        cumeric_t squared_norm() const;

        /**
         * @brief Computes reduction sum along a specified axis.
         * @param axis Target dimension index.
         * @param keed_dims Whether to retain reduced dimension with length 1.
         * @return Reduced Tensor.
         */
        Tensor sum(dim_t axis, bool keed_dims=true) const;

        /**
         * @brief Computes softmax activation along a specified axis.
         * @param axis Axis along which softmax is applied (-1 for last axis).
         * @return Softmax Tensor.
         */
        Tensor softmax(dim_t axis = -1) const;

        Tensor colwise_sum();
        Tensor rowwise_sum();
        Tensor channelwise_sum();

        /* Elementwise Operations */

        /**
         * @brief Applies elementwise neural activation function out-of-place.
         * @param function Activation function identifier enum.
         * @return Activated Tensor.
         */
        Tensor elementwise(functions::function_id function) const;

        /**
         * @brief Applies elementwise neural activation function in-place.
         * @param function Activation function identifier enum.
         * @return Reference to `*this`.
         */
        Tensor& elementwise_in_place(functions::function_id function);

        /**
         * @brief Computes elementwise activation derivative out-of-place.
         * @param function Activation function identifier enum.
         * @return Derivative Tensor.
         */
        Tensor elementwise_diff(functions::function_id function) const;

        /**
         * @brief Computes elementwise activation derivative in-place.
         * @param function Activation function identifier enum.
         * @return Reference to `*this`.
         */
        Tensor& elementwise_diff_in_place(functions::function_id function);

        /**
         * @brief Fills all tensor elements with a scalar value.
         * @param scalar Fill value.
         * @return Reference to `*this`.
         */
        Tensor& fill(cumeric_t scalar);

        Tensor multiply(const Tensor& tensor) const;
        Tensor cwiseProduct(const Tensor& tensor) const;
        Tensor& cwise_product_in_place(const Tensor& other);

        Tensor sqrt() const;
        Tensor& sqrt_in_place();

        Tensor square() const;
        Tensor& square_in_place();

        Tensor abs() const;
        Tensor& abs_in_place();

        Tensor clamp(cumeric_t min, cumeric_t max) const;
        Tensor& clamp_in_place(cumeric_t min, cumeric_t max);

        Tensor log() const;
        Tensor& log_in_place();

        Tensor& scale(cumeric_t scalar);

        /* Matrix Multiplication */

        /**
         * @brief Performs matrix or batched tensor multiplication with another tensor.
         * @param other Right-hand side tensor operand.
         * @return Matrix multiplication result Tensor.
         */
        Tensor matmul(const Tensor& other) const;

        /* Operator Overloads */

        friend Tensor operator + (const Tensor& A, const Tensor& B);
        friend Tensor operator - (const Tensor& A, const Tensor& B);
        friend Tensor operator * (const Tensor& A, const Tensor& B);
        friend Tensor operator / (const Tensor& A, const Tensor& B);

        friend Tensor operator + (const Tensor& tensor, cumeric_t scalar);
        friend Tensor operator + (cumeric_t scalar, const Tensor& tensor);
        friend Tensor operator - (const Tensor& tensor, cumeric_t scalar);
        friend Tensor operator - (cumeric_t scalar, const Tensor& tensor);
        friend Tensor operator * (const Tensor& tensor, cumeric_t scalar);
        friend Tensor operator * (cumeric_t scalar, const Tensor& tensor);
        friend Tensor operator / (const Tensor& tensor, cumeric_t scalar);
        friend Tensor operator / (cumeric_t scalar, const Tensor& tensor);

        Tensor operator + ();
        Tensor operator - () const;

        Tensor& operator += (const Tensor& other);
        Tensor& operator -= (const Tensor& other);
        Tensor& operator *= (const Tensor& other);
        Tensor& operator /= (const Tensor& other);
        Tensor& operator /= (cumeric_t scalar);

        friend bool operator == (const Tensor& A, const Tensor& B);
        friend bool operator != (const Tensor& A, const Tensor& B);

        Tensor& operator = (const Tensor& other);
        Tensor& operator = (Tensor&& other) noexcept;

    private:
        Tensor(neural_primitives::MemoryDescriptor&& desc, const neural_primitives::Memory& source);
        dim_t compute_index(const Shape& indices) const;
        void* compute_address(const Shape& indices);

        std::unique_ptr<neural_primitives::MemoryDescriptor> _desc_;
        std::unique_ptr<neural_primitives::Memory> _memr_;
        void* _data = nullptr;
        bool _owns_data = true;
    };

    template<typename T, dim_t... dims>
    Tensor::Tensor(const std::vector<T>& values) : Tensor(Shape{dims...}, datatype_of<T>())
    {
        constexpr dim_t elements_count = (dims * ...);

        if (values.size() != elements_count)
            throw std::invalid_argument("Tensor constructor: PI(dims) != lenght of values");

        const T* data = values.data();
        cum::memory::memcopy(_data, data, elements_count * sizeof(T));
    }

    template<datatype T, layout layout>
    Tensor Tensor::create_tensor(const Shape& shape)
    {
        return {shape, T, layout};
    }

    template<typename T>
    T& Tensor::at(const Shape& indices)
    {
        if (sizeof(T) != datatype_size(this->type()))
            throw std::runtime_error("datatype size mismatch");

        return data<T>()[compute_index(indices)];
    }

    template<typename T>
    const T& Tensor::at(const Shape& indices) const
    {
        if (sizeof(T) != datatype_size(this->type()))
            throw std::runtime_error("datatype size mismatch");

        return data<T>()[compute_index(indices)];
    }

    // Specializations for datatype_of trait
    template<>
    struct datatype_of<double>
    {
        static constexpr datatype value = datatype::FP64;
    };

    template<>
    struct datatype_of<float>
    {
        static constexpr datatype value = datatype::FP32;
    };

    template<>
    struct datatype_of<cum::float16>
    {
        static constexpr datatype value = datatype::FP16;
    };

    template<>
    struct datatype_of<cum::bfloat16>
    {
        static constexpr datatype value = datatype::BF16;
    };

    template<>
    struct datatype_of<cum::float8>
    {
        static constexpr datatype value = datatype::FP8;
    };

    template<>
    struct datatype_of<std::int64_t>
    {
        static constexpr datatype value = datatype::S64;
    };

    template<>
    struct datatype_of<std::int32_t>
    {
        static constexpr datatype value = datatype::S32;
    };

    template<>
    struct datatype_of<std::int16_t>
    {
        static constexpr datatype value = datatype::S16;
    };

    template<>
    struct datatype_of<std::int8_t>
    {
        static constexpr datatype value = datatype::S8;
    };

    template<>
    struct datatype_of<std::uint64_t>
    {
        static constexpr datatype value = datatype::U64;
    };

    template<>
    struct datatype_of<std::uint32_t>
    {
        static constexpr datatype value = datatype::U32;
    };

    template<>
    struct datatype_of<std::uint16_t>
    {
        static constexpr datatype value = datatype::U16;
    };

    template<>
    struct datatype_of<std::uint8_t>
    {
        static constexpr datatype value = datatype::U8;
    };

} // namespace cum
