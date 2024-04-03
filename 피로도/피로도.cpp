#include <iostream>
#include <vector>
#include<cstring>

using namespace std;
std::vector<std::vector<int>> Lines;
bool IsVisited[8] = { false };
int cnt;

void DFS(int _StartNode, int _pirodo)
{
	IsVisited[_StartNode] = true;
	for (int i = 0; i < Lines.size(); i++)
	{
		if (IsVisited[i] == false && _pirodo >= Lines[i][0])
		{
			cnt++;
			DFS(i, _pirodo - Lines[i][1]);
		}
	}
}

int solution(int k, vector<vector<int>> dungeons)
{
	Lines = dungeons;
	int answer = -1;
	for (int i = 0; i < dungeons.size(); i++)
	{
		cnt = 1;
		memset(IsVisited, false, sizeof(IsVisited));
		DFS(i, k - dungeons[i][1]);
		if (answer < cnt)
		{
			answer = cnt;
		}
	}


	return answer;
}
int main()
{
	solution(80, { {80,20},{50,40},{30,10} });
	return 0;
}