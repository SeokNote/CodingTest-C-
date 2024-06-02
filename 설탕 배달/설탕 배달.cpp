#include <iostream>
#include <vector>

int main()
{
	int N;
	int answer = 0;
	std::cin >> N;
	int Bag1 = 3;
	int Bag2 = 5;
	if (N < 3)
	{
		answer = -1;
		std::cout << answer;
		return 0;
	}
	if (N == 4)
	{
		answer = -1;
		std::cout << answer;
		return 0;
	}
	if (N == 7)
	{
		answer = -1;
		std::cout << answer;
		return 0;
	}
	int Num = N % Bag2;
	//5·Î³ª´« ¸òÀÌ 3À¸·Î ³ª´©¾î ¶³¾îÁú ¶§
	if (Num == 0)
	{
		answer += N / Bag2;
	}
	else if (Num == 1)
	{
		answer = N / Bag2 + 1;
	}
	else if (Num == 2 || Num == 4)
	{
		answer = N / Bag2 + 2;
	}
	else if (Num == 3)
	{
		answer += N / Bag2;
		answer += (N % Bag2) / Bag1;
	}
	std::cout << answer;
	return 0;
}