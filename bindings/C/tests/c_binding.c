/* Smoke test of the C binding. Compiled as pure C to verify that the headers are C-clean. */
#include <math.h>
#include <stdio.h>

#include "cum/cum.h"

#define CHECK(expression) \
    do { \
        if(!(expression)) { \
            fprintf(stderr, "%s:%d: check failed: %s (last error: %s)\n", \
                __FILE__, __LINE__, #expression, cum_last_error()); \
            return 1; \
        } \
    } while(0)

#define OK(call) CHECK((call) == CUM_STATUS_SUCCESS)
#define NEAR(a, b) (fabsf((a) - (b)) < 1e-4f)

static int test_tensor(void)
{
    const dim_t dims[2] = {2, 2};
    const cum_shape_t shape = {dims, 2};
    const cumeric_t a_data[4] = {1, 2, 3, 4};
    const cumeric_t b_data[4] = {5, 6, 7, 8};
    cum_tensor_t *a = NULL, *b = NULL, *c = NULL;
    const cumeric_t* out = NULL;
    cumeric_t sum = 0;
    cum_datatype_t datatype;
    size_t rank = 0;
    dim_t length = 0, read_dims[2];

    OK(cum_tensor_create_from_data(&a, shape, a_data));
    OK(cum_tensor_create_from_data(&b, shape, b_data));
    OK(cum_tensor_create_zeros(&c, shape));

    OK(cum_tensor_datatype(a, &datatype));
    CHECK(datatype == CUM_DATATYPE_FP32);
    OK(cum_tensor_shape(a, read_dims, 2, &rank));
    CHECK(rank == 2 && read_dims[0] == 2 && read_dims[1] == 2);
    OK(cum_tensor_length(a, &length));
    CHECK(length == 4);

    OK(cum_tensor_add(c, a, b));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 6) && NEAR(out[3], 12));

    OK(cum_tensor_sub(c, b, a));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 4) && NEAR(out[3], 4));

    OK(cum_tensor_mul(c, a, b)); /* element-wise */
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 5) && NEAR(out[1], 12) && NEAR(out[3], 32));

    OK(cum_tensor_div(c, b, a));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 5) && NEAR(out[1], 3));

    OK(cum_tensor_mmul(c, a, b));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 19) && NEAR(out[1], 22) && NEAR(out[2], 43) && NEAR(out[3], 50));

    OK(cum_tensor_add_in_place(c, a));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[0], 20));

    OK(cum_tensor_mul_scalar(c, a, 2.0f));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[3], 8));

    OK(cum_tensor_sum(a, &sum));
    CHECK(NEAR(sum, 10));

    OK(cum_tensor_fill(c, 3.0f));
    OK(cum_tensor_data(c, (const void**)&out));
    CHECK(NEAR(out[2], 3));

    CHECK(cum_tensor_add(NULL, a, b) == CUM_STATUS_INVALID_ARGUMENT);

    OK(cum_tensor_destroy(a));
    OK(cum_tensor_destroy(b));
    OK(cum_tensor_destroy(c));
    return 0;
}

static int test_matrix(void)
{
    const cumeric_t a_data[4] = {1, 2, 3, 4};
    const cumeric_t b_data[4] = {5, 6, 7, 8};
    cum_matrix_t *a = NULL, *b = NULL, *c = NULL;
    cumeric_t value = 0;
    dim_t rows = 0, cols = 0;

    OK(cum_matrix_create_from_data(&a, 2, 2, a_data));
    OK(cum_matrix_create_from_data(&b, 2, 2, b_data));
    OK(cum_matrix_create(&c, 2, 2));
    OK(cum_matrix_rows(a, &rows));
    OK(cum_matrix_cols(a, &cols));
    CHECK(rows == 2 && cols == 2);

    OK(cum_matrix_add(c, a, b));
    OK(cum_matrix_get(c, 1, 1, &value));
    CHECK(NEAR(value, 12));

    OK(cum_matrix_sub(c, b, a));
    OK(cum_matrix_get(c, 0, 0, &value));
    CHECK(NEAR(value, 4));

    OK(cum_matrix_mul(c, a, b)); /* matrix product */
    OK(cum_matrix_get(c, 0, 0, &value));
    CHECK(NEAR(value, 19));
    OK(cum_matrix_get(c, 1, 1, &value));
    CHECK(NEAR(value, 50));

    OK(cum_matrix_eltwise_mul(c, a, b));
    OK(cum_matrix_get(c, 0, 1, &value));
    CHECK(NEAR(value, 12));

    OK(cum_matrix_div(c, b, a));
    OK(cum_matrix_get(c, 0, 1, &value));
    CHECK(NEAR(value, 3));

    OK(cum_matrix_transpose(c, a));
    OK(cum_matrix_get(c, 0, 1, &value));
    CHECK(NEAR(value, 3));

    OK(cum_matrix_add_in_place(c, b));
    OK(cum_matrix_get(c, 0, 0, &value));
    CHECK(NEAR(value, 6));

    OK(cum_matrix_set(c, 0, 0, 42.0f));
    OK(cum_matrix_get(c, 0, 0, &value));
    CHECK(NEAR(value, 42));
    CHECK(cum_matrix_get(c, 2, 0, &value) == CUM_STATUS_INVALID_ARGUMENT);

    OK(cum_matrix_destroy(a));
    OK(cum_matrix_destroy(b));
    OK(cum_matrix_destroy(c));
    return 0;
}

static int test_vector(void)
{
    const cumeric_t a_data[3] = {1, 2, 3};
    const cumeric_t b_data[3] = {4, 5, 6};
    cum_vector_t *a = NULL, *b = NULL, *c = NULL;
    const cumeric_t* out = NULL;
    cumeric_t value = 0;
    dim_t length = 0;

    OK(cum_vector_create_from_data(&a, 3, a_data));
    OK(cum_vector_create_from_data(&b, 3, b_data));
    OK(cum_vector_create(&c, 3));
    OK(cum_vector_length(a, &length));
    CHECK(length == 3);

    OK(cum_vector_add(c, a, b));
    OK(cum_vector_data(c, &out));
    CHECK(NEAR(out[0], 5) && NEAR(out[2], 9));

    OK(cum_vector_mul(c, a, b));
    OK(cum_vector_data(c, &out));
    CHECK(NEAR(out[1], 10));

    OK(cum_vector_dot(a, b, &value));
    CHECK(NEAR(value, 32));

    OK(cum_vector_sum(a, &value));
    CHECK(NEAR(value, 6));

    OK(cum_vector_scale(c, 0.5f));
    OK(cum_vector_data(c, &out));
    CHECK(NEAR(out[1], 5));

    OK(cum_vector_destroy(a));
    OK(cum_vector_destroy(b));
    OK(cum_vector_destroy(c));
    return 0;
}

static int test_blas(void)
{
    cumeric_t *a = NULL, *b = NULL, *c = NULL, *res = NULL;
    cum_event_t* event = NULL;
    dim_t i;

    OK(cum_memory_allocate(4, &a));
    OK(cum_memory_allocate(4, &b));
    OK(cum_memory_allocate(4, &c));
    OK(cum_memory_allocate(1, &res));
    for(i = 0; i < 4; ++i)
    {
        a[i] = (cumeric_t)(i + 1);
        b[i] = (cumeric_t)(i + 5);
        c[i] = 0;
    }

    /* synchronous: event == NULL */
    OK(cum_gemm('N', 'N', 2, 2, 2, 1.0f, a, 2, b, 2, 0.0f, c, 2, NULL));
    CHECK(NEAR(c[0], 19) && NEAR(c[1], 22) && NEAR(c[2], 43) && NEAR(c[3], 50));

    OK(cum_dot(4, a, 1, b, 1, res, NULL));
    CHECK(NEAR(res[0], 70));

    /* asynchronous: event returned, then waited for */
    OK(cum_gemm('N', 'N', 2, 2, 2, 1.0f, a, 2, b, 2, 0.0f, c, 2, &event));
    CHECK(event != NULL);
    OK(cum_event_wait(event));
    OK(cum_event_destroy(event));
    CHECK(NEAR(c[3], 50));

    OK(cum_axpy(4, 2.0f, a, 1, c, 1, &event));
    OK(cum_event_wait(event));
    OK(cum_event_destroy(event));
    CHECK(NEAR(c[0], 21));

    OK(cum_scal(4, 0.5f, c, 1, NULL));
    CHECK(NEAR(c[0], 10.5f));

    OK(cum_nrm2(2, a, 1, res, NULL));
    CHECK(NEAR(res[0], sqrtf(5.0f)));

    OK(cum_synchronize());
    OK(cum_memory_free(a));
    OK(cum_memory_free(b));
    OK(cum_memory_free(c));
    OK(cum_memory_free(res));
    return 0;
}

static int test_neural_primitives(void)
{
    /* 1. MemoryDescriptor & Memory */
    const dim_t md_dims[2] = {2, 3};
    const cum_shape_t md_shape = {md_dims, 2};
    const dim_t rs_dims[2] = {3, 2};
    const cum_shape_t rs_shape = {rs_dims, 2};
    cum_memory_desc_t *md = NULL, *md_clone = NULL, *md_rs = NULL;
    cum_memory_t* mem = NULL;
    bool flag = false;
    dim_t strides[2] = {0, 0};
    size_t rank = 0;
    cumeric_t* mem_ptr = NULL;

    OK(cum_memory_desc_create(&md, md_shape, CUM_DATATYPE_FP32, CUM_LAYOUT_AB));
    OK(cum_memory_desc_valid(md, &flag));
    CHECK(flag);
    OK(cum_memory_desc_strides(md, strides, 2, &rank));
    CHECK(rank == 2 && strides[0] == 3 && strides[1] == 1);
    OK(cum_memory_desc_clone(&md_clone, md));
    OK(cum_memory_desc_equal(md, md_clone, &flag));
    CHECK(flag);
    OK(cum_memory_desc_reshape(&md_rs, md, rs_shape));
    OK(cum_memory_desc_equal(md, md_rs, &flag));
    CHECK(!flag);

    OK(cum_memory_create(&mem, md));
    OK(cum_memory_valid(mem, &flag));
    CHECK(flag);
    OK(cum_memory_mutable_data(mem, (void**)&mem_ptr));
    CHECK(mem_ptr != NULL);
    mem_ptr[0] = 7.5f;
    CHECK(NEAR(mem_ptr[0], 7.5f));

    OK(cum_memory_destroy(mem));
    OK(cum_memory_desc_destroy(md_rs));
    OK(cum_memory_desc_destroy(md_clone));
    OK(cum_memory_desc_destroy(md));

    /* 2. Matmul with bias + CUM_LAYOUT_ANY + async event chaining into Leaky ReLU + Backward */
    {
        const dim_t a_dims[2] = {2, 2}, b_dims[2] = {2, 2}, bias_dims[2] = {1, 2};
        const cum_shape_t a_sh = {a_dims, 2}, b_sh = {b_dims, 2}, bias_sh = {bias_dims, 2};
        const cumeric_t a_vals[4] = {1.0f, -2.0f, -3.0f, 1.0f};
        const cumeric_t b_vals[4] = {2.0f, 1.0f, 1.0f, 3.0f};
        const cumeric_t bias_vals[2] = {-1.0f, 0.5f};
        const cumeric_t dy_vals[4] = {1.0f, 2.0f, 3.0f, 4.0f};
        cum_tensor_t *a = NULL, *b = NULL, *bias = NULL, *mm_out = NULL, *act_out = NULL, *dy = NULL, *dx = NULL;
        cum_memory_desc_t *a_md = NULL, *b_md = NULL, *bias_md = NULL, *any_dst_md = NULL, *resolved_dst_md = NULL;
        cum_primitive_desc_t *mm_pd = NULL, *relu_pd = NULL, *relu_bwd_pd = NULL;
        cum_primitive_t *mm_prim = NULL, *relu_prim = NULL, *relu_bwd_prim = NULL;
        cum_primitive_kind_t kind = CUM_PRIMITIVE_UNDEF;
        const char* impl = NULL;
        cum_event_t *ev_mm = NULL, *ev_relu = NULL;
        const cum_event_t* deps1[1];
        const cumeric_t* out_ptr = NULL;

        OK(cum_tensor_create_from_data(&a, a_sh, a_vals));
        OK(cum_tensor_create_from_data(&b, b_sh, b_vals));
        OK(cum_tensor_create_from_data(&bias, bias_sh, bias_vals));
        OK(cum_tensor_create_from_data(&dy, a_sh, dy_vals));

        OK(cum_tensor_memory_desc(a, &a_md));
        OK(cum_tensor_memory_desc(b, &b_md));
        OK(cum_tensor_memory_desc(bias, &bias_md));
        OK(cum_memory_desc_create_any(&any_dst_md, a_sh, CUM_DATATYPE_FP32));

        OK(cum_primitive_desc_create_matmul(&mm_pd, any_dst_md, a_md, b_md, bias_md));
        OK(cum_primitive_desc_kind(mm_pd, &kind));
        CHECK(kind == CUM_PRIMITIVE_MATMUL);
        OK(cum_primitive_desc_impl_info(mm_pd, &impl));
        CHECK(impl != NULL && impl[0] != '\0');

        OK(cum_primitive_desc_dst_desc(mm_pd, 0, &resolved_dst_md));
        OK(cum_tensor_create_from_desc(&mm_out, resolved_dst_md));
        OK(cum_tensor_create_from_desc(&act_out, resolved_dst_md));
        OK(cum_tensor_create_from_desc(&dx, resolved_dst_md));

        OK(cum_primitive_create(&mm_prim, mm_pd));
        OK(cum_primitive_desc_create_eltwise_forward(
            &relu_pd, CUM_ALGO_ELTWISE_LEAKY_RELU, resolved_dst_md, resolved_dst_md,
            0.1f, 0.0f, CUM_PURPOSE_FORWARD_TRAINING));
        OK(cum_primitive_create(&relu_prim, relu_pd));

        /* Async Matmul -> dependent async LeakyReLU */
        OK(cum_primitive_execute_ternary(mm_prim, mm_out, a, b, bias, NULL, 0, &ev_mm));
        CHECK(ev_mm != NULL);
        deps1[0] = ev_mm;
        OK(cum_primitive_execute_unary(relu_prim, act_out, mm_out, deps1, 1, &ev_relu));
        CHECK(ev_relu != NULL);
        OK(cum_event_wait(ev_relu));

        /* mm_out = [[1*2 + (-2)*1 - 1, 1*1 + (-2)*3 + 0.5],
         *           [(-3)*2 + 1*1 - 1, (-3)*1 + 1*3 + 0.5]]
         *        = [[-1.0, -4.5], [-6.0, 0.5]]
         * leaky_relu(0.1): [-0.1, -0.45, -0.6, 0.5] */
        OK(cum_tensor_data(act_out, (const void**)&out_ptr));
        CHECK(NEAR(out_ptr[0], -0.1f) && NEAR(out_ptr[1], -0.45f) &&
              NEAR(out_ptr[2], -0.6f) && NEAR(out_ptr[3], 0.5f));

        /* Backward LeakyReLU */
        OK(cum_primitive_desc_create_eltwise_backward(
            &relu_bwd_pd, CUM_ALGO_ELTWISE_LEAKY_RELU,
            resolved_dst_md, resolved_dst_md, resolved_dst_md, relu_pd, 0.1f, 0.0f));
        OK(cum_primitive_create(&relu_bwd_prim, relu_bwd_pd));
        OK(cum_primitive_execute_binary(relu_bwd_prim, dx, dy, mm_out, NULL, 0, NULL));
        OK(cum_tensor_data(dx, (const void**)&out_ptr));
        CHECK(NEAR(out_ptr[0], 0.1f) && NEAR(out_ptr[1], 0.2f) &&
              NEAR(out_ptr[2], 0.3f) && NEAR(out_ptr[3], 4.0f));

        OK(cum_event_destroy(ev_relu));
        OK(cum_event_destroy(ev_mm));
        OK(cum_primitive_destroy(relu_bwd_prim));
        OK(cum_primitive_desc_destroy(relu_bwd_pd));
        OK(cum_primitive_destroy(relu_prim));
        OK(cum_primitive_desc_destroy(relu_pd));
        OK(cum_primitive_destroy(mm_prim));
        OK(cum_primitive_desc_destroy(mm_pd));
        OK(cum_memory_desc_destroy(resolved_dst_md));
        OK(cum_memory_desc_destroy(any_dst_md));
        OK(cum_memory_desc_destroy(bias_md));
        OK(cum_memory_desc_destroy(b_md));
        OK(cum_memory_desc_destroy(a_md));
        OK(cum_tensor_destroy(dx));
        OK(cum_tensor_destroy(dy));
        OK(cum_tensor_destroy(act_out));
        OK(cum_tensor_destroy(mm_out));
        OK(cum_tensor_destroy(bias));
        OK(cum_tensor_destroy(b));
        OK(cum_tensor_destroy(a));
    }

    /* 3. Concat with CUM_ARG_MULTIPLE_SRC_AT + Reduction Sum */
    {
        const dim_t s0_dims[2] = {2, 2}, red_dims[2] = {2, 1};
        const cum_shape_t s0_sh = {s0_dims, 2}, red_sh = {red_dims, 2};
        const cumeric_t x0_vals[4] = {1.0f, 2.0f, 3.0f, 4.0f};
        const cumeric_t x1_vals[4] = {10.0f, 20.0f, 30.0f, 40.0f};
        cum_tensor_t *x0 = NULL, *x1 = NULL, *cat = NULL, *red = NULL;
        cum_memory_desc_t *x0_md = NULL, *x1_md = NULL, *cat_md = NULL, *red_md = NULL;
        const cum_memory_desc_t* cat_srcs[2];
        cum_primitive_desc_t *cat_pd = NULL, *red_pd = NULL;
        cum_primitive_t *cat_prim = NULL, *red_prim = NULL;
        cum_tensor_arg_t cat_args[3];
        const cumeric_t* out_ptr = NULL;

        OK(cum_tensor_create_from_data(&x0, s0_sh, x0_vals));
        OK(cum_tensor_create_from_data(&x1, s0_sh, x1_vals));
        OK(cum_tensor_create_zeros(&red, red_sh));
        OK(cum_tensor_memory_desc(x0, &x0_md));
        OK(cum_tensor_memory_desc(x1, &x1_md));
        OK(cum_tensor_memory_desc(red, &red_md));

        cat_srcs[0] = x0_md;
        cat_srcs[1] = x1_md;
        OK(cum_primitive_desc_create_concat(&cat_pd, NULL, cat_srcs, 2, 1));
        OK(cum_primitive_desc_dst_desc(cat_pd, 0, &cat_md));
        OK(cum_tensor_create_from_desc(&cat, cat_md));
        OK(cum_primitive_create(&cat_prim, cat_pd));

        cat_args[0].arg = CUM_ARG_MULTIPLE_SRC_AT(0);
        cat_args[0].tensor = x0;
        cat_args[1].arg = CUM_ARG_MULTIPLE_SRC_AT(1);
        cat_args[1].tensor = x1;
        cat_args[2].arg = CUM_ARG_DST;
        cat_args[2].tensor = cat;
        OK(cum_primitive_execute_tensors(cat_prim, cat_args, 3, NULL, 0, NULL));

        OK(cum_primitive_desc_create_reduction(&red_pd, CUM_ALGO_REDUCTION_SUM, red_md, cat_md, 0.0f, 0.0f));
        OK(cum_primitive_create(&red_prim, red_pd));
        OK(cum_primitive_execute_unary(red_prim, red, cat, NULL, 0, NULL));

        /* Row 0: 1 + 2 + 10 + 20 = 33; Row 1: 3 + 4 + 30 + 40 = 77 */
        OK(cum_tensor_data(red, (const void**)&out_ptr));
        CHECK(NEAR(out_ptr[0], 33.0f) && NEAR(out_ptr[1], 77.0f));

        OK(cum_primitive_destroy(red_prim));
        OK(cum_primitive_desc_destroy(red_pd));
        OK(cum_primitive_destroy(cat_prim));
        OK(cum_primitive_desc_destroy(cat_pd));
        OK(cum_memory_desc_destroy(red_md));
        OK(cum_memory_desc_destroy(cat_md));
        OK(cum_memory_desc_destroy(x1_md));
        OK(cum_memory_desc_destroy(x0_md));
        OK(cum_tensor_destroy(red));
        OK(cum_tensor_destroy(cat));
        OK(cum_tensor_destroy(x1));
        OK(cum_tensor_destroy(x0));
    }

    return 0;
}

int main(void)
{
    int failed = 0;

    OK(cum_init(CUM_DEVICE_CPU));
    failed |= test_tensor();
    failed |= test_matrix();
    failed |= test_vector();
    failed |= test_blas();
    failed |= test_neural_primitives();
    OK(cum_shutdown());

    if(failed == 0)
        printf("C binding: all tests passed\n");
    return failed;
}
