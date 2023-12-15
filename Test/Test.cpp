#include <string>
#include <vector>

using namespace std;
//벡터의 초기화 방법 메모
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(), 0));
    answer.reserve(arr1.size());
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[i].size(); j++)
        {
            answer[i][j] = (arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}
int main()
{
    vector<vector<int>> arrr1 = {{1}, { 2 }};
    vector<vector<int>> arrr2= { {3}, { 5} };
    solution(arrr1, arrr2);
    return 0;
}