cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(example_project)

pico_sdk_init()

add_executable(example
	example.c
	non_blocking_timer.c
)

pico_enable_stdio_usb(example 1)
pico_enable_stdio_uart(example 1)
pico_add_extra_outputs(example)
target_link_libraries(example pico_stdlib)
