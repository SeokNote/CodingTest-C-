#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> jewels;
int People = 0;
int Colors = 0;
int Num = 0;
int Answer = 0;
void Solution()
{
	int Min = 1;
	int Max = jewels[jewels.size() - 1];
	while (Min<= Max)
	{
		int ResultPeople = 0;//나눠줘야하는 사람수
		int Mid = (Min + Max) / 2;
		for (int i = 0; i < jewels.size(); i++) //for문을 돌며 질투심의 갯수와 벡터 내의 사탕의 갯수를 비교하는데
		{
			ResultPeople += jewels[i] / Mid; // 질투심과 사탕의 갯수를 나눠서 줄수있는  사람의 수를 더한다.
			if (jewels[i] % Mid != 0) // 몫이 안나온다면 나누어 떨어지지 않는다는 것으로 한사람에게 나머지 사탕을 줘야해서 ++해준다.
			{
				ResultPeople++;
			}
		}
		if (ResultPeople <= People) // 나눠줘야 하는 사람의 수보다 작다면  더 줄여
		{
			Answer = Mid;
			Max = Mid - 1;
		}
		else //더 크면 다시 올려
		{
			Min = Mid + 1;
		}
	}
	return;
}
int main()
{
	std::cin >> People;
	std::cin >> Colors;
	jewels.reserve(Colors);
	for (int i = 0; i < Colors; i++)
	{
		int jewel = 0;
		std::cin >> jewel;
		jewels.push_back(jewel);

	}
	std::sort(jewels.begin(), jewels.end());
	Solution();
	std::cout << Answer;
	return 0;
}