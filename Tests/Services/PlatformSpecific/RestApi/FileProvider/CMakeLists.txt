cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_PlatformSpecific_RestApi_FileProvider)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/PlatformSpecific/RestApi/FileProvider" restapifileprovider)
endif()

project(MtSparked_Tests_Services_PlatformSpecific_RestApi_FileProvider)

add_executable(${PROJECT_NAME} src/provideFilesRestApiTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_PlatformSpecific_RestApi_FileProvider)

gtest_discover_tests(${PROJECT_NAME})
