#if 0
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str)) //接受一整行字符串
	{
		int flag = 1;
		float sum = 0;
		int count = 0;
		for (int i = 0; i < str.size();i++)
		{
			if (str[i] == 'A') { sum += 4;count++; }
			else if (str[i] == 'B') { sum += 3;count++; }
			else if (str[i] == 'C') { sum += 2;count++; }
			else if (str[i] == 'D') { sum += 1;count++; }
			else if (str[i] == 'F') { sum += 0;count++; }
			else if (str[i] == ' ') continue; 
			else
			{
				flag = 0;
				cout << "Unknown" << endl; 
				break; 
			}
		}
		if (flag) 
		{
			printf("%.2f\n", sum / count);
		}
	}
}
#endif 