#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
int Arr[100001];
int main()
{
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}
	std::vector<int> Answers;
	int Left = -1;
	int Right = -1;
	int Sum = 0;
	while (Left <= Right && Right < N)
	{
		if (Sum >= M)
		{
			Left++;
			Sum -= Arr[Left];
		}
		else if (Sum < M)
		{
			Right++;
			Sum += Arr[Right];
		}
	}
	return 0;
}