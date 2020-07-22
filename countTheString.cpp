/*
题目描述
【编程题】将给定的数转换为字符串，原则如下：1对应 a，2对应b，…..26对应z，
例如12258可以转换为"abbeh", "aveh", "abyh", "lbeh" and "lyh"，个数为5，
编写一个函数，给出可以转换的不同字符串的个数。
*/
int countTheString(string str)
{
    vector<int> dp(str.size() + 1);
    dp[0] = 1;
    dp[1] = str[0] - '0' > 0 ? 1 : 0;
    for(int i = 2; i < str.size() + 1; ++i)
    {
        int first = str[i - 1] - '0';
        if(first != 0)
            dp[i] += dp[i - 1];
        if(str[i - 2] - '0' == 0)
            continue;
        
        dp[i] += ((str[i - 2] - '0') * 10 + (str[i - 1] - '0')) <= 26 ? dp[i - 2] : 0; 
    }
    
    return dp[str.size()];
}