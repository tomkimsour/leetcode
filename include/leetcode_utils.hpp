#ifndef LEETCODE_UTILS
#define LEETCODE_UTILS

#include <iostream>
#include <vector>

template <class T> void print_vec(std::vector<T> input) {
  for (auto it = input.begin(); it != input.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

#endif // LEETCODE_UTILSLEETCODE_UTILS
