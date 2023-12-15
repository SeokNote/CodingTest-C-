#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int Sum = 0;
    std::sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++)
    {
        if (Sum <= budget)
        {
            Sum += d[i];
            answer++;
            if (Sum > budget)
            {
                answer--;
            }
        }

    }
    return answer;
}