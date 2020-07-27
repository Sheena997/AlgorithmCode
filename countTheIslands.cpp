/*
链接：https://www.nowcoder.com/questionTerminal/1ecd3d9e09664cde94919b65ea06b47c
来源：牛客网

[编程题]几个岛


给定一个m行n列的二维地图, 初始化每个单元都是水.
操作addLand 把单元格(row,col)变成陆地.
岛屿定义为一系列相连的被水单元包围的陆地单元, 横向或纵向相邻的陆地称为相连(斜对角不算).
在一系列addLand的操作过程中, 给出每次addLand操作后岛屿的个数.
二维地图的每条边界外侧假定都是水.

输入描述:
多组测试数据，请参考例题处理 每组数据k+3行, k表示addLand操作次数 第一行:表示行数m
第二行:表示列数n 第三行:表示addLand操作次数k 第4~k+3行:row col 表示addLand的坐标。
注意超过边界的坐标是无效的。


输出描述:
一行,k个整数, 表示每次addLand操作后岛屿的个数, 用空格隔开，结尾无空格
示例1
输入
3
3
4
0 0
0 1
1 2
2 1
输出
1 1 2 3
*/

#include <iostream>
#include <vector>

using namespace std;
int path[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> vvc, vector<vector<int>>& visited, int curRow, int curCol)
{
    visited[curRow][curCol] = 1;
    
    for(int i = 0; i < 4; ++i)
    {
        int nx = curRow + path[i][0];
        int ny = curCol + path[i][1];
        
        if(nx < 0 || nx >= vvc.size()
        || ny < 0 || ny >= vvc[0].size())
            continue;
        
        if(vvc[nx][ny] == 1 && visited[nx][ny] == 0)
            dfs(vvc, visited, nx, ny);
    }
}
int countTheIslands(vector<vector<int>> vvc, int m, int n)
{
    int sum = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(vvc[i][j] == 1 && visited[i][j] == 0)
            {
                ++sum;
                dfs(vvc, visited, i, j);
            }
        }
    }
    
    return sum;
}
int main()
{
    int m = 0, n = 0, k = 0;
    cin >> m >> n >> k;
    vector<vector<int>> vvc(m, vector<int>(n, 0));
    vector<int> res;
    while(k--)
    {
        int row = 0, col = 0;
        cin >> row >> col;
        vvc[row][col] = 1;
        
        int sum = countTheIslands(vvc, m, n);
        
        res.push_back(sum);
    }
    for(int i = 0; i < res.size(); ++i)
        (i == res.size() - 1) ? (cout << res[i] << endl) : (cout << res[i] << " ");
    
    return 0;
}