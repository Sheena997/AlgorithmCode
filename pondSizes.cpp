/*
面试题 16.19. 水域大小
你有一个用于表示一片土地的整数矩阵land，该矩阵中
每个点的值代表对应地点的海拔高度。若值为0则表示水
域。由垂直、水平或对角连接的水域为池塘。池塘的大小
是指相连接的水域的个数。编写一个方法来计算矩阵中所
有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：

0 < len(land) <= 1000
0 < len(land[i]) <= 1000

来源：LeetCode
链接：https://leetcode-cn.com/problems/pond-sizes-lcci/
*/
class Solution {
public:
    int path[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    
    void dfs(vector<vector<int>>& land, int& ret, int curX, int curY, vector<vector<int>>& visited, int row, int col)
    {
        //标记
        visited[curX][curY] = 1;
  

        //向8个方向搜索
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