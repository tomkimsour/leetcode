#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
  public:
    bool isValid(std::string s) {
    std::stack<char> stack;
        std::unordered_map<char, char> bracket_map;
        bracket_map.insert(std::make_pair('(', ')'));
        bracket_map.insert(std::make_pair('{', '}'));
        bracket_map.insert(std::make_pair('[', ']'));
        for (int i = 0 ; i < s.size() ; i++) {
            if (stack.empty()){
                stack.push(s[i]);
            } else {
                auto it = bracket_map.find(stack.top());
                if (it == bracket_map.end()){
                    stack.push(s[i]);
                } else {
                    std::cout << it->first << std::endl;
                    if (it->second == s[i]){
                        stack.pop();
                    } else {
                        stack.push(s[i]);
                    }
                }
            }
        }
        if (stack.size() != 0) return false;
        return true;}
};

int main() {
  Solution s;
  std::string test1 = "()";
  auto res = s.isValid(test1);
  std::cout << "Test 1 : " << res << std::endl;
  return 0;
}
