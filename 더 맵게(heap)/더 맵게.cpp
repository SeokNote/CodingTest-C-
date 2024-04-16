#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    std::priority_queue<int, std::vector<int>, std::greater<int>> Queue;

    for (int i = 0; i < scoville.size(); ++i)
    {
        Queue.push(scoville[i]);
    }

    while (Queue.top() < K)
    {
        if (1 == Queue.size())
        {
            answer = -1;
            return answer;
        }
        if (scoville.size() == 0)
        {
            answer = -1;
            return answer;
        }
        int MinLow = Queue.top();
        Queue.pop();

        int SecondLow = Queue.top();
        Queue.pop();

        Queue.push(MinLow + (SecondLow * 2));

        ++answer;
    }

    return answer;
}