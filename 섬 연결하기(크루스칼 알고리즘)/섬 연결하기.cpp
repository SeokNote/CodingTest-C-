//https://school.programmers.co.kr/learn/courses/30/lessons/42861
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> Graph;
vector<int> Parent;

int Find_Parent(int _Value)
{
	if (Parent[_Value] != _Value)
	{
		Parent[_Value] = Find_Parent(Parent[_Value]);
	}

	return Parent[_Value];
}

void Union_Parent(int _From, int _To)
{
	int From_Parent = Find_Parent(_From);
	int To_Parent = Find_Parent(_To);

	if (From_Parent > To_Parent)
	{
		Parent[From_Parent] = To_Parent;
	}
	else
	{
		Parent[To_Parent] = From_Parent;
	}
}


int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;

	Parent.resize(n + 1);

	for (size_t i = 0; i < costs.size(); i++)
	{
		int From = costs[i][0];
		int To = costs[i][1];
		int Weight = costs[i][2];
		Graph.push_back({ { From, To }, Weight });
	}

	for (int i = 0; i < Parent.size(); i++)
	{
		Parent[i] = i;
	}

	sort(Graph.begin(), Graph.end(), [=](const pair<pair<int, int>, int>& _Left, const pair<pair<int, int>, int>& _Right)
		{
			return _Left.second < _Right.second;
		});

	for (size_t i = 0; i < Graph.size(); i++)
	{
		int From = Graph[i].first.first;
		int To = Graph[i].first.second;
		int From_Parent = Parent[From];
		int To_Parent = Parent[To];
		int Weight = Graph[i].second;

		if (Find_Parent(From_Parent) != Find_Parent(To_Parent))
		{
			Union_Parent(From_Parent, To_Parent);
			answer += Weight;
		}
	}

	return answer;
}
