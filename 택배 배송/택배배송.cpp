#include <iostream>
#include <vector>
#include <queue>
std::vector<std::vector<std::pair<int, int>>> LinkNodes; // 간선정보들
std::vector<int> dist;
void dijkstra(int startNode)
{
	dist[startNode] = 0;
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(startNode, 0));
	while (!pq.empty())
	{
		int curnode = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (dist[curnode] < distance)
		{
			continue;
		}
		for (int i = 0; i < LinkNodes[curnode].size(); i++)
		{
			int nextnode = LinkNodes[curnode][i].first;
			int nextdist = distance + LinkNodes[curnode][i].second;
			if (nextdist < dist[nextnode])
			{
				dist[nextnode] = nextdist;
				pq.push(std::make_pair(nextnode, -nextdist));
			}
		}
	}
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	LinkNodes.resize(N+1);
	dist.resize(N + 1);
	//기본적으로 비용을 큰값으로 초기화
	for (int i = 0; i < dist.size(); i++)
	{
		dist[i] = INT32_MAX;
	}
	for (int i = 0; i < M; i++)
	{
		int node, linknode, weight;
		std::cin >> node>> linknode>> weight;
		LinkNodes[node].push_back(std::make_pair(linknode, weight));
		LinkNodes[linknode].push_back(std::make_pair(node, weight));

	}

	dijkstra(1);
	std::cout << dist[N];
	return 0;
}