#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 

int n, m;
int max = 99999999;

std::vector<std::pair<int, std::pair<int, int>>> edges;
long long dist[501]; 

bool bellmanFord(int start) 
{
	dist[start] = 0;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			int Node = edges[j].first;
			int Link = edges[j].second.first;
			int cost = edges[j].second.second;

			if (dist[Node] == 99999999)
			{ 
				continue; 
			}

			if (dist[Link] > dist[Node] + cost)
			{
				dist[Link] = dist[Node] + cost;

				if (i == n)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		int Node, Link, Weight;
		std::cin >> Node >> Link >> Weight;
		edges.push_back({ Node, {Link, Weight} });
	}
	
	for (int i = 0; i < 501; i++)
	{
		dist[i] = 99999999;
	}
	if (bellmanFord(1))
	{
		std::cout << "-1" << "\n";
		return 0;
	}

	for (int i = 2; i <= n; i++) 
	{
		if (dist[i] == 99999999)
		{
			std::cout << "-1\n";
		}
		else 
		{
			std::cout << dist[i] << "\n";
		}
	}

	return 0;
}