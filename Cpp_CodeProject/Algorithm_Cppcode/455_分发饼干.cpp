#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 用来遍历饼干
        int result;
        for (int i = g.size(); i >= 0; i--){
            if (index >= 0 && s[index] >= s[i]){
                index--;
                result++;
            }
        }
        return result;
    }
};