#include <iostream>
#include <cmath>
#include <vector>
//1¾ï¹üÀ§
int main()
{
    int N, M;
    std::cin >> N >> M;
    int answer = 0;
    int Game = N - M;
    double Z = (double)M / (double)N;
    Z *= 100.0f;
    for (int i = 1; i <= Game; i++)
    {
        double NewZ = (double)(M+i) / (double)(N+i);
        if (std::floor(Z) != std::floor(NewZ))
        {
            answer = i;
            break;
        }
    }
    if (N == M)
    {
        answer = -1;
    }

    std::cout << answer;
    return 0;
}