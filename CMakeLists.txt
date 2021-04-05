cmake_minimum_required(VERSION 3.12)

if (NOT EXISTS $ENV{PICO_DEBUG_SDK_PATH})
  message(FATAL_ERROR "Pico Debug SDK Path not found")
endif ()

include($ENV{PICO_DEBUG_SDK_PATH}/pico_sdk_init.cmake)

project(rp2040_bootstrap C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(./src/)
