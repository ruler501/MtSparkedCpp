cmake_minimum_required(VERSION 3.14)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)
add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

project(MtSparked_Services_PlatformSpecific_WebAssembly_FileProvider)

add_library(${PROJECT_NAME})

set(${PROJECT_NAME}_CONAN_LIBS)
set(${PROJECT_NAME}_CONAN_REMOTES)

include(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})

configure_file(include/compiletimeplugins/plugins/webassemblyfileproviderservicecreator.h
               ${CMAKE_BINARY_DIR}/generated/include/compiletimeplugins/plugins/webassemblyfileproviderservicecreator.h
               COPYONLY)

target_sources(${PROJECT_NAME} PUBLIC  include/mtsparked/services/fileprovider/webassembly/webassemblyfileprovider.h
                                       include/compiletimeplugins/plugins/webassemblyfileproviderservicecreator.h
                               PRIVATE src/webassemblyfileprovider.cpp)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR}/include)
target_link_libraries(MtSparked_Services_PlatformSpecific_WebAssembly_FileProvider INTERFACE CompileTimePlugins MtSparked_Interop)
