cmake_minimum_required(VERSION 3.14)

if(NOT TARGET MtSparked_Interop)
    project(MtSparked_Interop CXX)
    
    add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)
    add_subdirectory(extern/crossguid)

    add_library(${PROJECT_NAME} INTERFACE)

    set(${PROJECT_NAME}_CONAN_LIBS)
    set(${PROJECT_NAME}_CONAN_REMOTES)

    include(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins/cmake/AddConanLibs.cmake)
    AddConanLibs(TARGET ${PROJECT_NAME}
                 ACCESS INTERFACE
                 REMOTES ${${PROJECT_NAME}_CONAN_REMOTES}
                 LIBS ${${PROJECT_NAME}_CONAN_LIBS})

    target_sources(${PROJECT_NAME} INTERFACE  include/mtsparked/database/binarytransformation.h
                                              include/mtsparked/database/domaincriteria.h
                                              include/mtsparked/database/query.h
                                              include/mtsparked/database/searchcriteria.h
                                              include/mtsparked/database/sortcriteria.h
                                              include/mtsparked/models/card.h
                                              include/mtsparked/models/deck.h
                                              include/mtsparked/services/costlookup.h
                                              include/mtsparked/services/fileprovider.h
                                              include/mtsparked/services/formatter.h
                                              include/mtsparked/services/packgenerator.h
                                              include/mtsparked/services/querypersistence.h
                                              include/mtsparked/services/queryprovider.h
                                              include/mtsparked/services/settings.h)
    target_include_directories(${PROJECT_NAME} INTERFACE include)
    target_link_libraries(MtSparked_Interop INTERFACE CompileTimePlugins
                                                      crossguid)
endif()
