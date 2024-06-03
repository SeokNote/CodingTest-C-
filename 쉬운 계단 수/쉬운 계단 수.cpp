#include <iostream>
//   �ڸ���  ���� 
int DP[101][10] = { 0 };

int main()
{
	int N;
	int Mod = 1000000000;
	int answer = 0;
	std::cin >> N;
	//ù �ڸ� ���� 1���� ��� ��
	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}

	for (int y = 2; y < 101; y++)
	{
		for (int x = 0; x <= 9; x++)
		{
			if (x == 0)
			{
				//�� �ڸ��� 0�� ���� 1���� �������� ��� ��
				DP[y][x] = DP[y - 1][x + 1] % Mod;
			}
			else if (x == 9)
			{
				//�� �ڸ��� 9�� ���� ���ڸ��� 8�� ���ۿ� ���´�.
				DP[y][x] = DP[y - 1][x - 1] % Mod;
			}
			else
			{
				//�������� ������ �������ų� �ؿ��� �ö���ų� �� �� �ִ�
				DP[y][x] = (DP[y - 1][x - 1] % Mod + DP[y - 1][x + 1] % Mod) % Mod;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		answer += DP[N][i] % Mod;
		answer %= Mod;
	}
	std::cout << answer;
	return 0;
}