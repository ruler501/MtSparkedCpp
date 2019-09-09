cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_UI_QtLibrary)
    add_subdirectory("${CMAKE_SOURCE_DIR}/UI/QT" qt)
endif()

project(MtSparked_Tests_UI_Qt)

add_executable(${PROJECT_NAME} src/qtUiTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_UI_QtLibrary)

gtest_discover_tests(${PROJECT_NAME})
