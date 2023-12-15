#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int PrevIndex = 999999;
    for (int i = 0; i < arr.size(); i++)
    {
        if (PrevIndex != arr[i])
        {
            answer.push_back(arr[i]);
        }
        PrevIndex = arr[i];
    }
    return answer;
}
int main()
{
    vector<int> asd = { 1,1,3,3,0,1,1 };
    solution(asd);
    return 0;
}

//algorithm 헤더의 unique 활용
/*
vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}
*/