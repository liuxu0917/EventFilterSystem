cmake_minimum_required(VERSION 3.00)
set(ROOT_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_BUILD_TYPE "Release")
IF (WIN32)
    MESSAGE(STATUS "Now is windows")
    add_definitions(-D WIN32)
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systens.")
    add_definitions(-D APPLE)
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's.")
    add_definitions(-D UNIX)
ENDIF ()
add_subdirectory(src)
add_subdirectory(googletest)

