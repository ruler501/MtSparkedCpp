cmake_minimum_required(VERSION 3.14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

project(MtSparked_UI_Qt)

add_library(${PROJECT_NAME} INTERFACE)

set(BUILD_FROM_SOURCE "" CACHE STRING "Build these packages from source, very time intensive. Can use all to make it build all from source.")
    
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

target_sources(${PROJECT_NAME} INTERFACE include/mtsparked/ui/qt/viewmodels/settingsviewmodel.h
                                         include/mtsparked/ui/qt/viewmodels/cards/cardsviewmodel.h
                                         include/mtsparked/ui/qt/viewmodels/decks/decksviewmodel.h
                                         include/mtsparked/ui/qt/viewmodels/search/domaincriteriaviewmodel.h
                                         include/mtsparked/ui/qt/viewmodels/search/searchcriteriaviewmodel.h
                                         include/mtsparked/ui/qt/viewmodels/search/searchviewmodel.h)

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_check(REQUIRED)
if(DEFINED CONAN_COMMAND)
    set(GLOBAL PROPERTY CONAN_CMD "${CONAN_COMMAND}")
endif()

set(${PROJECT_NAME}_REQUIRE_CONAN_LIBS "")
set(${PROJECT_NAME}_LINK_CONAN_LIBS "")

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
        target_link_libraries(${PROJECT_NAME} PUBLIC ${CONAN_LIB})
    endforeach()
endif()

# find_package(Qt5 COMPONENTS Widgets REQUIRED)
# find_package(Qt5 COMPONENTS Core REQUIRED)

target_include_directories(${PROJECT_NAME} INTERFACE ${CURRENT_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)

target_link_libraries(MtSparked_UI_Qt INTERFACE CompileTimePlugins 
                                                # Qt5::Widgets Qt5::Core
                                                MtSparked_Interop)
