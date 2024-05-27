#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::pair<int, int>> Contents;
int Answer = 0;
int AnswerContentsCnt = 0;
std::vector<int> AnswerContensNumber;

int main()
{
    int S, N;
    std::cin >> S >> N;
    for (int i = 0; i < N; i++)
    {
        int Stamina = 0;
        int Experience = 0;
        std::cin >> Stamina >> Experience;
        Contents.push_back(std::make_pair(Stamina, Experience));
    }
	do
	{
		int sum = 0;
        int MaxExperience = 0;
        int ContentCnt = 0;
        std::vector<int> ContensNumber;
		for (int i = 0; i < Contents.size(); i++)
		{
            sum += Contents[i].first;

            if (sum > S)
            {
                break;
            }
            else
            {
                MaxExperience += Contents[i].second;
                ContensNumber.push_back(i + 1);
                ContentCnt++;
            }
		}
        if (Answer < MaxExperience)
        {
            Answer = MaxExperience;
            AnswerContentsCnt = ContentCnt;
            AnswerContensNumber = ContensNumber;
        }
	} while (std::next_permutation(Contents.begin(), Contents.end()));

    std::cout << Answer << "\n";
    std::cout << AnswerContentsCnt << "\n";
    for (int i = 0; i < AnswerContensNumber.size(); i++)
    {
        std::cout << AnswerContensNumber[i] << " ";
    }
    return 0;
}