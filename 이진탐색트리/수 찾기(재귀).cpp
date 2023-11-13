//#include <iostream>
//#include <algorithm>
//#include <vector>
//std::vector<int> Ms;
//std::vector<int> Ns;
//void Recursion_Search(std::vector<int> _M, std::vector<int> _N,int _Start ,int _End,int _Search)
//{
//	int Mid = (_Start + _End) / 2;
//	if (_M[Mid] == Ns[_Search])
//	{
//		std::cout << "1\n";
//		return;
//	}
//	if (_Start - _End == -1)
//	{
//		if (_M[_Start] == Ns[_Search])
//		{
//			std::cout << "1\n";
//			return;
//		}
//		else if (_M[_End] == Ns[_Search])
//		{
//			std::cout << "1\n";
//			return;
//		}
//		std::cout << "0\n";
//		return;
//	}
//	else if (_M[Mid] < Ns[_Search])
//	{
//		Recursion_Search(_M, _N, Mid + 1, _End, _Search);
//	}
//	else if (_M[Mid] > Ns[_Search])
//	{
//		Recursion_Search(_M, _N, _Start, Mid - 1, _Search);
//	}
//
//}
//int main()
//{
//	int M = 0;
//	int N = 0;
//	std::cin >> M;
//	Ms.reserve(M);
//	for (int i = 0; i < M; i++)
//	{
//		int Num = 0;
//		std::cin >> Num;
//		Ms.push_back(Num);
//	}
//	std::sort(Ms.begin(), Ms.end());
//	std::cin >> N;
//	Ns.reserve(N);
//	for (int i = 0; i < N; i++)
//	{
//		int Num = 0;
//		std::cin >> Num;
//		Ns.push_back(Num);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		Recursion_Search(Ms, Ns, 0, M-1, i);
//	}
//	return 0;
//}