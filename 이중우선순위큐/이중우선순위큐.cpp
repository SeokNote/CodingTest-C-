#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> Result;
    vector<int> number;
    vector<int> removenum;
    int Dcount = 0;
    int Icount = 0;
    //오름차순
    priority_queue<int> uppq;
    //내림차순
    priority_queue<int> downpq;
    for (int i = 0; i < operations.size(); i++)
    {
        if (Icount == Dcount)
        {
            uppq = priority_queue<int>();
            downpq = priority_queue<int>();
        }
        if (operations[i][0] == 'I')
        {
            Icount++;
            string str = "";
            bool IsValue = false;
            for (int j = 0; j < operations[i].size(); j++)
            {
                if (operations[i][j] == '-')
                {
                    IsValue = true;
                    continue;
                }
                if (operations[i][j] >= '0' && operations[i][j] <= '9')
                {
                    str += operations[i][j];
                }

            }
            if (IsValue == true)
            {
                uppq.push(stoi(str));
                downpq.push(-stoi(str));
            }
            else
            {
                uppq.push(-stoi(str));
                downpq.push(stoi(str));
            }

        }
        else if (operations[i][0] == 'D')
        {
            if (!uppq.empty() && !downpq.empty())
            {
                Dcount++;
                bool IsValue = false;
                for (int j = 0; j < operations[i].size(); j++)
                {
                    if (operations[i][j] == '-')
                    {
                        IsValue = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (IsValue == true)
                {
                    uppq.pop();
                }
                else
                {
                    downpq.pop();
                }
            }
        }

    }
    if (Dcount >= Icount)
    {
        Result.push_back(0);
        Result.push_back(0);
    }
    else
    {
        Result.push_back(downpq.top());
        Result.push_back(-uppq.top());
    }
    return Result;
}