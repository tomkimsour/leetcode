// hashtable ()
// hashset (unique)
// linked list
// graph
// oriented graph -> (prims, kruskal)
// tree -> (dfs)
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    // build hashtable
    // this should be an array of 26 values as there are 26 letters
    int arr[26];
    for (int i = 0; i < s.length(); i++) {
      arr[s[i] - 'a']++;
      arr[t[i] - 'a']--;
    }
    for (auto letter : arr) {
      if (letter != 0) {
        return false;
      }
    }
    return true;
  }

  bool isAnagram1(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    // build hashtable
    std::unordered_map<char, int> s_hash;
    for (char c : s) {
      auto it = s_hash.find(c);
      if (it != s_hash.end()) {
        it->second++;
      } else {
        s_hash.insert(std::make_pair(c, 1));
      }
    }
    std::unordered_map<char, int> t_hash;
    for (char c : t) {
      auto it = t_hash.find(c);
      if (it != t_hash.end()) {
        it->second++;
      } else {
        t_hash.insert(std::make_pair(c, 1));
      }
    }

    // look if both hash tables are equal
    for (auto its : s_hash) {
      auto itt = t_hash.find(its.first);
      // if the char can't be found in t_hash
      if (itt == t_hash.end()) {
        return false;
      }
      if (its.second != itt->second) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  assert(s.isAnagram("anagram", "nagaram") == true &&
         "anagram and nagaram should be false");
  assert(s.isAnagram("rat", "car") == false && "rat and car should be false");
  return 0;
}
