#include <iostream>
#include <algorithm>
#include <vector>
int M = 0;
int N = 0;
std::vector<int> Ms;
std::vector<int> Ns;

void Search_Repeat(int _Search)
{
	int Start = 0;
	int End = M-1;
	while (Start < End+1)
	{
		
		int Mid = (Start + End) / 2;
		if (Ms[Mid] == _Search)
		{
			std::cout << "1\n";
			return;
		}
		else if (Ms[Mid] < _Search)
		{
			Start = Mid + 1;
		}
		else if (Ms[Mid] > _Search)
		{
			End = Mid - 1;
		}
		
	}
	std::cout << "0\n";
	return;
}
int main()
{

	std::cin >> M;
	Ms.reserve(M);
	for (int i = 0; i < M; i++)
	{
		int Num = 0;
		std::cin >> Num;
		Ms.push_back(Num);
	}
	std::sort(Ms.begin(), Ms.end());
	std::cin >> N;
	Ns.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int Num = 0;
		std::cin >> Num;
		Ns.push_back(Num);
	}
	for (int i = 0; i < N; i++)
	{
		Search_Repeat(Ns[i]);
	}
	return 0;
}

