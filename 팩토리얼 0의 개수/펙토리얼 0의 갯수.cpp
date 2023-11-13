#include <iostream>
int Result = 0;
void Solution(int _Num)
{
	int Min = 1;
	int Max = 400000015;
	bool IsFind = false;
	while (Min <= Max)
	{
		int Count = 0;
		int Mid = (Min + Max) / 2;
		for (int i = 5; i <= Mid; i *= 5) // 5의 배수로 나누기
		{
			Count += (Mid / i);
		}
		if (Count >= _Num) //왼쪽으로
		{
			if (Count == _Num)
			{
				IsFind = true;
				Result = Mid;
			}
			Max = Mid - 1;
		}
		else
		{
			Min = Mid + 1;
		}
		

	}
	if (IsFind == false)
	{
		Result = -1;
		return;
	}
	else
	{
		return;
	}
}

int main()
{

	int Num;
	std::cin >> Num;
	Solution(Num);
	std::cout << Result;

	return 0;
}