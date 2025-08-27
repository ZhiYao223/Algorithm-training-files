#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0;
        vector<int> res;
        for (int i = 0; i < digits.size(); i++){
            sum = sum * 10 + digits[i];
        }
        sum ++;
        while (sum != 0){
            res.push_back(sum % 10);
            sum /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n-1; i >= 0; i--){
            if (digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};