#include <string>
#include <vector>

using namespace std;
//9/2 4 5
//9/3 == 1,2,6  1,3,5, 3,3,3 27
//5/2= 1,4, 2,3, 
//7/3 = 1,2,4, 1,3,3 2,2,3 , 12
//8/3 2 3 3 18  2 2 4 16
vector<int> solution(int n, int s)
{
    vector<int> answer;
    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0; i < n; i++)
    {
        answer.push_back(s / n);
    }
    int Mod = s % n;
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        if (Mod != 0)
        {
            answer[i] = answer[i] + 1;
            Mod--;
        }
    }
    return answer;
}