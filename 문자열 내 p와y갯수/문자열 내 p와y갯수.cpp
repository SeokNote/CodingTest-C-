#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int Pcount = 0;
    int Ycount = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s.at(i) == p || s[i] == pp)
        {
            Pcount++;
        }
        else if (s[i] == y || s[i] == yy)
        {
            Ycount++;
        }

    }
    if (Pcount == 0 && Ycount == 0)
    {
        return false;
    }
    if (Pcount == Ycount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string a = "pPoooyY";
    char b = a[0];
    solution(a);
    return 0;
}
