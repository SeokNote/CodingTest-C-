#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
std::vector<std::string> Grid;
std::vector<int> ans;
bool Isvisit[25][25] = { false };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N = 0;
int Count = 0;
int group = 0;
void DFS(int _StartX, int _StartY)
{
	Grid[_StartY][_StartX] = '0';
	Count++;
	for (int i = 0; i < 4; i++)
	{
		int CheckX = _StartX + dx[i];
		int CheckY = _StartY + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == '1')
		{
			DFS(CheckX, CheckY);
		}
	}
}

int main()
{
	std::cin >> N;
	Grid.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Grid[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Grid[i][j] == '1')
			{
				Count = 0;
				DFS(j, i);
				group++;
				ans.push_back(Count);
			}
		}
	}

	std::sort(ans.begin(), ans.end());
	std::cout << group << "\n";

	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << "\n";
	}
}