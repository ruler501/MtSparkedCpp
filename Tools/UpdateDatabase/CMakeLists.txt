cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tools_UpdateDatabase CXX)


add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

add_library(${PROJECT_NAME}Library)

set(${PROJECT_NAME}_CONAN_LIBS)
set(${PROJECT_NAME}_CONAN_REMOTES)

include(${CMAKE_SOURCE_DIR}/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}Library
             ACCESS PUBLIC
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})

target_sources(${PROJECT_NAME}Library PUBLIC include/mtsparked/tools/updatedatabase/updatedatabase.h
                                      PRIVATE src/updateDatabase.cpp)
target_link_libraries(${PROJECT_NAME}Library PUBLIC
                                                    MtSparked_Interop)
target_include_directories(${PROJECT_NAME}Library PUBLIC include)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Library)
