#if 0
#include <iostream>
using namespace std;

int main()
{
	int n, a = 0, sum = 0;
	while (cin>>n && n != 0)
	{
		while (n--) 
		{
			cin >> a;
			sum += a; 
		}
		cout << sum << endl; 
		sum = 0;
	}
	return 0;
}
#endif
