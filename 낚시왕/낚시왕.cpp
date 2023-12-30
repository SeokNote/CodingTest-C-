#include<iostream>
#include <vector>
//https://www.acmicpc.net/problem/17143
//R x C
//R은 행 C 는 열
//격자칸과 상어수 입력
//rcsdk rxc의 위치에 s의 속력과 d의 방향,c의 크기
//0번과1번은 위치
//2번은 속력
//3번은 방향 
//4번은 크기
//ㅈㅈㅈㅈㅈㅈㅈ
std::vector<std::vector<int>> Sharks;
int R, C, N;
void MoveShark()
{
	for (int i = 0; i < Sharks.size(); i++)
	{
		
		Sharks[i][0]; //r
		Sharks[i][1]; //c
		Sharks[i][2]; //속력
		//방향이 위아래라면 r값만 바뀐다.
		if (Sharks[i][3] == 2)
		{
			if ((Sharks[i][2] / (R- Sharks[i][0])) / 2 == 0) //나머지가 짝수라면
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // 나머지가 홀수라면.
			{
				Sharks[i][3] = 1; //방향을 바꾸고
				Sharks[i][0] = R- (Sharks[i][2] % (R - Sharks[i][0]));
			}
			//아래로
			
		}
		if (Sharks[i][3] == 1)
		{
			if ((Sharks[i][2] / (R - Sharks[i][0])) / 2 == 0) //나머지가 짝수라면
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // 나머지가 홀수라면.
			{
				Sharks[i][3] = 2; //방향을 바꾸고
				Sharks[i][0] = R - (Sharks[i][2] % (R - Sharks[i][0]));
			}
		}
		if (Sharks[i][3] == 3)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //나머지가 짝수라면
			{
				Sharks[i][0] += (Sharks[i][2] % (C - Sharks[i][0]));
			}
			else // 나머지가 홀수라면.
			{
				Sharks[i][3] = 4; //방향을 바꾸고
				Sharks[i][0] = C - (Sharks[i][2] % (C- Sharks[i][0]));
			}
			//아래로
		}
		if (Sharks[i][3] == 4)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //나머지가 짝수라면
			{
				Sharks[i][0] += (Sharks[i][2] % (C- Sharks[i][0]));
			}
			else // 나머지가 홀수라면.
			{
				Sharks[i][3] = 3; //방향을 바꾸고
				Sharks[i][0] = C - (Sharks[i][2] % (C - Sharks[i][0]));
			}
			//아래로
		}
		Sharks[i][3]; //방향
		Sharks[i][4] = Sharks[i][4]; //크기는 그대로.
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

	//일단 잡아
	for (int i = 1; i <= C; i++)
	{
		int Min = INT32_MAX;
		gachasize = 0;
		for (int j = 0; j < N; j++)
		{
			if (Sharks[j][1] == i) // 내가 잡고자 하는 열에 상어가있어
			{
				if (Min < Sharks[j][0]) //최솟값 갱신
				{
					Min = Sharks[j][0];
					gachasize = Sharks[j][4];
					DeletIndex = j;
				}
			}
			else //없으면 패스
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