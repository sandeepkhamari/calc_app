#include <iostream>
#pragma once
#include "add.hpp"
#include "gtest/gtest.h"

using namespace std;

/**
 * @file test_add.cpp
 * @brief Unit tests for the Addition class.
 */
class Test_Addition: public ::testing::Test
{
    protected:
        void setup() 
        {
            addition = new Addition();
        }

        void teardown() 
        {
            delete addition;
        }
    
    public:
        Addition* addition;
};

TEST_F(Test_Addition, TestAddPositiveNumbers) 
{
    EXPECT_EQ(addition->add(3, 5), 8);
}

TEST_F(Test_Addition, TestAddNegativeNumbers) 
{
    EXPECT_EQ(addition->add(-3, -5), -8);
}

TEST_F(Test_Addition, TestAddMixedNumbers) 
{
    EXPECT_EQ(addition->add(-3, 5), 2);
}

TEST_F(Test_Addition, TestAddZero) 
{
    EXPECT_EQ(addition->add(0, 5), 5);
    EXPECT_EQ(addition->add(3, 0), 3);
}

//int main(int argc, char **argv) 
//{
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}