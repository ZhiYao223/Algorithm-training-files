#include <iostream>
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 0b15ce38f0ad5a9d8cdbd6bd2502d8e874b99186
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentSum = nums[0];
        int maxSum = nums[0];
        for(int i = 0; i < n; i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};