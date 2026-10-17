#pragma once

#include "cum/Core.hpp"
#include "cum/memory.hpp"
#include "cum/functions/various.hpp"
#include <cmath>
#include <iostream>

struct TEST_DATA
{
    cum::cumeric_t* source = nullptr;
    cum::cumeric_t* result_cum = nullptr;
    cum::cumeric_t* result_std = nullptr;
    cum::cumeric_t  x_min = 0;
    cum::cumeric_t  x_max = 0;
    size_t N = 0;
};

struct TEST_EVAL
{
    cum::cumeric_t total_error = 0;
    cum::cumeric_t avarage_error = 0;
    cum::cumeric_t max_error = 0;
};

inline void setup_data(TEST_DATA& data, const cum::cumeric_t min = -10._c, const cum::cumeric_t max = 10._c, size_t N = 1024)
{
    data.N = N;
    data.x_min = min;
    data.x_max = max;

    data.source = cum::memory::allocate(data.N);
    data.result_cum = cum::memory::allocate(data.N);
    data.result_std = cum::memory::allocate(data.N);

    cum::functions::various::linespace(data.source, min, max, N);
}

inline void free_data(TEST_DATA& data)
{
    if (data.source) cum::memory::free(data.source);
    if (data.result_cum) cum::memory::free(data.result_cum);
    if (data.result_std) cum::memory::free(data.result_std);
    data.source = nullptr;
    data.result_cum = nullptr;
    data.result_std = nullptr;
}

inline void eval_data(TEST_EVAL& results, const TEST_DATA& data)
{
    for (std::size_t i = 0; i < data.N; ++i)
    {
        cum::cumeric_t current_error = std::abs(data.result_cum[i] - data.result_std[i]);
        if (current_error > results.max_error) results.max_error = current_error;
        results.total_error += current_error;
    }
    results.avarage_error = results.total_error / data.N;
}

inline void print_results(TEST_EVAL& eval)
{
    std::cout << "max error: " << eval.max_error << std::endl;
    std::cout << "avarage error: " << eval.avarage_error << std::endl;
}
