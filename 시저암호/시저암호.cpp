#include <string>
#include <vector>
#include <iostream>
using namespace std;
// char ���� -127 ~ 127 �����̱� ������ int �� �޾Ƽ� ����ؾ���
string solution(string s, int n) {
    string answer = "";
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] <= 'z' && s[i] >= 'a')
        {
            temp = s[i] + n;
            if (temp > 'z')
            {
                s[i] = s[i] - 26 + n;
            }
            else
            {
                s[i] = s[i] + n;
            }
        }
        if (s[i] <= 'Z' && s[i] >= 'A')
        {
            temp = s[i] + n;
            if (temp > 'Z')
            {
                s[i] = s[i] - 26 + n;
            }
            else
            {
                s[i] = s[i] + n;
            }

        }

    }
    answer = s;
    return answer;
}
int main()
{
    std::cout << solution("a B z", 25);
    return 0;
}