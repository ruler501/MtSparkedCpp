cmake_minimum_required(VERSION 3.14)

project(MtSparked_UI_Qt)

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/compiletime-plugins compiletime-plugins)
add_subdirectory(${CMAKE_SOURCE_DIR}/Interop interop)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(${PROJECT_NAME}Library)

find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

target_sources(${PROJECT_NAME}Library PRIVATE src/mainwindow.cpp
                                              src/mainwindow.ui
                                      PUBLIC  include/mtsparked/ui/qt/views/mainwindow.h
                                              include/mtsparked/ui/qt/viewmodels/settingsviewmodel.h
                                              include/mtsparked/ui/qt/viewmodels/cards/cardviewmodel.h
                                              include/mtsparked/ui/qt/viewmodels/decks/deckviewmodel.h
                                              include/mtsparked/ui/qt/viewmodels/search/domaincriteriaviewmodel.h
                                              include/mtsparked/ui/qt/viewmodels/search/searchcriteriaviewmodel.h
                                              include/mtsparked/ui/qt/viewmodels/search/searchviewmodel.h)
target_include_directories(${PROJECT_NAME}Library PUBLIC include)
target_link_libraries(${PROJECT_NAME}Library PUBLIC  CompileTimePlugins 
                                                     MtSparked_Interop
                                                     Qt5::Widgets 
                                             PRIVATE Qt5::Core
                                                     Qt5::Gui)

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Library)
