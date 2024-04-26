#if 1
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int n = 1;
	while (cin >> n && 1 <= n && n <= 100)
	{
		stack<int> s;
		queue<int> seq;
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> num;
			seq.push(num);
		}
		for (int i = 1; i <= n;i++)
		{
			s.push(i);
			while (!s.empty() && s.top() == seq.front())
			{
				s.pop();
				seq.pop();
			}
		}
		if(!s.empty())
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
}
#endif
