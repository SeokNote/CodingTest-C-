#include <iostream>
#include <vector>
#include <algorithm>
//홀수번째 인덱스는 높이르 뺀 값을 넣어준다
//이분탐색을 하면서 내 값보다 큰 값이 나오면 count를 새준다.
//count가 제일 적은 값이 답
int Answer = 0;

std::vector<int> Heights;
std::vector<int> Answers;

void Solution(int _Max)
{
	
	//while (Min <= Max)
	//{
	//	int Count = 0;
	//	int Mid = (Min + Max) / 2;
	//	for (int i = 0; i < Heights.size(); i++)
	//	{
	//		if (Heights[i] > Mid)
	//		{
	//			Count++;
	//		}
	//	}
	//}

	for (int i = 1; i < _Max; i++)
	{
		int Count = 0;
		for (int j = 0; j < Heights.size(); j++)
		{
			if (Heights[i] > j)
			{
				Count++;
			}
		}	
		Answers.push_back(Count);
	}
}
int main()
{
	int Leight = 0;
	int Height = 0;

	std::cin >> Leight;
	std::cin >> Height;
	Heights.reserve(Leight);
	for (int i = 0; i < Leight; i++)
	{
		int Num = 0;
		
		std::cin >> Num;
		if (i % 2 == 0)
		{
			Heights.push_back(Num);
		}
		else
		{
			Heights.push_back(Height - Num);
		}

	}
	Solution(Leight);
	std::sort(Answers.begin(), Answers.end());
	std::cout << Answers[0];
	return 0;
}