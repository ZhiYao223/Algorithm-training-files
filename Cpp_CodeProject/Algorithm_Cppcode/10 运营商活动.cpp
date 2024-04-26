#if 0
#include <iostream>
using namespace std;
int main()
{
	int M = 1, K = 1;
	while (1)
	{
	d	cin >> M >> K;     //输入M,N的值
		if (M == 0 && K == 0) return 0;
		int sumday = M;    //M元本金至少可以用M天
		while (M / K > 0)   
		{
			int a = M / K; //计算本金M可获赠的奖励
			int b = M % K; //兑换奖励后的余额
			sumday = sumday + a;
			M = a + b;	   //更新M的值
		}
		cout << sumday << endl; 
	}
	return 0;
}
#endif