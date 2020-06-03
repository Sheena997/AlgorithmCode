/*
面试题47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次
向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面
的礼物的价值，请计算你最多能拿到多少价值的礼物？
示例 1:
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200

来源：LeetCode
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
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