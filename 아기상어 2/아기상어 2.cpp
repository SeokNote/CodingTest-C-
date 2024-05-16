#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
std::vector<std::vector<int>> grid;
std::vector<std::vector<int>> dist;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<bool>> copyIsVisit;
std::vector<int> answer;

int dx[8] = { -1,0,1,0,1,1,-1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,-1,1 };
int N, M;
int cnt = 0;

void bfs(int _starty ,int _startx)
{
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(_starty, _startx));
	copyIsVisit[_starty][_startx] = true;
	while (!q.empty())
	{
		std::pair<int, int> curpos = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nextposx = curpos.second + dx[i];
			int nextposy = curpos.first + dy[i];

			if (nextposx < 0 || nextposy <0 || nextposx >=M || nextposy >= N )
			{
				continue;
			}
			if (grid[nextposy][nextposx] == 1)
			{
				continue;
			}
			if (copyIsVisit[nextposy][nextposx] == true)
			{
				continue;
			}
			dist[nextposy][nextposx] = std::min(dist[curpos.first][curpos.second] + 1, dist[nextposy][nextposx]);
			copyIsVisit[nextposy][nextposx] = true;
			q.push(std::make_pair(nextposy, nextposx));
			
		}
	}

}

int main()
{
	std::cin >> N >> M;
	grid.resize(N);
	dist.resize(N);
	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		grid[y].resize(M);
		dist[y].resize(M);
		IsVisit[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			int num = 0;
			std::cin >> num;
			grid[y][x] = num;
			if (num == 1)
			{
				IsVisit[y][x] = true;
				dist[y][x] = 0;
			}
			else
			{
				IsVisit[y][x] = false;
				dist[y][x] = INT32_MAX;
			}
		}
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (grid[y][x] == 1)
			{
				copyIsVisit = IsVisit;
				bfs(y, x);
			}
		}
	}
	int max = -1;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (max< dist[y][x])
			{
				max = dist[y][x];
			}
		}
	}
	std::cout << max;
	return 0;
}