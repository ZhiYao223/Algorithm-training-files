#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	int n;
	cin >> n;
	cin.ignore();//ºöÂÔ»»ĞĞ·û
	while (n--)
	{
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);
		if (str1.length() % 2 != 0) return 0;
		else if (str1.length() % 2 == 0)
		{
			size_t midIndex = str1.length() / 2;
			string newstr1 = str1.substr(0, midIndex) + str2 + str1.substr(midIndex, str1.length() - 1);
			cout << newstr1 << endl;  
		}
	}
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;

		str1.insert(str1.size() / 2, str2);
		cout << str1 << endl;
	}

	return 0;
}
#endif 