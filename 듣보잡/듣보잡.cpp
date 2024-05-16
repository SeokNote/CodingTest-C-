#include <iostream>
#include <map>
#include <set>
#include <algorithm>
int main()
{
	int N, M;
	std::cin >> N >> M;
	std::set<std::string> answer;
	std::map<std::string, int> map;
	if (N > M)
	{
		for (int i = 0; i < N; i++)
		{
			std::string str = "";
			std::cin >> str;
			map[str] += 1;

		}
		for (int i = 0; i < M; i++)
		{
			std::string str = "";
			std::cin >> str;
			map[str] += 1;
			if (map[str] > 1)
			{
				answer.insert(str);
			}
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			std::string str = "";
			std::cin >> str;
			map[str] += 1;

		}
		for (int i = 0; i < N; i++)
		{
			std::string str = "";
			std::cin >> str;
			map[str] += 1;
			if (map[str] > 1)
			{
				answer.insert(str);
			}
		}
	}
	std::cout << answer.size() << "\n";
	for (auto i : answer)
	{
		std::cout << i << "\n";
	}
	return 0;
}