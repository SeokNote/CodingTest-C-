//https://school.programmers.co.kr/learn/courses/30/lessons/42883
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    std::string answer;

    int Index = -1;

    for (int i = 0; i < number.size() - k; ++i)
    {
        char Max = 0;
        //앞에 k개 만큼 검사하고 큰값을 따로 저장
        for (int j = Index + 1; j <= i + k; ++j)
        {
            if (Max < number[j])
            {
                Max = number[j];
                Index = j;
            }
        }

        answer.push_back(Max);
    }

    return answer;
}