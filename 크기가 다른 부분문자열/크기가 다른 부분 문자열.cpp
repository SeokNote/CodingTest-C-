#include <string>
#include <vector>
// ������ : �޴� ������ ���̰� 18�����̹Ƿ� int�� �ƴ� long���� ����
// 64��Ʈ �ü�������� int�� 4����Ʈ long�� 8����Ʈ�� ���� �� �ִ�.
using namespace std;
int solution(string t, string p) {
    int Size = p.size();
    int answer = 0;
    long long intp = std::stol(p);
    for (int i = 0; i <= t.size() - Size; i++)
    {
        string Answer = t.substr(i, Size);
        long long Number = std::stol(Answer);
        if (Number <= intp)
        {
            answer++;
        }
    }
    return answer;
}