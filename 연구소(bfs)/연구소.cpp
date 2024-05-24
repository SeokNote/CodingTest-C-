#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//벽을 3개 세운다 조합으로 다 구해 그냥 64C3
//바이러스 기준으로 bfs돌면서 전염시킨다
//전염시키고 0의 갯수 count한다
std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> Copy;
std::vector<std::pair<int, int>> WallGrid;
std::queue<std::pair<int, int>> VirusQ;
std::queue<std::pair<int, int>> CopyQ;

std::vector<int> Temp;

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;
int cnt = 0;

void BFS()
{
	while (!CopyQ.empty())
	{
		std::pair<int, int> curpos = CopyQ.front();
		CopyQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int CheckX = curpos.second + dx[i];
			int CheckY = curpos.first + dy[i];
			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (Copy[CheckY][CheckX] == 1)
			{
				continue;
			}
			if (Copy[CheckY][CheckX] == 2)
			{
				continue;
			}
			if (Copy[CheckY][CheckX] == 0)
			{
				Copy[CheckY][CheckX] = 2;
				CopyQ.push({ CheckY, CheckX });
			}

		}
	}
}

int main()
{
	std::cin >> N >> M;
	Grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			int num = 0;
			std::cin >> num;
			Grid[y][x] = num;
			if (num == 0)
			{
				WallGrid.push_back(std::make_pair(y, x));
			}
			else if (num == 2)
			{
				VirusQ.push(std::make_pair(y, x));
			}
		}
	}
	Copy = Grid;
	CopyQ = VirusQ;
	Temp.resize(WallGrid.size(), 0);
	for (int i = 0; i < 3; i++)
	{
		Temp[i] = 1;
	}
	std::sort(Temp.begin(), Temp.end());
	do
	{
		Copy = Grid;
		CopyQ = VirusQ;
		cnt = 0;
		for (int i = 0; i < WallGrid.size(); i++)
		{
			if (Temp[i] == 1)
			{
				Copy[WallGrid[i].first][WallGrid[i].second] = 1;
			}
		}
		BFS();
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (Copy[y][x] == 0)
				{
					cnt++;
				}
			}
		}
		answer = std::max(answer, cnt);
	} while (std::next_permutation(Temp.begin(), Temp.end()));

	std::cout << answer;
	return 0;
}