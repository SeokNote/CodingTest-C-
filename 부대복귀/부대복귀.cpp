#include <iostream>
#include <string>
#include <vector>
#include <queue>
std::vector<std::vector<std::pair<int, int>>> LinkNodes; // ����������
std::vector<int> dist;
//���������κ��� ��� ����� ���� ��� ���ϱ�
void dijkstra(int startNode)
{
	//���� ���������� �������� ����� 0
	dist[startNode] = 0;
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(startNode, 0));
	while (!pq.empty())
	{
		//ó���� ���������� ����
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
	//�⺻������ ����� ū������ �ʱ�ȭ
	for (int i = 0; i < dist.size(); i++)
	{
		dist[i] = 999999;
	}
	for (int i = 0; i < roads.size(); i++)
	{
		int weight = 1;
		//LinkNodes[���][����ȳ��][����ġ] �Է¹ޱ�
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