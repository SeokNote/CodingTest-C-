#include <iostream>
#include <vector>

int DP[1001][4] = { 0 };
std::vector<std::vector<int>> ColorPrice;
int main()
{
	int N;
	std::cin >> N;
	ColorPrice.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		ColorPrice[i].resize(4);
		for (int j = 1; j < 4; j++)
		{
			std::cin >> ColorPrice[i][j];
		}
	}
	for (int i = 2; i <= N; i++)
	{
		DP[i][1] = ColorPrice[i][1] + std::min(DP[i - 1][2], DP[i - 1][3]);
		DP[i][2] = ColorPrice[i][2] + std::min(DP[i - 1][1], DP[i - 1][3]);
		DP[i][3] = ColorPrice[i][3] + std::min(DP[i - 1][2], DP[i - 1][1]);
	}

	DP[N][1] += std::min(ColorPrice[1][2], ColorPrice[1][3]);
	DP[N][2] += std::min(ColorPrice[1][3], ColorPrice[1][1]);
	DP[N][3] += std::min(ColorPrice[1][2], ColorPrice[1][1]);

	int answer = INT32_MAX;
	for (int i = 1; i <= 3; i++)
	{
		answer = std::min(answer, DP[N][i]);
	}
	std::cout << answer;
	return 0;
}