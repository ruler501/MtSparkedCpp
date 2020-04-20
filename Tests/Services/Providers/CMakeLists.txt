cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Services_Providers)

option(ENABLE_TEST_REST_API_PROVIDER "Enable the REST API Provider tests." ON)

if(ENABLE_TEST_REST_API_PROVIDER)
    add_subdirectory(RestApiProvider)
endif()
