/*
994. ���õ�����
�ڸ����������У�ÿ����Ԫ���������������ֵ֮һ��
ֵ 0 ����յ�Ԫ��
ֵ 1 �����������ӣ�
ֵ 2 �����õ����ӡ�
ÿ���ӣ��κ��븯�õ����ӣ��� 4 ���������ϣ����ڵ��������Ӷ��ḯ�á�
����ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ����� -1��

ʾ�� 1��
���룺[[2,1,1],[1,1,0],[0,1,1]]
�����4
ʾ�� 2��
���룺[[2,1,1],[0,1,1],[1,0,1]]
�����-1
���ͣ����½ǵ����ӣ��� 2 �У� �� 0 �У���Զ���ḯ�ã���Ϊ����ֻ�ᷢ���� 4 �������ϡ�
ʾ�� 3��
���룺[[0,2]]
�����0
���ͣ���Ϊ 0 ����ʱ�Ѿ�û�����������ˣ����Դ𰸾��� 0 ��
��ʾ��

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] ��Ϊ 0��1 �� 2

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/rotting-oranges/
*/
class Solution {
public:
    int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        queue<pair<int, int>> q;
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }
        
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;
            while(size--)
            {
                pair<int, int> cur = q.front();
                q.pop();
            
                for(int i = 0; i < 4; ++i)
                {
                    int nx = cur.first + path[i][0];
                    int ny = cur.second + path[i][1];
                
                    if(nx < 0 || nx >= row
                    || ny < 0 || ny >= col)
                        continue;
                    if(grid[nx][ny] == 1)
                    {
                        flag = 1;
                        grid[nx][ny] = 2;
                        q.push(pair<int, int>(nx, ny));
                    }
                
                }
            }
            if(flag == 1)
                ++res;
        }
        
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return res;
    }
};