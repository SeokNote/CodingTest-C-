#include <iostream>

int main()
{
    //ü�� ���� , ���� ���� �Ǹŷα� ��� ����
    //ü�� P , ���� Q �Ѿ� W
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