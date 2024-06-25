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
    for (int i = 1; i <= N; i*=2)
    {
        for (int j = i; j <= N; j++)
        {
            DP[j] = (DP[j] % mod + DP[j - i] % mod)% mod;
        }
    }
    std::cout << DP[N];
    return 0;
}