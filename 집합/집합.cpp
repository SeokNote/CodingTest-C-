#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int M;
	std::cin >> M;
	//	std::vector<int> answer;
	std::set<int> sets = { 0 };
	std::set<int> reset = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	std::set<int> clearset = { 0 };
	//	int cnt = 0;
	//	answer.resize(M);
	for (int i = 0; i < M; i++)
	{

		std::string oper = "";
		int num = 0;
		std::cin >> oper;
		if (oper == "add")
		{
			std::cin >> num;
			if (sets.find(num) == sets.end())
			{
				sets.insert(num);
			}
			else
			{
				continue;
			}
		}
		else if (oper == "remove")
		{
			std::cin >> num;
			if (sets.find(num) != sets.end())
			{
				sets.erase(num);
			}
			else
			{
				continue;
			}
		}
		else if (oper == "check")
		{

			std::cin >> num;
			if (sets.find(num) != sets.end())
			{
				std::cout << "1" << "\n";
			}
			else
			{
				std::cout << "0" << "\n";
			}
		}
		else if (oper == "toggle")
		{
			std::cin >> num;
			if (sets.find(num) != sets.end())
			{
				sets.erase(num);
			}
			else
			{
				sets.insert(num);
			}
		}
		else if (oper == "all")
		{
			sets = reset;
		}
		else
		{
			sets = clearset;
		}
	}
	//for (int i = 0; i < cnt; i++)
	//{
	//	std::cout << answer[i]<<"\n";
	//}

	return 0;

}