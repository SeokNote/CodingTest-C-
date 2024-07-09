#include <iostream>
#include <vector>

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
//D = 0 U = 1 L = 2 R = 3
std::vector<std::vector<int>> Grid;
int IsVisit[1001][1001] = { 0 };
int answer = 0;
void DFS(int _StartY, int _StartX)
{
	IsVisit[_StartY][_StartX] = 1;
	int NextX = _StartX + dx[Grid[_StartY][_StartX]];
	int NextY = _StartY + dy[Grid[_StartY][_StartX]];

	if (IsVisit[NextY][NextX] == 1)
	{
		answer++;
	}
	if (IsVisit[NextY][NextX] == 0)
	{
		DFS(NextY, NextX);
	}
	IsVisit[_StartY][_StartX] = 2;
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	Grid.resize(N);

	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			char Dir;
			std::cin >> Dir;
			if (Dir == 'D')
			{
				Grid[y][x] = 0;
			}
			else if (Dir == 'U')
			{
				Grid[y][x] = 1;
			}
			else if (Dir == 'L')
			{
				Grid[y][x] = 2;
			}
			else
			{
				Grid[y][x] = 3;
			}
		}
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (IsVisit[y][x] == 0)
			{
				DFS(y, x);
			}
		}
	}
	std::cout << answer;
	return 0;
}