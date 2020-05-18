/*
994. 腐烂的橘子
在给定的网格中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：
输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：
输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
提示：

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] 仅为 0、1 或 2

来源：LeetCode
链接：https://leetcode-cn.com/problems/rotting-oranges/
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
        
<<<<<<< HEAD
         //队列初始化，找到所有已经腐烂的橘子
=======
>>>>>>> 255f7f50b81cb58c3105041c225a970fb61e6da0
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
<<<<<<< HEAD
            //取出当前队列所有元素
=======
>>>>>>> 255f7f50b81cb58c3105041c225a970fb61e6da0
            while(size--)
            {
                pair<int, int> cur = q.front();
                q.pop();
<<<<<<< HEAD
                
                //上下左右搜索
=======
            
>>>>>>> 255f7f50b81cb58c3105041c225a970fb61e6da0
                for(int i = 0; i < 4; ++i)
                {
                    int nx = cur.first + path[i][0];
                    int ny = cur.second + path[i][1];
<<<<<<< HEAD
                    
                    if(nx < 0 || nx >= row
                    || ny < 0 || ny >= col)
                        continue;
                    
                    //将下一分钟腐烂的橘子放到队列中
=======
                
                    if(nx < 0 || nx >= row
                    || ny < 0 || ny >= col)
                        continue;
>>>>>>> 255f7f50b81cb58c3105041c225a970fb61e6da0
                    if(grid[nx][ny] == 1)
                    {
                        flag = 1;
                        grid[nx][ny] = 2;
                        q.push(pair<int, int>(nx, ny));
                    }
<<<<<<< HEAD
                }
            }
            //DFS的一步搜索完成
=======
                
                }
            }
>>>>>>> 255f7f50b81cb58c3105041c225a970fb61e6da0
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