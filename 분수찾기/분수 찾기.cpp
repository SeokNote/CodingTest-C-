#include <iostream>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> answer;
	int cnt = 0;
	//cnt번 째 칸의 N번 째에 위치해 있어?
	while (N>0)
	{
		cnt++;
		if (cnt >= N)
		{
			break;
		}
		N -= cnt;
	}
	//짝수 칸 일시 위에서 아래로
	if (cnt % 2 != 0)
	{
		for (int y = cnt; y >= 1; y--)
		{
			N--;
			int x = cnt + 1 - y;
			if (N == 0)
			{
				std::cout << y << "/" << x;
			}
		}

	}
	//홀수 칸 일시 아래에서 위로
	else
	{
		for (int x = cnt; x >= 1; x--)
		{
			N--;
			int y = cnt + 1 - x;
			if (N == 0)
			{
				std::cout << y << "/" << x;
			}
		}
	}
	int a = 0;
	return 0;
}