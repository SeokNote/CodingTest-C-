//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <set>
//bfs
////////////////////////////////
//bool IsVisited[101] = { false };
//std::vector<std::set<int>> LinkNodes; 
//int N, M;
//int answer = 0;
//int sum = 0;
//std::vector<int> ans;
//void BFS(int _StartNode)
//{
//	std::vector<int> cost(N+1,-1);
//	std::queue<int> q;
//	cost[_StartNode] = 0;
//	q.push(_StartNode);
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		for (auto i : LinkNodes[cur])
//		{
//			if (cost[i] != -1)
//			{
//				continue;
//			}
//			cost[i] = cost[cur] + 1;
//			q.push(i);
//		}
//	}
//
//	for (int i = 1; i < cost.size(); i++)
//	{
//		sum += cost[i];
//	}
//}
//
//int main()
//{
//	std::cin >> N >> M;
//	LinkNodes.resize(N + 1);
//	ans.reserve(N + 1);
//	int Min = INT32_MAX;
//	for (int i = 1; i <= M; i++)
//	{
//		int a, b;
//		std::cin >> a >> b;
//		LinkNodes[a].insert(b);
//		LinkNodes[b].insert(a);
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		sum = 0;
//		BFS(i);
//		ans.push_back(sum);
//	}
//
//	int answer = 9999999;
//
//	for (int i = 0; i < ans.size(); i++)
//	{
//		if (Min > ans[i])
//		{
//			Min = ans[i];
//			answer = i+1;
//		}
//	}
//	std::cout << answer;
//
//	return 0;
//}

//플로이드 와샬
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

int N, M;
int INF = 10000000;
std::vector<std::vector<int>> cost;
std::vector<std::vector<int>> FW()
{
	std::vector<std::vector<int>> dist = cost;

	for (int i = 0; i < dist.size(); i++) // 경유지
	{
		for(int j = 0; j< dist.size();j++) //출발지 
		{
			for (int t = 0; t < dist.size(); t++) // 도착지
			{
				dist[j][t] = std::min(dist[j][t], dist[j][i] + dist[i][t]);
			}
		}
	}
	return dist;
}

int main()
{

	std::cin >> N >> M;
	cost.resize(N+1);
	int min = INT32_MAX;
	std::vector<int> ans;
	for (int i = 0; i < cost.size(); i++)
	{
		cost[i].resize(N+1, 10000000);
	}

	for (int i = 0; i < cost.size(); i++)
	{
		cost[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		cost[a][b] = 1;
		cost[b][a] = 1;
	}

	std::vector<std::vector<int>> dist =FW();
	for (int i = 1; i < dist.size(); i++)
	{
		int sum = 0;
		for (int j = 1; j < dist[i].size(); j++)
		{
			sum += dist[i][j];
		}
		ans.push_back(sum);
	}
	int answer = 9999999;

	for (int i = 0; i < ans.size(); i++)
	{
		if (min > ans[i])
		{
			min = ans[i];
			answer = i+1;
		}
	}

	std::cout << answer;
	return 0;
}