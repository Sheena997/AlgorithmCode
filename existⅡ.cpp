/*
79. ��������
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ�����
�����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ
���ڵ���ĸ�������ظ�ʹ�á� 

ʾ��:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

���� word = "ABCCED", ���� true
���� word = "SEE", ���� true
���� word = "ABCB", ���� false
 
��ʾ��
board �� word ��ֻ������д��СдӢ����ĸ��
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/word-search/
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