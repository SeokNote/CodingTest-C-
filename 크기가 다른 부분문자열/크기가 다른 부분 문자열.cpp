#include <string>
#include <vector>
// 주의점 : 받는 숫자의 길이가 18까지이므로 int가 아닌 long으로 받자
// 64비트 운영체제에서의 int는 4바이트 long은 8바이트를 담을 수 있다.
using namespace std;
int solution(string t, string p) {
    int Size = p.size();
    int answer = 0;
    long long intp = std::stol(p);
    for (int i = 0; i <= t.size() - Size; i++)
    {
        string Answer = t.substr(i, Size);
        long long Number = std::stol(Answer);
        if (Number <= intp)
        {
            answer++;
        }
    }
    return answer;
}