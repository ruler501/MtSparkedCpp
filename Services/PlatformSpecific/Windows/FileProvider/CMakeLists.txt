cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_PlatformSpecific_Windows_FileProvider)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)
add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

add_library(${PROJECT_NAME})

set(${PROJECT_NAME}_CONAN_LIBS)
set(${PROJECT_NAME}_CONAN_REMOTES)

include(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})

configure_file(include/compiletimeplugins/plugins/windowsfileproviderservicecreator.h
               ${CMAKE_BINARY_DIR}/generated/include/compiletimeplugins/plugins/windowsfileproviderservicecreator.h
               COPYONLY)

target_sources(${PROJECT_NAME} PUBLIC  include/mtsparked/services/fileprovider/windows/windowsfileprovider.h
                                       include/compiletimeplugins/plugins/windowsfileproviderservicecreator.h
                               PRIVATE src/windowsfileprovider.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} INTERFACE CompileTimePlugins
                                                MtSparked_Interop)
