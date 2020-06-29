/*
516. 最长回文子序列
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。
可以假设 s 的最大长度为 1000 。

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

来源：LeetCode
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence/
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
            
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < n - i; ++j)
            {
                if(s[j] == s[j + i])
                    dp[j][j + i] = 1 + dp[j + 1][i + j - 1] + 1;
                else
                    dp[j][j + i] = max(dp[j + 1][j + i], dp[j][i + j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};