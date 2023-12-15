#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int Count = 0;
    if (s.size() == 6 || s.size() == 4)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int Num = std::stoi(s);
            if (Num < 10)
            {
                Count++;
            }
        }
        if (Count == s.size())
        {
            answer = true;
        }
        else
        {
            answer = false;
        }
    }
    return answer;
}