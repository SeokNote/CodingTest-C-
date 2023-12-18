#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int Num = 0;
bool compare(string _left, string _right)
{
    if (_left[Num] == _right[Num])
    {
        for (int i = 0; i < _left.size(); i++)
        {
            if (_left[i] == _right[i])
            {
                continue;
            }
            return _left[i] < _right[i];
        }
    }
    return _left[Num] < _right[Num];
}
vector<string> solution(vector<string> strings, int n) {
    Num = n;
    vector<string> answer = strings;
    std::sort(answer.begin(), answer.end(), compare);

    return answer;
}