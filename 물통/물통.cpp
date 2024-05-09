#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
int A = 0;
int B = 0;
int C = 0;
int maxa, maxb, maxc;
std::set<int> answer;
std::pair<int, int> Abottle;
std::pair<int, int> Bbottle;
std::pair<int, int> Cbottle;
bool IsVisit[201][201][201] = { false };

// n에서 m로 붇기
std::pair<std::pair<int, int>, std::pair<int, int>> PourNtoM(std::pair<int, int> n, std::pair<int, int> m)
{
	int curm = m.first;
	if (m.first + n.first >= m.second)
	{
		m.first = m.second;
		n.first -= m.second - curm;
	}
	else
	{
		m.first += n.first;
		n.first = 0;
	}

	return std::make_pair(n, m);
}

void DFS(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c)
{

	if (a.first == 0)
	{
		answer.insert(c.first);
	}
	IsVisit[a.first][b.first][c.first] = true;

	//어떤 짓을 해서 6가지 경우의 수를 리턴하는 배열을 만듬
	std::vector<std::vector<std::pair<int, int>>> AllCase;
	AllCase.resize(6);
	for (size_t i = 0; i < 6; i++)
	{
		AllCase[i].resize(3);
	}
	//A B, A C, B A, B C, C A, C B
	std::pair<std::pair<int, int>, std::pair<int, int>> Result = PourNtoM(a, b);
	AllCase[0][0] = Result.first;
	AllCase[0][1] = Result.second;
	AllCase[0][2] = c;
	Result = PourNtoM(a, c);
	AllCase[1][0] = Result.first;
	AllCase[1][1] = b;
	AllCase[1][2] = Result.second;
	Result = PourNtoM(b, a);
	AllCase[2][0] = Result.second;
	AllCase[2][1] = Result.first;
	AllCase[2][2] = c;
	Result = PourNtoM(b, c);
	AllCase[3][0] = a;
	AllCase[3][1] = Result.first;
	AllCase[3][2] = Result.second;
	Result = PourNtoM(c, a);
	AllCase[4][0] = Result.second;
	AllCase[4][1] = b;
	AllCase[4][2] = Result.first;
	Result = PourNtoM(c, b);
	AllCase[5][0] = a;
	AllCase[5][1] = Result.second;
	AllCase[5][2] = Result.first;

	for (size_t i = 0; i < 6; i++)
	{
		if (IsVisit[AllCase[i][0].first][AllCase[i][1].first][AllCase[i][2].first] == true)
		{
			continue;
		}

		DFS(AllCase[i][0], AllCase[i][1], AllCase[i][2]);
	}
}
int main()
{
	std::cin >> maxa >> maxb >> maxc;
	C = maxc;
	Abottle.first = A;
	Abottle.second = maxa;
	Bbottle.first = B;
	Bbottle.second = maxb;
	Cbottle.first = C;
	Cbottle.second = maxc;
	DFS(Abottle, Bbottle, Cbottle);
	for (auto i : answer)
	{
		std::cout << i << " ";
	}
	return 0;
}

