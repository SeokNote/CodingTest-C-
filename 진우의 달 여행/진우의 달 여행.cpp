#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int N, M;
    int DP[1001][1001][3] = {};
    std::cin >> N >> M;
    std::vector<std::vector<int>> grid(N,std::vector<int>(M,0));
    int answer = INT32_MAX;
    //fill_n(변경하려는 원소의 범위 시작주소, 변경하려는 원소 갯수, 변경 값)
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            for (int i = 0; i < 3; i++)
            {
                DP[y][x][i] = INT32_MAX;
            }
        }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cin >> grid[y][x];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            DP[0][i][j] = grid[0][i];
        }
    }
    for (int y = 1; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (x > 0)
            {
                DP[y][x][0] = std::min(DP[y-1][x-1][1], DP[y-1][x-1][2]) + grid[y][x];
            }
            DP[y][x][1] = std::min(DP[y-1][x][0], DP[y-1][x][2]) + grid[y][x];
            if (x+1 < M)
            {
                DP[y][x][2] = std::min(DP[y-1][x+1][1], DP[y-1][x+1][0]) + grid[y][x];
            }
        }
    }

        for (int x = 0; x < M; x++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (DP[N-1][x][i] == INT32_MAX)
                {
                    continue;
                }
                else
                {
                    answer = std::min(answer, DP[N-1][x][i]);
                }

            }
        }
  
    std::cout << answer;
    return 0;
}