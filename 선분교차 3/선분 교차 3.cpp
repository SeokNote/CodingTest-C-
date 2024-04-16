#include <iostream>
#include <cmath>
#include <algorithm>

double CCW(std::pair<double, double> _A, std::pair<double, double> _B, std::pair<double, double> _C)
{
    double Sum = 0.0;

    Sum += (_A.first * _B.second) + (_B.first * _C.second) + (_C.first * _A.second);
    Sum -= (_A.second * _B.first) + (_B.second * _C.first) + (_C.second * _A.first);

    if (Sum > 0)
    {
        return 1.0;
    }
    else if (Sum < 0)
    {
        return -1.0;
    }
    else
    {
        return 0;
    }
}

void FindImpact(std::pair<double, double> A, std::pair<double, double> B, std::pair<double, double> C, std::pair<double, double> D)
{
    double PX = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
    double PY = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
    double P = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

    if (0 == P) 
    {
        if (B == C && A <= C)
        {
            std::cout << B.first << " " << B.second << '\n';        
        }
        else if (A == D && C <= A)
        {        
            std::cout << A.first << " " << A.second << '\n';
        }
    }
    else 
    {
        double X = PX / P;
        double Y = PY / P;

        std::cout << std::fixed;
        std::cout.precision(16);
        std::cout << X << " " << Y;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::pair<double, double> A, B, C, D;

    std::cin >> A.first >> A.second >> B.first >> B.second;
    std::cin >> C.first >> C.second >> D.first >> D.second;

    double CCWA = CCW(A, B, C) * CCW(A, B, D);
    double CCWB = CCW(C, D, A) * CCW(C, D, B);

    if (0 == CCWA && 0 == CCWB)
    {
        // ÀÏÁ÷¼±        
        if (A > B)
        {
            std::swap(A, B);
        }
        if (C > D)
        {
            std::swap(C, D);
        }

        if (A <= D && B >= C)
        {
            std::cout << 1 << '\n';
            FindImpact(A, B, C, D);
        }
        else
        {
            std::cout << 0;
        }
    }
    else if (0 < CCWA || 0 < CCWB)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << 1 << '\n';
        FindImpact(A, B, C, D);
    }

    return 0;
}