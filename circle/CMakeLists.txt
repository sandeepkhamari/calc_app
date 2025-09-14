cmake_minimum_required(VERSION 3.10)

add_library(circle_lib STATIC src/circle.cpp)
target_include_directories(circle_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(circle_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

target_link_libraries(circle_lib PUBLIC mul_lib)

include(GNUInstallDirs)

install(TARGETS circle_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/circle.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)