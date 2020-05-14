/*
130. 被围绕的区域
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 
都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的
 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 
来源：LeetCode
链接：https://leetcode-cn.com/problems/surrounded-regions/
*/
class Solution {
public:
    int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int curX, int curY)
    {
        board[curX][curY] = '#';
        for(int i = 0; i < 4; ++i)
        {
            int newX = curX + path[i][0];
            int newY = curY + path[i][1];
            
            if(newX < 0 || newX >= board.size()
            || newY < 0 || newY >= board[0].size())
                continue;
            
            if(board[newX][newY] == 'O')
                dfs(board, newX, newY);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        
        //搜索四条边
        for(int i = 0; i < board[0].size(); ++i)
        {
            //第一行和最后一行
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[board.size() - 1][i] == 'O')
                dfs(board, board.size() - 1, i);
        }
        for(int i = 1; i < board.size() - 1; ++i)
        {
            //第一列和最后一列
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][board[0].size() - 1] == 'O')
                dfs(board, i, board[0].size() - 1);
        }
        
        
        //复原
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    
    }
};