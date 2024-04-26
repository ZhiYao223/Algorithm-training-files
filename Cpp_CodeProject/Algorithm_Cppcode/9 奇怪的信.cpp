#if 0
#include <iostream>
using namespace std;
int main()
{
	int number = 1;
	while (cin>>number)
	{
		int sum = 0; //初始化偶数和
		int ge = 0;  //初始化number的个位
		while(number > 0)   
		{
			ge = number % 10; //挨个取个位数
			number = number / 10; //更新number
			if (ge % 2 == 0) //判断第一位是否为偶数
			{
				sum += ge;  //累加
			}
		}
		cout << sum << endl << endl;
	}
}
#endif