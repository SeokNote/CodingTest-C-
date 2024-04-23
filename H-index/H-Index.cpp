//https://school.programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    std::sort(citations.begin(), citations.end(), std::greater<int>());
    int cnt;
    for (int j = 0; j < citations.size(); j++)
    {
        if (j + 1 <= citations[j])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    answer = cnt;

    return answer;
}