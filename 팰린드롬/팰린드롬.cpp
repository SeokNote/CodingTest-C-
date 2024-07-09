#include <iostream>
#include <vector>

std::vector<int> Nums;
std::vector<int> Answer;
int N;
int DP[2001][2001] = { 0 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Nums.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Nums[i];
	}

	for (int i = 1; i <= N; i++) 
	{
		DP[i][i] = 1; 
		if (i != 1 && Nums[i - 1] == Nums[i])
		{
			DP[i - 1][i] = 1;
		} 
	}
	for (int i = 3; i <= N; i++)
	{
		for (int Start = 1; Start <= N-i+1; Start++)
		{
			int End = Start + i - 1;
			if (Nums[Start] == Nums[End] && DP[Start + 1][End - 1] == 1)
			{
				DP[Start][End] = 1;
			}
		}
	}

	int M;
	std::cin >> M;

	for (int i = 1; i <= M; i++)
	{
		int Start, End;
		std::cin >> Start >> End;
		std::cout << DP[Start][End] <<"\n";
		
	}
	return 0;
}