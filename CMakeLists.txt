cmake_minimum_required(VERSION 3.26)  # CMake version check
project(leetcode_questions)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard


add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/242-valid-anagram
)

# install(TARGETS 242-valid-anagram DESTINATION bin)



