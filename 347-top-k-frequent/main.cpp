#include <assert.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> nb_count;
    std::priority_queue<std::pair<int, int>> pq;
    // fill map
    for (auto num : nums) {
      auto it = nb_count.find(num);
      if (it != nb_count.end()) {
        it->second++;
      } else {
        nb_count.insert({num, 1});
      }
    }

    // takes k most frequent
    for (auto it = nb_count.begin(); it != nb_count.end(); ++it) {
      pq.push({it->second, it->first});
    }

    std::vector<int> answer;
    while (k-- && !pq.empty()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }
    return answer;
  }
};

int main() {
  std::vector<int> test1{1, 1, 1, 2, 2, 3};
  std::vector<int> test2{4, 1, -1, 2, -1, 2, 3};
  Solution s;
  std::cout << "--- Test 1 ---" << '\n';
  s.topKFrequent(test1, 2);
  std::cout << "--- Test 2 ---" << '\n';
  s.topKFrequent(test2, 2);
  return 0;
}
