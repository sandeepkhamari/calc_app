cmake_minimum_required(VERSION 3.10)

# As the googletest is compiled with MTd_StaticDebug, we need to set the same for our project
# Set the runtime library for MSVC (Visual Studio) to be dynamic (MD/MDd)
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
endif()

message(STATUS "CMAKE_MSVC_RUNTIME_LIBRARY: ${CMAKE_MSVC_RUNTIME_LIBRARY}")
# Ensure gtest uses the shared CRT to match your project (avoids /MT vs /MD mismatch)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Avoid installing gtest alongside your project
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

# Add test executable
add_executable(test_all test_main.cpp test_sqr.cpp test_add.cpp 
test_sub.cpp test_mult.cpp test_div.cpp test_circle.cpp 
test_pow.cpp test_sum.cpp
)

target_link_libraries(test_all PUBLIC 
add_lib sub_lib sqr_lib mul_lib
div_lib circle_lib pow_lib sqr_lib 
sum_lib PRIVATE GTest::gtest GTest::gtest_main
)

enable_testing()

target_include_directories(test_all PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../addition/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../subtraction/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../multiplication/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../division/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../circle/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../power/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../square/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../sum/include
)

set_target_properties(test_all PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

# ---- GoogleTest Integration ----
# Find the GoogleTest package
# Link to Googletest
# This links your test executable to the Googletest and gtest_main libraries.
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})
#target_link_libraries(test_all PRIVATE gtest gtest_main)

# ---- Discover and Run Tests ----
# Include CTest to enable testing functionality
#include(CTest)

include(GoogleTest)
# Automatically discovers and adds all tests to CTest
gtest_discover_tests(test_all)

