#include <catch2/catch_test_macros.hpp>

#include <cum/cum.hpp>
#include <cum/functions.hpp>
#include <cum/memory.hpp>
#include <cum/runtime.hpp>

#include <cmath>

#include "helpers.hpp"

TEST_CASE("tanh")
{
    cum::cum(cum::DEVICE::CPU);

    TEST_DATA data;
    setup_data(data);
    cum::runtime::sync();

    for (std::size_t i = 0; i < data.N; ++i)
        data.result_std[i] = std::tanh(data.source[i]);

    cum::functions::hyperbolic::tanh(data.result_cum, data.source, data.N);
    cum::runtime::sync();

    TEST_EVAL eval{};
    eval_data(eval, data);

    free_data(data);
    cum::decum();
    REQUIRE(eval.avarage_error < 1e-4_c);
}

TEST_CASE("sin")
{
    cum::cum(cum::DEVICE::CPU);

    TEST_DATA data;
    setup_data(data);
    cum::runtime::sync();

    for (std::size_t i = 0; i < data.N; ++i)
        data.result_std[i] = std::sin(data.source[i]);

    cum::functions::trigonometric::sin(data.result_cum, data.source, data.N);
    cum::runtime::sync();

    TEST_EVAL eval{};
    eval_data(eval, data);

    free_data(data);
    cum::decum();
    REQUIRE(eval.avarage_error < 1e-4_c);
}

TEST_CASE("log")
{
    cum::cum(cum::DEVICE::CPU);

    TEST_DATA data;
    setup_data(data, 0.01_c, 20._c);
    cum::runtime::sync();

    for (std::size_t i = 0; i < data.N; ++i)
        data.result_std[i] = std::log(data.source[i]);

    cum::functions::exponential::log(data.result_cum, data.source, data.N);
    cum::runtime::sync();

    TEST_EVAL eval{};
    eval_data(eval, data);

    free_data(data);
    cum::decum();
    REQUIRE(eval.avarage_error < 1e-4_c);
}
