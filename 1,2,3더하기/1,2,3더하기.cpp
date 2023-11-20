#include <iostream>
#include <vector>
int DP[11] = {};
std::vector<int> Answer;
void Solution()
{
	for (int i = 4; i < 12; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}
}
int main()
{
	int Num = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	Solution();
	std::cin >> Num;
	Answer.resize(Num);
	for (int i = 0; i < Num; i++)
	{
		std::cin >> Answer[i];
	}
	for (int i = 0; i < Answer.size(); i++)
	{
		std::cout << DP[Answer[i]] << "\n";
	}
	return 0;
}