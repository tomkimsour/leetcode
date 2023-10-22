#include <assert.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Koko loves to eat bananas. There are n piles of bananas,
// the ith pile has piles[i] bananas. The guards have gone
// and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k.
// Each hour, she chooses some pile of bananas and eats k
// bananas from that pile. If the pile has less than k bananas,
// she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating
// all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

class Solution {
public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    std::sort(piles.begin(), piles.end(), std::greater<int>());
    int l = 0, r = piles[0];
    int k = 0;
    while (l <= r) {
      k = l + ((r - l) / 2);
      // test if solves with k
      if (pilesSolver(piles, h, k) <= h) {
        r = k - 1;
      } else {
        l = k + 1;
      }
    }
    return l;
  }

  // returns the number of iteration to solve the pile
  int pilesSolver(std::vector<int>& piles, int h, int k) {
    int nb_max_iter = h;
    for (auto& val : piles) {
      if (val <= k)
        nb_max_iter--;
      else {
        nb_max_iter = nb_max_iter - (val / k);
        if (val % k != 0)
          nb_max_iter--;
      }
      if (nb_max_iter < 0)
        return h + 1;
    }
    return h - nb_max_iter;
  }
};

int main() {
  std::vector<int> test1{ 3, 6, 7, 11 };
  std::vector<int> test2{ 30, 11, 23, 4, 20 };
  std::vector<int> test3{ 30, 11, 23, 4, 20 };
  Solution s;
  std::cout << "--- Test 1 ---" << '\n';
  std::cout << s.minEatingSpeed(test1, 8) << '\n';
  std::cout << "--- Test 2 ---" << '\n';
  std::cout << s.minEatingSpeed(test2, 5) << '\n';
  std::cout << "--- Test 3 ---" << '\n';
  std::cout << s.minEatingSpeed(test3, 6) << '\n';
  return 0;
}
