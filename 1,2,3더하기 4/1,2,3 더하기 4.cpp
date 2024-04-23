#include <iostream>
int DP[10001][3] = { 0 };

int main()
{
	DP[1][1] = 1;
	DP[2][1] = 1;
	DP[2][2] = 1;
	DP[3][1] = 1;
	DP[3][2] = 1;
	DP[3][3] = 1;

	for (int i = 4; i < 10001; i++)
	{
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int answer = 0;
		int num = 0;
		std::cin >> num;
		for (int i = 1; i <= 3; i++)
		{
			answer += DP[num][i];
		}
		std::cout << answer << "\n";
	}
	return 0;
}