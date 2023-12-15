#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
std::vector<int> Numbers;
std::vector<int> Answer;
std::vector<std::vector<int>> Starts;
std::vector<std::vector<int>> Links;
std::vector<int> Start;
std::vector<int> Link;
/*
[] [] [] []
[] [] [] []
[] [] [] []
[] [] [] []
*/

//4c4를 구한다.
//6c6을 구한다.
//거기서 또 조합
int main()
{
    int Num = 0;
    int Count = 0;
    std::cin >> Num;
    for (int i = 1; i <= Num; i++)
    {
        Numbers.push_back(i);
    }
    std::sort(Numbers.begin(), Numbers.end());

    do {

        for (int i = 0; i < Numbers.size(); i++)
        {
            if (i < Numbers.size() / 2)
            {
                Start.push_back(Numbers[i]);

            }
            else
            {
                Link.push_back(Numbers[i]);

            }
        }
        Starts.push_back(Start);
        Links.push_back(Link);
        Start.clear();
        Link.clear();
        std::cout << "\n";

    } while (next_permutation(Numbers.begin(), Numbers.end()));
    std::sort(Starts.begin(), Starts.end());
    Starts.erase(std::unique(Starts.begin(), Starts.end()), Starts.end());
    std::sort(Links.begin(), Links.end());
    Links.erase(std::unique(Links.begin(), Links.end()), Links.end());
    for (int i = 0; i < Starts.size(); i++)
    {
        int StartScore = 0;
        int LinkScore = 0;
        for (int j = 0; j < Starts[i].size(); j++)
        {
            StartScore += Starts[i][j];
            LinkScore += Links[i][j];
        }
    }
    int a = 0;

    return 0;
}
/////////////////////포기ㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣ