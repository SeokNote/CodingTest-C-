#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;
    int answer = n;
    while (answer >= 1)
    {
        if (answer % 2 == 0)
        {
            answer = answer / 2;
        }
        else
        {
            ans++;
            answer -= 1;
        }
    }

    return ans;
}