#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 1; //初始值
	vector<int> height;
	while (n >= 1 && n <= 50)
	{
		cin >> n;
		int sum = 0;  //积木总数
		if (n == 0)  return 0;  //输入0时退出
		height.resize(n);  //设定容器大小。
		for (int i = 0; i < n; i++)
		{
			cin >> height[i]; //将输入值存入容器
			sum += height[i]; //累加其值
		}
		if(sum % n == 0)  //判断整除条件
		{ 
			int mid_height = sum / n;  //相同高度
			int gap = 0;  //高度差累加
			for(int j = 0; j < n;j++)  
			{
				gap += abs(mid_height - height[j]);
			}
			int out = gap / 2;//移动次数就是高度差之和的一半
			cout << out << endl << endl;
		}
	}
	return 0;
}
#endif