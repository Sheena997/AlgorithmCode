/*
��ָ Offer 12. �����е�·��
�����һ�������������ж���һ���������Ƿ����һ������ĳ��
���������ַ���·����·�����ԴӾ����е�����һ��ʼ��ÿһ
�������ھ����������ҡ��ϡ����ƶ�һ�����һ��·������
�˾����ĳһ����ô��·�������ٴν���ø��ӡ����磬����
���3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ��
�Ӵֱ������

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�b
ռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�

 

ʾ�� 1��

���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
�����true
ʾ�� 2��

���룺board = [["a","b"],["c","d"]], word = "abcd"
�����false
��ʾ��

1 <= board.length <= 200
1 <= board[i].length <= 200

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
*/
//��ʱ
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