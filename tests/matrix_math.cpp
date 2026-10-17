/* Created by jaro on 7/16/26. */

#include <catch2/catch_test_macros.hpp>

#include <cum/Matrix.hpp>
#include <cum/cum.hpp>

TEST_CASE("CPU mmul")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Matrix A(2, 2,
        {1, 2,
         3, 4});

    cum::Matrix B(2, 2,
        {5, 6,
         7, 8});

    cum::Matrix C = A * B;
    cum::Matrix VALID_RESULT(2, 2,
        {19, 22,
         43, 50});

    REQUIRE(C == VALID_RESULT);

    cum::decum();
}

TEST_CASE("GPU mmul")
{
    cum::cum(cum::DEVICE::GPU);

    cum::Matrix A(2, 2,
        {1, 2,
         3, 4});

    cum::Matrix B(2, 2,
        {5, 6,
         7, 8});

    cum::Matrix C = A * B;
    cum::Matrix VALID_RESULT(2, 2,
        {19, 22,
         43, 50});

    REQUIRE(C == VALID_RESULT);

    cum::decum();
}

TEST_CASE("Matrix basic arithmetic and transpose")
{
    cum::cum(cum::DEVICE::CPU);

    cum::Matrix A(2, 3,
        {1, 2, 3,
         4, 5, 6});

    cum::Matrix AT = A.transpose();
    cum::Matrix EXPECTED_AT(3, 2,
        {1, 4,
         2, 5,
         3, 6});

    REQUIRE(AT == EXPECTED_AT);

    cum::Matrix B = cum::Matrix::Ones(2, 3);
    cum::Matrix SUM = A + B;
    cum::Matrix EXPECTED_SUM(2, 3,
        {2, 3, 4,
         5, 6, 7});

    REQUIRE(SUM == EXPECTED_SUM);

    cum::decum();
}
