#if 0
#include <iostream>
using namespace std;
int main()
{
	int M = 1, K = 1;
	while (1)
	{
	d	cin >> M >> K;     //����M,N��ֵ
		if (M == 0 && K == 0) return 0;
		int sumday = M;    //MԪ�������ٿ�����M��
		while (M / K > 0)   
		{
			int a = M / K; //���㱾��M�ɻ����Ľ���
			int b = M % K; //�һ�����������
			sumday = sumday + a;
			M = a + b;	   //����M��ֵ
		}
		cout << sumday << endl; 
	}
	return 0;
}
#endif