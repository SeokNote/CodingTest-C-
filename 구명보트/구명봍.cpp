#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0;
    int end = people.size() - 1;

    sort(people.begin(), people.end());

    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
        {
            start++;
        }
        end--;
        answer++;
    }

    return answer;
}
int main()
{
    solution({ 50,70,80,50 }, 100);
    return 0;
//}