#if 0
#include <iostream>
using namespace std;
int main()
{
	int number = 1;
	while (cin>>number)
	{
		int sum = 0; //��ʼ��ż����
		int ge = 0;  //��ʼ��number�ĸ�λ
		while(number > 0)   
		{
			ge = number % 10; //����ȡ��λ��
			number = number / 10; //����number
			if (ge % 2 == 0) //�жϵ�һλ�Ƿ�Ϊż��
			{
				sum += ge;  //�ۼ�
			}
		}
		cout << sum << endl << endl;
	}
}
#endif