#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> scores;
    scores.reserve(k);
    for (int i = 0; i < score.size(); i++)
    {
        if (scores.size() < k)
        {
            scores.push_back(score[i]);
            std::sort(scores.begin(), scores.end(), greater<int>());
            answer.push_back(scores[scores.size() - 1]);
        }
        else
        {
            if (score[i] > scores[k - 1])
            {
                scores.pop_back();
                scores.push_back(score[i]);
                std::sort(scores.begin(), scores.end(), greater<int>());
                answer.push_back(scores[k - 1]);

            }
            else
            {
                std::sort(scores.begin(), scores.end(), greater<int>());
                answer.push_back(scores[k - 1]);
            }
        }
    }
    return answer;
}
int main()
{
    solution(4, { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 });
    return 0;
}