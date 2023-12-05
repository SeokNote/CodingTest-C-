#include<iostream>
int DP[10000];
int main()
{
    int Num = 0;
    std::cin >> Num;

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= Num; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;

    }
    std::cout << DP[Num];
    return 0;
}