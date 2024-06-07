#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> Nums;
int DP[10001] = { 0 };

int main() {

    int N, K;

    std::cin >> N >> K;
    Nums.resize(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> Nums[i];
    }

    DP[0] = 1;

    //DP[10] = DP[9] + DP[8] + DP[5]
    //DP[9] = DP[8] +DP[7] +DP[4]
    for (int i = 0; i < Nums.size(); i++)
    {
        for (int j = Nums[i]; j <= K; j++)
        {
            DP[j] = DP[j] + DP[j - Nums[i]];
        }
    }

    std::cout << DP[K] << "\n";

    return 0;
}