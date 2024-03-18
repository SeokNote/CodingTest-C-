#include <iostream>
#include <vector>
#include <algorithm>
int N;
int answer = 0;
std::vector<int> ans;
std::vector<int> vec;

int main() 
{
	std::cin >> N;
	ans.resize(N);
	vec.resize(N);
	
	std::string str1 = "";
	std::string str2 = "";
	std::cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++)
	{
		vec[i] = str1[i] - '0';
	}
	for (int i = 0; i < str2.size(); i++)
	{
		ans[i] = str2[i] - '0';
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if ((i - 1) >= 0 && vec[i - 1] == 1)
		{
			vec[i - 1] = 0;
		}
		else if ((i - 1) >= 0 && vec[i - 1] == 0)
		{
			vec[i - 1] = 1;
		}

		if (vec[i] == 1)
		{
			vec[i] = 0;
		}
		else if (vec[i] == 0)
		{
			vec[i] = 1;
		}

		if ((i + 1) < vec.size() && vec[i + 1] == 1)
		{
			vec[i + 1] = 0;
		}
		else if ((i + 1) < vec.size() && vec[i + 1] == 0)
		{
			vec[i + 1] = 1;
		}

		if (vec == ans)
		{
			answer = i + 1;
			break;
		}
	}
	std::cout << answer;

	return 0;
}