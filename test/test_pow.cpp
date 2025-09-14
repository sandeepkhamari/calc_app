#include <iostream>
#include <gtest/gtest.h>
#include "pow.hpp"

using namespace std;

/**
 * @file test_pow.cpp
 * @brief Unit tests for the Power class.
 */
struct PowTestParams
{
    double base;
    int exponent;
    double expected_result;
};

class Test_Power: public ::testing::TestWithParam<PowTestParams> {};

TEST_P(Test_Power, TestPower) 
{
    PowTestParams params = GetParam();
    Power power;
    ASSERT_NEAR(power.power(params.base, params.exponent), params.expected_result, 1e-5)
        << "Input values: "<< params.base << ", " << params.exponent;
}

INSTANTIATE_TEST_SUITE_P(
    PowerTests,
    Test_Power,
    ::testing::Values(
        PowTestParams{2.0, 3, 8.0},
        PowTestParams{3.0, 4, 81.0},
        PowTestParams{2.5, 2, 6.25},
        PowTestParams{10.0, 1, 10.0}
    )
);

 //PowTestParams{5.0, 0, 1.0},
 //PowTestParams{2.0, -2, 0.25} // Assuming the function handles negative exponents