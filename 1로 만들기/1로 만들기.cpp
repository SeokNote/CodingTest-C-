//다이나믹 프로그래밍은 큰 문제를 작은 문제로 나누어줄 수 있거나 동일한 소스코드를 반복적으로 사용할 때 사용하는 방식이다
//탑다운(메모이제이션) :한 번 계산한 결과를 메모리 공간에 메모하는 기법으로 캐싱이라고도 불린다.
//보텀업(상향식) : 보통 반복문을 사용하고 결과 저장용 배열을 DP테이블이라고도 한다.
#include <iostream>
//int Result = 0;
//bool Decimal(int _Num) //소수인지?
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