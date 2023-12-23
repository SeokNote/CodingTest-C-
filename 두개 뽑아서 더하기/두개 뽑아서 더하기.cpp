#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/////////SET을 이용한 풀이 /////////////
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
/////////////unique///////////////
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int result = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            result = numbers[i] + numbers[j];
            answer.push_back(result);
            result = 0;
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}