
int main()
{
    int* test = new int;
    const int* A = test; // �ּҰ� ����Ű�� ���� �ٲܼ� ������
    int* const B = test; // �ּҸ� ���ٲٰ���
    const int* const C = test; // �ּҸ� ���ٲٰ���

    *B = 1;
    A = nullptr;
    *A = 2;

    C = nullptr;
    *C = 1;
    return 0;
}