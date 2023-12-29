#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
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