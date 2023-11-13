#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> Locations;
std::vector<int> Answer;
int length = 0;
int Num = 0;
int PrevHeight = 0;
int Height = 0;
void Solution()
{
	// ���ε� ������ ���� �� ���� �ϴ� ����� �� 
	for (int i = 0; i < Num-1; i++)
	{
		PrevHeight = Height;
		Height = ((Locations[i+1] - Locations[i]) + 1) / 2; //�ݿø��ϱ����� +1
		if (PrevHeight > Height)
		{
			Height = PrevHeight;
		}

	}
	// ó�� ���ε�� �� ���ε��� ���� ���۰� ���� ������ ���ߴ���.
	if ((Locations[0] - 0) > Height)
	{
		Height = Locations[0] - 0;
	}
	if ((length - Locations[Num - 1]) > Height)
	{
		Height = (length - Locations[Num - 1]);
	}
	return;

}
int main()
{
	std::cin >> length;
	std::cin >> Num;
	Locations.reserve(Num);
	for (int i = 0; i < Num; i++)
	{
		int Location = 0;
		std::cin >> Location;
		Locations.push_back(Location);
	}
	Solution();
	std::cout << Height;
	return 0;

}