/*
���ӣ�https://www.nowcoder.com/questionTerminal/1ecd3d9e09664cde94919b65ea06b47c
��Դ��ţ����

[�����]������


����һ��m��n�еĶ�ά��ͼ, ��ʼ��ÿ����Ԫ����ˮ.
����addLand �ѵ�Ԫ��(row,col)���½��.
���춨��Ϊһϵ�������ı�ˮ��Ԫ��Χ��½�ص�Ԫ, ������������ڵ�½�س�Ϊ����(б�Խǲ���).
��һϵ��addLand�Ĳ���������, ����ÿ��addLand��������ĸ���.
��ά��ͼ��ÿ���߽����ٶ�����ˮ.

��������:
����������ݣ���ο����⴦�� ÿ������k+3��, k��ʾaddLand�������� ��һ��:��ʾ����m
�ڶ���:��ʾ����n ������:��ʾaddLand��������k ��4~k+3��:row col ��ʾaddLand�����ꡣ
ע�ⳬ���߽����������Ч�ġ�


�������:
һ��,k������, ��ʾÿ��addLand��������ĸ���, �ÿո��������β�޿ո�
ʾ��1
����
3
3
4
0 0
0 1
1 2
2 1
���
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