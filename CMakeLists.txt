cmake_minimum_required(VERSION 3.26)  # CMake version check
project(leetcode_questions)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)


add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/1-two-sum
)
add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/242-valid-anagram
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/49-group-anagrams
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/347-top-k-frequent
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/238-product-of-array-except-self
)
add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/36-valid-sudoku
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/125-valid-palindrome
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/20-valid-parentheses
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/167-two-sum
)

add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/704-binary-search
)
add_subdirectory(  
  ${PROJECT_SOURCE_DIR}/74-search-a-2D-matrix
)
add_subdirectory(
  ${PROJECT_SOURCE_DIR}/875-koko-eating-bananas
)
# install(TARGETS 242-valid-anagram 1-two-sum DESTINATION release)



