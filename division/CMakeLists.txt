cmake_minimum_required(VERSION 3.10)
add_library(div_lib STATIC src/div.cpp)

target_include_directories(div_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(div_lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

include(GNUInstallDirs)

install(TARGETS div_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/div.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)