// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.
//
//
//
// Example 1:
//
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:
//
// Input: strs = [""]
// Output: [[""]]
// Example 3:
//
// Input: strs = ["a"]
// Output: [["a"]]

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

#include "leetcode_utils.hpp"

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> answer;
    std::unordered_map<std::string, std::vector<std::string>> map;
    /*
     * "aet" => "eat" , "tea" , "ate"
     * "ant" => "tan", "nat"
     * "abt" => "bat"
     * */
    for (auto word : strs) {
      std::string ordered_char = word;
      std::sort(ordered_char.begin(), ordered_char.end());
      map[ordered_char].push_back(word);
    }
    for (auto it : map) {
      answer.push_back(it.second);
    }

    for (auto it = answer.begin(); it != answer.end(); ++it) {
      print_vec<std::string>(*it);
    }
    return answer;
  }
};

int main() {
  Solution s;
  std::vector<std::string> test1{ "eat", "tea", "tan", "ate", "nat", "bat" };
  s.groupAnagrams(test1);
  return 0;
}
