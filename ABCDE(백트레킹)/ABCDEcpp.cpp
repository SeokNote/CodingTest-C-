#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
std::vector<std::vector<int>> grid;
std::vector<bool> isvisit;
int cnt = 0;
bool isvalue = false;
void dfs(int _startnode , int _cnt)
{
	if (_cnt == 4)
	{
		isvalue = true;
		return;
	}		
	isvisit[_startnode] = true;
	for (int j = 0; j < grid[_startnode].size(); j++)
	{
		int nextnode = grid[_startnode][j];
		if (isvisit[nextnode] == true)
		{
			continue;
		}
		dfs(nextnode, _cnt+1);
		isvisit[nextnode] = false;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	grid.resize(n);
	isvisit.resize(n);

	for (int i = 0; i < m; i++)
	{
		int node, link;
		std::cin >> node >> link;
		grid[node].push_back(link);
		grid[link].push_back(node);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			isvisit[j] = false;
		}
		dfs(i,0);
		if (isvalue == true)
		{
			break;
		}
	}
	std::cout << isvalue;
	return 0;
}

