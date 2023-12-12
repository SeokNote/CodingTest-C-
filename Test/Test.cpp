#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num; // num�� long long Ÿ������ ����

    while (number != 1) {
        if (answer == 500) { // �۾��� 500�� �ݺ��� ���
            answer = -1;
            break;
        }

        else { // �۾�Ƚ���� 500�� �̸��� ���
            if (number % 2 == 0) { // ¦���� ���
                number = number / 2;
                answer++;
            }
            else { // Ȧ���� ���
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
