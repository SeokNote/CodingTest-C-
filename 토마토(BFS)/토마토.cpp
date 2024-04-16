//https://www.acmicpc.net/status?user_id=mskim6295&problem_id=7576&from_mine=1

//BFS문제 시작지점들을 Q에 다 담고 돌면서 탐색.
#include <iostream>
#include <vector>
#include <queue>
int dx[4] = { -1,0,1,0 }; // 왼쪽 위 오른쪽 아래
int dy[4] = { 0,1,0,-1 };
int n, m;
std::queue<std::pair<int, int>> q;
int cnt = 1;

void bfs(std::vector<std::vector<int>>& _grid, int _maxx, int _maxy)
{

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

			if (_grid[CheckY][CheckX] > 0)
			{
				continue;
			}
			if (_grid[CheckY][CheckX] == 0)
			{
				_grid[CheckY][CheckX] = 1;
				_grid[CheckY][CheckX] = _grid[curpos.first][curpos.second]+1;
				q.push({ CheckY, CheckX });
			}
			if (_grid[CheckY][CheckX] == -1)
			{
				continue;
			}
		}
	}

}
int main()
{

	cnt = 0;
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int num = 0;
			std::cin >> num;
			if (num == 1)
			{
				q.push({ y,x });
			}
			grid[y][x] = num;
		}
	}
	bfs(grid, n, m);
	int max = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 0)
			{
				max = -1;
				std::cout << max << "\n";
				return 0;
			}
			max = std::max(max, grid[i][j]);
		}
	}
	int a = 0;
	std::cout << max-1 << "\n";
	return 0;
}