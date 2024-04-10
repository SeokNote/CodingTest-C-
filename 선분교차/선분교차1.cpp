// ������ �� ������ �����ϴ��� üũ�ϴ� ��.
// �� ������ �����ϱ� ���� ����
// 1. �Ѱ��� ������ ������ ��� ������ ������ ccw ������ ���� �� ������ �ٸ��� ������ �����ϴ�.
// 2. ������ ���е� 1���� �Ȱ��� üũ
// 3. �� ������ ������ ���(ccw�� �Ѵ� 0�϶�) 
#include<iostream>
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

bool IsIntersect(std::pair<std::pair<long long, long long>, std::pair<long long, long long>> _Line1, std::pair<std::pair<long long, long long>, std::pair<long long, long long>> _Line2)
{
    std::pair<long long, long long> A = _Line1.first;
    std::pair<long long, long long> B = _Line1.second;
    std::pair<long long, long long> C = _Line2.first;
    std::pair<long long, long long> D = _Line2.second;
    
    int AB = CCW(A, B, C) * CCW(A, B, D);
    int CD = CCW(C, D, A) * CCW(C, D, B);
  
    //������ ������ ��
    if (AB == 0 && CD == 0)
    {
        if (A > B)
        {
            std::swap(A, B);
        }
        if (C > D)
        {
            std::swap(C, D);
        }
        if (C <= B && A <= D)
        {
            return true;
        }
    }

    if (AB <= 0 && CD <= 0)
    {
        return true;
    }

    return false;
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

    if (IsIntersect(Line1, Line2))
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }


    std::cout << answer;
    return 0;
}
