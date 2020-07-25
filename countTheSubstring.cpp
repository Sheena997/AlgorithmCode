/*
链接：https://www.nowcoder.com/questionTerminal/6f0d16fc06274f44af8913d182668037
来源：牛客网

[编程题]病毒检测


小明最近在做病毒自动检测，他发现，在某些library 的代码段的二进制表示中，如果包含子串并且恰好有k个1，
就有可能有潜在的病毒。library的二进制表示可能很大，并且子串可能很多，人工分析不可能，于是他想写个程
序来先算算到底有多少个子串满足条件。如果子串内容相同，但是开始或者结束位置不一样，则被认为是不同的子串。
注：子串一定是连续的。例如"010"有6个子串，分别是 "0, "1", "0", "01", "10", "010"


输入描述:
第一行是一个整数k，表示子串中有k个1就有可能是病毒。其中 0 <= k <= 1 000 000

第二行是一个字符串，就是library的代码部分的二进制表示。字符串长度 <= 1 000 000。并且字符串中只包含"0"或"1".


输出描述:
输出一个整数，所有满足只包含k个1的子串的个数。
示例1
输入
1
1010
输出
6
说明
满足条件的子串有："1", "1", "10", "01", "10", "010".
示例2
输入
2
01010
输出
4
说明
满足条件的子串有： "101", "0101", "1010", "01010".
示例3
输入
100
01010
输出
0
*/
#include <iostream>
#include <string>

using namespace std;

long countTheSubstring(string str, long k)
{
    long res = 0;
    for(long i = 0; i < str.size(); ++i)
    {
        long right = i, count = 0;
        while(right < str.size() && count < k)
        {
            if(str[right] == '1' && ++count == k)
            {
                ++right;
                ++res;
                break;
            }
            ++right;
        }
        
        while(right < str.size() && str[right] != '1')
        {
            ++right;
            ++res;
        }
    }
    
    return res;
}
int main()
{
    long k = 0;
    cin >> k;
    string str = "";
    cin >> str;
    long res  = 0;
    for(auto& e : str)
        if(e == '1')
            ++res;
    
    if(res < k)
        cout << 0 << endl;
    else
        cout << countTheSubstring(str, k) << endl;
    
    return 0;
}