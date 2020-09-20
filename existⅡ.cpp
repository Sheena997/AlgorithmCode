/*
79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中
“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元
格内的字母不允许被重复使用。 

示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 
提示：
board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：LeetCode
链接：https://leetcode-cn.com/problems/word-search/
*/
class Solution {
public:
    int path[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>> board, string word, vector<vector<int>>& visited, int curx, int cury, int index)
    {
        if(curx < 0 || curx >= board.size() || cury < 0 || cury >= board[0].size() || visited[curx][cury] == 1 ||board[curx][cury] != word[index])
            return false;
        
        if(index == word.size() - 1)
            return true;
        
        visited[curx][cury] = 1;
        for(int i = 0; i < 4; ++i)
        {
            int nx = curx + path[i][0];
            int ny = cury + path[i][1];
            
            if(nx < 0 || nx >= board.size()
            || ny < 0 || ny >= board[0].size())
                continue;
            
            if(dfs(board, word, visited, nx, ny, index + 1))
                return true;
        }
        visited[curx][cury] = 0;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(visited[i][j] == 0 && board[i][j] == word[0])
                {
                    if(dfs(board, word, visited, i, j, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
};