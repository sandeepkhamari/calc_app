cmake_minimum_required(VERSION 3.10)
add_library(calc_lib STATIC src/calc.cpp)
target_include_directories(calc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(calc_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)
target_link_libraries(calc_lib 
    PRIVATE sum_lib 
    PRIVATE sub_lib 
    PRIVATE mul_lib 
    PRIVATE div_lib 
    PRIVATE add_lib
    PRIVATE pow_lib
    PRIVATE sqr_lib
    PRIVATE circle_lib
)

include(GNUInstallDirs)
install(TARGETS calc_lib
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/calc.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)