#include <iostream>
#include <vector>

int DP[1001] = {0};
std::vector<int> Nums;

int main()
{
	int N;
	std::cin >> N;
	Nums.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Nums[i];
	}

	int answer = 0;
	//처음 수 부터 돌아
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//증가하는 수인지 체크
			if (Nums[i] > Nums[j])
			{
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}
		answer = std::max(answer, DP[i]);
	}
	std::cout << answer;
	return 0;
}