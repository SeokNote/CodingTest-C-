#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num; // num을 long long 타입으로 변경

    while (number != 1) {
        if (answer == 500) { // 작업을 500번 반복한 경우
            answer = -1;
            break;
        }

        else { // 작업횟수가 500번 미만인 경우
            if (number % 2 == 0) { // 짝수인 경우
                number = number / 2;
                answer++;
            }
            else { // 홀수인 경우
                number = (number * 3) + 1;
                answer++;
            }
        }
    }
    return answer;
}
int main()
{
    std::cout << solution(626331);
    return 0;
}
