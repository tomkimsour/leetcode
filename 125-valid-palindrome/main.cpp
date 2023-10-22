
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

class Solution {
public:
  bool isPalindrome(std::string s) {
    // remove unwanted character
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return std::isspace(c) || !std::isalnum(c); } ), s.end());
    // lower everything
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    // std::cout << s << std::endl;

    std::uint16_t size = s.size();
    auto start = s.begin();
    auto end = s.end();
    // skips end of string char
    end--;
    for (std::uint16_t i=0 ; i < size/2 ; i++){
      if (*start != *end){
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};

int main() {
  Solution s;
  std::string test1 = "A man, a plan, a canal: Panama";
  auto res = s.isPalindrome(test1);
  std::cout << "Test 1 : " << res << std::endl;
  std::string test2 = "0P";
  res = s.isPalindrome(test2);
  std::cout << "Test 2 : " << res << std::endl;
  return 0;
}
