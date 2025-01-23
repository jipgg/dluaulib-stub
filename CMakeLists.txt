cmake_minimum_required(VERSION 3.22.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(dluaulib_stub LANGUAGES CXX C)
set(lib_EXPORT "DLUAU_LIB_EXPORT")

add_library(dluaulib_stub SHARED dluaulib_stub.cpp)
target_compile_definitions(dluaulib_stub PRIVATE ${lib_EXPORT})
target_include_directories(dluaulib_stub PUBLIC include)
set(lib_NAME dluaulib)
set_target_properties(dluaulib_stub PROPERTIES OUTPUT_NAME ${lib_NAME})
add_custom_command(TARGET dluaulib_stub POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E rm -f $<TARGET_FILE:dluaulib_stub>
)
