/*
链接：https://www.nowcoder.com/questionTerminal/28acd1134e344040ad105b3786a79e7a
来源：牛客网

[编程题]字符串通配

对于字符串A，其中绝对不含有字符’.’和’*’。再给定字符串B，其中可以含有’.’或’*’，’*’字符不能是
B的首字符，并且任意两个’*’字符不相邻。exp中的’.’代表任何一个字符，B中的’*’表示’*’的前一个字
符可以有0个或者多个。请写一个函数，判断A是否能被B匹配。

给定两个字符串A和B,同时给定两个串的长度lena和lenb，请返回一个bool值代表能否匹配。保证两串的长度均小于等于300。

测试样例：
"abcd",4,".*",2
返回：true
*/
class WildMatch {
public:
    bool chkWildMatch(string A, int lena, string B, int lenb) {
        // write code here
        vector<vector<bool>> dp(lena + 1, vector<bool>(lenb + 1, false));
        
        dp[0][0] = true;
        
        for(int i = 1; i < lena + 1; ++i)
        {
            for(int j = 1; j < lenb + 1; ++j)
            {
                if(B[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(B[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = (dp[i - 1][j - 1] && A[i - 1] == B[j - 1]);
            }
        }
        
        return dp[lena][lenb];
    }
};