#include<iostream>
#include <vector>
//https://www.acmicpc.net/problem/17143
//R x C
//R�� �� C �� ��
//����ĭ�� ���� �Է�
//rcsdk rxc�� ��ġ�� s�� �ӷ°� d�� ����,c�� ũ��
//0����1���� ��ġ
//2���� �ӷ�
//3���� ���� 
//4���� ũ��
//��������������
std::vector<std::vector<int>> Sharks;
int R, C, N;
void MoveShark()
{
	for (int i = 0; i < Sharks.size(); i++)
	{
		
		Sharks[i][0]; //r
		Sharks[i][1]; //c
		Sharks[i][2]; //�ӷ�
		//������ ���Ʒ���� r���� �ٲ��.
		if (Sharks[i][3] == 2)
		{
			if ((Sharks[i][2] / (R- Sharks[i][0])) / 2 == 0) //�������� ¦�����
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // �������� Ȧ�����.
			{
				Sharks[i][3] = 1; //������ �ٲٰ�
				Sharks[i][0] = R- (Sharks[i][2] % (R - Sharks[i][0]));
			}
			//�Ʒ���
			
		}
		if (Sharks[i][3] == 1)
		{
			if ((Sharks[i][2] / (R - Sharks[i][0])) / 2 == 0) //�������� ¦�����
			{
				Sharks[i][0] += (Sharks[i][2] % (R - Sharks[i][0]));
			}
			else // �������� Ȧ�����.
			{
				Sharks[i][3] = 2; //������ �ٲٰ�
				Sharks[i][0] = R - (Sharks[i][2] % (R - Sharks[i][0]));
			}
		}
		if (Sharks[i][3] == 3)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //�������� ¦�����
			{
				Sharks[i][0] += (Sharks[i][2] % (C - Sharks[i][0]));
			}
			else // �������� Ȧ�����.
			{
				Sharks[i][3] = 4; //������ �ٲٰ�
				Sharks[i][0] = C - (Sharks[i][2] % (C- Sharks[i][0]));
			}
			//�Ʒ���
		}
		if (Sharks[i][3] == 4)
		{
			if ((Sharks[i][2] / (C - Sharks[i][0])) / 2 == 0) //�������� ¦�����
			{
				Sharks[i][0] += (Sharks[i][2] % (C- Sharks[i][0]));
			}
			else // �������� Ȧ�����.
			{
				Sharks[i][3] = 3; //������ �ٲٰ�
				Sharks[i][0] = C - (Sharks[i][2] % (C - Sharks[i][0]));
			}
			//�Ʒ���
		}
		Sharks[i][3]; //����
		Sharks[i][4] = Sharks[i][4]; //ũ��� �״��.
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

	//�ϴ� ���
	for (int i = 1; i <= C; i++)
	{
		int Min = INT32_MAX;
		gachasize = 0;
		for (int j = 0; j < N; j++)
		{
			if (Sharks[j][1] == i) // ���� ����� �ϴ� ���� ���־�
			{
				if (Min < Sharks[j][0]) //�ּڰ� ����
				{
					Min = Sharks[j][0];
					gachasize = Sharks[j][4];
					DeletIndex = j;
				}
			}
			else //������ �н�
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