//#include <string>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//vector<int> solution(vector<string> gems) {
//    vector<int> answer;
//    vector<vector<int>> Indexs;
//    set<string> Nogem;
//    for (int i = 0; i < gems.size(); i++)
//    {
//        Nogem.insert(gems[i]);
//    }
//    vector<string> vec;
//    for (auto &i : Nogem)
//    {
//        vec.push_back(i);
//    }
//    int Size = gems.size();
//    int Count = 0;
//    int types = vec.size();
//    for (int i = 0; i < Size; i++)
//    {
//        vector<string> gem = vec;
//        remove(gem.begin(), gem.end(), gems[i]);
//        for (int j = i + 1; j < Size; j++)
//        {
//            remove(gem.begin(), gem.end(), gems[j]);
//            if (gem.size() == 0)
//            {
//                answer.push_back(i);
//                answer.push_back(j);
//            }
//            Indexs.push_back(answer);
//            answer.clear();
//        }
//
//    }
//
//    return answer;
//}
//int main()
//{
//    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
//    return 0;
//}


#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> jewel;
    int Size = gems.size();
    for (int i = 0; i < gems.size(); ++i)
    {
        jewel.insert(gems[i]);
    }

    int Min = INT32_MAX; 
    map<string, int> m;
    int left = 0;
    int right = 0;
    answer[0] = 0;
    answer[1] = INT32_MAX;
    m[gems[0]] = 1;
    int count = 1;
    int jewelSize = jewel.size();
    while (right < Size && left <= right)
    {
        if (count < jewelSize)
        {
            right++;
            if (right == Size)
            {
                break;
            }
            if (m[gems[right]] == 0)
            {
                count++;
            }
            m[gems[right]]++;
        }
        else
        {
            if (right - left < answer[1] - answer[0])
            {
                answer[0] = left;
                answer[1] = right;
            }
            if (m[gems[left]] == 1)
            {
                count--;
            }
            m[gems[left]]--;
            left++;

        }
    }
    answer[0]++;
    answer[1]++;
    return answer;
}
int main()
{
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    return 0;
}