#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 行检查
        for (int i = 0; i < 9; i++) {
            set<char> rowSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }
            }
        }

        // 列检查
        for (int j = 0; j < 9; j++) {
            set<char> colSet;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (colSet.count(board[i][j])) return false;
                    colSet.insert(board[i][j]);
                }
            }
        }

        // 宫格检查
        for (int blockRow = 0; blockRow < 9; blockRow += 3) {
            for (int blockCol = 0; blockCol < 9; blockCol += 3) {
                set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char num = board[blockRow + i][blockCol + j];
                        if (num != '.') {
                            if (boxSet.count(num)) return false;
                            boxSet.insert(num);
                        }
                    }
                }
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
    }
};