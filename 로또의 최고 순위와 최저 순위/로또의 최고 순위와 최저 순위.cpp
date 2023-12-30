#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int Size = lottos.size();
    int WinCount = 6;
    int ZeroCount = 0;
    for (int i = 0; i < Size; i++)
    {
        if (lottos[i] == 0)
        {
            ZeroCount++;
            WinCount--;
        }
        else
        {
            bool IsValue = false;
            for (int j = 0; j < Size; j++)
            {
                 if (lottos[i] == win_nums[j])
                 {
                     win_nums[j] = 99;
                     IsValue = true;
                 }
            }
            if (IsValue == false)
            {
                WinCount--;
            }
        }    
    }
    if (ZeroCount ==6)
    {
        answer.push_back(1);
        answer.push_back(6);
    }
    else if (WinCount + ZeroCount <2)
    {
        answer.push_back(6);
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7- (WinCount+ ZeroCount));
        answer.push_back(7 - WinCount);
    }

    return answer;
}
int main()
{
    solution({ 1,2,3,4,5,0 }, {7,8,9,10,11,12});
    return 0;
}