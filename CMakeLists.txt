cmake_minimum_required(VERSION 3.12)

OPTION(DEBUG_BUILD "Build for Debug binary" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (NOT EXISTS $ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "Pico SDK Path not found, please set correct environment variable PICO_SDK_PATH")
endif ()

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

if(DEBUG_BUILD)
  set(CMAKE_BUILD_TYPE=Debug)
endif()

enable_language(C CXX)
add_subdirectory(./src)

project(rp2040_bootstrap C CXX ASM)

project(pico-bootstrap
  VERSION 1.0
  DESCRIPTION "RP2040 Raspberry Pico Bootstrap Project with Debug Mode"
  LANGUAGES C
)
