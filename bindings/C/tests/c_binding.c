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

int main(void)
{
    int failed = 0;

    OK(cum_init(CUM_DEVICE_CPU));
    failed |= test_tensor();
    failed |= test_matrix();
    failed |= test_vector();
    failed |= test_blas();
    OK(cum_shutdown());

    if(failed == 0)
        printf("C binding: all tests passed\n");
    return failed;
}
