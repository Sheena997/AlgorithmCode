/*
剑指 Offer 12. 矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字
符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一
步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过
了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下
面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用
加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b
占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200

来源：LeetCode
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
*/
//超时
class Solution {
public:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited;
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int x, int y, int l, bool& res)
    {
        if(board[x][y] != word[l])
            return;
        if(l == word.size() - 1)
        {
            res = true;
            return;
        }
        
        visited[x][y] = true;
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + path[i][0];
            int ny = y + path[i][1];
            
            if(nx < 0 || nx >= board.size()
            || ny < 0 || ny >= board[0].size())
                continue;
            
            int ret = l + 1;
            if(board[nx][ny] == word[ret] && visited[nx][ny] == false)
                dfs(board, visited, word, nx, ny, l + 1, res);            
        }
        visited[x][y] = false;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        bool res = false;
        visited = vector(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0] && visited[i][j] == false)
                    dfs(board, visited, word, i, j, 0, res);
                if(res)
                    return true;;
            }
        }
        
        return false;
    }
};


class Solution {
public:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int x, int y, int l)
    {
         if(board[x][y] != word[l])
            return false;
        if(l == word.size() - 1)
            return true;
       
        visited[x][y] = true;
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + path[i][0];
            int ny = y + path[i][1];
            
            if(nx < 0 || nx >= board.size()
            || ny < 0 || ny >= board[0].size()
            || visited[nx][ny] == true)
                continue;
        
            if(dfs(board, visited, word, nx, ny, l + 1))
               return true;
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        visited = vector(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};