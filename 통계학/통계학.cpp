#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

std::vector<int> Numbers;
int N;

int Mean()
{
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += Numbers[i];
	}
	if (sum > 0)
	{
		return (int)((sum / N) + 0.5);
	}
	else
	{
		return (int)((sum / N) - 0.5);
	}
}

int Middle(std::vector<int>& _Numbers)
{
	std::sort(_Numbers.begin(), _Numbers.end());
	return _Numbers[N / 2];
}

int Mode()
{
	std::map<int, int> Nums;
	std::vector<int> ModeNumbers;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		Nums[Numbers[i]]++;
	}
	for (auto i : Nums)
	{
		if (max < i.second)
		{
			max = i.second;
		}
	}
	for (auto i : Nums)
	{
		if (i.second == max)
		{
			ModeNumbers.push_back(i.first);
		}
	}
	std::sort(ModeNumbers.begin(), ModeNumbers.end());
	if (ModeNumbers.size() > 1)
	{
		return ModeNumbers[1];
	}
	else
	{
		return ModeNumbers[0];
	}
}

int Range(std::vector<int>& _Numbers)
{
	std::sort(_Numbers.begin(), _Numbers.end());
	return _Numbers[N - 1] - Numbers[0];
}

int main()
{
	std::cin >> N;
	Numbers.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Numbers[i];
	}
	std::cout << Mean() << "\n";
	std::cout << Middle(Numbers) << "\n";
	std::cout << Mode() << "\n";
	std::cout << Range(Numbers) << "\n";
	return 0;
}