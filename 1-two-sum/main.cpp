#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <vector>
class Solution {
public:
  const std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hash_map;
    std::vector<int> out{0, 0};
    for (int i = 0; i < nums.size(); i++) {
      if (auto it = hash_map.find(nums[i]); it != hash_map.end()) {
        out[0] = it->second;
        out[1] = i;
        return out;
      } else {
        // insert target - val with value index
        hash_map.insert({target - nums[i], i});
      }
    }
    return out;
  }
};

int main() {
  Solution solution;
  std::vector<int> sample1{2, 7, 11, 15};
  std::vector<int> res1{0, 1};
  std::vector<int> sample2{3, 2, 4};
  std::vector<int> res2{1, 2};
  std::vector<int> sample3{3, 3};
  std::vector<int> res3{0, 1};
  assert(solution.twoSum(sample1, 9) == res1 && "Sample 1 output is wrong");
  assert(solution.twoSum(sample2, 6) == res2 && "Sample 2 output is wrong");
  assert(solution.twoSum(sample3, 6) == res3 && "Sample 3 output is wrong");
  return 0;
}
