#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string Number;
    std::cin >> Number;
    int checksize = 0;
    int answer = 0;
    int matchcount = 0;
    while (matchcount < Number.size())
    {
        answer++;
        std::string checknum = std::to_string(answer);
        for (int j = 0; j < checknum.size(); j++)
        {
            if (checknum[j] == Number[matchcount])
            {
                matchcount++;
            }
            else
            {
                continue;
            }
        }
    }
    std::cout << answer;
    return 0;
}