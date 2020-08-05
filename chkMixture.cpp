/*
链接：https://www.nowcoder.com/questionTerminal/138f0ae35154438caf3d0072bd6ffef5
来源：牛客网

[编程题]字符串交错组成

对于三个字符串A，B，C。我们称C由A和B交错组成当且仅当C包含且仅包含A，B中所有字符，且对应的顺序不改变。
请编写一个高效算法，判断C串是否由A和B交错组成。

给定三个字符串A,B和C，及他们的长度。请返回一个bool值，代表C是否由A和B交错组成。保证三个串的长度均小于等于100。

测试样例：
"ABC",3,"12C",3,"A12BCC",6
返回：true
*/
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        //初始化
        dp[0][0] = true;
        for(int i = 1; i < n + 1; ++i)
            dp[i][0] = (dp[i - 1][0] && A[i - 1] == C[i - 1]);
        for(int j = 1; j < m + 1; ++j)
            dp[0][j] = (dp[0][j - 1] && B[j - 1] == C[j - 1]);
        
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < m + 1; ++j)
            {
                dp[i][j] = ((dp[i - 1][j] && A[i - 1] == C[i + j - 1]) || (dp[i][j - 1] && B[j - 1] == C[i + j - 1]));
            }
        }
        
        return dp[n][m];
    }
};

