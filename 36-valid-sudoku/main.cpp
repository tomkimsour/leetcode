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

// Input: board =
// [['5','3','.','.','7','.','.','.','.']
// ,['6','.','.','1','9','5','.','.','.']
// ,['.','9','8','.','.','.','.','6','.']
// ,['8','.','.','.','6','.','.','.','3']
// ,['4','.','.','8','.','3','.','.','1']
// ,['7','.','.','.','2','.','.','.','6']
// ,['.','6','.','.','.','.','2','8','.']
// ,['.','.','.','4','1','9','.','.','5']
// ,['.','.','.','.','8','.','.','7','9']]
// Output: true

// Input: board =
// [['8','3','.','.','7','.','.','.','.']
// ,['6','.','.','1','9','5','.','.','.']
// ,['.','9','8','.','.','.','.','6','.']
// ,['8','.','.','.','6','.','.','.','3']
// ,['4','.','.','8','.','3','.','.','1']
// ,['7','.','.','.','2','.','.','.','6']
// ,['.','6','.','.','.','.','2','8','.']
// ,['.','.','.','4','1','9','.','.','5']
// ,['.','.','.','.','8','.','.','7','9']]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's
// in the top left 3x3 sub-box, it is invalid.

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<std::unordered_map<char, int>> valid_lines(9);
    std::vector<std::unordered_map<char, int>> valid_col(9);
    std::vector<std::unordered_map<char, int>> valid_box(9);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c = board[i][j];
        if (c != '.') {
          // adds in line
          auto it = valid_lines[i].find(c);
          if (it != valid_lines[i].end()) {
            return false;
          } else {
            valid_lines[i].insert(std::make_pair(c, 1));
          }
          // adds in col
          it = valid_col[j].find(c);
          if (it != valid_col[j].end()) {
            return false;
          } else {
            valid_col[j].insert(std::make_pair(c, 1));
          }
          // get box id
          int box_id = i / 3 + j / 3;
          // adds in box
          it = valid_box[j].find(c);
          if (it != valid_box[j].end()) {
            return false;
          } else {
            valid_box[j].insert(std::make_pair(c, 1));
          }
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<char>> test1{
    { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
  };
  auto res = s.isValidSudoku(test1);
  // std::vector<int> test2{ -1, 1, 0, -3, 3 };
  // res = s.isValidSudoku(test2);
  // print_vec(res);
  return 0;
}
