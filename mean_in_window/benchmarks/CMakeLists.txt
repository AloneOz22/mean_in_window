cmake_minimum_required(VERSION 3.5)

project(mean_in_window_lib_benchmark LANGUAGES CXX)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    enable_testing()
    find_package(mean-in-window-lib REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 14)

find_package(benchmark REQUIRED)

set(sources mean_in_window_benchmark.cpp)

add_executable(mean-in-window-bench)
target_sources(mean-in-window-bench PRIVATE ${sources})

target_link_libraries(mean-in-window-bench PRIVATE benchmark::benchmark benchmark::benchmark_main mean-in-window-lib)
