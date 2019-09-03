cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests)

# Download and unpack googletest at configure time
configure_file(${CMAKE_SOURCE_DIR}/cmake/DownloadGoogleTest.cmake.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

option(ENABLE_TEST_INTEROP "Enable testing the interop shared library." ON)
option(ENABLE_TEST_SERVICES "Enable testing the services shared libraries." ON)
option(ENABLE_TEST_UI "Enable testing the ui libraries." ON)
option(ENABLE_TEST_TOOLS "Enable testing the tool projects." ON)

if(ENABLE_TEST_INTEROP)
    add_subdirectory(Interop)
endif()
if(ENABLE_TEST_SERVICES)
    add_subdirectory(Services)
endif()
if(ENABLE_TEST_UI)
    add_subdirectory(UI)
endif()
if(ENABLE_TEST_TOOLS)
    add_subdirectory(Tools)
endif()
