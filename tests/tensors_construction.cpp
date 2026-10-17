/*
 * @author: jaro
 * @name:   tensors_construction
 * @file:   tests/tensors_construction.cpp
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cum/Tensor.hpp>
#include <cum/cum.hpp>
#include <cum/memory.hpp>
#include <cum/runtime.hpp>

TEST_CASE("Tensor slice returns correct submatrix")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({4, 5}, cum::default_type, cum::layout::OI);

    for (cum::dim_t r = 0; r < 4; ++r)
        for (cum::dim_t c = 0; c < 5; ++c)
            tensor.data<cum::cumeric_t>()[r * 5 + c] = static_cast<cum::cumeric_t>(r * 10 + c);

    auto slice = tensor.slice({1, 1}, {2, 3});

    REQUIRE(slice.rank() == 2);
    REQUIRE(slice.shape() == cum::Shape{2, 3});

    REQUIRE(slice.at({0, 0}) == 11.0f);
    REQUIRE(slice.at({0, 1}) == 12.0f);
    REQUIRE(slice.at({0, 2}) == 13.0f);

    REQUIRE(slice.at({1, 0}) == 21.0f);
    REQUIRE(slice.at({1, 1}) == 22.0f);
    REQUIRE(slice.at({1, 2}) == 23.0f);

    cum::decum();
}

TEST_CASE("Tensor row returns correct view")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({3, 4}, cum::default_type, cum::layout::OI);

    for (cum::dim_t i = 0; i < tensor.lenght(); ++i)
        tensor.data<cum::cumeric_t>()[i] = static_cast<cum::cumeric_t>(i);

    auto row = tensor.row(1);

    REQUIRE(row.rank() == 2);
    REQUIRE(row.shape() == cum::Shape{1, 4});

    REQUIRE(row.at({0, 0}) == 4.0f);
    REQUIRE(row.at({0, 1}) == 5.0f);
    REQUIRE(row.at({0, 2}) == 6.0f);
    REQUIRE(row.at({0, 3}) == 7.0f);

    cum::decum();
}

TEST_CASE("Tensor col returns correct view")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({3, 4}, cum::default_type, cum::layout::OI);
    cum::runtime::sync();

    cum::cumeric_t* buffer = tensor.data<cum::cumeric_t>();
    for (cum::dim_t i = 0; i < tensor.lenght(); i++)
    {
        buffer[i] = static_cast<cum::cumeric_t>(i);
    }
    cum::runtime::sync();

    auto col = tensor.col(2);

    REQUIRE(col.rank() == 2);
    REQUIRE(col.shape() == cum::Shape{3, 1});

    REQUIRE(col.at({0, 0}) == 2.0f);
    REQUIRE(col.at({1, 0}) == 6.0f);
    REQUIRE(col.at({2, 0}) == 10.0f);

    cum::decum();
}

TEST_CASE("Tensor slice shares memory with source")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({3, 4}, cum::default_type, cum::layout::OI);
    tensor.fill(0);

    auto slice = tensor.slice({1, 1}, {1, 2});

    slice.data<cum::cumeric_t>()[0] = 69.0f;

    REQUIRE(tensor.at({1, 1}) == 69.0f);

    cum::decum();
}

TEST_CASE("Tensor slice rejects invalid range")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({3, 4}, cum::default_type, cum::layout::OI);

    REQUIRE_THROWS(tensor.slice({3, 0}, {1, 4}));
    REQUIRE_THROWS(tensor.slice({0, 4}, {3, 1}));
    REQUIRE_THROWS(tensor.slice({2, 3}, {2, 2}));

    cum::decum();
}

TEST_CASE("Tensor row and col reject non-matrix tensors")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Tensor tensor({2, 3, 4}, cum::default_type, cum::layout::ABC);

    REQUIRE_THROWS(tensor.row(0));
    REQUIRE_THROWS(tensor.col(0));

    cum::decum();
}

TEST_CASE("Tensor static factories Zeros, Ones, Linspace and equality")
{
    cum::cum(cum::DEVICE::CPU);

    auto zeros = cum::Tensor::Zeros({2, 3}, cum::default_type, cum::layout::OI);
    auto ones = cum::Tensor::Ones({2, 3}, cum::default_type, cum::layout::OI);

    for (cum::dim_t i = 0; i < zeros.lenght(); ++i)
    {
        REQUIRE(zeros.data<cum::cumeric_t>()[i] == 0.0f);
        REQUIRE(ones.data<cum::cumeric_t>()[i] == 1.0f);
    }

    auto lin = cum::Tensor::Linspace(0.0f, 1.0f, 5);
    cum::runtime::sync();
    REQUIRE(lin.lenght() == 5);
    REQUIRE_THAT(lin.data<cum::cumeric_t>()[0], Catch::Matchers::WithinAbs(0.0f, 1e-5f));
    REQUIRE_THAT(lin.data<cum::cumeric_t>()[2], Catch::Matchers::WithinAbs(0.5f, 1e-5f));
    REQUIRE_THAT(lin.data<cum::cumeric_t>()[4], Catch::Matchers::WithinAbs(1.0f, 1e-5f));

    auto ones_copy = ones.clone();
    REQUIRE(ones == ones_copy);
    REQUIRE_FALSE(ones == zeros);

    cum::decum();
}
