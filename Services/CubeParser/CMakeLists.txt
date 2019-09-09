cmake_minimum_required(VERSION 3.14)

project(MtSparked_Services_CubeParser CXX)

add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)
add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)

add_library(${PROJECT_NAME} INTERFACE)

set(${PROJECT_NAME}_CONAN_LIBS)
set(${PROJECT_NAME}_CONAN_REMOTES)

list(APPEND ${PROJECT_NAME}_CONAN_LIBS "boost_spirit/1.69.0@bincrafters/stable")
list(APPEND ${PROJECT_NAME}_CONAN_REMOTES "https://api.bintray.com/conan/bincrafters/public-conan")

include(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins/cmake/AddConanLibs.cmake)
AddConanLibs(TARGET ${PROJECT_NAME}
             ACCESS INTERFACE
             REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
             LIBS ${${PROJECT_NAME}_CONAN_LIBS})

configure_file(include/compiletimeplugins/plugins/cubeparserservicecreator.h
               ${CMAKE_CURRENT_BINARY_DIR}/generated/include/compiletimeplugins/plugins/cubeparserservicecreator.h
               COPYONLY)

target_sources(${PROJECT_NAME} INTERFACE include/mtsparked/services/packgenerator/cubeparser/cubeparser.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodewrapper.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/addnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/arraynode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/assignnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/boardnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/comprehensionnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/constantnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/extractnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/repeatnode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/unpacknode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/variablenode.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodewrapper.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodes/arrayfunctions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodes/metafunctions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodes/numericfunctions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodes/stringfunctions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/propfunctionnodewrapper.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/propfunctionnodes/arraypropositions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/propfunctionnodes/operatorpropositions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/propfunctionnodes/propositions.h
                                         include/compiletimeplugins/plugins/cubeparserservicecreator.h)
target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} INTERFACE CompileTimePlugins
                                                MtSparked_Interop)
