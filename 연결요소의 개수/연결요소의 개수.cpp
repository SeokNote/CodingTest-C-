#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> LinkNode;
std::vector<bool> IsVisit;
void dfs(int a)
{
	IsVisit[a] = true;
	for (int i = 0; i < LinkNode[a].size(); i++)
	{
		int curnode = LinkNode[a][i];
		if (IsVisit[curnode] == true)
		{
			continue;
		}
		dfs(curnode);
	}
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	LinkNode.resize(N + 1);
	IsVisit.resize(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		LinkNode[a].push_back(b);
		LinkNode[b].push_back(a);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (IsVisit[i] == true)
		{
			continue;
		}
		dfs(i);
		answer++;
	}
	std::cout << answer;
	return 0;
}

