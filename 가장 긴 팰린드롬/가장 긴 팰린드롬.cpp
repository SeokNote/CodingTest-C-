#include <iostream>
#include <string>
#include <deque>
using namespace std;
bool PalindromCheck(const std::deque<char>& _deque)
{
    int Cnt = 0;
    for (int i = 0; i < _deque.size() / 2; i++)
    {
        if (_deque[i] == _deque[_deque.size() - i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int solution(string s)
{
    int answer = 1;

    int StrSize = s.size();
    if (StrSize == 0)
    {
        return 0;
    }

    if (StrSize == 1)
    {
        return 1;
    }

    for (int i = StrSize; i > 0; i--)
    {
        std::deque<char> SlidingWindow;
        int Right = 0;
        for (int left = 0; left < StrSize - i + 1; left++)
        {
            while (SlidingWindow.size() < i && Right < StrSize)
            {
                SlidingWindow.push_back(s[Right]);
                Right++;
            }

            if (PalindromCheck(SlidingWindow))
            {
                return i;
            }
            SlidingWindow.pop_front();
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("ecdabbcadc");
    return 0;
}