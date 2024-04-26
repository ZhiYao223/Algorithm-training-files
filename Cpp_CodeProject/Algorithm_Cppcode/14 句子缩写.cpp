#if 0
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;   
    cin.ignore();  //getchar(); //消除缓冲区
    while (n--)
    {
        string input;
        getline(cin, input);  //输入词组
        string output;    
        istringstream iss(input); //分割词组
        string word;
        while (iss >> word)   
        {
            transform(word.begin(), word.end(), word.begin(), ::toupper);  //将所有字符全部转为大写
            output += word[0]; //将每个单词的首字母拼起来
        }
        cout << output << endl;  
    }
    return 0;
}
#endif