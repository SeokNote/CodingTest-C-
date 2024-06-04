#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> Nodes;
std::vector<std::vector<int>> Grid;
std::vector<bool> RootCheck;
int xPos = 0;
void DFS(int _Node, int _level)
{
	if (_Node == -1)
	{
		return;
	}
	DFS(Nodes[_Node].first, _level + 1);
	Grid[_level].push_back(xPos++);
	DFS(Nodes[_Node].second, _level + 1);
}

int main()
{
	int N;
	std::cin >> N;
	Nodes.resize(N + 1);
	Grid.resize(N + 1);
	RootCheck.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		int ParentNode = 0;
		int ChildNode1 = 0;
		int ChildNode2 = 0;
		std::cin >> ParentNode >> ChildNode1 >> ChildNode2;
		Nodes[ParentNode].first = ChildNode1;
		Nodes[ParentNode].second = ChildNode2;
		if (ChildNode1 != -1)
		{
			RootCheck[ChildNode1] = true;
		}
		if (ChildNode2 != -1)
		{
			RootCheck[ChildNode2] = true;
		}
	}
	int Root = 0;
	for (int i = 1; i < RootCheck.size(); i++)
	{
		if (RootCheck[i] == true)
		{
			continue;
		}
		else
		{
			Root = i;
		}
	}
	DFS(Root, 1);
	int Max = 0;
	int Level = 0;

	for (int i = 1; i < Grid.size(); i++)
	{
		if (Grid[i].size() != 0)
		{
			int Len = Grid[i][Grid[i].size() - 1] - Grid[i][0] + 1;
			if (Max < Len)
			{
				Max = Len;
				Level = i;

			}
		}
		else
		{
			continue;
		}
	}

	std::cout << Level << " " << Max;
	return 0;
}