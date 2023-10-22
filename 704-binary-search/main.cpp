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
  int search(const std::vector<int>& nums, int target) {
    int l = 0, r = nums.size() -1;
    while (l<=r) {
      int middle = l + ((r-l)/2);
      if (nums[middle] == target){
        return middle;
      } else if (nums[middle] < target){
        l = middle +1;
      } else {
        r = middle -1;
      }
    }
    return -1;
  }
};

int main() {
  std::vector<int> test1{ -1, 0, 3, 5, 9, 12 };
  std::vector<int> test2{ -1, 0, 3, 5, 9, 12 };
  Solution s;
  std::cout << "--- Test 1 ---" << '\n';
  std::cout << s.search(test1, 9) << '\n';
  std::cout << "--- Test 2 ---" << '\n';
  std::cout << s.search(test2, 2) << '\n';
  return 0;
}
