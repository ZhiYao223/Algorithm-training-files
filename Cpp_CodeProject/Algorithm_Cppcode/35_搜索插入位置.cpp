#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                left = mid + 1;
                if (left >= nums.size()){
                    return nums.size();
                }
            }else if (nums[mid] > target){
                right = mid - 1;
                if (right < 0){
                    return 0;
                }
            }
        }
        return left; // If not found, return the position where it can be inserted
    }
};