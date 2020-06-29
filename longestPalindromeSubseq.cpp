/*
516. �����������
����һ���ַ��� s ���ҵ�������Ļ��������У������ظ����еĳ��ȡ�
���Լ��� s ����󳤶�Ϊ 1000 ��

ʾ�� 1:
����:

"bbbab"
���:

4
һ�����ܵ������������Ϊ "bbbb"��

ʾ�� 2:
����:

"cbbd"
���:

2
һ�����ܵ������������Ϊ "bb"��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/longest-palindromic-subsequence/
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