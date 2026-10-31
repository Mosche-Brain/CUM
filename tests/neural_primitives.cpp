/**
 * @file neural_primitives.cpp
 * @brief Unit tests for unified cum::neural_primitives (MemoryDescriptor, Memory, PrimitiveDescriptor, Primitive).
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cmath>
#include <cstdint>
#include <vector>

#include <cum/Tensor.hpp>
#include <cum/cum.hpp>
#include <cum/neural_primitives.hpp>

namespace np = cum::neural_primitives;

namespace
{
    void require_close(float actual, float expected, float tol = 1e-4f)
    {
        REQUIRE_THAT(actual, Catch::Matchers::WithinAbs(expected, tol));
    }
}

TEST_CASE("MemoryDescriptor and Memory support const copy, strides, equality, and shared USM")
{
    cum::cum(cum::DEVICE::CPU);

    const np::MemoryDescriptor md({2, 3}, cum::datatype::FP32, cum::layout::AB);
    REQUIRE(md.valid());
    REQUIRE(md.ndims() == 2);
    REQUIRE(md.shape() == cum::Shape{2, 3});
    REQUIRE(md.strides() == cum::Shape{3, 1});
    REQUIRE(md.stride() == 3);
    REQUIRE(md.size() == 2 * 3 * static_cast<cum::dim_t>(sizeof(float)));
    REQUIRE(md.type() == cum::datatype::FP32);
    REQUIRE(md.format() == cum::layout::AB);

    // Const copy & comparison
    np::MemoryDescriptor copy_md(md);
    REQUIRE(copy_md == md);

    const np::MemoryDescriptor reshaped = md.reshape({3, 2});
    REQUIRE(reshaped.shape() == cum::Shape{3, 2});
    REQUIRE(reshaped != md);

    // Standalone USM-backed Memory
    np::Memory mem(md);
    REQUIRE(mem.valid());
    REQUIRE(mem.descriptor() == md);
    for (int i = 0; i < 6; ++i)
        mem.data<float>()[i] = static_cast<float>(i + 1);
    require_close(mem.data<float>()[5], 6.0f);

    cum::decum();
}

TEST_CASE("Primitive Binary supports arithmetic, broadcasting, ArgBinding, and event chaining")
{
    cum::cum(cum::DEVICE::CPU);

    np::MemoryDescriptor md_a({2, 3}, cum::datatype::FP32, cum::layout::AB);
    np::MemoryDescriptor md_b({1, 3}, cum::datatype::FP32, cum::layout::AB);
    np::MemoryDescriptor md_c({2, 3}, cum::datatype::FP32, cum::layout::AB);

    np::Memory a(md_a);
    np::Memory b(md_b);
    np::Memory c(md_c);
    np::Memory d(md_c);

    const float a_vals[6] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f};
    const float b_vals[3] = {10.f, 20.f, 30.f};
    for (int i = 0; i < 6; ++i) a.data<float>()[i] = a_vals[i];
    for (int i = 0; i < 3; ++i) b.data<float>()[i] = b_vals[i];

    const auto add_pd = np::PrimitiveDescriptor::Binary(np::Algo::binary_add, md_c, md_a, md_b);
    REQUIRE(add_pd.valid());
    REQUIRE(add_pd.kind() == np::PrimitiveDescriptor::Kind::binary);
    REQUIRE(!add_pd.impl_info().empty());

    // Test copy semantics of PrimitiveDescriptor and Primitive
    const np::PrimitiveDescriptor add_pd_copy = add_pd;
    np::Primitive add_prim(add_pd_copy);
    const np::Primitive add_prim_copy = add_prim;

    auto ev1 = add_prim_copy.execute(c, a, b);

    // Chain second binary primitive via SYCL event dependency + named ArgBinding list
    auto mul_pd = np::PrimitiveDescriptor::Binary(np::Algo::binary_mul, md_c, md_c, md_b);
    np::Primitive mul_prim(mul_pd);
    auto ev2 = mul_prim.execute(
        {
            {np::Primitive::Argument::src0, c},
            {np::Primitive::Argument::src1, b},
            {np::Primitive::Argument::dst, d},
        },
        cum::__events__{std::ref(ev1)}
    );
    ev2.wait();

    const float expected[6] = {
        (1.f + 10.f) * 10.f, (2.f + 20.f) * 20.f, (3.f + 30.f) * 30.f,
        (4.f + 10.f) * 10.f, (5.f + 20.f) * 20.f, (6.f + 30.f) * 30.f
    };
    for (int i = 0; i < 6; ++i)
        require_close(d.data<float>()[i], expected[i]);

    cum::decum();
}

TEST_CASE("Primitive Elementwise supports forward and backward passes with parameters")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor x(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    cum::Tensor y(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    cum::Tensor dy(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    cum::Tensor dx(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);

    x.data<float>()[0] = -2.0f;
    x.data<float>()[1] = -0.5f;
    x.data<float>()[2] = 0.5f;
    x.data<float>()[3] = 3.0f;

    dy.data<float>()[0] = 1.0f;
    dy.data<float>()[1] = 2.0f;
    dy.data<float>()[2] = 3.0f;
    dy.data<float>()[3] = 4.0f;

    const float slope = 0.1f;
    REQUIRE(np::to_algo(cum::functions::function_id::leaky_relu) == np::Algo::eltwise_leaky_relu);

    auto fwd_pd = np::PrimitiveDescriptor::Elementwise(
        np::Algo::eltwise_leaky_relu, *y.descriptor(), *x.descriptor(), slope
    );
    auto bwd_pd = np::PrimitiveDescriptor::ElementwiseBackward(
        np::Algo::eltwise_leaky_relu, *dx.descriptor(), *dy.descriptor(), *x.descriptor(), fwd_pd, slope
    );

    np::Primitive fwd(fwd_pd);
    np::Primitive bwd(bwd_pd);

    fwd.execute(y, x).wait();
    bwd.execute(dx, dy, x).wait();

    require_close(y.data<float>()[0], -0.2f);
    require_close(y.data<float>()[1], -0.05f);
    require_close(y.data<float>()[2], 0.5f);
    require_close(y.data<float>()[3], 3.0f);

    require_close(dx.data<float>()[0], 0.1f);
    require_close(dx.data<float>()[1], 0.2f);
    require_close(dx.data<float>()[2], 3.0f);
    require_close(dx.data<float>()[3], 4.0f);

    // Clip with alpha (min) and beta (max)
    cum::Tensor clipped(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    np::Primitive clip_prim(np::PrimitiveDescriptor::Elementwise(
        np::Algo::eltwise_clip, *clipped.descriptor(), *x.descriptor(), -1.0f, 1.5f
    ));
    clip_prim.execute(clipped, x).wait();
    require_close(clipped.data<float>()[0], -1.0f);
    require_close(clipped.data<float>()[1], -0.5f);
    require_close(clipped.data<float>()[2], 0.5f);
    require_close(clipped.data<float>()[3], 1.5f);

    // Tanh backward using forward dst (`eltwise_tanh_use_dst_for_bwd`)
    cum::Tensor tanh_y(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    cum::Tensor tanh_dx(cum::Shape{4}, cum::datatype::FP32, cum::layout::A);
    auto tanh_fwd_pd = np::PrimitiveDescriptor::Elementwise(
        np::Algo::eltwise_tanh_use_dst_for_bwd, *tanh_y.descriptor(), *x.descriptor()
    );
    auto tanh_bwd_pd = np::PrimitiveDescriptor::ElementwiseBackward(
        np::Algo::eltwise_tanh_use_dst_for_bwd,
        *tanh_dx.descriptor(),
        *dy.descriptor(),
        *tanh_y.descriptor(),
        tanh_fwd_pd
    );
    np::Primitive(tanh_fwd_pd).execute(tanh_y, x).wait();
    np::Primitive(tanh_bwd_pd).execute(tanh_dx, dy, tanh_y).wait();

    for (int i = 0; i < 4; ++i)
    {
        const float t = std::tanh(x.data<float>()[i]);
        require_close(tanh_y.data<float>()[i], t);
        require_close(tanh_dx.data<float>()[i], dy.data<float>()[i] * (1.0f - t * t));
    }

    cum::decum();
}

TEST_CASE("Primitive Matmul supports 2D and biased execution with layout::ANY resolution")
{
    cum::cum(cum::DEVICE::CPU);

    // A: (2, 3), B: (3, 2), bias: (1, 2) -> C: (2, 2)
    cum::Tensor A({2, 3}, cum::datatype::FP32, cum::layout::AB);
    cum::Tensor B({3, 2}, cum::datatype::FP32, cum::layout::AB);
    cum::Tensor bias({1, 2}, cum::datatype::FP32, cum::layout::AB);

    const float a_vals[6] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f};
    const float b_vals[6] = {1.f, 0.f, 0.f, 1.f, 2.f, -1.f};
    for (int i = 0; i < 6; ++i) A.data<float>()[i] = a_vals[i];
    for (int i = 0; i < 6; ++i) B.data<float>()[i] = b_vals[i];
    bias.data<float>()[0] = 0.5f;
    bias.data<float>()[1] = -2.0f;

    auto any_dst = np::MemoryDescriptor::Any({2, 2}, cum::datatype::FP32);
    auto mm_pd = np::PrimitiveDescriptor::Matmul(any_dst, *A.descriptor(), *B.descriptor(), *bias.descriptor());
    REQUIRE(mm_pd.valid());
    REQUIRE(mm_pd.bias_desc().valid());

    auto resolved_dst = mm_pd.dst_desc();
    REQUIRE(resolved_dst.valid());
    REQUIRE(resolved_dst.shape() == cum::Shape{2, 2});

    cum::Tensor C(resolved_dst);
    np::Primitive mm(mm_pd);
    mm.execute(C, A, B, bias).wait();

    // Row 0: [1*1 + 2*0 + 3*2 + 0.5, 1*0 + 2*1 + 3*(-1) - 2.0] = [7.5, -3.0]
    // Row 1: [4*1 + 5*0 + 6*2 + 0.5, 4*0 + 5*1 + 6*(-1) - 2.0] = [16.5, -3.0]
    require_close(C.at<float>({0, 0}), 7.5f);
    require_close(C.at<float>({0, 1}), -3.0f);
    require_close(C.at<float>({1, 0}), 16.5f);
    require_close(C.at<float>({1, 1}), -3.0f);

    cum::decum();
}

TEST_CASE("Primitive Softmax supports forward and backward along negative axis")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor x({2, 3}, cum::datatype::FP32, cum::layout::AB);
    cum::Tensor y({2, 3}, cum::datatype::FP32, cum::layout::AB);
    cum::Tensor dy({2, 3}, cum::datatype::FP32, cum::layout::AB);
    cum::Tensor dx({2, 3}, cum::datatype::FP32, cum::layout::AB);

    const float x_vals[6] = {1.f, 2.f, 3.f, -1.f, 0.f, 1.f};
    const float dy_vals[6] = {0.2f, -0.5f, 0.3f, 1.0f, 0.0f, -0.4f};
    for (int i = 0; i < 6; ++i)
    {
        x.data<float>()[i] = x_vals[i];
        dy.data<float>()[i] = dy_vals[i];
    }

    auto fwd_pd = np::PrimitiveDescriptor::Softmax(np::Algo::softmax_accurate, *y.descriptor(), *x.descriptor(), -1);
    auto bwd_pd = np::PrimitiveDescriptor::SoftmaxBackward(
        np::Algo::softmax_accurate, *dx.descriptor(), *dy.descriptor(), *y.descriptor(), -1, fwd_pd
    );

    np::Primitive(fwd_pd).execute(y, x).wait();
    np::Primitive(bwd_pd).execute(dx, dy, y).wait();

    for (int r = 0; r < 2; ++r)
    {
        float row_sum = 0.f;
        for (int c = 0; c < 3; ++c)
            row_sum += y.data<float>()[r * 3 + c];
        require_close(row_sum, 1.0f);

        float dot = 0.f;
        for (int c = 0; c < 3; ++c)
            dot += dy.data<float>()[r * 3 + c] * y.data<float>()[r * 3 + c];

        for (int c = 0; c < 3; ++c)
        {
            const float expected_dx = y.data<float>()[r * 3 + c] * (dy.data<float>()[r * 3 + c] - dot);
            require_close(dx.data<float>()[r * 3 + c], expected_dx);
        }
    }

    cum::decum();
}

TEST_CASE("Primitive Reduction, Reorder, Sum, and Concat compute expected tensor results")
{
    cum::cum(cum::DEVICE::CPU);

    // 1. Reduction (axis 1 sum & global L2 norm)
    cum::Tensor src({2, 3}, cum::datatype::FP32, cum::layout::AB);
    const float vals[6] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f};
    for (int i = 0; i < 6; ++i) src.data<float>()[i] = vals[i];

    cum::Tensor row_sum({2, 1}, cum::datatype::FP32, cum::layout::AB);
    np::Primitive red_sum(np::PrimitiveDescriptor::Reduction(
        np::Algo::reduction_sum, *row_sum.descriptor(), *src.descriptor()
    ));
    red_sum.execute(row_sum, src).wait();
    require_close(row_sum.data<float>()[0], 6.0f);
    require_close(row_sum.data<float>()[1], 15.0f);

    cum::Tensor l2_out({1, 1}, cum::datatype::FP32, cum::layout::AB);
    np::Primitive red_l2(np::PrimitiveDescriptor::Reduction(
        np::Algo::reduction_norm_lp_power_p_sum, *l2_out.descriptor(), *src.descriptor(), 2.0f, 0.0f
    ));
    red_l2.execute(l2_out, src).wait();
    require_close(l2_out.data<float>()[0], 91.0f); // 1+4+9+16+25+36 = 91

    // 2. Reorder (AB FP32 -> BA S32: layout transpose + datatype conversion)
    np::MemoryDescriptor dst_ba_s32({2, 3}, cum::datatype::S32, cum::layout::BA);
    np::Memory reordered(dst_ba_s32);
    np::Primitive reorder_prim(np::PrimitiveDescriptor::Reorder(dst_ba_s32, *src.descriptor()));
    reorder_prim.execute(reordered, *src.memory()).wait();
    // In BA (col-major for {2, 3}, strides = {1, 2}): element (r, c) is at r + c * 2
    REQUIRE(reordered.data<std::int32_t>()[0 + 0 * 2] == 1);
    REQUIRE(reordered.data<std::int32_t>()[1 + 0 * 2] == 4);
    REQUIRE(reordered.data<std::int32_t>()[0 + 2 * 2] == 3);
    REQUIRE(reordered.data<std::int32_t>()[1 + 2 * 2] == 6);

    // 3. Scaled Sum: 2.0 * src + (-0.5) * src = 1.5 * src
    cum::Tensor sum_out({2, 3}, cum::datatype::FP32, cum::layout::AB);
    auto sum_pd = np::PrimitiveDescriptor::Sum(
        *sum_out.descriptor(),
        {*src.descriptor(), *src.descriptor()},
        {2.0f, -0.5f}
    );
    np::Primitive(sum_pd).execute(sum_out, src, src).wait();
    for (int i = 0; i < 6; ++i)
        require_close(sum_out.data<float>()[i], 1.5f * vals[i]);

    // 4. Concat along axis = -1: (2, 3) + (2, 1) -> (2, 4)
    auto concat_pd = np::PrimitiveDescriptor::Concat({*src.descriptor(), *row_sum.descriptor()}, -1);
    auto concat_dst_md = concat_pd.dst_desc();
    REQUIRE(concat_dst_md.shape() == cum::Shape{2, 4});
    cum::Tensor cat_out(concat_dst_md);
    np::Primitive(concat_pd).execute(cat_out, src, row_sum).wait();
    require_close(cat_out.at<float>({0, 0}), 1.0f);
    require_close(cat_out.at<float>({0, 2}), 3.0f);
    require_close(cat_out.at<float>({0, 3}), 6.0f);
    require_close(cat_out.at<float>({1, 0}), 4.0f);
    require_close(cat_out.at<float>({1, 3}), 15.0f);

    cum::decum();
}

TEST_CASE("Primitive Matmul and Elementwise execute asynchronously on active AUTO/GPU device")
{
    cum::cum(cum::DEVICE::AUTO);

    np::MemoryDescriptor md_a({2, 3}, cum::datatype::FP32, cum::layout::AB);
    np::MemoryDescriptor md_b({3, 2}, cum::datatype::FP32, cum::layout::AB);
    np::MemoryDescriptor md_c({2, 2}, cum::datatype::FP32, cum::layout::AB);

    np::Memory a(md_a);
    np::Memory b(md_b);
    np::Memory c(md_c);
    np::Memory out(md_c);

    const float a_vals[6] = {1.f, -2.f, 3.f, -4.f, 5.f, -6.f};
    const float b_vals[6] = {2.f, 1.f, 0.f, -1.f, -1.f, 2.f};
    for (int i = 0; i < 6; ++i) a.data<float>()[i] = a_vals[i];
    for (int i = 0; i < 6; ++i) b.data<float>()[i] = b_vals[i];

    np::Primitive mm(np::PrimitiveDescriptor::Matmul(md_c, md_a, md_b));
    np::Primitive relu(np::PrimitiveDescriptor::Elementwise(np::Algo::eltwise_relu, md_c, md_c));

    auto ev_mm = mm.execute(c, a, b);
    auto ev_relu = relu.execute(out, c, cum::__events__{std::ref(ev_mm)});
    ev_relu.wait();

    // c = [[-1, 9], [-2, -11]] -> relu(c) = [[0, 9], [0, 0]]
    require_close(out.data<float>()[0], 0.0f);
    require_close(out.data<float>()[1], 9.0f);
    require_close(out.data<float>()[2], 0.0f);
    require_close(out.data<float>()[3], 0.0f);

    cum::decum();
}
