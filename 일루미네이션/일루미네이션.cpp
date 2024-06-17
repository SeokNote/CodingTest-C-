#include <iostream>
#include <vector>
#include <queue>
//위아래만 없음 치즈처럼 못가는 공간 표시하자
int dx1[4] = { -1,0,1,0 };
int dy1[4] = { 0,1,0,-1 };

int evendx[6] = { 0,1,0,-1,-1,-1 };
int evendy[6] = { -1,0,1,1,0,-1 };

int odddx[6] = { 1,1,1,0,-1,0 };
int odddy[6] = { -1,0,1,1,0,-1 };

int W, H;
int answer = 0;
std::vector<std::vector<int>> Grid;

void SearchNoneBlock(int _y,int _x)
{
	Grid[_y][_x] = 0;
	std::queue<std::pair<int, int>> q;
	q.push({ _y, _x });
	while (!q.empty())
	{
		std::pair<int, int> curpos = q.front();
		q.pop();
		for (int i = 0; i <4; i++)
		{
			int CheckX = curpos.second + dx1[i];
			int CheckY = curpos.first + dy1[i];
			if (CheckX < 0 || CheckY < 0 || CheckX >= W+2 || CheckY >= H+2)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 1)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 2)
			{
				continue;
			}

			Grid[CheckY][CheckX] = 2;
			q.push({ CheckY, CheckX });

		}
	}
}

void SearchSurface()
{
	for (int y = 0; y <= H+1; y++)
	{
		for (int x = 0; x <= W+1; x++)
		{
			if (Grid[y][x] == 1)
			{
				if (y % 2 == 0)
				{
					for (int i = 0; i < 6; i++)
					{
						int CheckX = x + evendx[i];
						int CheckY = y + evendy[i];
						if (CheckX < 0 || CheckY < 0 || CheckX >= W + 2 || CheckY >= H + 2)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 1)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 0)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 2)
						{
							answer++;
						}
					}
				}
				else
				{
					for (int i = 0; i < 6; i++)
					{
						int CheckX = x + odddx[i];
						int CheckY = y + odddy[i];
						if (CheckX < 0 || CheckY < 0 || CheckX >= W + 2|| CheckY >= H + 2)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 1)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 0)
						{
							continue;
						}
						if (Grid[CheckY][CheckX] == 2)
						{
							answer++;
						}
					}
				}
			}

		}
	}
}


int main()
{
	std::cin >> W >> H;
	Grid.resize(H + 2);
	for (int y = 0; y <= H +1; y++)
	{
		Grid[y].resize(W + 2);
		for (int x = 0; x <= W+1; x++)
		{
			Grid[y][x] = 0;
		}
	}

	for (int y = 1; y <= H; y++)
	{
		for (int x = 1; x <= W; x++)
		{
			std::cin>>Grid[y][x];
		}
	}
	SearchNoneBlock(0,0);
	SearchSurface();
	std::cout << answer;
	return 0;
}
