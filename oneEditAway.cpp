/*
������ 01.05. һ�α༭
�ַ��������ֱ༭����:����һ���ַ���ɾ��һ���ַ������滻
һ���ַ��� ���������ַ�������дһ�������ж������Ƿ�ֻ��
Ҫһ��(�������)�༭�� 

ʾ�� 1:
����: 
first = "pale"
second = "ple"
���: True

ʾ�� 2:
����: 
first = "pales"
second = "pal"
���: False

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/one-away-lcci/
*/
class Solution {
public:
    bool oneEditAway(string first, string second) {
        vector<vector<int>> dp(first.size() + 1, vector<int>(second.size() + 1));
        for(int i = 1; i < first.size() + 1; ++i)
            dp[i][0] = i;
        for(int j = 1; j < second.size() + 1; ++j)
            dp[0][j] = j;
        
        for(int i = 1; i < first.size() + 1; ++i)
        {
            for(int j = 1; j < second.size() + 1; ++j)
            {
                if(first[i - 1] == second[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        
        if(dp[first.size()][second.size()] > 1)
            return false;
        
        return true;
    }
};