#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*如果numRows == 1， 或numRows>= s.length(),直接返回原字符串*/
        if (numRows == 1 || numRows >= s.length()){
            return s;
        }
        int n = s.length();
        int flag = 1; // 1表示向下，0表示向上
        int currentrow = 0;
        vector<string> rowstr(min(numRows, int(n)));
        for(auto c : s){
            rowstr[currentrow] += c;
            currentrow += flag;   
            if (currentrow == 0 || currentrow == (numRows-1)){
                flag = -flag;
            }
        }

        string result;
        for(auto c : rowstr){
            result += c;
        }
        return result;
    }
};

class Solution {
public:
    int reverse(int x) {
    int res = 0;
    while(x != 0){
        // 取末尾数字
        int digit = x % 10;
        // 判断是否溢出
        if (res > (pow(2,31)/10) || (res == pow(2,31)/10 && digit > 7)){
            return 0;
        }
        if (res < -(pow(2,31)/10) || (res == pow(2,31)/10 || digit < -8)){
            return 0;
        }
        res = res* 10 + digit;
        x = x/10;
    }
    return res;
    }
};

// 1. 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vermap;
        for (int i = 0; i < nums.size(); i++){
            int num = target - nums[i];
            // 当前值的补数在哈希表中
            if (vermap.find(num) != vermap.end()){
                return {vermap[num], i};
            }
            vermap[nums[i]] = i;
        }
        return {};
    }
};

// 4. 寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(auto num : nums1){

        }
    }
};j

