cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_PlatformSpecific)

string(TOLOWER "${CMAKE_SYSTEM_NAME}" cmake_system_name_lower)
if(cmake_system_name_lower STREQUAL "windows")
    add_subdirectory(Windows)
elseif(cmake_system_name_lower STREQUAL "msys")
    add_subdirectory(Windows)
elseif(cmake_system_name_lower STREQUAL "darwin")
    # Might be iOS, will get to that when it becomes relevant
    add_subdirectory(Mac)
elseif(cmake_system_name_lower STREQUAL "android")
    add_subdirectory(Android)
elseif(cmake_system_name_lower STREQUAL "linux")
    add_subdirectory(Linux)
endif()
