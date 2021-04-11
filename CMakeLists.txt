cmake_minimum_required(VERSION 3.12)

OPTION(PICO_BUILD "Build the binary for upload to Pico" OFF)
OPTION(DEBUG_BUILD "Build for Debug binary" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(PICO_BUILD)
  if (NOT EXISTS $ENV{PICO_SDK_PATH})
    message(FATAL_ERROR "Pico SDK Path not found, please set correct environment variable PICO_SDK_PATH")
  endif ()

  include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
  pico_sdk_init()

  enable_language(C CXX)
  add_subdirectory(./src)
endif()

if(DEBUG_BUILD)
  if (NOT EXISTS $ENV{PICO_DEBUG_SDK_PATH})
    message(FATAL_ERROR "Pico Debug SDK Path not found, please set correct environment variable PICO_SDK_PATH")
  endif ()

  set(CMAKE_BUILD_TYPE=Debug)

  include($ENV{PICO_DEBUG_SDK_PATH}/pico_sdk_init.cmake)
  pico_sdk_init()
  
  enable_language(C CXX)
  add_subdirectory(./src)
endif()

include($ENV{PICO_DEBUG_SDK_PATH}/pico_sdk_init.cmake)

project(rp2040_bootstrap C CXX ASM)

project(pico-bootstrap
  VERSION 1.0
  DESCRIPTION "RP2040 Raspberry Pico Bootstrap Project with Debug Mode"
  LANGUAGES C
)

