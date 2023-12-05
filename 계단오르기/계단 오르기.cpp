#include <iostream>
#include <vector>
#include <algorithm>
int Count[10000];
int DP[300];

int main()
{
	int Num = 0;
	std::cin >> Num;
	for (int i = 1; i <= Num; i++)
	{
		std::cin >> Count[i];
	}
	DP[1] = Count[1];
	DP[2] = Count[1] + Count[2];
	DP[3] = std::max(Count[1] + Count[3], Count[2] + Count[3]);
	for (int i = 4; i <= Num; i++)
	{
		DP[i] = std::max(DP[i - 2] + Count[i], DP[i - 3] + Count[i - 1] + Count[i]);
	}
	std::cout << DP[Num];
	return 0;
}