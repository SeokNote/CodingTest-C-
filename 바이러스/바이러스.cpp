#include <iostream>
#include <vector>
#include <set>

std::vector<std::set<int>> LinkNode;
bool IsVisit[101] = { false };
int answer = 0;
void DFS(int _StartNode)
{
	IsVisit[_StartNode] = true;
	for (auto i : LinkNode[_StartNode])
	{
		if (IsVisit[i] == true)
		{
			continue;
		}
		answer++;
		DFS(i);
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	LinkNode.resize(N);
	for (int i = 0; i < M; i++)
	{
		int Node = 0;
		int Link = 0;
		std::cin >> Node >> Link;
		LinkNode[Node - 1].insert(Link - 1);
		LinkNode[Link - 1].insert(Node - 1);
	}
	DFS(0);
	std::cout << answer;
	return 0;

}

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::string> Grid;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int BFS()
{
	std::pair<int, int> StartPos = { 0,0 };
	std::pair<int, int> EndPos = { M - 1,N - 1 };

	std::queue<std::pair<int, int>> q;
	Grid[StartPos.second][StartPos.first] = '0';
	q.push(StartPos);

	std::vector<std::vector<int>> Depth;

	Depth.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Depth[i].resize(M, -1);
	}

	Depth[StartPos.second][StartPos.first] = 1;

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		Grid[CurPos.second][CurPos.first] = '0';
		q.pop();

		if (CurPos == EndPos)
		{
			return Depth[EndPos.second][EndPos.first];
		}

		for (size_t i = 0; i < 4; i++)
		{
			int CheckX = CurPos.first + dx[i];
			int CheckY = CurPos.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == '0')
			{
				continue;
			}

			Depth[CheckY][CheckX] = Depth[CurPos.second][CurPos.first] + 1;
			q.push({ CheckX, CheckY });
		}
	}

	return Depth[EndPos.second][EndPos.first];
}

int main()
{
	std::cin >> N >> M;
	Grid.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Grid[i];
	}

	int Answer = BFS();
	return 0;
}