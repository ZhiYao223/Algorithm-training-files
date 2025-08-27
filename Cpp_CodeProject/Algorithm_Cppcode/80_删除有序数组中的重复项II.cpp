#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int left = 0, right = 1;
        int count = 1;
        while(right < nums.size()){
            if (nums[left] == nums[right]){
                count++;
                if (count <= 2){
                    left++;
                    nums[left] = nums[right];
                }
                right++;
            }else{
                count = 1;
                left++;
                nums[left] = nums[right];
                right++;;
            }
            return left+1;
        }
    }
};

