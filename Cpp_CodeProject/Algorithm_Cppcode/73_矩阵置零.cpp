#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int m = 0, n = 0;
    vector<vector<int>> point;
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    point.push_back({i,j});
                }
            }
        }
        col_row_zero(m, n, point,matrix);
    }
public:
    void col_row_zero(int m, int n, vector<vector<int>>& pos, vector<vector<int>>& matrix){
        int N = pos.size();
        for (int num = 0; num < N; num++){
            for (int j = 0; j < n; j++){
                matrix[pos[num][0]][j] = 0;
            }
            for (int i = 0; i < m; i++){
                matrix[i][pos[num][1]] = 0;
            }
        }
    }
};