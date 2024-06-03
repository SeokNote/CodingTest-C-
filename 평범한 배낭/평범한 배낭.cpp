#include <iostream>
#include <vector>
//     ���Ǽ� ����    ��ġ
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
			//���濡 ���� ���ϴ� ������ ��
			if (Bag[y].first > x)
			{
				DP[y][x] = DP[y - 1][x];
			}
			else //���� �� ������ �ȳִ� ���� ���� ����� �ִ� ��ġ
			{
				DP[y][x] = std::max(DP[y - 1][x], DP[y - 1][x - Bag[y].first] + Bag[y].second);
			}
		}
	}

	std::cout << DP[N][K];
	return 0;

}