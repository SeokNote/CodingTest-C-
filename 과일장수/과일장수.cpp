#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int size = score.size() / m;
    std::vector<int> AppleBox;
    AppleBox.reserve(size);
    std::sort(score.begin(), score.end(), greater<int>());
    for (int i = 0; i < size; i++)
    {
        AppleBox.clear();
        for (int j = i * m; j < i * m + m; j++)
        {
            AppleBox.push_back(score[j]);
        }
        std::sort(AppleBox.begin(), AppleBox.end());
        answer += AppleBox[0] * m;
    }
    return answer;
}