#include <string>
#include <vector>
#include <cmath>
using namespace std;
std::vector<int> vec;
void Threejin(int n, int b)
{
    if (n / b == 0)
    {
        vec.push_back(n % b);
    }
    else
    {
        vec.push_back(n % b);
        Threejin(n / b, b);
    }
}
int solution(int n)
{
    int answer = 0;
    Threejin(n, 3);
    int Num = vec.size() - 1;
    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i] * std::pow(3, Num);
        Num--;
    }

    return answer;
}
int main()
{
    solution(45);
    return 0;
}