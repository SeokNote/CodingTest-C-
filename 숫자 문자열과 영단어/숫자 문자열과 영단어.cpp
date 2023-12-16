#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<string> Numbers;
int solution(string s) {
    Numbers.reserve(10);
    Numbers.push_back("zero");
    Numbers.push_back("one");
    Numbers.push_back("two");
    Numbers.push_back("three");
    Numbers.push_back("four");
    Numbers.push_back("five");
    Numbers.push_back("six");
    Numbers.push_back("seven");
    Numbers.push_back("eight");
    Numbers.push_back("nine");
    int answer = 0;
    for (int i = 0; i < Numbers.size(); i++)
    {
        string find_str = Numbers[i];
        while (s.find(find_str) != std::string::npos) // ¿Ö while µ¹±î
        {
            s.replace(s.find(find_str), find_str.length(), to_string(i));
        }

    }
    answer = std::stoi(s);
    return answer;
}

int main()
{
    std::cout << solution("onetwothreefourfivesixseveneightninezero");
    return 0;
}
