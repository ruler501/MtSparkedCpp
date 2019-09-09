cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_Providers_RestApiProvider)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Providers/RestApiProvider" restapiprovider)
endif()

project(MtSparked_Tests_Services_Providers_RestApiProvider)

add_executable(${PROJECT_NAME} src/restApiQueryTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Providers_RestApiProvider)

gtest_discover_tests(${PROJECT_NAME})

