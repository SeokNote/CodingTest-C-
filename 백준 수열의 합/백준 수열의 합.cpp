#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    int L = 0;

    std::cin >> N >> L;

    int Start = -1;
    int Count = 0;

    for (int i = L; i <= 100; ++i)
    {
        int Sum = i * (i - 1) / 2;

        // 초과 더이상 확인할 필요가 없음
        if (Sum > N)
        {
            break;
        }

        int Remainder = N - Sum;

        // 해당 수열로는 될 수 없음
        if (0 != (Remainder % i))
        {
            continue;
        }

        Start = Remainder / i;
        Count = i;

        break;
    }

    if (-1 == Start)
    {
        std::cout << "-1";
    }

    for (size_t i = 0; i < Count; ++i)
    {
        std::cout << Start + i << " ";
    }

    return 0;
}