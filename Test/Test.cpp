#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    set<int> answers;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            answers.insert(numbers[i] + numbers[j]);
        }
    }
    for (auto i : answers)
    {
        answer.push_back(i);
    }
    return answer;
}