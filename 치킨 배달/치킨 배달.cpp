#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::vector<std::pair<int, int>>> Grid;
std::vector<std::pair<int, int>> ChickenPos;
std::vector<std::pair<int, int>> HousePos;
std::vector<std::pair<int, int>> SelectPos;
int N, M;

int answer = INT32_MAX;

void SelectChicken(int cnt, int start)
{
	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i < HousePos.size(); i++)
		{
			int minlen = INT32_MAX;
			for (int j = 0; j < M; j++)
			{
				minlen = std::min(minlen, std::abs(HousePos[i].second - SelectPos[j].second) + std::abs(HousePos[i].first - SelectPos[j].first));
			}
			sum += minlen;
		}
		answer = std::min(answer, sum);
		return;
	}
	else
	{
		for (int i = start; i < ChickenPos.size(); i++)
		{
			SelectPos[cnt] = (ChickenPos[i]);
			SelectChicken(cnt + 1, i + 1);
		}
	}
	return;
}

//치킨집의 갯수중 M개를 뽑은 후 뽑은 위치에서 가장 가까운 집을 찾아서 더하면 된다.
int main()
{

	std::cin >> N >> M;
	Grid.resize(N);
	SelectPos.resize(M);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			int num = 0;
			std::cin >> num;
			if (num == 2)
			{
				ChickenPos.push_back(std::make_pair(y, x));
			}
			if (num == 1)
			{
				HousePos.push_back(std::make_pair(y, x));
			}

		}
	}
	SelectChicken(0, 0);

	std::cout << answer;
	return 0;
}