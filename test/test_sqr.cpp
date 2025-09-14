#include "sqr.hpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * @file test_sqr.cpp
 * @brief Unit tests for the Square class.
 */
struct SqrTestParams
{
    double side;
    double expected_area;
};

class Test_Square: public ::testing::TestWithParam<SqrTestParams> {};

TEST_P(Test_Square, TestArea) 
{
    SqrTestParams params = GetParam();
    Square square;
    ASSERT_EQ(square.area(params.side), params.expected_area)
        << "Input value: "<< params.side;
}

INSTANTIATE_TEST_SUITE_P(
    SquareTests,
    Test_Square,
    ::testing::Values(
        SqrTestParams{2.0, 4.0},
        SqrTestParams{3.0, 9.0},
        SqrTestParams{4.5, 20.25},
        SqrTestParams{0.0, 0.0},
        SqrTestParams{-2.0, 4.0} // Assuming area is always positive
    )
);