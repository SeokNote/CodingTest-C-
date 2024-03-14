#include <iostream>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> vec;
	vec.resize(N);
	int Max = INT64_MAX;
	for (int i = 0; i < N; i++)
	{
		int M = 0;
		std::cin >> M;
		vec[i] = M;
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (vec[i] > vec[i + 1])
		{
			continue;
		}
		int count = 1;
		for (int j = i + 1; j < N; j++)
		{
			if (vec[i] <= vec[j])
			{
				count++;
			}
			else
			{
				break;
			}

		}
		if (Max < (vec[i] * count))
		{
			Max = vec[i] * count;
		}

	}
	for (int i = N - 1; i > 1; i--)
	{
		if (vec[i] > vec[i - 1])
		{
			continue;
		}
		int count = 1;
		for (int j = i - 1; j > 0; j--)
		{
			if (vec[i] <= vec[j])
			{
				count++;
			}
			else
			{
				break;
			}

		}

		if (Max < (vec[i] * count))
		{
			Max = vec[i] * count;
		}

	}
	std::cout << Max;
}