cmake_minimum_required(VERSION 3.10)
add_library(mul_lib STATIC src/mult.cpp)
target_include_directories(mul_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(mul_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)
include(GNUInstallDirs)

install(TARGETS mul_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/mult.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)