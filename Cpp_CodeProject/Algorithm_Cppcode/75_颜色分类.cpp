#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                swap(nums[ptr], nums[i]);
                ptr++;
            }
        }
        ptr = nums.size()-1;
        for (int i = nums.size()-1; i >= 0; i--){
            if (nums[i] == 2){
                swap(nums[ptr], nums[i]);
                ptr--;
            }
        }
    }
};