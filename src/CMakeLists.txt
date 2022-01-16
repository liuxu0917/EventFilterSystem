project(EventFilterSystem)

set(CMAKE_CXX_STANDARD 14)

set (LIBRARY_OUTPUT_PATH ${ROOT_SOURCE_DIR}/output)

file(GLOB SOURCES ./*.cpp)
file(GLOB FILTER_SOURCES Filter/*.cpp)
file(GLOB PROCESSOR_SOURCES Processor/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${FILTER_SOURCES} ${PROCESSOR_SOURCES})
add_subdirectory(dt_test)