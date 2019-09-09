cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_Providers_CouchBaseLiteProvider)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Providers/CouchBaseLiteProvider" couchbaseliteprovider)
endif()

project(MtSparked_Tests_Services_Providers_CouchBaseLiteProvider)

add_executable(${PROJECT_NAME} src/couchBaseLiteQueryTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Providers_CouchBaseLiteProvider)

gtest_discover_tests(${PROJECT_NAME})
