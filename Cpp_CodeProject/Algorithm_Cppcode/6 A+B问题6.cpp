#if 0
#include <iostream>
using namespace std;
int main()
{
	int n, m, a;
	while (cin>>n && n > 0)
	{
		while (n--)
		{
			cin >> m; 
			int sum = 0;
			while (m--)
			{
				cin >> a;
				sum += a; 
			}
			cout << sum << endl; 
			if (n != 0) cout << endl; 
		}
	}
}
#endif