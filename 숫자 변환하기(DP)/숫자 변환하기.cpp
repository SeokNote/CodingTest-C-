#include <iostream>

int DP[1000001] = {};
//x는 목적 ,y는 출발,n은 뺴는값.
int solution(int x, int y, int n)
{
	int answer = 0;
	for (int i = 0; i < 1000001; i++)
	{
		DP[i] = 999999;
	}
	DP[y] = 0;
	for (int i = y; i >= x; i--)
	{
		if (DP[i] != 999999)
		{
			if (i % 3 == 0)
			{
				DP[i / 3] = std::min(DP[i] + 1, DP[i / 3]);
			}
			if (i % 2 == 0)
			{
				DP[i / 2] = std::min(DP[i] + 1, DP[i / 2]);
			}
			if (i - n > 0)
			{
				DP[i - n] = std::min(DP[i] + 1, DP[i - n]);
			}
		}
	}
	if (DP[x] == 999999)
	{
		DP[x] = -1;
	}
	answer = DP[x];
	return answer;
}