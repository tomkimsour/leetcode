#include <assert.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Given an array of integers nums which is sorted in ascending order,
// and an integer target, write a function to search target in nums.
// If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int l = 0, r = rows * cols -1;
    while (l <= r) {
      int middle = l + ((r - l) /2);
      int mid_value = matrix[middle / cols][middle % cols];
      if (mid_value== target){
        return true;
      } else if (mid_value < target){
        l = middle + 1;
      } else {
        r = middle - 1;
      }
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> test1{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  std::vector<std::vector<int>> test2{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  Solution s;
  std::cout << "--- Test 1 ---" << '\n';
  std::cout << s.searchMatrix(test1, 3) << '\n';
  std::cout << "--- Test 2 ---" << '\n';
  std::cout << s.searchMatrix(test2, 13) << '\n';
  return 0;
}
