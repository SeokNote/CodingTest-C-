#include <string>
#include <vector>

using namespace std;
//기사는 자신의 번호의 약수의 갯수의 공격력을 갖는 무기를 구매한다.
//그치만 약수의 개수가 제한수치보다 커진 경우에는 협약기관에서 준 공격력을 사용함 limit
int solution(int number, int limit, int power)
{
    int Count = 1;
    int Sum = 0;
    for (int i = 1; i <= number; i++)
    {
        Count = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                Count++;
            }
        }
        if (Count <= limit)
        {
            Sum += Count;
        }
        else
        {
            Sum += power;
        }
    }
    int answer = 0;
    answer = Sum;
    return answer;
}