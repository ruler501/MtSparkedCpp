cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_PlatformSpecific_RestApi_FileProvider)


add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

add_library(${PROJECT_NAME})

set(${PROJECT_NAME}_CONAN_LIBS)
set(${PROJECT_NAME}_CONAN_REMOTES)

include(${CMAKE_SOURCE_DIR}/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})





target_sources(${PROJECT_NAME} PUBLIC  include/mtsparked/services/fileprovider/restapi/restapifileprovider.h

                               PRIVATE src/restapifileprovider.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR})
target_link_libraries(MtSparked_Services_PlatformSpecific_RestApi_FileProvider INTERFACE MtSparked_Interop)
