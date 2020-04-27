/*
链接：https://www.nowcoder.com/questionTerminal/2b7995aa4f7949d99674d975489cb7da
来源：牛客网

[编程题]triangle
热度指数：22339时间限制：C/C++ 1秒，其他语言2秒空间限制：C/C++ 32M，其他语言64M
算法知识视频讲解
给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
例如，给出的三角形如下：
[↵     [2],↵    [3,4],↵   [6,5,7],↵  [4,1,8,3]↵]
最小的从顶部到底部的路径和是2 + 3 + 5 + 1 = 11。
注意：
如果你能只用O（N）的额外的空间来完成这项工作的话，就可以得到附加分，其中N是三角形中的行总数。


Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle

[     [2],   [3,4],   [6,5,7],  [4,1,8,3]]

The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
Note: 
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        int row = triangle.size();
        vector<vector<int>> dp(triangle);
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < row; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                if(j == 0) 
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if(i == j)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        } 
        
        int res = dp[row - 1][0];
        for(int j = 1; j < row; ++j)
            res = min(res, dp[row - 1][j]);
        
        return res;
    }
};