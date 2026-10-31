#ifndef CUM_C_NEURAL_PRIMITIVES_H
#define CUM_C_NEURAL_PRIMITIVES_H

#include <stdbool.h>
#include <stddef.h>

#include "cum/core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Propagation modes mirroring cum::neural_primitives::Purpose. */
typedef enum cum_purpose_t
{
    CUM_PURPOSE_FORWARD = 64,
    CUM_PURPOSE_FORWARD_TRAINING = 64,
    CUM_PURPOSE_FORWARD_INFERENCE = 96,
    CUM_PURPOSE_BACKWARD = 128,
    CUM_PURPOSE_BACKWARD_DATA = 160,
    CUM_PURPOSE_BACKWARD_WEIGHTS = 192,
    CUM_PURPOSE_BACKWARD_BIAS = 193
} cum_purpose_t;

/* Algorithm tags mirroring cum::neural_primitives::Algo. */
typedef enum cum_algo_t
{
    CUM_ALGO_UNDEF = 0,

    /* Elementwise algorithms (forward & backward) */
    CUM_ALGO_ELTWISE_RELU = 1,
    CUM_ALGO_ELTWISE_TANH = 2,
    CUM_ALGO_ELTWISE_ELU = 3,
    CUM_ALGO_ELTWISE_SQUARE = 4,
    CUM_ALGO_ELTWISE_ABS = 5,
    CUM_ALGO_ELTWISE_SQRT = 6,
    CUM_ALGO_ELTWISE_LINEAR = 7,
    CUM_ALGO_ELTWISE_SOFT_RELU = 8,
    CUM_ALGO_ELTWISE_LOGISTIC = 9,
    CUM_ALGO_ELTWISE_EXP = 10,
    CUM_ALGO_ELTWISE_GELU_TANH = 11,
    CUM_ALGO_ELTWISE_GELU_ERF = 12,
    CUM_ALGO_ELTWISE_SWISH = 13,
    CUM_ALGO_ELTWISE_MISH = 14,
    CUM_ALGO_ELTWISE_LOG = 15,
    CUM_ALGO_ELTWISE_CLIP = 16,
    CUM_ALGO_ELTWISE_CLIP_V2 = 17,
    CUM_ALGO_ELTWISE_POW = 18,
    CUM_ALGO_ELTWISE_ROUND = 19,
    CUM_ALGO_ELTWISE_HARDSWISH = 20,
    CUM_ALGO_ELTWISE_HARDSIGMOID = 21,

    /* Elementwise algorithms consuming forward destination `dst` in backward pass */
    CUM_ALGO_ELTWISE_RELU_USE_DST_FOR_BWD = 22,
    CUM_ALGO_ELTWISE_TANH_USE_DST_FOR_BWD = 23,
    CUM_ALGO_ELTWISE_ELU_USE_DST_FOR_BWD = 24,
    CUM_ALGO_ELTWISE_SQRT_USE_DST_FOR_BWD = 25,
    CUM_ALGO_ELTWISE_LOGISTIC_USE_DST_FOR_BWD = 26,
    CUM_ALGO_ELTWISE_EXP_USE_DST_FOR_BWD = 27,
    CUM_ALGO_ELTWISE_CLIP_V2_USE_DST_FOR_BWD = 28,

    /* Binary tensor operations (supporting per-dimension broadcast) */
    CUM_ALGO_BINARY_ADD = 0x100,
    CUM_ALGO_BINARY_SUB = 0x101,
    CUM_ALGO_BINARY_MUL = 0x102,
    CUM_ALGO_BINARY_DIV = 0x103,
    CUM_ALGO_BINARY_MAX = 0x104,
    CUM_ALGO_BINARY_MIN = 0x105,
    CUM_ALGO_BINARY_EQ = 0x106,
    CUM_ALGO_BINARY_NE = 0x107,
    CUM_ALGO_BINARY_GT = 0x108,
    CUM_ALGO_BINARY_GE = 0x109,
    CUM_ALGO_BINARY_LT = 0x10A,
    CUM_ALGO_BINARY_LE = 0x10B,

    /* Softmax operations */
    CUM_ALGO_SOFTMAX_ACCURATE = 0x200,
    CUM_ALGO_SOFTMAX_LOG = 0x201,

    /* Reduction operations */
    CUM_ALGO_REDUCTION_MAX = 0x300,
    CUM_ALGO_REDUCTION_MIN = 0x301,
    CUM_ALGO_REDUCTION_SUM = 0x302,
    CUM_ALGO_REDUCTION_MUL = 0x303,
    CUM_ALGO_REDUCTION_MEAN = 0x304,
    CUM_ALGO_REDUCTION_NORM_LP_MAX = 0x305,
    CUM_ALGO_REDUCTION_NORM_LP_SUM = 0x306,
    CUM_ALGO_REDUCTION_NORM_LP_POWER_P_MAX = 0x307,
    CUM_ALGO_REDUCTION_NORM_LP_POWER_P_SUM = 0x308,

    /* Ergonomic aliases */
    CUM_ALGO_ELTWISE_LEAKY_RELU = CUM_ALGO_ELTWISE_RELU,
    CUM_ALGO_ELTWISE_SIGMOID = CUM_ALGO_ELTWISE_LOGISTIC,
    CUM_ALGO_ELTWISE_GELU = CUM_ALGO_ELTWISE_GELU_TANH,
    CUM_ALGO_ELTWISE_CLAMP = CUM_ALGO_ELTWISE_CLIP
} cum_algo_t;

/* Primitive operation categories mirroring cum::neural_primitives::PrimitiveDescriptor::Kind. */
typedef enum cum_primitive_kind_t
{
    CUM_PRIMITIVE_UNDEF = 0,
    CUM_PRIMITIVE_BINARY = 1,
    CUM_PRIMITIVE_ELEMENTWISE = 2,
    CUM_PRIMITIVE_MATMUL = 3,
    CUM_PRIMITIVE_SOFTMAX = 4,
    CUM_PRIMITIVE_REDUCTION = 5,
    CUM_PRIMITIVE_REORDER = 6,
    CUM_PRIMITIVE_SUM = 7,
    CUM_PRIMITIVE_CONCAT = 8
} cum_primitive_kind_t;

/* Named argument slots mirroring cum::neural_primitives::Primitive::Argument. */
typedef enum cum_primitive_arg_t
{
    CUM_ARG_UNDEF = 0,
    CUM_ARG_SRC = 1,
    CUM_ARG_SRC_0 = 1,
    CUM_ARG_SRC_1 = 2,
    CUM_ARG_SRC_2 = 3,
    CUM_ARG_SRC_3 = 4,
    CUM_ARG_DST = 17,
    CUM_ARG_DST_0 = 17,
    CUM_ARG_WEIGHTS = 33,
    CUM_ARG_BIAS = 41,
    CUM_ARG_WORKSPACE = 64,
    CUM_ARG_SCRATCHPAD = 80,
    CUM_ARG_DIFF_SRC = 129,
    CUM_ARG_DIFF_SRC_0 = 129,
    CUM_ARG_DIFF_SRC_1 = 130,
    CUM_ARG_DIFF_DST = 145,
    CUM_ARG_DIFF_WEIGHTS = 161,
    CUM_ARG_DIFF_BIAS = 169,
    CUM_ARG_MULTIPLE_SRC = 1024
} cum_primitive_arg_t;

/* Computes variadic source slot `CUM_ARG_MULTIPLE_SRC + index` for Sum and Concat primitives. */
#define CUM_ARG_MULTIPLE_SRC_AT(index) ((cum_primitive_arg_t)((int)CUM_ARG_MULTIPLE_SRC + (int)(index)))

/* Named memory argument binding for cum_primitive_execute(). */
typedef struct cum_memory_arg_t
{
    cum_primitive_arg_t arg;
    const cum_memory_t* memory;
} cum_memory_arg_t;

/* Named tensor argument binding for cum_primitive_execute_tensors(). */
typedef struct cum_tensor_arg_t
{
    cum_primitive_arg_t arg;
    const cum_tensor_t* tensor;
} cum_tensor_arg_t;

/* --------------------------------------------------------------------------
 * MemoryDescriptor
 * -------------------------------------------------------------------------- */

CUM_C_API cum_status_t cum_memory_desc_create(
    cum_memory_desc_t** desc,
    cum_shape_t shape,
    cum_datatype_t datatype,
    cum_layout_t layout
);
CUM_C_API cum_status_t cum_memory_desc_create_strided(
    cum_memory_desc_t** desc,
    cum_shape_t shape,
    cum_datatype_t datatype,
    cum_shape_t strides
);
CUM_C_API cum_status_t cum_memory_desc_create_any(
    cum_memory_desc_t** desc,
    cum_shape_t shape,
    cum_datatype_t datatype
);
CUM_C_API cum_status_t cum_memory_desc_clone(
    cum_memory_desc_t** dst,
    const cum_memory_desc_t* src
);
CUM_C_API cum_status_t cum_memory_desc_destroy(cum_memory_desc_t* desc);

CUM_C_API cum_status_t cum_memory_desc_valid(const cum_memory_desc_t* desc, bool* is_valid);
CUM_C_API cum_status_t cum_memory_desc_equal(
    const cum_memory_desc_t* lhs,
    const cum_memory_desc_t* rhs,
    bool* is_equal
);
CUM_C_API cum_status_t cum_memory_desc_size(const cum_memory_desc_t* desc, dim_t* size);
CUM_C_API cum_status_t cum_memory_desc_ndims(const cum_memory_desc_t* desc, dim_t* ndims);
/* When `dims` / `strides` is NULL only `*rank` is written. */
CUM_C_API cum_status_t cum_memory_desc_shape(
    const cum_memory_desc_t* desc,
    dim_t* dims,
    size_t capacity,
    size_t* rank
);
CUM_C_API cum_status_t cum_memory_desc_strides(
    const cum_memory_desc_t* desc,
    dim_t* strides,
    size_t capacity,
    size_t* rank
);
CUM_C_API cum_status_t cum_memory_desc_datatype(const cum_memory_desc_t* desc, cum_datatype_t* datatype);
CUM_C_API cum_status_t cum_memory_desc_layout(const cum_memory_desc_t* desc, cum_layout_t* layout);
CUM_C_API cum_status_t cum_memory_desc_reshape(
    cum_memory_desc_t** dst,
    const cum_memory_desc_t* src,
    cum_shape_t shape
);

/* --------------------------------------------------------------------------
 * Memory
 * -------------------------------------------------------------------------- */

/* Allocates shared USM storage matching `desc`. */
CUM_C_API cum_status_t cum_memory_create(cum_memory_t** memory, const cum_memory_desc_t* desc);
/* Wraps an external device-accessible pointer `data` without taking ownership. */
CUM_C_API cum_status_t cum_memory_create_from_ptr(
    cum_memory_t** memory,
    const cum_memory_desc_t* desc,
    void* data
);
/* Creates a memory view over `source` with layout/shape `view_desc`. */
CUM_C_API cum_status_t cum_memory_create_view(
    cum_memory_t** memory,
    const cum_memory_desc_t* view_desc,
    const cum_memory_t* source
);
CUM_C_API cum_status_t cum_memory_destroy(cum_memory_t* memory);

CUM_C_API cum_status_t cum_memory_valid(const cum_memory_t* memory, bool* is_valid);
CUM_C_API cum_status_t cum_memory_desc(const cum_memory_t* memory, cum_memory_desc_t** desc);
CUM_C_API cum_status_t cum_memory_data(const cum_memory_t* memory, const void** data);
CUM_C_API cum_status_t cum_memory_mutable_data(cum_memory_t* memory, void** data);
CUM_C_API cum_status_t cum_memory_set_data(cum_memory_t* memory, void* data);

/* --------------------------------------------------------------------------
 * PrimitiveDescriptor
 * -------------------------------------------------------------------------- */

CUM_C_API cum_status_t cum_primitive_desc_create_binary(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src0,
    const cum_memory_desc_t* src1
);
CUM_C_API cum_status_t cum_primitive_desc_create_eltwise_forward(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src,
    float alpha,
    float beta,
    cum_purpose_t purpose
);
/* `hint_fwd_pd` may be NULL, in which case the forward hint is synthesized automatically. */
CUM_C_API cum_status_t cum_primitive_desc_create_eltwise_backward(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* diff_src,
    const cum_memory_desc_t* diff_dst,
    const cum_memory_desc_t* data,
    const cum_primitive_desc_t* hint_fwd_pd,
    float alpha,
    float beta
);
/* `bias` may be NULL when no additive bias is used. */
CUM_C_API cum_status_t cum_primitive_desc_create_matmul(
    cum_primitive_desc_t** pd,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src,
    const cum_memory_desc_t* weights,
    const cum_memory_desc_t* bias
);
CUM_C_API cum_status_t cum_primitive_desc_create_softmax_forward(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src,
    int axis,
    cum_purpose_t purpose
);
/* `hint_fwd_pd` may be NULL, in which case the forward hint is synthesized automatically. */
CUM_C_API cum_status_t cum_primitive_desc_create_softmax_backward(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* diff_src,
    const cum_memory_desc_t* diff_dst,
    const cum_memory_desc_t* dst,
    int axis,
    const cum_primitive_desc_t* hint_fwd_pd
);
CUM_C_API cum_status_t cum_primitive_desc_create_reduction(
    cum_primitive_desc_t** pd,
    cum_algo_t algo,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src,
    float p,
    float eps
);
CUM_C_API cum_status_t cum_primitive_desc_create_reorder(
    cum_primitive_desc_t** pd,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* src
);
/* `scales` may be NULL (defaults to 1.0f for every input). */
CUM_C_API cum_status_t cum_primitive_desc_create_sum(
    cum_primitive_desc_t** pd,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* const* srcs,
    size_t num_srcs,
    const float* scales
);
/* `dst` may be NULL to let the backend deduce the optimal output layout (query via cum_primitive_desc_dst_desc). */
CUM_C_API cum_status_t cum_primitive_desc_create_concat(
    cum_primitive_desc_t** pd,
    const cum_memory_desc_t* dst,
    const cum_memory_desc_t* const* srcs,
    size_t num_srcs,
    int axis
);

CUM_C_API cum_status_t cum_primitive_desc_clone(
    cum_primitive_desc_t** dst,
    const cum_primitive_desc_t* src
);
CUM_C_API cum_status_t cum_primitive_desc_destroy(cum_primitive_desc_t* pd);

CUM_C_API cum_status_t cum_primitive_desc_valid(const cum_primitive_desc_t* pd, bool* is_valid);
CUM_C_API cum_status_t cum_primitive_desc_kind(const cum_primitive_desc_t* pd, cum_primitive_kind_t* kind);
CUM_C_API cum_status_t cum_primitive_desc_purpose(const cum_primitive_desc_t* pd, cum_purpose_t* purpose);
CUM_C_API cum_status_t cum_primitive_desc_algo(const cum_primitive_desc_t* pd, cum_algo_t* algo);
/* Borrowed NUL-terminated string valid for the lifetime of `pd`. */
CUM_C_API cum_status_t cum_primitive_desc_impl_info(const cum_primitive_desc_t* pd, const char** info);

/* Resolved memory descriptor queries (caller owns returned `*desc` and must free it with cum_memory_desc_destroy). */
CUM_C_API cum_status_t cum_primitive_desc_src_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_dst_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_weights_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_bias_desc(
    const cum_primitive_desc_t* pd,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_diff_src_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_diff_dst_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_diff_weights_desc(
    const cum_primitive_desc_t* pd,
    int index,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_workspace_desc(
    const cum_primitive_desc_t* pd,
    cum_memory_desc_t** desc
);
CUM_C_API cum_status_t cum_primitive_desc_scratchpad_desc(
    const cum_primitive_desc_t* pd,
    cum_memory_desc_t** desc
);

/* --------------------------------------------------------------------------
 * Primitive
 * -------------------------------------------------------------------------- */

CUM_C_API cum_status_t cum_primitive_create(cum_primitive_t** prim, const cum_primitive_desc_t* pd);
CUM_C_API cum_status_t cum_primitive_clone(cum_primitive_t** dst, const cum_primitive_t* src);
CUM_C_API cum_status_t cum_primitive_destroy(cum_primitive_t* prim);

CUM_C_API cum_status_t cum_primitive_valid(const cum_primitive_t* prim, bool* is_valid);
CUM_C_API cum_status_t cum_primitive_kind(const cum_primitive_t* prim, cum_primitive_kind_t* kind);
/* Caller owns returned `*pd` and must release it with cum_primitive_desc_destroy(). */
CUM_C_API cum_status_t cum_primitive_get_desc(const cum_primitive_t* prim, cum_primitive_desc_t** pd);

/* Execution functions follow cum/event.h semantics:
 * - `deps` may be NULL when `num_deps == 0`.
 * - When `event == NULL`, execution blocks until completion.
 * - When `event != NULL`, execution runs asynchronously and stores a handle in `*event`
 *   that the caller must release with cum_event_destroy(). */
CUM_C_API cum_status_t cum_primitive_execute(
    const cum_primitive_t* prim,
    const cum_memory_arg_t* args,
    size_t num_args,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);
CUM_C_API cum_status_t cum_primitive_execute_tensors(
    const cum_primitive_t* prim,
    const cum_tensor_arg_t* args,
    size_t num_args,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);

/* Positional execution helpers over cum_tensor_t. */
CUM_C_API cum_status_t cum_primitive_execute_unary(
    const cum_primitive_t* prim,
    cum_tensor_t* dst,
    const cum_tensor_t* src0,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);
CUM_C_API cum_status_t cum_primitive_execute_binary(
    const cum_primitive_t* prim,
    cum_tensor_t* dst,
    const cum_tensor_t* src0,
    const cum_tensor_t* src1,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);
CUM_C_API cum_status_t cum_primitive_execute_ternary(
    const cum_primitive_t* prim,
    cum_tensor_t* dst,
    const cum_tensor_t* src0,
    const cum_tensor_t* src1,
    const cum_tensor_t* src2,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);

/* Positional execution helpers over cum_memory_t. */
CUM_C_API cum_status_t cum_primitive_execute_memory_unary(
    const cum_primitive_t* prim,
    cum_memory_t* dst,
    const cum_memory_t* src0,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);
CUM_C_API cum_status_t cum_primitive_execute_memory_binary(
    const cum_primitive_t* prim,
    cum_memory_t* dst,
    const cum_memory_t* src0,
    const cum_memory_t* src1,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);
CUM_C_API cum_status_t cum_primitive_execute_memory_ternary(
    const cum_primitive_t* prim,
    cum_memory_t* dst,
    const cum_memory_t* src0,
    const cum_memory_t* src1,
    const cum_memory_t* src2,
    const cum_event_t* const* deps,
    size_t num_deps,
    cum_event_t** event
);

#ifdef __cplusplus
}
#endif

#endif /* CUM_C_NEURAL_PRIMITIVES_H */
