#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(char i, char j)
{
    return j < i;
}
string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), compare);
    for (size_t i = 0; i < s.size(); i++)
    {
        answer += s[i];
    }
    return answer;
}