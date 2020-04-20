cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_PlatformSpecific_Mac_FileProvider)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugin)
add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

add_library(${PROJECT_NAME})

include(${CMAKE_SOURCE_DIR}/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})





target_sources(${PROJECT_NAME} PUBLIC  include/mtsparked/services/fileprovider/mac/macfileprovider.h

                               PRIVATE src/macfileprovider.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} INTERFACE
                                                MtSparked_Interop)
