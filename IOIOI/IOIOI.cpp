#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	int answer = 0;
	std::string str = "";
	std::string str1 = "I";
	int num = 0;
	std::string str3 = "";
	std::cin >> N >> M;
	std::cin >> str;
	for (int i = 0; i < N; i++)
	{
		str1 += "O";
		str1 += "I";
	}
	int size = str.size();
	bool value = false;
	for (int i = 0; i < size - N; i++)
	{
		if (str[i] != 'I')
		{
			continue;
		}
		else
		{
			while (str[i + 1] == 'O' && str[i + 2] == 'I')
			{
				num++;
				if (num == N)
				{
					num--;
					answer++;
				}
				i += 2;
			}
			num = 0;
		}
	}
	std::cout << answer;
	return 0;
}
