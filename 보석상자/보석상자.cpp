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
		int ResultPeople = 0;//��������ϴ� �����
		int Mid = (Min + Max) / 2;
		for (int i = 0; i < jewels.size(); i++) //for���� ���� �������� ������ ���� ���� ������ ������ ���ϴµ�
		{
			ResultPeople += jewels[i] / Mid; // �����ɰ� ������ ������ ������ �ټ��ִ�  ����� ���� ���Ѵ�.
			if (jewels[i] % Mid != 0) // ���� �ȳ��´ٸ� ������ �������� �ʴ´ٴ� ������ �ѻ������ ������ ������ ����ؼ� ++���ش�.
			{
				ResultPeople++;
			}
		}
		if (ResultPeople <= People) // ������� �ϴ� ����� ������ �۴ٸ�  �� �ٿ�
		{
			Answer = Mid;
			Max = Mid - 1;
		}
		else //�� ũ�� �ٽ� �÷�
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