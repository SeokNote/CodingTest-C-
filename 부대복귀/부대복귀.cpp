#include <iostream>
#include <string>
#include <vector>
#include <queue>
std::vector<std::vector<std::pair<int, int>>> LinkNodes; // 간선정보들
std::vector<int> dist;
//도착점으로부터 모든 점들로 가는 비용 구하기
void dijkstra(int startNode)
{
	//현재 도착점에서 도착점은 비용이 0
	dist[startNode] = 0;
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(startNode, 0));
	while (!pq.empty())
	{
		//처음은 도착점에서 시작
		int curnode = pq.top().first;
		//
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
std::vector<int> solution(int n, std::vector<std::vector<int>> roads, std::vector<int> sources, int destination) {
	std::vector<int> answer;
	LinkNodes.resize(n+1);
	dist.resize(n + 1);
	//기본적으로 비용을 큰값으로 초기화
	for (int i = 0; i < dist.size(); i++)
	{
		dist[i] = 999999;
	}
	for (int i = 0; i < roads.size(); i++)
	{
		int weight = 1;
		//LinkNodes[노드][연결된노드][가중치] 입력받기
		LinkNodes[roads[i][0]].push_back(std::make_pair(roads[i][1], weight));
		LinkNodes[roads[i][1]].push_back(std::make_pair(roads[i][0], weight));

	}
	dijkstra(destination);
	for (int i = 0; i < sources.size(); i++)
	{
		for (int j = 0; j < dist.size(); j++)
		{
			if (sources[i] == j)
			{
				if (dist[j] == 999999)
				{
					answer.push_back(-1);
				}
				else
				{
					answer.push_back(dist[j]);
				}
			}
		}
	}
	return answer;
}
int main()
{
	solution(5, { {1, 2},{1, 4},{2, 4},{2, 5},{4, 5} }, {1,3,5}, 5);
	return 0;
}