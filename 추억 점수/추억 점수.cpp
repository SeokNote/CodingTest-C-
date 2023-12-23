#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for (int i = 0; i < photo.size(); i++)
    {
        int Sum = 0;
        for (int j = 0; j < photo[i].size(); j++)
        {
            for (int t = 0; t < name.size(); t++)
            {
                if (name[t] == photo[i][j])
                {
                    Sum += yearning[t];
                }
            }
        }
        answer.push_back(Sum);
    }
    return answer;
}