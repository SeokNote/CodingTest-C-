#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int, int>> LinkNodes[10]; // 간선정보들
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
		for (int i = 0; i < LinkNodes[curnode].size();i++)
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
	return 0;
}