cmake_minimum_required(VERSION 3.14)

project(MtSparked_UI)

option(ENABLE_QT "Enable the Qt interface view for the app." ON)

if(ENABLE_QT)
    add_subdirectory(Qt)
endif()
