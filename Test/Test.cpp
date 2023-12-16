#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int jump = 0;
    answer.push_back(-1);
    for (int i = 1; i < s.size(); i++)
    {
       string str = s.substr(0, i+1);
       count = 0;
       jump = 0;
       for (int j = str.size() - 1; j >= 0; j--)
       {
           jump++;
           if (str[j] == s[i])
           {
               count++;

           }
           if (count == 2)
           {
               break;
           }
       }
       if (count == 1)
       {
           answer.push_back(-1);
       }
       else
       {
          answer.push_back(jump-1);

       }
    }
    return answer;
}
int main()
{
    solution("banana");
    return 0;
}