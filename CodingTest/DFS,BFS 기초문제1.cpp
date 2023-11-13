#include <iostream>
#include <vector>
#include <set>
#include <queue>
//4 5 1
//정점의 갯수, 간선의 갯수, 시작지점

std::queue<int> Nodes;

std::vector<int> Lines[10000];
bool Visited[1000];

void DFS(int _StartNode)
{
	std::cout<< _StartNode << " ";
	Visited[_StartNode] = true;
	for (int i = 0; i < Lines[_StartNode].size(); i++)
	{
		int NextNode = Lines[_StartNode][i];
		if (Visited[NextNode] == false)
		{
			DFS(NextNode);
		}
	}
}
//void BFS(int _StartNode)
//{
//	//std::cout << _StartNode << " ";
//	Nodes.push(_StartNode);
//	Visited[_StartNode] = true;
//	for (int i = 0; i < Lines[_StartNode].size(); i++)
//	{
//		Nodes.push(Lines[_StartNode][i]);
//		Visited[Lines[_StartNode][i]] = true;
//
//	}
//
//}
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
	DFS(StartNode);
	return 0;
}