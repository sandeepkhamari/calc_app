cmake_minimum_required(VERSION 3.10)

# As the googletest is compiled with MTd_StaticDebug, we need to set the same for our project
# Set the runtime library for MSVC (Visual Studio) to be dynamic (MD/MDd)
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
endif()

project(FinalProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(addition)
add_subdirectory(subtraction)
add_subdirectory(multiplication)
add_subdirectory(division)

add_subdirectory(circle)
add_subdirectory(power)
add_subdirectory(square)
add_subdirectory(sum)
add_subdirectory(calculator)

add_subdirectory(test)

add_executable(calc_app calc_runner/src/main.cpp)
#target_link_libraries(calc_app Addition Subtraction Multiplication Division)
#target_link_libraries(calc_app PUBLIC Addition)
target_link_libraries(calc_app PUBLIC 
add_lib sub_lib mul_lib 
div_lib circle_lib 
pow_lib sqr_lib 
sum_lib calc_lib
)

target_include_directories(calc_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/addition/include
    ${CMAKE_CURRENT_SOURCE_DIR}/subtraction/include
    ${CMAKE_CURRENT_SOURCE_DIR}/multiplication/include
    ${CMAKE_CURRENT_SOURCE_DIR}/division/include
    ${CMAKE_CURRENT_SOURCE_DIR}/circle/include
    ${CMAKE_CURRENT_SOURCE_DIR}/power/include
    ${CMAKE_CURRENT_SOURCE_DIR}/square/include
    ${CMAKE_CURRENT_SOURCE_DIR}/sum/include
)

# Set a default installation prefix
#if(NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")
#endif()
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# Add this section to your top-level CMakeLists.txt
# This will install your main executable.
include(GNUInstallDirs)
#install(TARGETS calc_app DESTINATION bin)
install(TARGETS calc_app 
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# You can also install the dependent libraries and headers if they aren't already handled
# by the subdirectory's install rules.
#install(TARGETS Addition DESTINATION lib)
#install(DIRECTORY addition/include/ DESTINATION include)

# --- Configure GoogleTest ---
# Include the FetchContent module
include(FetchContent)

# Define the content to fetch (Googletest)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY  https://github.com/google/googletest.git
  GIT_TAG         v1.16.0
)

# Populate the content, which downloads and exposes the source code
FetchContent_MakeAvailable(googletest)

#add_subdirectory(test)

# Add your executable for running tests
#add_executable(
#    FinalProjectTests
#    test/test_main.cpp
#    test/test_add.cpp
#    test/test_sub.cpp
    #test/test_mult.cpp
    #test/test_div.cpp
    #test/test_circle.cpp
    #test/test_pow.cpp
#    test/test_sqr.cpp
    #test/test_sum.cpp
#)

# Link your executable to the necessary Googletest libraries
#target_link_libraries( FinalProjectTests PRIVATE
    #gtest
    #gtest_main
  #  GTest::gtest_main
  ##  add_lib
   # sub_lib
    #mul_lib
    #div_lib
    #circle_lib
    #pow_lib
    #sqr_lib
    #sum_lib
#)

enable_testing()
include(CTest)

# You can also use the gtest_discover_tests command to automatically find and run your tests
#include(CTest)
#gtest_discover_tests(FinalProjectTests)


# --- End of Googletest configuration ---
