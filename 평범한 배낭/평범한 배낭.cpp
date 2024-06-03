#include <iostream>
#include <vector>
//     물건수 무게    가치
int DP[101][100001] = { 0 };
std::vector<std::pair<int, int>> Bag;

int main()
{
	int N, K;
	std::cin >> N >> K;
	Bag.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int W, V;
		std::cin >> W >> V;
		Bag[i].first = W;
		Bag[i].second = V;
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= K; x++)
		{
			//가방에 넣지 못하는 무게일 때
			if (Bag[y].first > x)
			{
				DP[y][x] = DP[y - 1][x];
			}
			else //넣을 수 있지만 안넣는 경우와 넣을 경우중 최대 가치
			{
				DP[y][x] = std::max(DP[y - 1][x], DP[y - 1][x - Bag[y].first] + Bag[y].second);
			}
		}
	}

	std::cout << DP[N][K];
	return 0;

}