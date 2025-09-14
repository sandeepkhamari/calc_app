#include <iostream>
#include "gtest/gtest.h"
#include "circle.hpp"

using namespace std;

/**
 * @file test_circle.cpp
 * @brief Unit tests for the Circle class.
 */
struct CircleTestParams
{
    double radius;
    double expected_area;
};

class Test_Circle: public ::testing::TestWithParam<CircleTestParams> {};

TEST_P(Test_Circle, TestArea) 
{
    CircleTestParams params = GetParam();
    Circle circle;
    ASSERT_NEAR(circle.area(params.radius), params.expected_area, 1e-5)
        << "Input value: "<< params.radius;
}

INSTANTIATE_TEST_SUITE_P(
    CircleTests,
    Test_Circle,
    ::testing::Values(
        CircleTestParams{1.0, 3.14159},
        CircleTestParams{2.0, 12.56636},
        CircleTestParams{3.5, 38.4844775},
        CircleTestParams{0.0, 0.0},
        CircleTestParams{-2.0, 12.56636} // Assuming area is always positive
    )
);

// To run the tests, use the command: ./your_test_executable --gtest_filter=CircleTests.*