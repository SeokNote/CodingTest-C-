#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
std::vector<std::pair<int, int>> homeworks;
bool Isvisit[1001] = { false };
std::vector<int> answers;
bool compare(std::pair<int, int>& a, std::pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first > b.first;
	}
	else
	{
		return a.second > b.second;
	}
}
int main()
{
	int n;
	std::cin >> n;
	homeworks.reserve(n);
	answers.reserve(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int day, score;
		std::cin >> day >> score;
		homeworks.push_back(std::make_pair(day, score));

	}
	std::sort(homeworks.begin(), homeworks.end(), compare);
	for (int i = 0; i < n; i++)
	{
		for (int j = homeworks[i].first; j > 0; j--)
		{
			if (Isvisit[j] == true)
			{
				continue;
			}
			else
			{
				answers.push_back(homeworks[i].second);
				Isvisit[j] = true;
				break;
			}
		}
	}
	for (int i = 0; i < answers.size(); i++)
	{
		answer += answers[i];
	}
	std::cout << answer;
	return 0;

}

