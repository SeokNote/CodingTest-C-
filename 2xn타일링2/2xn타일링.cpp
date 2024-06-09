#include<iostream>
int DP[10001];

int main()
{
    int Num = 0;
    std::cin >> Num;

    DP[1] = 1;
    DP[0] = 1;
    for (int i = 2; i <= Num; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 2]) % 10007;

    }
    std::cout << DP[Num];
    return 0;
}