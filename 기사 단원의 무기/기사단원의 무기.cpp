#include <string>
#include <vector>

using namespace std;
//���� �ڽ��� ��ȣ�� ����� ������ ���ݷ��� ���� ���⸦ �����Ѵ�.
//��ġ�� ����� ������ ���Ѽ�ġ���� Ŀ�� ��쿡�� ���������� �� ���ݷ��� ����� limit
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