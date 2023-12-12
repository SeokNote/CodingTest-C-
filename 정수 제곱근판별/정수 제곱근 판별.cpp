#include <string>
#include <vector>
#include <cmath>
//sqrt 와 ceil을 사용
long long solution(long long n) {
    long long answer = 0;
    double Num =  std::sqrt(n);
    double Num2 = std::ceil(Num);
    if (Num == Num2)
    {
        answer = (Num + 1) * (Num + 1);
    }
    else
    {
        answer = -1;
    }
    return answer;
}
int main()
{
    solution(121);
    return 0;
}