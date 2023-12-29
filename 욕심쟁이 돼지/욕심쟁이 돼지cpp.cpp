#include <iostream>
#include <vector>
int main()
{
	int N = 0;
	int Allfood = 0;
	int Pigs = 6;
	int SumFoods = 0;
	int Days = 0;
	int Value = 0;
	std::vector<int> vec;
	std::cin >> N;
	vec.reserve(N);
	std::vector<int> foods(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Allfood;
		foods[i]=Allfood;
		SumFoods = 0;
		for (int j = 0; j < Pigs; j++)
		{
			int food = 0;
			std::cin >> food;
			SumFoods += food;
		}

		vec.push_back(SumFoods);
	}
	for (int i = 0; i < N; i++)
	{
		Value = vec[i];
		if (Value > foods[i])
		{
			std::cout << 1 << "\n";
		}
		else
		{
			Days = 1;
			while (Value <= foods[i])
			{
				Days++;
				Value = Value * 4;

			}
			std::cout << Days << "\n";

		}
	}
	return 0;
}
