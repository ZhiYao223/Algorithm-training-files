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
    cin.ignore();  //getchar(); //����������
    while (n--)
    {
        string input;
        getline(cin, input);  //�������
        string output;    
        istringstream iss(input); //�ָ����
        string word;
        while (iss >> word)   
        {
            transform(word.begin(), word.end(), word.begin(), ::toupper);  //�������ַ�ȫ��תΪ��д
            output += word[0]; //��ÿ�����ʵ�����ĸƴ����
        }
        cout << output << endl;  
    }
    return 0;
}
#endif