/*
200. ��������
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�������ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��
ʾ�� 1:
����:
11110
11010
11000
00000
���: 1

ʾ�� 2:
����:
11000
11000
00100
00011
���: 3
����: ÿ������ֻ����ˮƽ��/����ֱ���������ڵ�½�����Ӷ��ɡ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/number-of-islands/
*/
class Solution {
public:
    int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited, int curX, int curY)
    {
        //���
        visited[curX][curY] = 1;
        
        //���ĸ���������
        for(int i = 0; i < 4; ++i)
        {
            int nx = curX + path[i][0];
            int ny = curY + path[i][1];
            
            //�жϷ�Χ
            if(nx < 0 || nx >= row
            || ny < 0 || ny >= col)
                continue;
            
             //�ж��Ƿ�Ϊ½�أ����Ƿ���ʹ�
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