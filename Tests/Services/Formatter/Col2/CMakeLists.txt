cmake_minimum_required(VERSION 3.14)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

add_subdirectory("${CMAKE_SOURCE_DIR}/Services/Formatter/Col2")

project(MtSparked_Tests_Services_Formatter_Col2)

add_executable(${PROJECT_NAME} PRIVATE src/col2Tests.cpp)

add_target_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_Formatter_Col2)

gtest_discover_tests(${PROJECT_NAME})

