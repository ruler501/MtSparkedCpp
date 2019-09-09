cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Tools_UpdateDatabaseLibrary)
    add_subdirectory("${CMAKE_BINARY_DIR}/Tools/UpdateDatabase" updatedatabase)
endif()

project(MtSparked_Tests_Tools_UpdateDatabase)

add_executable(${PROJECT_NAME} src/updateDatabaseTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Tools_UpdateDatabaseLibrary)

gtest_discover_tests(${PROJECT_NAME})
