cmake_minimum_required(VERSION 3.14)
if(NOT TARGET MtSparked_Services_CubeParser)
    add_subdirectory(${CMAKE_SOURCE_DIR}/Services/CubeParser cubeparser)
endif()

project(MtSparked_Tests_Services_CubeParser)

add_executable(${PROJECT_NAME} src/cubeParsingTests.cpp
                               src/cubeGenerationTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_CubeParser)

gtest_discover_tests(${PROJECT_NAME})
