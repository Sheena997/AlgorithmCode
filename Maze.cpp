//�Թ�����������㷨��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//��ŵ�����
struct node
{
	int _x;
	int _y;
	node(int x, int y)
		:_x(x)
		,_y(y)
	{}
};

bool BFS(vector<int>& grid, int startx, int starty, int destx, int desty)
{
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<int>> visited(row, vector<int>(col, 0));
	queue<node> q;
	
	//������
	q.push(node(startx, starty));
	visited[startx][starty] = 1;//��ʾ���ʹ���
	
	//��������
	while(!q.empty())
	{
		//��ȡ��ͷԪ��
		node curPos = q.front();
		q.pop();
		if(curPos._x = destx && curPos._y == desty)
			return true;
		
		//����
		//������������
		for(int i = 0; i < 4; ++i)
		{
			int nx = curPos._x + pos[i][0];
			int ny = curPos._y + pos[i][1];
			
			//�жϷ�Χ
			if(nx < 0 || nx >= row
			|| ny < 0 || ny >= col)
				continue;
			
			//���û��Խ�磨��ǰλ�ÿ���ͨ������û���߹��������µĵ���������
			if(grid[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				q.push(node(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
	
	return false;
}

int main()
{
	vector<vector<int>> grid = { {0, 0, 1, 0, 1}
	                            ,{0, 1, 0, 1, 0}
								,{1, 0, 0, 0, 1}
								,{0, 1, 0, 1, 0}
							   };
	
	int sx, sy, dx, dy;
	while(1)
	{
		cout << "������㣬�յ�" << endl;
		cin >> sx >> sy >> dx >> dy;
		cout << BFS(grid, sx, sy, dx, dy) << endl;
	}
							   
}