/*
动态规划：最短路径：
链接：https://www.nowcoder.com/questionTerminal/23462ed010024fcabb7dbd3df57c715e
来源：牛客网

给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(grid);
        for(int i = 1; i < row; ++i)
            dp[i][0] += dp[i - 1][0];
        for(int j = 1; j < col; ++j)
            dp[0][j] += dp[0][j - 1];
        
        for(int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
        return dp[row - 1][col - 1];
    }
};
