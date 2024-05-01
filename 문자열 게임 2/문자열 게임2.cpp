#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		int shortnum = 10001;
		int longnum = 0;
		std::vector<int> answer;
		std::vector<std::vector<int>> strs;
		answer.reserve(T);
		std::string str;
		std::cin >> str;
		std::cin >> n;
		strs.resize(26);

		for (int j = 0; j < str.size(); j++)
		{
			strs[str[j] - 'a'].push_back(j+1);
		}
		for (int j = 0; j < strs.size(); j++)
		{
			
			for (int t = 0; t < strs[j].size(); t++)
			{
				if (strs[j].size() < n)
				{
					continue;
				}
				if (t + n-1 < strs[j].size())
				{
					int num = strs[j][t + n - 1] - strs[j][t] + 1;
					shortnum = std::min(shortnum, num);
					longnum = std::max(longnum, num);
				}
			}
			
		}
		if (shortnum == 10001)
		{
			answer.push_back(-1);
		}
		else
		{
			answer.push_back(shortnum);
			answer.push_back(longnum);
		}
		for (int y = 0; y < answer.size(); y++)
		{
			std::cout << answer[y] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
