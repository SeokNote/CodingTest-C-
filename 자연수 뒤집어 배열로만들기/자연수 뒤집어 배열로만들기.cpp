#include <string>
#include <vector>

std::vector<int> solution(long long n) {
    std::vector<int> answer;
    std::string strn = std::to_string(n);
    for (int i = strn.size() - 1; i >= 0; i--)
    {
        int Num = strn[i] - '0';
        answer.push_back(Num);
    }
    return answer;
}