cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_Providers)

option(ENABLE_COUCHBASE_LITE_PROVIDER "Enable using CouchBase Lite plugin library as a query provider." ON)
option(ENABLE_REST_API_PROVIDER "Enable using the Rest API Query Provider plugin library." ON)

if(ENABLE_COUCHBASE_LITE_PROVIDER)
    add_subdirectory(CouchBaseLiteProvider)
endif()
if(ENABLE_REST_API_PROVIDER)
    add_subdirectory(RestApiProvider)
endif()
