#include <iostream>
#include <vector>
int main()
{
	int N;
	int answer = 0;
	std::cin >> N;
	std::string check = "";
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		std::string str = "";
		if (i == 0)
		{
			std::cin >> check;
		}
		else
		{
			std::cin >> str;
			for (int j = 0; j < check.size(); j++)
			{
				size_t place = str.find(check[j]);
				if (std::string::npos != place)
				{
					str[place] = '0';
				}
				else
				{
					continue;
				}
			}
			for (int t = 0; t < str.size(); t++)
			{
				if (str[t] == '0')
				{
					cnt++;
				}
			}
			if (str.size() - cnt < 2 && check.size() - cnt < 2)
			{
				answer++;
			}
		}

	}
	std::cout << answer;
	return 0;
}
