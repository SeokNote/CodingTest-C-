#include <string>
#include <vector>

std::vector<long long> solution(int x, int n) {
    std::vector<long long> answer;
    answer.resize(n);
    answer[0] = x;
    for (int i = 1; i < n; i++)
    {
        answer[i] += answer[i-1]+x;
    }
    return answer;
}