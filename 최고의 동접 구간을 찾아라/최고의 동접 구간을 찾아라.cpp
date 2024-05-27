#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//타임테이블?
//4억
//로그인한 시간과 로그아웃한 시간
//최대로 로그인하면 동접1등
//정렬
std::vector<std::pair<std::string, int>> Log;
std::vector<std::pair<int, int>> LogCnt;

bool Compare(const std::pair<std::string, int>& _a, const std::pair<std::string, int>& _b)
{
    return _a.second < _b.second;
}

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int LoginMinutes = 0;
        int LogOutMinutes = 0;
        std::string Login = "";
        std::string LogOut = "";
        std::cin >> Login >> LogOut;

        size_t Pos = Login.find(":");
        std::string LoginMinuteStr = "";
        std::string LoginSecStr = "";
        std::string LogOutMinuteStr = "";
        std::string LogOutSecStr = "";

        for (size_t t = 0; t < Login.size(); t++)
        {
            if (t < Pos)
            {
                LoginMinuteStr += Login[t];
                LogOutMinuteStr += LogOut[t];
            }
            else if (t > Pos)
            {
                LoginSecStr += Login[t];
                LogOutSecStr += LogOut[t];

            }
        }
        LoginMinutes = 60 * std::stoi(LoginMinuteStr) + std::stoi(LoginSecStr);
        LogOutMinutes = 60 * std::stoi(LogOutMinuteStr) + std::stoi(LogOutSecStr);
        Log.push_back(std::make_pair("LogIn", LoginMinutes));
        Log.push_back(std::make_pair("LogOut", LogOutMinutes));
    }
    std::sort(Log.begin(), Log.end(), Compare);
    int MaxLogIn = 0;
    int MaxLoginTime = 0;
    int MaxLogOutTime = 0;
    int MaxIndex = 0;
    int LogInCnt = 0;
    bool LogOutValue = false;
    for (int i = 0; i < Log.size(); i++)
    {
        if (Log[i].first == "LogIn")
        {
            //로그인인데 같은시간에 로그아웃하는 사람이 있으면
            if (i + 1 < Log.size() && Log[i].second == Log[i + 1].second && Log[i].first != Log[i + 1].first)
            {
                i++;
                continue;
            }
            else
            {
                LogInCnt++;
            }
        }
        else if (Log[i].first == "LogOut")
        {
            //로그아웃인데 같은시간에 로그인하는 사람이 있으면

            if (i + 1 < Log.size() && Log[i].second == Log[i + 1].second && Log[i].first != Log[i + 1].first)
            {
                i++;
                continue;
            }
            else
            {
                LogInCnt--;
            }
        }
        if (MaxLogIn < LogInCnt)
        {
            MaxLogIn = LogInCnt;
            MaxLoginTime = Log[i].second;
            MaxIndex = i;
        }
        LogCnt.push_back(std::make_pair(LogInCnt, i));
    }

    for (int i = 0; i < LogCnt.size(); i++)
    {
        if (MaxIndex < i && LogCnt[i].first == MaxLogIn - 1)
        {
            MaxLogOutTime = Log[LogCnt[i].second].second;
            break;
        }
    }


    std::string LogInMin = "";
    std::string LogInOutMin = "";
    std::string LogInScend = "";
    std::string LogInOut = "";
    //동접 최대일때의 로그인 분
    if (MaxLoginTime / 60 <= 9)
    {
        LogInMin = "0";
        LogInMin += std::to_string(MaxLoginTime / 60);
    }
    else if (MaxLoginTime / 60 == 0)
    {
        LogInMin = "00";
    }
    else
    {
        LogInMin = std::to_string(MaxLoginTime / 60);
    }
    //동접 최대일 때의 로그아웃 분
    if (MaxLogOutTime / 60 <= 9)
    {
        LogInOutMin = "0";
        LogInOutMin += std::to_string(MaxLogOutTime / 60);
    }
    else if (MaxLogOutTime / 60 == 0)
    {
        LogInOutMin = "00";
    }
    else
    {
        LogInOutMin = std::to_string(MaxLogOutTime / 60);
    }

    if (MaxLoginTime % 60 == 0)
    {
        LogInScend = "00";
    }
    else if (MaxLoginTime % 60 <= 9)
    {
        LogInScend = "0";
        LogInScend += std::to_string(60 - MaxLogOutTime % 60);
    }
    else
    {
        LogInScend = std::to_string(MaxLoginTime % 60);
    }

    if (MaxLogOutTime % 60 == 0)
    {
        LogInOut = "00";
    }
    else if (MaxLogOutTime % 60 <= 9)
    {
        LogInOut = "0";
        LogInOut += std::to_string(60 - MaxLogOutTime % 60);
    }
    else
    {
        LogInOut = std::to_string(MaxLogOutTime % 60);
    }

    std::cout << MaxLogIn << "\n";
    std::cout << LogInMin << ":" << LogInScend << " " << LogInOutMin << ":" << LogInOut;
    return 0;
}