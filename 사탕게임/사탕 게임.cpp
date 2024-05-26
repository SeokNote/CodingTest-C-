#include <iostream>
#include <vector>

std::vector<std::vector<char>> Grid;
std::vector<std::vector<char>> CopyGrid;

int N;
int answer = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//일단 하나하나씩 다 4방향으로 스왑해본다
//스왑하고 체크한다.
int CandyCnt()
{
	int MaxRowCnt = 0;
	int MaxColCnt = 0;
	//가로 체크
	for (int y = 0; y < N; y++)
	{
		int RowCnt = 1;
		for (int x = 0; x < N - 1; x++)
		{
			if (CopyGrid[y][x] == CopyGrid[y][x + 1])
			{
				RowCnt++;
			}
			else
			{
				MaxRowCnt = std::max(MaxRowCnt, RowCnt);
				RowCnt = 1;
			}

			if (x == N - 2)
			{
				if (RowCnt > MaxRowCnt)
				{
					MaxRowCnt = RowCnt;
					RowCnt = 1;
				}
			}
		}
	}
	//세로 체크
	for (int x = 0; x < N; x++)
	{
		int ColCnt = 1;
		for (int y = 0; y < N - 1; y++)
		{
			if (CopyGrid[y][x] == CopyGrid[y + 1][x])
			{
				ColCnt++;
			}
			else
			{
				MaxColCnt = std::max(MaxColCnt, ColCnt);
				ColCnt = 1;
			}
			if (y == N - 2)
			{
				if (ColCnt > MaxColCnt)
				{
					MaxColCnt = ColCnt;
					ColCnt = 1;
				}
			}

		}
	}

	return std::max(MaxColCnt, MaxRowCnt);
}

void SwapCandy(int _y, int _x)
{
	answer = std::max(answer, CandyCnt());
	for (int i = 0; i < 4; i++)
	{
		CopyGrid = Grid;
		int NextPosX = _x + dx[i];
		int NextPosY = _y + dy[i];
		if (NextPosX < 0 || NextPosY < 0 || NextPosX >= N || NextPosY >= N)
		{
			continue;
		}
		char temp = CopyGrid[_y][_x];
		CopyGrid[_y][_x] = CopyGrid[NextPosY][NextPosX];
		CopyGrid[NextPosY][NextPosX] = temp;
		answer = std::max(answer, CandyCnt());
	}
}

int main()
{
	std::cin >> N;
	Grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
		}
	}
	CopyGrid = Grid;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			SwapCandy(y, x);
		}
	}
	std::cout << answer;
	return 0;
}