#include <iostream>
#include <vector>
std::vector<int> Nums;
int DP[100001] = { 0 };
int main()
{
	int N;
	int answer = INT32_MIN;
	std::cin >> N;
	Nums.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Nums[i];
	}
	DP[0] = Nums[0];
	for (int i = 1; i < N; i++)
	{
		if (DP[i - 1] + Nums[i] > 0)
		{
			if (DP[i - 1] + Nums[i] < Nums[i])
			{
				DP[i] = Nums[i];
			}
			else
			{
				DP[i] = DP[i - 1] + Nums[i];
			}
		}
		else
		{
			DP[i] = Nums[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		answer = std::max(answer, DP[i]);
	}
	std::cout << answer;
	return 0;

}