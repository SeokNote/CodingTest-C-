#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    bool Isvalue = false;
    for (int i = 0; i < targets.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            size_t num = 0;
            int min = 999999;
            for (int t = 0; t < keymap.size(); t++)
            {
                if (keymap[t].find(targets[i][j]) == string::npos)
                {
                    num = 0;
                    continue;
                }
                else
                {
                    num = keymap[t].find(targets[i][j]) + 1;
                    if (min > num)
                    {
                        min = num;
                    }
                }
               
            }
            if (min == 999999)
            {
                count = -1;
                break;
            }
            count += min;
        }

         answer.push_back(count);

    }


    return answer;
}
int main()
{
    solution({"AA"}, { "B"});
}