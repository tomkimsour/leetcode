cmake_minimum_required(VERSION 3.26)  # CMake version check
project(leetcode_questions)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/1-two-sum
)
add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/242-valid-anagram
)

# install(TARGETS 242-valid-anagram 1-two-sum DESTINATION release)



