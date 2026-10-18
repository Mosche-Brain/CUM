#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cum/cum.hpp>
#include <cum/generics/Vector.hpp>

#include <cmath>
#include <stdexcept>

TEST_CASE("generics::Vector construction and element access")
{
    cum::cum(cum::DEVICE::CPU);

    SECTION("Fixed-size vector construction and indexing")
    {
        cum::fvec3 v;
        REQUIRE(v.length() == 3);
        v[0] = 1.5f;
        v[1] = -2.5f;
        v[2] = 4.0f;

        const auto& cv = v;
        REQUIRE_THAT(cv[0], Catch::Matchers::WithinAbs(1.5f, 1e-6f));
        REQUIRE_THAT(cv[1], Catch::Matchers::WithinAbs(-2.5f, 1e-6f));
        REQUIRE_THAT(cv[2], Catch::Matchers::WithinAbs(4.0f, 1e-6f));
    }

    SECTION("Fixed-size vector throws when constructed with dynamic length")
    {
        REQUIRE_THROWS_AS(cum::fvec3(3), std::runtime_error);
    }

    SECTION("Dynamic vector construction, length, and arithmetic")
    {
        cum::Vector<double, cum::Dynamic> v(4);
        cum::Vector<double, cum::Dynamic> u(4);
        REQUIRE(v.length() == 4);
        for (cum::dim_t i = 0; i < 4; ++i)
        {
            v[i] = static_cast<double>(i + 1) * 2.0;
            u[i] = 1.0;
        }

        auto w = v + u;
        REQUIRE(w.length() == 4);
        REQUIRE_THAT(w[0], Catch::Matchers::WithinAbs(3.0, 1e-9));
        REQUIRE_THAT(w[1], Catch::Matchers::WithinAbs(5.0, 1e-9));
        REQUIRE_THAT(w[2], Catch::Matchers::WithinAbs(7.0, 1e-9));
        REQUIRE_THAT(w[3], Catch::Matchers::WithinAbs(9.0, 1e-9));
        REQUIRE_THAT(w.sum(), Catch::Matchers::WithinAbs(24.0, 1e-9));
    }

    cum::decum();
}

TEST_CASE("generics::Vector elementwise and scalar arithmetic operators")
{
    cum::cum(cum::DEVICE::CPU);

    cum::dvec3 a;
    cum::dvec3 b;
    a[0] = 10.0; a[1] = 20.0; a[2] = 30.0;
    b[0] = 2.0;  b[1] = 4.0;  b[2] = 5.0;

    SECTION("Binary operators +, -, *, /")
    {
        auto sum = a + b;
        REQUIRE_THAT(sum[0], Catch::Matchers::WithinAbs(12.0, 1e-9));
        REQUIRE_THAT(sum[1], Catch::Matchers::WithinAbs(24.0, 1e-9));
        REQUIRE_THAT(sum[2], Catch::Matchers::WithinAbs(35.0, 1e-9));

        auto diff = a - b;
        REQUIRE_THAT(diff[0], Catch::Matchers::WithinAbs(8.0, 1e-9));
        REQUIRE_THAT(diff[1], Catch::Matchers::WithinAbs(16.0, 1e-9));
        REQUIRE_THAT(diff[2], Catch::Matchers::WithinAbs(25.0, 1e-9));

        auto prod = a * b;
        REQUIRE_THAT(prod[0], Catch::Matchers::WithinAbs(20.0, 1e-9));
        REQUIRE_THAT(prod[1], Catch::Matchers::WithinAbs(80.0, 1e-9));
        REQUIRE_THAT(prod[2], Catch::Matchers::WithinAbs(150.0, 1e-9));

        auto quot = a / b;
        REQUIRE_THAT(quot[0], Catch::Matchers::WithinAbs(5.0, 1e-9));
        REQUIRE_THAT(quot[1], Catch::Matchers::WithinAbs(5.0, 1e-9));
        REQUIRE_THAT(quot[2], Catch::Matchers::WithinAbs(6.0, 1e-9));
    }

    SECTION("Scalar operators * and /")
    {
        auto scaled = a * 2.5;
        REQUIRE_THAT(scaled[0], Catch::Matchers::WithinAbs(25.0, 1e-9));
        REQUIRE_THAT(scaled[1], Catch::Matchers::WithinAbs(50.0, 1e-9));
        REQUIRE_THAT(scaled[2], Catch::Matchers::WithinAbs(75.0, 1e-9));

        auto divided = a / 2.0;
        REQUIRE_THAT(divided[0], Catch::Matchers::WithinAbs(5.0, 1e-9));
        REQUIRE_THAT(divided[1], Catch::Matchers::WithinAbs(10.0, 1e-9));
        REQUIRE_THAT(divided[2], Catch::Matchers::WithinAbs(15.0, 1e-9));
    }

    SECTION("Compound assignment operators +=, -=, *=, /=")
    {
        a += b;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(12.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(24.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(35.0, 1e-9));

        a -= b;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(10.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(20.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(30.0, 1e-9));

        a *= b;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(20.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(80.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(150.0, 1e-9));

        a /= b;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(10.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(20.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(30.0, 1e-9));

        a *= 0.5;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(5.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(10.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(15.0, 1e-9));

        a /= 5.0;
        REQUIRE_THAT(a[0], Catch::Matchers::WithinAbs(1.0, 1e-9));
        REQUIRE_THAT(a[1], Catch::Matchers::WithinAbs(2.0, 1e-9));
        REQUIRE_THAT(a[2], Catch::Matchers::WithinAbs(3.0, 1e-9));
    }

    SECTION("Integer vector ivec3 arithmetic")
    {
        cum::ivec3 u;
        cum::ivec3 v;
        u[0] = 6; u[1] = 8; u[2] = 10;
        v[0] = 2; v[1] = 4; v[2] = 5;

        auto w = u + v;
        REQUIRE(w[0] == 8);
        REQUIRE(w[1] == 12);
        REQUIRE(w[2] == 15);
    }

    cum::decum();
}

TEST_CASE("generics::Vector dot, norm, sum, cross, and normalize")
{
    cum::cum(cum::DEVICE::CPU);

    cum::fvec3 u;
    cum::fvec3 v;
    u[0] = 3.0f; u[1] = 4.0f; u[2] = 0.0f;
    v[0] = 1.0f; v[1] = 2.0f; v[2] = 3.0f;

    REQUIRE_THAT(u.norm(), Catch::Matchers::WithinAbs(5.0f, 1e-5f));
    REQUIRE_THAT(u.dot(v), Catch::Matchers::WithinAbs(11.0f, 1e-5f));
    REQUIRE_THAT(u.sum(), Catch::Matchers::WithinAbs(7.0f, 1e-5f));

    auto unit_u = u.normalize();
    REQUIRE_THAT(unit_u[0], Catch::Matchers::WithinAbs(0.6f, 1e-5f));
    REQUIRE_THAT(unit_u[1], Catch::Matchers::WithinAbs(0.8f, 1e-5f));
    REQUIRE_THAT(unit_u[2], Catch::Matchers::WithinAbs(0.0f, 1e-5f));

    auto c = u.cross(v);
    REQUIRE_THAT(c[0], Catch::Matchers::WithinAbs(12.0f, 1e-5f));
    REQUIRE_THAT(c[1], Catch::Matchers::WithinAbs(-9.0f, 1e-5f));
    REQUIRE_THAT(c[2], Catch::Matchers::WithinAbs(2.0f, 1e-5f));

    cum::decum();
}

TEST_CASE("generics::Vector::random, zeros, and ones factories")
{
    cum::cum(cum::DEVICE::CPU);

    auto rf = cum::fvec4::random(2.0f, 5.0f);
    REQUIRE(rf.length() == 4);
    for (cum::dim_t i = 0; i < 4; ++i)
    {
        REQUIRE(rf[i] >= 2.0f);
        REQUIRE(rf[i] <= 5.0f);
    }

    auto rd = cum::Vector<double, cum::Dynamic>::random(8, -10.0, -5.0);
    REQUIRE(rd.length() == 8);
    for (cum::dim_t i = 0; i < 8; ++i)
    {
        REQUIRE(rd[i] >= -10.0);
        REQUIRE(rd[i] <= -5.0);
    }

    auto ri = cum::ivec3::random(10, 20);
    for (cum::dim_t i = 0; i < 3; ++i)
    {
        REQUIRE(ri[i] >= 10);
        REQUIRE(ri[i] <= 20);
    }

    auto zf = cum::fvec3::zeros();
    REQUIRE(zf.length() == 3);
    for (cum::dim_t i = 0; i < 3; ++i)
    {
        REQUIRE_THAT(zf[i], Catch::Matchers::WithinAbs(0.0f, 1e-6f));
    }

    auto od = cum::dvec4::ones();
    REQUIRE(od.length() == 4);
    for (cum::dim_t i = 0; i < 4; ++i)
    {
        REQUIRE_THAT(od[i], Catch::Matchers::WithinAbs(1.0, 1e-9));
    }

    auto zd = cum::Vector<int, cum::Dynamic>::zeros(5);
    auto oi = cum::Vector<int, cum::Dynamic>::ones(5);
    REQUIRE(zd.length() == 5);
    REQUIRE(oi.length() == 5);
    for (cum::dim_t i = 0; i < 5; ++i)
    {
        REQUIRE(zd[i] == 0);
        REQUIRE(oi[i] == 1);
    }

    cum::decum();
}

