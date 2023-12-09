#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

std::vector<int> Nodes[100001];
bool IsVisited[100001];
void BFS(int _StartNode)
{
	std::queue<int> Q;
	Q.push(_StartNode);
	IsVisited[_StartNode] = true;
	while (!Q.empty())
	{
		int A = Q.front();
		Q.pop();
		std::cout << A << "\n";
		for (int i = 0; i < Nodes[A].size(); i++)
		{
			int B = Nodes[A][i];
			if (IsVisited[B] == false)
			{
				Q.push(B);
				IsVisited[B] = true;
			}
		}
	}
	std::cout << "0";
}
int main()
{
	int Vertex = 0;
	int Edges = 0;
	int StartNode = 0;
	std::cin >> Vertex;
	std::cin >> Edges;
	std::cin >> StartNode;

	for (int i = 0; i < Edges; i++)
	{
		int Vertex1, Vertex2;
		std::cin >> Vertex1;
		std::cin >> Vertex2;
		Nodes[Vertex1].push_back(Vertex2);
		Nodes[Vertex2].push_back(Vertex1);

	}
	for (int i = 1; i <= Vertex; i++)
	{
		std::sort(Nodes[i].begin(), Nodes[i].end());
	}
	BFS(StartNode);
}