#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> vec = { "aya","ye","woo","ma" };
    std::string prevstring = "";
    //yeayaye
    for (int j = 0; j < babbling.size(); j++)
    {
        for (int i = 0; i < babbling[j].size();)
        {
            if (babbling[j].substr(i, i + 3) == "aya")
            {
                i += 3;
            }
            else if (babbling[j].substr(i, i + 2) == "ye")
            {
                i += 2;
            }
            else if (babbling[j].substr(i, i + 3) == "woo")
            {
                i += 3;

            }
            else if (babbling[j].substr(i, i + 2) == "ma")
            {
                i += 2;
            }
            else
            {
                break;
            }
        
        }
    }
    return answer;
}
int main()
{
    solution({ "yeayaye" });
    return 0;
}