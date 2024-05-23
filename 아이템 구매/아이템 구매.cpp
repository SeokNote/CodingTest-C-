#include <iostream>

int main()
{
    //체력 물약 , 마나 물약 판매로그 기록 못함
    //체력 P , 마나 Q 총액 W
    int P = 0;
    int Q = 0;
    int W = 0;
    std::cin >> P >> Q >> W;
    int size = W / Q;
    for (int i = 0; i <= size; i++)
    {
        int remain = W - (Q * i);
        if (remain % P == 0)
        {
            std::cout << remain / P << " " << i;
            return 0;
        }
    }
    size = W / P;
    for (int i = 0; i <= size; i++)
    {
        int remain = W - (P * i);
        if (remain % Q == 0)
        {
            std::cout << remain / Q << " " << i;
            return 0;
        }
    }
    return 0;
}