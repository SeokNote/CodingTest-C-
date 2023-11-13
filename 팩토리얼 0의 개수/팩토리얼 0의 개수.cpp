//#include <cmath>
//#include <iostream>
//int Num = 0;
//int Answer = 0;
//int Factorial(int _num)
//{
//	int Result = 1;
//	for (int i = _num; i > 0; i--)
//	{
//		Result = Result * i;
//	}
//	return Result;
//}
//void fail_Solution(int _Num)
//{
//
//	if (_Num % 5 == 0)
//	{
//		
//		double A = std::log10(_Num) / std::log10(5);
//		A = std::floor(A + 0.5);
//		double Pow = std::pow(5, static_cast<int>(A));
//		if (_Num == static_cast<int>(Pow))
//		{
//			Answer = -1;
//			return;
//		}
//		else
//		{
//			double A = std::log10(_Num) / std::log10(5);
//
//				Answer = (_Num - static_cast<int>(A)) * 5;
//			
//
//
//			return;
//		}
//	}
//	else 
//	{
//		double A = std::log10(_Num) / std::log10(5);
//
//		Answer = (_Num - static_cast<int>(A)) * 5;
//
//
//		return;
//	}
//	
//}
//int main()
//{
//	while (true)
//	{
//		std::cin >> Num;
//		fail_Solution(Num);
//		std::cout << Answer << std::endl;
//	}
//
//	return 0;
//}