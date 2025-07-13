#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closeSum = 0;
        int mindiff = INT_MAX;
        for(int i = 0; i < n; i++){
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
                if (diff < mindiff){
                    mindiff = diff;
                    closeSum = sum;
                }
                while(left < right && sum < target) left++;
                while(left < right && sum > target) right--;
                if(sum == target){
                    return sum;
                }
            }
        }
        return closeSum;
    }
};

int main()
{

}