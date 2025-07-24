#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, path, used, result);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<int>&path, vector<bool> &used, vector<vector<int>>& result){
        if(path.size() == nums.size()){
            result.push_back(path); // 找到一个完整排列
            return ;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!used[i]){ //如果数字未被使用
                used[i] = true; // 标记为已使用
                path.push_back(nums[i]);
                backtrack(nums, path, used, result);
                path.pop_back(); // 撤销选择
                used[i] = false;
            }
        }
    }
};