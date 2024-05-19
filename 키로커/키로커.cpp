#include <iostream>
#include <stack>
#include <list>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	//std::stack<char> answer;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::list<char> answer;
		std::list<char>::iterator it = answer.begin();
		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size(); j++)
		{

			if (str[j] >= 'A' && str[j] <= 'Z')
			{
				answer.insert(it, str[j]);
			}
			else if (str[j] >= 'a' && str[j] <= 'z')
			{
				answer.insert(it, str[j]);
			}
			else if (str[j] >= '0' && str[j] <= '9')
			{
				answer.insert(it, str[j]);
			}
			else if (str[j] == '-')
			{
				if (it != answer.begin())
				{
					it--;
					it = answer.erase(it);
				}
			}
			else if(str[j] == '>')
			{
				if (it != answer.end())
				{
					it++;
				}
			}
			else if (str[j] == '<')
			{
				if (it != answer.begin())
				{
					it--;
				}
			}
		} 

		for (auto k : answer)
		{
			std::cout << k;
		}

		std::cout << "\n";
 }

	return 0;
}