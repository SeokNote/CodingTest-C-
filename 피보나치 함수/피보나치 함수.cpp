#include <iostream>
#include <vector>
int DP[41] = { 0 };
int main()
{
    int N;
    std::cin >> N;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 2;
    DP[4] = 3;
    for (int i = 4; i < 41; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }
    for (int i = 1; i <= N; i++)
    {

        int Num;
        std::cin >> Num;
        if (Num == 0)
        {
            std::cout << "1" << " " << "0";
        }
        else
        {
            std::cout << DP[Num - 1] << " " << DP[Num];
        }
        std::cout << "\n";

    }
    return 0;
}