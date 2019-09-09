cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Services_TCGPlayerCosts)
    add_subdirectory("${CMAKE_SOURCE_DIR}/Services/TCGPlayerCosts" tcgplayercosts)
endif()

project(MtSparked_Tests_Services_TCGPlayerCosts)

add_executable(${PROJECT_NAME} src/tcgPlayerCostsLookupTests.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main MtSparked_Services_TCGPlayerCosts)

gtest_discover_tests(${PROJECT_NAME})

