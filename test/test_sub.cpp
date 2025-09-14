#include "sub.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

/**
 * @file test_sub.cpp
 * @brief Unit tests for the Subtraction class.
 */
class Test_Subtraction: public ::testing::Test
{
    protected:
        void SetUp() 
        {
            subtraction = new Subtraction();
        }

        void TearDown() 
        {
            delete subtraction;
        }
    
    public:
        Subtraction* subtraction;
};

TEST_F(Test_Subtraction, TestSubtractPositiveNumbers) 
{
    EXPECT_EQ(subtraction->subtract(5, 3), 2);
}

TEST_F(Test_Subtraction, TestSubtractNegativeNumbers)
{
    EXPECT_EQ(subtraction->subtract(-5, -3), -2);
}

TEST_F(Test_Subtraction, TestSubtractMixedNumbers) 
{
    EXPECT_EQ(subtraction->subtract(5, -3), 8);
    EXPECT_EQ(subtraction->subtract(-5, 3), -8);
}

TEST_F(Test_Subtraction, TestSubtractZero) 
{
    EXPECT_EQ(subtraction->subtract(0, 5), -5);
    EXPECT_EQ(subtraction->subtract(5, 0), 5);
}