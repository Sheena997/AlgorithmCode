/*
链接：https://www.nowcoder.com/questionTerminal/3d08b635346d4610b01c6256bc07c394
来源：牛客网

[编程题]幸运N串-研发


小A很喜欢字母N，他认为连续的N串是他的幸运串。有一天小A看到了一个全部由大写字母组成的字符串，
他被允许改变最多2个大写字母（也允许不改变或者只改变1个大写字母），使得字符串中所包含的最长
的连续的N串的长度最长。你能帮助他吗？


输入描述:
输入的第一行是一个正整数T（0 < T <= 20），表示有T组测试数据。对于每一个测试数据包含一行大写字
符串S（0 < |S| <= 50000，|S|表示字符串长度）。

数据范围：

20%的数据中，字符串长度不超过100；

70%的数据中，字符串长度不超过1000；

100%的数据中，字符串长度不超过50000。


输出描述:
对于每一组测试样例，输出一个整数，表示操作后包含的最长的连续N串的长度。
示例1
输入
3
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN
输出
4
10
18
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0; 
    cin >> n;
    int dp[50002][3];
    while(n--)
    {
        string str;
        cin >> str;
        if(str.empty())
            cout << 0 << endl;
        
        dp[0][0] = ((str[0] == 'N') ? 1 : 0);
        dp[0][1] = dp[0][2] = 1;
        int resMax = 1;
        for(int i = 1; i < str.size(); ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(str[i] == 'N')
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                    ++j;
                    while(j < 3)
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        ++j;
                    }
                }
            }
            
            resMax = max(resMax, max(max(dp[i][0], dp[i][1]), dp[i][2]));
        }
        
        cout << resMax << endl;
    }
    
    return 0;
}