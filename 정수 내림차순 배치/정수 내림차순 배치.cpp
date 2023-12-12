#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
// stoll »ç¿ë
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    std::string strn = std::to_string(n);
    std::vector<int> Numbers;
    std::sort(strn.begin(), strn.end(), greater<>());
    answer = std::stoll(strn);
    return answer;
}
int main()
{
    solution(118372);
}