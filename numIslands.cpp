/*
200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

来源：LeetCode
链接：https://leetcode-cn.com/problems/number-of-islands/
*/
class Solution {
public:
    int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited, int curX, int curY)
    {
        //标记
        visited[curX][curY] = 1;
        
        //向四个方向搜索
        for(int i = 0; i < 4; ++i)
        {
            int nx = curX + path[i][0];
            int ny = curY + path[i][1];
            
            //判断范围
            if(nx < 0 || nx >= row
            || ny < 0 || ny >= col)
                continue;
            
             //判断是否为陆地，且是否访问过
            if(grid[nx][ny] == '1' && visited[nx][ny] == 0)
                dfs(grid, row, col, visited, nx, ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int res = 0;
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    ++res;
                    dfs(grid, row, col, visited, i, j);
                }
            }
        }
        
        return res;
    }
};