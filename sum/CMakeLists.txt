cmake_minimum_required(VERSION 3.10)

add_library(sum_lib STATIC src/sum.cpp)
target_include_directories(sum_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(sum_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

target_link_libraries(sum_lib PUBLIC add_lib)

include(GNUInstallDirs)

install(TARGETS sum_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/sum.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)