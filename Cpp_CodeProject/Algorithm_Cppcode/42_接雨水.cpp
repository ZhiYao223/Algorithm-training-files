#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        //求层数，即最大高度
        int maxHeight = 0;
        for (int i = 0; i < height.size(); i++){
            maxHeight = (maxHeight <= height[i]) ? height[i] : maxHeight; 
        }
        int result = 0; 
        // 第i层，从下往上
        for (int i = 1; i <= maxHeight; i++){
            int temp = 0;  // 记录同一层的蓝色块 
            bool isStart = false; // 标记第一面高度大于i的墙
            // 从左到右遍历
            for(int j = 0; j < height.size(); j++){
                if (isStart && height[j] < i){
                    temp++;
                }
                if (height[j] >= i){
                    isStart = true;
                    result += temp;
                    temp = 0;
                }
            }
        }
        return result;
    }
};