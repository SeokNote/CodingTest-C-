#include<iostream>
#include <vector>
//https://www.acmicpc.net/problem/17143
//R x C
//R精 楳 C 澗 伸
//維切牒引 雌嬢呪 脊径
//rcsdk rxc税 是帖拭 s税 紗径引 d税 号狽,c税 滴奄
//0腰引1腰精 是帖
//2腰精 紗径
//3腰精 号狽 
//4腰精 滴奄
//じじじじじじじ
std::vector<std::vector<int>> Sharks;
int R, C, N;
void MoveShark()
{
	for (int i = 0; i < Sharks.size(); i++)
	{
		
		Sharks[i][0]; //r
		Sharks[i][1]; //c
		Sharks[i][2]; //紗径
		//号狽戚 是焼掘虞檎 r葵幻 郊駕陥.
		if (Sharks[i][3] == 2)
		{
			if ((Sharks[i][2] / (R- Sharks[i][0])) / 2 == 0) //蟹袴走亜 側呪虞檎
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // 蟹袴走亜 筈呪虞檎.
			{
				Sharks[i][3] = 1; //号狽聖 郊荷壱
				Sharks[i][0] = R- (Sharks[i][2] % (R - Sharks[i][0]));
			}
			//焼掘稽
			
		}
		if (Sharks[i][3] == 1)
		{
			if ((Sharks[i][2] / (R - Sharks[i][0])) / 2 == 0) //蟹袴走亜 側呪虞檎
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // 蟹袴走亜 筈呪虞檎.
			{
				Sharks[i][3] = 2; //号狽聖 郊荷壱
				Sharks[i][0] = R - (Sharks[i][2] % (R - Sharks[i][0]));
			}
		}
		if (Sharks[i][3] == 3)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //蟹袴走亜 側呪虞檎
			{
				Sharks[i][0] += (Sharks[i][2] % (C - Sharks[i][0]));
			}
			else // 蟹袴走亜 筈呪虞檎.
			{
				Sharks[i][3] = 4; //号狽聖 郊荷壱
				Sharks[i][0] = C - (Sharks[i][2] % (C- Sharks[i][0]));
			}
			//焼掘稽
		}
		if (Sharks[i][3] == 4)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //蟹袴走亜 側呪虞檎
			{
				Sharks[i][0] += (Sharks[i][2] % (C- Sharks[i][0]));
			}
			else // 蟹袴走亜 筈呪虞檎.
			{
				Sharks[i][3] = 3; //号狽聖 郊荷壱
				Sharks[i][0] = C - (Sharks[i][2] % (C - Sharks[i][0]));
			}
			//焼掘稽
		}
		Sharks[i][3]; //号狽
		Sharks[i][4] = Sharks[i][4]; //滴奄澗 益企稽.
	}
}
int main()
{
	int gacha = 0;
	int gachasize = 0;
	int DeletIndex = 0;
	std::vector<int> SharkInfo;
	SharkInfo.reserve(5);
	std::cin >> R >> C >> N;
	Sharks.reserve(N);
	for (int i = 0; i < N; i++)
	{
		SharkInfo.clear();
		for (int j = 0; j < 5; j++)
		{
			int Info = 0;
			std::cin >> Info;
			SharkInfo.push_back(Info);
		}
		Sharks.push_back(SharkInfo);
	}

	//析舘 説焼
	for (int i = 1; i <= C; i++)
	{
		int Min = INT32_MAX;
		gachasize = 0;
		for (int j = 0; j < N; j++)
		{
			if (Sharks[j][1] == i) // 鎧亜 説壱切 馬澗 伸拭 雌嬢亜赤嬢
			{
				if (Min < Sharks[j][0]) //置借葵 飴重
				{
					Min = Sharks[j][0];
					gachasize = Sharks[j][4];
					DeletIndex = j;
				}
			}
			else //蒸生檎 鳶什
			{
				gachasize = 0;
			}
		}
		gacha += gachasize;
		Sharks.erase(Sharks.begin() + DeletIndex);
		MoveShark();
	}
	return 0;
}