#include <string>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<std::vector<int>> copygrid;
std::vector<std::vector<int>> grid1;
vector<int> answer;

void spin(int x1, int y1, int x2, int y2)
{
    int min = 9999999;
    grid1 = copygrid;
    for (int i = x1; i <= x2; i++)
    {

        for (int j = y1; j <= y2; j++)
        {
            if (i > x1 && i<x2 && j>y1 && j < y2)
            {
                continue;
            }
            else
            {
                if (i == x1)
                {
                    if (j + 1 > y2)
                    {
                        copygrid[i + 1][j] = grid1[i][j];
                    }
                    else
                    {
                        copygrid[i][j + 1] = grid1[i][j];
                    }
                }
                else if (i == x2)
                {
                    if (j == y1)
                    {
                        copygrid[i - 1][j] = grid1[i][j];
                    }
                    else
                    {
                        copygrid[i][j - 1] = grid1[i][j];
                    }
                }
                else
                {
                    if (j == y1)
                    {
                        copygrid[i - 1][j] = grid1[i][j];
                    }
                    else
                    {
                        copygrid[i + 1][j] = grid1[i][j];
                    }
                }
                min = std::min(min, grid1[i][j]);
            }
        }

    }
    answer.push_back(min);
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int cnt = 0;
    copygrid.resize(rows);
    grid1.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            copygrid[i].push_back(++cnt);
            grid1[i].push_back(cnt);
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        spin(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
    }
    return answer;
}