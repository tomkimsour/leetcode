cmake_minimum_required(VERSION 3.26)  # CMake version check
project(238-product-of-array-except-self)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

add_executable(product_of_array_except_self main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)