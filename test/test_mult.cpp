#include <iostream>
#include <gtest/gtest.h>
#include "mult.hpp"

using namespace std;

/**
 * @file test_mult.cpp
 * @brief Unit tests for the Multiplication class.
 */
struct MultTestParams
{
    double a;
    double b;
    double expected_result;
};

class Test_Multiplication: public ::testing::TestWithParam<MultTestParams> {};

TEST_P(Test_Multiplication, TestMultiply) 
{
    MultTestParams params = GetParam();
    Multiplication multiplication;
    ASSERT_NEAR(multiplication.multiply(params.a, params.b), params.expected_result, 1e-5)
        << "Input values: "<< params.a << ", " << params.b;
}

INSTANTIATE_TEST_SUITE_P(
    MultiplicationTests,
    Test_Multiplication,
    ::testing::Values(
        MultTestParams{2.0, 3.0, 6.0},
        MultTestParams{5.5, 2.0, 11.0},
        MultTestParams{-4.0, 2.5, -10.0},
        MultTestParams{0.0, 100.0, 0.0},
        MultTestParams{-3.0, -3.0, 9.0}
    )
);