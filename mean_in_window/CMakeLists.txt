cmake_minimum_required(VERSION 3.5)
project(mean_in_window_lib LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")


option(BUILD_TESTS "Build tests" OFF)
option(BUILD_BENCHMARKS "Build benchmarks" OFF)

set(lib_sources src/mean_in_window.cpp include/mean_in_window.hpp)

add_library(mean-in-window-lib STATIC ${lib_sources})

target_include_directories(mean-in-window-lib PUBLIC include)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()