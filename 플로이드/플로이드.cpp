//플로이드 와샬
//최댓값 설정 주의
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
		for (int j = 0; j < dist.size(); j++) //출발지 
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
	cost.resize(N + 1);
	int min = INT32_MAX;
	std::vector<int> ans;
	for (int i = 0; i < cost.size(); i++)
	{
		cost[i].resize(N + 1, 10000001);
	}

	for (int i = 0; i < cost.size(); i++)
	{
		cost[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int city, link, dt;
		std::cin >> city >> link >> dt;
		if (cost[city][link] > dt)
		{
			cost[city][link] = dt;
		}
	}

	std::vector<std::vector<int>> dist = FW();
	for (int i = 1; i < dist.size(); i++)
	{
		int sum = 0;
		for (int j = 1; j < dist[i].size(); j++)
		{
			if (dist[i][j] == 10000001)
			{
				std::cout << "0" << " ";
			}
			else
			{
				std::cout << dist[i][j] << " ";
			}
		}
		std::cout << "\n";

	}

	return 0;
}