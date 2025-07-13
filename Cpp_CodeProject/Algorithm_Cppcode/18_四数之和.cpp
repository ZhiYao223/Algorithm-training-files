#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        //排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; 
        // 从nums[i]，开始，用双指针
        for (int i = 0; i < n-3; i++){
            if (nums[i] > target && nums[i] >= 0) break;
            if (i > 0 && nums[i] == nums[i-1]) break;
            for(int j = i+1; j < n-2; j++){
                if (nums[i] + nums[j] > target && nums[j] >= 0){
                    break;
                }
                if(j > i+1 && nums[j] == nums[j-1]) break;
                
            }
        }
    }
};

int main()
{
    return 0;
}