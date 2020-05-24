cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Interop)
    project(MtSparked_Interop CXX)

    option(CROSSGUID_TESTS "Build test runner for crossguid." OFF)
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/crossguid crossguid)
    option(CPPPROPERTY_TESTS "Build tests for CppProperty." OFF)
    option(CPPPROPERTY_EXAMPLES "Build examples for CppProperty." OFF)
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/cppproperty cppproperty)

    add_library(${PROJECT_NAME})

    target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

    set(${PROJECT_NAME}_CONAN_LIBS)
    set(${PROJECT_NAME}_CONAN_REMOTES)

    include(${CMAKE_SOURCE_DIR}/cmake/AddConanLibs.cmake)
    AddConanLibs(TARGET ${PROJECT_NAME}
                 ACCESS INTERFACE
                 REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
                 LIBS ${${PROJECT_NAME}_CONAN_LIBS})

    target_sources(${PROJECT_NAME} PUBLIC include/mtsparked/database/binarytransformation.h
                                          include/mtsparked/database/domaincriteria.h
                                          include/mtsparked/database/query.h
                                          include/mtsparked/database/searchcriteria.h
                                          include/mtsparked/database/sortcriteria.h
                                          include/mtsparked/models/card.h
                                          include/mtsparked/models/deck.h
                                          include/mtsparked/models/dollarValue.h
                                          include/mtsparked/services/costlookup.h
                                          include/mtsparked/services/fileprovider.h
                                          include/mtsparked/services/formatter.h
                                          include/mtsparked/services/packgenerator.h
                                          include/mtsparked/services/querypersistence.h
                                          include/mtsparked/services/queryprovider.h
                                          include/mtsparked/services/settings.h
                                          include/mtsparked/utils/erasedcontainer.h
                                  PRIVATE src/mtsparked/models/card.cpp)

    target_include_directories(${PROJECT_NAME} PUBLIC include)
    target_link_libraries(MtSparked_Interop PUBLIC cppproperty
                                                   crossguid)
endif()
