#include <iostream>
#include <vector>

int DP[1001] = { 0 };
std::vector<int> Numbers;
int main()
{
    int N;
    std::cin >> N;
    Numbers.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        std::cin >> Numbers[i];
    }
    DP[1] = 1;
    int CheckNum = Numbers[1];
    for (int i = 2; i <= N; i++)
    {
        if (Numbers[i] > CheckNum)
        {
            DP[i] = DP[i - 1] + 1;
        }
        else
        {
            DP[i] = DP[i - 1];
        }
        CheckNum = Numbers[i];

    }
    std::cout << DP[N];
    return 0;
}