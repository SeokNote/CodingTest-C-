#include <iostream>
#include <vector>
int main()
{
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> answer;
	int cnt = 0;
	//cnt�� ° ĭ�� N�� °�� ��ġ�� �־�?
	while (N>0)
	{
		cnt++;
		if (cnt >= N)
		{
			break;
		}
		N -= cnt;
	}
	//¦�� ĭ �Ͻ� ������ �Ʒ���
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
	//Ȧ�� ĭ �Ͻ� �Ʒ����� ����
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