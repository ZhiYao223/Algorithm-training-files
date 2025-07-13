#include <iostream>
#include <vector>
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

int main()
{
    return 0;
}