#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cum/lara/vecops.hpp>
#include <cum/lara/matops.hpp>
#include <cum/functions/trigonometric.hpp>
#include <cum/functions/exponential.hpp>
#include <cum/functions/linear_units.hpp>
#include <cum/functions/logistic.hpp>
#include <cum/functions/transform.hpp>
#include <cum/cum.hpp>
#include <cum/memory.hpp>
#include <cum/runtime.hpp>

#include <cmath>
#include <cstdint>

TEST_CASE("lara::vadd runtime datatype dispatch works for FP32, FP64, and S32")
{
    cum::cum(cum::DEVICE::CPU);

    constexpr cum::dim_t n = 4;

    SECTION("FP32 dispatch")
    {
        auto* a = static_cast<float*>(cum::memory::allocate(n, cum::datatype::FP32));
        auto* b = static_cast<float*>(cum::memory::allocate(n, cum::datatype::FP32));
        auto* r = static_cast<float*>(cum::memory::allocate(n, cum::datatype::FP32));

        for (cum::dim_t i = 0; i < n; ++i)
        {
            a[i] = static_cast<float>(i + 1);
            b[i] = static_cast<float>((i + 1) * 10);
        }

        auto ev = cum::lara::vadd(cum::datatype::FP32, r, a, b, n);
        ev.wait();

        REQUIRE_THAT(r[0], Catch::Matchers::WithinAbs(11.0f, 1e-5f));
        REQUIRE_THAT(r[1], Catch::Matchers::WithinAbs(22.0f, 1e-5f));
        REQUIRE_THAT(r[2], Catch::Matchers::WithinAbs(33.0f, 1e-5f));
        REQUIRE_THAT(r[3], Catch::Matchers::WithinAbs(44.0f, 1e-5f));

        cum::memory::free(a);
        cum::memory::free(b);
        cum::memory::free(r);
    }

    SECTION("FP64 dispatch")
    {
        auto* a = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));
        auto* b = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));
        auto* r = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));

        for (cum::dim_t i = 0; i < n; ++i)
        {
            a[i] = static_cast<double>(i) * 0.5;
            b[i] = static_cast<double>(i) * 1.5;
        }

        auto ev = cum::lara::vadd(cum::datatype::FP64, r, a, b, n);
        ev.wait();

        REQUIRE_THAT(r[0], Catch::Matchers::WithinAbs(0.0, 1e-9));
        REQUIRE_THAT(r[1], Catch::Matchers::WithinAbs(2.0, 1e-9));
        REQUIRE_THAT(r[2], Catch::Matchers::WithinAbs(4.0, 1e-9));
        REQUIRE_THAT(r[3], Catch::Matchers::WithinAbs(6.0, 1e-9));

        cum::memory::free(a);
        cum::memory::free(b);
        cum::memory::free(r);
    }

    SECTION("S32 fallback kernel dispatch")
    {
        auto* a = static_cast<std::int32_t*>(cum::memory::allocate(n, cum::datatype::S32));
        auto* b = static_cast<std::int32_t*>(cum::memory::allocate(n, cum::datatype::S32));
        auto* r = static_cast<std::int32_t*>(cum::memory::allocate(n, cum::datatype::S32));

        for (cum::dim_t i = 0; i < n; ++i)
        {
            a[i] = static_cast<std::int32_t>(i * 3);
            b[i] = static_cast<std::int32_t>(i * 7);
        }

        auto ev = cum::lara::vadd(cum::datatype::S32, r, a, b, n);
        ev.wait();

        REQUIRE(r[0] == 0);
        REQUIRE(r[1] == 10);
        REQUIRE(r[2] == 20);
        REQUIRE(r[3] == 30);

        cum::memory::free(a);
        cum::memory::free(b);
        cum::memory::free(r);
    }

    cum::decum();
}

TEST_CASE("lara::matops runtime datatype dispatch works for FP32, FP64, and S32")
{
    cum::cum(cum::DEVICE::CPU);

    SECTION("mmul and mtrans FP64")
    {
        auto* A = static_cast<double*>(cum::memory::allocate(4, cum::datatype::FP64));
        auto* B = static_cast<double*>(cum::memory::allocate(4, cum::datatype::FP64));
        auto* C = static_cast<double*>(cum::memory::allocate(4, cum::datatype::FP64));
        auto* At = static_cast<double*>(cum::memory::allocate(4, cum::datatype::FP64));

        A[0] = 1.0; A[1] = 2.0; A[2] = 3.0; A[3] = 4.0;
        B[0] = 5.0; B[1] = 6.0; B[2] = 7.0; B[3] = 8.0;

        cum::lara::mmul(cum::datatype::FP64, C, A, B, 2, 2, 2).wait();
        REQUIRE_THAT(C[0], Catch::Matchers::WithinAbs(19.0, 1e-9));
        REQUIRE_THAT(C[1], Catch::Matchers::WithinAbs(22.0, 1e-9));
        REQUIRE_THAT(C[2], Catch::Matchers::WithinAbs(43.0, 1e-9));
        REQUIRE_THAT(C[3], Catch::Matchers::WithinAbs(50.0, 1e-9));

        cum::lara::mtrans(cum::datatype::FP64, At, A, 2, 2).wait();
        REQUIRE_THAT(At[0], Catch::Matchers::WithinAbs(1.0, 1e-9));
        REQUIRE_THAT(At[1], Catch::Matchers::WithinAbs(3.0, 1e-9));
        REQUIRE_THAT(At[2], Catch::Matchers::WithinAbs(2.0, 1e-9));
        REQUIRE_THAT(At[3], Catch::Matchers::WithinAbs(4.0, 1e-9));

        cum::memory::free(A);
        cum::memory::free(B);
        cum::memory::free(C);
        cum::memory::free(At);
    }

    SECTION("mmul S32 fallback kernel")
    {
        auto* A = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));
        auto* B = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));
        auto* C = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));

        A[0] = 1; A[1] = 2; A[2] = 3; A[3] = 4;
        B[0] = 2; B[1] = 0; B[2] = 1; B[3] = 2;

        cum::lara::mmul(cum::datatype::S32, C, A, B, 2, 2, 2).wait();
        REQUIRE(C[0] == 4);
        REQUIRE(C[1] == 4);
        REQUIRE(C[2] == 10);
        REQUIRE(C[3] == 8);

        cum::memory::free(A);
        cum::memory::free(B);
        cum::memory::free(C);
    }

    cum::decum();
}

TEST_CASE("functions elementwise runtime datatype dispatch works for FP64 and FP32")
{
    cum::cum(cum::DEVICE::CPU);

    constexpr std::size_t n = 4;
    auto* x = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));
    auto* y = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));

    x[0] = -1.0;
    x[1] = 0.0;
    x[2] = 0.5;
    x[3] = 1.0;

    cum::functions::trigonometric::sin(cum::datatype::FP64, y, x, n).wait();
    for (std::size_t i = 0; i < n; ++i)
    {
        REQUIRE_THAT(y[i], Catch::Matchers::WithinAbs(std::sin(x[i]), 1e-9));
    }

    cum::functions::exponential::exp(cum::datatype::FP64, y, x, n).wait();
    for (std::size_t i = 0; i < n; ++i)
    {
        REQUIRE_THAT(y[i], Catch::Matchers::WithinAbs(std::exp(x[i]), 1e-9));
    }

    cum::functions::linear_units::relu(cum::datatype::FP64, y, x, static_cast<cum::dim_t>(n)).wait();
    REQUIRE_THAT(y[0], Catch::Matchers::WithinAbs(0.0, 1e-9));
    REQUIRE_THAT(y[1], Catch::Matchers::WithinAbs(0.0, 1e-9));
    REQUIRE_THAT(y[2], Catch::Matchers::WithinAbs(0.5, 1e-9));
    REQUIRE_THAT(y[3], Catch::Matchers::WithinAbs(1.0, 1e-9));

    cum::functions::logistic::sigmoid(cum::datatype::FP64, y, x, n).wait();
    for (std::size_t i = 0; i < n; ++i)
    {
        double expected = 1.0 / (1.0 + std::exp(-x[i]));
        REQUIRE_THAT(y[i], Catch::Matchers::WithinAbs(expected, 1e-9));
    }

    cum::memory::free(x);
    cum::memory::free(y);
    cum::decum();
}

TEST_CASE("type_tag returns expected constexpr cum::datatype")
{
    STATIC_REQUIRE(cum::type_tag<double>() == cum::datatype::FP64);
    STATIC_REQUIRE(cum::type_tag<const float&>() == cum::datatype::FP32);
    STATIC_REQUIRE(cum::type_tag<cum::float16>() == cum::datatype::FP16);
    STATIC_REQUIRE(cum::type_tag<cum::bfloat16>() == cum::datatype::BF16);
    STATIC_REQUIRE(cum::type_tag<cum::float8>() == cum::datatype::FP8);
    STATIC_REQUIRE(cum::type_tag<std::int64_t>() == cum::datatype::S64);
    STATIC_REQUIRE(cum::type_tag<cum::int64>() == cum::datatype::S64);
    STATIC_REQUIRE(cum::type_tag<std::int32_t>() == cum::datatype::S32);
    STATIC_REQUIRE(cum::type_tag<std::int16_t>() == cum::datatype::S16);
    STATIC_REQUIRE(cum::type_tag<std::int8_t>() == cum::datatype::S8);
    STATIC_REQUIRE(cum::type_tag<std::uint64_t>() == cum::datatype::U64);
    STATIC_REQUIRE(cum::type_tag<std::uint32_t>() == cum::datatype::U32);
    STATIC_REQUIRE(cum::type_tag<std::uint16_t>() == cum::datatype::U16);
    STATIC_REQUIRE(cum::type_tag<std::uint8_t>() == cum::datatype::U8);
    STATIC_REQUIRE(cum::type_tag<bool>() == cum::datatype::UNDEF);
}

#include <cum/lara/BLAS.hpp>

TEST_CASE("cum::blas Level 1, 2, 3 datatype dispatch works for cumeric_t and const void* scalars")
{
    cum::cum(cum::DEVICE::CPU);

    SECTION("Level 1: axpy, dot, asum, nrm2, iamax, amax, scal (FP64 & S32)")
    {
        constexpr cum::dim_t n = 3;
        auto* x = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));
        auto* y = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));
        auto* res = static_cast<double*>(cum::memory::allocate(1, cum::datatype::FP64));
        auto* idx_res = static_cast<cum::dim_t*>(cum::memory::allocate(1, cum::datatype::S64));

        x[0] = 1.0; x[1] = -2.0; x[2] = 3.0;
        y[0] = 10.0; y[1] = 20.0; y[2] = 30.0;

        // cumeric_t scalar overload
        cum::blas::axpy(cum::datatype::FP64, n, 2.0_c, x, 1, y, 1).wait();
        REQUIRE_THAT(y[0], Catch::Matchers::WithinAbs(12.0, 1e-9));
        REQUIRE_THAT(y[1], Catch::Matchers::WithinAbs(16.0, 1e-9));
        REQUIRE_THAT(y[2], Catch::Matchers::WithinAbs(36.0, 1e-9));

        // const void* scalar overload
        const double alpha = 0.5;
        cum::blas::scal(cum::datatype::FP64, n, &alpha, y, 1).wait();
        REQUIRE_THAT(y[0], Catch::Matchers::WithinAbs(6.0, 1e-9));
        REQUIRE_THAT(y[1], Catch::Matchers::WithinAbs(8.0, 1e-9));
        REQUIRE_THAT(y[2], Catch::Matchers::WithinAbs(18.0, 1e-9));

        cum::blas::dot(cum::datatype::FP64, n, x, 1, y, 1, res).wait();
        REQUIRE_THAT(res[0], Catch::Matchers::WithinAbs(44.0, 1e-9));

        cum::blas::asum(cum::datatype::FP64, n, x, 1, res).wait();
        REQUIRE_THAT(res[0], Catch::Matchers::WithinAbs(6.0, 1e-9));

        cum::blas::iamax(cum::datatype::FP64, n, x, 1, idx_res).wait();
        REQUIRE(idx_res[0] == 2);

        cum::blas::amax(cum::datatype::FP64, n, x, 1, res).wait();
        REQUIRE_THAT(res[0], Catch::Matchers::WithinAbs(3.0, 1e-9));

        cum::memory::free(x);
        cum::memory::free(y);
        cum::memory::free(res);
        cum::memory::free(idx_res);
    }

    SECTION("Level 2 & 3: gemv, trmv, gemm, symm, trmm (S32 fallback & FP64)")
    {
        auto* A = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));
        auto* B = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));
        auto* C = static_cast<std::int32_t*>(cum::memory::allocate(4, cum::datatype::S32));
        auto* x = static_cast<std::int32_t*>(cum::memory::allocate(2, cum::datatype::S32));
        auto* y = static_cast<std::int32_t*>(cum::memory::allocate(2, cum::datatype::S32));

        // A = [[1, 2], [3, 4]], x = [2, 3], y = [1, 1]
        A[0] = 1; A[1] = 2; A[2] = 3; A[3] = 4;
        x[0] = 2; x[1] = 3;
        y[0] = 1; y[1] = 1;

        const std::int32_t alpha_i = 2;
        const std::int32_t beta_i = 1;
        cum::blas::gemv(cum::datatype::S32, 'N', 2, 2, &alpha_i, A, 2, x, 1, &beta_i, y, 1).wait();
        // y = 2 * [1*2+2*3, 3*2+4*3] + [1, 1] = [17, 37]
        REQUIRE(y[0] == 17);
        REQUIRE(y[1] == 37);

        // trmv upper non-unit: [[1, 2], [0, 4]] * [2, 3] = [8, 12]
        cum::blas::trmv(cum::datatype::S32, 'U', 'N', 'N', 2, A, 2, x, 1).wait();
        REQUIRE(x[0] == 8);
        REQUIRE(x[1] == 12);

        // gemm with cumeric_t scalars on S32
        B[0] = 1; B[1] = 0; B[2] = 0; B[3] = 1;
        C[0] = 0; C[1] = 0; C[2] = 0; C[3] = 0;
        cum::blas::gemm(cum::datatype::S32, 'N', 'N', 2, 2, 2, 3.0_c, A, 2, B, 2, 0.0_c, C, 2).wait();
        REQUIRE(C[0] == 3);
        REQUIRE(C[1] == 6);
        REQUIRE(C[2] == 9);
        REQUIRE(C[3] == 12);

        // trmm out-of-place upper non-unit: C = 1 * [[1, 2], [0, 4]] * I = [[1, 2], [0, 4]]
        cum::blas::trmm(cum::datatype::S32, 'L', 'U', 'N', 'N', C, 2, 2, &beta_i, A, 2, B, 2).wait();
        REQUIRE(C[0] == 1);
        REQUIRE(C[1] == 2);
        REQUIRE(C[2] == 0);
        REQUIRE(C[3] == 4);

        cum::memory::free(A);
        cum::memory::free(B);
        cum::memory::free(C);
        cum::memory::free(x);
        cum::memory::free(y);
    }

    cum::decum();
}

TEST_CASE("lara::vadd_batch contiguous and strided/broadcast dispatch")
{
    cum::cum(cum::DEVICE::CPU);

    constexpr cum::dim_t batch = 3;
    constexpr cum::dim_t n = 2;

    auto* v = static_cast<double*>(cum::memory::allocate(batch * n, cum::datatype::FP64));
    auto* u = static_cast<double*>(cum::memory::allocate(batch * n, cum::datatype::FP64));
    auto* r = static_cast<double*>(cum::memory::allocate(batch * n, cum::datatype::FP64));
    auto* bias = static_cast<double*>(cum::memory::allocate(n, cum::datatype::FP64));

    for (cum::dim_t i = 0; i < batch * n; ++i)
    {
        v[i] = static_cast<double>(i + 1);
        u[i] = static_cast<double>((i + 1) * 10);
    }
    bias[0] = 100.0;
    bias[1] = 200.0;

    // Contiguous batch addition
    cum::lara::vadd_batch(cum::datatype::FP64, r, v, u, n, batch).wait();
    for (cum::dim_t i = 0; i < batch * n; ++i)
    {
        REQUIRE_THAT(r[i], Catch::Matchers::WithinAbs(static_cast<double>((i + 1) * 11), 1e-9));
    }

    // Strided batch with broadcast (stride_u == 0)
    cum::lara::vadd_batch(cum::datatype::FP64, r, n, v, n, bias, 0, n, batch).wait();
    REQUIRE_THAT(r[0], Catch::Matchers::WithinAbs(101.0, 1e-9));
    REQUIRE_THAT(r[1], Catch::Matchers::WithinAbs(202.0, 1e-9));
    REQUIRE_THAT(r[2], Catch::Matchers::WithinAbs(103.0, 1e-9));
    REQUIRE_THAT(r[3], Catch::Matchers::WithinAbs(204.0, 1e-9));
    REQUIRE_THAT(r[4], Catch::Matchers::WithinAbs(105.0, 1e-9));
    REQUIRE_THAT(r[5], Catch::Matchers::WithinAbs(206.0, 1e-9));

    cum::memory::free(v);
    cum::memory::free(u);
    cum::memory::free(r);
    cum::memory::free(bias);
    cum::decum();
}


