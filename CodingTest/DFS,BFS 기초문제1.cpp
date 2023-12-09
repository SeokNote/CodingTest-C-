#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
//4 5 1
//정점의 갯수, 간선의 갯수, 시작지점


std::vector<int> Lines[10000];
bool DFSVisited[1000];
bool BFSVisited[1000];

void DFS(int _StartNode)
{
	DFSVisited[_StartNode] = true;
	std::cout<< _StartNode << " ";
	for (int i = 0; i < Lines[_StartNode].size(); i++)
	{
		int NextNode = Lines[_StartNode][i];
		if (DFSVisited[NextNode] == false)
		{
			DFS(NextNode);
		}
	}
}
void BFS(int _StartNode)
{
	std::queue<int> Q;
	Q.push(_StartNode);
	BFSVisited[_StartNode] = true;
	while (Q.empty() == false)
	{
		int A = Q.front();
		Q.pop();
		std::cout << A << " ";
		for (int i = 0; i < Lines[A].size(); i++)
		{
			int B = Lines[A][i];
			if (BFSVisited[B] == false)
			{
				Q.push(B);
				BFSVisited[B] = true;
			}
		}
	}
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
		Lines[Vertex1].push_back(Vertex2);
		Lines[Vertex2].push_back(Vertex1);

	}
	for (int i = 1; i <= Vertex; i++) 
	{
		std::sort(Lines[i].begin(), Lines[i].end());
	}
	DFS(StartNode);
	std::cout << "\n";
	BFS(StartNode);

	return 0;
}