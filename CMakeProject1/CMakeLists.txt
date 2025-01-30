cmake_minimum_required(VERSION 3.12)
project(CmakePriject1)

# First program: Prints "Hello World"
add_executable(hello_world hello_world.cpp)

# Second program: Prints "Hello CMake"
add_executable(hello_cmake hello_cmake.cpp)

# Optional: Set C++ standard for both
set_property(TARGET hello_world PROPERTY CXX_STANDARD 20)
set_property(TARGET hello_cmake PROPERTY CXX_STANDARD 20)