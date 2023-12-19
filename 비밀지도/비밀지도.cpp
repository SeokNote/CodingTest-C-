#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
std::vector<int> binary(int _Value, int _n)
{
    std::vector<int> vec(_n, 0);
    int i = 0;
    while (_Value != 0)
    {
        if (_Value % 2 == 1)
        {
            vec[i] = 1;
        }
        else
        {
            vec[i] = 0;
        }
        _Value /= 2;
        i++;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> left;
    vector<vector<int>> right;
    left.reserve(n);
    right.reserve(n);
    for (int i = 0; i < arr1.size(); i++)
    {
        left.push_back(binary(arr1[i], n));
        right.push_back(binary(arr2[i], n));
    }
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = 0; j < n; j++)
        {
            if (left[i][j] + right[i][j] >= 1)
            {
                str += "#";
            }
            else
            {
                str += " ";
            }
        }
        answer.push_back(str);
    }
    return answer;
}

void Test(vector<string>&& _Value)
{

}

void Test(vector<string>& _Value)
{

}

int main()
{

    std::vector<std::string> L = solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
    
    Test(L);
    return 0;
}