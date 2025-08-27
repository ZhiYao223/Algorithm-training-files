#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = nums[0];
        int sumMax = nums[0];
        for (int i = 0; i < nums.size(); i++){
            currentMax = max(currentMax+nums[i], nums[i]);
            sumMax = max(currentMax, sumMax);
        }      
        return currentMax;
    }
};