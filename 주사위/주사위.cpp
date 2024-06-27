#include <iostream>
#include <algorithm>

long long Dice[6] = { 0 };

int main()
{

	long long N;
	std::cin >> N;
	long long answer = 0;
	for (int i = 0; i < 6; i++)
	{
		std::cin >> Dice[i];
	}
	if (N == 1)
	{
		std::sort(Dice, Dice + 6);
		for (int i = 0; i < 6; i++)
		{
			answer += Dice[i];
		}
		answer -= Dice[5];
		std::cout << answer;

	}
	else
	{
		long long Min[3];
		//�ô�� ���� ���� �ϳ��� ���ϼ� �����Ƿ� �� �ô�� ���� �ּҰ� ���Ѵ�. 
		Min[0] = std::min(Dice[0], Dice[5]);
		Min[1] = std::min(Dice[1], Dice[4]);
		Min[2] = std::min(Dice[2], Dice[3]);
		std::sort(Min, Min + 3);
		long long Num1 = Min[0];
		long long Num2 = Min[0] + Min[1];
		long long Num3 = Min[0] + Min[1] + Min[2];
		//3���� ����Ǵ� �ֻ����� ������ ������ 4��
		answer = (Num3 * 4) + (Num2 * ((N - 2) * 8 + 4)) + (Num1 * ((N - 2) * (N - 2) * 5 + (N - 2) * 4));
		std::cout << answer;
		
	}

	return 0;


}