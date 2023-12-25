#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool compare(std::pair<int, double> _left, std::pair<int, double> _right)
{
    if (_left.second == _right.second)
    {
        return _left.first < _right.first;
    }
    return _left.second > _right.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> percents;
    int Count = 0;
    int Number = 0;
    int size = stages.size();
    int people = 0;
    for (int i = 1; i <= N; i++)
    {
        people = size - Count;
        Number = 0;
        for (int j = 0; j < size; j++)
        {
            if (stages[j] == i)
            {
                Count++;
                Number++;
            }
            else
            {
                continue;
            }
        }
        if (Number == 0)
        {
            percents.push_back(pair<int, double>(i, 0.0f));
        }
        else
        {
            double percent = static_cast<double>(Number) / static_cast<double>(people);
            percents.push_back(pair<int, double>(i, percent));
        }
    }
    std::sort(percents.begin(), percents.end(), compare);
    for (int i = 0; i < percents.size(); i++)
    {
        answer.push_back(percents[i].first);
    }
    return answer;
}
int main()
{
    solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
    return 0;
}