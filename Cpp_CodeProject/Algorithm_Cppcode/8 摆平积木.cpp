#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 1; //��ʼֵ
	vector<int> height;
	while (n >= 1 && n <= 50)
	{
		cin >> n;
		int sum = 0;  //��ľ����
		if (n == 0)  return 0;  //����0ʱ�˳�
		height.resize(n);  //�趨������С��
		for (int i = 0; i < n; i++)
		{
			cin >> height[i]; //������ֵ��������
			sum += height[i]; //�ۼ���ֵ
		}
		if(sum % n == 0)  //�ж���������
		{ 
			int mid_height = sum / n;  //��ͬ�߶�
			int gap = 0;  //�߶Ȳ��ۼ�
			for(int j = 0; j < n;j++)  
			{
				gap += abs(mid_height - height[j]);
			}
			int out = gap / 2;//�ƶ��������Ǹ߶Ȳ�֮�͵�һ��
			cout << out << endl << endl;
		}
	}
	return 0;
}
#endif