#include <iostream>
#include <vector>
int main()
{
	int N, K;
	std::cin >> N >> K;
	std::string str = "";
	std::cin >> str;
	int answer = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'P')
		{
			for (int j = -K; j <= K; j++)
			{
				if (i - j <= 0 && i + j>str.size())
				{
					continue;
				}
				if (str[i + j] == 'H')
				{
					str[i + j] = '0';
					answer++;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			continue;
		}
	}
	std::cout << answer;
	return 0;
}