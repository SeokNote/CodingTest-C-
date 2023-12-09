#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Students;
vector<int> vec;
vector<vector<int>> Answers;
int solution(vector<int> number) {
    int answer = 0;
    std::vector<int> temp(number.size(), 1);
    for (int i = 0; i < 3; i++)
    {
        temp[i] = 0;
    }
    std::sort(number.begin(), number.end());
    do
    {
        for (int i = 0; i < number.size(); i++)
        {
            if (temp[i] == 0)
            {
                vec.push_back(number[i]);
            }
        }
        Answers.push_back(vec);
        vec.clear();
    } while (std::next_permutation(temp.begin(), temp.end()));
    for (int i = 0; i < Answers.size(); i++)
    {
        int SubNum = 0;
        for (int j = 0; j < Answers[i].size(); j++)
        {
            SubNum += Answers[i][j];
        }
        if (SubNum == 0)
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    std::vector<int> asda = { -2, 3, 0, 2, -5 };
    std::cout << solution(asda);
}