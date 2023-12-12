#include <iostream>
#include <string>
int solution(int n)
{
    int answer = 0;
    std::string strn = std::to_string(n);
    for (int i = 0; i < strn.size(); i++)
    {
        int a = strn[i]-'0';
        answer += a;
    }
    return answer;
}
int main()
{
    solution(123);
}