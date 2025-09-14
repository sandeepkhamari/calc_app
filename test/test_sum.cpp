#include <iostream>
#include <gtest/gtest.h>
#include "sum.hpp"

using namespace std;

/**
 * @file test_sum.cpp
 * @brief Unit tests for the Sum class.
 */
struct SumTestParams
{
    int n;
    int expected_sum;
};

class Test_Sum: public ::testing::TestWithParam<SumTestParams> {};

TEST_P(Test_Sum, TestSummation) 
{
    SumTestParams params = GetParam();
    Sum sum;
    ASSERT_EQ(sum.summation(params.n), params.expected_sum)
        << "Input value: "<< params.n;
}

INSTANTIATE_TEST_SUITE_P(
    SumTests,
    Test_Sum,
    ::testing::Values(
        SumTestParams{1, 1},
        SumTestParams{5, 15},
        SumTestParams{10, 55},
        SumTestParams{0, 0},
        SumTestParams{-3, 0} // Assuming summation for negative numbers is 0
    )
);