#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> chou;

bool Check(int n) 
{
	while (1)
	{

	}
}
int main()
{
	int N;
	std::cin >> N;
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> chou[i];
		sum += chou[i];
	}

	for (int i = 1; i < sum; i++)
	{
		if (Check(i) == true)
		{
			answer = i;
			break;
		}
	}
	std::cout << answer;
	return 0;
}