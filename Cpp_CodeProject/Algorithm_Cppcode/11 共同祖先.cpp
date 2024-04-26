#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, a, b;
	vector<int>nums = vector<int>(30,0);
	while (cin>>n)
	{
		while (n--)
		{
			cin >> a >> b;
			nums[a] = b; 
		}
		int Mlen = 0, Ylen = 0;
		int ming = nums[1];
		while (ming!=0)
		{
			ming = nums[ming];
			Mlen++; 
		}
		int yu = nums[2];
		while (yu !=0)
		{
			yu = nums[yu];
			Ylen++;
		}
		if (Mlen > Ylen)
			cout << "You are my elder" << endl;
		else if (Mlen == Ylen)
			cout << "You are my brother" << endl;
		else cout << "You are my younger" << endl; 
	}
	return 0;
}
#endif