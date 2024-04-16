#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = INT64_MAX;

    long long Start = 1;
    long long End = 1e18;

    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        long long PassCount = 0;

        for (int i = 0; i < times.size(); ++i)
        {
            PassCount += Mid / times[i];
        }

        if (PassCount >= n)
        {
            answer = std::min(answer, Mid);
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }

    return answer;
}