cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Services_PlatformSpecific_Linux)

option(ENABLE_TEST_FILEPROVIDER "Enable testing the platform specific File Provider plugin service." ON)

if(ENABLE_TEST_FILEPROVIDER)
    add_subdirectory(FileProvider)
endif()
