cmake_minimum_required(VERSION 3.14)

add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

project(MtSparked_Services_CubeParser CXX)

add_library(${PROJECT_NAME} INTERFACE)
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
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/functionnodes/stringfuncions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/propfunctionnodewrapper.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/arraypropositions.h
                                         include/mtsparked/services/packgenerator/cubeparser/nodes/operatorpropositions.h
                                         include/mtsparked/services/packgenerator/cubeparser/cubeparserservicecreator.h)

set(BUILD_FROM_SOURCE "" CACHE STRING "Build these packages from source, very time intensive. Can use all to make it build all from source.")
    
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_check(REQUIRED)
if(DEFINED CONAN_COMMAND)
    set(GLOBAL PROPERTY CONAN_CMD "${CONAN_COMMAND}")
endif()

conan_add_remote(NAME bincrafters URL https://api.bintray.com/conan/bincrafters/public-conan)

set(${PROJECT_NAME}_REQUIRE_CONAN_LIBS "")
set(${PROJECT_NAME}_LINK_CONAN_LIBS "")

list(APPEND ${PROJECT_NAME}_REQUIRE_CONAN_LIBS "boost_spirit/1.69.0@bincrafters/stable")
list(APPEND ${PROJECT_NAME}_LINK_CONAN_LIBS "CONAN_PKG::boost_spirit")

if(${PROJECT_NAME}_REQUIRE_CONAN_LIBS)
    if(BUILD_FROM_SOURCE)
        conan_cmake_run(REQUIRES ${${PROJECT_NAME}_REQUIRE_CONAN_LIBS}
                        BUILD ${BUILD_FROM_SOURCE}
                        BASIC_SETUP CMAKE_TARGETS)
    else()
        conan_cmake_run(REQUIRES ${${PROJECT_NAME}_REQUIRE_CONAN_LIBS}
                BASIC_SETUP CMAKE_TARGETS)
    endif()
    foreach(CONAN_LIB " ${${PROJECT_NAME}_LINK_CONAN_LIBS}")
        string(REGEX REPLACE " " "" CONAN_LIB "${CONAN_LIB}")
        target_link_libraries(${PROJECT_NAME} INTERFACE ${CONAN_LIB})
    endforeach()
endif()

target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR}/include)

configure_file(include/mtsparked/services/packgenerator/cubeparser/cubeparserservicecreator.h
               ${CMAKE_BINARY_DIR}/generated/include/compiletimeplugins/plugins/cubeparserservicecreator.h
               COPYONLY)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)

target_link_libraries(MtSparked_Services_CubeParser INTERFACE CompileTimePlugins MtSparked_Interop)
