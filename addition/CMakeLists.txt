cmake_minimum_required(VERSION 3.10)
add_library(add_lib STATIC src/add.cpp)
target_include_directories(add_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#set_target_properties(add_lib PROPERTIES OUTPUT_NAME "Addition")
#add_library(Addition ALIAS add_lib)

set_target_properties(add_lib PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED ON
)

include(GNUInstallDirs)

#This command is crucial to make the library available for installation.
#i.e. exportable.
install(TARGETS add_lib 
    #ARCHIVE DESTINATION lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #LIBRARY DESTINATION lib
    #NOT NEEDED FOR STATIC
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #RUNTIME DESTINATION bin
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

#install the public headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ 
    #DESTINATION include
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)
