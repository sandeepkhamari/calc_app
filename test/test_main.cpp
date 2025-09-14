#include <gtest/gtest.h>
#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "sqr.hpp"

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}