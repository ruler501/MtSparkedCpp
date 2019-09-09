cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_Formatter_Col2)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Formatter/Col2" col2)
endif()

project(MtSparked_Tests_Services_Formatter_Col2)

add_executable(${PROJECT_NAME} src/col2Tests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Formatter_Col2)

gtest_discover_tests(${PROJECT_NAME})

