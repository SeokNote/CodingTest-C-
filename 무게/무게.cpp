#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::pair<int, int>> vec;
int main()
{
	int N;
	int answer = 0;
	std::cin >> N;
	vec.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int weight = 0;
		int len = 0;
		std::cin >> weight >> len;
		vec.push_back(std::make_pair(weight, len));
	}

	for (int i = 0; i < N; i++)
	{
		answer = 1;
		for (int j = 0; j < N; j++)
		{
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
			{
				answer++;
			}
		}
		std::cout << answer << "\n";
	}
	return 0;
}
