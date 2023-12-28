#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//* = 이전과 이번 점수를 2배로 만든다. 이전 점수가 없으면 현재 점수만 2배
//# = 당점시 이 점수를 마이너스한다. 
//*은 중첩이 가능하다.
//#과*이 중첩되면 #의 점수는 2배 마이너스 된 값이 들어간다.
//single double triple 
int solution(string dartResult) {
    int answer = 0;
    int Spos = 0;  int Dpos = 0; int Tpos = 0;
    int S = 0; int D = 0; int T=0;
    int count = 0;
    int j = 0;
    std::vector<int> vec;
    for (int i = 1; i < dartResult.size(); i++)
    {
        j++;
        int Value = dartResult[i - 1] - '0';
        if (0 <= Value && Value<=10)
        {
            count++;
        }
        if (count == 2)
        {
            Value = 10;
        }
        if (dartResult[i] == 'S')
        {
            count = 0;
            Value = pow(Value, 1);
            vec.push_back(Value);
        }
        if (dartResult[i] == 'D')
        {
            count = 0;
            Value = pow(Value, 2);
            vec.push_back(Value);
        }
        if (dartResult[i] == 'T')
        {
            count = 0;
            Value = pow(Value, 3);
            vec.push_back(Value);
        }
        if (dartResult[i] == '#')
        {
            count = 0;
            int Index = j / 2;
            vec[Index - 1] *= -1;
            j--;
        }
        if (dartResult[i] == '*')
        {
            count = 0;
            int Index = j / 2;
            if (Index > 1)
            {
                vec[Index - 1] *= 2;
                vec[Index - 2] *= 2;
            }
            else
            {
                vec[Index - 1] *= 2;
            }
            j--;
        }

    }
    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i];
    }
    return answer;
}
int main()
{
    solution("1S*2D*3T*");
    return 0;
}