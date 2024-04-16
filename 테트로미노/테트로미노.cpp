#include <iostream>
#include <vector>
#include <algorithm>
int N, M;
int cnt = 0;
int sum = 0;
int max = 0;
int dx[3] = { -1,1,0 };
int dy[3] = { 0,0,1 };
bool Isvisit[501][501] = { false };
std::vector<std::vector<int>> grid;

void dfs(int _x,int _y)
{
	Isvisit[_y][_x] = true;		
	sum += grid[_y][_x];
	cnt++; 
	if (cnt == 4)
	{
		max = std::max(max, sum);
		Isvisit[_y][_x] = false;
		cnt--;
		sum -= grid[_y][_x];
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		int nextx = _x + dx[i];
		int nexty = _y + dy[i];
		if (nextx<0 || nexty < 0 || nextx>=M || nexty>=N)
		{
			continue;
		}
		if (Isvisit[nexty][nextx] == true)
		{
			continue;
		}
		dfs(nextx, nexty);
	}
	Isvisit[_y][_x] = false;
	cnt--;
	sum -= grid[_y][_x];

}

int main()
{
	std::cin >> N >> M;
	grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int num = 0;
			std::cin >> num;
			grid[y].push_back(num);
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			dfs(x, y);
		}
	}
	/*
	け
	けけ
	け
	*/
	for (int y = 0; y < N-2; y++)
	{
		for (int x = 0; x < M-1; x++)
		{
			max = std::max(max, grid[y][x] + grid[y + 1][x] + grid[y + 2][x] + grid[y + 1][x + 1]);
		}
	}
	/*
	けけけ
	  け
	*/
	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < M - 2; x++)
		{
			max = std::max(max, grid[y][x] + grid[y][x+1] + grid[y][x+2] + grid[y + 1][x + 1]);
		}
	}
	/*
	  け
	けけ
	  け
	*/
	for (int y = 0; y < N - 2; y++)
	{
		for (int x = 1; x < M; x++)
		{
			max = std::max(max, grid[y][x] + grid[y+1][x] + grid[y+2][x] + grid[y + 1][x - 1]);
		}
	}
	/*
	   け
	 けけけ
	*/
	for (int y = 1; y < N; y++)
	{
		for (int x = 1; x < M-2; x++)
		{
			max = std::max(max, grid[y][x] + grid[y][x-1] + grid[y][x+1] + grid[y-1][x]);
		}
	}
	std::cout << max;
	return 0;
}