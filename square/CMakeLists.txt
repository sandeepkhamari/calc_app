cmake_minimum_required(VERSION 3.10)

add_library(sqr_lib STATIC src/sqr.cpp)

target_include_directories(sqr_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(sqr_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)
target_link_libraries(sqr_lib PUBLIC pow_lib)

include(GNUInstallDirs)

install(TARGETS sqr_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/sqr.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)