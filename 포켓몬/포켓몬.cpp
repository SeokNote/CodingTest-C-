#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    std::set<int> answers;
    for (int i = 0; i < nums.size(); i++)
    {
        answers.insert(nums[i]);
    }
    if (nums.size() / 2 < answers.size())
    {
        answer = nums.size() / 2;
    }
    else
    {
        answer = answers.size();
    }
    return answer;
}