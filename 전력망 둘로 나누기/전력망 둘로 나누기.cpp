#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
std::vector<std::vector<int>> Nodes;
bool IsVisited[101];
std::vector<int> Answers;
int count = 0;
void DFS(int _StartNode, std::vector<std::vector<int>> _Nodes) //1로 시작
{
	IsVisited[_StartNode] = true;
	count++;
	for (int i = 0; i < _Nodes[_StartNode].size(); i++)
	{
		int NextNode = _Nodes[_StartNode][i];
		if (IsVisited[NextNode] == false)
		{
			DFS(NextNode, _Nodes);
		}
	}
}
int solution(int n, std::vector<std::vector<int>> wires) // 갯수와 송전탑들 입력받아
{
	int answer = -1;
	int Min = INT32_MAX;
	// 총 9개의 노드
	for (int i = 0; i < n - 1; i++)
	{

		Nodes.clear();
		Nodes.resize(n + 1);
		std::memset(IsVisited, false, sizeof(IsVisited));
		count = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (i == j)
			{
				continue;
			}
			Nodes[wires[j][0]].push_back(wires[j][1]);
			Nodes[wires[j][1]].push_back(wires[j][0]);
		}
		DFS(1, Nodes);
		int Num1 = count;
		int Num2 = abs(n - count);

		int result = abs(Num1 - Num2);
		if (result < Min)
		{
			Min = result;
		}
	}


	answer = Min;
	return answer;
}
