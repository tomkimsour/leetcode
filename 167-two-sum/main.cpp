// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

 

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
// Example 2:

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
// Example 3:

// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

// Constraints:

// 2 <= numbers.length <= 3 * 104
// -1000 <= numbers[i] <= 1000
// numbers is sorted in non-decreasing order.
// -1000 <= target <= 1000
// The tests are generated such that there is exactly one solution.


#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
  const std::vector<int> twoSum(const std::vector<int> &nums, int target) {
  std::vector<int> out{0, 0};
      int vector_size = nums.size();
      int i = 0,j = 0;
      int rest=0;
      while(out[0] != out[1]){
        rest = target - nums[vector_size - j]; 
        if (rest < 0) {
          j--; 
          continue;
        }else {
          if (rest - nums[i] == 0){
            out[0] = i;
            out[1] = j;
            std::cout << "Out : ["<< out[0] << "," << out[1] <<"]"  << std::endl;
            return out;
          } else {
            i++;
          }
        }
      }
      return out; 
}
};

int main() {
  Solution solution;
  std::vector<int> sample1{2, 7, 11, 15};
  std::vector<int> res1{0, 1};
  std::vector<int> sample2{2, 3, 4};
  std::vector<int> res2{0, 2};
  std::vector<int> sample3{-1, 0};
  std::vector<int> res3{0, 1};
  assert(solution.twoSum(sample1, 9) == res1 && "Sample 1 output is wrong");
  assert(solution.twoSum(sample2, 6) == res2 && "Sample 2 output is wrong");
  assert(solution.twoSum(sample3, -1) == res3 && "Sample 3 output is wrong");
  return 0;
}
