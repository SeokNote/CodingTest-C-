#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<vector<int>> Indexs;
    set<string> Nogem;
    for (int i = 0; i < gems.size(); i++)
    {
        Nogem.insert(gems[i]);
    }
    vector<string> vec;
    for (auto i : Nogem)
    {
        vec.push_back(i);
    }
    int Size = gems.size();
    int Count = 0;
    int types = vec.size();
    for (int i = 0; i < Size; i++)
    {
        vector<string> gem = vec;
        remove(gem.begin(), gem.end(), gems[i]);
        for (int j = i + 1; j < Size; j++)
        {
            remove(gem.begin(), gem.end(), gems[j]);
            if (gem.size() == 0)
            {
                answer.push_back(i);
                answer.push_back(j);
            }
            Indexs.push_back(answer);
            answer.clear();
        }

    }

    return answer;
}
int main()
{
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    return 0;
}