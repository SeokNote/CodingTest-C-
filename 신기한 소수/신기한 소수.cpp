#include <iostream>
#include <cmath>
#include <string>
#include <vector>
//소수판별해서 

bool IsVisit[4] = { false };
int N;
std::vector<int> Answer;
std::string CheckNum = "";

bool isPrime(int x)
{
    if (x == 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

//하나씩 붙여서 검사하기
void BT()
{
    if (CheckNum.size() == N)
    {
        Answer.push_back(std::stoi(CheckNum));
        return;
    }
    for (int i = 1; i < 10; i++)
    {

        CheckNum += i + '0';
        if (isPrime(std::stoi(CheckNum)))
        {
            BT();
        }
        CheckNum.pop_back();
    }
}

int main()
{
	std::cin >> N;
    BT();

    for (int i = 0; i < Answer.size(); i++)
    {
        std::cout<<Answer[i]<<"\n";
    }
    return 0;
}