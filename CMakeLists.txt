cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0002 OLD)

project(MtSparked
        DESCRIPTION "App to manage magic collections and decks."
        VERSION 0.0.0
        HOMEPAGE_URL "https://github.com/ruler501/MtSparked2"
        LANGUAGES CXX)

option(ENABLE_SERVICES "Enable building the plugin services." ON)
option(ENABLE_UI "Enable building the UI interface executables and library plugins." ON)
option(ENABLE_TOOLS "Enable building the tools executables." ON)
option(ENABLE_TESTS "Enable building the tests." ON)

add_subdirectory(Interop)
if(ENABLE_SERVICES)
    add_subdirectory(Services)
endif()
if(ENABLE_UI)
    add_subdirectory(UI)
endif()
if(ENABLE_TOOLS)
    add_subdirectory(Tools)
endif()
if(ENABLE_TESTS)
    add_subdirectory(Tests EXCLUDEFROMALL)
endif()

add_custom_command(COMMAND ${CMAKE_COMMAND} . --graphviz=graphviz/mtsparked.json
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   OUTPUT ${CMAKE_BINARY_DIR}/graphviz/mtsparked.json
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/graphviz/mtsparked.json
                   VERBATIM)
add_custom_target(GenerateGraphvizJson
                  DEPENDS ${CMAKE_BINARY_DIR}/graphviz/mtsparked.json)

add_custom_command(COMMAND dot -Tsvg -o mtsparked.svg graphviz/mtsparked.json
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   DEPENDS ${CMAKE_BINARY_DIR}/graphviz/mtsparked.json
                   MAIN_DEPENDENCY ${CMAKE_BINARY_DIR}/graphviz/mtsparked.json
                   OUTPUT ${CMAKE_BINARY_DIR}/mtsparked.svg
                   BYPRODUCTS ${CMAKE_BINARY_DIR}/mtsparked.svg
                   VERBATIM)
add_custom_target(GenerateGraphvizSvg
                  DEPENDS ${CMAKE_BINARY_DIR}/mtsparked.svg)
