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
    int size = nums.size();
    std::vector<int> res(size);

    res[0] = 1;
    for (int i = 1; i < size; i++) {
      res[i] = nums[i-1] * res[i-1];
    }

    int factor = 1;
    for (int i = size-1; i >= 0; i--) {
      res[i] = res[i] * factor;
      factor = factor * nums[i];
    }
    return res;
    // int n = nums.size();
    // std::vector<int> output(n);
    // output[0] = 1;
    // for(int i=1; i<n; i++){
    //     output[i] = output[i-1] * nums[i-1];
    // }
    // int right = 1;
    // for(int i=n-1; i>=0; i--){
    //     output[i] *= right;
    //     right *= nums[i];
    // }
    // return output;
  }
};

int main() {
  Solution s;
  std::vector<int> test1{ 1, 2, 3, 4 };
  print_vec<int>(test1);
  auto res = s.productExceptSelf(test1);
  print_vec(res);
  std::vector<int> test2{ -1, 1, 0, -3, 3 };
  print_vec<int>(test2);
  res = s.productExceptSelf(test2);
  print_vec(res);
  return 0;
}
