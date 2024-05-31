#include <iostream>
#include <vector>
#include <queue>
int main()
{
    int N, W, L;
    std::cin >> N >> W >> L;
    std::queue<int> Trucks;
    std::queue<std::pair<int, int>> Bridge;

    for (int i = 0; i < N; i++)
    {
        int Weight = 0;
        std::cin >> Weight;
        Trucks.push(Weight);
    }
    int Time = 1;
    int SumWeight = 0;
    Bridge.push(std::make_pair(Trucks.front(), Time + W));
    SumWeight += Trucks.front();
    Trucks.pop();
    while (!Trucks.empty())
    {
        Time++;
        if (Bridge.front().second == Time)
        {
            SumWeight -= Bridge.front().first;
            Bridge.pop();
        }

        if (Bridge.size() == W)
        {
            continue;
        }

        if (SumWeight + Trucks.front() > L)
        {
            continue;
        }

        Bridge.push(std::make_pair(Trucks.front(), Time + W));
        SumWeight += Trucks.front();
        Trucks.pop();

        if (Bridge.empty())
        {
            break;
        }
    }
    std::cout << Bridge.back().second;
    return 0;

}