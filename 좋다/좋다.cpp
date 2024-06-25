#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Nums;

int main()
{
	int N;
	int answer = 0;
	std::cin >> N;
	Nums.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int Num = 0;
		std::cin >> Num;
		Nums.push_back(Num);
	}

	std::sort(Nums.begin(), Nums.end());

	for (int i = 0; i < N; i++)
	{
		int checknum = Nums[i];
		int Left = 0;
		int Right = N - 1;
		while (Left < Right)
		{
			int Lenght = Nums[Left] + Nums[Right];
			if (i == Left)
			{
				Left++;
				continue;
			}
			if (i == Right)
			{
				Right--;
				continue;
			}
			if (checknum == Nums[Left] + Nums[Right])
			{
				answer++;
				break;
			}
			else if (checknum > Lenght)
			{
				Left++;
			}
			else if (checknum < Lenght)
			{
				Right--;
			}

		}

	}
	std::cout << answer;
	return 0;

}