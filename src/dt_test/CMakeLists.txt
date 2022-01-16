project(dt_test)

include_directories (../../googletest/googletest/include)
include_directories(${ROOT_SOURCE_DIR}/src)

link_libraries(gtest_main EventFilterSystem)


set (EXECUTABLE_OUTPUT_PATH ${ROOT_SOURCE_DIR}/output)

file(GLOB SOURCES ./*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})