#include <iostream>
#include <vector>
#include <algorithm>
int main()
{

	int N, X;
	std::cin >> N >> X;
	std::vector<int> peoples;
	std::vector<int> answers;
	int answer = 0;
	int cnt = 0;
	peoples.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> peoples[i];
	}

	int right = 0;
	int sum = 0;
	int max = 0;
	for (int left = 0; left < N; left++)
	{
		while ((right - left) < X && right < N)
		{
			sum += peoples[right];
			right++;
		}
		
		answers.push_back(sum);
		max = std::max(max, sum);
		sum -= peoples[left];
	}
	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == max)
		{
			cnt++;
		}
	}
	if (max == 0)
	{
		std::cout << "SAD";
	}
	else
	{
		std::cout << max << "\n";
		std::cout << cnt;
	}
	return 0;
}