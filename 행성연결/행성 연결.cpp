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

    int N = 0;
    cin >> N;

    Parent.resize(N + 1);

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            int Weight = 0;
            cin >> Weight;
            if (y < x)
            {
                Flows.push_back({ { y, x }, Weight });
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        Parent[i] = i;
    }

    sort(Flows.begin(), Flows.end(), Compair);

    long long Result = 0;
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
        }
    }

    cout << Result << '\n';

    return 0;
}
[출처] [C++] 백준(16398) 행성연결 | 작성자 난너무슬프다