//https://www.acmicpc.net/source/77752743
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
int main()
{
	std::stack<std::pair<int, int>> topstack;
	std::vector<int> answer;
	int n;
	std::cin >> n;
	answer.reserve(n);
	topstack.push(std::make_pair(INT32_MAX, 0));
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		std::cin >> num;
		while (topstack.top().first < num && !topstack.empty())
		{
			topstack.pop();
		}
		answer.push_back(topstack.top().second);
		topstack.push(std::make_pair(num, i));
	}
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << " ";
	}
	return 0;
}

