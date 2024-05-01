#include <iostream>
#include <vector>

std::vector<std::vector<int>> grid;
int dx[3] = {-1,0,1};
int dy[3] = {1,1,1};

int N, M;
int sumdist = 0;
int curdist = 0;
int answer = INT32_MAX;
void dfs(int x, int y, int dir)
{
	sumdist += grid[y][x];
	if (y == N - 1)
	{
		answer = std::min(answer, sumdist);
		sumdist -= grid[y][x];
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i == dir)
		{
			continue;
		}
		int curx = x + dx[i];
		int cury = y + dy[i];
		if (curx < 0 || cury < 0 || curx >= M || cury >= N)
		{
			continue;
		}

		dfs(curx, cury, i);
		//
	}
	sumdist -= grid[y][x];

}

int main()
{
	std::cin >> N >> M;
	grid = std::vector<std::vector<int>>(N, std::vector<int>(M, 0));

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			std::cin >> grid[y][x];
		}
	}
	for (int i = 0; i < M; i++)
	{
		dfs(i, 0, 4);
	}
	std::cout << answer;
	return 0;
}