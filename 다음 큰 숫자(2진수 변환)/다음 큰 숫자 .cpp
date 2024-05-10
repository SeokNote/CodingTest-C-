#include <string>
#include <vector>
#include <bitset>
#include <iostream>
int onecount(int _num)
{
    int cnt = 0;
    std::bitset<32> my_b(_num);
    for (int i = 0; i < my_b.size(); i++)
    {
        if (my_b[i] == 1)
        {
            cnt++;
        }
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    int cnt = onecount(n);
    while (1)
    {
        n++;
        if (cnt == onecount(n))
        {
            answer = n;
            break;

        }
    }
    return answer;
}
int main()
{
    std::cout << solution(78);
    return 0;
}