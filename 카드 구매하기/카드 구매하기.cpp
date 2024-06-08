#include <iostream>
#include <vector>
//카드팩의 종류는 1~N개
std::vector<int> CardPrice;

int DP[1001] = { 0 };

int main()
{
	int N;
	std::cin >> N;
	CardPrice.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> CardPrice[i];
	}

	DP[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			DP[j] = std::max(DP[j],DP[j-i]+ CardPrice[i]);
		}
	}
	std::cout << DP[N];
	return 0;
}