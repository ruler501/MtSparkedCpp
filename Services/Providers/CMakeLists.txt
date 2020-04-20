cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_Providers)

option(ENABLE_REST_API_PROVIDER "Enable using the Rest API Query Provider plugin library." ON)

if(ENABLE_REST_API_PROVIDER)
    add_subdirectory(RestApiProvider)
endif()
