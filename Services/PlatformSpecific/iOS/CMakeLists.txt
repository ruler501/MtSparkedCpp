cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_PlatformSpecific_iOS)

option(ENABLE_FILE_PROVIDER "Enable the file provider it can save and load files" ON)

if(ENABLE_FILE_PROVIDER)
    add_subdirectory(FileProvider)
endif()
