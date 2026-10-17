#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cum/lara/vecops.hpp>
#include <cum/lara/matops.hpp>
#include <cum/functions/trigonometric.hpp>
#include <cum/functions/exponential.hpp>
#include <cum/functions/linear_units.hpp>
#include <cum/functions/logistic.hpp>
#include <cum/functions/transform.hpp>
#include <cum/Vector.hpp>
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

