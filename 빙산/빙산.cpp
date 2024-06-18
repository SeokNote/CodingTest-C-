#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> CopyGrid;
std::vector<std::vector<int>> InitGrid;


int dx[8] = { -1,0,1,0 };
int dy[8] = { 0,1,0,-1};
int N, M;


void OneYearsAgo()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (CopyGrid[y][x] != 0)
			{
				int cnt = 0;
				for (int i = 0; i < 4; i++)
				{
					int NextX = x + dx[i];
					int NextY = y + dy[i];
					if (NextX < 0 || NextY < 0 || NextX >= M || NextY >= N)
					{
						continue;
					}
					if (CopyGrid[NextY][NextX] == 0)
					{
						cnt++;
					}
				}
				if (Grid[y][x] - cnt < 0)
				{
					Grid[y][x] = 0;
				}
				else
				{
					Grid[y][x] -= cnt;
				}
			}
		}
	}

}

void BFS(int _y,int _x)
{
	CopyGrid[_y][_x] = 0;
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
			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (CopyGrid[CheckY][CheckX] == 0)
			{
				continue;
			}
			CopyGrid[CheckY][CheckX] = 0;
			q.push({ CheckY, CheckX });

		}
	}
}

bool LumpCheck()
{
	int cnt = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (CopyGrid[y][x] != 0)
			{
				cnt++;
				BFS(y, x);
			}
		}
	}
	if (cnt >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	std::cin >> N >> M;
	Grid.resize(N);
	InitGrid.resize(N);
	bool Check = false;
	int answer = 0;
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		InitGrid[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			std::cin >> Grid[y][x];
			InitGrid[y][x] = 0;
		}
	}

	while (1)
	{
		CopyGrid = Grid;
		OneYearsAgo();
		answer++;
		CopyGrid = Grid;
		Check = LumpCheck();
		if (InitGrid == Grid || Check == true)
		{
			break;
		}
	}
	if (Check == true)
	{
		std::cout << answer;
	}
	else
	{
		std::cout << 0;
	}
	return 0;
}