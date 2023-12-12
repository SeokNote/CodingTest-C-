#include <string>
#include <vector>
#include <iostream>
std::vector<int> Number;
int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            Number.push_back(i);
        }
    }
    for (int i = 0; i < Number.size(); i++)
    {
        answer += Number[i];
    }
    return answer;
}

int main()
{
    std::cout<<solution(12);
}