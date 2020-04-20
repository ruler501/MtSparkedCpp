cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Formats)

option(ENABLE_TEST_YDEC "Enable testing the YDec format plugin library." ON)
option(ENABLE_TEST_COL2 "Enable testing the Col2 format plugin library." ON)
option(ENABLE_TEST_DEC "Enable testing the Dec format plugin library." ON)

if(ENABLE_TEST_JDEC)
    add_subdirectory(YDec)
endif()
if(ENABLE_TEST_COL2)
    add_subdirectory(Col2)
endif()
if(ENABLE_TEST_DEC)
    add_subdirectory(Dec)
endif()
