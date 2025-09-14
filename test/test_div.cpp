#include <iostream> 
#include <gtest/gtest.h>
#include "div.hpp"

using namespace std;

/**
 * @file test_div.cpp
 * @brief Unit tests for the Division class.
 */
struct DivTestParams
{
    double numerator;
    double denominator;
    double expected_result;
    bool expect_error; // To handle division by zero cases
};

class Test_Division: public ::testing::TestWithParam<DivTestParams> {};

TEST_P(Test_Division, TestDivide) 
{
    DivTestParams params = GetParam();
    Division division;
    if (params.expect_error) 
    {
        // Expecting an error for division by zero
        testing::internal::CaptureStderr();
        double result = division.divide(params.numerator, params.denominator);
        string output = testing::internal::GetCapturedStderr();
        ASSERT_EQ(result, 0); // Assuming the function returns 0 on error
        ASSERT_NE(output.find("Error: Division by zero!"), string::npos);
    } 
    else 
    {
        ASSERT_NEAR(division.divide(params.numerator, params.denominator), params.expected_result, 1e-5)
            << "Input values: "<< params.numerator << ", " << params.denominator;
    }
}

INSTANTIATE_TEST_SUITE_P(
    DivisionTests,
    Test_Division,
    ::testing::Values(
        DivTestParams{6.0, 3.0, 2.0, false},
        DivTestParams{5.0, 2.0, 2.5, false},
        DivTestParams{7.5, 2.5, 3.0, false},
        DivTestParams{10.0, 0.0, 0.0, true}, // Division by zero case
        DivTestParams{-6.0, -3.0, 2.0, false},
        DivTestParams{-6.0, 3.0, -2.0, false}
    )
);