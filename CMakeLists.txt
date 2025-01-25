cmake_minimum_required(VERSION 3.5)
project(mean_in_window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(mean_in_window)

set(sources examples/example.cpp)

add_executable(mean-in-window ${sources})
target_link_libraries(mean-in-window mean-in-window-lib)
