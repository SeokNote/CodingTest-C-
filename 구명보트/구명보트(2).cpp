#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int Size = people.size() - 1;
    std::sort(people.begin(), people.end(), greater<int>());
    for (int i = Size; i >= 0; i--)
    {
        int sum = people[i];
        for (int j = i - 1; j >= 0; j--)
        {
            sum += people[j];
            if (sum <= limit)
            {
                people.pop_back();
            }
        }
    }
    answer = people.size();
    return answer;
}
int main()
{
    std::cout<<solution({ 50,70,80},100);
	return 0;
}