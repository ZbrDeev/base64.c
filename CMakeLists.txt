cmake_minimum_required(VERSION 3.20)

project(base64 VERSION 1.0.5 DESCRIPTION "Base64 library")

add_library(base64 SHARED base64.c)
target_link_libraries(base64 m)

set_target_properties(base64 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER base64.h)

target_include_directories(base64 PRIVATE .)

install(TARGETS base64
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

