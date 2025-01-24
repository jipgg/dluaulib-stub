cmake_minimum_required(VERSION 3.22.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(dluaulib-stub LANGUAGES CXX C)
set(lib_EXPORT "DLUAU_LIB_EXPORT")

add_library(dluaulib-stub SHARED stub.cpp)
target_compile_definitions(dluaulib-stub PRIVATE ${lib_EXPORT})
target_include_directories(dluaulib-stub PUBLIC include)
set(lib_NAME dluaulib)
set_target_properties(dluaulib-stub PROPERTIES OUTPUT_NAME ${lib_NAME})
add_custom_command(TARGET dluaulib-stub POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E rm -f $<TARGET_FILE:dluaulib-stub>
)
