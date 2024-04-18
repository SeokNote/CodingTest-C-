#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> Flows;
vector<int> Parent;

bool Compair(pair<pair<int, int>, int> _Left, pair<pair<int, int>, int> _Right)
{
    if (_Left.second == _Right.second)
    {
        return _Left.first.first < _Left.first.first;
    }
    else
    {
        return _Left.second < _Right.second;
    }
}

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
    _From = Find_Parent(_From);
    _To = Find_Parent(_To);

    if (_From > _To)
    {
        Parent[_From] = _To;
    }
    else
    {
        Parent[_To] = _From;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int House = 0;
        int HouseLink = 0;
        int dist = 0;
        std::cin >> House >> HouseLink >> dist;
        Flows.push_back({ { House, HouseLink }, dist });
    }

    Parent.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        Parent[i] = i;
    }

    sort(Flows.begin(), Flows.end(), Compair);

    long long Result = 0;
    int lastweight = 0;
    for (size_t i = 0; i < Flows.size(); i++)
    {
        int From = Flows[i].first.first;
        int To = Flows[i].first.second;
        int From_Parent = Parent[From];
        int To_Parent = Parent[To];

        int Weight = Flows[i].second;

        if (Find_Parent(From_Parent) != Find_Parent(To_Parent))
        {
            Union_Parent(From_Parent, To_Parent);
            Result += Weight;
            lastweight = Weight;
        }
    }

    cout << Result -lastweight  << '\n';
    return 0;
}