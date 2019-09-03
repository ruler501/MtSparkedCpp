cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0002 OLD)

project(MtSparked CXX)

option(ENABLE_SERVICES "Enable building the plugin services." ON)
option(ENABLE_UI "Enable building the UI interface executables and library plugins." ON)
option(ENABLE_TOOLS "Enable building the tools executables." ON)
option(ENABLE_TESTS "Enable building the tests." ON)

add_subdirectory(Interop)
if(ENABLE_SERVICES)
    add_subdirectory(Services)
endif()
if(ENABLE_UI)
    add_subdirectory(UI)
endif()
if(ENABLE_TOOLS)
    add_subdirectory(Tools)
endif()
if(ENABLE_TESTS)
    add_subdirectory(Tests EXCLUDEFROMALL)
endif()
