// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements
// of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

#include "leetcode_utils.hpp"

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res;
    int factor = 1;
    print_vec(nums);
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      factor = factor * (*it);
      std::cout << factor << std::endl;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        res.push_back(factor);
      } else {
        res.push_back(factor / nums[i]);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> test1{ 1, 2, 3, 4 };
  auto res = s.productExceptSelf(test1);
  print_vec(res);
  std::vector<int> test2{ -1, 1, 0, -3, 3 };
  res = s.productExceptSelf(test2);
  print_vec(res);
  return 0;
}
