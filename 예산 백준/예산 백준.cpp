#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	int N = 0;
	int Answer = 0;
	std::cin >> N;
	std::vector<int> vec;
	vec.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int Money = 0;
		std::cin >> Money;
		vec.push_back(Money);
	}
	int Max = 0;
	std::cin >> Max;
	std::sort(vec.begin(), vec.end());
	int count = 0;
	int Start = 0;
	int End = vec[N - 1];
	int Sum = 0;
	int Total = 0;
	while (Start <= End)
	{
		Sum = 0;
		int mid = (Start + End) / 2;
		for (int i = 0; i < N; i++) {
			Sum += std::min(vec[i], mid);
		}
		if (Max >= Sum) {
			Answer = mid;
			Start = mid + 1;
		}
		else {
			End = mid - 1;
		}
	}
	std::cout << Answer;
	return 0;
}