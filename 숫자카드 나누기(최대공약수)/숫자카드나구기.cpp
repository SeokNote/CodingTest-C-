#include <iostream>
#include <vector>
int gcd(int a, int b) // a > b
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int solution(std::vector<int> arrayA, std::vector<int> arrayB)
{
    int gcd_A = arrayA[0];
    int gcd_B = arrayB[0];
    bool IsValue = false;
    int answer = 0;
    for (int i = 1; i < arrayA.size(); i++)
    {
        gcd_A = gcd(gcd_A, arrayA[i]);
    }
    for (int i = 1; i < arrayB.size(); i++)
    {
        gcd_B = gcd(gcd_B, arrayB[i]);
    }
 
    if (gcd_A != 1)
    {
        for (int i = 0; i < arrayB.size(); i++)
        {
            if (arrayB[i] % gcd_A == 0)
            {
                IsValue = true;
                break;
            }
        }
        if (IsValue == false)
        {
            answer = gcd_A;
        }
    }
    if (gcd_B != 1)
    {
        IsValue = false;
        for (int i = 0; i < arrayA.size(); i++)
        {
            if (arrayA[i] % gcd_B == 0)
            {
                IsValue = true;
                break;
            }
           
        }
        if (IsValue == false)
        {
            answer = std::max(gcd_B, answer);
        }
    }
    return answer;
}

int main()
{
    solution({ 10,20 }, { 20 });
}