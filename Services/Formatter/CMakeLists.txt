cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_Formatter)

option(ENABLE_JDEC "Enable using the JDec format for persistence." ON)
option(ENABLE_DEC "Enable using the Dec format for persistence." ON)
option(ENABLE_COL2 "Enable using the Col2 format for persistence." ON)

if(ENABLE_JDEC)
    add_subdirectory(JDec)
endif()
if(ENABLE_DEC)
    add_subdirectory(Dec)
endif()
if(ENABLE_COL2)
    add_subdirectory(Col2)
endif()
