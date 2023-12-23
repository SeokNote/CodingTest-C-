#include <string>
#include <vector>

using namespace std;
int bincola = 0;
int cola = 0;
int sum = 0;
void Answer(int a, int b, int n)
{
    if (n != 1 && n >= a)
    {
        cola = (n / a) * b;
        cola += n % a;
        sum += (n / a) * b;
    }
    else
    {
        return;
    }
    Answer(a, b, cola);
}
int solution(int a, int b, int n) {
    int answer = 0;
    Answer(a, b, n);
    answer = sum;
    return answer;
}