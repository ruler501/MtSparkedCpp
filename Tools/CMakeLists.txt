cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tools)

option(ENABLE_UPDATE_DATABASE "Enable building the tool to update the database." ON)

if(ENABLE_UPDATE_DATABASE)
    add_subdirectory(UpdateDatabase)
endif()
