cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_PlatformSpecific_WebAssembly_FileProvider)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/PlatformSpecific/WebAssembly/FileProvider" webassemblyfileprovider)
endif()

project(MtSparked_Tests_Services_PlatformSpecific_WebAssembly_FileProvider)

add_executable(${PROJECT_NAME} src/provideFilesWebAssemblyTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_PlatformSpecific_WebAssembly_FileProvider)

gtest_discover_tests(${PROJECT_NAME})
