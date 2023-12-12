#include <string>
#include <vector>

int solution(std::string s) {
    int answer = 0;
    if (s[0] == '-')
    {
        std::string Str = s.substr(1, s.size());
        answer = std::stoi(Str);
        return -answer;
    }
    else
    {
        answer = std::stoi(s);
        return answer;
    }
}