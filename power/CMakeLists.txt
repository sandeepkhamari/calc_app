cmake_minimum_required(VERSION 3.10)
add_library(pow_lib STATIC src/pow.cpp)
target_include_directories(pow_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(pow_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

target_link_libraries(pow_lib PUBLIC mul_lib)
include(GNUInstallDirs)

install(TARGETS pow_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/pow.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)