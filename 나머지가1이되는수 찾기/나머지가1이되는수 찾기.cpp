#include <string>
#include <vector>
#include <algorithm>
//�������� 1�̵Ǵ� ���� ���� �ڿ���.
std::vector<int> Num;
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 1)
        {
            Num.push_back(i);
        }
    }

    std::sort(Num.begin(), Num.end());
    answer = Num[0];
    return answer;
}