cmake_minimum_required(VERSION 3.14)

project(MtSparked_Tests_Services)

option(ENABLE_TEST_CUBEPARSER "Enable testing the CubeParser plugin service." ON)
option(ENABLE_TEST_TCGPLAYERCOSTS "Enable testing the cost lookup plugin library that uses tcplayer." ON)
option(ENABLE_TEST_FORMATTER "Enable testing the Formatter plugin library." ON)
option(ENABLE_TEST_PROVIDERS "Enable testing the data provider plugin libraries." ON)
option(ENABLE_TEST_PLATFORM_SPECIFIC "Enable testing the PlatformSpecific plugin services." ON)

if(ENABLE_TEST_CUBEPARSER)
    add_subdirectory(CubeParser)
endif()
if(ENABLE_TEST_TCGPLAYERCOSTS)
    add_subdirectory(TCGPlayerCosts)
endif()
if(ENABLE_TEST_FORMATTER)
    add_subdirectory(Formatter)
endif()
if(ENABLE_TEST_PROVIDERS)
    add_subdirectory(Providers)
endif()
if(ENABLE_TEST_PLATFORM_SPECIFIC)
    add_subdirectory(PlatformSpecific)
endif()
