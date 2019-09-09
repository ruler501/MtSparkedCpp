cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_Providers_CouchBaseLiteProvider CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)
add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)
add_subdirectory(extern/couchbase-lite-C)

add_library(${PROJECT_NAME})

include(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})

configure_file(include/compiletimeplugins/plugins/couchbasequeryproviderservicecreator.h
               ${CMAKE_BINARY_DIR}/generated/include/compiletimeplugins/plugins/couchbasequeryproviderservicecreator.h
               COPYONLY)

target_sources(${PROJECT_NAME} PUBLIC   include/mtsparked/services/queryprovider/couchbaselite/couchbasequery.h
                                        include/mtsparked/services/queryprovider/couchbaselite/couchbasequeryprovider.h
                                        include/mtsparked/services/queryprovider/couchbaselite/couchbasequeryexecutor.h
                                        include/compiletimeplugins/plugins/couchbasequeryproviderservicecreator.h
                               PRIVATE  src/couchbasequeryexecutor.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC  CompileTimePlugins
                                              MtSparked_Interop
                                      PRIVATE CouchbaseLiteCStatic)
