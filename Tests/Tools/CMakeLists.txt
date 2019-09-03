cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Tools)

option(ENABLE_TEST_UPDATE_DATABASE "Enable testing the Database Update executable tools." ON)

if(ENABLE_TEST_UPDATE_DATABASE)
    add_subdirectory(UpdateDatabase)
endif()
