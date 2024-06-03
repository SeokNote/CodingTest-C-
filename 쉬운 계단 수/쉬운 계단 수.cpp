#include <iostream>
//   자릿수  끝수 
int DP[101][10] = { 0 };

int main()
{
	int N;
	int Mod = 1000000000;
	int answer = 0;
	std::cin >> N;
	//첫 자리 수는 1가지 경우 뿐
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
				//뒷 자리가 0인 경우는 1에서 내려오는 경우 뿐
				DP[y][x] = DP[y - 1][x + 1] % Mod;
			}
			else if (x == 9)
			{
				//뒷 자리가 9인 경우는 뒷자리가 8인 경우밖에 못온다.
				DP[y][x] = DP[y - 1][x - 1] % Mod;
			}
			else
			{
				//나머지는 위에서 내려오거나 밑에서 올라오거나 할 수 있다
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