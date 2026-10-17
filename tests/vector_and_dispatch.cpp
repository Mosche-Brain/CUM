#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cum/lara/vecops.hpp>
#include <cum/Vector.hpp>
#include <cum/cum.hpp>
#include <cum/memory.hpp>
#include <cum/runtime.hpp>

#include <cstdint>

TEST_CASE("LinearAlgebra::vadd runtime datatype dispatch works for FP32, FP64, and S32")
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
