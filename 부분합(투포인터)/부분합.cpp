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
	int Answer = INT_MAX;
	while (Left <= Right && Right < N)
	{
		if (Sum >= M)
		{
			Answer = std::min(Answer, Right - (++Left)+ 1);
			Sum -= Arr[Left];
		}
		else if (Sum < M)
		{
			Sum += Arr[++Right];
		}
	}
	if (Answer == INT_MAX)
	{
		std::cout << 0;
		return 0;
	}
	std::cout << Answer;
	return 0;
}