#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int Xcount[10] = { 0 };
    int Ycount[10] = { 0 };
    int Value = 0;;

    for (int i = 0; i < X.size(); i++)
    {
        Value = X[i] - '0';
        Xcount[Value]++;
    }

    for (int i = 0; i < Y.size(); i++)
    {
        Value = Y[i] - '0';
        Ycount[Value]++;
    }

    for (int i = 9; i >= 0; i--)
    {
        int n = min(Xcount[i], Ycount[i]);
        for (int j = 0; j < n; j++)
        {
            answer += to_string(i);
        }
    }

    if (answer == "")
    {
        answer = "-1";
    }
    else if (answer[0] == '0')
    {
        answer = "0";
    }

    return answer;
}