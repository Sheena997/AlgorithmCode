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
        
        for(int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = 1 + dp[i + 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};