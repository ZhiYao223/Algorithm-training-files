#include <iostream>
#if 0
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore(); //�������з�
	while (n--)
	{
		string str = {};
		getline(cin, str); //����һ���ַ���
		char temp = {};   //��ʼ���м����
		if (str.length() > 50 && str.length()/2 != 0) return 0;
		for (int i = 0; i <= str.length()-2;i+=2)
		{
			temp = str[i];
			str[i] = str[i+1];
			str[i + 1] = temp;
		}
		cout << str << endl; 
	}
	return 0;
}
#endif
