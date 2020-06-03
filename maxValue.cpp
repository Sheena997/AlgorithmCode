/*
������47. ���������ֵ
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
����ֵ���� 0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ��
���һ��������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼�������
������ļ�ֵ���������������õ����ټ�ֵ�����
ʾ�� 1:
����: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 12
����: ·�� 1��3��5��2��1 �����õ�����ֵ������
 

��ʾ��

0 < grid.length <= 200
0 < grid[0].length <= 200

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
*/
class Solution {
public:
    void _maxValue(vector<vector<int>>& grid, vector<vector<int>>& dp, int len1, int len2)
    {
        dp[0][0] = grid[0][0];
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int maxValue(vector<vector<int>>& grid) {
        int len1 = grid.size(), len2 = grid[0].size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        _maxValue(grid, dp, len1, len2);
        
        return dp[len1][len2];
    }
};