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
	// 가로등 사이의 빛이 다 들어야 하는 경우의 수 
	for (int i = 0; i < Num-1; i++)
	{
		PrevHeight = Height;
		Height = ((Locations[i+1] - Locations[i]) + 1) / 2; //반올림하기위한 +1
		if (PrevHeight > Height)
		{
			Height = PrevHeight;
		}

	}
	// 처음 가로등과 끝 가로등이 길의 시작과 끝을 완전히 비추는지.
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