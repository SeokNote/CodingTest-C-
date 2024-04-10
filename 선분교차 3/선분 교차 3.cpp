#include<iostream>
#include<cmath>
#include<algorithm>
int CCW(std::pair<long long, long long> _Point1, std::pair<long long, long long> _Point2, std::pair<long long, long long> _Point3)
{
    if ((_Point2.first - _Point1.first) * (_Point3.second - _Point1.second) - (_Point3.first - _Point1.first) * (_Point2.second - _Point1.second) > 0)
    {
        return 1;
    }
    else if ((_Point2.first - _Point1.first) * (_Point3.second - _Point1.second) - (_Point3.first - _Point1.first) * (_Point2.second - _Point1.second) == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
//교점 구하기.
void find_intersection(std::pair<long long, long long> _Point1, std::pair<long long, long long> _Point2, std::pair<long long, long long> _Point3, std::pair<long long, long long> _Point4) // 교점 구하기
{
    double px = (_Point1.first * _Point2.second - _Point1.second * _Point2.first) * (_Point3.first - _Point4.first) - (_Point1.first - _Point2.first) * (_Point3.first * _Point4.second - _Point3.second * _Point4.first);
    double py = (_Point1.first * _Point2.second - _Point1.second * _Point2.first) * (_Point3.second - _Point4.second) - (_Point1.second - _Point2.second) * (_Point3.first * _Point4.second - _Point3.second * _Point4.first);
    double p = (_Point1.first - _Point2.first) * (_Point3.second - _Point4.second) - (_Point1.second - _Point2.second) * (_Point3.first - _Point4.first);

    if (p == 0) // 평행할 때
    {
        // 교점이 하나일 때
        if (_Point2 == _Point3 && _Point1 <= _Point3)
        {
            std::cout << _Point2.first << " " << _Point2.second << '\n';
        }
        else if (_Point1 == _Point4 && _Point3 <= _Point1)
        {
            std::cout << _Point1.first << " " << _Point1.second << '\n';
        }
    }
    else // 교차할 때
    {
        double x = px / p;
        double y = py / p;

        std::cout << std::fixed;
        std::cout.precision(9);
        std::cout << x << " " << y;
    }
}
void IsIntersect(std::pair<std::pair<long long, long long>, std::pair<long long, long long>> _Line1, std::pair<std::pair<long long, long long>, std::pair<long long, long long>> _Line2)
{
    std::pair<long long, long long> A = _Line1.first;
    std::pair<long long, long long> B = _Line1.second;
    std::pair<long long, long long> C = _Line2.first;
    std::pair<long long, long long> D = _Line2.second;

    int AB = CCW(A, B, C) * CCW(A, B, D);
    int CD = CCW(C, D, A) * CCW(C, D, B);
    if (AB == 0 && CD == 0)
    {
        if (A > C)
        {
            std::swap(A, C);
        }
        if (B > D)
        {
            std::swap(B, D);
        }
        if (B >= C && A <= D)
        {
            std::cout << 1 << '\n';
            find_intersection(A, B, C, D);
        }
        else
        {
            std::cout << 0 << '\n';
        }
    }
    else if (AB <= 0 && CD <= 0)
    {
        std::cout << 1 << '\n';
        find_intersection(A, B, C, D);
    }
    else
    {
        std::cout << 0 << '\n';
    }

}
int main() {
    std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line1;
    std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line2;

    std::cin >> Line1.first.first >> Line1.first.second;
    std::cin >> Line1.second.first >> Line1.second.second;
    std::cin >> Line2.first.first >> Line2.first.second;
    std::cin >> Line2.second.first >> Line2.second.second;

    std::pair<long long, long long> A = Line1.first;
    std::pair<long long, long long> B = Line1.second;
    std::pair<long long, long long> C = Line2.first;
    std::pair<long long, long long> D = Line2.second;

    int answer = 0;

    IsIntersect(Line1, Line2);
    
    return 0;
}
