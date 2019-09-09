cmake_minimum_required(VERSION 3.14)
if(NOT TARGET MtSparked_Interop)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Interop" interop)
endif()

project(MtSparked_Tests_Interop)

add_executable(${PROJECT_NAME} src/interopTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Interop)

gtest_discover_tests(${PROJECT_NAME})
