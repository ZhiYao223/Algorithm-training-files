#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char str;
    int n = 1;
    while (cin>>str>>n)
    {
        if (str == '@') return 0;
        if (n <= 0 || n >= 41)   return 0; //����n�Ĵ�С
        for (int i = 1; i <= n; i++) //����ѭ��
        {
            if (i == n)  //���һ��ȫ���ַ����޿ո�
            {
                for (int k = 1;k <= 2 * n - 1;k++)
                    cout << str;    //���һ�������ַ�
                cout << endl << endl; //��Ҫ��ÿ���������һ������
                break;  
            }
            for (int j = 1; j <= 2 * n - 1; j++)  //��i�У�ÿ�����2n-1���ַ�
            {
                if (j == n - (i - 1) || j == n+(i-1))//����ַ���λ�á�
                {
                    cout << str;  
                    if (j == n + (i - 1)) //��i�У���ĩ�����ַ����������С�
                    {
                        cout << endl; 
                        break;  //����ѭ�������л�����һ��
                    }
                }
                else cout << " ";  //�����ַ��ĵط��⣬���ÿո�
            }
        }
    }
}
#endif