#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int Sum = 0;
    std::string strx = std::to_string(x);
    for (int i = 0; i < strx.size(); i++)
    {
        Sum += strx[i] - '0';
    }
    if (x % Sum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}