#include <iostream>
#include <vector>
#include <string>
std::vector<char> Inequalitys;
std::vector<bool> IsVisit;
std::vector<bool> CopyVisit;
std::vector<int> numbers;
int k;
std::string max = "0";
std::string min = "99999999";
bool checknum(int a, int b, char c)
{
	if (c == '<')
	{
		if (a < b)
		{
			return true;
		}
	}
	else
	{
		if (a > b)
		{
			return true;
		}
	}
	return false;
}

void dfs(int _number, int _cnt)
{
	if (_cnt == k)
	{
		std::string str = "";
		for (int i = 0; i < _cnt+1; i++)
		{
			str += std::to_string(numbers[i]);
		}
		max = std::max(max, str);
		min = std::min(min, str);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (IsVisit[i] == true)
		{
			continue;
		}

		if (checknum(_number, i, Inequalitys[_cnt]) == true)
		{
			IsVisit[i] = true;
			numbers.push_back(i);
			dfs(i, _cnt+1);
			IsVisit[i] = false;
			numbers.pop_back();
		}

	}
}

int main()
{
	std::cin >> k;
	Inequalitys.resize(k+1);
	IsVisit.resize(10, false);
	CopyVisit.resize(10, false);
	for (int i = 0; i < k; i++)
	{
		std::cin >> Inequalitys[i];
	}
	for (int i = 0; i <= 9; i++)
	{
		IsVisit = CopyVisit;
		IsVisit[i] = true;
		numbers.clear();
		numbers.push_back(i);
		dfs(i, 0);
	}
	std::cout << max << "\n";
	std::cout << min << "\n";
	return 0;
}