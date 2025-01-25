cmake_minimum_required(VERSION 3.5) 
project(mean_in_window_tests )

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if (is_top_level) 
    enable_testing() 
    find_package(mean-in-window-lib REQUIRED) 
endif()

find_package(GTest REQUIRED)

set(sources mean_in_window_test.cpp) 

add_executable(mean-in-window-tests) 
target_sources(mean-in-window-tests PRIVATE ${sources})

target_link_libraries(mean-in-window-tests PRIVATE mean-in-window-lib gtest gtest_main)

# gtest_discover_tests(mean-in-window-tests 
# 	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})