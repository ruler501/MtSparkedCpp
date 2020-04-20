cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_UI)

option(ENABLE_TEST_QT "Enable testing the Qt plugin service and executables." ON)

if(ENABLE_TEST_QT)
    add_subdirectory(Qt)
endif()
