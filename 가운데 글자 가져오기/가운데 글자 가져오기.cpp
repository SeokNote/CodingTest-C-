#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int Number = s.size();
    if (Number % 2 == 0)
    {
        answer = s[Number / 2 - 1];
        answer += s[Number / 2];
    }
    else
    {
        answer = s[Number / 2];
    }
    return answer;
}
int main()
{
    solution("abcde");
    return 0;
}