#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int Num = 0;
    for (int i = 0; i < food.size(); i++)
    {
        food[i] = food[i] / 2;
        Num += food[i];
    }
    for (int i = 1; i < food.size(); i++)
    {
        for (int j = 0; j < food[i]; j++)
        {
            answer += std::to_string(i);
        }
    }
    answer += std::to_string(food[0]);
    for (int i = food.size() - 1; i >= 1; i--)
    {
        for (int j = 0; j < food[i]; j++)
        {
            answer += std::to_string(i);
        }
    }
    return answer;
}
int main()
{
    solution({ 1, 3, 4, 6 });
    return 0;
}