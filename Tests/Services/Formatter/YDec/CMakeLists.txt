cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_Formatter_YDec)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Formatter/YDec")
endif()

project(MtSparked_Tests_Services_Formatter_YDec)

add_executable(${PROJECT_NAME} src/yDecTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Formatter_YDec)

gtest_discover_tests(${PROJECT_NAME})
