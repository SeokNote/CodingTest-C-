//���̳��� ���α׷����� ū ������ ���� ������ �������� �� �ְų� ������ �ҽ��ڵ带 �ݺ������� ����� �� ����ϴ� ����̴�
//ž�ٿ�(�޸������̼�) :�� �� ����� ����� �޸� ������ �޸��ϴ� ������� ĳ���̶�� �Ҹ���.
//���Ҿ�(�����) : ���� �ݺ����� ����ϰ� ��� ����� �迭�� DP���̺��̶�� �Ѵ�.
#include <iostream>
//int Result = 0;
//bool Decimal(int _Num) //�Ҽ�����?
//{
//	bool Value = true;
//	if (_Num == 1)
//	{
//		return false;
//	}
//	for (int i = 2; i < _Num; i++)
//	{
//		if (_Num % i == 0)
//		{
//			Value = false;
//			break;
//		}
//	}
//	return Value;
//}
//int Solution(int _Num)
//{
//	int Result = _Num;
//	int Count = 0;
//	while (Result != 1)
//	{
//		if (Decimal(Result) == true && Result > 4)
//		{
//			Result--;
//			Count++;
//		}
//		if (Result % 5 == 0)
//		{
//			Result--;
//			Count++;
//		}
//		if (Result % 3 == 0)
//		{
//			Result /= 3;
//			Count++;
//		}
//		if (Result % 2 == 0)
//		{
//			Result /= 2;
//			Count++;
//		}
//	}
//	return Count;
//}
int DP[1000000] = {};

void Dp_Solution(int _Value)
{
	for (int i = 2; i <= _Value; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		}
	}
}

int main()
{
	int Num = 0;
	DP[1] = 0;
	std::cin >> Num;
	Dp_Solution(Num);
	std::cout << DP[Num];
	return 0;
}