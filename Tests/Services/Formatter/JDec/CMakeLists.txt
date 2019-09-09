cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_Formatter_JDec)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Formatter/JDec")
endif()

project(MtSparked_Tests_Services_Formatter_JDec)

add_executable(${PROJECT_NAME} src/jDecTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Formatter_JDec)

gtest_discover_tests(${PROJECT_NAME})
