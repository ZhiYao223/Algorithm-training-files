#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	int n, m;
	while (cin>>n)
	{
		for (int i = 1; i <= 2*n-1; i++)
		{
			if (i <= n) m = i;
			else m = 2 * n - i; 
			for(int j=1;j<=n - m;j++) 
			{
				cout << " ";
			}
			for (int k = 1;k <= m;k++)
			{
				cout << k;
			}
			for (int w = m - 1; w >= 1;w--)
			{
				cout << w; 
			}
			cout << endl;
		}
	}
	return 0;
}
#endif