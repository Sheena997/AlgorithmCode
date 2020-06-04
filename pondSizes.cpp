/*
������ 16.19. ˮ���С
����һ�����ڱ�ʾһƬ���ص���������land���þ�����
ÿ�����ֵ�����Ӧ�ص�ĺ��θ߶ȡ���ֵΪ0���ʾˮ
���ɴ�ֱ��ˮƽ��Խ����ӵ�ˮ��Ϊ�����������Ĵ�С
��ָ�����ӵ�ˮ��ĸ�������дһ�������������������
�г����Ĵ�С������ֵ��Ҫ��С��������

ʾ����

���룺
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
����� [1,2,4]
��ʾ��

0 < len(land) <= 1000
0 < len(land[i]) <= 1000

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/pond-sizes-lcci/
*/
class Solution {
public:
    int path[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    
    void dfs(vector<vector<int>>& land, int& ret, int curX, int curY, vector<vector<int>>& visited, int row, int col)
    {
        //���
        visited[curX][curY] = 1;
  

        //��8����������
        for(int i = 0; i < 8; ++i)
        {
            int newX = curX + path[i][0];
            int newY = curY + path[i][1];
            
            if(newX < 0 || newX >= row
            || newY < 0 || newY >= col)
                continue;
            
            if(land[newX][newY] == 0 && visited[newX][newY] == 0)
                dfs(land, ++ret, newX, newY, visited, row, col);
            
        }
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<int> res;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        if(land.empty())
            return res;
        for(int i = 0; i < land.size(); ++i)
        {
            for(int j = 0; j < land[0].size(); ++j)
            {
                int ret = 1;
                if(land[i][j] == 0 && visited[i][j] == 0)
                {
                    dfs(land, ret, i, j, visited, row, col);
                    res.push_back(ret);
                }
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};