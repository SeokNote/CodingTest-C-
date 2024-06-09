#include <iostream>
#include <vector>

//DP[I][J] I������ ���������� J���� �� ����Ʈ�� �ּ�
int DP[1001][4] = { 0 };

int main()
{
	int N;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			std::cin >> DP[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		DP[i][1] += std::min(DP[i - 1][2], DP[i - 1][3]);
		DP[i][2] += std::min(DP[i - 1][1], DP[i - 1][3]);
		DP[i][3] += std::min(DP[i - 1][2], DP[i - 1][1]);

	}
	int answer = INT32_MAX;
	for (int i = 1; i <= 3; i++)
	{
		answer = std::min(answer, DP[N][i]);
	}
	std::cout << answer;
	return 0;
}