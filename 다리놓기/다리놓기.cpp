#include <iostream>
#include <vector>
std::vector<int> Answer;
int DP[31][31];
//3C2
//3x2x1 / 2x1
//5c1
//5x4x3x2x1/4x3x2x1
void SetDP()
{
	for (int i = 2; i < 31; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i==j)
			{
				DP[i][j] = 1;
				continue;
			}
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}
}
int main()
{
	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;
	SetDP();
	int Num = 0;
	std::cin >> Num;
	for (int i = 0; i < Num; i++)
	{
		int Left = 0;
		int Right = 0;
		std::cin >> Left >> Right;
		Answer.push_back(DP[Right][Left]);
	}

	for (int i = 0; i < Num; i++)
	{
		std::cout << Answer[i] << "\n";
	}
	return 0;
}