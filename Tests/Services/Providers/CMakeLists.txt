cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Services_Providers)

option(ENABLE_TEST_COUCHBASE_LITE_PROVIDER "Enable the CouchBase Lite Provider tests." ON)
option(ENABLE_TEST_REST_API_PROVIDER "Enable the REST API Provider tests." ON)

if(ENABLE_TEST_COUCHBASE_LITE_PROVIDER)
    add_subdirectory(CouchBaseLiteProvider)
endif()
if(ENABLE_TEST_REST_API_PROVIDER)
    add_subdirectory(RestApiProvider)
endif()
