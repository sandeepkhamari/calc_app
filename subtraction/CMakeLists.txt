cmake_minimum_required(VERSION 3.10)
add_library(sub_lib STATIC src/sub.cpp)
target_include_directories(sub_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) 
set_target_properties(sub_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

include(GNUInstallDirs)

install(TARGETS sub_lib 
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/sub.hpp 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)