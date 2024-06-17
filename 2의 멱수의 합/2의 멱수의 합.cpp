#include <iostream>
#include <cmath>
#include <vector>
//100만이면 2의 20승
std::vector<int> DP;
int mod = 1000000000;
int main()
{
	int N;
	std::cin >> N;
    DP.resize(N+1);
    DP[0] = 1;
    for (int i = 1; i < N; i++)
    {
        int pow = std::pow(2, i);
        for (int j = pow; j <= N; j++)
        {
            DP[j] = (DP[j] + DP[j - pow])% mod;
        }
    }
    int max = 0;
    for (int i = 0; i <= N; i++)
    {
        max = std::max(max,DP[i]);
    }
    std::cout << max;
    return 0;
}