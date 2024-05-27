#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> answer;
std::string WinTeam = "";

bool compare(const std::pair<std::string, double>& _a, const std::pair<std::string, double>& _b)
{
    return _a.second < _b.second;
}

void ItemGame(const std::vector<std::pair<std::string, std::string>> _Teams)
{
    double MinTime = INT32_MAX;
    for (int i = 0; i < _Teams.size(); i++)
    {
        double Time = 0.0f;
        std::string StrSeconds = "";
        size_t Numpos = _Teams[i].second.find(":");
        double Minute = _Teams[i].second[Numpos - 1] - '0';
        for (size_t j = Numpos + 1; j < _Teams[i].second.size(); j++)
        {
            StrSeconds += _Teams[i].second[j];
        }
        Time = std::stod(StrSeconds) + Minute * 60.0f;
        if (MinTime > Time)
        {
            MinTime = Time;
            WinTeam = _Teams[i].first;
        }
    }
}

void SpeedGame(const std::vector<std::pair<std::string, std::string>> _Teams)
{
    int RedTotalScore = 0;
    int BlueTotalScore = 0;
    std::vector<std::pair<std::string, double>> TeamScore;
    for (int i = 0; i < _Teams.size(); i++)
    {
        double Time = 0.0f;
        std::string StrSeconds = "";
        size_t Numpos = _Teams[i].second.find(":");
        double Minute = _Teams[i].second[Numpos - 1] - '0';
        for (size_t j = Numpos + 1; j < _Teams[i].second.size(); j++)
        {
            StrSeconds += _Teams[i].second[j];
        }
        Time = std::stod(StrSeconds) + Minute * 60.0f;
        TeamScore.push_back(std::make_pair(_Teams[i].first, Time));
    }
    std::sort(TeamScore.begin(), TeamScore.end(), compare);
    double FirstTime = TeamScore[0].second;
    for (int i = 0; i < TeamScore.size(); i++)
    {
        if (TeamScore[i].first == "blue")
        {
            if (TeamScore[i].second - FirstTime >= 10.0f)
            {
                BlueTotalScore += 0;
            }
            else
            {
                if (i == 0)
                {
                    BlueTotalScore += 10;
                }
                else if (i == 1)
                {
                    BlueTotalScore += 8;
                }
                else
                {
                    BlueTotalScore += 8 - i;
                }
            }
        }
        else
        {
            if (TeamScore[i].second - FirstTime >= 10.0f)
            {
                RedTotalScore += 0;
            }
            else
            {
                if (i == 0)
                {
                    RedTotalScore += 10;
                }
                else if (i == 1)
                {
                    RedTotalScore += 8;
                }
                else
                {
                    RedTotalScore += 8 - i;
                }
            }
        }
    }
    if (RedTotalScore > BlueTotalScore)
    {
        WinTeam = "red";
    }
    else if (RedTotalScore == BlueTotalScore)
    {
        WinTeam = TeamScore[0].first;
    }
    else
    {
        WinTeam = "blue";
    }

}
int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::vector<std::pair<std::string, std::string>> Teams;
        std::string Game = "";
        std::cin >> Game;
        for (int j = 0; j < 8; j++)
        {
            std::string Color = "";
            std::string Time = "";
            std::cin >> Color >> Time;
            Teams.push_back(std::make_pair(Color, Time));
        }
        if (Game == "item")
        {
            ItemGame(Teams);
        }
        else
        {
            SpeedGame(Teams);
        }

        answer.push_back(WinTeam);
    }
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << "\n";
    }
    return 0;
}