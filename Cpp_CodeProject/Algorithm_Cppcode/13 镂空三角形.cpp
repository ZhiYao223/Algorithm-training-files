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
        if (n <= 0 || n >= 41)   return 0; //限制n的大小
        for (int i = 1; i <= n; i++) //行数循环
        {
            if (i == n)  //最后一行全是字符，无空格
            {
                for (int k = 1;k <= 2 * n - 1;k++)
                    cout << str;    //最后一行铺满字符
                cout << endl << endl; //按要求，每条结果后多出一个空行
                break;  
            }
            for (int j = 1; j <= 2 * n - 1; j++)  //第i行，每行最多2n-1个字符
            {
                if (j == n - (i - 1) || j == n+(i-1))//添加字符的位置。
                {
                    cout << str;  
                    if (j == n + (i - 1)) //第i行，行末铺上字符后立即换行。
                    {
                        cout << endl; 
                        break;  //跳出循环，从切换到下一行
                    }
                }
                else cout << " ";  //除有字符的地方外，放置空格
            }
        }
    }
}
#endif