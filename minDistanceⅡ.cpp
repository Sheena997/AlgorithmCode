/*
链接：https://www.nowcoder.com/questionTerminal/dfa502cf6a914fb5b98c59c56619e96c
来源：牛客网

[编程题]最小编辑代价
热度指数：1295时间限制：C/C++ 2秒，其他语言4秒空间限制：C/C++ 256M，其他语言512M
算法知识视频讲解
给定两个字符串str1和str2，再给定三个整数ic，dc和rc，分别代表插入、删除和替换一个字符的代价，请输出将str1编辑成str2的最小代价。

输入描述:
输出三行，第一行和第二行均为一行字符串，分别表示两个字符串str1，str2。
\left( 1\leq length(str1),length(str2) \leq 5000 \right)(1≤length(str1),length(str2)≤5000)。
第三行为三个正整数，代表ic，dc和rc。（1<=ic<=10000、1<=dc<=10000、1<=rc<=10000）


输出描述:
输出一个整数，表示编辑的最小代价。
示例1
输入
abc
adc
5 3 2
输出
2
示例2
输入
abc
adc
5 3 100
输出
8
示例3
输入
abc
abc
5 3 2
输出
0

备注:
时间复杂度O(n*m)O(n?m)，空间复杂度O(n)O(n)。(n,m代表两个字符串长度)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string str1, string str2, int ic, int dc, int rc)
{
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    
    for(int i = 0; i < str1.size() + 1; ++i)
        dp[i][0] = i * dc;
    for(int j = 0; j < str2.size() + 1; ++j)
        dp[0][j] = j * ic;
    
    for(int i = 1; i < str1.size() + 1; ++i)
    {
        for(int j = 1; j < str2.size() + 1; ++j)
        {
            dp[i][j] = min(dp[i - 1][j] + dc, dp[i][j - 1] + ic);
            dp[i][j] = min(dp[i][j], (str1[i - 1] == str2[j - 1]) ? (dp[i - 1][j - 1]) : (dp[i - 1][j - 1] + rc));
        }
    }
    
    return dp[str1.size()][str2.size()];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int ic = 0, dc = 0, rc = 0;
    cin >> ic >> dc >> rc;
    
    cout << minDistance(str1, str2, ic, dc, rc) << endl;
    
    return 0;
}