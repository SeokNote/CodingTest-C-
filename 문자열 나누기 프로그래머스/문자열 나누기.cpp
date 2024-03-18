#include <iostream>
#include <string>
#include <vector>

int solution(std::string s)
{
    int answer = 0;
    int Count = 0;
    int Other = 0;
    char Start = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == Start)
        {
            Count++;
        }
        else
        {
            Other++;
        }
        if (i + 1 == s.size())
        {
            if (Count != Other)
            {
                answer++;
            }
        }
        if (Count == Other)
        {
            Count = 0;
            Other = 0;
            Start = s[i + 1];
            answer++;
        }
    }
    return answer;
}

int main()
{
    std::string str = "";
    std::cin >> str;
    solution(str);
}