#include <iostream>
#include <vector>
#include <queue>
int dx[4] = { -1,0,1,0 }; // 왼쪽 위 오른쪽 아래
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
void dfs(int _x,int _y, std::vector<std::vector<int>>& _grid,int _maxx,int _maxy)
{
	_grid[_y][_x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int CheckX = _x + dx[i];
		int CheckY = _y + dy[i];
		if (CheckX < 0 || CheckY < 0 || CheckX >= _maxx || CheckY >= _maxy)
		{
			continue;
		}

		if (_grid[CheckY][CheckX] == 0)
		{
			continue;
		}
		_grid[CheckY][CheckX] = 0;
		dfs(CheckX, CheckY, _grid, _maxx, _maxy);
	}
}
void bfs(int _x, int _y, std::vector<std::vector<int>>& _grid, int _maxx, int _maxy)
{
	_grid[_y][_x] = 0;
	std::queue<std::pair<int, int>> q;
	q.push({ _y, _x });
	while (!q.empty())
	{
		std::pair<int, int> curpos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int CheckX = curpos.second + dx[i];
			int CheckY = curpos.first + dy[i];
			if (CheckX < 0 || CheckY < 0 || CheckX >= _maxx || CheckY >= _maxy)
			{
				continue;
			}

			if (_grid[CheckY][CheckX] == 0)
			{
				continue;
			}
			_grid[CheckY][CheckX] = 0;
			q.push({ CheckY, CheckX });

		}
	}

}
int main()
{
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		cnt = 0;
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> grid(m,std::vector<int> (n,0));
		int num;
		std::cin >> num;
		for (int j = 0; j < num; j++)
		{
			int x, y;
			std::cin >> x >> y;
			grid[y][x] = 1;
		}
		for (int y = 0; y < grid.size(); y++)
		{
			for (int x = 0; x < grid[y].size(); x++)
			{
				if (grid[y][x] == 1) 
				{
					cnt++;
					bfs(x, y, grid, n, m);
				}
			}
		}
		std::cout << cnt << "\n";
	}
	return 0;
}