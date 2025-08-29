#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        vector<int> result = {-1, -1};
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target){
                right = mid -1;
            }
            if (nums[mid] < target){
                left = mid + 1;
            }
        }
        if (left < nums.size() && nums[left] == target){
            result[0] = left;
        }
        left = 0, right = nums.size() -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if (nums[mid] <= target){
                left = mid + 1;
            }
            if (nums[mid] > target){
                right = mid - 1;
            }
        }
        if (right >= 0 && nums[right] == target){
            result[1] = right;
        }
        return result;
    }
};