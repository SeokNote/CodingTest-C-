#include <iostream>
#include <vector>
#include <string>

bool IsVisit[51] = { false };
std::string Nums = "";
std::vector<int> answer;
int N = 0;
void BT(int _len)
{
	if (_len == Nums.size())
	{
		for (int i = 0; i < answer.size(); i++)
		{
			std::cout << answer[i] << " ";
		}
		exit(0);
	}
	std::string CheckStr = "";
	for (int i = 0; i < 2; i++)
	{
		CheckStr += Nums[_len + i];
		if (N < std::stoi(CheckStr))
		{
			continue;
		}
		if (IsVisit[std::stoi(CheckStr)] == false)
		{
			answer.push_back(std::stoi(CheckStr));
			IsVisit[std::stoi(CheckStr)] = true;
			BT(_len + CheckStr.size());
			IsVisit[std::stoi(CheckStr)] = false;
			answer.pop_back();
		}
	}
}

int main()
{
	std::cin >> Nums;
	if (Nums.size() < 10)
	{
		N = Nums.size();
	}
	else
	{
		N = 9 + (Nums.size() - 9)/2;
	}

	BT(0);

	return 0;
}